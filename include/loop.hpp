#pragma once
#include "common.hpp"
#include "program.hpp"
#include "var-op.hpp"
#include "scoping.hpp"

class ForNode : public ProgramNode {
    ProgramNode* preLoop = nullptr;
    Expression* condition = nullptr;
    AssignNode* assignment = nullptr;
    ProgramNode* postLoop = nullptr;
    ScopeNode* body = nullptr;
    bool inverted;

    public:
        
        ForNode( int line, ProgramNode* preLoop, Expression* condition, ProgramNode* postLoop, ScopeNode* body, bool inverted = false);
        ForNode( int line, ProgramNode* preLoop, AssignNode* assignment, ProgramNode* postLoop, ScopeNode* body );
        ~ForNode();
        
        std::string nodeName() override;

        void checkCondition(Scope* forScope);
        bool getLoopCondition(Scope* forScope);

        void generateQuadruples(Scope* scope) override;
        void run(Scope* scope = nullptr) override;
        void runSemanticChecker(Scope* scope = nullptr) override;
};

class WhileNode : public ProgramNode {
    Expression* condition = nullptr;
    AssignNode* assignment = nullptr;
    ScopeNode* body = nullptr;
    bool inverted;

    public:
        WhileNode( int line, Expression* condition, ScopeNode* body, bool inverted = false);
        WhileNode( int line, AssignNode* assignment, ScopeNode* body );
        ~WhileNode();
        
        std::string nodeName() override;

        bool getLoopCondition(Scope* whileScope);
        void checkCondition(Scope* whileScope);
        
        void generateQuadruples(Scope* scope) override;
        void run(Scope* scope = nullptr) override;
        void runSemanticChecker(Scope* scope = nullptr) override;
};

class DoWhileNode: public ProgramNode {
    Expression* condition = nullptr;
    AssignNode* assignment = nullptr;
    ScopeNode* body = nullptr;
    bool inverted;

    public:
        DoWhileNode( int line, Expression* condition, ScopeNode* body, bool inverted = false );
        DoWhileNode( int line, AssignNode* condition, ScopeNode* body );
        ~DoWhileNode();
    
        std::string nodeName() override;

        bool getLoopCondition(Scope* whileScope);
        void checkCondition(Scope* doWhileScope);

        void generateQuadruples(Scope* scope) override;
        void run(Scope* scope = nullptr) override;
        void runSemanticChecker(Scope* scope = nullptr) override;
};