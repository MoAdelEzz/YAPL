#pragma once
#include "common.hpp"
#include "expression.hpp"

class ProgramNode {
    protected:
        ProgramNode* next = nullptr;

    public:
        ProgramNode() {}
        ProgramNode(ProgramNode* next) : next(next) {}
        ProgramNode* setNext(ProgramNode* next) { 
            this->next = next; 
            return this; 
        }
        ProgramNode* getNext() { return next; }

        virtual void run(Scope* scope = nullptr) {
            ProgramNode* it = next;
            while (it) {
                it->run(scope);
                it = next->next;
            }
        }
};


class PrintNode : public ProgramNode {
    Expression* body;
    public:
        PrintNode( Expression* body ) {
            this->body = body;
        }   

        void run(Scope* scope = nullptr) {
            std::cout << body->getValue(scope) << std::endl;
        }
};