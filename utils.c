#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

char* typeToString(int type) {
    switch (type) {
        case INT_TYPE:
            return "int";
        case FLOAT_TYPE:
            return "float";
        case CHAR_TYPE:
            return "char";
        case BOOLEAN_TYPE:
            return "boolean";
        case STRING_TYPE:
            return "string";
        default:
            return "undefined";
    }
}

int resolveResultType(int type1, int type2) {
    if (type1 > type2) {
        int temp = type1;
        type1 = type2;
        type2 = temp;
    }

    if (type1 == BOOLEAN_TYPE && type2 <= FLOAT_TYPE) {
        return BOOLEAN_TYPE;
    }

    if (type1 == INT_TYPE && type2 <= FLOAT_TYPE) {
        return type1 > type2 ? type1 : type2;
    }

    if (type1 == CHAR_TYPE) {
        return type2 == FLOAT_TYPE ? FLOAT_TYPE : CHAR_TYPE;
    }

    if (type1 == FLOAT_TYPE && type2 <= FLOAT_TYPE) {
        return FLOAT_TYPE;
    }

    return UNDEFINED_TYPE;
}

void* castNodeTo(EvaluationNode node, int type) {
    void* value;
    switch (type) {
        case INT_TYPE: case CHAR_TYPE:
            value = (void *)malloc(sizeof(int));
            *(int*)value = *(int*)node.value;
            break;

        case FLOAT_TYPE:
            value = (void *)malloc(sizeof(float));
            if (node.type == INT_TYPE) {
                *(float*)value = (float) *(int*)node.value;
            }
            else if (node.type == CHAR_TYPE) {
                *(float*)value = (float) *(int*)node.value;
            } else {
                *(float*)value = *(float*)node.value;
            }
            break;
        
        case BOOLEAN_TYPE:
            value = (void *)malloc(sizeof(int));
            *(int*)value = *(int*)node.value;
            break;
    }
    return value;
}

int handleIntegerOperations(int x, int y, char operator) {
    switch (operator) {
        case '+':
            return x + y;
        case '-':
            return x - y;
        case '*':
            return x * y;
        case '/':
            return x / y;
        case '%':
            return x % y;
        default:
            return UNDEFINED_TYPE;
    }
}

float handleFloatOperations(float x, float y, char operator) {
    switch (operator) {
        case '+':
            return x + y;
        case '-':
            return x - y;
        case '*':
            return x * y;
        case '/':
            return x / y;
        default:
            return UNDEFINED_TYPE;
    }
}

int handleCharOperations(int a, int b, char operator) {
    switch (operator) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*': 
            return a * b;
        case '/':  
            return a / b;
        default:
            return UNDEFINED_TYPE;
    }
    printf("\n\n\n");
}

EvaluationNode evaluate(EvaluationNode node1, EvaluationNode node2, char operator) {
    const int resultType = resolveResultType(node1.type, node2.type);

    void* result;
    void* x = castNodeTo(node1, resultType);
    void* y = castNodeTo(node2, resultType);

    switch(resultType) {
        case INT_TYPE: case CHAR_TYPE:
            result = (void *)malloc(sizeof(int));
            *(int*)result = handleIntegerOperations(*(int*)x, *(int*)y, operator);
            break;
        case FLOAT_TYPE:
            result = (void *)malloc(sizeof(float));                
            *(float*)result = handleFloatOperations(*(float*)x, *(float*)y, operator);
            break;
        default:
            free(x);
            free(y);
            return (EvaluationNode){ UNDEFINED_TYPE, result };
    }


    return (EvaluationNode){ resultType, result };
}

void printNode(EvaluationNode node) {
    switch (node.type) {
        case INT_TYPE:
            printf("Node = %d, Type = %s \n", *(int*)node.value, typeToString(node.type));
            break;
        case FLOAT_TYPE:
            printf("Node = %f, Type = %s \n", *(float*)node.value, typeToString(node.type));
            break;
        case CHAR_TYPE:
            printf("Node = %d, Type = %s \n", *(int*)node.value, typeToString(node.type));
            break;
        case BOOLEAN_TYPE:
            printf("Node = %d, Type = %s \n", *(int*)node.value, typeToString(node.type));
            break;
        case UNDEFINED_TYPE:
            break;
        default:
            break;
    }
}