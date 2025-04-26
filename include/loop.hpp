#pragma once
#include "common.hpp"
#include "program.hpp"
#include "var-op.hpp"
#include "scoping.hpp"

class ForNode : public ProgramNode {
    DefineNode* preLoop;
    Expression* condition;
    ProgramNode* postLoop;
    ScopeNode* body;

    public:
        
        ForNode( int line, DefineNode* preLoop, Expression* condition, ProgramNode* postLoop, ScopeNode* body );
        ~ForNode();
        
        std::string nodeName() override;

        void checkCondition(Scope* forScope);
        bool getLoopCondition(Scope* forScope);

        void generateQuadruples(Scope* scope) override;
        void run(Scope* scope = nullptr) override;
        void runSemanticChecker(Scope* scope = nullptr) override;
};

class WhileNode : public ProgramNode {
    Expression* condition;
    ScopeNode* body;

    public:
        WhileNode( int line, Expression* condition, ScopeNode* body );
        ~WhileNode();
        
        std::string nodeName() override;

        bool getLoopCondition(Scope* whileScope);
        void checkCondition(Scope* whileScope);
        
        void generateQuadruples(Scope* scope) override;
        void run(Scope* scope = nullptr) override;
        void runSemanticChecker(Scope* scope = nullptr) override;
};

class DoWhileNode: public ProgramNode {
    Expression* condition;
    ScopeNode* body;

    public:
        DoWhileNode( int line, Expression* condition, ScopeNode* body );
        ~DoWhileNode();
    
        std::string nodeName() override;

        bool getLoopCondition(Scope* whileScope);
        void checkCondition(Scope* doWhileScope);

        void generateQuadruples(Scope* scope) override;
        void run(Scope* scope = nullptr) override;
        void runSemanticChecker(Scope* scope = nullptr) override;
};