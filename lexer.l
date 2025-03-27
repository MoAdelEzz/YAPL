%{
    #include <string>
    #include <iostream>
    #include "utils.hpp"
    #include "parser.tab.hpp"
%}

%option noyywrap


%%
true|false {
    yylval.INum = yytext == "true" ? 1 : 0;
    return BOOLEAN;
}

pow { return POW; }
sqrt { return SQRT; }
\<\< { return SHL; }
\>\> { return SHR; }

[a-zA-Z_][a-zA-Z0-9_]* {
    // std::cout << "Variable" << " " << yytext <<  std::endl;
    yylval.str = strdup(yytext);
    return IDENTIFIER;
}


0+|-?[0-9]+[0-9]* {
    // std::cout << "Integer " << yytext << std::endl;
    yylval.INum = atoi(yytext);
    return INTEGER;
}

0+\.0*|[-+]?[0-9]*\.[0-9]* {
    // std::cout << "FLOAT " << yytext << std::endl;
    yylval.FNum = atof(yytext);
    return FLOAT;
}

[=();+\-*/%,&|^] {
    // std::cout << "symbol " << yytext << std::endl;
    return yytext[0];
}

'.' {
    // std::cout << "Character " << yytext << std::endl;
    yylval.character = yytext[1];
    return CHARACTER;
}

\/\/.*\n ;

[ \t\n] ;


%%