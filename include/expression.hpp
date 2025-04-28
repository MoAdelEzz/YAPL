#pragma once
#include "common.hpp"
#include "organizer.hpp"
#include "math.h"

class Expression {
    protected:
        Expression *left = nullptr;
        Expression *right = nullptr;
        OperationType op;

        Operand nodeValue;
        std::string quadContainer;
    public:
        Expression(Expression *l, Expression *r, OperationType op);

        Expression(const char* value, DataType* type);

        ~Expression();

        OperandType getType();

        virtual std::string generateQuadruples(Scope* scope = nullptr);

        virtual Operand calculateNodeValue(Expression* left, Expression* right, Scope* scope);

        virtual Operand getValue(Scope* scope = nullptr);

        virtual OperandType getExpectedType(Scope* scope = nullptr);
};

class StringContainer : public Expression {
    public:
        StringContainer(Expression *left, Expression *right, OperationType op);
        StringContainer(const char* value);
        
        Operand calculateNodeValue(Expression* left, Expression* right, Scope* scope) override;

        friend std::ostream& operator<<(std::ostream& os, const StringContainer& node);
};

class IdentifierContainer : public Expression {
    std::string varName;
    OperationType op;
    public:
        IdentifierContainer(std::string varName, OperationType op = OP_NONE);
        
        std::string getIdentifier() { return varName; }

        std::string generateQuadruples(Scope* scope) override;
        Operand getValue(Scope* scope = nullptr) override;
        OperandType getExpectedType(Scope* scope) override;

        friend std::ostream& operator<<(std::ostream& os, const IdentifierContainer& node);
};


