#pragma once
#include "program.hpp"

class ContinueNode : public ProgramNode {
    public:
        ContinueNode(int line);

        std::string nodeName() override;

        void run(Scope* scope = nullptr) override;
        void runSemanticChecker(Scope* scope = nullptr) override;
        void generateQuadruples(Scope* scope = nullptr) override;
};


class BreakNode : public ProgramNode {
    public:
        BreakNode(int line);

        std::string nodeName() override;

        void run(Scope* scope = nullptr) override;
        void runSemanticChecker(Scope* scope = nullptr) override;
        void generateQuadruples(Scope* scope = nullptr) override;
};