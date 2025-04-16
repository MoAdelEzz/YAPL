%{
    #include <string>
    #include <iostream>

    #include "branching.hpp"
    #include "common.hpp"
    #include "expression.hpp"
    #include "loop.hpp"
    #include "program.hpp"
    #include "scoping.hpp"
    #include "var-op.hpp"

    #include "parser.tab.hpp"
%}

%option noyywrap


%%
return              { return RETURN; }
switch              { return SWITCH; }
case                { return CASE; }
default             { return DEFAULT;}
continue            { return CONTINUE; }
break               { return BREAK;}
true|false          {
                        yylval.str = strdup(yytext);
                        return BOOLEAN;
                    }

\<\<                { return SHL;   }
\>\>                { return SHR;   }
pow                 { return POW;   }
sqrt                { return SQRT;  }
if                  { return IF;    }
else                { return ELSE;  }
while               { return WHILE; }
do                  { return DO;    }
for                 { return FOR;   }
print               { return PRINT; }
&&                  { return AND;   }
\|\|                { return OR;   }
\>\=                { return GTE;   }
\<\=                { return LTE;   }
\<                  { return LT;    }
\>                  { return GT;    }
\=\=                { return ISEQUAL;}
\!\=                { return NOTEQUAL;}
\+\+                { return INCREMENT; }
\-\-                { return DECREMENT; }

int|float|bool|char|string|void { yylval.str = strdup(yytext); return DATA_TYPE; }

[a-zA-Z_][a-zA-Z0-9_]* {
    // std::cout << "Variable" << " " << yytext <<  std::endl;
    yylval.str = strdup(yytext);
    return IDENTIFIER;
}


0+|-?[0-9]+[0-9]* {
    // std::cout << "Integer " << yytext << std::endl;
    yylval.str = strdup(yytext);
    return INTEGER;
}

0+\.0*|[-+]?[0-9]*\.[0-9]* {
    // std::cout << "FLOAT " << yytext << std::endl;
    yylval.str = strdup(yytext);
    return FLOAT;
}

'.' {
    // std::cout << "Character " << yytext << std::endl;
    yylval.str = strdup(yytext);
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


\/\/.*\n? ;

[ \t\n] ;


%%