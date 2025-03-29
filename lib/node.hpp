#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include <string>
#include <math.h>
#include "identifier.hpp"
#include "program.hpp"

extern void yyerror(const char* s);

enum OperationType { 
    OP_ADD, OP_SUB, OP_MUL, OP_DIV, OP_MOD, 
    OP_EQ, OP_NEQ, OP_LT, OP_LE, OP_GT, OP_GE, 
    OP_AND, OP_OR, OP_XOR, OP_NOT, OP_SHL, OP_SHR,
    OP_POW, OP_SQRT, OP_NONE
};

class ExpressionNode {
    protected:
        ExpressionNode *left;
        ExpressionNode *right;
        OperationType op;

        Value nodeValue;
    public:
        ExpressionNode(ExpressionNode *l, ExpressionNode *r, OperationType op) : left(l), right(r), op(op) { }

        ExpressionNode(const char* value, ValueType type) {
            nodeValue.init(value, type);

        }
       
        ValueType inferResultType(ValueType type1, ValueType type2){
            if (type1 > type2) {
                ValueType temp = type1;
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

        virtual Value calculateNodeValue(ExpressionNode* left, ExpressionNode* right, Scope* scope) { 
            Value op1 = left->getValue(scope);
            Value op2 = right->getValue(scope);

            if (op == OP_SQRT) {
                float res = sqrt((float)op1);
                nodeValue.init(std::to_string(res).c_str(), TFLOAT);
                return nodeValue;
            }

            if (op == OP_POW) {
                float res = pow((float)op1, (float)op2);
                nodeValue.init(std::to_string(res).c_str(), TFLOAT);
                return nodeValue;
            }
            
            ValueType resType = inferResultType(op1.type, op2.type);
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
                        result = (int)op1 & (int)op2;  break;
                    case OP_OR: 
                        result = (int)op1 | (int)op2;  break;
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
                nodeValue.init(std::to_string(result).c_str(), resType);
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
                        throw("mod operation is not supported for float");
                        break;
                    case OP_AND: case OP_OR: case OP_XOR: case OP_SHL: case OP_SHR:
                        throw("bitwise operation is not supported for float");
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
                        break;
                }
                nodeValue.init(std::to_string(result).c_str(), resType);
            }
            
            return nodeValue;
        }

        ValueType getType() { return nodeValue.type; }

        virtual Value getValue(Scope* scope = nullptr) { 
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

        bool isZero() {
            if (nodeValue.content == nullptr) { getValue(); }
            
            switch (nodeValue.type) {
                case TINT: case TBOOLEAN: case TCHAR:
                    return (int)nodeValue == 0;
                case TFLOAT:
                    return (float)nodeValue == 0;
                case TSTRING:
                    return nodeValue.toString() == "";
                default:
                    return false;
            }

            return false;
        }

};

class StringNode : public ExpressionNode {
    public:
        StringNode(ExpressionNode *left, ExpressionNode *right, OperationType op) : ExpressionNode(left, right, op) {}
        StringNode(const char* value) : ExpressionNode(value, TSTRING) {}
        
        Value calculateNodeValue(ExpressionNode* left, ExpressionNode* right, Scope* scope) { 
            Value op1 = left->getValue(scope);
            Value op2 = right->getValue(scope);
            
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
            nodeValue.init(result.c_str(), TSTRING);
            return nodeValue;
        }

        friend std::ostream& operator<<(std::ostream& os, const StringNode& node) {
            // std::cout << "StringNode: ";
            os << *(std::string*)node.nodeValue.content;
            return os;
        }
};

class IdentifierNode : public ExpressionNode {
    std::string varName;
    public:
        IdentifierNode(std::string varName) : ExpressionNode(nullptr, TUNDEFINED), varName(varName) {}
        
        Value getValue(Scope* scope = nullptr) { 
            if (scope == nullptr) {
                std::cout << "Skill Issues" << std::endl;
            }

            return scope->valueOf(this->varName);
        }

        friend std::ostream& operator<<(std::ostream& os, const IdentifierNode& node) {
            // std::cout << "Identifier ( " << node.varName << " ): ";
            os << *(std::string*)node.nodeValue.content;
            return os;
        }
};

class VariableDefinitionNode : public ProgramNode {
    ExpressionNode* value;
    std::string name;
    ValueType type;
    
    public:
        VariableDefinitionNode( std::string type, std::string name, ExpressionNode* value) {            
            this->name = name;
            this->value = value;
            if (type == "int") { this->type = TINT; }
            else if (type == "float") { this->type = TFLOAT; }
            else if (type == "char") { this->type = TCHAR; }
            else if (type == "string") { this->type = TSTRING; }
            else if (type == "bool") { this->type = TBOOLEAN; }
        }

        void run(Scope* scope = nullptr) {
            scope->defineVariable(name, type, value->getValue(scope));
            // std::cout << scope->valueOf(name) << std::endl;       
        }
};

class VariableAssignmentNode: public ProgramNode {
    ExpressionNode* value;
    std::string name;
    
    public:
        VariableAssignmentNode( std::string name, ExpressionNode* value ) {            
            this->name = name;
            this->value = value;
            this->setNext(nullptr);
        }

        void run(Scope* scope = nullptr) {
            scope->assignVariable(name,  value->getValue(scope));
            // std::cout << "Assigning " << name << " = " << scope->valueOf(name) << std::endl;
        }
};


class PrintNode : public ProgramNode {
    ExpressionNode* data;
    public:
        PrintNode( ExpressionNode* data ) {
            this->data = data;
        }   

        void run(Scope* scope = nullptr) {
            std::cout << data->getValue(scope) << std::endl;
        }
};

// class ForNode : public ProgramNode {
//     ExpressionNode* value;
//     std::string name;
    
//     public:
//         ForNode(  ) {            
//             this->name = name;
//             this->value = value;
//             this->setNext(nullptr);
//         }

//         void run(Scope* scope = nullptr) {
//             scope->assignVariable(name,  value->getValue(scope));
//             std::cout << "Assigning " << name << " = " << scope->valueOf(name) << std::endl;
//         }
// }

#endif