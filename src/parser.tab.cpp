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
    #include "organizer.hpp"

    #include "parser.tab.hpp"
    extern int yylex();
    extern FILE *yyin;   

    int lineNumber = 1;
    int scopeDepth = 0;
    int quadruplesLabel = 0;
    std::vector<int> breakJumpTo;
    std::vector<int> continueJumpTo;
    std::vector<int> returnJumpTo;

    void yyerror(const char* s) {
        std::cerr << "Error: " << s << std::endl;
        std::cerr << "Line: " << lineNumber << std::endl;
    }
    CompilerState CompilerOrganizer::state = VALIDATING;
    std::vector<ErrorDetail> CompilerOrganizer::errors;
    std::vector<SymbolTableEntry> CompilerOrganizer::symbolTable;
    std::vector<QuadrupleEntry> CompilerOrganizer::quadruples;

    int QuadrupleEntry::index = 1;

#line 110 "src/parser.tab.cpp"

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
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_FOR = 5,                        /* FOR  */
  YYSYMBOL_WHILE = 6,                      /* WHILE  */
  YYSYMBOL_DO = 7,                         /* DO  */
  YYSYMBOL_SWITCH = 8,                     /* SWITCH  */
  YYSYMBOL_CASE = 9,                       /* CASE  */
  YYSYMBOL_DEFAULT = 10,                   /* DEFAULT  */
  YYSYMBOL_CONTINUE = 11,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 12,                     /* BREAK  */
  YYSYMBOL_RETURN = 13,                    /* RETURN  */
  YYSYMBOL_PRINT = 14,                     /* PRINT  */
  YYSYMBOL_DATA_TYPE = 15,                 /* DATA_TYPE  */
  YYSYMBOL_IDENTIFIER = 16,                /* IDENTIFIER  */
  YYSYMBOL_INTEGER = 17,                   /* INTEGER  */
  YYSYMBOL_BOOLEAN = 18,                   /* BOOLEAN  */
  YYSYMBOL_FLOAT = 19,                     /* FLOAT  */
  YYSYMBOL_CONST = 20,                     /* CONST  */
  YYSYMBOL_STRING = 21,                    /* STRING  */
  YYSYMBOL_POW = 22,                       /* POW  */
  YYSYMBOL_SQRT = 23,                      /* SQRT  */
  YYSYMBOL_SHL = 24,                       /* SHL  */
  YYSYMBOL_SHR = 25,                       /* SHR  */
  YYSYMBOL_AND = 26,                       /* AND  */
  YYSYMBOL_OR = 27,                        /* OR  */
  YYSYMBOL_GTE = 28,                       /* GTE  */
  YYSYMBOL_LTE = 29,                       /* LTE  */
  YYSYMBOL_LT = 30,                        /* LT  */
  YYSYMBOL_GT = 31,                        /* GT  */
  YYSYMBOL_ISEQUAL = 32,                   /* ISEQUAL  */
  YYSYMBOL_NOTEQUAL = 33,                  /* NOTEQUAL  */
  YYSYMBOL_CHARACTER = 34,                 /* CHARACTER  */
  YYSYMBOL_INCREMENT = 35,                 /* INCREMENT  */
  YYSYMBOL_DECREMENT = 36,                 /* DECREMENT  */
  YYSYMBOL_PLUS_EQUAL = 37,                /* PLUS_EQUAL  */
  YYSYMBOL_MINUS_EQUAL = 38,               /* MINUS_EQUAL  */
  YYSYMBOL_DIV_EQUAL = 39,                 /* DIV_EQUAL  */
  YYSYMBOL_MOD_EQUAL = 40,                 /* MOD_EQUAL  */
  YYSYMBOL_AND_EQUAL = 41,                 /* AND_EQUAL  */
  YYSYMBOL_OR_EQUAL = 42,                  /* OR_EQUAL  */
  YYSYMBOL_XOR_EQUAL = 43,                 /* XOR_EQUAL  */
  YYSYMBOL_MUL_EQUAL = 44,                 /* MUL_EQUAL  */
  YYSYMBOL_SCOPE_BEGIN = 45,               /* SCOPE_BEGIN  */
  YYSYMBOL_SCOPE_END = 46,                 /* SCOPE_END  */
  YYSYMBOL_47_ = 47,                       /* ','  */
  YYSYMBOL_48_ = 48,                       /* '='  */
  YYSYMBOL_49_ = 49,                       /* '|'  */
  YYSYMBOL_50_ = 50,                       /* '^'  */
  YYSYMBOL_51_ = 51,                       /* '&'  */
  YYSYMBOL_52_ = 52,                       /* '+'  */
  YYSYMBOL_53_ = 53,                       /* '-'  */
  YYSYMBOL_54_ = 54,                       /* '*'  */
  YYSYMBOL_55_ = 55,                       /* '/'  */
  YYSYMBOL_56_ = 56,                       /* '%'  */
  YYSYMBOL_57_ = 57,                       /* '('  */
  YYSYMBOL_58_ = 58,                       /* ')'  */
  YYSYMBOL_59_ = 59,                       /* '['  */
  YYSYMBOL_60_ = 60,                       /* ']'  */
  YYSYMBOL_61_ = 61,                       /* '!'  */
  YYSYMBOL_62_ = 62,                       /* '~'  */
  YYSYMBOL_63_ = 63,                       /* ';'  */
  YYSYMBOL_64_ = 64,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 65,                  /* $accept  */
  YYSYMBOL_Program = 66,                   /* Program  */
  YYSYMBOL_Sentences = 67,                 /* Sentences  */
  YYSYMBOL_Scope = 68,                     /* Scope  */
  YYSYMBOL_Sentence = 69,                  /* Sentence  */
  YYSYMBOL_VariableAssignment = 70,        /* VariableAssignment  */
  YYSYMBOL_SwitchSentence = 71,            /* SwitchSentence  */
  YYSYMBOL_SwitchBody = 72,                /* SwitchBody  */
  YYSYMBOL_Case = 73,                      /* Case  */
  YYSYMBOL_ReturnSentence = 74,            /* ReturnSentence  */
  YYSYMBOL_PrintSentence = 75,             /* PrintSentence  */
  YYSYMBOL_IFSentence = 76,                /* IFSentence  */
  YYSYMBOL_IfExtension = 77,               /* IfExtension  */
  YYSYMBOL_ForSentence = 78,               /* ForSentence  */
  YYSYMBOL_ForCondition = 79,              /* ForCondition  */
  YYSYMBOL_ForPostSentence = 80,           /* ForPostSentence  */
  YYSYMBOL_WhileSentence = 81,             /* WhileSentence  */
  YYSYMBOL_DoWhileSentence = 82,           /* DoWhileSentence  */
  YYSYMBOL_LoopScope = 83,                 /* LoopScope  */
  YYSYMBOL_FunctionDefinition = 84,        /* FunctionDefinition  */
  YYSYMBOL_FunctionParams = 85,            /* FunctionParams  */
  YYSYMBOL_FunctionDefaulValueParams = 86, /* FunctionDefaulValueParams  */
  YYSYMBOL_VariableDeclaration = 87,       /* VariableDeclaration  */
  YYSYMBOL_Condition = 88,                 /* Condition  */
  YYSYMBOL_Operation = 89,                 /* Operation  */
  YYSYMBOL_FunctionCall = 90,              /* FunctionCall  */
  YYSYMBOL_FunctionCallParams = 91,        /* FunctionCallParams  */
  YYSYMBOL_MathOperation = 92,             /* MathOperation  */
  YYSYMBOL_StringOperation = 93,           /* StringOperation  */
  YYSYMBOL_Operand = 94,                   /* Operand  */
  YYSYMBOL_FunctionParamOperand = 95,      /* FunctionParamOperand  */
  YYSYMBOL_MathOperand = 96,               /* MathOperand  */
  YYSYMBOL_StringOperand = 97,             /* StringOperand  */
  YYSYMBOL_Type = 98                       /* Type  */
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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  84
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   914

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  137
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  299

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   301


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
       2,     2,     2,    61,     2,     2,     2,    56,    51,     2,
      57,    58,    54,    52,    47,    53,     2,    55,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    64,    63,
       2,    48,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    59,     2,    60,    50,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    49,     2,    62,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    95,    95,   119,   121,   123,   126,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   144,
     146,   150,   156,   162,   168,   174,   180,   186,   192,   201,
     202,   205,   208,   213,   214,   217,   218,   221,   224,   225,
     226,   228,   229,   230,   234,   235,   237,   240,   244,   244,
     247,   248,   249,   251,   255,   259,   263,   266,   269,   274,
     274,   277,   282,   283,   284,   285,   288,   289,   290,   291,
     294,   295,   296,   297,   298,   301,   302,   303,   305,   306,
     307,   308,   309,   310,   312,   313,   314,   315,   316,   317,
     319,   325,   326,   329,   330,   333,   334,   337,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   361,
     362,   363,   364,   365,   366,   367,   368,   370,   370,   373,
     375,   377,   379,   382,   384,   386,   389,   390
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
  "\"end of file\"", "error", "\"invalid token\"", "IF", "ELSE", "FOR",
  "WHILE", "DO", "SWITCH", "CASE", "DEFAULT", "CONTINUE", "BREAK",
  "RETURN", "PRINT", "DATA_TYPE", "IDENTIFIER", "INTEGER", "BOOLEAN",
  "FLOAT", "CONST", "STRING", "POW", "SQRT", "SHL", "SHR", "AND", "OR",
  "GTE", "LTE", "LT", "GT", "ISEQUAL", "NOTEQUAL", "CHARACTER",
  "INCREMENT", "DECREMENT", "PLUS_EQUAL", "MINUS_EQUAL", "DIV_EQUAL",
  "MOD_EQUAL", "AND_EQUAL", "OR_EQUAL", "XOR_EQUAL", "MUL_EQUAL",
  "SCOPE_BEGIN", "SCOPE_END", "','", "'='", "'|'", "'^'", "'&'", "'+'",
  "'-'", "'*'", "'/'", "'%'", "'('", "')'", "'['", "']'", "'!'", "'~'",
  "';'", "':'", "$accept", "Program", "Sentences", "Scope", "Sentence",
  "VariableAssignment", "SwitchSentence", "SwitchBody", "Case",
  "ReturnSentence", "PrintSentence", "IFSentence", "IfExtension",
  "ForSentence", "ForCondition", "ForPostSentence", "WhileSentence",
  "DoWhileSentence", "LoopScope", "FunctionDefinition", "FunctionParams",
  "FunctionDefaulValueParams", "VariableDeclaration", "Condition",
  "Operation", "FunctionCall", "FunctionCallParams", "MathOperation",
  "StringOperation", "Operand", "FunctionParamOperand", "MathOperand",
  "StringOperand", "Type", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-239)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-75)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     376,   -51,   -28,   -24,   535,   -20,   -16,    10,    65,   -18,
    -239,   857,  -239,  -239,  -239,    44,  -239,    18,    20,  -239,
      73,    86,   482,   173,   704,   173,   117,  -239,   429,   429,
      57,  -239,  -239,  -239,  -239,  -239,  -239,  -239,  -239,   -31,
    -239,  -239,   406,    99,  -239,  -239,  -239,   115,   543,   292,
     590,  -239,  -239,   128,   138,  -239,  -239,   -12,  -239,    93,
     704,  -239,  -239,   704,   704,   704,   704,   704,   704,   704,
     704,   704,   600,  -239,   173,   173,  -239,  -239,   131,   173,
     105,   734,    54,  -239,  -239,  -239,  -239,  -239,   170,  -239,
     173,   173,   173,   173,   173,   704,   173,   173,   173,   173,
     704,   704,   704,   173,   -23,   647,   647,   129,    -8,   835,
     111,   130,   -19,   186,   647,   145,    16,   147,   152,  -239,
     154,  -239,  -239,  -239,  -239,  -239,  -239,  -239,  -239,  -239,
    -239,  -239,    58,   353,   757,  -239,   769,   173,   239,  -239,
     165,   286,   286,   577,   280,   827,   105,  -239,   105,  -239,
    -239,  -239,   406,   -26,   -26,   125,  -239,   125,   704,    36,
     647,    22,   747,   804,    27,   160,     1,   647,   647,     1,
     173,   173,   173,   173,   173,   173,   704,   704,   704,   704,
     704,   704,   647,   647,   171,   163,   535,   535,   657,   177,
     161,   704,  -239,   173,  -239,   105,  -239,   704,  -239,   174,
     212,   835,   111,  -239,     1,   225,  -239,  -239,    27,    27,
     227,  -239,   459,   459,   459,   459,   459,   459,    99,    99,
      99,    99,    99,    99,   181,    27,   182,   535,  -239,  -239,
     647,   178,    71,    12,  -239,  -239,   792,  -239,   198,   190,
     242,  -239,     1,     1,   712,   712,  -239,   191,   187,   188,
     303,   195,  -239,    26,   429,  -239,  -239,    36,     1,  -239,
    -239,  -239,  -239,    61,    63,   189,  -239,  -239,  -239,   196,
    -239,  -239,  -239,  -239,   429,  -239,  -239,  -239,   247,  -239,
     712,   535,   535,  -239,  -239,  -239,    90,  -239,  -239,  -239,
     180,   217,   218,    36,    36,  -239,   252,  -239,   221
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      74,     0,     0,     0,    74,     0,     0,     0,     0,     0,
     137,   134,   129,   132,   130,     0,   135,     0,     0,   131,
       0,     0,    74,     0,     0,     0,     0,     2,     5,     5,
       0,    16,    15,    14,    10,    11,    12,    13,     9,     0,
      20,   118,    91,    92,   133,   117,   126,     0,     0,    74,
       0,    59,    60,     0,     0,    17,    18,   134,    36,     0,
       0,   112,   115,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   136,     0,     0,   113,   114,     0,     0,
     116,     0,     0,   111,     1,     4,     3,     7,     0,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    70,     0,     0,     0,     0,    91,
      92,     0,     0,     0,     0,     0,     0,     0,     0,    35,
       0,    21,    22,    24,    25,    26,    27,    28,    23,    19,
      94,    96,     0,     0,     0,     6,     0,     0,   103,   123,
      72,   106,   107,   108,   110,   109,    97,   122,    98,    99,
     100,   101,     0,   124,   125,   120,   119,   121,     0,    65,
       0,     0,     0,     0,    77,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    49,    49,    70,     0,    74,    74,     0,     0,
       0,     0,    93,     0,   105,    97,   102,     0,    71,     0,
       0,     0,     0,    90,     0,    45,    44,    39,    76,    75,
      45,    38,    78,    80,    81,    79,    82,    83,    84,    86,
      87,    85,    88,    89,     0,    48,     0,    74,    54,    53,
       0,     0,     0,     0,    37,    95,     0,    73,     0,    64,
      45,    40,     0,     0,    52,    52,    55,     0,     0,     0,
       0,     0,    30,     0,     5,   104,    61,    65,     0,    45,
      42,    41,    50,     0,     0,     0,    57,    56,   134,     0,
     127,   128,    34,    29,     5,    31,    62,    63,     0,    43,
       0,    74,    74,    58,    33,    32,    64,    51,    47,    46,
       0,    68,    69,     0,     0,    66,     0,    67,     0
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -239,  -239,   -21,    -4,    -2,   -39,  -239,  -239,    17,  -239,
    -239,  -149,  -128,  -239,    89,    31,  -239,  -239,  -156,  -239,
      24,  -148,   250,   -35,    -3,  -239,  -239,   192,   -10,  -239,
      13,    50,  -238,   -46
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    26,    27,    28,    29,    30,    31,   253,   254,    32,
      33,    34,   207,    35,   224,   263,    36,    37,    53,    38,
     199,   277,    39,   164,    40,    41,   132,    42,    43,   269,
      44,    45,    46,    47
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      51,    78,    52,   113,     1,    59,    48,    85,    86,   107,
     111,   115,   271,   108,    82,   116,    88,   206,   167,   168,
     206,   250,   251,    61,    62,   158,   102,   103,    88,    49,
     228,   229,    89,    50,   159,   250,   251,    54,   110,    60,
     110,   211,   167,   168,   183,    72,    22,    55,   167,   168,
     169,    10,   292,   167,   168,   206,    15,   120,   252,    73,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   131,
     161,   246,   273,    56,   187,    74,   241,    75,   100,   101,
     203,    57,    12,    13,    14,   147,    16,    17,    18,    76,
     153,   154,   156,   206,   206,   163,   110,   167,   168,    19,
      20,    21,    77,   165,   110,   191,   102,   103,   280,   206,
     280,   185,   139,   200,   260,   261,   192,    84,    23,   281,
      87,   282,    24,   100,   101,   288,   289,    25,    58,   249,
     279,   104,   208,   209,   117,   100,   101,   257,   290,   176,
     177,   178,   179,   180,   181,   295,   297,   225,   225,   231,
     202,   102,   103,   232,   118,   198,   119,   202,   202,    97,
      98,    99,   205,   102,   103,   210,   218,   219,   220,   221,
     222,   223,   202,   202,    92,    93,    94,   135,   110,    97,
      98,    99,    51,    51,    52,    52,   140,   166,   235,    57,
      12,    13,    14,   182,   237,    17,    18,    12,    13,    14,
     240,    16,   184,   186,   188,   262,   262,    19,    20,    21,
     189,   278,   190,   197,    19,    80,    81,    83,   204,   158,
     110,   227,   233,    51,   234,    52,    23,   247,   239,   242,
      79,   243,   238,   275,   256,    25,   248,   257,   259,   259,
     109,   287,   109,    22,   244,   245,   258,   296,   296,   265,
     266,   267,   283,   285,   259,    57,    12,    13,    14,   272,
     284,    17,    18,   286,   293,   294,   133,   134,   298,   290,
     274,   136,   226,    19,    20,    21,   264,    51,    51,    52,
      52,   276,   141,   142,   143,   144,   145,   146,   148,   149,
     150,   151,   152,   152,   155,   157,    79,   162,   109,   112,
     270,    25,     0,   291,    90,    91,   109,    10,    11,    12,
      13,    14,    15,    16,    17,    18,     0,     0,     0,   268,
      12,    13,    14,     0,    16,     0,    19,    20,    21,   195,
     196,    94,   137,    96,    97,    98,    99,    19,   137,    96,
      97,    98,    99,     0,     0,    23,     0,     0,     0,    24,
       0,     0,   201,     0,    25,     0,     0,     0,     0,   201,
     201,     0,   212,   213,   214,   215,   216,   217,   152,   152,
     152,   152,   152,   152,   201,   201,    -5,    90,    91,     1,
     109,     2,     3,     4,     5,   236,     0,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
     193,     0,    92,    93,    94,   137,    96,    97,    98,    99,
      19,    20,    21,     0,     0,     0,     0,     0,     0,     0,
       0,    22,   109,     0,     0,     0,     0,     0,     0,    23,
      90,    91,     1,    24,     2,     3,     4,     5,    25,     0,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,     0,     0,    92,    93,    94,    95,    96,
      97,    98,    99,    19,    20,    21,     0,     0,     0,     0,
       0,     0,     0,     0,    22,     0,   -74,     0,     0,     0,
       0,     0,    23,    90,    91,     1,    24,     2,     3,     4,
       5,    25,   -74,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,     0,     0,    92,    93,
      94,   137,    96,    97,    98,    99,    19,    20,    21,     0,
       0,     0,     0,     0,     0,     0,     0,    22,    -5,     0,
       0,     0,     0,     0,     0,    23,     0,     0,     1,    24,
       2,     3,     4,     5,    25,     0,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    11,
      12,    13,    14,     0,    16,    17,    18,     0,     0,    19,
      20,    21,     0,     0,     0,     0,     0,    19,    20,    21,
      22,     0,     0,     0,     0,     0,     0,     0,    23,     0,
       0,     0,    24,     0,     0,     0,    23,    25,     0,     0,
     105,    90,    91,     0,   106,    25,    11,    12,    13,    14,
       0,    16,    17,    18,     0,     0,    57,    12,    13,    14,
       0,    16,    17,    18,    19,    20,    21,    93,    94,   137,
      96,    97,    98,    99,    19,    20,    21,     0,     0,     0,
       0,     0,     0,    23,     0,     0,     0,   105,     0,     0,
       0,   114,    25,    23,     0,     0,     0,    24,   130,     0,
       0,     0,    25,    57,    12,    13,    14,     0,    16,    17,
      18,     0,     0,    11,    12,    13,    14,     0,    16,    17,
      18,    19,    20,    21,     0,     0,     0,     0,     0,     0,
       0,    19,    20,    21,     0,     0,     0,     0,     0,     0,
      23,     0,     0,     0,   105,     0,     0,     0,   160,    25,
      23,     0,     0,     0,   105,     0,     0,     0,   230,    25,
      57,    12,    13,    14,     0,    16,    17,    18,    11,    12,
      13,    14,     0,    16,    17,    18,     0,     0,    19,    20,
      21,     0,     0,     0,     0,     0,    19,    20,    21,     0,
       0,     0,     0,     0,     0,     0,     0,    23,    90,    91,
       0,    24,     0,     0,     0,    23,    25,     0,     0,    24,
       0,    90,    91,     0,    25,   170,   171,   172,   173,   174,
     175,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,     0,   138,    90,    91,     0,    92,    93,    94,    95,
      96,    97,    98,    99,     0,   138,    92,    93,    94,   137,
      96,    97,    98,    99,     0,   194,    90,    91,    92,    93,
      94,   137,    96,    97,    98,    99,     0,   138,   100,   101,
       0,     0,   176,   177,   178,   179,   180,   181,     0,     0,
       0,    92,    93,    94,   137,    96,    97,    98,    99,     0,
     255,    90,    91,     0,     0,     0,   102,   103,     0,    90,
      91,     0,   139,   170,   171,   172,   173,   174,   175,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   137,
      96,    97,    98,    99,    92,    93,    94,    95,    96,    97,
      98,    99,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,     0,     0,     0,    71,     0,     0,     0,     0,
       0,     0,     0,     0,    72
};

