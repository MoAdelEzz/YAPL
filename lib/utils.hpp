#include <cstdlib>
#include <math.h>
#include <iostream>
#include <string>
#include <sys/stat.h>
#define IsInt(type) (type == TINT || type == TBOOLEAN || type == TCHAR)

extern void yyerror(const char* s);
enum ValueType { TBOOLEAN, TINT, TCHAR, TFLOAT, TSTRING, TUNDEFINED };

class ExpressionNode {
    public:
        void* value;
        enum ValueType type;
        ExpressionNode(char* value, enum ValueType type) : type(type), value(nullptr) {
            if (value == nullptr) {
                return;
            }

            this->value = malloc(typeToSize(type));
            switch (type) {
                case TINT:
                    *(int*)this->value = atoi(value);
                    break;
                case TFLOAT:
                    *(float*)this->value = atof(value);
                    break;
                case TCHAR:
                    *(char*)this->value = value[0];
                    break;
                case TSTRING:
                    *(std::string**)this->value = new std::string(value);
                    break;
                default:
                    break;
            }
        }

        ValueType getType() { return type; }
        void* getValue() { return value; }

        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////// Casts ////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        operator int() const {
            return *(int*)value;
        }

        operator float() const {
            if (type == TSTRING) {
                throw("Cannot cast string to float");
            }
            if (type == TINT || type == TBOOLEAN || type == TCHAR) {
                return (float) *(int*)value;
            }
            return *(float*)value;
        }

        operator char() const {
            if (type == TSTRING) {
                throw("Cannot cast string to char");
            }

            if (type == TFLOAT) {
                throw("Cannot cast float to char");
            }

            if (type == TBOOLEAN) {
                return *(int*)value != 0 ? 'T' : 'F';
            }

            return *(char*)value;
        }

        operator bool() const {
            if (type == TSTRING) {
                throw("Cannot cast string to char");
            }

            return *(int*)value != 0;
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

        static ValueType inferResultType(ValueType type1, ValueType type2){
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

        friend std::ostream& operator<<(std::ostream& os, const ExpressionNode& node) {
            switch (node.type) {
                case TINT:
                    os << *(int*)node.value;
                    break;
                case TFLOAT:
                    os << *(float*)node.value;
                    break;
                case TCHAR:
                    os << *(char*)node.value;
                    break;
                case TBOOLEAN:
                    os << *(bool*)node.value;
                    break;
                default:
                    throw("WTF Bro");
            }
            return os;
        }
};

class MathNode : public ExpressionNode {
    public:
        MathNode(char* value, enum ValueType type) : ExpressionNode(value, type) {};
        
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /////////////////////////////////////////////////// Operators Overloading ////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        bool isNonZero() {
            if (type == TFLOAT) {
                return *(float*)value != 0;
            }
            return *(int*)value != 0;
        }


        MathNode& operator+(MathNode that) {
            ValueType inferedType = inferResultType(this->type, that.type);

            void* resultValue = nullptr;
            switch (inferedType) {
                case TINT: case TCHAR: case TBOOLEAN:
                    resultValue = (void *)malloc(sizeof(int));
                    *(int*)resultValue = (int)(*this) + (int)(that);
                    break;
                case TFLOAT:
                    resultValue = (void *)malloc(sizeof(float));
                    *(float*)resultValue = (float)(*this) + (float)(that);
                    break;
                default:
                    throw("WTF Bro");
            }

            free(value);
            value = resultValue;
            type = inferedType;
            return *this;
        }

        MathNode& operator-(MathNode that) {
            ValueType inferedType = inferResultType(this->type, that.type);

            void* resultValue = nullptr;
            switch (inferedType) {
                case TINT: case TCHAR: case TBOOLEAN:
                    resultValue = (void *)malloc(sizeof(int));
                    *(int*)resultValue = (int)(*this) - (int)(that);
                    break;
                case TFLOAT:
                    resultValue = (void *)malloc(sizeof(float));
                    *(float*)resultValue = (float)(*this) - (float)(that);
                    break;
                default:
                    throw("WTF Bro");
            }

            free(value);
            value = resultValue;
            type = inferedType;
            return *this;
        }

        MathNode& operator*(MathNode that) {
            ValueType inferedType = inferResultType(this->type, that.type);

            void* resultValue = nullptr;
            switch (inferedType) {
                case TINT: case TCHAR: case TBOOLEAN:
                    resultValue = (void *)malloc(sizeof(int));
                    *(int*)resultValue = (int)(*this) * (int)(that);
                    break;
                case TFLOAT:
                    resultValue = (void *)malloc(sizeof(float));
                    *(float*)resultValue = (float)(*this) * (float)(that);
                    break;
                default:
                    throw("WTF Bro");
            }

            free(value);
            value = resultValue;
            type = inferedType;
            return *this;
        }

        MathNode& operator/(MathNode that) {
            ValueType inferedType = inferResultType(this->type, that.type);

            void* resultValue = nullptr;
            switch (inferedType) {
                case TINT: case TCHAR: case TBOOLEAN:
                    resultValue = (void *)malloc(sizeof(int));
                    if ((int)that == 0) yyerror("Division by 0");
                    else *(int*)resultValue = (int)(*this) / (int)(that);
                    break;
                case TFLOAT:
                    resultValue = (void *)malloc(sizeof(float));
                    if ((float)that == 0) yyerror("Division by 0");
                    else *(float*)resultValue = (float)(*this) / (float)(that);
                    break;
                default:
                    yyerror("TF BRO !!!!");
            }

            free(value);
            value = resultValue;
            type = inferedType;
            return *this;
        }

        MathNode& operator%(MathNode that) {
            if (this->type == TFLOAT || that.type == TFLOAT) 
                yyerror("Integer Modulo is not supported for floating point operations");
            
            else if ((int)(that) == 0) 
                yyerror("Division by 0");

            else {
                int* resultValue = (int*)malloc(sizeof(int));
                *resultValue = (int)(*this) % (int)(that);
    
                free(value);
                value = resultValue;
                type = TINT;
            }
            return *this;
        }

        MathNode& operator<<(MathNode that) {
            if ( ! IsInt(that.type) || ! IsInt(this->type)) {
                yyerror("shift operation is not supported for non integer types");
            } else {
                ValueType inferedType = TINT;
                int* resultValue = (int*)malloc(sizeof(int));
                *resultValue = (int)(*this) << (int)(that);

                free(value);
                value = resultValue;
                type = inferedType;
            }
            return *this;
        }   
        
        MathNode& operator>>(MathNode that) {
            if ( ! IsInt(that.type) || ! IsInt(this->type)) {
                yyerror("shift operation is not supported for non integer types");
            } else {
                ValueType inferedType = TINT;
                int* resultValue = (int*)malloc(sizeof(int));
                *resultValue = (int)(*this) >> (int)(that);

                free(value);
                value = resultValue;
                type = inferedType;
            }
            return *this;
        }  
        
        MathNode& operator| (MathNode that) {
            if ( ! IsInt(that.type) || ! IsInt(this->type)) {
                yyerror("shift operation is not supported for non integer types");
            } else {
                ValueType inferedType = TINT;
                int* resultValue = (int*)malloc(sizeof(int));
                *resultValue = (int)(*this) | (int)(that);

                free(value);
                value = resultValue;
                type = inferedType;
            }
            return *this;
        }

        MathNode& operator& (MathNode that) {
            if ( ! IsInt(that.type) || ! IsInt(this->type)) {
                yyerror("shift operation is not supported for non integer types");
            } else {
                ValueType inferedType = TINT;
                int* resultValue = (int*)malloc(sizeof(int));
                *resultValue = (int)(*this) & (int)(that);

                free(value);
                value = resultValue;
                type = inferedType;
            }
            return *this;
        }

        MathNode& operator^ (MathNode that) {
            if ( ! IsInt(that.type) || ! IsInt(this->type)) {
                yyerror("shift operation is not supported for non integer types");
            } else {
                ValueType inferedType = TINT;
                int* resultValue = (int*)malloc(sizeof(int));
                *resultValue = (int)(*this) ^ (int)(that);

                free(value);
                value = resultValue;
                type = inferedType;
            }
            return *this;
        }
        
        int operator>=(MathNode that) {
            switch (type) {
                case TINT: case TCHAR: case TBOOLEAN:
                    return (int)(*this) >= (int)(that);
                    break;
                case TFLOAT:
                    return (float)(*this) >= (float)(that);
                    break;
                default:
                    yyerror("Comparison operator is not supported for this type");
            }
            return false;
        }

        int operator>(MathNode that) {
            switch (type) {
                case TINT: case TCHAR: case TBOOLEAN:
                    return (int)(*this) > (int)(that);
                    break;
                case TFLOAT:
                    return (float)(*this) > (float)(that);
                    break;
                default:
                    yyerror("Comparison operator is not supported for this type");
            }
            return false;
        }

        int operator<=(MathNode that) {
            switch (type) {
                case TINT: case TCHAR: case TBOOLEAN:
                    return (int)(*this) <= (int)(that);
                    break;
                case TFLOAT:
                    return (float)(*this) <= (float)(that);
                    break;
                default:
                    yyerror("Comparison operator is not supported for this type");
            }
            return false;
        }

        int operator<(MathNode that) {
            switch (type) {
                case TINT: case TCHAR: case TBOOLEAN:
                    return (int)(*this) < (int)(that);
                    break;
                case TFLOAT:
                    return (float)(*this) < (float)(that);
                    break;
                default:
                    yyerror("Comparison operator is not supported for this type");
            }
            return false;
        }

        int operator==(MathNode that) {
            switch (type) {
                case TINT: case TCHAR: case TBOOLEAN:
                    return (int)(*this) == (int)(that);
                    break;
                case TFLOAT:
                    return (float)(*this) == (float)(that);
                    break;
                default:
                    yyerror("Comparison operator is not supported for this type");
            }
            return false;
        }

        int operator!=(MathNode that) {
            switch (type) {
                case TINT: case TCHAR: case TBOOLEAN:
                    return (int)(*this) != (int)(that);
                    break;
                case TFLOAT:
                    return (float)(*this) != (float)(that);
                    break;
                default:
                    yyerror("Comparison operator is not supported for this type");
            }
            return false;
        }

        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////// Math Functions ////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        MathNode& SQRT() {
            float* resultValue = (float *)malloc(sizeof(float));
            *resultValue = sqrt((float)(*this));
            free(value);
            value = resultValue;
            type = TFLOAT;
            return *this;
        }

        MathNode& POW(MathNode that) {
            void* resultValue =  (void*)malloc(sizeof(float));
            *(float*)resultValue = pow( (float)(*this), (float)(that) );

            free(value);
            value = resultValue;
            type = TFLOAT;
            return *this;
        }

        ~MathNode() {
            if (value != nullptr) {
                free(value);
            }
        }
};

