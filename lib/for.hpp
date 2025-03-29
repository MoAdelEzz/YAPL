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
                body->resetScope();
            }
        }
};


class WhileNode : public ProgramNode {
    ExpressionNode* condition;
    ScopeNode* body;

    public:
        WhileNode( ExpressionNode* condition, ScopeNode* body ) {
            this->condition = condition; 
            this->body = body; 
        }

        void run(Scope* scope = nullptr) {
            while (condition->getValue(scope) != 0) {
                body->run(scope);
                body->resetScope();
            }
        }
};


class DoWhileNode: public ProgramNode {
    ExpressionNode* condition;
    ScopeNode* body;

    public:
        DoWhileNode( ExpressionNode* condition, ScopeNode* body ) {
            this->condition = condition; 
            this->body = body; 
        }

        void run(Scope* scope = nullptr) {
            do {
                body->run(scope);
                body->resetScope();
            } while (condition->getValue(scope) != 0);
        }
};
