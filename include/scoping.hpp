#pragma once
#include "program.hpp"

class ScopeNode : public ProgramNode {
    Scope* scope = nullptr;
    ProgramNode* nextChild = nullptr;

  public:
    ScopeNode() {
        scope = new Scope();
    }  

    ScopeNode(ProgramNode* next) : ProgramNode(nullptr) {
        scope = new Scope();
        nextChild = next;
    }

    ScopeNode(ScopeNode* node) {
        scope = new Scope(node->scope);
    }

    Scope* getScope() { return scope; }

    void resetScope() { scope->reset(); }

    void run(Scope* parentScope = nullptr) {
        this->scope->setParent(parentScope);
        ProgramNode* it = nextChild;
        while (it != nullptr) {
            it->run(this->scope);
            it = it->getNext();
        }
    }

    Operand valueOf(std::string varName) { 
        return scope->valueOf(varName);
    }
};