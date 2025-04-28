#pragma once
#include <iostream>

enum OperationType { 
    OP_ADD, OP_PRE_ADD, OP_POST_ADD, OP_SUB, OP_MUL, OP_DIV, OP_MOD, OP_UMINUS,
    OP_EQ, OP_PRE_SUB, OP_POST_SUB, OP_NEQ, OP_LT, OP_LE, OP_GT, OP_GE, 
    OP_AND, OP_BW_AND, OP_OR, OP_BW_OR, OP_NOT, OP_BW_NOT, OP_XOR, OP_SHL, OP_SHR,
    OP_POW, OP_SQRT, OP_NONE, QUAD_GOTO_IF_TRUE, QUAD_GOTO_IF_FALSE, QUAD_GOTO, QUAD_LABEL,
    QUAD_PRINT, QUAD_ASSIGN, QUAD_DECLARE, QUAD_FUNCTION_START, QUAD_FUNCTION_END, QUAD_FUNCTION_ARGUMENT,
    QUAD_FUNCTION_RETURN, QUAD_FUNCTION_CALL
};



inline std::string opToString(OperationType op) { 
    switch (op) {
        case OP_ADD: return "ADD"; 
        case OP_SUB: return "SUB"; 
        case OP_MUL: return "MUL"; 
        case OP_DIV: return "DIV"; 
        case OP_MOD: return "MOD"; 
        case OP_UMINUS: return "NEG"; 
        case OP_EQ: return "EQ"; 
        case OP_NEQ: return "NEQ"; 
        case OP_LT: return "LT"; 
        case OP_LE: return "LTE"; 
        case OP_GT: return "GT"; 
        case OP_GE: return "GTE";
        case OP_AND: return "AND"; 
        case OP_OR: return "OR"; 
        case OP_NOT: return "NOT"; 
        case OP_XOR: return "XOR"; 
        case OP_SHL: return "SHL"; 
        case OP_SHR: return "SHR"; 
        case OP_POW: return "POW"; 
        case OP_SQRT: return "SQRT";
        case QUAD_GOTO_IF_TRUE: return "JNZ";
        case QUAD_GOTO_IF_FALSE: return "JZ";
        case QUAD_GOTO: return "JMP";
        case QUAD_PRINT: return "PRINT";
        case QUAD_ASSIGN: return "ASSIGN";
        case QUAD_DECLARE: return "DECLARE";
        case QUAD_LABEL: return "LABEL";
        case QUAD_FUNCTION_START: return "FUNC_START";
        case QUAD_FUNCTION_END: return "FUNC_END";
        case QUAD_FUNCTION_ARGUMENT: return "ARG";
        case QUAD_FUNCTION_RETURN: return "RET";
        case QUAD_FUNCTION_CALL: return "CALL";
        default: return "";
    }   
}

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
            if (lhs == TVOID    && rhs == TVOID)        return true;

            if (lhs == TSTRING  && rhs < TVOID)    return true;
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