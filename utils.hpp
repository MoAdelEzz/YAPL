#include <cstdlib>
#include <math.h>
#include <iostream>
#include <string>
#include <sys/stat.h>

#define BOOLEAN_TYPE 0
#define INT_TYPE 1
#define CHAR_TYPE 2
#define FLOAT_TYPE 3
#define STRING_TYPE 4
#define UNDEFINED_TYPE 5
extern void yyerror(const char* s);
enum ValueType {
    TBOOLEAN, TINT, TCHAR, TFLOAT, TSTRING, TUNDEFINED
};

#define IsInt(type) (type == TINT || type == TBOOLEAN || type == TCHAR)


class ExpressionNode {
    private:
        void* value;
        enum ValueType type;
    public:
        ExpressionNode(enum ValueType type) : type(type), value(nullptr) { 
            value = malloc(valueSize(type));
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

        static ExpressionNode* createIntNode(int num) {
            ExpressionNode* node = new ExpressionNode(TINT);
            node->value = (void*)malloc(sizeof(int));
            *(int*)node->value = num;
            return node;
        }

        static ExpressionNode* createCharNode(char c) {
            ExpressionNode* node = new ExpressionNode(TCHAR);
            *(int*)node->value = c;
            return node;
        }

        static ExpressionNode* createFloatNode(float num) {
            ExpressionNode* node = new ExpressionNode(TFLOAT);
            *(float*)node->value = num;
            return node;
        }

        static ExpressionNode* createBooleanNode(int num) {
            ExpressionNode* node = new ExpressionNode(TBOOLEAN);
            *(int*)node->value = num;
            return node;
        }

        static int valueSize(ValueType type) {
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

        ExpressionNode& operator+(ExpressionNode that) {
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

        ExpressionNode& operator-(ExpressionNode that) {
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

        ExpressionNode& operator*(ExpressionNode that) {
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

        ExpressionNode& operator/(ExpressionNode that) {
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

        ExpressionNode& operator%(ExpressionNode that) {
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

        ExpressionNode& operator<<(ExpressionNode that) {
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
        
        ExpressionNode& operator>>(ExpressionNode that) {
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
        
        ExpressionNode& operator| (ExpressionNode that) {
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

        ExpressionNode& operator& (ExpressionNode that) {
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

        ExpressionNode& operator^ (ExpressionNode that) {
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

        ExpressionNode& SQRT() {
            float* resultValue = (float *)malloc(sizeof(float));
            *resultValue = sqrt((float)(*this));
            free(value);
            value = resultValue;
            type = TFLOAT;
            return *this;
        }

        ExpressionNode& POW(ExpressionNode that) {
            void* resultValue =  (void*)malloc(sizeof(float));
            *(float*)resultValue = pow( (float)(*this), (float)(that) );

            free(value);
            value = resultValue;
            type = TFLOAT;
            return *this;
        }

        ~ExpressionNode() {
            if (value != nullptr) {
                free(value);
            }
        }
};