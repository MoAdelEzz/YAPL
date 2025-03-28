// #include "utils.h"
// #include <stdlib.h>
// #include <stdio.h>
// void yyerror(char *);    


// void* castNodeTo(ExpressionNode node, enum ValueType type) {
//     void* value;
//     switch (type) {
//         case TINT: case TCHAR:
//             value = (void *)malloc(sizeof(int));
//             *(int*)value = *(int*)node.value;
//             break;

//         case TFLOAT:
//             value = (void *)malloc(sizeof(float));
//             if (node.type == TINT) {
//                 *(float*)value = (float) *(int*)node.value;
//             }
//             else if (node.type == TCHAR) {
//                 *(float*)value = (float) *(int*)node.value;
//             } else {
//                 *(float*)value = *(float*)node.value;
//             }
//             break;
        
//         case TBOOLEAN:
//             value = (void *)malloc(sizeof(int));
//             *(int*)value = *(int*)node.value;
//             break;
//     }
//     return value;
// }

// int handleIntegerOperations(int x, int y, char operator) {
//     switch (operator) {
//         case '+':
//             return x + y;
//         case '-':
//             return x - y;
//         case '*':
//             return x * y;
//         case '/':
//             return x / y;
//         case '%':
//             return x % y;
//         default:
//             return TUNDEFINED;
//     }
// }

// float handleFloatOperations(float x, float y, char operator) {
//     switch (operator) {
//         case '+':
//             return x + y;
//         case '-':
//             return x - y;
//         case '*':
//             return x * y;
//         case '/':
//             return x / y;
//         default:
//             return TUNDEFINED;
//     }
// }

// int handleCharOperations(int a, int b, char operator) {
//     switch (operator) {
//         case '+':
//             return a + b;
//         case '-':
//             return a - b;
//         case '*': 
//             return a * b;
//         case '/':  
//             return a / b;
//         default:
//             return TUNDEFINED;
//     }
//     printf("\n\n\n");
// }

// ExpressionNode evaluate (ExpressionNode node1, ExpressionNode node2, enum Operation operation) {
//     enum ValueType resultType = inferResultType(node1.type, node2.type);
//     ExpressionNode result = { resultType, NULL };

//     switch (resultType) {
//         case TINT:
//             result.value = (void *)malloc(sizeof(int));
//             *(int*)result.value = nodeValueAsInt(node1) + nodeValueAsInt(node2);
//             break;
//         case TFLOAT:
//             result.value = (void *)malloc(sizeof(float));
//             *(float*)result.value = nodeValueAsFloat(node1) + nodeValueAsFloat(node2);
//             break;
//         case TCHAR:
//             result.value = (void *)malloc(sizeof(int));
//             *(int*)result.value = nodeValueAsInt(node1) + nodeValueAsInt(node2);
//             break;
//         case TBOOLEAN:
//             result.value = (void *)malloc(sizeof(int));
//             *(int*)result.value = (*(int*)node1.value + *(int*)node2.value + 2) % 2;
//             break;
//         default:
//             return (ExpressionNode){ TUNDEFINED, NULL };
//     }
//     yyerror("Plus Operation Cannot Be Done");
// }

// ExpressionNode plus (ExpressionNode node1, ExpressionNode node2) {
//     enum ValueType resultType = inferResultType(node1.type, node2.type);
//     ExpressionNode result = { resultType, NULL };

//     switch (resultType) {
//         case TINT:
//             result.value = (void *)malloc(sizeof(int));
//             *(int*)result.value = nodeValueAsInt(node1) + nodeValueAsInt(node2);
//             break;
//         case TFLOAT:
//             result.value = (void *)malloc(sizeof(float));
//             *(float*)result.value = nodeValueAsFloat(node1) + nodeValueAsFloat(node2);
//             break;
//         case TCHAR:
//             result.value = (void *)malloc(sizeof(int));
//             *(int*)result.value = nodeValueAsInt(node1) + nodeValueAsInt(node2);
//             break;
//         case TBOOLEAN:
//             result.value = (void *)malloc(sizeof(int));
//             *(int*)result.value = (*(int*)node1.value + *(int*)node2.value + 2) % 2;
//             break;
//         default:
//             return (ExpressionNode){ TUNDEFINED, NULL };
//     }
//     yyerror("Plus Operation Cannot Be Done");
// }

