%{
    #include <string>
    #include <iostream>

    #include "program.hpp"
    #include "identifier.hpp"
    #include "node.hpp"
    #include "if.hpp"

    #include "parser.tab.hpp"
%}

%option noyywrap


%%
true|false {
    yylval.INum = yytext == "true" ? 1 : 0;
    return BOOLEAN;
}

\<\<        { return SHL;   }
\>\>        { return SHR;   }
pow         { return POW;   }
sqrt        { return SQRT;  }
if          { return IF;    }
else        { return ELSE;  }
while       { return WHILE; }
do          { return DO;    }
for         { return FOR;   }
&&          { return AND;   }
\|\|        { return OR;    }
\>\=        { return GTE;   }
\<\=        { return LTE;   }
\<          { return LT;    }
\>          { return GT;    }
\=\=        { return ISEQUAL;}
\!\=        { return NOTEQUAL;}
func        { return FUNCTIONDEF;}

int|float|bool|char|string { yylval.str = strdup(yytext); return DATA_TYPE; }

[a-zA-Z_][a-zA-Z0-9_]* {
    // std::cout << "Variable" << " " << yytext <<  std::endl;
    yylval.str = strdup(yytext);
    return IDENTIFIER;
}


0+|-?[0-9]+[0-9]* {
    // std::cout << "Integer " << yytext << std::endl;
    yylval.INum = atoi(yytext);
    yylval.str = yytext;
    return INTEGER;
}

0+\.0*|[-+]?[0-9]*\.[0-9]* {
    // std::cout << "FLOAT " << yytext << std::endl;
    yylval.FNum = atof(yytext);
    yylval.str = yytext;
    return FLOAT;
}

'.' {
    // std::cout << "Character " << yytext << std::endl;
    yylval.character = yytext[1];
    return CHARACTER;
}

\"[^"]*\" {
    yylval.str = strdup(yytext + 1);
    yylval.str[strlen(yylval.str) - 1] = '\0';
    return STRING;
}

[=();+\-*/%,&|^\[\]:\}\{] {
    // std::cout << "symbol " << yytext << std::endl;
    return yytext[0];
}


\/\/.*\n ;

[ \t\n] ;


%%