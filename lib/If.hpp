#pragma once

#include "program.hpp"
#include "node.hpp"

class IfNode : public ProgramNode {
    ExpressionNode* condition;
    ProgramNode* accept;
    ProgramNode* reject;

public:

    IfNode(ExpressionNode* cond, ProgramNode* acc) {
        condition = cond;
        accept = acc;
    }

    IfNode(ExpressionNode* cond, ProgramNode* acc, ProgramNode* rej) {
        condition = cond;
        accept = acc;
        reject = rej;
    }

    void setElse(ProgramNode* rej) {
        reject = rej;
    }

    void run() {
        if (condition->getValue() == 0) {

        } else {

        }
    }
};