#pragma once
#include "program.hpp"
#include "var-op.hpp"
#include "scoping.hpp"

class ForNode : public ProgramNode {
    DefineNode* preLoop;
    Expression* condition;
    ProgramNode* postLoop;
    ScopeNode* body;

    public:
        ForNode( DefineNode* preLoop, Expression* condition, ProgramNode* postLoop, ScopeNode* body ) {
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
    Expression* condition;
    ScopeNode* body;

    public:
        WhileNode( Expression* condition, ScopeNode* body ) {
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
    Expression* condition;
    ScopeNode* body;

    public:
        DoWhileNode( Expression* condition, ScopeNode* body ) {
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