static const yytype_int16 yycheck[] =
{
       4,    22,     4,    49,     3,     8,    57,    28,    29,    48,
      49,    50,   250,    48,    24,    50,    47,   166,    26,    27,
     169,     9,    10,    35,    36,    48,    52,    53,    47,    57,
     186,   187,    63,    57,    57,     9,    10,    57,    48,    57,
      50,   169,    26,    27,    63,    57,    45,    63,    26,    27,
      58,    15,   290,    26,    27,   204,    20,    60,    46,    15,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
     105,   227,    46,    63,    58,    57,   204,    57,    24,    25,
      58,    16,    17,    18,    19,    95,    21,    22,    23,    16,
     100,   101,   102,   242,   243,   105,   106,    26,    27,    34,
      35,    36,    16,   106,   114,    47,    52,    53,    47,   258,
      47,   114,    58,   159,   242,   243,    58,     0,    53,    58,
      63,    58,    57,    24,    25,   281,   282,    62,    63,    58,
     258,    16,   167,   168,     6,    24,    25,    47,    48,    28,
      29,    30,    31,    32,    33,   293,   294,   182,   183,   188,
     160,    52,    53,   188,    16,   158,    63,   167,   168,    54,
      55,    56,   166,    52,    53,   169,   176,   177,   178,   179,
     180,   181,   182,   183,    49,    50,    51,    46,   188,    54,
      55,    56,   186,   187,   186,   187,    16,    58,   191,    16,
      17,    18,    19,    63,   197,    22,    23,    17,    18,    19,
     204,    21,    16,    58,    57,   244,   245,    34,    35,    36,
      58,   257,    58,    48,    34,    23,    24,    25,    58,    48,
     230,    58,    45,   227,    63,   227,    53,   230,    16,     4,
      57,     4,    58,   254,   238,    62,    58,    47,   242,   243,
      48,   280,    50,    45,    63,    63,     4,   293,   294,    58,
      63,    63,    63,   274,   258,    16,    17,    18,    19,    64,
      64,    22,    23,    16,    47,    47,    74,    75,    16,    48,
     253,    79,   183,    34,    35,    36,   245,   281,   282,   281,
     282,   257,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,    57,   105,   106,    49,
     250,    62,    -1,   290,    24,    25,   114,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    -1,    -1,    16,
      17,    18,    19,    -1,    21,    -1,    34,    35,    36,   137,
     138,    51,    52,    53,    54,    55,    56,    34,    52,    53,
      54,    55,    56,    -1,    -1,    53,    -1,    -1,    -1,    57,
      -1,    -1,   160,    -1,    62,    -1,    -1,    -1,    -1,   167,
     168,    -1,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,     0,    24,    25,     3,
     188,     5,     6,     7,     8,   193,    -1,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      47,    -1,    49,    50,    51,    52,    53,    54,    55,    56,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,   230,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      24,    25,     3,    57,     5,     6,     7,     8,    62,    -1,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    -1,    47,    -1,    -1,    -1,
      -1,    -1,    53,    24,    25,     3,    57,     5,     6,     7,
       8,    62,    63,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,     3,    57,
       5,     6,     7,     8,    62,    -1,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    16,
      17,    18,    19,    -1,    21,    22,    23,    -1,    -1,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,    34,    35,    36,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    57,    -1,    -1,    -1,    53,    62,    -1,    -1,
      57,    24,    25,    -1,    61,    62,    16,    17,    18,    19,
      -1,    21,    22,    23,    -1,    -1,    16,    17,    18,    19,
      -1,    21,    22,    23,    34,    35,    36,    50,    51,    52,
      53,    54,    55,    56,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    -1,    -1,    -1,    57,    -1,    -1,
      -1,    61,    62,    53,    -1,    -1,    -1,    57,    58,    -1,
      -1,    -1,    62,    16,    17,    18,    19,    -1,    21,    22,
      23,    -1,    -1,    16,    17,    18,    19,    -1,    21,    22,
      23,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    57,    -1,    -1,    -1,    61,    62,
      53,    -1,    -1,    -1,    57,    -1,    -1,    -1,    61,    62,
      16,    17,    18,    19,    -1,    21,    22,    23,    16,    17,
      18,    19,    -1,    21,    22,    23,    -1,    -1,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    24,    25,
      -1,    57,    -1,    -1,    -1,    53,    62,    -1,    -1,    57,
      -1,    24,    25,    -1,    62,    28,    29,    30,    31,    32,
      33,    24,    25,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    58,    24,    25,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    58,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    58,    24,    25,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    58,    24,    25,
      -1,    -1,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      58,    24,    25,    -1,    -1,    -1,    52,    53,    -1,    24,
      25,    -1,    58,    28,    29,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      53,    54,    55,    56,    49,    50,    51,    52,    53,    54,
      55,    56,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    57
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     5,     6,     7,     8,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    34,
      35,    36,    45,    53,    57,    62,    66,    67,    68,    69,
      70,    71,    74,    75,    76,    78,    81,    82,    84,    87,
      89,    90,    92,    93,    95,    96,    97,    98,    57,    57,
      57,    68,    69,    83,    57,    63,    63,    16,    63,    89,
      57,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    48,    57,    15,    57,    57,    16,    16,    67,    57,
      92,    92,    93,    92,     0,    67,    67,    63,    47,    63,
      24,    25,    49,    50,    51,    52,    53,    54,    55,    56,
      24,    25,    52,    53,    16,    57,    61,    70,    88,    92,
      93,    70,    87,    98,    61,    70,    88,     6,    16,    63,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      58,    89,    91,    92,    92,    46,    92,    52,    58,    58,
      16,    92,    92,    92,    92,    92,    92,    93,    92,    92,
      92,    92,    92,    93,    93,    92,    93,    92,    48,    57,
      61,    88,    92,    93,    88,    89,    58,    26,    27,    58,
      28,    29,    30,    31,    32,    33,    28,    29,    30,    31,
      32,    33,    63,    63,    16,    89,    58,    58,    57,    58,
      58,    47,    58,    47,    58,    92,    92,    48,    89,    85,
      98,    92,    93,    58,    58,    68,    76,    77,    88,    88,
      68,    77,    92,    92,    92,    92,    92,    92,    93,    93,
      93,    93,    93,    93,    79,    88,    79,    58,    83,    83,
      61,    70,    88,    45,    63,    89,    92,    89,    58,    16,
      68,    77,     4,     4,    63,    63,    83,    89,    58,    58,
       9,    10,    46,    72,    73,    58,    68,    47,     4,    68,
      77,    77,    70,    80,    80,    58,    63,    63,    16,    94,
      96,    97,    64,    46,    73,    67,    85,    86,    98,    77,
      47,    58,    58,    63,    64,    67,    16,    70,    83,    83,
      48,    95,    97,    47,    47,    86,    98,    86,    16
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    65,    66,    67,    67,    67,    68,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    71,
      71,    72,    72,    73,    73,    74,    74,    75,    76,    76,
      76,    76,    76,    76,    77,    77,    78,    78,    79,    79,
      80,    80,    80,    81,    81,    81,    82,    82,    82,    83,
      83,    84,    85,    85,    85,    85,    86,    86,    86,    86,
      87,    87,    87,    87,    87,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    89,    89,    90,    90,    91,    91,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    93,
      93,    93,    93,    93,    93,    93,    93,    94,    94,    95,
      95,    95,    95,    96,    96,    97,    98,    98
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     0,     3,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     3,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     7,
       6,     2,     3,     3,     2,     3,     2,     5,     5,     5,
       6,     7,     7,     8,     1,     1,     9,     9,     1,     0,
       1,     3,     0,     5,     5,     6,     7,     7,     8,     1,
       1,     6,     4,     4,     2,     0,     6,     6,     4,     4,
       2,     4,     3,     5,     0,     3,     3,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     4,     3,     3,     1,     3,     3,     3,
       3,     3,     4,     3,     6,     4,     3,     3,     3,     3,
       3,     2,     2,     2,     2,     2,     2,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1
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
#line 95 "lex-yacc/parser.ypp"
                    {
    ScopeNode* scopeNode = new ScopeNode(-1, (yyvsp[0].Node));

    scopeNode->runSemanticChecker();
    CompilerOrganizer::dumpErrors();

    if (CompilerOrganizer::getErrorCount() == 0) {
        scopeNode->generateQuadruples();

        CompilerOrganizer::startRunning();
        scopeNode->run();
        CompilerOrganizer::exitWithSuccess();
        
        CompilerOrganizer::dumpSymbolTable();
        CompilerOrganizer::dumpQuadruples();
    } else {
        std::cout << "There Are " << CompilerOrganizer::getErrorCount()  << " Errors Found" << std::endl;
        CompilerOrganizer::exitWithFailure();
    }

    delete scopeNode;
}
#line 1537 "src/parser.tab.cpp"
    break;

  case 3: /* Sentences: Sentence Sentences  */
#line 119 "lex-yacc/parser.ypp"
                                { (yyval.Node) = (yyvsp[-1].Node)->setNext((yyvsp[0].Node)); }
#line 1543 "src/parser.tab.cpp"
    break;

  case 4: /* Sentences: Scope Sentences  */
#line 121 "lex-yacc/parser.ypp"
                                { (yyval.Node) = (yyvsp[-1].Node)->setNext((yyvsp[0].Node)); }
#line 1549 "src/parser.tab.cpp"
    break;

  case 5: /* Sentences: %empty  */
#line 123 "lex-yacc/parser.ypp"
                                { (yyval.Node) = nullptr; }
#line 1555 "src/parser.tab.cpp"
    break;

  case 6: /* Scope: SCOPE_BEGIN Sentences SCOPE_END  */
#line 126 "lex-yacc/parser.ypp"
                                          { (yyval.Node) = new ScopeNode((yyvsp[-2].data).line, (yyvsp[-1].Node)); }
#line 1561 "src/parser.tab.cpp"
    break;

  case 7: /* Sentence: VariableAssignment ';'  */
#line 129 "lex-yacc/parser.ypp"
                                { (yyval.Node) = (yyvsp[-1].Node); }
#line 1567 "src/parser.tab.cpp"
    break;

  case 8: /* Sentence: VariableDeclaration ';'  */
#line 130 "lex-yacc/parser.ypp"
                                { (yyval.Node) = (yyvsp[-1].Node); }
#line 1573 "src/parser.tab.cpp"
    break;

  case 9: /* Sentence: FunctionDefinition  */
#line 131 "lex-yacc/parser.ypp"
                                { (yyval.Node) = (yyvsp[0].Node); }
#line 1579 "src/parser.tab.cpp"
    break;

  case 10: /* Sentence: IFSentence  */
#line 132 "lex-yacc/parser.ypp"
                                { (yyval.Node) = (yyvsp[0].Node); }
#line 1585 "src/parser.tab.cpp"
    break;

  case 11: /* Sentence: ForSentence  */
#line 133 "lex-yacc/parser.ypp"
                                { (yyval.Node) = (yyvsp[0].Node); }
#line 1591 "src/parser.tab.cpp"
    break;

  case 12: /* Sentence: WhileSentence  */
#line 134 "lex-yacc/parser.ypp"
                                { (yyval.Node) = (yyvsp[0].Node); }
#line 1597 "src/parser.tab.cpp"
    break;

  case 13: /* Sentence: DoWhileSentence  */
#line 135 "lex-yacc/parser.ypp"
                                { (yyval.Node) = (yyvsp[0].Node); }
#line 1603 "src/parser.tab.cpp"
    break;

  case 14: /* Sentence: PrintSentence  */
#line 136 "lex-yacc/parser.ypp"
                                { (yyval.Node) = (yyvsp[0].Node); }
#line 1609 "src/parser.tab.cpp"
    break;

  case 15: /* Sentence: ReturnSentence  */
#line 137 "lex-yacc/parser.ypp"
                                { (yyval.Node) = (yyvsp[0].Node); }
#line 1615 "src/parser.tab.cpp"
    break;

  case 16: /* Sentence: SwitchSentence  */
#line 138 "lex-yacc/parser.ypp"
                                { (yyval.Node) = (yyvsp[0].Node); }
#line 1621 "src/parser.tab.cpp"
    break;

  case 17: /* Sentence: CONTINUE ';'  */
#line 139 "lex-yacc/parser.ypp"
                                { (yyval.Node) = new ContinueNode((yyvsp[-1].data).line);}
#line 1627 "src/parser.tab.cpp"
    break;

  case 18: /* Sentence: BREAK ';'  */
#line 140 "lex-yacc/parser.ypp"
                                { (yyval.Node) = new BreakNode((yyvsp[-1].data).line);}
#line 1633 "src/parser.tab.cpp"
    break;

  case 19: /* VariableAssignment: IDENTIFIER '=' Operation  */
#line 144 "lex-yacc/parser.ypp"
                                  { (yyval.Node) = new AssignNode((yyvsp[-2].data).line, (yyvsp[-2].data).str, (yyvsp[0].Exp)); }
#line 1639 "src/parser.tab.cpp"
    break;

  case 20: /* VariableAssignment: Operation  */
#line 146 "lex-yacc/parser.ypp"
                {
        (yyval.Node) = new AssignNode(lineNumber, "", (yyvsp[0].Exp));
    }
#line 1647 "src/parser.tab.cpp"
    break;

  case 21: /* VariableAssignment: IDENTIFIER PLUS_EQUAL Operation  */
#line 150 "lex-yacc/parser.ypp"
                                         { 
        Expression* id = new IdentifierContainer((yyvsp[-2].data).str);
        Expression* exp = new Expression(id, (yyvsp[0].Exp), OP_ADD);
        (yyval.Node) = new AssignNode((yyvsp[-2].data).line, (yyvsp[-2].data).str, exp); 
    }
#line 1657 "src/parser.tab.cpp"
    break;

  case 22: /* VariableAssignment: IDENTIFIER MINUS_EQUAL Operation  */
#line 156 "lex-yacc/parser.ypp"
                                          { 
        Expression* id = new IdentifierContainer((yyvsp[-2].data).str);
        Expression* exp = new Expression(id, (yyvsp[0].Exp), OP_SUB);
        (yyval.Node) = new AssignNode((yyvsp[-2].data).line, (yyvsp[-2].data).str, exp); 
    }
#line 1667 "src/parser.tab.cpp"
    break;

  case 23: /* VariableAssignment: IDENTIFIER MUL_EQUAL Operation  */
#line 162 "lex-yacc/parser.ypp"
                                        { 
        Expression* id = new IdentifierContainer((yyvsp[-2].data).str);
        Expression* exp = new Expression(id, (yyvsp[0].Exp), OP_MUL);
        (yyval.Node) = new AssignNode((yyvsp[-2].data).line, (yyvsp[-2].data).str, exp); 
    }
#line 1677 "src/parser.tab.cpp"
    break;

  case 24: /* VariableAssignment: IDENTIFIER DIV_EQUAL Operation  */
#line 168 "lex-yacc/parser.ypp"
                                        { 
        Expression* id = new IdentifierContainer((yyvsp[-2].data).str);
        Expression* exp = new Expression(id, (yyvsp[0].Exp), OP_DIV);
        (yyval.Node) = new AssignNode((yyvsp[-2].data).line, (yyvsp[-2].data).str, exp); 
    }
#line 1687 "src/parser.tab.cpp"
    break;

  case 25: /* VariableAssignment: IDENTIFIER MOD_EQUAL Operation  */
#line 174 "lex-yacc/parser.ypp"
                                        { 
        Expression* id = new IdentifierContainer((yyvsp[-2].data).str);
        Expression* exp = new Expression(id, (yyvsp[0].Exp), OP_MOD);
        (yyval.Node) = new AssignNode((yyvsp[-2].data).line, (yyvsp[-2].data).str, exp); 
    }
#line 1697 "src/parser.tab.cpp"
    break;

  case 26: /* VariableAssignment: IDENTIFIER AND_EQUAL Operation  */
#line 180 "lex-yacc/parser.ypp"
                                        { 
        Expression* id = new IdentifierContainer((yyvsp[-2].data).str);
        Expression* exp = new Expression(id, (yyvsp[0].Exp), OP_AND);
        (yyval.Node) = new AssignNode((yyvsp[-2].data).line, (yyvsp[-2].data).str, exp); 
    }
#line 1707 "src/parser.tab.cpp"
    break;

  case 27: /* VariableAssignment: IDENTIFIER OR_EQUAL Operation  */
#line 186 "lex-yacc/parser.ypp"
                                       { 
        Expression* id = new IdentifierContainer((yyvsp[-2].data).str);
        Expression* exp = new Expression(id, (yyvsp[0].Exp), OP_OR);
        (yyval.Node) = new AssignNode((yyvsp[-2].data).line, (yyvsp[-2].data).str, exp); 
    }
#line 1717 "src/parser.tab.cpp"
    break;

  case 28: /* VariableAssignment: IDENTIFIER XOR_EQUAL Operation  */
#line 192 "lex-yacc/parser.ypp"
                                        { 
        Expression* id = new IdentifierContainer((yyvsp[-2].data).str);
        Expression* exp = new Expression(id, (yyvsp[0].Exp), OP_XOR);
        (yyval.Node) = new AssignNode((yyvsp[-2].data).line, (yyvsp[-2].data).str, exp); 
    }
#line 1727 "src/parser.tab.cpp"
    break;

  case 29: /* SwitchSentence: SWITCH '(' IDENTIFIER ')' SCOPE_BEGIN SwitchBody SCOPE_END  */
#line 201 "lex-yacc/parser.ypp"
                                                                 { (yyval.Node) = new SwitchNode((yyvsp[-6].data).line, (yyvsp[-4].data).str, (yyvsp[-1].SB)); }
#line 1733 "src/parser.tab.cpp"
    break;

  case 30: /* SwitchSentence: SWITCH '(' IDENTIFIER ')' SCOPE_BEGIN SCOPE_END  */
#line 202 "lex-yacc/parser.ypp"
                                                                 { (yyval.Node) = new SwitchNode((yyvsp[-5].data).line, (yyvsp[-3].data).str, nullptr); }
#line 1739 "src/parser.tab.cpp"
    break;

  case 31: /* SwitchBody: Case Sentences  */
#line 205 "lex-yacc/parser.ypp"
                                    { 
        (yyval.SB) = new SwitchBody(dynamic_cast<CaseNode*>((yyvsp[-1].Node))->assignBody((yyvsp[0].Node))); 
    }
#line 1747 "src/parser.tab.cpp"
    break;

  case 32: /* SwitchBody: SwitchBody Case Sentences  */
#line 208 "lex-yacc/parser.ypp"
                                    { 
        (yyval.SB) = dynamic_cast<SwitchBody*>((yyvsp[-2].SB))->addCase(dynamic_cast<CaseNode*>((yyvsp[-1].Node))->assignBody((yyvsp[0].Node))); 
    }
#line 1755 "src/parser.tab.cpp"
    break;

  case 33: /* Case: CASE Operand ':'  */
#line 213 "lex-yacc/parser.ypp"
                                    { (yyval.Node) = new CaseNode((yyvsp[-2].data).line, (yyvsp[-1].Exp)); }
#line 1761 "src/parser.tab.cpp"
    break;

  case 34: /* Case: DEFAULT ':'  */
#line 214 "lex-yacc/parser.ypp"
                                    { (yyval.Node) = new CaseNode((yyvsp[-1].data).line);}
#line 1767 "src/parser.tab.cpp"
    break;

  case 35: /* ReturnSentence: RETURN Operation ';'  */
#line 217 "lex-yacc/parser.ypp"
                                      { (yyval.Node) = new ReturnNode((yyvsp[-2].data).line, (yyvsp[-1].Exp));}
#line 1773 "src/parser.tab.cpp"
    break;

  case 36: /* ReturnSentence: RETURN ';'  */
#line 218 "lex-yacc/parser.ypp"
                                      { (yyval.Node) = new ReturnNode((yyvsp[-1].data).line); }
#line 1779 "src/parser.tab.cpp"
    break;

  case 37: /* PrintSentence: PRINT '(' Operation ')' ';'  */
#line 221 "lex-yacc/parser.ypp"
                                    { (yyval.Node) = new PrintNode((yyvsp[-4].data).line, (yyvsp[-2].Exp));  }
#line 1785 "src/parser.tab.cpp"
    break;

  case 38: /* IFSentence: IF '(' Condition ')' IfExtension  */
#line 224 "lex-yacc/parser.ypp"
                                                                    { (yyval.Node) = new IfNode((yyvsp[-4].data).line, (yyvsp[-2].Exp), (yyvsp[0].Node));   }
#line 1791 "src/parser.tab.cpp"
    break;

  case 39: /* IFSentence: IF '(' VariableAssignment ')' IfExtension  */
#line 225 "lex-yacc/parser.ypp"
                                                                    { (yyval.Node) = new IfNode((yyvsp[-4].data).line, dynamic_cast<AssignNode*>((yyvsp[-2].Node)), (yyvsp[0].Node));   }
#line 1797 "src/parser.tab.cpp"
    break;

  case 40: /* IFSentence: IF '(' '!' Operation ')' IfExtension  */
#line 226 "lex-yacc/parser.ypp"
                                                                    { (yyval.Node) = new IfNode((yyvsp[-5].data).line, (yyvsp[-2].Exp), (yyvsp[0].Node), true);   }
#line 1803 "src/parser.tab.cpp"
    break;

  case 41: /* IFSentence: IF '(' Condition ')' Scope ELSE IfExtension  */
#line 228 "lex-yacc/parser.ypp"
                                                                    { (yyval.Node) = new IfNode((yyvsp[-6].data).line, (yyvsp[-4].Exp), (yyvsp[-2].Node)); dynamic_cast<IfNode*>((yyval.Node))->setElse((yyvsp[0].Node));   }
#line 1809 "src/parser.tab.cpp"
    break;

  case 42: /* IFSentence: IF '(' VariableAssignment ')' Scope ELSE IfExtension  */
#line 229 "lex-yacc/parser.ypp"
                                                                    { (yyval.Node) = new IfNode((yyvsp[-6].data).line, dynamic_cast<AssignNode*>((yyvsp[-4].Node)), (yyvsp[-2].Node)); dynamic_cast<IfNode*>((yyval.Node))->setElse((yyvsp[0].Node));   }
#line 1815 "src/parser.tab.cpp"
    break;

  case 43: /* IFSentence: IF '(' '!' Operation ')' Scope ELSE IfExtension  */
#line 230 "lex-yacc/parser.ypp"
                                                                    { (yyval.Node) = new IfNode((yyvsp[-7].data).line, (yyvsp[-4].Exp), (yyvsp[-2].Node), true); dynamic_cast<IfNode*>((yyval.Node))->setElse((yyvsp[0].Node));   }
#line 1821 "src/parser.tab.cpp"
    break;

  case 44: /* IfExtension: IFSentence  */
#line 234 "lex-yacc/parser.ypp"
                                                                    {  (yyval.Node) = new ScopeNode(lineNumber, (yyvsp[0].Node)); }
#line 1827 "src/parser.tab.cpp"
    break;

  case 46: /* ForSentence: FOR '(' VariableDeclaration ';' ForCondition ';' ForPostSentence ')' LoopScope  */
#line 237 "lex-yacc/parser.ypp"
                                                                                            {
    (yyval.Node) = new ForNode((yyvsp[-8].data).line, (yyvsp[-6].Node), (yyvsp[-4].Exp), dynamic_cast<AssignNode*>((yyvsp[-2].Node)), dynamic_cast<ScopeNode*>((yyvsp[0].Node)));
}
#line 1835 "src/parser.tab.cpp"
    break;

  case 47: /* ForSentence: FOR '(' VariableAssignment ';' ForCondition ';' ForPostSentence ')' LoopScope  */
#line 240 "lex-yacc/parser.ypp"
                                                                                {
    (yyval.Node) = new ForNode((yyvsp[-8].data).line, (yyvsp[-6].Node), (yyvsp[-4].Exp), dynamic_cast<AssignNode*>((yyvsp[-2].Node)), dynamic_cast<ScopeNode*>((yyvsp[0].Node)));
}
#line 1843 "src/parser.tab.cpp"
    break;

  case 49: /* ForCondition: %empty  */
#line 244 "lex-yacc/parser.ypp"
                           {(yyval.Exp) = nullptr;}
#line 1849 "src/parser.tab.cpp"
    break;

  case 50: /* ForPostSentence: VariableAssignment  */
#line 247 "lex-yacc/parser.ypp"
                                                 { (yyval.Node) = (yyvsp[0].Node);  }
#line 1855 "src/parser.tab.cpp"
    break;

  case 51: /* ForPostSentence: ForPostSentence ',' VariableAssignment  */
#line 248 "lex-yacc/parser.ypp"
                                                 { (yyval.Node) = dynamic_cast<AssignNode*>((yyvsp[-2].Node))->setNextAssignment((yyvsp[0].Node)); }
#line 1861 "src/parser.tab.cpp"
    break;

  case 52: /* ForPostSentence: %empty  */
#line 249 "lex-yacc/parser.ypp"
      {(yyval.Node) = nullptr;}
#line 1867 "src/parser.tab.cpp"
    break;

  case 53: /* WhileSentence: WHILE '(' Condition ')' LoopScope  */
#line 251 "lex-yacc/parser.ypp"
                                                 {
    (yyval.Node) = new WhileNode((yyvsp[-4].data).line, (yyvsp[-2].Exp), dynamic_cast<ScopeNode*>((yyvsp[0].Node)));
}
#line 1875 "src/parser.tab.cpp"
    break;

  case 54: /* WhileSentence: WHILE '(' VariableAssignment ')' LoopScope  */
#line 255 "lex-yacc/parser.ypp"
                                             {
    (yyval.Node) = new WhileNode((yyvsp[-4].data).line, dynamic_cast<AssignNode*>((yyvsp[-2].Node)), dynamic_cast<ScopeNode*>((yyvsp[0].Node)));
}
#line 1883 "src/parser.tab.cpp"
    break;

  case 55: /* WhileSentence: WHILE '(' '!' Operation ')' LoopScope  */
#line 259 "lex-yacc/parser.ypp"
                                        {
    (yyval.Node) = new WhileNode((yyvsp[-5].data).line, (yyvsp[-2].Exp), dynamic_cast<ScopeNode*>((yyvsp[0].Node)), true);
}
#line 1891 "src/parser.tab.cpp"
    break;

  case 56: /* DoWhileSentence: DO LoopScope WHILE '(' Condition ')' ';'  */
#line 263 "lex-yacc/parser.ypp"
                                                          {
    (yyval.Node) = new DoWhileNode((yyvsp[-6].data).line, (yyvsp[-2].Exp), dynamic_cast<ScopeNode*>((yyvsp[-5].Node)));
}
#line 1899 "src/parser.tab.cpp"
    break;

  case 57: /* DoWhileSentence: DO LoopScope WHILE '(' VariableAssignment ')' ';'  */
#line 266 "lex-yacc/parser.ypp"
                                                    {
    (yyval.Node) = new DoWhileNode((yyvsp[-6].data).line, dynamic_cast<AssignNode*>((yyvsp[-2].Node)), dynamic_cast<ScopeNode*>((yyvsp[-5].Node)));
}
#line 1907 "src/parser.tab.cpp"
    break;

  case 58: /* DoWhileSentence: DO LoopScope WHILE '(' '!' Operation ')' ';'  */
#line 269 "lex-yacc/parser.ypp"
                                               {
    (yyval.Node) = new DoWhileNode((yyvsp[-7].data).line, (yyvsp[-2].Exp), dynamic_cast<ScopeNode*>((yyvsp[-6].Node)), true);
}
#line 1915 "src/parser.tab.cpp"
    break;

  case 60: /* LoopScope: Sentence  */
#line 274 "lex-yacc/parser.ypp"
                     { (yyval.Node) = new ScopeNode(lineNumber, (yyvsp[0].Node)); }
#line 1921 "src/parser.tab.cpp"
    break;

  case 61: /* FunctionDefinition: Type IDENTIFIER '(' FunctionParams ')' Scope  */
#line 277 "lex-yacc/parser.ypp"
                                                   { 
        (yyval.Node) = new FunctionDefintionNode((yyvsp[-4].data).line, (yyvsp[-5].DT), (yyvsp[-4].data).str, (yyvsp[-2].FP), dynamic_cast<ScopeNode*>((yyvsp[0].Node))); 
    }
#line 1929 "src/parser.tab.cpp"
    break;

  case 62: /* FunctionParams: Type IDENTIFIER ',' FunctionParams  */
#line 282 "lex-yacc/parser.ypp"
                                                                              { (yyval.FP) = (yyvsp[0].FP)->addParameter(nullptr, (yyvsp[-3].DT), (yyvsp[-2].data).str);}
#line 1935 "src/parser.tab.cpp"
    break;

  case 63: /* FunctionParams: Type IDENTIFIER ',' FunctionDefaulValueParams  */
#line 283 "lex-yacc/parser.ypp"
                                                                              { (yyval.FP) = (yyvsp[0].FP)->addParameter(nullptr, (yyvsp[-3].DT), (yyvsp[-2].data).str);}
#line 1941 "src/parser.tab.cpp"
    break;

  case 64: /* FunctionParams: Type IDENTIFIER  */
#line 284 "lex-yacc/parser.ypp"
                                                                              { (yyval.FP) = new FunctionParametersNode(nullptr, (yyvsp[-1].DT), (yyvsp[0].data).str);}
#line 1947 "src/parser.tab.cpp"
    break;

  case 65: /* FunctionParams: %empty  */
#line 285 "lex-yacc/parser.ypp"
                                                                              { (yyval.FP) = nullptr; }
#line 1953 "src/parser.tab.cpp"
    break;

  case 66: /* FunctionDefaulValueParams: Type IDENTIFIER '=' FunctionParamOperand ',' FunctionDefaulValueParams  */
#line 288 "lex-yacc/parser.ypp"
                                                                              { (yyval.FP) = (yyvsp[0].FP)->addParameter((yyvsp[-2].Exp), (yyvsp[-5].DT), (yyvsp[-4].data).str);}
#line 1959 "src/parser.tab.cpp"
    break;

  case 67: /* FunctionDefaulValueParams: Type IDENTIFIER '=' StringOperand ',' FunctionDefaulValueParams  */
#line 289 "lex-yacc/parser.ypp"
                                                                              { (yyval.FP) = (yyvsp[0].FP)->addParameter((yyvsp[-2].Exp), (yyvsp[-5].DT), (yyvsp[-4].data).str);}
#line 1965 "src/parser.tab.cpp"
    break;

  case 68: /* FunctionDefaulValueParams: Type IDENTIFIER '=' FunctionParamOperand  */
#line 290 "lex-yacc/parser.ypp"
                                                                              { (yyval.FP) = new FunctionParametersNode((yyvsp[0].Exp), (yyvsp[-3].DT), (yyvsp[-2].data).str);}
#line 1971 "src/parser.tab.cpp"
    break;

  case 69: /* FunctionDefaulValueParams: Type IDENTIFIER '=' StringOperand  */
#line 291 "lex-yacc/parser.ypp"
                                                                              { (yyval.FP) = new FunctionParametersNode((yyvsp[0].Exp), (yyvsp[-3].DT), (yyvsp[-2].data).str);}
#line 1977 "src/parser.tab.cpp"
    break;

  case 70: /* VariableDeclaration: Type IDENTIFIER  */
#line 294 "lex-yacc/parser.ypp"
                                                        { (yyval.Node) = new DefineNode((yyvsp[0].data).line, (yyvsp[-1].DT), (yyvsp[0].data).str, nullptr); }
#line 1983 "src/parser.tab.cpp"
    break;

  case 71: /* VariableDeclaration: Type IDENTIFIER '=' Operation  */
#line 295 "lex-yacc/parser.ypp"
                                                        { (yyval.Node) = new DefineNode((yyvsp[-2].data).line, (yyvsp[-3].DT), (yyvsp[-2].data).str, (yyvsp[0].Exp)); }
#line 1989 "src/parser.tab.cpp"
    break;

  case 72: /* VariableDeclaration: VariableDeclaration ',' IDENTIFIER  */
#line 296 "lex-yacc/parser.ypp"
                                                        { (yyval.Node) = dynamic_cast<DefineNode*>((yyvsp[-2].Node))->setNextDefine( new DefineNode((yyvsp[0].data).line, (yyvsp[0].data).str, nullptr) ); }
#line 1995 "src/parser.tab.cpp"
    break;

  case 73: /* VariableDeclaration: VariableDeclaration ',' IDENTIFIER '=' Operation  */
#line 297 "lex-yacc/parser.ypp"
                                                        { (yyval.Node) = dynamic_cast<DefineNode*>((yyvsp[-4].Node))->setNextDefine( new DefineNode((yyvsp[-2].data).line, (yyvsp[-2].data).str, (yyvsp[0].Exp)) ); }
#line 2001 "src/parser.tab.cpp"
    break;

  case 74: /* VariableDeclaration: %empty  */
#line 298 "lex-yacc/parser.ypp"
      {(yyval.Node) = nullptr;}
#line 2007 "src/parser.tab.cpp"
    break;

  case 75: /* Condition: Condition OR Condition  */
#line 301 "lex-yacc/parser.ypp"
                                                      { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_OR);  }
