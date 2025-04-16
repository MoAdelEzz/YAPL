#pragma once
#include "program.hpp"

class ContinueNode : public ProgramNode {
    public:

        void run(Scope* scope = nullptr) override {
            scope->contScope();
        }

        std::string nodeName() override {
            return "ContinueNode";
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
};