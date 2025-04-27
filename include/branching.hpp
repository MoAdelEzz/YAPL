#pragma once
#include "common.hpp"
#include "program.hpp"
#include "expression.hpp"
#include "scoping.hpp"
#include "var-op.hpp"
#include <string>

class IfNode : public ProgramNode {
    Expression* condition;
    AssignNode* assignment;
    ProgramNode* accept;
    ProgramNode* reject;
    bool inverted;

    public:
        IfNode( int line, Expression* condition, ProgramNode* accept, bool inverted = false  );  
        IfNode( int line, AssignNode* assignment, ProgramNode* accept );  
        ~IfNode();

        std::string nodeName() override;
        IfNode* setElse(ProgramNode* reject);

        void run(Scope* scope = nullptr) override;
        void runSemanticChecker(Scope* scope) override;
        void generateQuadruples(Scope* scope) override;
};

class CaseNode : public ProgramNode {
    Expression* condition;
    ScopeNode* body;
    public:
        bool isMatched = false;
        int skipConditionLabel = 0;
        std::string varName;

        CaseNode( int line, Expression* condition = nullptr);
        ~CaseNode();

        std::string nodeName() override;
        CaseNode* assignBody(ProgramNode* node);

        void run(Scope *scope = nullptr, Expression* identifier = nullptr, bool forceMatch = false);
        void runSemanticChecker(Scope* scope = nullptr) override;
        void generateQuadruples(Scope* scope) override;
};

class SwitchBody {
    std::vector<CaseNode*> cases;
    std::vector<int> labels;

    public:
        SwitchBody();
        SwitchBody(CaseNode* cn);
        ~SwitchBody();
        
        SwitchBody* addCase(CaseNode* caseNode);
        std::vector<CaseNode*> getCases();
        int getCaseLabel(int index);

        void generateCaseLabels(std::string varName);
};


class SwitchNode : public ProgramNode {
    IdentifierContainer* identifier;
    SwitchBody* body;

    public:
        SwitchNode( int line, std::string id, SwitchBody* body );
        ~SwitchNode();

        std::string nodeName() override;

        void run(Scope* scope = nullptr) override;
        void runSemanticChecker(Scope* scope = nullptr) override;
        void generateQuadruples(Scope* scope) override;
}; 