#line 2013 "src/parser.tab.cpp"
    break;

  case 76: /* Condition: Condition AND Condition  */
#line 302 "lex-yacc/parser.ypp"
                                                      { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_AND); }
#line 2019 "src/parser.tab.cpp"
    break;

  case 77: /* Condition: '!' Condition  */
#line 303 "lex-yacc/parser.ypp"
                                                      { (yyval.Exp) = new Expression((yyvsp[0].Exp), (yyvsp[0].Exp), OP_NOT); }
#line 2025 "src/parser.tab.cpp"
    break;

  case 78: /* Condition: MathOperation GTE MathOperation  */
#line 305 "lex-yacc/parser.ypp"
                                                      { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_GE);  }
#line 2031 "src/parser.tab.cpp"
    break;

  case 79: /* Condition: MathOperation GT MathOperation  */
#line 306 "lex-yacc/parser.ypp"
                                                      { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_GT);  }
#line 2037 "src/parser.tab.cpp"
    break;

  case 80: /* Condition: MathOperation LTE MathOperation  */
#line 307 "lex-yacc/parser.ypp"
                                                      { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_LE);  }
#line 2043 "src/parser.tab.cpp"
    break;

  case 81: /* Condition: MathOperation LT MathOperation  */
#line 308 "lex-yacc/parser.ypp"
                                                      { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_LT);  }
