#pragma once
#include "common.hpp"
#include "scoping.hpp"
#include "program.hpp"
#include "expression.hpp"
#include <vector>

class FunctionDefintionNode : public ProgramNode {
    DataType* returnType;
    std::string name;
    FunctionParametersNode* parameters;
    ScopeNode* body;
    
    public:

        FunctionDefintionNode( DataType* returnType, std::string name, FunctionParametersNode* params, ScopeNode* body) {   
            this->name = name;
            this->parameters = params ? params : new FunctionParametersNode();
            this->body = body;
            this->returnType = returnType;
        }

        void run(Scope* scope = nullptr) {
            scope->defineFunction(returnType, name, parameters, body);
        }
};


class FunctionCallNode : public Expression {
    std::string name;
    FunctionCallParametersNode* arguments;
    
    public:
        FunctionCallNode(std::string name, FunctionCallParametersNode* arguments) : Expression(nullptr, DataType::Undefined()) {   
            this->name = name;
            this->arguments = arguments ? arguments : new FunctionCallParametersNode();
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