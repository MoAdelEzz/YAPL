%{ 
    #include "utils.h"
    #include <stdlib.h>
    #include <stdio.h>

    void yyerror(char *);    
    int yylex(void);
    extern FILE *yyin;   
%}

%union  {
    int INum;
    float FNum;
    char character;
    char* str;
    EvaluationNode operationValue;
}


%token <str> IDENTIFIER
%token <character> CHARACTER
%token <INum> INTEGER
%token <FNum> FLOAT

%right '+' '-'
%left '*' '/' '%'
%left ')'

%type <operationValue> Operation MathOperand 

%start Program
%%

Program: 
        Program Sentence { }
        | ;

Sentence:
        Assignment ';'

Assignment: IDENTIFIER '=' Operation { printNode($3); }

Operation:
        Operation '+' Operation     { $$ = evaluate($1, $3, '+'); }
    |   Operation '-' Operation     { $$ = evaluate($1, $3, '-'); }
    |   Operation '*' Operation     { $$ = evaluate($1, $3, '*'); }
    |   Operation '/' Operation     { $$ = evaluate($1, $3, '/'); }
    |   Operation '%' Operation     { $$ = evaluate($1, $3, '%'); }
    |   '(' Operation ')' Operation { $$ = evaluate($2, $4, '*'); }
    |   '(' Operation ')'           { $$ = $2; }   
    |   MathOperand                 { $$ = $1; }

MathOperand:
        INTEGER {
            int* x = malloc(sizeof(int));
            *x = $1;
            $$ = (EvaluationNode){ INT_TYPE, (void*)x };
        }

        | FLOAT {
            float* x = malloc(sizeof(float));
            *x = $1;
            $$ = (EvaluationNode){ FLOAT_TYPE, (void*)x };
        }

        | CHARACTER {
            int* c = malloc(sizeof(char));
            *c = (int)$1;
            $$ = (EvaluationNode){ CHAR_TYPE, (void*)c };
        }
    
%%

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}

int main(int argc, char *argv[]) {
    yyin = fopen("test.yapl", "r");
    yyparse();
    return 0;
}