#line 2049 "src/parser.tab.cpp"
    break;

  case 82: /* Condition: MathOperation ISEQUAL MathOperation  */
#line 309 "lex-yacc/parser.ypp"
                                                      { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_EQ);  }
#line 2055 "src/parser.tab.cpp"
    break;

  case 83: /* Condition: MathOperation NOTEQUAL MathOperation  */
#line 310 "lex-yacc/parser.ypp"
                                                      { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_NEQ); }
#line 2061 "src/parser.tab.cpp"
    break;

  case 84: /* Condition: StringOperation GTE StringOperation  */
#line 312 "lex-yacc/parser.ypp"
                                                      { (yyval.Exp) = new StringContainer((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_GE);   }
#line 2067 "src/parser.tab.cpp"
    break;

  case 85: /* Condition: StringOperation GT StringOperation  */
#line 313 "lex-yacc/parser.ypp"
                                                      { (yyval.Exp) = new StringContainer((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_GT);   }
#line 2073 "src/parser.tab.cpp"
    break;

  case 86: /* Condition: StringOperation LTE StringOperation  */
#line 314 "lex-yacc/parser.ypp"
                                                      { (yyval.Exp) = new StringContainer((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_LE);   }
#line 2079 "src/parser.tab.cpp"
    break;

  case 87: /* Condition: StringOperation LT StringOperation  */
#line 315 "lex-yacc/parser.ypp"
                                                      { (yyval.Exp) = new StringContainer((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_LT);   }
#line 2085 "src/parser.tab.cpp"
    break;

  case 88: /* Condition: StringOperation ISEQUAL StringOperation  */
#line 316 "lex-yacc/parser.ypp"
                                                      { (yyval.Exp) = new StringContainer((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_EQ);   }
#line 2091 "src/parser.tab.cpp"
    break;

  case 89: /* Condition: StringOperation NOTEQUAL StringOperation  */
#line 317 "lex-yacc/parser.ypp"
                                                      { (yyval.Exp) = new StringContainer((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_NEQ);  }
#line 2097 "src/parser.tab.cpp"
    break;

  case 90: /* Condition: '(' Condition ')'  */
#line 319 "lex-yacc/parser.ypp"
                                                      { (yyval.Exp) = (yyvsp[-1].Exp); }
#line 2103 "src/parser.tab.cpp"
    break;

  case 91: /* Operation: MathOperation  */
#line 325 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = (yyvsp[0].Exp); }
#line 2109 "src/parser.tab.cpp"
    break;

  case 92: /* Operation: StringOperation  */
#line 326 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = (yyvsp[0].Exp); }
#line 2115 "src/parser.tab.cpp"
    break;

  case 93: /* FunctionCall: IDENTIFIER '(' FunctionCallParams ')'  */
#line 329 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new FunctionCallNode( (yyvsp[-3].data).line, (yyvsp[-3].data).str, (yyvsp[-1].FCP) ); }
#line 2121 "src/parser.tab.cpp"
    break;

  case 94: /* FunctionCall: IDENTIFIER '(' ')'  */
#line 330 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new FunctionCallNode( (yyvsp[-2].data).line, (yyvsp[-2].data).str, nullptr ); }
#line 2127 "src/parser.tab.cpp"
    break;

  case 95: /* FunctionCallParams: FunctionCallParams ',' Operation  */
#line 333 "lex-yacc/parser.ypp"
                                                    { (yyval.FCP) = (yyvsp[-2].FCP)->addParameter((yyvsp[0].Exp)); }
#line 2133 "src/parser.tab.cpp"
    break;

  case 96: /* FunctionCallParams: Operation  */
#line 334 "lex-yacc/parser.ypp"
                                                    { (yyval.FCP) = new FunctionCallParametersNode((yyvsp[0].Exp)); }
#line 2139 "src/parser.tab.cpp"
    break;

  case 97: /* MathOperation: MathOperation '+' MathOperation  */
#line 337 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_ADD); }
#line 2145 "src/parser.tab.cpp"
    break;

  case 98: /* MathOperation: MathOperation '-' MathOperation  */
#line 338 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_SUB); }
#line 2151 "src/parser.tab.cpp"
    break;

  case 99: /* MathOperation: MathOperation '*' MathOperation  */
#line 339 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_MUL); }
#line 2157 "src/parser.tab.cpp"
    break;

  case 100: /* MathOperation: MathOperation '/' MathOperation  */
#line 340 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_DIV); }
#line 2163 "src/parser.tab.cpp"
    break;

  case 101: /* MathOperation: MathOperation '%' MathOperation  */
#line 341 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_MOD); }
#line 2169 "src/parser.tab.cpp"
    break;

  case 102: /* MathOperation: '(' MathOperation ')' MathOperation  */
#line 342 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_MUL); }
#line 2175 "src/parser.tab.cpp"
    break;

  case 103: /* MathOperation: '(' MathOperation ')'  */
#line 343 "lex-yacc/parser.ypp"
                                                    {               (yyval.Exp) = (yyvsp[-1].Exp);               }
#line 2181 "src/parser.tab.cpp"
    break;

  case 104: /* MathOperation: POW '(' MathOperation ',' MathOperation ')'  */
#line 344 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-3].Exp), (yyvsp[-1].Exp), OP_POW); }
#line 2187 "src/parser.tab.cpp"
    break;

  case 105: /* MathOperation: SQRT '(' MathOperation ')'  */
#line 345 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-1].Exp), (yyvsp[-1].Exp), OP_SQRT);}
#line 2193 "src/parser.tab.cpp"
    break;

  case 106: /* MathOperation: MathOperation SHL MathOperation  */
#line 346 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_SHL); }
#line 2199 "src/parser.tab.cpp"
    break;

  case 107: /* MathOperation: MathOperation SHR MathOperation  */
#line 347 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_SHR); }
#line 2205 "src/parser.tab.cpp"
    break;

  case 108: /* MathOperation: MathOperation '|' MathOperation  */
#line 348 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_BW_OR);  }
#line 2211 "src/parser.tab.cpp"
    break;

  case 109: /* MathOperation: MathOperation '&' MathOperation  */
#line 349 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_BW_AND); }
#line 2217 "src/parser.tab.cpp"
    break;

  case 110: /* MathOperation: MathOperation '^' MathOperation  */
#line 350 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_XOR); }
#line 2223 "src/parser.tab.cpp"
    break;

  case 111: /* MathOperation: '~' MathOperation  */
#line 351 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[0].Exp), (yyvsp[0].Exp), OP_BW_NOT); }
#line 2229 "src/parser.tab.cpp"
    break;

  case 112: /* MathOperation: IDENTIFIER INCREMENT  */
#line 352 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new IdentifierContainer((yyvsp[-1].data).str, OP_POST_ADD); }
#line 2235 "src/parser.tab.cpp"
    break;

  case 113: /* MathOperation: INCREMENT IDENTIFIER  */
#line 353 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new IdentifierContainer((yyvsp[0].data).str, OP_PRE_ADD); }
#line 2241 "src/parser.tab.cpp"
    break;

  case 114: /* MathOperation: DECREMENT IDENTIFIER  */
#line 354 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new IdentifierContainer((yyvsp[0].data).str, OP_PRE_SUB); }
#line 2247 "src/parser.tab.cpp"
    break;

  case 115: /* MathOperation: IDENTIFIER DECREMENT  */
#line 355 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new IdentifierContainer((yyvsp[-1].data).str, OP_POST_SUB); }
#line 2253 "src/parser.tab.cpp"
    break;

  case 116: /* MathOperation: '-' MathOperation  */
#line 356 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[0].Exp), (yyvsp[0].Exp), OP_UMINUS); }
#line 2259 "src/parser.tab.cpp"
    break;

  case 119: /* StringOperation: StringOperation '+' StringOperation  */
#line 361 "lex-yacc/parser.ypp"
                                                        { (yyval.Exp) =  new StringContainer((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_ADD); }
#line 2265 "src/parser.tab.cpp"
    break;

  case 120: /* StringOperation: StringOperation '+' MathOperation  */
#line 362 "lex-yacc/parser.ypp"
                                                        { (yyval.Exp) =  new StringContainer((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_ADD); }
#line 2271 "src/parser.tab.cpp"
    break;

  case 121: /* StringOperation: StringOperation '-' MathOperation  */
#line 363 "lex-yacc/parser.ypp"
                                                        { (yyval.Exp) =  new StringContainer((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_SUB); }
#line 2277 "src/parser.tab.cpp"
    break;

  case 122: /* StringOperation: MathOperation '+' StringOperation  */
#line 364 "lex-yacc/parser.ypp"
                                                        { (yyval.Exp) =  new StringContainer((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_ADD); }
#line 2283 "src/parser.tab.cpp"
    break;

  case 123: /* StringOperation: '(' StringOperation ')'  */
#line 365 "lex-yacc/parser.ypp"
                                                        { (yyval.Exp) =  (yyvsp[-1].Exp); }
#line 2289 "src/parser.tab.cpp"
    break;

  case 124: /* StringOperation: StringOperation SHL StringOperation  */
#line 366 "lex-yacc/parser.ypp"
                                                        { (yyval.Exp) =  new StringContainer((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_SHL); }
#line 2295 "src/parser.tab.cpp"
    break;

  case 125: /* StringOperation: StringOperation SHR StringOperation  */
#line 367 "lex-yacc/parser.ypp"
                                                        { (yyval.Exp) =  new StringContainer((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_SHR); }
#line 2301 "src/parser.tab.cpp"
    break;

  case 129: /* FunctionParamOperand: INTEGER  */
#line 373 "lex-yacc/parser.ypp"
                        { (yyval.Exp) = new Expression((yyvsp[0].data).str, DataType::Int());}
#line 2307 "src/parser.tab.cpp"
    break;

  case 130: /* FunctionParamOperand: FLOAT  */
#line 375 "lex-yacc/parser.ypp"
                        { (yyval.Exp) = new Expression((yyvsp[0].data).str, DataType::Float());}
#line 2313 "src/parser.tab.cpp"
    break;

  case 131: /* FunctionParamOperand: CHARACTER  */
#line 377 "lex-yacc/parser.ypp"
                        { (yyval.Exp) = new Expression((yyvsp[0].data).str, DataType::Char());}
#line 2319 "src/parser.tab.cpp"
    break;

  case 132: /* FunctionParamOperand: BOOLEAN  */
#line 379 "lex-yacc/parser.ypp"
                        { (yyval.Exp) = new Expression((yyvsp[0].data).str, DataType::Bool());}
#line 2325 "src/parser.tab.cpp"
    break;

  case 134: /* MathOperand: IDENTIFIER  */
#line 384 "lex-yacc/parser.ypp"
                        { (yyval.Exp) = new IdentifierContainer((yyvsp[0].data).str); }
#line 2331 "src/parser.tab.cpp"
    break;

  case 135: /* StringOperand: STRING  */
#line 386 "lex-yacc/parser.ypp"
                        { (yyval.Exp) = new StringContainer((yyvsp[0].data).str); }
#line 2337 "src/parser.tab.cpp"
    break;

  case 136: /* Type: CONST DATA_TYPE  */
#line 389 "lex-yacc/parser.ypp"
                        { (yyval.DT) = new DataType((yyvsp[0].data).str, true);}
#line 2343 "src/parser.tab.cpp"
    break;

  case 137: /* Type: DATA_TYPE  */
#line 390 "lex-yacc/parser.ypp"
                        { (yyval.DT) = new DataType((yyvsp[0].data).str, false);}
#line 2349 "src/parser.tab.cpp"
    break;


#line 2353 "src/parser.tab.cpp"

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

#line 392 "lex-yacc/parser.ypp"



int main(int argc, char* argv[]) {
    ScopeNode* x = new ScopeNode(-1);
    yyin = fopen("test.yapl", "r");
    yyparse();
    return 0;
}