// ExpressionNode minus (ExpressionNode node1, ExpressionNode node2) {
//     enum ValueType resultType = inferResultType(node1.type, node2.type);
//     ExpressionNode result = { resultType, NULL };

//     switch (resultType) {
//         case TINT:
//             result.value = (void *)malloc(sizeof(int));
//             *(int*)result.value = nodeValueAsInt(node1) + nodeValueAsInt(node2);
//             break;
//         case TFLOAT:
//             result.value = (void *)malloc(sizeof(float));
//             *(float*)result.value = nodeValueAsFloat(node1) + nodeValueAsFloat(node2);
//             break;
//         case TCHAR:
//             result.value = (void *)malloc(sizeof(int));
//             *(int*)result.value = nodeValueAsInt(node1) + nodeValueAsInt(node2);
//             break;
//         case TBOOLEAN:
//             result.value = (void *)malloc(sizeof(int));
//             *(int*)result.value = (*(int*)node1.value + *(int*)node2.value + 2) % 2;
//             break;
//         default:
//             return (ExpressionNode){ TUNDEFINED, NULL };
//     }
//     yyerror("Plus Operation Cannot Be Done");
// }

// enum ValueType inferResultType(enum ValueType type1, enum ValueType type2){
//     if (type1 > type2) {
//         int temp = type1;
//         type1 = type2;
//         type2 = temp;
//     }

//     if (type1 == TBOOLEAN && type2 <= TFLOAT) {
//         return TBOOLEAN;
//     }

//     if (type1 == TINT && type2 <= TFLOAT) {
//         return type1 > type2 ? type1 : type2;
//     }

//     if (type1 == TCHAR) {
//         return type2 == TFLOAT ? TFLOAT : TCHAR;
//     }

//     if (type1 == TFLOAT && type2 <= TFLOAT) {
//         return TFLOAT;
//     }

//     return TUNDEFINED;
// }

// char* typeToString(enum ValueType type) {
//     switch (type) {
//         case TINT:
//             return "int";
//         case TFLOAT:
//             return "float";
//         case TCHAR:
//             return "char";
//         case TBOOLEAN:
//             return "boolean";
//         case TSTRING:
//             return "string";
//         default:
//             return "undefined";
//     }
// }

// int nodeValueAsInt(ExpressionNode node) {
//     switch (node.type) {
//         case TINT:
//             return *(int*)node.value;
//         case TFLOAT:
//             return *(float*)node.value;
//         case TCHAR:
//             return *(char*)node.value;
//         case TBOOLEAN:
//             return *(int*)node.value;
//         default:
//             yyerror("cast failed");
//             exit(0);
//     }

//     return *(int*)node.value;
// }

// float nodeValueAsFloat(ExpressionNode node) {
//     switch (node.type) {
//         case TINT:
//             return *(int*)node.value;
//         case TFLOAT:
//             return *(float*)node.value;
//         case TCHAR:
//             return *(int*)node.value;
//         case TBOOLEAN:
//             return *(int*)node.value;
//         default:
//             yyerror("cast failed");
//             exit(0);
//     }
// }

// int nodeValueAsChar(ExpressionNode node) {
//     switch (node.type) {
//         case TINT:
//             return *(int*)node.value;
//         case TCHAR:
//             return *(char*)node.value;
//         case TBOOLEAN:
//             return *(int*)node.value;
//         default:
//             yyerror("cast failed");
//             exit(0);
//     }
// }

// void printNode(ExpressionNode node) {
//     switch (node.type) {
//         case TINT:
//             printf("Node = %d, Type = %s \n", *(int*)node.value, typeToString(node.type));
//             break;
//         case TFLOAT:
//             printf("Node = %f, Type = %s \n", *(float*)node.value, typeToString(node.type));
//             break;
//         case TCHAR:
//             printf("Node = %d, Type = %s \n", *(int*)node.value, typeToString(node.type));
//             break;
//         case TBOOLEAN:
//             printf("Node = %d, Type = %s \n", *(int*)node.value, typeToString(node.type));
//             break;
//         case TUNDEFINED:
//             break;
//         default:
//             break;
//     }
// }