#pragma once
#include "common.hpp"
#include "math.h"

enum OperationType { 
    OP_ADD, OP_PRE_ADD, OP_POST_ADD, OP_SUB, OP_MUL, OP_DIV, OP_MOD, 
    OP_EQ, OP_PRE_SUB, OP_POST_SUB, OP_NEQ, OP_LT, OP_LE, OP_GT, OP_GE, 
    OP_AND, OP_BW_AND, OP_OR, OP_BW_OR, OP_NOT, OP_BW_NOT, OP_XOR, OP_SHL, OP_SHR,
    OP_POW, OP_SQRT, OP_NONE
};

class Expression {
    protected:
        Expression *left;
        Expression *right;
        OperationType op;

        Operand nodeValue;
    public:
        Expression(Expression *l, Expression *r, OperationType op) : left(l), right(r), op(op) {}

        Expression(const char* value, DataType* type) { nodeValue.init(value, type); }

        OperandType getType() { return nodeValue.dataType->type; }
    
        OperandType inferResultType(OperandType type1, OperandType type2) {
            if (type1 == TVOID || type2 == TVOID) { return TUNDEFINED; }

            if (type1 > type2) {
                OperandType temp = type1;
                type1 = type2;
                type2 = temp;
            }

            if (type1 == TBOOLEAN && type2 <= TFLOAT) {
                return TBOOLEAN;
            }

            if (type1 == TINT && type2 <= TFLOAT) {
                return type1 > type2 ? type1 : type2;
            }

            if (type1 == TCHAR) {
                return type2 == TFLOAT ? TFLOAT : TCHAR;
            }

            if (type1 == TFLOAT && type2 <= TFLOAT) {
                return TFLOAT;
            }

            return TUNDEFINED;
        }

        virtual Operand calculateNodeValue(Expression* left, Expression* right, Scope* scope) { 
            Operand op1 = left->getValue(scope);
            Operand op2 = right->getValue(scope);

            if (op1.dataType->type == TVOID || op2.dataType->type == TVOID) {
                throw std::runtime_error("Invalid Operand Type");
            }

            if (op == OP_SQRT) {
                float res = sqrt((float)op1);
                nodeValue.init(std::to_string(res).c_str(), DataType::Float());
                return nodeValue;
            }

            if (op == OP_POW) {
                float res = pow((float)op1, (float)op2);
                nodeValue.init(std::to_string(res).c_str(), DataType::Float());
                return nodeValue;
            }

            OperandType resType = inferResultType(op1.dataType->type, op2.dataType->type);

            if (op == OP_AND || op == OP_OR || op == OP_NOT) {
                resType = TBOOLEAN;
            }

            if (resType == TINT || resType == TBOOLEAN || resType == TCHAR) {
                int result = 0;
                switch (op) {
                    case OP_ADD:
                        result = (int)op1 + (int)op2;   break;
                    case OP_SUB:
                        result = (int)op1 - (int)op2;   break;
                    case OP_MUL:
                        result = (int)op1 * (int)op2;   break;
                    case OP_DIV:
                        if ((int)op2 == 0) { result = 0; }
                        else {result = (int)op1 / (int)op2;}   
                        break;
                    case OP_MOD:
                        result = (int)op1 % (int)op2;   break;
                    case OP_AND:
                        result = (int)op1 && (int)op2;  break;
                    case OP_BW_AND:
                        result = (int)op1 && (int)op2;  break;
                    case OP_BW_OR:
                        result = (int)op1 | (int)op2;   break;
                    case OP_NOT:
                        result = !(int)op1;             break;
                    case OP_BW_NOT:
                        result = ~(int)op1;             break;
                    case OP_OR: 
                        result = (int)op1 || (int)op2;  break;
                    case OP_XOR:
                        result = (int)op1 ^ (int)op2;  break;
                    case OP_EQ:
                        result = (int)op1 == (int)op2;  break;
                    case OP_NEQ:
                        result = (int)op1 != (int)op2;  break;
                    case OP_LT:
                        result = (int)op1 < (int)op2;   break;
                    case OP_LE:
                        result = (int)op1 <= (int)op2;  break;
                    case OP_GT:
                        result = (int)op1 > (int)op2;   break;
                    case OP_GE:
                        result = (int)op1 >= (int)op2;  break;
                    case OP_SHL:
                        result = (int)op1 << (int)op2;  break;
                    case OP_SHR:
                        result = (int)op1 >> (int)op2;  break;
                    default:
                        break;
                }
                nodeValue.init(std::to_string(result).c_str(), new DataType(resType));
            } else {
                float result = 0;
                switch (op) {
                    case OP_ADD:
                        result = (float)op1 + (float)op2;   break;
                    case OP_SUB:
                        result = (float)op1 - (float)op2;   break;
                    case OP_MUL:
                        result = (float)op1 * (float)op2;   break;
                    case OP_DIV:
                        result = (float)op1 / (float)op2;   break;
                    case OP_MOD:
                        throw std::runtime_error("mod operation is not supported for float");
                        break;
                    case OP_AND:
                        result = (float)op1 && (float)op2;  break;
                    case OP_NOT:
                        result = !(float)op1;               break;
                    case OP_BW_AND: case OP_BW_OR: case OP_BW_NOT: case OP_XOR: case OP_SHL: case OP_SHR:
                        throw std::runtime_error("bitwise operation is not supported for float");
                        break;
                    case OP_EQ:
                        result = (float)op1 == (float)op2;  break;
                    case OP_NEQ:
                        result = (float)op1 != (float)op2;  break;
                    case OP_LT:
                        result = (float)op1 < (float)op2;   break;
                    case OP_LE:
                        result = (float)op1 <= (float)op2;  break;
                    case OP_GT:
                        result = (float)op1 > (float)op2;   break;
                    case OP_GE:
                        result = (float)op1 >= (float)op2;  break;
                    default:
                        throw std::runtime_error("unknown operation");
                        break;
                }
                nodeValue.init(std::to_string(result).c_str(), new DataType(resType));
            }
            
            return nodeValue;
        }

