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

    #include "program.hpp"
    #include "identifier.hpp"
    #include "node.hpp"
    #include "if.hpp"
    #include "for.hpp"

    #include "parser.tab.hpp"
    extern int yylex();
    extern FILE *yyin;   
    void yyerror(const char* s) {
        std::cerr << "Error: " << s << std::endl;
    }

#line 89 "src/parser.tab.cpp"

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
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_STRING = 4,                     /* STRING  */
  YYSYMBOL_POW = 5,                        /* POW  */
  YYSYMBOL_SQRT = 6,                       /* SQRT  */
  YYSYMBOL_SHL = 7,                        /* SHL  */
  YYSYMBOL_SHR = 8,                        /* SHR  */
  YYSYMBOL_DATA_TYPE = 9,                  /* DATA_TYPE  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_WHILE = 12,                     /* WHILE  */
  YYSYMBOL_FOR = 13,                       /* FOR  */
  YYSYMBOL_AND = 14,                       /* AND  */
  YYSYMBOL_OR = 15,                        /* OR  */
  YYSYMBOL_GTE = 16,                       /* GTE  */
  YYSYMBOL_LTE = 17,                       /* LTE  */
  YYSYMBOL_LT = 18,                        /* LT  */
  YYSYMBOL_GT = 19,                        /* GT  */
  YYSYMBOL_ISEQUAL = 20,                   /* ISEQUAL  */
  YYSYMBOL_NOTEQUAL = 21,                  /* NOTEQUAL  */
  YYSYMBOL_FUNCTIONDEF = 22,               /* FUNCTIONDEF  */
  YYSYMBOL_DO = 23,                        /* DO  */
  YYSYMBOL_CHARACTER = 24,                 /* CHARACTER  */
  YYSYMBOL_INTEGER = 25,                   /* INTEGER  */
  YYSYMBOL_BOOLEAN = 26,                   /* BOOLEAN  */
  YYSYMBOL_FLOAT = 27,                     /* FLOAT  */
  YYSYMBOL_PRINT = 28,                     /* PRINT  */
  YYSYMBOL_29_ = 29,                       /* ';'  */
  YYSYMBOL_30_ = 30,                       /* '|'  */
  YYSYMBOL_31_ = 31,                       /* '^'  */
  YYSYMBOL_32_ = 32,                       /* '&'  */
  YYSYMBOL_33_ = 33,                       /* '+'  */
  YYSYMBOL_34_ = 34,                       /* '-'  */
  YYSYMBOL_35_ = 35,                       /* '*'  */
  YYSYMBOL_36_ = 36,                       /* '/'  */
  YYSYMBOL_37_ = 37,                       /* '%'  */
  YYSYMBOL_38_ = 38,                       /* '['  */
  YYSYMBOL_39_ = 39,                       /* ']'  */
  YYSYMBOL_40_ = 40,                       /* ')'  */
  YYSYMBOL_41_ = 41,                       /* '('  */
  YYSYMBOL_42_ = 42,                       /* '{'  */
  YYSYMBOL_43_ = 43,                       /* '}'  */
  YYSYMBOL_44_ = 44,                       /* ','  */
  YYSYMBOL_45_ = 45,                       /* '='  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_Program = 47,                   /* Program  */
  YYSYMBOL_Sentences = 48,                 /* Sentences  */
  YYSYMBOL_Scope = 49,                     /* Scope  */
  YYSYMBOL_Sentence = 50,                  /* Sentence  */
  YYSYMBOL_PrintSentence = 51,             /* PrintSentence  */
  YYSYMBOL_IFSentence = 52,                /* IFSentence  */
  YYSYMBOL_ForSentence = 53,               /* ForSentence  */
  YYSYMBOL_WhileSentence = 54,             /* WhileSentence  */
  YYSYMBOL_DoWhileSentence = 55,           /* DoWhileSentence  */
  YYSYMBOL_FunctionDefinition = 56,        /* FunctionDefinition  */
  YYSYMBOL_FunctionParams = 57,            /* FunctionParams  */
  YYSYMBOL_VariableDeclaration = 58,       /* VariableDeclaration  */
  YYSYMBOL_VariableAssignment = 59,        /* VariableAssignment  */
  YYSYMBOL_Condition = 60,                 /* Condition  */
  YYSYMBOL_Operation = 61,                 /* Operation  */
  YYSYMBOL_MathOperation = 62,             /* MathOperation  */
  YYSYMBOL_StringOperation = 63,           /* StringOperation  */
  YYSYMBOL_MathOperand = 64,               /* MathOperand  */
  YYSYMBOL_StringOperand = 65              /* StringOperand  */
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
#define YYFINAL  31
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   307

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  159

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   283


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
       2,     2,     2,     2,     2,     2,     2,    37,    32,     2,
      41,    40,    35,    33,    44,    34,     2,    36,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    29,
       2,    45,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    39,    31,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,    30,    43,     2,     2,     2,     2,
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
      25,    26,    27,    28
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    77,    77,    84,    86,    88,    90,    93,    94,    95,
      96,    97,    98,    99,   100,   103,   108,   109,   110,   112,
     116,   120,   124,   126,   126,   129,   130,   132,   135,   136,
     137,   138,   139,   140,   141,   142,   144,   145,   146,   147,
     148,   149,   151,   152,   155,   156,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   176,   177,   178,   179,   181,   182,   183,   186,   188,
     190,   192,   194,   196
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
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER", "STRING",
  "POW", "SQRT", "SHL", "SHR", "DATA_TYPE", "IF", "ELSE", "WHILE", "FOR",
  "AND", "OR", "GTE", "LTE", "LT", "GT", "ISEQUAL", "NOTEQUAL",
  "FUNCTIONDEF", "DO", "CHARACTER", "INTEGER", "BOOLEAN", "FLOAT", "PRINT",
  "';'", "'|'", "'^'", "'&'", "'+'", "'-'", "'*'", "'/'", "'%'", "'['",
  "']'", "')'", "'('", "'{'", "'}'", "','", "'='", "$accept", "Program",
  "Sentences", "Scope", "Sentence", "PrintSentence", "IFSentence",
  "ForSentence", "WhileSentence", "DoWhileSentence", "FunctionDefinition",
  "FunctionParams", "VariableDeclaration", "VariableAssignment",
  "Condition", "Operation", "MathOperation", "StringOperation",
  "MathOperand", "StringOperand", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-37)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       2,   -36,    10,   -18,   -15,    -4,    25,     1,    -3,     2,
      40,   -37,     2,     2,   -37,    34,   -37,   -37,   -37,   -37,
     -37,   -37,    83,   -13,    83,    83,    47,    16,    58,    83,
      29,   -37,   -37,   -37,    -6,   -37,   -37,    32,    39,   -37,
     -37,   -37,   -37,    83,    52,   192,    27,   -37,   -37,   -37,
      83,    43,   200,   273,    44,    83,    82,    60,    62,   -37,
     -37,    34,    71,    71,   124,   172,   -37,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    -2,    -2,    83,
      71,    76,     1,    71,    71,    71,    71,    71,    71,    71,
      71,    -2,    -2,    -2,    -2,    -2,    -2,     1,    77,   108,
      89,    83,   104,    71,    86,   141,    71,   -37,   -16,   -16,
     231,   237,   242,    78,    78,   -37,   -37,   -37,    -2,   -27,
     -27,   166,   -37,   166,   -37,   -37,   192,   192,   192,   192,
     192,   192,   192,   192,    27,    27,    27,    27,    27,    27,
     -37,   131,    93,     1,    95,   -37,    71,   -37,   -37,    98,
      82,   -37,   110,   155,     1,   -37,   -37,   -37,   -37
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     0,     0,     0,     0,     0,     0,     0,     5,
       0,     2,     5,     5,    14,    10,    11,    12,    13,     9,
       8,     7,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,     4,     3,     0,    72,    73,     0,     0,    70,
      68,    71,    69,     0,     0,    44,    45,    60,    67,    25,
       0,     0,    42,    43,     0,     0,    24,     0,     0,     6,
      18,    17,     0,     0,     0,     0,    27,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    52,    64,    55,    56,
      57,    59,    58,    46,    47,    48,    49,    50,     0,    65,
      66,    62,    61,    63,    26,    16,    29,    28,    30,    32,
      33,    31,    34,    35,    36,    38,    39,    37,    40,    41,
      20,     0,     0,     0,     0,    15,     0,    54,    51,     0,
      24,    22,     0,     0,     0,    23,    21,    53,    19
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -37,   -37,    91,    -7,   -37,   -37,   112,   -37,   -37,   -37,
     -37,     0,   125,    11,   -22,   -19,   -21,    49,   -37,   -37
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,   100,    20,    21,    51,    44,    52,    53,    47,    48
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      28,    45,    36,    54,     3,     1,    79,    80,    45,    22,
      58,     2,     3,    23,     4,     5,    49,    72,    73,    74,
      75,    76,    64,    24,     6,     7,    25,    60,    27,    45,
       8,    81,    50,    98,    77,    78,     9,    26,    29,   118,
      31,   104,   105,     9,     9,    34,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,     2,    56,   121,   123,
      79,    80,   126,   127,   128,   129,   130,   131,   132,   133,
      57,    46,    59,    62,    35,   125,    37,    38,    46,   144,
      63,    66,    64,    82,    97,   148,    35,    36,    37,    38,
     140,    99,    65,    67,    68,    39,    40,    41,    42,    46,
      30,   101,   102,    32,    33,   124,   141,    39,    40,    41,
      42,   142,   103,    74,    75,    76,    69,    70,    71,    72,
      73,    74,    75,    76,    43,   153,   119,   120,   122,   143,
     146,    67,    68,   145,     1,   152,   151,   150,   154,   156,
     134,   135,   136,   137,   138,   139,    61,   158,    67,    68,
     155,    55,   149,     0,    69,    70,    71,    72,    73,    74,
      75,    76,    67,    68,   106,     0,     0,    65,     0,     0,
       0,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,   147,     0,     0,     0,    69,    70,    71,    72,    73,
      74,    75,    76,     0,     0,   157,    69,    70,    71,    67,
      68,    74,    75,    76,     0,    79,    80,    67,    68,     0,
       0,     0,   107,     0,    83,    84,    85,    86,    87,    88,
      89,    90,    69,    70,    71,    72,    73,    74,    75,    76,
      69,    70,    71,    72,    73,    74,    75,    76,    67,    68,
       0,     0,     0,     0,    67,    68,     0,     0,     0,    67,
      68,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    70,    71,    72,    73,    74,    75,    76,    71,
      72,    73,    74,    75,    76,    72,    73,    74,    75,    76,
      77,    78,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,    95,    96,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    79,    80
};

