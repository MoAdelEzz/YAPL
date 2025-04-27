/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_INCLUDE_PARSER_TAB_HPP_INCLUDED
# define YY_YY_INCLUDE_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IF = 258,                      /* IF  */
    ELSE = 259,                    /* ELSE  */
    FOR = 260,                     /* FOR  */
    WHILE = 261,                   /* WHILE  */
    DO = 262,                      /* DO  */
    SWITCH = 263,                  /* SWITCH  */
    CASE = 264,                    /* CASE  */
    DEFAULT = 265,                 /* DEFAULT  */
    CONTINUE = 266,                /* CONTINUE  */
    BREAK = 267,                   /* BREAK  */
    RETURN = 268,                  /* RETURN  */
    PRINT = 269,                   /* PRINT  */
    DATA_TYPE = 270,               /* DATA_TYPE  */
    IDENTIFIER = 271,              /* IDENTIFIER  */
    INTEGER = 272,                 /* INTEGER  */
    BOOLEAN = 273,                 /* BOOLEAN  */
    FLOAT = 274,                   /* FLOAT  */
    CONST = 275,                   /* CONST  */
    STRING = 276,                  /* STRING  */
    POW = 277,                     /* POW  */
    SQRT = 278,                    /* SQRT  */
    SHL = 279,                     /* SHL  */
    SHR = 280,                     /* SHR  */
    AND = 281,                     /* AND  */
    OR = 282,                      /* OR  */
    GTE = 283,                     /* GTE  */
    LTE = 284,                     /* LTE  */
    LT = 285,                      /* LT  */
    GT = 286,                      /* GT  */
    ISEQUAL = 287,                 /* ISEQUAL  */
    NOTEQUAL = 288,                /* NOTEQUAL  */
    CHARACTER = 289,               /* CHARACTER  */
    INCREMENT = 290,               /* INCREMENT  */
    DECREMENT = 291,               /* DECREMENT  */
    PLUS_EQUAL = 292,              /* PLUS_EQUAL  */
    MINUS_EQUAL = 293,             /* MINUS_EQUAL  */
    DIV_EQUAL = 294,               /* DIV_EQUAL  */
    MOD_EQUAL = 295,               /* MOD_EQUAL  */
    AND_EQUAL = 296,               /* AND_EQUAL  */
    OR_EQUAL = 297,                /* OR_EQUAL  */
    XOR_EQUAL = 298,               /* XOR_EQUAL  */
    MUL_EQUAL = 299,               /* MUL_EQUAL  */
    SCOPE_BEGIN = 300,             /* SCOPE_BEGIN  */
    SCOPE_END = 301                /* SCOPE_END  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 42 "lex-yacc/parser.ypp"

    ProgramNode*    Node;
    Expression*     Exp;
    FunctionParametersNode* FP;
    FunctionCallParametersNode* FCP;
    SwitchBody* SB;
    DataType* DT;

    struct {
        int line;
        char* str;
    } data;

#line 124 "include/parser.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_INCLUDE_PARSER_TAB_HPP_INCLUDED  */
