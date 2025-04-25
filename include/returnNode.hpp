#pragma once
#include "common.hpp"
#include "enums.hpp"
#include "expression.hpp"
#include "program.hpp"

class ReturnNode : public ProgramNode {
    Expression* value;
  public:
    std::string nodeName() {
        return "ReturnNode";
    } 

    ReturnNode(int line, Expression* value) : ProgramNode(line) {
        this->value = value;
        this->setNext(nullptr);
        this->setLine(line);
    }

    ReturnNode(int line) : ProgramNode(line) {
        this->setNext(nullptr);
    }

    ~ReturnNode() {
        if (value) delete value;
    }

    void runSemanticChecker(Scope* scope = nullptr) {
        if (!scope->canReturn()) {
            ErrorDetail error(Severity::ERROR, "Return Statement Not Allowed Here");
            error.setLine(this->line);
            CompilerOrganizer::addError(error);
        } else {
            try {
                OperandType valueType = TUNDEFINED; 
                try {
                    valueType = value == nullptr ? TVOID : value->getExpectedType(scope);
                } catch (ErrorDetail error) {
                    error.setLine(this->line);
                    CompilerOrganizer::addError(error);
                }
                scope->validReturn(valueType);
            } catch(ErrorDetail error) {
                error.setLine(this->line);
                CompilerOrganizer::addError(error);
            }
        }
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
};