%{
    #include "utils.h"
    #include "y.tab.h"
    void yyerror(char *);
%}

%%
[a-zA-Z_][a-zA-Z0-9_]* {
    yylval.str = strdup(yytext);
    return IDENTIFIER;
}


0+|[-]?[0-9]+[0-9]* {
    yylval.INum = atoi(yytext);
    return INTEGER;
}

0+.0*|[-+]?[0-9]*\.[0-9]* {
    yylval.FNum = atof(yytext);
    return FLOAT;
}

[=();+\-*/%] {
    return yytext[0];
}

'.' {
    yylval.character = yytext[1];
    return CHARACTER;
}

[ \t\n] ;


%%

int yywrap() {
    return 1;
}