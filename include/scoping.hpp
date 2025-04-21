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

    ScopeNode(int line, bool isFunction = false, bool breakable = false, bool continuable = false) 
    : returnable(isFunction), 
      breakable(breakable), 
      continuable(continuable),
      scope(new Scope()),
      ProgramNode(line) { if (line > 0) { this->logLineInfo(); } }  

    ScopeNode(int line, ProgramNode* next, bool isFunction = false) 
    : ProgramNode(line, nullptr), 
      returnable(isFunction),       
      breakable(false), 
      continuable(false),
      scope(new Scope()),
      nextChild(next) { if (line > 0) { this->logLineInfo(); } }  

    ScopeNode(int line, ScopeNode* node) 
    : ProgramNode(line), 
      scope(new Scope(node->scope)) { if (line > 0) { this->logLineInfo(); } }  

    ScopeNode(int line, Scope* scp) 
    : ProgramNode(line), 
      scope(new Scope(scp)) { if (line > 0) { this->logLineInfo(); } }  

    Scope* getScope() { return scope; }

    void resetScope() { scope->reset(); }

    virtual void runSemanticChecker(Scope* parentScope = nullptr) {
        this->scope->setParent(parentScope);
        ProgramNode* it = nextChild;
        while (it != nullptr) {
            it->runSemanticChecker(this->scope);
            it = it->getNext();
        }

        if (!scope->returned()) {
            this->scope->assignReturn(Operand::voidValue());
        }
        
        this->scope->reset();
    }


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
            parentScope->assignReturn(Operand::voidValue());
        }

        scope->reset();
    }

    std::string nodeName() {
        return "ScopeNode";
    } 

    Operand valueOf(std::string varName) { 
        return scope->valueOf(varName);
    }
};