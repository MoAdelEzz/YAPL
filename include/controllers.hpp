#pragma once
#include "program.hpp"

class ContinueNode : public ProgramNode {
    public:
        std::string nodeName() override {
            return "ContinueNode";
        }

        ContinueNode(int line) : ProgramNode(line) {
            this->logLineInfo();
        }

        void runSemanticChecker(Scope* scope = nullptr) override {
            
        }

        void run(Scope* scope = nullptr) override {
            scope->contScope();
        }

};


class BreakNode : public ProgramNode {
    public:
        void run(Scope* scope = nullptr) override {
            scope->breakScope();
        }

        void runSemanticChecker(Scope* scope = nullptr) override {
            
        }

        std::string nodeName() override {
            return "BreakNode";
        }
        
        BreakNode(int line) : ProgramNode(line) {
            this->logLineInfo();
        }

};