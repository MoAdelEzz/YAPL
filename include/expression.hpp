#pragma once
#include "common.hpp"
#include "organizer.hpp"
#include "math.h"

class Expression {
    protected:
        Expression *left;
        Expression *right;
        OperationType op;

        Operand nodeValue;
    public:
        Expression(Expression *l, Expression *r, OperationType op);

        Expression(const char* value, DataType* type);

        ~Expression();

        OperandType getType();

        virtual Operand calculateNodeValue(Expression* left, Expression* right, Scope* scope);

        virtual Operand getValue(Scope* scope = nullptr);

        virtual OperandType getExpectedType(Scope* scope = nullptr);
};

class StringContainer : public Expression {
    public:
        StringContainer(Expression *left, Expression *right, OperationType op);
        StringContainer(const char* value);
        
        Operand calculateNodeValue(Expression* left, Expression* right, Scope* scope);

        friend std::ostream& operator<<(std::ostream& os, const StringContainer& node);
};

class IdentifierContainer : public Expression {
    std::string varName;
    OperationType op;
    public:
        IdentifierContainer(std::string varName, OperationType op = OP_NONE);
        
        Operand getValue(Scope* scope = nullptr) override;

        OperandType getExpectedType(Scope* scope) override;

        friend std::ostream& operator<<(std::ostream& os, const IdentifierContainer& node);
};


