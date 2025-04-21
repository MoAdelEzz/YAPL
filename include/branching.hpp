#pragma once
#include "errorHandler.hpp"
#include "program.hpp"
#include "expression.hpp"
#include "scoping.hpp"
#include <string>

class IfNode : public ProgramNode {
    Expression* condition;
    ProgramNode* accept;
    ProgramNode* reject;

    public:
        std::string nodeName() override {
            return "IfNode";
        }

        IfNode( int line, Expression* condition, ProgramNode* accept ) : ProgramNode(line) {
            this->condition = condition;
            this->accept = accept;
            this->logLineInfo();
        }   

        IfNode* setElse(ProgramNode* reject) { this->reject = reject; return this; }

        void run(Scope* scope = nullptr) override {
            bool conditionResult;
            try {
                conditionResult = condition->getValue(scope) != 0;
            } catch (ErrorDetail error) {
                error.setLine(this->line);
                CompilerOrganizer::addError(error);
            }

            if (conditionResult) {

                try {
                    accept->run(scope);
                } catch (ErrorDetail error) {
                    error.setLine(this->line);
                    CompilerOrganizer::addError(error);
                }

            } else if (reject) {
                try {
                    reject->run(scope);
                } catch (ErrorDetail error) {
                    error.setLine(this->line);
                    CompilerOrganizer::addError(error);
                }
            }
        }
};

class CaseNode : public ProgramNode {
    Expression* condition;
    ScopeNode* body;
    public:
        bool isMatched = false;

        std::string nodeName() override {
            return "CaseNode";
        }

        CaseNode( int line, Expression* condition = nullptr) : ProgramNode(line) {
            this->condition = condition;
            this->body = nullptr;
            this->logLineInfo();
        }

        CaseNode* assignBody(ProgramNode* node) {
            body = new ScopeNode(-1, node);
            return this;
        }


        void runSemanticChecker(Scope* scope = nullptr) override {
            body->runSemanticChecker(scope); 
        }

        void run(Scope *scope = nullptr, Expression* identifier = nullptr, bool forceMatch = false) {
            bool isSatisfied = false;

            try {
                isSatisfied = forceMatch || condition == nullptr || condition->getValue(scope) == identifier->getValue(scope);
            } catch(ErrorDetail error) {
                error.setLine(this->line);
                CompilerOrganizer::addError(error);
            }

            if (isSatisfied) {
                try {
                    body->run(scope);
                } catch (ErrorDetail error) {
                    error.setLine(this->line);
                    CompilerOrganizer::addError(error);
                }
                
                isMatched = true;
            }
            else {
                isMatched = false;
            }
        }
        

        bool breakCalled() { return body->getScope()->isBroke(); }
};

class SwitchBody {
    std::vector<CaseNode*> cases;

    public:
        SwitchBody() {}
        SwitchBody(CaseNode* cn) { addCase(cn); }
        SwitchBody* addCase(CaseNode* caseNode) { cases.push_back(caseNode); return this; }
        std::vector<CaseNode*> getCases() { return cases; }
};


class SwitchNode : public ProgramNode {
    Expression* identifier;
    SwitchBody* body;

    public:
        std::string nodeName() override {
            return "SwitchNode";
        }
        
        SwitchNode( int line, std::string id, SwitchBody* body ) : ProgramNode(line) { 
            this->body = body;
            this->identifier = new IdentifierContainer(id);
            this->logLineInfo();
        }

        void runSemanticChecker(Scope* scope = nullptr) override {
            ScopeNode* SwitchScope = new ScopeNode(-1, scope);
            SwitchScope->breakable = true;

            if (body) {
                bool caseMatched = false;
                for (CaseNode* caseNode : body->getCases()) {
                    caseNode->runSemanticChecker(scope);
                }
            }
        }

        void run(Scope* scope = nullptr) override {
            ScopeNode* SwitchScope = new ScopeNode(-1, scope);
            SwitchScope->breakable = true;

            if (body) {
                bool caseMatched = false;
                for (CaseNode* caseNode : body->getCases()) {
                    caseNode->run(SwitchScope->getScope(), identifier, caseMatched);
                    caseMatched |= caseNode->isMatched;
                    if (SwitchScope->getScope()->isBroke()) break;
                }
            }
        }
}; 




