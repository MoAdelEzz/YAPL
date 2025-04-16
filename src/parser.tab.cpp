/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "lex-yacc/parser.ypp"
 
    #include <iostream>
    #include <string>

    #include "branching.hpp"
    #include "common.hpp"
    #include "expression.hpp"
    #include "loop.hpp"
    #include "program.hpp"
    #include "scoping.hpp"
    #include "var-op.hpp"
    #include "functions.hpp"
    #include "controllers.hpp"
    #include "returnNode.hpp"

    #include "parser.tab.hpp"
    extern int yylex();
    extern FILE *yyin;   
    void yyerror(const char* s) {
        std::cerr << "Error: " << s << std::endl;
    }

#line 94 "src/parser.tab.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_RETURN = 3,                     /* RETURN  */
  YYSYMBOL_IDENTIFIER = 4,                 /* IDENTIFIER  */
  YYSYMBOL_STRING = 5,                     /* STRING  */
  YYSYMBOL_POW = 6,                        /* POW  */
  YYSYMBOL_SQRT = 7,                       /* SQRT  */
  YYSYMBOL_SHL = 8,                        /* SHL  */
  YYSYMBOL_SHR = 9,                        /* SHR  */
  YYSYMBOL_DATA_TYPE = 10,                 /* DATA_TYPE  */
  YYSYMBOL_IF = 11,                        /* IF  */
  YYSYMBOL_ELSE = 12,                      /* ELSE  */
  YYSYMBOL_WHILE = 13,                     /* WHILE  */
  YYSYMBOL_FOR = 14,                       /* FOR  */
  YYSYMBOL_AND = 15,                       /* AND  */
  YYSYMBOL_OR = 16,                        /* OR  */
  YYSYMBOL_GTE = 17,                       /* GTE  */
  YYSYMBOL_LTE = 18,                       /* LTE  */
  YYSYMBOL_LT = 19,                        /* LT  */
  YYSYMBOL_GT = 20,                        /* GT  */
  YYSYMBOL_ISEQUAL = 21,                   /* ISEQUAL  */
  YYSYMBOL_NOTEQUAL = 22,                  /* NOTEQUAL  */
  YYSYMBOL_DO = 23,                        /* DO  */
  YYSYMBOL_SWITCH = 24,                    /* SWITCH  */
  YYSYMBOL_CASE = 25,                      /* CASE  */
  YYSYMBOL_DEFAULT = 26,                   /* DEFAULT  */
  YYSYMBOL_CONTINUE = 27,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 28,                     /* BREAK  */
  YYSYMBOL_CHARACTER = 29,                 /* CHARACTER  */
  YYSYMBOL_INCREMENT = 30,                 /* INCREMENT  */
  YYSYMBOL_DECREMENT = 31,                 /* DECREMENT  */
  YYSYMBOL_INTEGER = 32,                   /* INTEGER  */
  YYSYMBOL_BOOLEAN = 33,                   /* BOOLEAN  */
  YYSYMBOL_FLOAT = 34,                     /* FLOAT  */
  YYSYMBOL_PRINT = 35,                     /* PRINT  */
  YYSYMBOL_36_ = 36,                       /* ';'  */
  YYSYMBOL_37_ = 37,                       /* '|'  */
  YYSYMBOL_38_ = 38,                       /* '^'  */
  YYSYMBOL_39_ = 39,                       /* '&'  */
  YYSYMBOL_40_ = 40,                       /* '+'  */
  YYSYMBOL_41_ = 41,                       /* '-'  */
  YYSYMBOL_42_ = 42,                       /* '*'  */
  YYSYMBOL_43_ = 43,                       /* '/'  */
  YYSYMBOL_44_ = 44,                       /* '%'  */
  YYSYMBOL_45_ = 45,                       /* '['  */
  YYSYMBOL_46_ = 46,                       /* ']'  */
  YYSYMBOL_47_ = 47,                       /* ')'  */
  YYSYMBOL_48_ = 48,                       /* '('  */
  YYSYMBOL_49_ = 49,                       /* '{'  */
  YYSYMBOL_50_ = 50,                       /* '}'  */
  YYSYMBOL_51_ = 51,                       /* ':'  */
  YYSYMBOL_52_ = 52,                       /* ','  */
  YYSYMBOL_53_ = 53,                       /* '='  */
  YYSYMBOL_YYACCEPT = 54,                  /* $accept  */
  YYSYMBOL_Program = 55,                   /* Program  */
  YYSYMBOL_Sentences = 56,                 /* Sentences  */
  YYSYMBOL_Scope = 57,                     /* Scope  */
  YYSYMBOL_Sentence = 58,                  /* Sentence  */
  YYSYMBOL_SwitchSentence = 59,            /* SwitchSentence  */
  YYSYMBOL_SwitchBody = 60,                /* SwitchBody  */
  YYSYMBOL_Case = 61,                      /* Case  */
  YYSYMBOL_ReturnSentence = 62,            /* ReturnSentence  */
  YYSYMBOL_PrintSentence = 63,             /* PrintSentence  */
  YYSYMBOL_IFSentence = 64,                /* IFSentence  */
  YYSYMBOL_ForSentence = 65,               /* ForSentence  */
  YYSYMBOL_WhileSentence = 66,             /* WhileSentence  */
  YYSYMBOL_DoWhileSentence = 67,           /* DoWhileSentence  */
  YYSYMBOL_FunctionDefinition = 68,        /* FunctionDefinition  */
  YYSYMBOL_FunctionParams = 69,            /* FunctionParams  */
  YYSYMBOL_VariableDeclaration = 70,       /* VariableDeclaration  */
  YYSYMBOL_VariableAssignment = 71,        /* VariableAssignment  */
  YYSYMBOL_Condition = 72,                 /* Condition  */
  YYSYMBOL_Operation = 73,                 /* Operation  */
  YYSYMBOL_FunctionCall = 74,              /* FunctionCall  */
  YYSYMBOL_FunctionCallParams = 75,        /* FunctionCallParams  */
  YYSYMBOL_MathOperation = 76,             /* MathOperation  */
  YYSYMBOL_StringOperation = 77,           /* StringOperation  */
  YYSYMBOL_Operand = 78,                   /* Operand  */
  YYSYMBOL_MathOperand = 79,               /* MathOperand  */
  YYSYMBOL_StringOperand = 80              /* StringOperand  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  63
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   392

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  232

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   290


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    44,    39,     2,
      48,    47,    42,    40,    52,    41,     2,    43,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    51,    36,
       2,    53,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    45,     2,    46,    38,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,    37,    50,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    71,    71,    77,    79,    81,    83,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,   102,
     103,   106,   109,   114,   115,   118,   121,   126,   127,   128,
     130,   134,   138,   143,   147,   153,   154,   157,   158,   161,
     163,   169,   175,   181,   187,   193,   199,   205,   213,   214,
     215,   216,   217,   218,   219,   220,   222,   223,   224,   225,
     226,   227,   229,   230,   233,   234,   235,   238,   239,   242,
     243,   246,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     267,   268,   269,   270,   272,   273,   274,   276,   276,   279,
     281,   283,   285,   287,   289
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "RETURN", "IDENTIFIER",
  "STRING", "POW", "SQRT", "SHL", "SHR", "DATA_TYPE", "IF", "ELSE",
  "WHILE", "FOR", "AND", "OR", "GTE", "LTE", "LT", "GT", "ISEQUAL",
  "NOTEQUAL", "DO", "SWITCH", "CASE", "DEFAULT", "CONTINUE", "BREAK",
  "CHARACTER", "INCREMENT", "DECREMENT", "INTEGER", "BOOLEAN", "FLOAT",
  "PRINT", "';'", "'|'", "'^'", "'&'", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'['", "']'", "')'", "'('", "'{'", "'}'", "':'", "','", "'='", "$accept",
  "Program", "Sentences", "Scope", "Sentence", "SwitchSentence",
  "SwitchBody", "Case", "ReturnSentence", "PrintSentence", "IFSentence",
  "ForSentence", "WhileSentence", "DoWhileSentence", "FunctionDefinition",
  "FunctionParams", "VariableDeclaration", "VariableAssignment",
  "Condition", "Operation", "FunctionCall", "FunctionCallParams",
  "MathOperation", "StringOperation", "Operand", "MathOperand",
  "StringOperand", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-51)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,   176,   339,    12,   -26,    29,    38,    -7,    41,    60,
      92,    81,     4,   134,   -51,     4,     4,   -51,   -51,   -51,
     124,   -51,   -51,   -51,   -51,   -51,   -51,    49,   -51,   101,
     102,   -51,   147,   148,   -51,   -51,   -51,   187,   117,   -51,
     251,    86,   -51,   -51,   104,   111,   112,   113,   114,   116,
     123,   125,   176,    37,   187,   187,   144,   166,   180,   -51,
     -51,   176,   135,   -51,   -51,   -51,    22,   -51,   -51,   141,
     196,   196,   -51,   -51,    -5,   214,    67,   -51,   196,   196,
     196,   196,   196,   196,   196,   196,   196,   196,     6,     6,
     187,   196,   176,   176,   176,   176,   176,   176,   176,   176,
     150,   -51,    31,   176,   304,   251,    86,   318,   183,   187,
     142,   149,   151,   -51,   -51,   124,   -51,   -51,   -23,   196,
      61,   225,   196,   -51,    99,    99,   262,   274,   288,    89,
      89,   -51,   -51,   -51,     6,    76,    76,   199,   -51,   199,
     159,   161,   163,   165,   175,   178,   195,   203,   -51,   208,
      -7,    36,   204,   196,   196,   187,   187,   187,   187,   187,
     187,    -7,    -7,   -30,   338,   187,   198,   212,   -51,   176,
     196,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,
     -51,   -51,   -51,    -7,   222,   -51,   251,   251,   251,    86,
     251,    86,   251,    86,   251,    86,   251,    86,   251,    86,
     -51,   -51,   245,   326,   -16,   -51,   -51,   237,   -51,   246,
     226,   249,    77,   235,   -51,   -13,     4,   -51,   -51,    -7,
     -51,   -51,   236,   -51,   -51,   -51,   -51,     4,   -51,   -51,
     -51,   -51
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     5,     0,     2,     5,     5,    16,    15,    14,
      10,    11,    12,    13,     9,     8,     7,   103,   104,     0,
       0,   101,     0,     0,    99,   102,   100,     0,     0,    66,
      64,    65,    89,    96,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    17,
      18,     0,     0,     1,     4,     3,     0,    85,    88,     0,
       0,     0,    86,    87,   103,     0,     0,    25,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    37,     0,     0,     0,    62,    63,     0,     0,     0,
       0,     0,     0,     6,    29,    28,    68,    70,     0,     0,
       0,     0,    77,    93,    80,    81,    82,    84,    83,    71,
      72,    73,    74,    75,     0,    94,    95,    91,    90,    92,
       0,     0,     0,     0,     0,     0,     0,     0,    39,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    67,     0,
       0,    79,    76,    46,    47,    45,    40,    41,    42,    43,
      44,    36,    34,     0,     0,    38,    49,    48,    50,    56,
      52,    58,    53,    59,    51,    57,    54,    60,    55,    61,
      27,    31,     0,     0,     0,    26,    69,     0,    33,     0,
       0,     0,     0,     0,    20,     0,     5,    78,    35,     0,
      32,   103,     0,    97,    98,    24,    19,     5,    21,    30,
      23,    22
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -51,   -51,   -12,    -6,   -51,   -51,   -51,    83,   -51,   -51,
     233,   -51,   -51,   -51,   -51,   -51,   252,   105,   -50,   -31,
     -51,   -51,   -35,     3,   -51,    97,    98
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    13,    14,    15,    16,    17,   215,   216,    18,    19,
      20,    21,    22,    23,    24,   151,    25,    26,   104,    38,
      39,   118,    40,    41,   222,    42,    43
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      62,    57,    75,    64,    65,   107,   101,     1,     2,   212,
     213,    28,   212,   213,     3,     4,    53,     5,     6,   105,
     105,   100,    54,   103,   168,    67,    68,     7,     8,   169,
     112,     9,    10,     4,   214,   120,   121,   226,   117,    11,
      76,   149,    12,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,    12,   134,   137,   139,   106,   106,   164,
     114,   140,   141,   142,   143,   144,   145,   146,   147,    78,
      79,    12,   152,   101,   105,    88,    89,    55,   150,    67,
      68,   221,    28,   183,    75,   102,    56,   172,   184,    58,
     103,   135,   136,   138,    88,    89,    59,    69,    80,    81,
      82,    83,    84,    85,    86,    87,    31,    90,    91,    34,
      35,    36,   106,   170,   123,   203,    90,    91,   186,   187,
     188,   190,   192,   194,   196,   198,    90,    91,    60,    61,
     105,    85,    86,    87,    63,   207,    66,    76,   206,    83,
      84,    85,    86,    87,   182,    27,    28,    29,    30,    70,
      71,    72,    73,    77,   108,   200,   201,    92,   189,   191,
     193,   195,   197,   199,    93,    94,    95,    96,   106,    97,
      31,    32,    33,    34,    35,    36,    98,   208,    99,   110,
      27,    28,    29,    30,   111,   113,   148,   163,   116,    37,
     165,    74,    28,    29,    30,   173,   166,   174,   167,   175,
      74,   176,    29,    30,   228,    31,    32,    33,    34,    35,
      36,   177,   181,   229,   178,   231,    31,    32,    33,    34,
      35,    36,    78,    79,    37,    31,    32,    33,    34,    35,
      36,   179,   209,    78,    79,    37,    80,    81,    82,   180,
     185,    85,    86,    87,   119,    78,    79,   204,   205,     2,
     218,    80,    81,    82,    83,    84,    85,    86,    87,    78,
      79,   122,    80,    81,    82,    83,    84,    85,    86,    87,
      78,    79,   171,   219,    80,    81,    82,    83,    84,    85,
      86,    87,    78,    79,   217,   220,   225,   230,    80,    81,
      82,    83,    84,    85,    86,    87,    78,    79,   227,   115,
      81,    82,    83,    84,    85,    86,    87,   210,   109,   223,
     224,     0,     0,    82,    83,    84,    85,    86,    87,   153,
     154,   155,   156,   157,   158,   159,   160,     0,    83,    84,
      85,    86,    87,   153,   154,   155,   156,   157,   158,   159,
     160,   153,   154,   155,   156,   157,   158,   159,   160,     0,
       0,   161,     0,   153,   154,   155,   156,   157,   158,   159,
     160,     0,     0,     0,     0,   162,     0,     0,     0,     0,
       0,     0,     0,   211,   202,     0,    44,    45,    46,    47,
      48,    49,    50,    51,     0,     0,     0,     0,     0,     0,
       0,     0,    52
};

static const yytype_int16 yycheck[] =
{
      12,     7,    37,    15,    16,    55,    36,     3,     4,    25,
      26,     5,    25,    26,    10,    11,     4,    13,    14,    54,
      55,    52,    48,    53,    47,    30,    31,    23,    24,    52,
      61,    27,    28,    11,    50,    70,    71,    50,    69,    35,
      37,    10,    49,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    49,    48,    90,    91,    54,    55,   109,
      66,    92,    93,    94,    95,    96,    97,    98,    99,     8,
       9,    49,   103,    36,   109,     8,     9,    48,    47,    30,
      31,     4,     5,    47,   119,    48,    48,   122,    52,    48,
      53,    88,    89,    90,     8,     9,    36,    48,    37,    38,
      39,    40,    41,    42,    43,    44,    29,    40,    41,    32,
      33,    34,   109,    52,    47,   165,    40,    41,   153,   154,
     155,   156,   157,   158,   159,   160,    40,    41,    36,    48,
     165,    42,    43,    44,     0,   170,    12,   134,   169,    40,
      41,    42,    43,    44,   150,     4,     5,     6,     7,    48,
      48,     4,     4,    36,    10,   161,   162,    53,   155,   156,
     157,   158,   159,   160,    53,    53,    53,    53,   165,    53,
      29,    30,    31,    32,    33,    34,    53,   183,    53,    13,
       4,     5,     6,     7,     4,    50,    36,     4,    47,    48,
      48,     4,     5,     6,     7,    36,    47,    36,    47,    36,
       4,    36,     6,     7,   216,    29,    30,    31,    32,    33,
      34,    36,     4,   219,    36,   227,    29,    30,    31,    32,
      33,    34,     8,     9,    48,    29,    30,    31,    32,    33,
      34,    36,    10,     8,     9,    48,    37,    38,    39,    36,
      36,    42,    43,    44,    48,     8,     9,    49,    36,     4,
       4,    37,    38,    39,    40,    41,    42,    43,    44,     8,
       9,    47,    37,    38,    39,    40,    41,    42,    43,    44,
       8,     9,    47,    47,    37,    38,    39,    40,    41,    42,
      43,    44,     8,     9,    47,    36,    51,    51,    37,    38,
      39,    40,    41,    42,    43,    44,     8,     9,   215,    66,
      38,    39,    40,    41,    42,    43,    44,   202,    56,   212,
     212,    -1,    -1,    39,    40,    41,    42,    43,    44,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    40,    41,
      42,    43,    44,    15,    16,    17,    18,    19,    20,    21,
      22,    15,    16,    17,    18,    19,    20,    21,    22,    -1,
      -1,    47,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    47,    36,    -1,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,    10,    11,    13,    14,    23,    24,    27,
      28,    35,    49,    55,    56,    57,    58,    59,    62,    63,
      64,    65,    66,    67,    68,    70,    71,     4,     5,     6,
       7,    29,    30,    31,    32,    33,    34,    48,    73,    74,
      76,    77,    79,    80,    37,    38,    39,    40,    41,    42,
      43,    44,    53,     4,    48,    48,    48,    57,    48,    36,
      36,    48,    56,     0,    56,    56,    12,    30,    31,    48,
      48,    48,     4,     4,     4,    76,    77,    36,     8,     9,
      37,    38,    39,    40,    41,    42,    43,    44,     8,     9,
      40,    41,    53,    53,    53,    53,    53,    53,    53,    53,
      73,    36,    48,    53,    72,    76,    77,    72,    10,    70,
      13,     4,    73,    50,    57,    64,    47,    73,    75,    48,
      76,    76,    47,    47,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    48,    77,    77,    76,    77,    76,
      73,    73,    73,    73,    73,    73,    73,    73,    36,    10,
      47,    69,    73,    15,    16,    17,    18,    19,    20,    21,
      22,    47,    47,     4,    72,    48,    47,    47,    47,    52,
      52,    47,    76,    36,    36,    36,    36,    36,    36,    36,
      36,     4,    57,    47,    52,    36,    76,    76,    76,    77,
      76,    77,    76,    77,    76,    77,    76,    77,    76,    77,
      57,    57,    36,    72,    49,    36,    73,    76,    57,    10,
      71,    47,    25,    26,    50,    60,    61,    47,     4,    47,
      36,     4,    78,    79,    80,    51,    50,    61,    56,    57,
      51,    56
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    56,    56,    56,    57,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    59,
      59,    60,    60,    61,    61,    62,    63,    64,    64,    64,
      65,    66,    67,    68,    68,    69,    69,    70,    70,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    73,    73,    73,    74,    74,    75,
      75,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      77,    77,    77,    77,    77,    77,    77,    78,    78,    79,
      79,    79,    79,    79,    80
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     0,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     7,
       6,     2,     3,     3,     2,     3,     5,     5,     3,     3,
       8,     5,     7,     6,     5,     4,     2,     3,     5,     4,
       5,     5,     5,     5,     5,     5,     5,     5,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     4,     3,     3,
       1,     3,     3,     3,     3,     3,     4,     3,     6,     4,
       3,     3,     3,     3,     3,     2,     2,     2,     2,     1,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Program: Sentences  */
