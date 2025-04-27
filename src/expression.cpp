#include "expression.hpp"
#include "enums.hpp"
#include "organizer.hpp"
// =========================================================================================
// ====================================== Expression ======================================
// =========================================================================================

Expression::Expression(Expression *l, Expression *r, OperationType op) : left(l), right(r), op(op) {}

Expression::Expression(const char* value, DataType* type) { 
    if (type->type == TCHAR) {
        nodeValue.init(std::to_string((int)value[0]).c_str(), type);
    } else {
        nodeValue.init(value, type); 
    }
}

Expression::~Expression() {
    if (left != nullptr) delete left, left = nullptr;
    if (right != nullptr) delete right, right = nullptr;
}

OperandType Expression::getType() { return nodeValue.dataType->type; }

Operand Expression::calculateNodeValue(Expression* left, Expression* right, Scope* scope) { 
    Operand op1 = left->getValue(scope);
    Operand op2 = right->getValue(scope);

    if (op1.dataType->type == TVOID || op2.dataType->type == TVOID) {
        ErrorDetail error(Severity::ERROR, "void operation is not supported");
        throw error;
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

    OperandType resType = Utils::operationType(op1.dataType->type, op2.dataType->type);

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
            case OP_UMINUS:
                result = -(int)op1;             break;
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
            case OP_UMINUS:
                result = -(float)op1;               break;
            case OP_MUL:
                result = (float)op1 * (float)op2;   break;
            case OP_DIV:
                result = (float)op1 / (float)op2;   break;
            case OP_MOD:
                throw ErrorDetail(Severity::ERROR, "mod operation is not supported for float");
                break;
            case OP_AND:
                result = (float)op1 && (float)op2;  break;
            case OP_NOT:
                result = !(float)op1;               break;
            case OP_BW_AND: case OP_BW_OR: case OP_BW_NOT: case OP_XOR: case OP_SHL: case OP_SHR:
                throw ErrorDetail(Severity::ERROR, "bitwise operation is not supported for float");
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

Operand Expression::getValue(Scope* scope) { 
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

bool validateOperation(OperandType type1, OperandType type2, OperationType op) { 
    return !isBitwiseOperation(op) || (type1 != TFLOAT && type2 != TFLOAT);
}

std::string Expression::generateQuadruples(Scope* scope) {
    if (left != nullptr && right != nullptr) {
        std::string llabel = left->generateQuadruples();
        std::string rlabel = right->generateQuadruples();
        return CompilerOrganizer::createQuadEntry(op, llabel, rlabel);
    } else if (left != nullptr) {
        return left->generateQuadruples();
    } else if (right != nullptr) {
        return right->generateQuadruples();
    } else {
        return nodeValue.toString();
    }
}

OperandType Expression::getExpectedType(Scope* scope) {
    if (left == nullptr && right == nullptr) {
        return nodeValue.dataType->type;
    } else if (left != nullptr && right == nullptr) {
        return left->getExpectedType(scope);
    } else if (left == nullptr && right != nullptr) {
        return right->getExpectedType(scope);
    } else {
        OperandType op1 = left->getExpectedType(scope);
        OperandType op2 = right->getExpectedType(scope);
        if (!validateOperation(op1, op2, op)) {
            std::string message = op == OP_MOD ? "mod operation is not supported for float" : "bitwise operation is not supported for float";
            throw ErrorDetail(Severity::ERROR, message);
        }
        return Utils::operationType(left->getExpectedType(scope), right->getExpectedType(scope));
    }
    return TUNDEFINED;
}

// =========================================================================================
// =================================-== String Container ===================================
// =========================================================================================

StringContainer::StringContainer(Expression *left, Expression *right, OperationType op) : Expression(left, right, op) {}
StringContainer::StringContainer(const char* value) : Expression(value, DataType::String()) {}

Operand StringContainer::calculateNodeValue(Expression* left, Expression* right, Scope* scope) { 
    Operand op1 = left->getValue(scope);
    Operand op2 = right->getValue(scope);

    if (op1.dataType->type == TVOID || op2.dataType->type == TVOID) {
        throw ErrorDetail(Severity::ERROR, "void operation is not supported for string");
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

std::ostream& operator<<(std::ostream& os, const StringContainer& node) {
    os << *(std::string*)node.nodeValue.content;
    return os;
}

// =========================================================================================
// ================================== Identifier Container =================================
// =========================================================================================

IdentifierContainer::IdentifierContainer(std::string varName, OperationType op) 
: Expression(nullptr, DataType::Undefined()), varName(varName), op(op)  {}


std::string IdentifierContainer::generateQuadruples(Scope* scope) {
    if (op == OP_PRE_ADD) {
        CompilerOrganizer::addQuadruple(OP_ADD, varName, "1", varName);
        return varName;
    } else if (op == OP_POST_ADD) {
        std::string res = CompilerOrganizer::createQuadEntry(QUAD_ASSIGN, varName, "");
        CompilerOrganizer::addQuadruple(OP_ADD, varName, "1", varName);
        return res;
    } else if (op == OP_PRE_SUB) {
        CompilerOrganizer::addQuadruple(OP_SUB, varName, "1", varName);
        return varName;
    } else if (op == OP_POST_SUB) {
        std::string res = CompilerOrganizer::createQuadEntry(QUAD_ASSIGN, varName, "");
        CompilerOrganizer::addQuadruple(OP_SUB, varName, "1", varName);
        return res;
    } else {
        return varName;
    }
}

Operand IdentifierContainer::getValue(Scope* scope) { 
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

OperandType IdentifierContainer::getExpectedType(Scope* scope) {
    OperandType type = scope->typeOf(varName);
    bool isInitialized = scope->isInitialized(varName);

    if (op == OP_PRE_ADD || op == OP_POST_ADD || op == OP_PRE_SUB || op == OP_POST_SUB) {
        if (scope->isConstVariable(varName)) {
            throw ErrorDetail(Severity::ERROR, "Variable " + varName + " is constant and cannot be assigned");
        }
    }

    if (type == TUNDEFINED) {
        throw ErrorDetail(Severity::ERROR, "Variable " + varName + " is not defined");
    } else if (!isInitialized) {
        throw ErrorDetail(Severity::ERROR, "Variable " + varName + " was used before it was initialized");
    } else {
        CompilerOrganizer::markSymbolAsUsed(varName);
    }
    return scope->typeOf(varName);
}

std::ostream& operator<<(std::ostream& os, const IdentifierContainer& node) {
    os << *(std::string*)node.nodeValue.content;
    return os;
}