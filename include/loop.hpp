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
        std::string nodeName() override { return "ForNode"; }

        ForNode( int line, DefineNode* preLoop, Expression* condition, ProgramNode* postLoop, ScopeNode* body ) : ProgramNode(false) {  
            this->preLoop = preLoop; 
            this->condition = condition; 
            this->postLoop = postLoop; 
            this->body = body; 
            this->setLine(line);
        }

        void run(Scope* scope = nullptr) override {
            ScopeNode* forScope = new ScopeNode(scope);
            preLoop->run(forScope->getScope());
            forScope->breakable = true;
            forScope->continuable = true;

            while (condition->getValue(forScope->getScope()) != 0) {
                body->run(forScope->getScope());
                postLoop->run(forScope->getScope());
                body->resetScope();

                if (forScope->getScope()->isBroke()) {
                    break;
                }
            }
        }
};

class WhileNode : public ProgramNode {
    Expression* condition;
    ScopeNode* body;

    public:
        std::string nodeName() override { return "WhileNode"; }

        WhileNode( int line, Expression* condition, ScopeNode* body ) : ProgramNode(false) {
            this->condition = condition; 
            this->body = body; 
            this->setLine(line);        
        }

        void run(Scope* scope = nullptr) override {
            body->breakable = true;
            body->continuable = true;

            while (condition->getValue(scope) != 0) {
                body->run(scope);
                body->resetScope();

                if (body->getScope()->isBroke()) {
                    break;
                }
            }
        }
};

class DoWhileNode: public ProgramNode {
    Expression* condition;
    ScopeNode* body;

    public:
        std::string nodeName() override { return "DoWhileNode"; }

        DoWhileNode( int line, Expression* condition, ScopeNode* body ) : ProgramNode(false) {
            this->condition = condition; 
            this->body = body; 
            this->setLine(line);
        }

        void run(Scope* scope = nullptr) override {
            body->breakable = true;
            body->continuable = true;

            do {
                body->run(scope);
                body->resetScope();
                if (body->getScope()->isBroke()) {
                    break;
                }
            } while (condition->getValue(scope) != 0);
        }
};