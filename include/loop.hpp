#pragma once
#include "common.hpp"
#include "errorHandler.hpp"
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

        ForNode( int line, DefineNode* preLoop, Expression* condition, ProgramNode* postLoop, ScopeNode* body ) : ProgramNode(line) {  
            this->preLoop = preLoop; 
            this->condition = condition; 
            this->postLoop = postLoop; 
            this->body = body; 
            this->logLineInfo();
        }

        void checkCondition(ScopeNode* forScope) {
            if (condition == nullptr) {
                throw "Possible Infinite Loop";
            }

            if (condition->getExpectedType() > TSTRING) {
                throw "Something Wrong With The Operation inside the condition";
            }
        }

        bool getLoopCondition(ScopeNode* forScope) {
            bool loopCondition = false;
            try {
                loopCondition = condition != nullptr && condition->getValue(forScope->getScope()) != 0;
            } catch(ErrorDetail error) {
                error.setLine(this->line);
                CompilerOrganizer::addError(error);
                return false;
            }
            return loopCondition;
        }

        virtual void runSemanticChecker(Scope* scope = nullptr) override {
            ScopeNode* forScope = new ScopeNode(-1, scope);
            forScope->breakable = true;
            forScope->continuable = true;
            
            preLoop->runSemanticChecker(forScope->getScope());
            checkCondition(forScope);
            body->runSemanticChecker(forScope->getScope());
            postLoop->runSemanticChecker(forScope->getScope());

            // delete forScope;
        }

        void run(Scope* scope = nullptr) override {
            ScopeNode* forScope = new ScopeNode(-1, scope);
            preLoop->run(forScope->getScope());
            forScope->breakable = true;
            forScope->continuable = true;

            while (getLoopCondition(forScope)) {
                try {
                    body->run(forScope->getScope());
                } catch (ErrorDetail error) {
                    error.setLine(this->line);
                    CompilerOrganizer::addError(error);
                    break;
                }
                
                try {
                    postLoop->run(forScope->getScope());
                } catch (ErrorDetail error) {
                    error.setLine(this->line);
                    CompilerOrganizer::addError(error);
                    break;
                }

                body->resetScope();

                bool isScopeBroke = false;
                try {
                    isScopeBroke = forScope->getScope()->isBroke();
                } catch (ErrorDetail error) {
                    error.setLine(this->line);
                    CompilerOrganizer::addError(error);
                    break;
                }
                
                if (isScopeBroke) {
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

        WhileNode( int line, Expression* condition, ScopeNode* body ) : ProgramNode(line) {
            this->condition = condition; 
            this->body = body; 
            this->logLineInfo();        
        }

        bool getLoopCondition(Scope* whileScope) {
            bool loopCondition = false;
            try {
                loopCondition = condition != nullptr && condition->getValue(whileScope) != 0;
            } catch(ErrorDetail error) {
                error.setLine(this->line);
                CompilerOrganizer::addError(error);
                return false;
            }
            return loopCondition;
        }

        void checkCondition(ScopeNode* forScope) {
            if (condition == nullptr) {
                throw "Possible Infinite Loop";
            }

            if (condition->getExpectedType() > TSTRING) {
                throw "Something Wrong With The Operation inside the condition";
            }
        }

        virtual void runSemanticChecker(Scope* scope = nullptr) override {
            ScopeNode* forScope = new ScopeNode(-1, scope);
            forScope->breakable = true;
            forScope->continuable = true;
            
            checkCondition(forScope);
            body->runSemanticChecker(forScope->getScope());

            // delete forScope;
        }

        void run(Scope* scope = nullptr) override {
            body->breakable = true;
            body->continuable = true;

            while (getLoopCondition(scope)) {
                try {
                    body->run(scope);
                } catch (ErrorDetail error) {
                    error.setLine(this->line);
                    CompilerOrganizer::addError(error);
                    break;
                }

                body->resetScope();

                bool isScopeBroke = false;
                try {
                    isScopeBroke = body->getScope()->isBroke();
                } catch (ErrorDetail error) {
                    error.setLine(this->line);
                    CompilerOrganizer::addError(error);
                    break;
                }

                if (isScopeBroke) {
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

        DoWhileNode( int line, Expression* condition, ScopeNode* body ) : ProgramNode(line) {
            this->condition = condition; 
            this->body = body; 
            this->logLineInfo();
        }

        bool getLoopCondition(Scope* whileScope) {
            bool loopCondition = false;
            try {
                loopCondition = condition != nullptr && condition->getValue(whileScope) != 0;
            } catch(ErrorDetail error) {
                error.setLine(this->line);
                CompilerOrganizer::addError(error);
                return false;
            }
            return loopCondition;
        }

        void checkCondition(ScopeNode* forScope) {
            if (condition == nullptr) {
                throw "Possible Infinite Loop";
            }

            if (condition->getExpectedType() > TSTRING) {
                throw "Something Wrong With The Operation inside the condition";
            }
        }

        virtual void runSemanticChecker(Scope* scope = nullptr) override {
            ScopeNode* forScope = new ScopeNode(-1, scope);
            forScope->breakable = true;
            forScope->continuable = true;
            
            checkCondition(forScope);
            body->runSemanticChecker(forScope->getScope());

            // delete forScope;
        }


        void run(Scope* scope = nullptr) override {
            body->breakable = true;
            body->continuable = true;

            do {
                try {
                    body->run(scope);
                } catch (ErrorDetail error) {
                    error.setLine(this->line);
                    CompilerOrganizer::addError(error);
                    break;
                }

                body->resetScope();

                bool isScopeBroke = false;
                try {
                    isScopeBroke = body->getScope()->isBroke();
                } catch (ErrorDetail error) {
                    error.setLine(this->line);
                    CompilerOrganizer::addError(error);
                    break;
                }

                if (isScopeBroke) {
                    break;
                }
            } while (getLoopCondition(scope));
        }
};