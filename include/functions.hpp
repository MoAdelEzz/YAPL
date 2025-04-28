#pragma once
#include "common.hpp"
#include "scoping.hpp"
#include "program.hpp"
#include "expression.hpp"
#include <string>

class FunctionDefintionNode : public ProgramNode {
    DataType* returnType = nullptr;
    std::string name;
    FunctionParametersNode* parameters = nullptr;
    ScopeNode* body = nullptr;
    
    public:
        FunctionDefintionNode( int line, DataType* returnType, std::string name, FunctionParametersNode* params, ScopeNode* body);
        ~FunctionDefintionNode();
        
        std::string nodeName() override;

        void run(Scope* scope = nullptr) override;
        void runSemanticChecker(Scope* scope = nullptr) override;
        void generateQuadruples(Scope* scope = nullptr) override;
};


class FunctionCallNode : public Expression {
    int line;
    std::string name;
    FunctionCallParametersNode* arguments = nullptr;
    
    public:
        FunctionCallNode(int line, std::string name, FunctionCallParametersNode* arguments);

        ~FunctionCallNode();
        
        OperandType getExpectedType(Scope* scope = nullptr) override;
        Operand getValue(Scope* scope = nullptr) override;
        std::string generateQuadruples(Scope* scope) override;
    };