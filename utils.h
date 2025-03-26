#define BOOLEAN_TYPE 0
#define INT_TYPE 1
#define CHAR_TYPE 2
#define FLOAT_TYPE 3
#define STRING_TYPE 4
#define UNDEFINED_TYPE 5

typedef struct {
    int type;
    void* value;
} EvaluationNode;

void printNode(EvaluationNode node);

EvaluationNode evaluate(EvaluationNode node1, EvaluationNode node2, char operator);


