#pragma once
#include "common.hpp"
#include "program.hpp"

class ScopeNode : public ProgramNode {
    Scope* scope = nullptr;
    ProgramNode* nextChild = nullptr;
    
public:
    bool returnable = false;
    bool breakable = false;
    bool continuable = false;

    ScopeNode(bool isFunction = false, bool breakable = false, bool continuable = false) : returnable(isFunction) { scope = new Scope(); }  

    ScopeNode(ProgramNode* next, bool isFunction = false) : ProgramNode(nullptr), returnable(isFunction) {
        scope = new Scope();
        nextChild = next;
    }

    ScopeNode(ScopeNode* node) {
        scope = new Scope(node->scope);
    }

    ScopeNode(Scope* scp) {
        this->scope = new Scope(scp);
    }

    Scope* getScope() { return scope; }

    void resetScope() { scope->reset(); }

    void run(Scope* parentScope = nullptr) {
        this->scope->setParent(parentScope);
        ProgramNode* it = nextChild;
        while (it != nullptr) {
            it->run(this->scope);

            if (scope->returned()) {
                if ( !returnable && parentScope != nullptr ) {
                    parentScope->assignReturn(scope->valueOf("return"));
                }
                break;
            }

            if (scope->isBroke()) {
                if ( !breakable && parentScope != nullptr ) {
                    parentScope->breakScope();
                }
                break;
            }

            if (scope->isContinued()) {
                if ( !continuable && parentScope != nullptr ) {
                    parentScope->contScope();
                }
                break;
            }

            it = it->getNext();
        }

        if (!scope->returned()) {
            this->scope->assignReturn(Operand::voidValue());
        }
    }

    std::string nodeName() {
        return "ScopeNode";
    } 

    Operand valueOf(std::string varName) { 
        return scope->valueOf(varName);
    }
};