#line 71 "lex-yacc/parser.ypp"
                    {
    ScopeNode* scopeNode = new ScopeNode((yyvsp[0].Node));
    scopeNode->run();
}
#line 1347 "src/parser.tab.cpp"
    break;

  case 3: /* Sentences: Sentence Sentences  */
#line 77 "lex-yacc/parser.ypp"
                                { (yyval.Node) = (yyvsp[-1].Node)->setNext((yyvsp[0].Node)); }
#line 1353 "src/parser.tab.cpp"
    break;

  case 4: /* Sentences: Scope Sentences  */
#line 79 "lex-yacc/parser.ypp"
                                { (yyval.Node) = (yyvsp[-1].Node)->setNext((yyvsp[0].Node)); }
#line 1359 "src/parser.tab.cpp"
    break;

  case 5: /* Sentences: %empty  */
#line 81 "lex-yacc/parser.ypp"
                                { (yyval.Node) = nullptr; }
#line 1365 "src/parser.tab.cpp"
    break;

  case 6: /* Scope: '{' Sentences '}'  */
#line 83 "lex-yacc/parser.ypp"
                                { (yyval.Node) = new ScopeNode((yyvsp[-1].Node)); }
#line 1371 "src/parser.tab.cpp"
    break;

  case 7: /* Sentence: VariableAssignment  */
