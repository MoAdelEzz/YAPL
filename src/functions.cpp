#include "functions.hpp"
#include "enums.hpp"
#include "organizer.hpp"
#include <string>

// =========================================================================================
// =================================== Function Defintion ==================================
// =========================================================================================

FunctionDefintionNode::FunctionDefintionNode( int line, DataType* returnType, std::string name, FunctionParametersNode* params, ScopeNode* body) 
: ProgramNode(line) {   
    this->name = name;
    this->parameters = params ? params : new FunctionParametersNode();
    this->body = body;
    this->returnType = returnType;
    this->logLineInfo();
}

FunctionDefintionNode::~FunctionDefintionNode() {
    if(parameters) delete parameters;
    if(body) delete body;
    if(returnType) delete returnType;
}

std::string FunctionDefintionNode::nodeName() {
    return "Function Defintion Node";
}

void FunctionDefintionNode::run(Scope* scope) {
    body->setParentScope(scope);
    body->isFunction = true;
    body->haltLogging = true;
    scope->defineFunction(returnType, name, parameters, body);
    body->getScope()->defineReturn(returnType);
}

void FunctionDefintionNode::runSemanticChecker(Scope* scope) {
    try {
        SymbolTableEntry stEntry = scope->defineFunction(returnType, name, parameters, body);
        stEntry.setLine(this->line);
        CompilerOrganizer::addSymbolTableEntry(stEntry);
    } catch( ErrorDetail error ) {
        error.setLine(line);
        CompilerOrganizer::addError(error);
    }
    
    FunctionParametersNode* params = scope->getFunctionParameters(name);
    std::reverse(params->names.begin(), params->names.end());
    std::reverse(params->types.begin(), params->types.end());
    std::reverse(params->defaultValues.begin(), params->defaultValues.end());

    Scope* functionScope = body->getScope();

    scopeDepth++;
    CompilerOrganizer::addSymbolTableEntry(SymbolTableEntry::scopeEntry());

    functionScope->defineReturn(returnType);
    for (int i = 0; i < parameters->names.size(); i++) {
        SymbolTableEntry stEntry = functionScope->defineVariable(parameters->names[i], parameters->types[i], Operand::undefined(), true);
        stEntry.setLine(this->line);
        CompilerOrganizer::addSymbolTableEntry(stEntry);

        if (parameters->defaultValues[i] != nullptr) 
            CompilerOrganizer::markSymbolAsInitialized(parameters->names[i]);  
        functionScope->assignVariableValueType(parameters->names[i], parameters->types[i]->type);
    }

    body->isFunction = true;
    body->haltLogging = true;
    body->runSemanticChecker(scope);
    functionScope->reset();
    
    CompilerOrganizer::addSymbolTableEntry(SymbolTableEntry::scopeExit());
    scopeDepth--;
}

void FunctionDefintionNode::generateQuadruples(Scope* scope) {
    CompilerOrganizer::addFunctionStartLabel(name);
    body->generateQuadruples(scope);
    CompilerOrganizer::addFunctionEndLabel(name);
}

// =========================================================================================
// ===================================== Function Call =====================================
// =========================================================================================

FunctionCallNode::FunctionCallNode(int line, std::string name, FunctionCallParametersNode* arguments) 
: Expression(nullptr, DataType::Undefined()) {   
    this->name = name;
    this->arguments = arguments ? arguments : new FunctionCallParametersNode();
    this->line = line;
}

FunctionCallNode::~FunctionCallNode() {
    if(arguments) delete arguments;
}

OperandType FunctionCallNode::getExpectedType(Scope* scope) {
    OperandType returnType = scope->getFunctionReturnType(name);

    if (returnType == TUNDEFINED) {
        ErrorDetail error(Severity::ERROR, "Function Not Defined");
        error.setLine(this->line);
        CompilerOrganizer::addError(error);
    } else {
        CompilerOrganizer::markSymbolAsUsed(name);
    }

    FunctionParametersNode* params = scope->getFunctionParameters(name);
    int requiredArgumentsCount = scope->getFunctionRequiredParamsCount(name);

    if (!arguments && requiredArgumentsCount > 0) {
        std::string message = "Missing " + std::to_string(requiredArgumentsCount) + " arguments";
        ErrorDetail error(Severity::ERROR, message);
        error.setLine(this->line);
        CompilerOrganizer::addError(error);
    }

    if (arguments && arguments->params.size() < requiredArgumentsCount) {
        std::string message = "Expected At Least " + std::to_string(requiredArgumentsCount) + " arguments, but got " + std::to_string(arguments->params.size());
        ErrorDetail error(Severity::ERROR, message);
        error.setLine(this->line);
        CompilerOrganizer::addError(error);
    }

    if (arguments && arguments->params.size() > params->names.size()) {
        std::string message = "Expected At Most " + std::to_string(params->names.size()) + " arguments, but got " + std::to_string(arguments->params.size());
        ErrorDetail error(Severity::ERROR, message);
        error.setLine(this->line);
        CompilerOrganizer::addError(error);
    }

    for (int i = 0; i < params->names.size(); i++) {
        if (i == arguments->params.size()) {
            arguments->addParameter(params->defaultValues[i]);
        } else {
            OperandType argumentType = TUNDEFINED;
            try { argumentType = arguments->params[i]->getExpectedType(scope); } catch(ErrorDetail error) { error.setLine(line); CompilerOrganizer::addError(error); }
    
            if ( !Utils::isValidAssignment(params->types[i]->type, argumentType) ) {
                ErrorDetail error(Severity::ERROR, "Argument type mismatch in position " + std::to_string(i + 1) + ", expected " 
                    + Utils::typeToString(params->types[i]->type) 
                    + " but got " + Utils::typeToString( arguments->params[i]->getType()));    
                error.setLine(line);
                CompilerOrganizer::addError(error);
            }
        }
    }

    CompilerOrganizer::markSymbolAsUsed(name, FUNCTION);

    return returnType;
}

Operand FunctionCallNode::getValue(Scope* scope) { 
    FunctionParametersNode* functionParameters = scope->getFunctionParameters(name);
    ScopeNode* functionScope = scope->scopeOf(name);

    for (int i = 0; i < functionParameters->names.size(); i++) { 
        functionScope->
        getScope()->
        defineVariable(functionParameters->names[i], functionParameters->types[i], arguments->params[i]->getValue(scope), false);
    }
    
    functionScope->run(scope);
    Operand returnValue = functionScope->valueOf("return");
    functionScope->getScope()->reset();

    if (returnValue.dataType->type == TVOID) {
        return Operand::voidValue();
    } else {
        return returnValue;
    }
}

std::string FunctionCallNode::generateQuadruples(Scope* scope) {
    for (int i = 0; i < arguments->params.size(); i++) { 
        CompilerOrganizer::addFunctionArgument(arguments->params[i]->generateQuadruples(scope));
    }
    
    return CompilerOrganizer::createQuadEntry(QUAD_FUNCTION_CALL, name, std::to_string(arguments->params.size()));
}