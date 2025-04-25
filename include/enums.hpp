#pragma once
#include <iostream>

enum OperationType { 
    OP_ADD, OP_PRE_ADD, OP_POST_ADD, OP_SUB, OP_MUL, OP_DIV, OP_MOD, OP_UMINUS,
    OP_EQ, OP_PRE_SUB, OP_POST_SUB, OP_NEQ, OP_LT, OP_LE, OP_GT, OP_GE, 
    OP_AND, OP_BW_AND, OP_OR, OP_BW_OR, OP_NOT, OP_BW_NOT, OP_XOR, OP_SHL, OP_SHR,
    OP_POW, OP_SQRT, OP_NONE
};

inline bool isBitwiseOperation(OperationType op) {
    switch (op) {
        case OP_MOD:
        case OP_BW_AND:
        case OP_BW_OR:
        case OP_BW_NOT:
        case OP_XOR:
        case OP_SHL:
        case OP_SHR:
            return true;
        default:
            return false;
    }
}


enum OperandType { TBOOLEAN, TINT, TCHAR, TFLOAT, TSTRING, TVOID, TUNDEFINED };

class Utils {
    public:
        static OperandType operationType(OperandType op1, OperandType op2) {
            if (op1 == TUNDEFINED || op2 == TUNDEFINED) return TUNDEFINED;
            if (op1 == TVOID || op2 == TVOID)           return TUNDEFINED;

            if (op1 < op2) std::swap(op1, op2);
            
            if (op1 == TSTRING)    return TSTRING;
            if (op1 == TFLOAT)     return TFLOAT;
            if (op1 == TCHAR)      return TCHAR;
            if (op1 == TINT)       return TINT;
            if (op1 == TBOOLEAN)   return TBOOLEAN;

            return TUNDEFINED;
        }


        static bool isValidAssignment(OperandType lhs, OperandType rhs) {
            if (lhs == TUNDEFINED || rhs == TUNDEFINED) return false;
            if (lhs == TVOID    || rhs == TVOID)        return false;

            if (lhs == TSTRING  && rhs != TVOID)    return true;
            if (lhs == TBOOLEAN && rhs < TSTRING)   return true;
            if (lhs == TINT     && rhs < TSTRING)   return true;
            if (lhs == TCHAR    && rhs < TSTRING)   return true;
            if (lhs == TFLOAT   && rhs < TSTRING)    return true;

            return false;
        }

        static std::string typeToString(OperandType type) {
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
                case TVOID:
                    return "void";
                default:
                    return "undefined";
            }
        }
        
        static int typeToSize(OperandType type) {
            switch (type) {
                case TINT:
                    return sizeof(int);
                case TFLOAT:
                    return sizeof(float);
                case TCHAR:
                    return sizeof(char);
                case TBOOLEAN:
                    return sizeof(int);
                default:
                    return 0;
            }
        }

};