#line 87 "lex-yacc/parser.ypp"
                                { (yyval.Node) = (yyvsp[0].Node); }
#line 1377 "src/parser.tab.cpp"
    break;

  case 8: /* Sentence: VariableDeclaration  */
#line 88 "lex-yacc/parser.ypp"
                                { (yyval.Node) = (yyvsp[0].Node); }
#line 1383 "src/parser.tab.cpp"
    break;

  case 9: /* Sentence: FunctionDefinition  */
#line 89 "lex-yacc/parser.ypp"
                                { (yyval.Node) = (yyvsp[0].Node); }
#line 1389 "src/parser.tab.cpp"
    break;

  case 10: /* Sentence: IFSentence  */
#line 90 "lex-yacc/parser.ypp"
                                { (yyval.Node) = (yyvsp[0].Node); }
#line 1395 "src/parser.tab.cpp"
    break;

  case 11: /* Sentence: ForSentence  */
#line 91 "lex-yacc/parser.ypp"
                                { (yyval.Node) = (yyvsp[0].Node); }
#line 1401 "src/parser.tab.cpp"
    break;

  case 12: /* Sentence: WhileSentence  */
#line 92 "lex-yacc/parser.ypp"
                                { (yyval.Node) = (yyvsp[0].Node); }
#line 1407 "src/parser.tab.cpp"
    break;

  case 13: /* Sentence: DoWhileSentence  */
