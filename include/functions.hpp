#pragma once
#include "common.hpp"
#include "errorHandler.hpp"
#include "scoping.hpp"
#include "program.hpp"
#include "expression.hpp"
#include <string>
#include <vector>

class FunctionDefintionNode : public ProgramNode {
    DataType* returnType;
    std::string name;
    FunctionParametersNode* parameters;
    ScopeNode* body;
    
    public:
        std::string nodeName() override { return "FunctionDefintionNode"; }

        FunctionDefintionNode( int line, DataType* returnType, std::string name, FunctionParametersNode* params, ScopeNode* body) 
        : ProgramNode(line) {   
            this->name = name;
            this->parameters = params ? params : new FunctionParametersNode();
            this->body = body;
            this->returnType = returnType;
            this->logLineInfo();
        }

        virtual void runSemanticChecker(Scope* scope = nullptr) override {
            try {
                scope->defineFunction(returnType, name, parameters, body);
            } catch( ErrorDetail error ) {
                error.setLine(line);
                CompilerOrganizer::addError(error);
            }
        }


        void run(Scope* scope = nullptr) override {
            try {
                scope->defineFunction(returnType, name, parameters, body);
            } catch (ErrorDetail error) {
                error.setLine(this->line);
                CompilerOrganizer::addError(error);
            }
        }
};


class FunctionCallNode : public Expression {
    int line;
    std::string name;
    FunctionCallParametersNode* arguments;
    
    public:
        FunctionCallNode(int line, std::string name, FunctionCallParametersNode* arguments) : Expression(nullptr, DataType::Undefined()) {   
            this->name = name;
            this->arguments = arguments ? arguments : new FunctionCallParametersNode();
            this->line = line;
        }

        virtual OperandType getExpectedType(Scope* scope = nullptr) {
            return scope->getFunctionReturnType(name);
        }

        Operand getValue(Scope* scope = nullptr) { 
            FunctionParametersNode* functionParameters = scope->getFunctionParameters(name);
            ScopeNode* functionScope = scope->scopeOf(name);

            for (int i = 0; i < functionParameters->names.size(); i++) { 
                // TODO: you can relax this a lil bit if we just look if the type can be matched instead of being exactly the same
                if (arguments->params[i]->getType() != functionParameters->types[i]->type) { 
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
};