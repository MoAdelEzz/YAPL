#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include <string>
#include <unordered_map>
#include <utility>
#include "identifier.hpp"


extern void yyerror(const char* s);

class Scope {
    private:
        Scope* parent = nullptr;
        std::unordered_map<std::string, std::pair<ValueType, Value>> variables;
    public:
        Scope() { this->parent = nullptr; }
        Scope(Scope* parent) { this->parent = parent; }
        Scope* getParent() { return parent; }
        void setParent(Scope* parent) { this->parent = parent; }

        void defineVariable(std::string varName, ValueType type, Value value) { 
            if (variables.find(varName) == variables.end()) {
                variables[varName] = {type, value}; 
            } else {
                throw std::runtime_error("Variable " + varName + " has already been declared");
            }
        }    

        void assignVariable(std::string varName, Value value) {
            const auto& it = variables.find(varName);
            if (it != variables.end()) {
                //TODO: change this later
                if (variables[varName].first == value.type) {
                    variables[varName].second = value;
                } else {
                    throw std::runtime_error("Variable " + varName + " type mismatch");
                }
                
            } else if (parent != nullptr) {
                parent->assignVariable(varName, value);
            } else {
                throw std::runtime_error("Variable " + varName + " not found");
            }
        }
        
        Value valueOf(std::string varName) { 
            if (variables.find(varName) != variables.end()) {
                return variables[varName].second;
            }  else if (parent != nullptr) {
                return parent->valueOf(varName);
            } else {
                throw std::runtime_error("Variable " + varName + " not found");
                return Value();
            }
        }

        ValueType typeOf(std::string varName) {
            if (variables.find(varName) != variables.end()) {
                return variables[varName].first;
            } else if (parent != nullptr) {
                return parent->typeOf(varName);
            } else {
                throw std::runtime_error("Variable " + varName + " not found");
                return TINT;
            }
        }
};

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

    void run(Scope* parentScope = nullptr) {
        this->scope->setParent(parentScope);
        ProgramNode* it = nextChild;
        while (it != nullptr) {
            it->run(this->scope);
            it = it->getNext();
        }
    }

    Value valueOf(std::string varName) { 
        return scope->valueOf(varName);
    }
};


#endif