#line 93 "lex-yacc/parser.ypp"
                                { (yyval.Node) = (yyvsp[0].Node); }
#line 1413 "src/parser.tab.cpp"
    break;

  case 14: /* Sentence: PrintSentence  */
#line 94 "lex-yacc/parser.ypp"
                                { (yyval.Node) = (yyvsp[0].Node); }
#line 1419 "src/parser.tab.cpp"
    break;

  case 15: /* Sentence: ReturnSentence  */
#line 95 "lex-yacc/parser.ypp"
                                { (yyval.Node) = (yyvsp[0].Node); }
#line 1425 "src/parser.tab.cpp"
    break;

  case 16: /* Sentence: SwitchSentence  */
#line 96 "lex-yacc/parser.ypp"
                                { (yyval.Node) = (yyvsp[0].Node); }
#line 1431 "src/parser.tab.cpp"
    break;

  case 17: /* Sentence: CONTINUE ';'  */
#line 97 "lex-yacc/parser.ypp"
                                { (yyval.Node) = new ContinueNode();}
#line 1437 "src/parser.tab.cpp"
    break;

  case 18: /* Sentence: BREAK ';'  */
#line 98 "lex-yacc/parser.ypp"
                                { (yyval.Node) = new BreakNode();}
#line 1443 "src/parser.tab.cpp"
    break;

  case 19: /* SwitchSentence: SWITCH '(' IDENTIFIER ')' '{' SwitchBody '}'  */
