#pragma once

#include "node.hpp"
#include "program.hpp"


class ForNode : public ProgramNode {
    VariableDefinitionNode* preLoop;
    ExpressionNode* condition;
    ProgramNode* postLoop;
    ScopeNode* body;

    public:
        ForNode( VariableDefinitionNode* preLoop, ExpressionNode* condition, ProgramNode* postLoop, ScopeNode* body ) {
            this->preLoop = preLoop; 
            this->condition = condition; 
            this->postLoop = postLoop; 
            this->body = body; 
        }

        void run(Scope* scope = nullptr) {
            preLoop->run(scope);
            while (condition->getValue(scope) != 0) {
                body->run(scope);
                postLoop->run(scope);
            }
        }
};