class StringNode: public ExpressionNode {
        std::string strVal;
    public:
        StringNode(const char* value) : ExpressionNode(nullptr, TSTRING) {
            strVal = std::string(value);
        }
        
        int size() { return strVal.size(); }

        StringNode& operator+(MathNode that) {
            switch (that.type) {
                case TINT: case TBOOLEAN:
                    this->strVal += std::to_string((int)that);
                    break;
                case TCHAR:
                    this->strVal += std::to_string((char)that);
                    break;
                case TFLOAT:
                    this->strVal += std::to_string((float)that);
                    break;
                default:
                    break;
            }
            return *this;
        }

        StringNode& operator+(StringNode that) {
            this->strVal += that.strVal;
            return *this;
        }

        StringNode& operator-(MathNode that) {
            for (int i = 0; i < (int)that && strVal.size() > 0; i++) {
                this->strVal.pop_back();
            }
            return *this;
        }

        StringNode* partition(char* start, char* end) {
            int l = std::atoi(start);
            int r = std::atoi(end);
            std::string sliced = strVal.substr(l, r - l);
            return new StringNode(sliced.c_str());
        }

        StringNode* append(StringNode* that) {
            StringNode* otherGuy = new StringNode(this->strVal.c_str());
            otherGuy->strVal += " " + that->strVal;
            return otherGuy;
        }

        friend std::ostream& operator<<(std::ostream& os, const StringNode& node) {
            os << node.strVal;
            return os;
        }

        ~StringNode() {};
};