#line 102 "lex-yacc/parser.ypp"
                                                   { (yyval.Node) = new SwitchNode((yyvsp[-4].str), (yyvsp[-1].SB)); }
#line 1449 "src/parser.tab.cpp"
    break;

  case 20: /* SwitchSentence: SWITCH '(' IDENTIFIER ')' '{' '}'  */
#line 103 "lex-yacc/parser.ypp"
                                                   { (yyval.Node) = new SwitchNode((yyvsp[-3].str), nullptr); }
#line 1455 "src/parser.tab.cpp"
    break;

  case 21: /* SwitchBody: Case Sentences  */
#line 106 "lex-yacc/parser.ypp"
                                    { 
        (yyval.SB) = new SwitchBody(dynamic_cast<CaseNode*>((yyvsp[-1].Node))->assignBody((yyvsp[0].Node))); 
    }
#line 1463 "src/parser.tab.cpp"
    break;

  case 22: /* SwitchBody: SwitchBody Case Sentences  */
#line 109 "lex-yacc/parser.ypp"
                                    { 
        (yyval.SB) = dynamic_cast<SwitchBody*>((yyvsp[-2].SB))->addCase(dynamic_cast<CaseNode*>((yyvsp[-1].Node))->assignBody((yyvsp[0].Node))); 
    }
#line 1471 "src/parser.tab.cpp"
    break;

  case 23: /* Case: CASE Operand ':'  */
#line 114 "lex-yacc/parser.ypp"
                                    { (yyval.Node) = new CaseNode((yyvsp[-1].Exp)); }
#line 1477 "src/parser.tab.cpp"
    break;

  case 24: /* Case: DEFAULT ':'  */
#line 115 "lex-yacc/parser.ypp"
                                    { (yyval.Node) = new CaseNode();}
#line 1483 "src/parser.tab.cpp"
    break;

  case 25: /* ReturnSentence: RETURN Operation ';'  */
#line 118 "lex-yacc/parser.ypp"
                                    { (yyval.Node) = new ReturnNode((yyvsp[-1].Exp));}
#line 1489 "src/parser.tab.cpp"
    break;

  case 26: /* PrintSentence: PRINT '(' Operation ')' ';'  */
#line 121 "lex-yacc/parser.ypp"
                                    {
                                        (yyval.Node) = new PrintNode((yyvsp[-2].Exp));
                                    }
#line 1497 "src/parser.tab.cpp"
    break;

  case 27: /* IFSentence: IF '(' Condition ')' Scope  */
#line 126 "lex-yacc/parser.ypp"
                                   { (yyval.Node) = new IfNode((yyvsp[-2].Exp), (yyvsp[0].Node));   }
#line 1503 "src/parser.tab.cpp"
    break;

  case 28: /* IFSentence: IFSentence ELSE IFSentence  */
#line 127 "lex-yacc/parser.ypp"
                                   { (yyval.Node) = dynamic_cast<IfNode*>((yyvsp[-2].Node))->setElse((yyvsp[0].Node));  }
#line 1509 "src/parser.tab.cpp"
    break;

  case 29: /* IFSentence: IFSentence ELSE Scope  */
#line 128 "lex-yacc/parser.ypp"
                                   { (yyval.Node) = dynamic_cast<IfNode*>((yyvsp[-2].Node))->setElse((yyvsp[0].Node));  }
#line 1515 "src/parser.tab.cpp"
    break;

  case 30: /* ForSentence: FOR '(' VariableDeclaration Condition ';' VariableAssignment ')' Scope  */
#line 130 "lex-yacc/parser.ypp"
                                                                                    {
    (yyval.Node) = new ForNode(dynamic_cast<DefineNode*>((yyvsp[-5].Node)), (yyvsp[-4].Exp), dynamic_cast<AssignNode*>((yyvsp[-2].Node)), dynamic_cast<ScopeNode*>((yyvsp[0].Node)));
}
#line 1523 "src/parser.tab.cpp"
    break;

  case 31: /* WhileSentence: WHILE '(' Condition ')' Scope  */
#line 134 "lex-yacc/parser.ypp"
                                             {
    (yyval.Node) = new WhileNode((yyvsp[-2].Exp), dynamic_cast<ScopeNode*>((yyvsp[0].Node)));
}
#line 1531 "src/parser.tab.cpp"
    break;

  case 32: /* DoWhileSentence: DO Scope WHILE '(' Condition ')' ';'  */
#line 138 "lex-yacc/parser.ypp"
                                                      {
    (yyval.Node) = new DoWhileNode((yyvsp[-2].Exp), dynamic_cast<ScopeNode*>((yyvsp[-5].Node)));
}
#line 1539 "src/parser.tab.cpp"
    break;

  case 33: /* FunctionDefinition: DATA_TYPE IDENTIFIER '(' FunctionParams ')' Scope  */
#line 143 "lex-yacc/parser.ypp"
                                                        { 
        dynamic_cast<ScopeNode*>((yyvsp[0].Node))->returnable = true;
        (yyval.Node) = new FunctionDefintionNode((yyvsp[-5].str), (yyvsp[-4].str), (yyvsp[-2].FP), dynamic_cast<ScopeNode*>((yyvsp[0].Node))); 
    }
