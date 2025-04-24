#pragma once
#include "common.hpp"
#include "organizer.hpp"
#include "program.hpp"

extern int scopeDepth;

class ScopeNode : public ProgramNode {
    Scope* scope = nullptr;
    ProgramNode* nextChild = nullptr;
    
public:
    bool haltLogging = false;

    ScopeNode(int line, bool isFunction = false, bool breakable = false, bool continuable = false) 
    :
      scope(new Scope()),
      ProgramNode(line) { if (line > 0) { this->logLineInfo(); } }  

    ScopeNode(int line, ProgramNode* next, bool isFunction = false) 
    : ProgramNode(line, nullptr), 
      scope(new Scope()),
      nextChild(next) { if (line > 0) { this->logLineInfo(); } }  

    ScopeNode(int line, ScopeNode* node) 
    : ProgramNode(line), 
      scope(new Scope(node->scope)) { if (line > 0) { this->logLineInfo(); } }  

    ScopeNode(int line, Scope* scp) 
    : ProgramNode(line), 
      scope(new Scope(scp)) { if (line > 0) { this->logLineInfo(); } }  

    ~ScopeNode() {
        if (scope) delete scope;
        if (nextChild) delete nextChild;
    }

    Scope* getScope() { return scope; }

    void resetScope() { scope->reset(); }

    virtual void runSemanticChecker(Scope* parentScope = nullptr) {
        if (!haltLogging) {
            scopeDepth++;
            CompilerOrganizer::addSymbolTableEntry(SymbolTableEntry::scopeEntry());
        }

        this->scope->setParent(parentScope);
        ProgramNode* it = nextChild;
        while (it != nullptr) {
            it->runSemanticChecker(this->scope);
            it = it->getNext();
        }
        
        this->scope->reset();
        
        if (!haltLogging) {
            CompilerOrganizer::addSymbolTableEntry(SymbolTableEntry::scopeExit());
            scopeDepth--;
        }
    }

    void run(Scope* parentScope = nullptr) {
        scopeDepth++;

        this->scope->setParent(parentScope);
        ProgramNode* it = nextChild;
        while (it != nullptr) {
            it->run(this->scope);

            if (scope->hasReturned() || scope->hasBreak() || scope->hasContinued()) {
                break;
            }

            it = it->getNext();
        }
        
        scopeDepth--;
    }
    


    std::string nodeName() {
        return "ScopeNode";
    } 

    Operand valueOf(std::string varName) { 
        return scope->valueOf(varName);
    }
};