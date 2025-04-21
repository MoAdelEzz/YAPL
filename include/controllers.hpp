#pragma once
#include "program.hpp"

class ContinueNode : public ProgramNode {
    public:
        std::string nodeName() override {
            return "ContinueNode";
        }

        ContinueNode(int line) : ProgramNode(false) {
            this->setLine(line);
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

        std::string nodeName() override {
            return "BreakNode";
        }
        
        BreakNode(int line) : ProgramNode(false) {
            this->setLine(line);
        }

};