#line 1548 "src/parser.tab.cpp"
    break;

  case 34: /* FunctionDefinition: DATA_TYPE IDENTIFIER '(' ')' Scope  */
#line 147 "lex-yacc/parser.ypp"
                                                        { 
        dynamic_cast<ScopeNode*>((yyvsp[0].Node))->returnable = true;
        (yyval.Node) = new FunctionDefintionNode((yyvsp[-4].str), (yyvsp[-3].str), nullptr, dynamic_cast<ScopeNode*>((yyvsp[0].Node))); 
    }
#line 1557 "src/parser.tab.cpp"
    break;

  case 35: /* FunctionParams: FunctionParams ',' DATA_TYPE IDENTIFIER  */
#line 153 "lex-yacc/parser.ypp"
                                                    { (yyval.FP) = (yyvsp[-3].FP)->addParameter((yyvsp[-1].str), (yyvsp[0].str));}
#line 1563 "src/parser.tab.cpp"
    break;

  case 36: /* FunctionParams: DATA_TYPE IDENTIFIER  */
#line 154 "lex-yacc/parser.ypp"
                                                    { (yyval.FP) = new FunctionParametersNode((yyvsp[-1].str), (yyvsp[0].str));}
#line 1569 "src/parser.tab.cpp"
    break;

  case 37: /* VariableDeclaration: DATA_TYPE IDENTIFIER ';'  */
#line 157 "lex-yacc/parser.ypp"
                                                    { (yyval.Node) = new DefineNode((yyvsp[-2].str), (yyvsp[-1].str), nullptr); }
#line 1575 "src/parser.tab.cpp"
    break;

  case 38: /* VariableDeclaration: DATA_TYPE IDENTIFIER '=' Operation ';'  */
#line 158 "lex-yacc/parser.ypp"
                                                    { (yyval.Node) = new DefineNode((yyvsp[-4].str), (yyvsp[-3].str), (yyvsp[-1].Exp)); }
#line 1581 "src/parser.tab.cpp"
    break;

  case 39: /* VariableAssignment: IDENTIFIER '=' Operation ';'  */
#line 161 "lex-yacc/parser.ypp"
                                          { (yyval.Node) = new AssignNode((yyvsp[-3].str), (yyvsp[-1].Exp)); }
#line 1587 "src/parser.tab.cpp"
    break;

  case 40: /* VariableAssignment: IDENTIFIER '+' '=' Operation ';'  */
#line 163 "lex-yacc/parser.ypp"
                                          { 
        Expression* id = new IdentifierContainer((yyvsp[-4].str));
        Expression* exp = new Expression(id, (yyvsp[-1].Exp), OP_ADD);
        (yyval.Node) = new AssignNode((yyvsp[-4].str), exp); 
    }
#line 1597 "src/parser.tab.cpp"
    break;

  case 41: /* VariableAssignment: IDENTIFIER '-' '=' Operation ';'  */
#line 169 "lex-yacc/parser.ypp"
                                          { 
        Expression* id = new IdentifierContainer((yyvsp[-4].str));
        Expression* exp = new Expression(id, (yyvsp[-1].Exp), OP_SUB);
        (yyval.Node) = new AssignNode((yyvsp[-4].str), exp); 
    }
#line 1607 "src/parser.tab.cpp"
    break;

  case 42: /* VariableAssignment: IDENTIFIER '*' '=' Operation ';'  */
#line 175 "lex-yacc/parser.ypp"
                                          { 
        Expression* id = new IdentifierContainer((yyvsp[-4].str));
        Expression* exp = new Expression(id, (yyvsp[-1].Exp), OP_MUL);
        (yyval.Node) = new AssignNode((yyvsp[-4].str), exp); 
    }
#line 1617 "src/parser.tab.cpp"
    break;

  case 43: /* VariableAssignment: IDENTIFIER '/' '=' Operation ';'  */
#line 181 "lex-yacc/parser.ypp"
                                          { 
        Expression* id = new IdentifierContainer((yyvsp[-4].str));
        Expression* exp = new Expression(id, (yyvsp[-1].Exp), OP_DIV);
        (yyval.Node) = new AssignNode((yyvsp[-4].str), exp); 
    }
#line 1627 "src/parser.tab.cpp"
    break;

  case 44: /* VariableAssignment: IDENTIFIER '%' '=' Operation ';'  */
#line 187 "lex-yacc/parser.ypp"
                                          { 
        Expression* id = new IdentifierContainer((yyvsp[-4].str));
        Expression* exp = new Expression(id, (yyvsp[-1].Exp), OP_MOD);
        (yyval.Node) = new AssignNode((yyvsp[-4].str), exp); 
    }
#line 1637 "src/parser.tab.cpp"
    break;

  case 45: /* VariableAssignment: IDENTIFIER '&' '=' Operation ';'  */
#line 193 "lex-yacc/parser.ypp"
                                          { 
        Expression* id = new IdentifierContainer((yyvsp[-4].str));
        Expression* exp = new Expression(id, (yyvsp[-1].Exp), OP_AND);
        (yyval.Node) = new AssignNode((yyvsp[-4].str), exp); 
    }
#line 1647 "src/parser.tab.cpp"
    break;

  case 46: /* VariableAssignment: IDENTIFIER '|' '=' Operation ';'  */
#line 199 "lex-yacc/parser.ypp"
                                          { 
        Expression* id = new IdentifierContainer((yyvsp[-4].str));
        Expression* exp = new Expression(id, (yyvsp[-1].Exp), OP_OR);
        (yyval.Node) = new AssignNode((yyvsp[-4].str), exp); 
    }
#line 1657 "src/parser.tab.cpp"
    break;

  case 47: /* VariableAssignment: IDENTIFIER '^' '=' Operation ';'  */
