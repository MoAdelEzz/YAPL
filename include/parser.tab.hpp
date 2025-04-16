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
    RETURN = 258,                  /* RETURN  */
    IDENTIFIER = 259,              /* IDENTIFIER  */
    STRING = 260,                  /* STRING  */
    POW = 261,                     /* POW  */
    SQRT = 262,                    /* SQRT  */
    SHL = 263,                     /* SHL  */
    SHR = 264,                     /* SHR  */
    DATA_TYPE = 265,               /* DATA_TYPE  */
    IF = 266,                      /* IF  */
    ELSE = 267,                    /* ELSE  */
    WHILE = 268,                   /* WHILE  */
    FOR = 269,                     /* FOR  */
    AND = 270,                     /* AND  */
    OR = 271,                      /* OR  */
    GTE = 272,                     /* GTE  */
    LTE = 273,                     /* LTE  */
    LT = 274,                      /* LT  */
    GT = 275,                      /* GT  */
    ISEQUAL = 276,                 /* ISEQUAL  */
    NOTEQUAL = 277,                /* NOTEQUAL  */
    DO = 278,                      /* DO  */
    SWITCH = 279,                  /* SWITCH  */
    CASE = 280,                    /* CASE  */
    DEFAULT = 281,                 /* DEFAULT  */
    CONTINUE = 282,                /* CONTINUE  */
    BREAK = 283,                   /* BREAK  */
    CHARACTER = 284,               /* CHARACTER  */
    INCREMENT = 285,               /* INCREMENT  */
    DECREMENT = 286,               /* DECREMENT  */
    PLUS_EQUAL = 287,              /* PLUS_EQUAL  */
    MINUS_EQUAL = 288,             /* MINUS_EQUAL  */
    DIV_EQUAL = 289,               /* DIV_EQUAL  */
    MOD_EQUAL = 290,               /* MOD_EQUAL  */
    AND_EQUAL = 291,               /* AND_EQUAL  */
    OR_EQUAL = 292,                /* OR_EQUAL  */
    INTEGER = 293,                 /* INTEGER  */
    BOOLEAN = 294,                 /* BOOLEAN  */
    XOR_EQUAL = 295,               /* XOR_EQUAL  */
    MUL_EQUAL = 296,               /* MUL_EQUAL  */
    FLOAT = 297,                   /* FLOAT  */
    CONST = 298,                   /* CONST  */
    PRINT = 299                    /* PRINT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 24 "lex-yacc/parser.ypp"

    ProgramNode*    Node;
    Expression*     Exp;
    FunctionParametersNode* FP;
    FunctionCallParametersNode* FCP;
    SwitchBody* SB;
    DataType* DT;
    char* str;

#line 118 "include/parser.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_INCLUDE_PARSER_TAB_HPP_INCLUDED  */
