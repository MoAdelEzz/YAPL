#include <iostream>
#include <string>
#include <math.h>
#include <vector>

extern void yyerror(const char* s);

enum ValueType { TBOOLEAN, TINT, TCHAR, TFLOAT, TSTRING, TUNDEFINED };

enum OperationType { 
    OP_ADD, OP_SUB, OP_MUL, OP_DIV, OP_MOD, 
    OP_EQ, OP_NEQ, OP_LT, OP_LE, OP_GT, OP_GE, 
    OP_AND, OP_OR, OP_XOR, OP_NOT, OP_SHL, OP_SHR,
    OP_POW, OP_SQRT, OP_NONE
};

class ProgramNode {
    std::vector<ProgramNode> children;

    public:
        ProgramNode() {}
        ProgramNode(std::vector<ProgramNode> children) : children(children) {}
        std::vector<ProgramNode> getChildren() { return children; }
        void addChild(ProgramNode child) { children.push_back(child); }

        virtual void run() {}
};

class Value {
    public:
        void* content;
        ValueType type;

        void init(const char* value, ValueType type) {
            this->type = type;
            if (value == nullptr) { return; }
            content = malloc(typeToSize(type));
            switch (type) {
                case TINT:
                    *(int*)content = atoi(value); break;
                case TFLOAT:
                    *(float*)content = atof(value); break;
                case TCHAR:
                    *(char*)content = value[0]; break;
                case TSTRING:
                    *(std::string*)content = std::string(value); break;
                default: break;
            }
        }
        
        static std::string typeToString(ValueType type) {
            switch (type) {
                case TINT:
                    return "int";
                case TFLOAT:
                    return "float";
                case TCHAR:
                    return "char";
                case TBOOLEAN:
                    return "boolean";
                case TSTRING:
                    return "string";
                default:
                    return "undefined";
            }
        }
        
        static int typeToSize(ValueType type) {
            switch (type) {
                case TINT:
                    return sizeof(int);
                case TFLOAT:
                    return sizeof(float);
                case TCHAR:
                    return sizeof(int);
                case TBOOLEAN:
                    return sizeof(int);
                default:
                    return 0;
            }
        }

        std::string toString() const {
            switch (type) {
                case TINT: case TBOOLEAN: case TCHAR:
                    return std::to_string((int) *(int*)content);
                case TFLOAT:
                    return std::to_string((float) *(float*)content);
                case TSTRING:
                    return *(std::string*)content;
                default:
                    return "undefined";
            }
        }

        operator int() const {
            switch (type) {
                case TINT: case TBOOLEAN: case TCHAR:
                    return (int) *(int*)content;
                case TFLOAT:
                    return (int) *(float*)content;
                default:
                    return 0;
            }
        }

        operator float() const {
            switch (type) {
                case TINT: case TBOOLEAN: case TCHAR:
                    return (float) *(int*)content;
                case TFLOAT:
                    return (float) *(float*)content;
                default:
                    return 0;
            }
        }

        operator char() const {
            switch (type) {
                case TINT: case TBOOLEAN: case TCHAR:
                    return (char) (int) *(int*)content;
                case TFLOAT:
                    return (char) (int) *(float*)content;
                default:
                    return 0;
            }
        }

        operator bool() const {
            switch (type) {
                case TINT: case TBOOLEAN: case TCHAR:
                    return *(int*)content != 0;
                case TFLOAT:
                    return *(float*)content != 0;
                default:
                    return 0;
            }
        }

        friend std::ostream& operator<<(std::ostream& os, const Value& node) {
            switch (node.type) {
                case TINT:
                    os << (int)node;
                    break;
                case TFLOAT:
                    os << (float)node;
                    break;
                case TCHAR:
                    os << (char)node;
                    break;
                case TBOOLEAN:
                    os << (bool)node;
                    break;
                default:
                    throw("WTF Bro");
            }
            return os;
        }
};


class ExpressionNode : public ProgramNode {
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

        Value calculateNodeValue(ExpressionNode* left, ExpressionNode* right) { 
            Value op1 = left->getValue();
            Value op2 = right->getValue();

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
            bool castToInt = resType == TINT;

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

        Value getValue() { 
            if (left == nullptr && right == nullptr) {
                return nodeValue;
            } else if (left != nullptr && right == nullptr) {
                return left->getValue();
            } else if (left == nullptr && right != nullptr) {
                return right->getValue();
            } else {
                return calculateNodeValue(left, right);
            }
        }

        friend std::ostream& operator<<(std::ostream& os, const ExpressionNode& node) {
            switch (node.nodeValue.type) {
                case TINT:
                    os << (int)node.nodeValue;
                    break;
                case TFLOAT:
                    os << (float)node.nodeValue;
                    break;
                case TCHAR:
                    os << (char)node.nodeValue;
                    break;
                case TBOOLEAN:
                    os << (bool)node.nodeValue;
                    break;
                default:
                    throw("WTF Bro");
            }
            return os;
        }
};


class StringNode : public ExpressionNode {
    public:
        StringNode(StringNode* left, StringNode* right, OperationType op) : ExpressionNode(left, right, op) {}
        StringNode(ExpressionNode *left, ExpressionNode *right, OperationType op) : ExpressionNode(left, right, op) {}
        StringNode(const char* value) : ExpressionNode(nullptr, TSTRING) {}
        
        
        Value calculateNodeValue(ExpressionNode* left, ExpressionNode* right) { 
            Value op1 = left->getValue();
            Value op2 = right->getValue();
            
            ValueType resType = inferResultType(op1.type, op2.type);
            bool castToInt = resType == TINT;

            Value res;
            std::string result = "";
            switch (op) {
                case OP_ADD:
                    result = op1.toString() + op2.toString();   break;

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
            res.init(result.c_str(), resType);
            return res;
        }

};