        virtual Operand getValue(Scope* scope = nullptr) { 
            if (left == nullptr && right == nullptr) {
                return nodeValue;
            } else if (left != nullptr && right == nullptr) {
                this->nodeValue = left->getValue(scope);
            } else if (left == nullptr && right != nullptr) {
                this->nodeValue = right->getValue(scope);
            } else {
                this->nodeValue = calculateNodeValue(left, right, scope);
            }
            return this->nodeValue;
        }
};

class StringContainer : public Expression {
    public:
        StringContainer(Expression *left, Expression *right, OperationType op) : Expression(left, right, op) {}
        StringContainer(const char* value) : Expression(value, DataType::String()) {}
        
        Operand calculateNodeValue(Expression* left, Expression* right, Scope* scope) 
        { 
            Operand op1 = left->getValue(scope);
            Operand op2 = right->getValue(scope);

            if (op1.dataType->type == TVOID || op2.dataType->type == TVOID) {
                throw std::runtime_error("void operation is not supported for string");
            }
            
            std::string result = "";
            switch (op) {
                case OP_ADD:
                    result = op1.toString() + op2.toString();   
                    break;

                case OP_SUB:
                    result = op1.toString();
                    for (int i = 0; i < (int)op2; i++) {
                        result.pop_back();
                    }
                    break;

                case OP_MUL:
                    result = op1.toString();
                    for (int i = 0; i < (int)op2; i++) { result += op1.toString(); }
                    break;

                case OP_SHL:
                    result = op2.toString() + " " + op1.toString(); break;

                case OP_SHR:
                    result = op1.toString() + " " + op2.toString(); break;

                case OP_EQ:
                    result = op1.toString() == op2.toString();  break;

                case OP_NEQ:
                    result = op1.toString() != op2.toString();  break;

                case OP_LT:
                    result = op1.toString() < op2.toString();   break;

                case OP_LE:
                    result = op1.toString() <= op2.toString();  break;

                case OP_GT:
                    result = op1.toString() > op2.toString();   break;

                case OP_GE:
                    result = op1.toString() >= op2.toString();  break;

                default: break;
            }
            nodeValue.init(result.c_str(), DataType::String());
            return nodeValue;
        }

        friend std::ostream& operator<<(std::ostream& os, const StringContainer& node) {
            os << *(std::string*)node.nodeValue.content;
            return os;
        }
};

class IdentifierContainer : public Expression {
    std::string varName;
    OperationType op;
    public:
        IdentifierContainer(std::string varName, OperationType op = OP_NONE) 
        : Expression(nullptr, DataType::Undefined()), varName(varName), op(op)  {}
        
        Operand getValue(Scope* scope = nullptr) { 
            Operand value = scope->valueOf(this->varName);
            switch (op) {
                case OP_PRE_ADD: 
                    scope->assignVariable(varName, value + 1);
                    return value + 1; 
                case OP_POST_ADD:
                    scope->assignVariable(varName, value + 1);
                    return value;
                case OP_PRE_SUB: 
                    scope->assignVariable(varName, value + -1);
                    return value + -1; 
                case OP_POST_SUB:
                    scope->assignVariable(varName, value + -1);
                    return value;
                default:
                    return value;
            }
        }

        friend std::ostream& operator<<(std::ostream& os, const IdentifierContainer& node) {
            os << *(std::string*)node.nodeValue.content;
            return os;
        }
};