#line 205 "lex-yacc/parser.ypp"
                                          { 
        Expression* id = new IdentifierContainer((yyvsp[-4].str));
        Expression* exp = new Expression(id, (yyvsp[-1].Exp), OP_XOR);
        (yyval.Node) = new AssignNode((yyvsp[-4].str), exp); 
    }
#line 1667 "src/parser.tab.cpp"
    break;

  case 48: /* Condition: Condition OR MathOperation  */
#line 213 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_OR);  }
#line 1673 "src/parser.tab.cpp"
    break;

  case 49: /* Condition: Condition AND MathOperation  */
#line 214 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_AND); }
#line 1679 "src/parser.tab.cpp"
    break;

  case 50: /* Condition: Condition GTE MathOperation  */
#line 215 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_GE);  }
#line 1685 "src/parser.tab.cpp"
    break;

  case 51: /* Condition: Condition GT MathOperation  */
#line 216 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_GT);  }
#line 1691 "src/parser.tab.cpp"
    break;

  case 52: /* Condition: Condition LTE MathOperation  */
#line 217 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_LE);  }
#line 1697 "src/parser.tab.cpp"
    break;

  case 53: /* Condition: Condition LT MathOperation  */
#line 218 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_LT);  }
#line 1703 "src/parser.tab.cpp"
    break;

  case 54: /* Condition: Condition ISEQUAL MathOperation  */
#line 219 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_EQ);  }
#line 1709 "src/parser.tab.cpp"
    break;

  case 55: /* Condition: Condition NOTEQUAL MathOperation  */
#line 220 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_NEQ); }
#line 1715 "src/parser.tab.cpp"
    break;

  case 56: /* Condition: Condition GTE StringOperation  */
#line 222 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new StringContainer((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_GE);   }
#line 1721 "src/parser.tab.cpp"
    break;

  case 57: /* Condition: Condition GT StringOperation  */
#line 223 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new StringContainer((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_GT);   }
#line 1727 "src/parser.tab.cpp"
    break;

  case 58: /* Condition: Condition LTE StringOperation  */
#line 224 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new StringContainer((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_LE);   }
#line 1733 "src/parser.tab.cpp"
    break;

  case 59: /* Condition: Condition LT StringOperation  */
#line 225 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new StringContainer((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_LT);   }
#line 1739 "src/parser.tab.cpp"
    break;

  case 60: /* Condition: Condition ISEQUAL StringOperation  */
#line 226 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new StringContainer((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_EQ);   }
#line 1745 "src/parser.tab.cpp"
    break;

  case 61: /* Condition: Condition NOTEQUAL StringOperation  */
#line 227 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new StringContainer((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_NEQ);  }
#line 1751 "src/parser.tab.cpp"
    break;

  case 62: /* Condition: MathOperation  */
#line 229 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = (yyvsp[0].Exp); }
#line 1757 "src/parser.tab.cpp"
    break;

  case 63: /* Condition: StringOperation  */
#line 230 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = (yyvsp[0].Exp); }
#line 1763 "src/parser.tab.cpp"
    break;

  case 64: /* Operation: MathOperation  */
#line 233 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = (yyvsp[0].Exp); }
#line 1769 "src/parser.tab.cpp"
    break;

  case 65: /* Operation: StringOperation  */
#line 234 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = (yyvsp[0].Exp); }
#line 1775 "src/parser.tab.cpp"
    break;

  case 66: /* Operation: FunctionCall  */
#line 235 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = (yyvsp[0].Exp); }
#line 1781 "src/parser.tab.cpp"
    break;

  case 67: /* FunctionCall: IDENTIFIER '(' FunctionCallParams ')'  */
#line 238 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new FunctionCallNode( (yyvsp[-3].str), (yyvsp[-1].FCP) ); }
#line 1787 "src/parser.tab.cpp"
    break;

  case 68: /* FunctionCall: IDENTIFIER '(' ')'  */
#line 239 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new FunctionCallNode( (yyvsp[-2].str), nullptr ); }
#line 1793 "src/parser.tab.cpp"
    break;

  case 69: /* FunctionCallParams: FunctionCallParams ',' Operation  */
#line 242 "lex-yacc/parser.ypp"
                                                    { (yyval.FCP) = (yyvsp[-2].FCP)->addParameter((yyvsp[0].Exp)); }
#line 1799 "src/parser.tab.cpp"
    break;

  case 70: /* FunctionCallParams: Operation  */
#line 243 "lex-yacc/parser.ypp"
                                                    { (yyval.FCP) = new FunctionCallParametersNode((yyvsp[0].Exp)); }
#line 1805 "src/parser.tab.cpp"
    break;

  case 71: /* MathOperation: MathOperation '+' MathOperation  */
#line 246 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_ADD); }
#line 1811 "src/parser.tab.cpp"
    break;

  case 72: /* MathOperation: MathOperation '-' MathOperation  */
#line 247 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_SUB); }
#line 1817 "src/parser.tab.cpp"
    break;

  case 73: /* MathOperation: MathOperation '*' MathOperation  */
#line 248 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_MUL); }
#line 1823 "src/parser.tab.cpp"
    break;

  case 74: /* MathOperation: MathOperation '/' MathOperation  */
#line 249 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_DIV); }
#line 1829 "src/parser.tab.cpp"
    break;

  case 75: /* MathOperation: MathOperation '%' MathOperation  */
#line 250 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_MOD); }
#line 1835 "src/parser.tab.cpp"
    break;

  case 76: /* MathOperation: '(' MathOperation ')' MathOperation  */
#line 251 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_MUL); }
#line 1841 "src/parser.tab.cpp"
    break;

  case 77: /* MathOperation: '(' MathOperation ')'  */
#line 252 "lex-yacc/parser.ypp"
                                                    {                   (yyval.Exp) = (yyvsp[-1].Exp);               }
