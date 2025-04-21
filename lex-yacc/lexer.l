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
return              { yylval.line = ProgramNode::lineNumber; return RETURN; }
switch              { yylval.line = ProgramNode::lineNumber; return SWITCH; }
case                { yylval.line = ProgramNode::lineNumber; return CASE; }
default             { yylval.line = ProgramNode::lineNumber; return DEFAULT;}
continue            { yylval.line = ProgramNode::lineNumber; return CONTINUE; }
break               { yylval.line = ProgramNode::lineNumber; return BREAK;}
const               { yylval.line = ProgramNode::lineNumber; return CONST; }
true|false          {
                        yylval.str = strdup(yytext);
                        return BOOLEAN;
                    }

\<\<                { return SHL;   }
\>\>                { return SHR;   }
pow                 { return POW;   }
sqrt                { return SQRT;  }
if                  { yylval.line = ProgramNode::lineNumber; return IF;    }
else                { yylval.line = ProgramNode::lineNumber; return ELSE;  }
while               { yylval.line = ProgramNode::lineNumber; return WHILE; }
do                  { yylval.line = ProgramNode::lineNumber; return DO;    }
for                 { yylval.line = ProgramNode::lineNumber; return FOR;   }
print               { yylval.line = ProgramNode::lineNumber; return PRINT; }
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
\+\=                { return PLUS_EQUAL; }
\-\=                { return MINUS_EQUAL; }
\*\=                { return MUL_EQUAL; }
\/\=                { return DIV_EQUAL; }
\%\=                { return MOD_EQUAL; }
\&\=                { return AND_EQUAL; }
\|\=                { return OR_EQUAL; }
\^\=                { return XOR_EQUAL; }

int|float|bool|char|string|void { yylval.line = ProgramNode::lineNumber; yylval.str = strdup(yytext); return DATA_TYPE; }

[a-zA-Z_][a-zA-Z0-9_]* {
    // std::cout << "Variable" << " " << yytext <<  std::endl;
    yylval.line = ProgramNode::lineNumber;
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

[~!=();+\-*/%,&|^\[\]:\}\{] {
    // std::cout << "symbol " << yytext << std::endl;
    return yytext[0];
}

\n { ProgramNode::newLine(); }

\/\/.*\n? ;

[ \t\n] ;


%%