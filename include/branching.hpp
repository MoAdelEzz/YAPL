#pragma once
#include "program.hpp"
#include "expression.hpp"
#include "scoping.hpp"
#include <string>

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


class CaseNode : public ProgramNode {
    Expression* condition;
    ScopeNode* body;
    public:
        bool isMatched = false;

        CaseNode( Expression* condition = nullptr) {
            this->condition = condition;
            this->body = nullptr;
        }

        CaseNode* assignBody(ProgramNode* node) {
            body = new ScopeNode(node);
            return this;
        }

        void run(Scope *scope = nullptr, Expression* identifier = nullptr, bool forceMatch = false) {
            if (forceMatch || condition == nullptr || condition->getValue(scope) == identifier->getValue(scope)) {
                body->run(scope);
                isMatched = true;
            }
            else {
                isMatched = false;
            }
        }

        bool breakCalled() { return body->getScope()->isBroke(); }

        std::string nodeName() override {
            return "CaseNode";
        }
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
        SwitchNode(std::string id, SwitchBody* body) { 
            this->body = body;
            this->identifier = new IdentifierContainer(id);
        }

        void run(Scope* scope = nullptr) {
            ScopeNode* SwitchScope = new ScopeNode(scope);
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




