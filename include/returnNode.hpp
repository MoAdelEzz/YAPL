#pragma once
#include "expression.hpp"
#include "program.hpp"

class ReturnNode : public ProgramNode {
    Expression* value;
  public:
    ReturnNode(Expression* value) {
        this->value = value;
        this->setNext(nullptr);
    }

    ReturnNode() {
        this->setNext(nullptr);
    }


    void run(Scope* parentScope = nullptr) {
        if (parentScope == nullptr) {
            throw std::runtime_error("No parent scope to return");
        } else if (value == nullptr) {
            parentScope->assignReturn(Operand::voidValue());
        } else {
            parentScope->assignReturn(value->getValue(parentScope));
        }
    }

    std::string nodeName() {
        return "ReturnNode";
    } 
};