#line 1847 "src/parser.tab.cpp"
    break;

  case 78: /* MathOperation: POW '(' MathOperation ',' MathOperation ')'  */
#line 253 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-3].Exp), (yyvsp[-1].Exp), OP_POW);  }
#line 1853 "src/parser.tab.cpp"
    break;

  case 79: /* MathOperation: SQRT '(' MathOperation ')'  */
#line 254 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-1].Exp), (yyvsp[-1].Exp), OP_SQRT); }
#line 1859 "src/parser.tab.cpp"
    break;

  case 80: /* MathOperation: MathOperation SHL MathOperation  */
#line 255 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_SHL); }
#line 1865 "src/parser.tab.cpp"
    break;

  case 81: /* MathOperation: MathOperation SHR MathOperation  */
#line 256 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_SHR); }
#line 1871 "src/parser.tab.cpp"
    break;

  case 82: /* MathOperation: MathOperation '|' MathOperation  */
#line 257 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_OR); }
#line 1877 "src/parser.tab.cpp"
    break;

  case 83: /* MathOperation: MathOperation '&' MathOperation  */
#line 258 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_AND); }
#line 1883 "src/parser.tab.cpp"
    break;

  case 84: /* MathOperation: MathOperation '^' MathOperation  */
#line 259 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_XOR); }
#line 1889 "src/parser.tab.cpp"
    break;

  case 85: /* MathOperation: IDENTIFIER INCREMENT  */
#line 260 "lex-yacc/parser.ypp"
                                                      { (yyval.Exp) = new IdentifierContainer((yyvsp[-1].str), OP_POST_ADD); }
#line 1895 "src/parser.tab.cpp"
    break;

  case 86: /* MathOperation: INCREMENT IDENTIFIER  */
#line 261 "lex-yacc/parser.ypp"
                                                      { (yyval.Exp) = new IdentifierContainer((yyvsp[0].str), OP_PRE_ADD); }
#line 1901 "src/parser.tab.cpp"
    break;

  case 87: /* MathOperation: DECREMENT IDENTIFIER  */
#line 262 "lex-yacc/parser.ypp"
                                                      { (yyval.Exp) = new IdentifierContainer((yyvsp[0].str), OP_PRE_SUB); }
#line 1907 "src/parser.tab.cpp"
    break;

  case 88: /* MathOperation: IDENTIFIER DECREMENT  */
#line 263 "lex-yacc/parser.ypp"
                                                      { (yyval.Exp) = new IdentifierContainer((yyvsp[-1].str), OP_POST_ADD); }
#line 1913 "src/parser.tab.cpp"
    break;

  case 90: /* StringOperation: StringOperation '+' StringOperation  */
#line 267 "lex-yacc/parser.ypp"
                                                        { (yyval.Exp) =  new StringContainer((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_ADD); }
#line 1919 "src/parser.tab.cpp"
    break;

  case 91: /* StringOperation: StringOperation '+' MathOperation  */
#line 268 "lex-yacc/parser.ypp"
                                                        { (yyval.Exp) =  new StringContainer((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_ADD); }
#line 1925 "src/parser.tab.cpp"
    break;

  case 92: /* StringOperation: StringOperation '-' MathOperation  */
#line 269 "lex-yacc/parser.ypp"
                                                        { (yyval.Exp) =  new StringContainer((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_SUB); }
#line 1931 "src/parser.tab.cpp"
    break;

  case 93: /* StringOperation: '(' StringOperation ')'  */
#line 270 "lex-yacc/parser.ypp"
                                                        { (yyval.Exp) =  (yyvsp[-1].Exp); }
#line 1937 "src/parser.tab.cpp"
    break;

  case 94: /* StringOperation: StringOperation SHL StringOperation  */
#line 272 "lex-yacc/parser.ypp"
                                                            { (yyval.Exp) =  new StringContainer((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_SHL); }
#line 1943 "src/parser.tab.cpp"
    break;

  case 95: /* StringOperation: StringOperation SHR StringOperation  */
#line 273 "lex-yacc/parser.ypp"
                                                            { (yyval.Exp) =  new StringContainer((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_SHR); }
#line 1949 "src/parser.tab.cpp"
    break;

  case 99: /* MathOperand: INTEGER  */
#line 279 "lex-yacc/parser.ypp"
                        { (yyval.Exp) = new Expression((yyvsp[0].str), TINT);}
#line 1955 "src/parser.tab.cpp"
    break;

  case 100: /* MathOperand: FLOAT  */
#line 281 "lex-yacc/parser.ypp"
                        { (yyval.Exp) = new Expression((yyvsp[0].str), TFLOAT);}
#line 1961 "src/parser.tab.cpp"
    break;

  case 101: /* MathOperand: CHARACTER  */
#line 283 "lex-yacc/parser.ypp"
                        { (yyval.Exp) = new Expression((yyvsp[0].str), TCHAR);}
#line 1967 "src/parser.tab.cpp"
    break;

  case 102: /* MathOperand: BOOLEAN  */
#line 285 "lex-yacc/parser.ypp"
                        { (yyval.Exp) = new Expression((yyvsp[0].str), TBOOLEAN);}
#line 1973 "src/parser.tab.cpp"
    break;

  case 103: /* MathOperand: IDENTIFIER  */
#line 287 "lex-yacc/parser.ypp"
                        { (yyval.Exp) = new IdentifierContainer((yyvsp[0].str)); }
#line 1979 "src/parser.tab.cpp"
    break;

  case 104: /* StringOperand: STRING  */
#line 289 "lex-yacc/parser.ypp"
                        { (yyval.Exp) = new StringContainer((yyvsp[0].str)); }
#line 1985 "src/parser.tab.cpp"
    break;


#line 1989 "src/parser.tab.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 291 "lex-yacc/parser.ypp"



int main() {
    ScopeNode* x = new ScopeNode();
    yyin = fopen("test.yapl", "r");
    yyparse();
    return 0;
}
