#include "functions.hpp"

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
    scope->defineFunction(returnType, name, parameters, body);
    body->getScope()->defineReturn(returnType);
}

void FunctionDefintionNode::runSemanticChecker(Scope* scope) {
    try {
        scope->defineFunction(returnType, name, parameters, body);
    } catch( ErrorDetail error ) {
        error.setLine(line);
        CompilerOrganizer::addError(error);
    }

    Scope* functionScope = body->getScope();

    functionScope->defineReturn(returnType);

    for (int i = 0; i < parameters->names.size(); i++) {
        functionScope->defineVariable(parameters->names[i], parameters->types[i], Operand::undefined());
    }

    body->runSemanticChecker(scope);
    functionScope->reset();
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

    return returnType;
}

Operand FunctionCallNode::getValue(Scope* scope) { 
    FunctionParametersNode* functionParameters = scope->getFunctionParameters(name);
    ScopeNode* functionScope = scope->scopeOf(name);

    for (int i = 0; i < functionParameters->names.size(); i++) { 
        if (!Utils::isValidAssignment(functionParameters->types[i]->type, arguments->params[i]->getType())) { 
            throw std::runtime_error("Argument type mismatch"); 
        }

        functionScope->
        getScope()->
        defineVariable(functionParameters->names[i], functionParameters->types[i], arguments->params[i]->getValue(scope));
    }

    functionScope->run(scope);
    Operand returnValue = functionScope->valueOf("return");
    functionScope->getScope()->reset();

    if (returnValue.dataType->type != scope->getFunctionReturnType(name)) {
        std::cout << "Mismatch in return type" << std::endl;
        throw std::runtime_error("Return Type Mismatch");
        return Operand::undefined();
    } else if (returnValue.dataType->type == TVOID) {
        return Operand::voidValue();
    } else {
        return returnValue;
    }
}