#pragma once
#include "program.hpp"
#include "expression.hpp"

class IfNode : public ProgramNode {
    Expression* condition;
    ProgramNode* accept;
    ProgramNode* reject;

    public:
        IfNode( Expression* condition, ProgramNode* accept ) {
            this->condition = condition;
            this->accept = accept;
        }   

        IfNode* setElse(ProgramNode* reject) { this->reject = reject; return this; }

        void run(Scope* scope = nullptr) {
            if (condition->getValue(scope) != 0) {
                accept->run(scope);
            } else if (reject) {
                reject->run(scope);
            }
        }
};