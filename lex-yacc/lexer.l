%{
    #include <string>
    #include <string.h>
    #include <cstring>
    #include <cstdlib>
    #include <iostream>

    #include "branching.hpp"
    #include "common.hpp"
    #include "expression.hpp"
    #include "loop.hpp"
    #include "program.hpp"
    #include "scoping.hpp"
    #include "var-op.hpp"

    #include "parser.tab.hpp"

    extern int lineNumber;
%}

%option noyywrap


%%
return              { yylval.data.line = lineNumber; return RETURN; }
switch              { yylval.data.line = lineNumber; return SWITCH; }
case                { yylval.data.line = lineNumber; return CASE; }
default             { yylval.data.line = lineNumber; return DEFAULT;}
continue            { yylval.data.line = lineNumber; return CONTINUE; }
break               { yylval.data.line = lineNumber; return BREAK;}
const               { yylval.data.line = lineNumber; return CONST; }
true|false          {
                        yylval.data.str = strdup(yytext);
                        return BOOLEAN;
                    }

\<\<                { yylval.data.line = lineNumber; return SHL;   }
\>\>                { yylval.data.line = lineNumber; return SHR;   }
pow                 { yylval.data.line = lineNumber; return POW;   }
sqrt                { yylval.data.line = lineNumber; return SQRT;  }
if                  { yylval.data.line = lineNumber; return IF;    }
else                { yylval.data.line = lineNumber; return ELSE;  }
while               { yylval.data.line = lineNumber; return WHILE; }
do                  { yylval.data.line = lineNumber; return DO;    }
for                 { yylval.data.line = lineNumber; return FOR;   }
print               { yylval.data.line = lineNumber; return PRINT; }
&&                  { yylval.data.line = lineNumber; return AND;   }
\|\|                { yylval.data.line = lineNumber; return OR;   }
\>\=                { yylval.data.line = lineNumber; return GTE;   }
\<\=                { yylval.data.line = lineNumber; return LTE;   }
\<                  { yylval.data.line = lineNumber; return LT;    }
\>                  { yylval.data.line = lineNumber; return GT;    }
\=\=                { yylval.data.line = lineNumber; return ISEQUAL;}
\!\=                { yylval.data.line = lineNumber; return NOTEQUAL;}
\+\+                { yylval.data.line = lineNumber; return INCREMENT; }
\-\-                { yylval.data.line = lineNumber; return DECREMENT; }
\+\=                { yylval.data.line = lineNumber; return PLUS_EQUAL; }
\-\=                { yylval.data.line = lineNumber; return MINUS_EQUAL; }
\*\=                { yylval.data.line = lineNumber; return MUL_EQUAL; }
\/\=                { yylval.data.line = lineNumber; return DIV_EQUAL; }
\%\=                { yylval.data.line = lineNumber; return MOD_EQUAL; }
\&\=                { yylval.data.line = lineNumber; return AND_EQUAL; }
\|\=                { yylval.data.line = lineNumber; return OR_EQUAL; }
\^\=                { yylval.data.line = lineNumber; return XOR_EQUAL; }

\{ {
    yylval.data.line = lineNumber;
    return SCOPE_BEGIN;
}

\} {
    yylval.data.line = lineNumber;
    return SCOPE_END;
}


int|float|bool|char|string|void { yylval.data.line = lineNumber; yylval.data.str = strdup(yytext); return DATA_TYPE; }

[a-zA-Z_][a-zA-Z0-9_]* {
    // std::cout << "Variable" << " " << yytext <<  std::endl;
    yylval.data.line = lineNumber;
    yylval.data.str = strdup(yytext);
    return IDENTIFIER;
}


0+|-?[0-9]+[0-9]* {
    // std::cout << "Integer " << yytext << std::endl;
    yylval.data.line = lineNumber;
    yylval.data.str = strdup(yytext);
    return INTEGER;
}

0+\.0*|[-+]?[0-9]*\.[0-9]* {
    // std::cout << "FLOAT " << yytext << std::endl;
    yylval.data.line = lineNumber;
    yylval.data.str = strdup(yytext);
    return FLOAT;
}

'.' {
    // std::cout << "Character " << yytext << std::endl;
    yylval.data.line = lineNumber;
    yylval.data.str = strdup(yytext);
    return CHARACTER;
}

\"[^"]*\" {
    yylval.data.line = lineNumber;
    yylval.data.str = strdup(yytext + 1);
    yylval.data.str[strlen(yylval.data.str) - 1] = '\0';
    return STRING;
}

[~!=();+\-*/%,&|^\[\]:] {
    return yytext[0];
}

\n { lineNumber++; }

\/\/.*\n? { lineNumber++; }

[ \t\n] ;


%%