static const yytype_int16 yycheck[] =
{
       7,    22,     4,    25,    10,     3,    33,    34,    29,    45,
      29,     9,    10,     3,    12,    13,    29,    33,    34,    35,
      36,    37,    43,    41,    22,    23,    41,    34,     3,    50,
      28,    50,    45,    55,     7,     8,    42,    41,    41,    41,
       0,    62,    63,    42,    42,    11,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,     9,    41,    79,    80,
      33,    34,    83,    84,    85,    86,    87,    88,    89,    90,
      12,    22,    43,    41,     3,    82,     5,     6,    29,   101,
      41,    29,   103,    40,    40,   106,     3,     4,     5,     6,
      97,     9,    43,     7,     8,    24,    25,    26,    27,    50,
       9,    41,    40,    12,    13,    29,    29,    24,    25,    26,
      27,     3,    41,    35,    36,    37,    30,    31,    32,    33,
      34,    35,    36,    37,    41,   146,    77,    78,    79,    40,
      44,     7,     8,    29,     3,    40,   143,    44,    40,    29,
      91,    92,    93,    94,    95,    96,    34,   154,     7,     8,
     150,    26,   141,    -1,    30,    31,    32,    33,    34,    35,
      36,    37,     7,     8,    40,    -1,    -1,   118,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,     7,
       8,    40,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    40,    30,    31,    32,     7,
       8,    35,    36,    37,    -1,    33,    34,     7,     8,    -1,
      -1,    -1,    40,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    30,    31,    32,    33,    34,    35,    36,    37,
      30,    31,    32,    33,    34,    35,    36,    37,     7,     8,
      -1,    -1,    -1,    -1,     7,     8,    -1,    -1,    -1,     7,
       8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,    33,    34,    35,    36,    37,    32,
      33,    34,    35,    36,    37,    33,    34,    35,    36,    37,
       7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     9,    10,    12,    13,    22,    23,    28,    42,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      58,    59,    45,     3,    41,    41,    41,     3,    49,    41,
      48,     0,    48,    48,    11,     3,     4,     5,     6,    24,
      25,    26,    27,    41,    61,    62,    63,    64,    65,    29,
      45,    60,    62,    63,    60,    58,    41,    12,    61,    43,
      49,    52,    41,    41,    62,    63,    29,     7,     8,    30,
      31,    32,    33,    34,    35,    36,    37,     7,     8,    33,
      34,    61,    40,    14,    15,    16,    17,    18,    19,    20,
      21,    16,    17,    18,    19,    20,    21,    40,    60,     9,
      57,    41,    40,    41,    62,    62,    40,    40,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    41,    63,
      63,    62,    63,    62,    29,    49,    62,    62,    62,    62,
      62,    62,    62,    62,    63,    63,    63,    63,    63,    63,
      49,    29,     3,    40,    60,    29,    44,    40,    62,    59,
      44,    49,    40,    62,    40,    57,    29,    40,    49
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    48,    49,    50,    50,    50,
      50,    50,    50,    50,    50,    51,    52,    52,    52,    53,
      54,    55,    56,    57,    57,    58,    58,    59,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    61,    61,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    63,    63,    63,    63,    63,    63,    63,    64,    64,
      64,    64,    64,    65
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     0,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     5,     3,     3,     8,
       5,     7,     6,     4,     0,     3,     5,     4,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     4,     3,     6,     4,     3,     3,     3,     3,     3,
       1,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       1,     1,     1,     1
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
#line 77 "lex-yacc/parser.ypp"
                    {
    ScopeNode* scopeNode = new ScopeNode((yyvsp[0].PNode));
    scopeNode->run();
}
#line 1270 "src/parser.tab.cpp"
    break;

  case 3: /* Sentences: Sentence Sentences  */
#line 84 "lex-yacc/parser.ypp"
                                { (yyval.PNode) = (yyvsp[-1].PNode)->setNext((yyvsp[0].PNode)); }
#line 1276 "src/parser.tab.cpp"
    break;

  case 4: /* Sentences: Scope Sentences  */
#line 86 "lex-yacc/parser.ypp"
                                { (yyval.PNode) = (yyvsp[-1].SCNode)->setNext((yyvsp[0].PNode)); }
#line 1282 "src/parser.tab.cpp"
    break;

  case 5: /* Sentences: %empty  */
#line 88 "lex-yacc/parser.ypp"
                                { (yyval.PNode) = nullptr; }
#line 1288 "src/parser.tab.cpp"
    break;

  case 6: /* Scope: '{' Sentences '}'  */
#line 90 "lex-yacc/parser.ypp"
                                { (yyval.SCNode) = new ScopeNode((yyvsp[-1].PNode)); }
#line 1294 "src/parser.tab.cpp"
    break;

  case 7: /* Sentence: VariableAssignment  */
#line 93 "lex-yacc/parser.ypp"
                                { (yyval.PNode) = (yyvsp[0].VANode); }
#line 1300 "src/parser.tab.cpp"
    break;

  case 8: /* Sentence: VariableDeclaration  */
#line 94 "lex-yacc/parser.ypp"
                                { (yyval.PNode) = (yyvsp[0].VDNode); }
#line 1306 "src/parser.tab.cpp"
    break;

  case 9: /* Sentence: FunctionDefinition  */
#line 95 "lex-yacc/parser.ypp"
                                { (yyval.PNode) = new ScopeNode(); }
#line 1312 "src/parser.tab.cpp"
    break;

  case 10: /* Sentence: IFSentence  */
#line 96 "lex-yacc/parser.ypp"
                                { (yyval.PNode) = (yyvsp[0].FNode); }
#line 1318 "src/parser.tab.cpp"
    break;

  case 11: /* Sentence: ForSentence  */
#line 97 "lex-yacc/parser.ypp"
                                { (yyval.PNode) = (yyvsp[0].FrNode); }
#line 1324 "src/parser.tab.cpp"
    break;

  case 12: /* Sentence: WhileSentence  */
#line 98 "lex-yacc/parser.ypp"
                                { (yyval.PNode) = (yyvsp[0].WNode); }
#line 1330 "src/parser.tab.cpp"
    break;

  case 13: /* Sentence: DoWhileSentence  */
#line 99 "lex-yacc/parser.ypp"
                                { (yyval.PNode) = (yyvsp[0].DWNode); }
#line 1336 "src/parser.tab.cpp"
    break;

  case 14: /* Sentence: PrintSentence  */
#line 100 "lex-yacc/parser.ypp"
                                { (yyval.PNode) = (yyvsp[0].PrNode); }
#line 1342 "src/parser.tab.cpp"
    break;

  case 15: /* PrintSentence: PRINT '(' Operation ')' ';'  */
#line 103 "lex-yacc/parser.ypp"
                                {
        (yyval.PrNode) = new PrintNode((yyvsp[-2].MNode));
    }
#line 1350 "src/parser.tab.cpp"
    break;

  case 16: /* IFSentence: IF '(' Condition ')' Scope  */
#line 108 "lex-yacc/parser.ypp"
                                   { (yyval.FNode) = new IfNode((yyvsp[-2].MNode), (yyvsp[0].SCNode));   }
#line 1356 "src/parser.tab.cpp"
    break;

  case 17: /* IFSentence: IFSentence ELSE IFSentence  */
#line 109 "lex-yacc/parser.ypp"
                                   { (yyval.FNode) = (yyvsp[-2].FNode)->setElse((yyvsp[0].FNode));  }
#line 1362 "src/parser.tab.cpp"
    break;

  case 18: /* IFSentence: IFSentence ELSE Scope  */
#line 110 "lex-yacc/parser.ypp"
                                   { (yyval.FNode) = (yyvsp[-2].FNode)->setElse((yyvsp[0].SCNode));  }
#line 1368 "src/parser.tab.cpp"
    break;

  case 19: /* ForSentence: FOR '(' VariableDeclaration Condition ';' VariableAssignment ')' Scope  */
#line 112 "lex-yacc/parser.ypp"
                                                                                    {
    (yyval.FrNode) = new ForNode((yyvsp[-5].VDNode), (yyvsp[-4].MNode), (yyvsp[-2].VANode), (yyvsp[0].SCNode));
}
#line 1376 "src/parser.tab.cpp"
    break;

  case 20: /* WhileSentence: WHILE '(' Condition ')' Scope  */
#line 116 "lex-yacc/parser.ypp"
                                             {
    (yyval.WNode) = new WhileNode((yyvsp[-2].MNode), (yyvsp[0].SCNode));
}
#line 1384 "src/parser.tab.cpp"
    break;

  case 21: /* DoWhileSentence: DO Scope WHILE '(' Condition ')' ';'  */
#line 120 "lex-yacc/parser.ypp"
                                                      {
    (yyval.DWNode) = new DoWhileNode((yyvsp[-2].MNode), (yyvsp[-5].SCNode));
}
#line 1392 "src/parser.tab.cpp"
    break;

  case 25: /* VariableDeclaration: DATA_TYPE IDENTIFIER ';'  */
#line 129 "lex-yacc/parser.ypp"
                                                    { (yyval.VDNode) = new VariableDefinitionNode((yyvsp[-2].str), (yyvsp[-1].str), nullptr); }
#line 1398 "src/parser.tab.cpp"
    break;

  case 26: /* VariableDeclaration: DATA_TYPE IDENTIFIER '=' Operation ';'  */
#line 130 "lex-yacc/parser.ypp"
                                                    { (yyval.VDNode) = new VariableDefinitionNode((yyvsp[-4].str), (yyvsp[-3].str), (yyvsp[-1].MNode)); }
#line 1404 "src/parser.tab.cpp"
    break;

  case 27: /* VariableAssignment: IDENTIFIER '=' Operation ';'  */
#line 132 "lex-yacc/parser.ypp"
                                                    { (yyval.VANode) = new VariableAssignmentNode((yyvsp[-3].str), (yyvsp[-1].MNode)); }
#line 1410 "src/parser.tab.cpp"
    break;

  case 28: /* Condition: MathOperation OR MathOperation  */
#line 135 "lex-yacc/parser.ypp"
                                                    { (yyval.MNode) = new ExpressionNode((yyvsp[-2].MNode), (yyvsp[0].MNode), OP_OR);  }
#line 1416 "src/parser.tab.cpp"
    break;

  case 29: /* Condition: MathOperation AND MathOperation  */
#line 136 "lex-yacc/parser.ypp"
                                                    { (yyval.MNode) = new ExpressionNode((yyvsp[-2].MNode), (yyvsp[0].MNode), OP_AND); }
#line 1422 "src/parser.tab.cpp"
    break;

  case 30: /* Condition: MathOperation GTE MathOperation  */
#line 137 "lex-yacc/parser.ypp"
                                                    { (yyval.MNode) = new ExpressionNode((yyvsp[-2].MNode), (yyvsp[0].MNode), OP_GE);  }
#line 1428 "src/parser.tab.cpp"
    break;

  case 31: /* Condition: MathOperation GT MathOperation  */
#line 138 "lex-yacc/parser.ypp"
                                                    { (yyval.MNode) = new ExpressionNode((yyvsp[-2].MNode), (yyvsp[0].MNode), OP_GT);  }
#line 1434 "src/parser.tab.cpp"
    break;

  case 32: /* Condition: MathOperation LTE MathOperation  */
#line 139 "lex-yacc/parser.ypp"
                                                    { (yyval.MNode) = new ExpressionNode((yyvsp[-2].MNode), (yyvsp[0].MNode), OP_LE);  }
#line 1440 "src/parser.tab.cpp"
    break;

  case 33: /* Condition: MathOperation LT MathOperation  */
#line 140 "lex-yacc/parser.ypp"
                                                    { (yyval.MNode) = new ExpressionNode((yyvsp[-2].MNode), (yyvsp[0].MNode), OP_LT);  }
#line 1446 "src/parser.tab.cpp"
    break;

  case 34: /* Condition: MathOperation ISEQUAL MathOperation  */
#line 141 "lex-yacc/parser.ypp"
                                                    { (yyval.MNode) = new ExpressionNode((yyvsp[-2].MNode), (yyvsp[0].MNode), OP_EQ);  }
#line 1452 "src/parser.tab.cpp"
    break;

  case 35: /* Condition: MathOperation NOTEQUAL MathOperation  */
#line 142 "lex-yacc/parser.ypp"
                                                    { (yyval.MNode) = new ExpressionNode((yyvsp[-2].MNode), (yyvsp[0].MNode), OP_NEQ); }
#line 1458 "src/parser.tab.cpp"
    break;

  case 36: /* Condition: StringOperation GTE StringOperation  */
#line 144 "lex-yacc/parser.ypp"
                                                    { (yyval.MNode) = new StringNode((yyvsp[-2].SNode), (yyvsp[0].SNode), OP_GE);   }
#line 1464 "src/parser.tab.cpp"
    break;

  case 37: /* Condition: StringOperation GT StringOperation  */
#line 145 "lex-yacc/parser.ypp"
                                                    { (yyval.MNode) = new StringNode((yyvsp[-2].SNode), (yyvsp[0].SNode), OP_GT);   }
#line 1470 "src/parser.tab.cpp"
    break;

  case 38: /* Condition: StringOperation LTE StringOperation  */
#line 146 "lex-yacc/parser.ypp"
                                                    { (yyval.MNode) = new StringNode((yyvsp[-2].SNode), (yyvsp[0].SNode), OP_LE);   }
#line 1476 "src/parser.tab.cpp"
    break;

  case 39: /* Condition: StringOperation LT StringOperation  */
#line 147 "lex-yacc/parser.ypp"
                                                    { (yyval.MNode) = new StringNode((yyvsp[-2].SNode), (yyvsp[0].SNode), OP_LT);   }
#line 1482 "src/parser.tab.cpp"
    break;

  case 40: /* Condition: StringOperation ISEQUAL StringOperation  */
#line 148 "lex-yacc/parser.ypp"
                                                    { (yyval.MNode) = new StringNode((yyvsp[-2].SNode), (yyvsp[0].SNode), OP_EQ);   }
#line 1488 "src/parser.tab.cpp"
    break;

  case 41: /* Condition: StringOperation NOTEQUAL StringOperation  */
#line 149 "lex-yacc/parser.ypp"
                                                    { (yyval.MNode) = new StringNode((yyvsp[-2].SNode), (yyvsp[0].SNode), OP_NEQ);  }
#line 1494 "src/parser.tab.cpp"
    break;

  case 42: /* Condition: MathOperation  */
#line 151 "lex-yacc/parser.ypp"
                                                    { (yyval.MNode) = (yyvsp[0].MNode); }
#line 1500 "src/parser.tab.cpp"
    break;

  case 43: /* Condition: StringOperation  */
#line 152 "lex-yacc/parser.ypp"
                                                    { (yyval.MNode) = (yyvsp[0].SNode); }
#line 1506 "src/parser.tab.cpp"
    break;

  case 44: /* Operation: MathOperation  */
#line 155 "lex-yacc/parser.ypp"
                                                    { (yyval.MNode) = (yyvsp[0].MNode); /*std::cout << $1->getValue() << std::endl;*/ }
#line 1512 "src/parser.tab.cpp"
    break;

  case 45: /* Operation: StringOperation  */
#line 156 "lex-yacc/parser.ypp"
                                                    { (yyval.MNode) = (yyvsp[0].SNode); /*std::cout << $1->getValue() << std::endl;*/ }
#line 1518 "src/parser.tab.cpp"
    break;

  case 46: /* MathOperation: MathOperation '+' MathOperation  */
#line 159 "lex-yacc/parser.ypp"
                                                    { (yyval.MNode) = new ExpressionNode((yyvsp[-2].MNode), (yyvsp[0].MNode), OP_ADD); }
#line 1524 "src/parser.tab.cpp"
    break;

  case 47: /* MathOperation: MathOperation '-' MathOperation  */
#line 160 "lex-yacc/parser.ypp"
                                                    { (yyval.MNode) = new ExpressionNode((yyvsp[-2].MNode), (yyvsp[0].MNode), OP_SUB); }
#line 1530 "src/parser.tab.cpp"
    break;

  case 48: /* MathOperation: MathOperation '*' MathOperation  */
#line 161 "lex-yacc/parser.ypp"
                                                    { (yyval.MNode) = new ExpressionNode((yyvsp[-2].MNode), (yyvsp[0].MNode), OP_MUL); }
#line 1536 "src/parser.tab.cpp"
    break;

  case 49: /* MathOperation: MathOperation '/' MathOperation  */
#line 162 "lex-yacc/parser.ypp"
                                                    { (yyval.MNode) = new ExpressionNode((yyvsp[-2].MNode), (yyvsp[0].MNode), OP_DIV); }
#line 1542 "src/parser.tab.cpp"
    break;

  case 50: /* MathOperation: MathOperation '%' MathOperation  */
#line 163 "lex-yacc/parser.ypp"
                                                    { (yyval.MNode) = new ExpressionNode((yyvsp[-2].MNode), (yyvsp[0].MNode), OP_MOD); }
#line 1548 "src/parser.tab.cpp"
    break;

  case 51: /* MathOperation: '(' MathOperation ')' MathOperation  */
#line 164 "lex-yacc/parser.ypp"
                                                    { (yyval.MNode) = new ExpressionNode((yyvsp[-2].MNode), (yyvsp[0].MNode), OP_MUL); }
#line 1554 "src/parser.tab.cpp"
    break;

  case 52: /* MathOperation: '(' MathOperation ')'  */
#line 165 "lex-yacc/parser.ypp"
                                                    {                   (yyval.MNode) = (yyvsp[-1].MNode);               }
#line 1560 "src/parser.tab.cpp"
    break;

  case 53: /* MathOperation: POW '(' MathOperation ',' MathOperation ')'  */
#line 166 "lex-yacc/parser.ypp"
                                                    { (yyval.MNode) = new ExpressionNode((yyvsp[-3].MNode), (yyvsp[-1].MNode), OP_POW);  }
#line 1566 "src/parser.tab.cpp"
    break;

  case 54: /* MathOperation: SQRT '(' MathOperation ')'  */
#line 167 "lex-yacc/parser.ypp"
                                                    { (yyval.MNode) = new ExpressionNode((yyvsp[-1].MNode), (yyvsp[-1].MNode), OP_SQRT); }
#line 1572 "src/parser.tab.cpp"
    break;

  case 55: /* MathOperation: MathOperation SHL MathOperation  */
#line 168 "lex-yacc/parser.ypp"
                                                    { (yyval.MNode) = new ExpressionNode((yyvsp[-2].MNode), (yyvsp[0].MNode), OP_SHL); }
#line 1578 "src/parser.tab.cpp"
    break;

  case 56: /* MathOperation: MathOperation SHR MathOperation  */
#line 169 "lex-yacc/parser.ypp"
                                                    { (yyval.MNode) = new ExpressionNode((yyvsp[-2].MNode), (yyvsp[0].MNode), OP_SHR); }
#line 1584 "src/parser.tab.cpp"
    break;

  case 57: /* MathOperation: MathOperation '|' MathOperation  */
#line 170 "lex-yacc/parser.ypp"
                                                    { (yyval.MNode) = new ExpressionNode((yyvsp[-2].MNode), (yyvsp[0].MNode), OP_OR); }
#line 1590 "src/parser.tab.cpp"
    break;

  case 58: /* MathOperation: MathOperation '&' MathOperation  */
#line 171 "lex-yacc/parser.ypp"
                                                    { (yyval.MNode) = new ExpressionNode((yyvsp[-2].MNode), (yyvsp[0].MNode), OP_AND); }
#line 1596 "src/parser.tab.cpp"
    break;

  case 59: /* MathOperation: MathOperation '^' MathOperation  */
#line 172 "lex-yacc/parser.ypp"
                                                    { (yyval.MNode) = new ExpressionNode((yyvsp[-2].MNode), (yyvsp[0].MNode), OP_XOR); }
#line 1602 "src/parser.tab.cpp"
    break;

  case 61: /* StringOperation: StringOperation '+' StringOperation  */
#line 176 "lex-yacc/parser.ypp"
                                                        { (yyval.SNode) =  new StringNode((yyvsp[-2].SNode), (yyvsp[0].SNode), OP_ADD); }
#line 1608 "src/parser.tab.cpp"
    break;

  case 62: /* StringOperation: StringOperation '+' MathOperation  */
#line 177 "lex-yacc/parser.ypp"
                                                        { (yyval.SNode) =  new StringNode((yyvsp[-2].SNode), (yyvsp[0].MNode), OP_ADD); }
#line 1614 "src/parser.tab.cpp"
    break;

  case 63: /* StringOperation: StringOperation '-' MathOperation  */
#line 178 "lex-yacc/parser.ypp"
                                                        { (yyval.SNode) =  new StringNode((yyvsp[-2].SNode), (yyvsp[0].MNode), OP_SUB); }
#line 1620 "src/parser.tab.cpp"
    break;

  case 64: /* StringOperation: '(' StringOperation ')'  */
#line 179 "lex-yacc/parser.ypp"
                                                        { (yyval.SNode) =  (yyvsp[-1].SNode); }
#line 1626 "src/parser.tab.cpp"
    break;

  case 65: /* StringOperation: StringOperation SHL StringOperation  */
#line 181 "lex-yacc/parser.ypp"
                                                            { (yyval.SNode) =  new StringNode((yyvsp[-2].SNode), (yyvsp[0].SNode), OP_SHL); }
#line 1632 "src/parser.tab.cpp"
    break;

  case 66: /* StringOperation: StringOperation SHR StringOperation  */
#line 182 "lex-yacc/parser.ypp"
                                                            { (yyval.SNode) =  new StringNode((yyvsp[-2].SNode), (yyvsp[0].SNode), OP_SHR); }
#line 1638 "src/parser.tab.cpp"
    break;

  case 68: /* MathOperand: INTEGER  */
#line 186 "lex-yacc/parser.ypp"
                        { (yyval.MNode) = new ExpressionNode((yyvsp[0].str), TINT);}
#line 1644 "src/parser.tab.cpp"
    break;

  case 69: /* MathOperand: FLOAT  */
#line 188 "lex-yacc/parser.ypp"
                        { (yyval.MNode) = new ExpressionNode((yyvsp[0].str), TFLOAT);}
#line 1650 "src/parser.tab.cpp"
    break;

  case 70: /* MathOperand: CHARACTER  */
#line 190 "lex-yacc/parser.ypp"
                        { (yyval.MNode) = new ExpressionNode((yyvsp[0].str), TCHAR);}
#line 1656 "src/parser.tab.cpp"
    break;

  case 71: /* MathOperand: BOOLEAN  */
#line 192 "lex-yacc/parser.ypp"
                        { (yyval.MNode) = new ExpressionNode((yyvsp[0].str), TBOOLEAN);}
#line 1662 "src/parser.tab.cpp"
    break;

  case 72: /* MathOperand: IDENTIFIER  */
#line 194 "lex-yacc/parser.ypp"
                        { (yyval.MNode) = new IdentifierNode((yyvsp[0].str)); }
#line 1668 "src/parser.tab.cpp"
    break;

  case 73: /* StringOperand: STRING  */
#line 196 "lex-yacc/parser.ypp"
                        { (yyval.SNode) = new StringNode((yyvsp[0].str)); }
#line 1674 "src/parser.tab.cpp"
    break;


#line 1678 "src/parser.tab.cpp"

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

#line 198 "lex-yacc/parser.ypp"



int main() {
    ScopeNode* x = new ScopeNode();
    yyin = fopen("test.yapl", "r");
    yyparse();
    return 0;
}
