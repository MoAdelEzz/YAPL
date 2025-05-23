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
        ErrorDetail error(Severity::ERROR, "Syntax Error", "", lineNumber);
        CompilerOrganizer::addError(error);
        std::cerr << "Error: " << s << std::endl;
        std::cerr << "Line: " << lineNumber << std::endl;
    }
    CompilerState CompilerOrganizer::state = VALIDATING;
    std::vector<ErrorDetail> CompilerOrganizer::errors;
    std::vector<SymbolTableEntry> CompilerOrganizer::symbolTable;
    std::vector<QuadrupleEntry> CompilerOrganizer::quadruples;

    int QuadrupleEntry::index = 1;

#line 112 "src/parser.tab.cpp"

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
  YYSYMBOL_Operation = 88,                 /* Operation  */
  YYSYMBOL_FunctionCall = 89,              /* FunctionCall  */
  YYSYMBOL_FunctionCallParams = 90,        /* FunctionCallParams  */
  YYSYMBOL_MathOperation = 91,             /* MathOperation  */
  YYSYMBOL_StringOperation = 92,           /* StringOperation  */
  YYSYMBOL_Operand = 93,                   /* Operand  */
  YYSYMBOL_FunctionParamOperand = 94,      /* FunctionParamOperand  */
  YYSYMBOL_MathOperand = 95,               /* MathOperand  */
  YYSYMBOL_StringOperand = 96,             /* StringOperand  */
  YYSYMBOL_Type = 97                       /* Type  */
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
#define YYFINAL  89
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   876

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  130
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  266

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
       0,    97,    97,   123,   125,   127,   130,   131,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   150,   152,   156,   162,   168,   174,   180,   186,   192,
     198,   206,   207,   210,   213,   218,   219,   222,   223,   226,
     229,   231,   235,   236,   238,   241,   245,   245,   248,   249,
     250,   252,   256,   261,   261,   264,   269,   270,   271,   272,
     275,   276,   277,   278,   281,   282,   283,   284,   285,   288,
     289,   292,   293,   296,   297,   300,   301,   302,   303,   304,
     305,   306,   307,   309,   310,   311,   312,   314,   315,   316,
     317,   318,   319,   320,   321,   322,   324,   325,   326,   327,
     329,   330,   331,   332,   334,   335,   338,   339,   340,   341,
     342,   343,   344,   346,   347,   348,   349,   350,   351,   353,
     355,   355,   358,   360,   362,   364,   367,   369,   371,   374,
     375
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
  "FunctionDefaulValueParams", "VariableDeclaration", "Operation",
  "FunctionCall", "FunctionCallParams", "MathOperation", "StringOperation",
  "Operand", "FunctionParamOperand", "MathOperand", "StringOperand",
  "Type", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-201)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-69)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     283,   -39,   -28,    26,    95,   472,   105,     5,    32,   505,
     118,  -201,   461,  -201,  -201,  -201,    43,  -201,   125,   127,
    -201,    37,    74,   409,   582,   142,   582,   582,   193,  -201,
     219,   219,   131,  -201,  -201,  -201,  -201,  -201,  -201,  -201,
    -201,   -25,  -201,  -201,   729,   823,  -201,  -201,  -201,   182,
    -201,  -201,   558,    -2,   558,  -201,  -201,   195,   190,  -201,
    -201,     4,  -201,   147,   142,  -201,  -201,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   529,  -201,   582,   582,
    -201,  -201,   165,   582,   153,   629,   116,    23,  -201,  -201,
    -201,  -201,  -201,   197,  -201,   582,   582,   582,   582,   582,
     582,   582,   582,   582,   582,   582,   582,   582,   142,   582,
     582,   582,   582,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   582,    34,   157,   160,   -11,   227,   191,   194,
     192,  -201,   202,  -201,  -201,  -201,  -201,  -201,  -201,  -201,
    -201,  -201,  -201,  -201,   -12,   719,   639,  -201,   674,   582,
     590,  -201,   200,   517,   517,    23,    23,   101,   101,   101,
     101,   815,   815,   762,   772,   805,   153,  -201,   153,    23,
      23,    23,   729,    33,    33,   114,   114,   114,   114,   285,
     285,    38,  -201,    38,   142,    27,   472,   142,   142,   204,
     472,   558,   217,   205,   142,  -201,   582,  -201,   153,    23,
     142,  -201,   209,   247,  -201,  -201,   265,   207,  -201,   208,
    -201,   215,    21,  -201,  -201,   684,  -201,    11,   228,   472,
     558,   558,   214,   240,   221,  -201,    35,   346,  -201,   232,
    -201,    27,  -201,  -201,   -10,    -4,  -201,  -201,   223,  -201,
    -201,  -201,  -201,   346,  -201,  -201,  -201,   263,   558,   472,
     472,  -201,  -201,   123,  -201,  -201,  -201,   305,   245,   246,
      27,    27,  -201,   291,  -201,   260
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   130,   127,   122,   125,   123,     0,   128,     0,     0,
     124,     0,     0,     0,     0,     0,     0,     0,     0,     2,
       0,     0,     0,    17,    16,    15,    11,    12,    13,    14,
      10,     0,    22,   105,    69,    70,   126,   104,   119,     0,
       7,    20,     0,    68,     0,    53,    54,     0,     0,    18,
      19,   127,    38,     0,     0,   100,   103,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   129,     0,     0,
     101,   102,     0,     0,    77,     0,     0,    89,    86,     1,
       4,     3,     8,     0,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    64,     0,     0,     0,     0,     0,     0,
       0,    37,     0,    23,    24,    26,    27,    28,    29,    30,
      25,    21,    72,    74,     0,     0,     0,     6,     0,     0,
      97,   110,    66,    81,    82,    87,    88,    90,    92,    93,
      91,    94,    95,    83,    85,    84,    75,   109,    76,    78,
      79,    80,     0,   111,   112,   113,   115,   116,   114,   117,
     118,   107,   106,   108,     0,    59,     0,    47,    47,    64,
       0,     0,     0,     0,     0,    71,     0,    99,    75,    96,
       0,    65,     0,     0,    43,    42,    40,     0,    46,     0,
      51,     0,     0,    39,    73,     0,    67,     0,    58,     0,
      50,    50,     0,     0,     0,    32,     0,     0,    98,     0,
      55,    59,    41,    48,     0,     0,    52,   127,     0,   120,
     121,    36,    31,     0,    33,    56,    57,     0,     0,     0,
       0,    35,    34,    58,    49,    45,    44,     0,    62,    63,
       0,     0,    60,     0,    61,     0
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -201,  -201,   -22,    -5,    -3,   -48,  -201,  -201,    85,  -201,
    -201,  -201,    93,  -201,   132,   100,  -201,  -201,  -187,  -201,
      94,   -69,   274,     2,  -201,  -201,     1,    16,  -201,    72,
     108,  -200,   -43
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    28,    29,    30,    31,    32,    33,   226,   227,    34,
      35,    36,   206,    37,   207,   234,    38,    39,    57,    40,
     202,   246,    41,    42,    43,   144,    44,    45,   238,    46,
      47,    48,    49
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      55,    82,    56,   210,   124,   125,   128,    50,    90,    91,
     127,    63,   229,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    93,   240,    51,    84,    85,    87,    88,    52,
     223,   224,    20,    21,    22,   194,    93,   248,    94,    65,
      66,    86,    11,   248,   223,   224,   195,    16,   249,    97,
      98,    24,   188,    80,   250,    25,    23,   259,    77,    26,
      27,    76,   255,   256,    97,    98,   132,   225,    59,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   143,   145,
     146,   242,   184,    53,   148,   121,   122,   105,   106,   107,
      81,   185,   110,   111,   112,    60,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     168,   169,   170,   171,   172,   172,   172,   172,   172,   172,
     172,   172,   181,   183,   167,    95,    96,    97,    98,   173,
     174,   175,   176,   177,   178,   179,   180,   182,   113,   114,
     113,   114,   203,   211,   115,   116,   117,   118,   119,   120,
     198,   199,    54,   149,   109,   110,   111,   112,    61,    13,
      14,    15,    58,    17,    18,    19,   121,   122,   121,   122,
     231,   257,   233,   233,   151,    64,    20,    21,    22,    97,
      98,   204,    78,   205,    79,    55,   201,    56,   247,   208,
     208,   262,   264,    89,    92,    24,   214,   215,   123,    25,
     254,   129,   216,    26,    27,   244,   130,   110,   111,   112,
     131,   147,   230,   152,   204,   186,   205,   263,   263,    -5,
       1,   252,     2,   187,     3,     4,     5,     6,    -5,    -5,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,   189,    55,    55,    56,    56,   200,   190,
     192,   191,   184,    20,    21,    22,   237,    13,    14,    15,
     193,    17,   212,   218,    23,    -5,   -68,   217,   213,   219,
     220,   221,    24,   222,    20,   231,    25,   236,    50,   253,
      26,    27,   -68,    -5,     1,   241,     2,   251,     3,     4,
       5,     6,   260,   261,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,   265,   257,   113,
     114,   243,   232,   115,   116,   117,   118,    20,    21,    22,
     209,   235,    13,    14,    15,   245,    17,   126,    23,   258,
     -68,   239,     0,     0,     0,     0,    24,   121,   122,    20,
      25,     0,     0,     0,    26,    27,   -68,     1,     0,     2,
       0,     3,     4,     5,     6,    -5,    -5,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      20,    21,    22,     0,     0,     0,     0,     0,     0,     0,
       0,    23,    -5,   -68,     0,     0,     0,     0,     0,    24,
       0,     0,     0,    25,     0,     0,     0,    26,    27,   -68,
       1,     0,     2,     0,     3,     4,     5,     6,     0,     0,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    20,    21,    22,     0,     0,     0,     0,
       0,     0,     0,     0,    23,    -5,   -68,     0,     0,     0,
       0,     0,    24,     0,     0,     0,    25,     0,     0,     0,
      26,    27,   -68,     1,     0,     2,     0,     3,     4,     5,
       6,     0,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    20,    21,    22,    75,
       0,     0,     0,     0,     0,     0,     0,    23,    76,   -68,
       0,    61,    13,    14,    15,    24,    17,    18,    19,    25,
       0,     0,     0,    26,    27,   -68,     0,     0,     0,    20,
      21,    22,     0,    97,    98,    61,    13,    14,    15,     0,
      17,    18,    19,     0,     0,     0,     0,     0,    24,     0,
       0,     0,    25,    20,    21,    22,    26,    27,    62,   149,
     109,   110,   111,   112,    12,    13,    14,    15,     0,    17,
      18,    19,    24,     0,     0,     0,    25,   142,     0,     0,
      26,    27,    20,    21,    22,     0,     0,     0,    61,    13,
      14,    15,     0,     0,    18,    19,    61,    13,    14,    15,
       0,    24,    18,    19,     0,    25,    20,    21,    22,    26,
      27,     0,     0,     0,    20,    21,    22,     0,     0,     0,
       0,     0,     0,     0,     0,    24,     0,     0,     0,    83,
       0,     0,     0,    26,    27,     0,     0,    83,     0,     0,
       0,    26,    27,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,     0,     0,     0,     0,     0,   105,   106,
     107,   108,   109,   110,   111,   112,     0,   150,   105,   106,
     107,   149,   109,   110,   111,   112,     0,   197,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,     0,     0,
       0,     0,     0,   105,   106,   107,   149,   109,   110,   111,
     112,     0,   150,   105,   106,   107,   149,   109,   110,   111,
     112,     0,   228,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,     0,     0,     0,   196,     0,   105,   106,
     107,   149,   109,   110,   111,   112,     0,     0,   105,   106,
     107,   108,   109,   110,   111,   112,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,     0,     0,     0,     0,
       0,     0,   106,   107,   149,   109,   110,   111,   112,     0,
       0,     0,     0,   107,   149,   109,   110,   111,   112,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,    95,
      96,    97,    98,    99,   100,   101,   102,   113,   114,     0,
       0,   115,   116,   117,   118,   119,   120,   149,   109,   110,
     111,   112,     0,     0,     0,     0,     0,   149,   109,   110,
     111,   112,     0,     0,     0,   121,   122
};

static const yytype_int16 yycheck[] =
{
       5,    23,     5,   190,    52,    53,    54,    46,    30,    31,
      53,     9,     1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    47,   223,    63,    24,    25,    26,    27,    57,
       9,    10,    34,    35,    36,    47,    47,    47,    63,    35,
      36,    25,    15,    47,     9,    10,    58,    20,    58,    26,
      27,    53,    63,    16,    58,    57,    45,   257,    15,    61,
      62,    57,   249,   250,    26,    27,    64,    46,    63,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    78,
      79,    46,    48,    57,    83,    52,    53,    49,    50,    51,
      16,    57,    54,    55,    56,    63,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   108,    24,    25,    26,    27,   113,
     114,   115,   116,   117,   118,   119,   120,   121,    24,    25,
      24,    25,   185,   191,    28,    29,    30,    31,    32,    33,
     149,   150,    57,    52,    53,    54,    55,    56,    16,    17,
      18,    19,    57,    21,    22,    23,    52,    53,    52,    53,
      47,    48,   220,   221,    58,    57,    34,    35,    36,    26,
      27,   186,    57,   186,    57,   190,   184,   190,   231,   187,
     188,   260,   261,     0,    63,    53,   194,   196,    16,    57,
     248,     6,   200,    61,    62,   227,    16,    54,    55,    56,
      63,    46,   217,    16,   219,    58,   219,   260,   261,     0,
       1,   243,     3,    63,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    16,   249,   250,   249,   250,    48,    58,
      58,    57,    48,    34,    35,    36,    16,    17,    18,    19,
      58,    21,    45,    16,    45,    46,    47,    58,    63,     4,
      63,    63,    53,    58,    34,    47,    57,    63,    46,    16,
      61,    62,    63,     0,     1,    64,     3,    64,     5,     6,
       7,     8,    47,    47,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    16,    48,    24,
      25,   226,   219,    28,    29,    30,    31,    34,    35,    36,
     188,   221,    17,    18,    19,   231,    21,    53,    45,   257,
      47,   223,    -1,    -1,    -1,    -1,    53,    52,    53,    34,
      57,    -1,    -1,    -1,    61,    62,    63,     1,    -1,     3,
      -1,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,    53,
      -1,    -1,    -1,    57,    -1,    -1,    -1,    61,    62,    63,
       1,    -1,     3,    -1,     5,     6,     7,     8,    -1,    -1,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,    -1,    -1,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    57,    -1,    -1,    -1,
      61,    62,    63,     1,    -1,     3,    -1,     5,     6,     7,
       8,    -1,    -1,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    34,    35,    36,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    57,    47,
      -1,    16,    17,    18,    19,    53,    21,    22,    23,    57,
      -1,    -1,    -1,    61,    62,    63,    -1,    -1,    -1,    34,
      35,    36,    -1,    26,    27,    16,    17,    18,    19,    -1,
      21,    22,    23,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    57,    34,    35,    36,    61,    62,    63,    52,
      53,    54,    55,    56,    16,    17,    18,    19,    -1,    21,
      22,    23,    53,    -1,    -1,    -1,    57,    58,    -1,    -1,
      61,    62,    34,    35,    36,    -1,    -1,    -1,    16,    17,
      18,    19,    -1,    -1,    22,    23,    16,    17,    18,    19,
      -1,    53,    22,    23,    -1,    57,    34,    35,    36,    61,
      62,    -1,    -1,    -1,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    57,
      -1,    -1,    -1,    61,    62,    -1,    -1,    57,    -1,    -1,
      -1,    61,    62,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    58,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    58,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    58,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    58,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,    47,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    51,    52,    53,    54,    55,    56,    -1,
      -1,    -1,    -1,    51,    52,    53,    54,    55,    56,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    24,
      25,    26,    27,    28,    29,    30,    31,    24,    25,    -1,
      -1,    28,    29,    30,    31,    32,    33,    52,    53,    54,
      55,    56,    -1,    -1,    -1,    -1,    -1,    52,    53,    54,
      55,    56,    -1,    -1,    -1,    52,    53
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     5,     6,     7,     8,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      34,    35,    36,    45,    53,    57,    61,    62,    66,    67,
      68,    69,    70,    71,    74,    75,    76,    78,    81,    82,
      84,    87,    88,    89,    91,    92,    94,    95,    96,    97,
      46,    63,    57,    57,    57,    68,    69,    83,    57,    63,
      63,    16,    63,    88,    57,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    48,    57,    15,    57,    57,
      16,    16,    67,    57,    91,    91,    92,    91,    91,     0,
      67,    67,    63,    47,    63,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    49,    50,    51,    52,    53,
      54,    55,    56,    24,    25,    28,    29,    30,    31,    32,
      33,    52,    53,    16,    70,    70,    87,    97,    70,     6,
      16,    63,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    58,    88,    90,    91,    91,    46,    91,    52,
      58,    58,    16,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    92,    91,    91,
      91,    91,    91,    92,    92,    92,    92,    92,    92,    92,
      92,    91,    92,    91,    48,    57,    58,    63,    63,    16,
      58,    57,    58,    58,    47,    58,    47,    58,    91,    91,
      48,    88,    85,    97,    68,    69,    77,    79,    88,    79,
      83,    70,    45,    63,    88,    91,    88,    58,    16,     4,
      63,    63,    58,     9,    10,    46,    72,    73,    58,     1,
      68,    47,    77,    70,    80,    80,    63,    16,    93,    95,
      96,    64,    46,    73,    67,    85,    86,    97,    47,    58,
      58,    64,    67,    16,    70,    83,    83,    48,    94,    96,
      47,    47,    86,    97,    86,    16
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    65,    66,    67,    67,    67,    68,    68,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    71,    71,    72,    72,    73,    73,    74,    74,    75,
      76,    76,    77,    77,    78,    78,    79,    79,    80,    80,
      80,    81,    82,    83,    83,    84,    85,    85,    85,    85,
      86,    86,    86,    86,    87,    87,    87,    87,    87,    88,
      88,    89,    89,    90,    90,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      93,    93,    94,    94,    94,    94,    95,    95,    96,    97,
      97
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     0,     3,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     7,     6,     2,     3,     3,     2,     3,     2,     5,
       5,     7,     1,     1,     9,     9,     1,     0,     1,     3,
       0,     5,     7,     1,     1,     6,     4,     4,     2,     0,
       6,     6,     4,     4,     2,     4,     3,     5,     0,     1,
       1,     4,     3,     3,     1,     3,     3,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     3,     3,     2,
       3,     3,     3,     3,     3,     3,     4,     3,     6,     4,
       2,     2,     2,     2,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1
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
#line 97 "lex-yacc/parser.ypp"
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
        CompilerOrganizer::optimizeQuadruples();
        CompilerOrganizer::dumpQuadruples(true);
    } else {
        std::cout << "There Are " << CompilerOrganizer::getErrorCount()  << " Errors Found" << std::endl;
        CompilerOrganizer::exitWithFailure();
    }

    delete scopeNode;
}
#line 1523 "src/parser.tab.cpp"
    break;

  case 3: /* Sentences: Sentence Sentences  */
#line 123 "lex-yacc/parser.ypp"
                                { (yyval.Node) = (yyvsp[-1].Node)->setNext((yyvsp[0].Node)); }
#line 1529 "src/parser.tab.cpp"
    break;

  case 4: /* Sentences: Scope Sentences  */
#line 125 "lex-yacc/parser.ypp"
                                { (yyval.Node) = (yyvsp[-1].Node)->setNext((yyvsp[0].Node)); }
#line 1535 "src/parser.tab.cpp"
    break;

  case 5: /* Sentences: %empty  */
#line 127 "lex-yacc/parser.ypp"
                                { (yyval.Node) = nullptr; }
#line 1541 "src/parser.tab.cpp"
    break;

  case 6: /* Scope: SCOPE_BEGIN Sentences SCOPE_END  */
#line 130 "lex-yacc/parser.ypp"
                                          { (yyval.Node) = new ScopeNode((yyvsp[-2].data).line, (yyvsp[-1].Node)); }
#line 1547 "src/parser.tab.cpp"
    break;

  case 7: /* Scope: error SCOPE_END  */
#line 131 "lex-yacc/parser.ypp"
                                          { yyerrok; }
#line 1553 "src/parser.tab.cpp"
    break;

  case 8: /* Sentence: VariableAssignment ';'  */
#line 134 "lex-yacc/parser.ypp"
                                { (yyval.Node) = (yyvsp[-1].Node); }
#line 1559 "src/parser.tab.cpp"
    break;

  case 9: /* Sentence: VariableDeclaration ';'  */
#line 135 "lex-yacc/parser.ypp"
                                { (yyval.Node) = (yyvsp[-1].Node); }
#line 1565 "src/parser.tab.cpp"
    break;

  case 10: /* Sentence: FunctionDefinition  */
#line 136 "lex-yacc/parser.ypp"
                                { (yyval.Node) = (yyvsp[0].Node); }
#line 1571 "src/parser.tab.cpp"
    break;

  case 11: /* Sentence: IFSentence  */
#line 137 "lex-yacc/parser.ypp"
                                { (yyval.Node) = (yyvsp[0].Node); }
#line 1577 "src/parser.tab.cpp"
    break;

  case 12: /* Sentence: ForSentence  */
#line 138 "lex-yacc/parser.ypp"
                                { (yyval.Node) = (yyvsp[0].Node); }
#line 1583 "src/parser.tab.cpp"
    break;

  case 13: /* Sentence: WhileSentence  */
#line 139 "lex-yacc/parser.ypp"
                                { (yyval.Node) = (yyvsp[0].Node); }
#line 1589 "src/parser.tab.cpp"
    break;

  case 14: /* Sentence: DoWhileSentence  */
#line 140 "lex-yacc/parser.ypp"
                                { (yyval.Node) = (yyvsp[0].Node); }
#line 1595 "src/parser.tab.cpp"
    break;

  case 15: /* Sentence: PrintSentence  */
#line 141 "lex-yacc/parser.ypp"
                                { (yyval.Node) = (yyvsp[0].Node); }
#line 1601 "src/parser.tab.cpp"
    break;

  case 16: /* Sentence: ReturnSentence  */
#line 142 "lex-yacc/parser.ypp"
                                { (yyval.Node) = (yyvsp[0].Node); }
#line 1607 "src/parser.tab.cpp"
    break;

  case 17: /* Sentence: SwitchSentence  */
#line 143 "lex-yacc/parser.ypp"
                                { (yyval.Node) = (yyvsp[0].Node); }
#line 1613 "src/parser.tab.cpp"
    break;

  case 18: /* Sentence: CONTINUE ';'  */
#line 144 "lex-yacc/parser.ypp"
                                { (yyval.Node) = new ContinueNode((yyvsp[-1].data).line);}
#line 1619 "src/parser.tab.cpp"
    break;

  case 19: /* Sentence: BREAK ';'  */
#line 145 "lex-yacc/parser.ypp"
                                { (yyval.Node) = new BreakNode((yyvsp[-1].data).line);}
#line 1625 "src/parser.tab.cpp"
    break;

  case 20: /* Sentence: error ';'  */
#line 146 "lex-yacc/parser.ypp"
                                { yyerrok; (yyval.Node) = new ProgramNode(lineNumber); }
#line 1631 "src/parser.tab.cpp"
    break;

  case 21: /* VariableAssignment: IDENTIFIER '=' Operation  */
#line 150 "lex-yacc/parser.ypp"
                                  { (yyval.Node) = new AssignNode((yyvsp[-2].data).line, (yyvsp[-2].data).str, (yyvsp[0].Exp)); }
#line 1637 "src/parser.tab.cpp"
    break;

  case 22: /* VariableAssignment: Operation  */
#line 152 "lex-yacc/parser.ypp"
                {
        (yyval.Node) = new AssignNode(lineNumber, "", (yyvsp[0].Exp));
    }
#line 1645 "src/parser.tab.cpp"
    break;

  case 23: /* VariableAssignment: IDENTIFIER PLUS_EQUAL Operation  */
#line 156 "lex-yacc/parser.ypp"
                                         { 
        Expression* id = new IdentifierContainer((yyvsp[-2].data).str);
        Expression* exp = new Expression(id, (yyvsp[0].Exp), OP_ADD);
        (yyval.Node) = new AssignNode((yyvsp[-2].data).line, (yyvsp[-2].data).str, exp); 
    }
#line 1655 "src/parser.tab.cpp"
    break;

  case 24: /* VariableAssignment: IDENTIFIER MINUS_EQUAL Operation  */
#line 162 "lex-yacc/parser.ypp"
                                          { 
        Expression* id = new IdentifierContainer((yyvsp[-2].data).str);
        Expression* exp = new Expression(id, (yyvsp[0].Exp), OP_SUB);
        (yyval.Node) = new AssignNode((yyvsp[-2].data).line, (yyvsp[-2].data).str, exp); 
    }
#line 1665 "src/parser.tab.cpp"
    break;

  case 25: /* VariableAssignment: IDENTIFIER MUL_EQUAL Operation  */
#line 168 "lex-yacc/parser.ypp"
                                        { 
        Expression* id = new IdentifierContainer((yyvsp[-2].data).str);
        Expression* exp = new Expression(id, (yyvsp[0].Exp), OP_MUL);
        (yyval.Node) = new AssignNode((yyvsp[-2].data).line, (yyvsp[-2].data).str, exp); 
    }
#line 1675 "src/parser.tab.cpp"
    break;

  case 26: /* VariableAssignment: IDENTIFIER DIV_EQUAL Operation  */
#line 174 "lex-yacc/parser.ypp"
                                        { 
        Expression* id = new IdentifierContainer((yyvsp[-2].data).str);
        Expression* exp = new Expression(id, (yyvsp[0].Exp), OP_DIV);
        (yyval.Node) = new AssignNode((yyvsp[-2].data).line, (yyvsp[-2].data).str, exp); 
    }
#line 1685 "src/parser.tab.cpp"
    break;

  case 27: /* VariableAssignment: IDENTIFIER MOD_EQUAL Operation  */
#line 180 "lex-yacc/parser.ypp"
                                        { 
        Expression* id = new IdentifierContainer((yyvsp[-2].data).str);
        Expression* exp = new Expression(id, (yyvsp[0].Exp), OP_MOD);
        (yyval.Node) = new AssignNode((yyvsp[-2].data).line, (yyvsp[-2].data).str, exp); 
    }
#line 1695 "src/parser.tab.cpp"
    break;

  case 28: /* VariableAssignment: IDENTIFIER AND_EQUAL Operation  */
#line 186 "lex-yacc/parser.ypp"
                                        { 
        Expression* id = new IdentifierContainer((yyvsp[-2].data).str);
        Expression* exp = new Expression(id, (yyvsp[0].Exp), OP_AND);
        (yyval.Node) = new AssignNode((yyvsp[-2].data).line, (yyvsp[-2].data).str, exp); 
    }
#line 1705 "src/parser.tab.cpp"
    break;

  case 29: /* VariableAssignment: IDENTIFIER OR_EQUAL Operation  */
#line 192 "lex-yacc/parser.ypp"
                                       { 
        Expression* id = new IdentifierContainer((yyvsp[-2].data).str);
        Expression* exp = new Expression(id, (yyvsp[0].Exp), OP_OR);
        (yyval.Node) = new AssignNode((yyvsp[-2].data).line, (yyvsp[-2].data).str, exp); 
    }
#line 1715 "src/parser.tab.cpp"
    break;

  case 30: /* VariableAssignment: IDENTIFIER XOR_EQUAL Operation  */
#line 198 "lex-yacc/parser.ypp"
                                        { 
        Expression* id = new IdentifierContainer((yyvsp[-2].data).str);
        Expression* exp = new Expression(id, (yyvsp[0].Exp), OP_XOR);
        (yyval.Node) = new AssignNode((yyvsp[-2].data).line, (yyvsp[-2].data).str, exp); 
    }
#line 1725 "src/parser.tab.cpp"
    break;

  case 31: /* SwitchSentence: SWITCH '(' IDENTIFIER ')' SCOPE_BEGIN SwitchBody SCOPE_END  */
#line 206 "lex-yacc/parser.ypp"
                                                                 { (yyval.Node) = new SwitchNode((yyvsp[-6].data).line, (yyvsp[-4].data).str, (yyvsp[-1].SB)); }
#line 1731 "src/parser.tab.cpp"
    break;

  case 32: /* SwitchSentence: SWITCH '(' IDENTIFIER ')' SCOPE_BEGIN SCOPE_END  */
#line 207 "lex-yacc/parser.ypp"
                                                                 { (yyval.Node) = new SwitchNode((yyvsp[-5].data).line, (yyvsp[-3].data).str, nullptr); }
#line 1737 "src/parser.tab.cpp"
    break;

  case 33: /* SwitchBody: Case Sentences  */
#line 210 "lex-yacc/parser.ypp"
                                    { 
        (yyval.SB) = new SwitchBody(dynamic_cast<CaseNode*>((yyvsp[-1].Node))->assignBody((yyvsp[0].Node))); 
    }
#line 1745 "src/parser.tab.cpp"
    break;

  case 34: /* SwitchBody: SwitchBody Case Sentences  */
#line 213 "lex-yacc/parser.ypp"
                                    { 
        (yyval.SB) = dynamic_cast<SwitchBody*>((yyvsp[-2].SB))->addCase(dynamic_cast<CaseNode*>((yyvsp[-1].Node))->assignBody((yyvsp[0].Node))); 
    }
#line 1753 "src/parser.tab.cpp"
    break;

  case 35: /* Case: CASE Operand ':'  */
#line 218 "lex-yacc/parser.ypp"
                                    { (yyval.Node) = new CaseNode((yyvsp[-2].data).line, (yyvsp[-1].Exp)); }
#line 1759 "src/parser.tab.cpp"
    break;

  case 36: /* Case: DEFAULT ':'  */
#line 219 "lex-yacc/parser.ypp"
                                    { (yyval.Node) = new CaseNode((yyvsp[-1].data).line);}
#line 1765 "src/parser.tab.cpp"
    break;

  case 37: /* ReturnSentence: RETURN Operation ';'  */
#line 222 "lex-yacc/parser.ypp"
                                      { (yyval.Node) = new ReturnNode((yyvsp[-2].data).line, (yyvsp[-1].Exp));}
#line 1771 "src/parser.tab.cpp"
    break;

  case 38: /* ReturnSentence: RETURN ';'  */
#line 223 "lex-yacc/parser.ypp"
                                      { (yyval.Node) = new ReturnNode((yyvsp[-1].data).line); }
#line 1777 "src/parser.tab.cpp"
    break;

  case 39: /* PrintSentence: PRINT '(' Operation ')' ';'  */
#line 226 "lex-yacc/parser.ypp"
                                    { (yyval.Node) = new PrintNode((yyvsp[-4].data).line, (yyvsp[-2].Exp));  }
#line 1783 "src/parser.tab.cpp"
    break;

  case 40: /* IFSentence: IF '(' VariableAssignment ')' IfExtension  */
#line 229 "lex-yacc/parser.ypp"
                                                                    { (yyval.Node) = new IfNode((yyvsp[-4].data).line, dynamic_cast<AssignNode*>((yyvsp[-2].Node)), (yyvsp[0].Node));   }
#line 1789 "src/parser.tab.cpp"
    break;

  case 41: /* IFSentence: IF '(' VariableAssignment ')' IfExtension ELSE IfExtension  */
#line 231 "lex-yacc/parser.ypp"
                                                                    { (yyval.Node) = new IfNode((yyvsp[-6].data).line, dynamic_cast<AssignNode*>((yyvsp[-4].Node)), (yyvsp[-2].Node)); dynamic_cast<IfNode*>((yyval.Node))->setElse((yyvsp[0].Node));   }
#line 1795 "src/parser.tab.cpp"
    break;

  case 42: /* IfExtension: Sentence  */
#line 235 "lex-yacc/parser.ypp"
                                                                  {  (yyval.Node) = new ScopeNode(lineNumber, (yyvsp[0].Node)); }
#line 1801 "src/parser.tab.cpp"
    break;

  case 44: /* ForSentence: FOR '(' VariableDeclaration ';' ForCondition ';' ForPostSentence ')' LoopScope  */
#line 238 "lex-yacc/parser.ypp"
                                                                                            {
    (yyval.Node) = new ForNode((yyvsp[-8].data).line, (yyvsp[-6].Node), (yyvsp[-4].Exp), dynamic_cast<AssignNode*>((yyvsp[-2].Node)), dynamic_cast<ScopeNode*>((yyvsp[0].Node)));
}
#line 1809 "src/parser.tab.cpp"
    break;

  case 45: /* ForSentence: FOR '(' VariableAssignment ';' ForCondition ';' ForPostSentence ')' LoopScope  */
#line 241 "lex-yacc/parser.ypp"
                                                                                {
    (yyval.Node) = new ForNode((yyvsp[-8].data).line, (yyvsp[-6].Node), (yyvsp[-4].Exp), dynamic_cast<AssignNode*>((yyvsp[-2].Node)), dynamic_cast<ScopeNode*>((yyvsp[0].Node)));
}
#line 1817 "src/parser.tab.cpp"
    break;

  case 47: /* ForCondition: %empty  */
#line 245 "lex-yacc/parser.ypp"
                           {(yyval.Exp) = nullptr;}
#line 1823 "src/parser.tab.cpp"
    break;

  case 48: /* ForPostSentence: VariableAssignment  */
#line 248 "lex-yacc/parser.ypp"
                                                 { (yyval.Node) = (yyvsp[0].Node);  }
#line 1829 "src/parser.tab.cpp"
    break;

  case 49: /* ForPostSentence: ForPostSentence ',' VariableAssignment  */
#line 249 "lex-yacc/parser.ypp"
                                                 { (yyval.Node) = dynamic_cast<AssignNode*>((yyvsp[-2].Node))->setNextAssignment((yyvsp[0].Node)); }
#line 1835 "src/parser.tab.cpp"
    break;

  case 50: /* ForPostSentence: %empty  */
#line 250 "lex-yacc/parser.ypp"
      {(yyval.Node) = nullptr;}
#line 1841 "src/parser.tab.cpp"
    break;

  case 51: /* WhileSentence: WHILE '(' VariableAssignment ')' LoopScope  */
#line 252 "lex-yacc/parser.ypp"
                                                          {
    (yyval.Node) = new WhileNode((yyvsp[-4].data).line, dynamic_cast<AssignNode*>((yyvsp[-2].Node)), dynamic_cast<ScopeNode*>((yyvsp[0].Node)));
}
#line 1849 "src/parser.tab.cpp"
    break;

  case 52: /* DoWhileSentence: DO LoopScope WHILE '(' VariableAssignment ')' ';'  */
#line 256 "lex-yacc/parser.ypp"
                                                                   {
    (yyval.Node) = new DoWhileNode((yyvsp[-6].data).line, dynamic_cast<AssignNode*>((yyvsp[-2].Node)), dynamic_cast<ScopeNode*>((yyvsp[-5].Node)));
}
#line 1857 "src/parser.tab.cpp"
    break;

  case 54: /* LoopScope: Sentence  */
#line 261 "lex-yacc/parser.ypp"
                     { (yyval.Node) = new ScopeNode(lineNumber, (yyvsp[0].Node)); }
#line 1863 "src/parser.tab.cpp"
    break;

  case 55: /* FunctionDefinition: Type IDENTIFIER '(' FunctionParams ')' Scope  */
#line 264 "lex-yacc/parser.ypp"
                                                   { 
        (yyval.Node) = new FunctionDefintionNode((yyvsp[-4].data).line, (yyvsp[-5].DT), (yyvsp[-4].data).str, (yyvsp[-2].FP), dynamic_cast<ScopeNode*>((yyvsp[0].Node))); 
    }
#line 1871 "src/parser.tab.cpp"
    break;

  case 56: /* FunctionParams: Type IDENTIFIER ',' FunctionParams  */
#line 269 "lex-yacc/parser.ypp"
                                                                              { (yyval.FP) = (yyvsp[0].FP)->addParameter(nullptr, (yyvsp[-3].DT), (yyvsp[-2].data).str);}
#line 1877 "src/parser.tab.cpp"
    break;

  case 57: /* FunctionParams: Type IDENTIFIER ',' FunctionDefaulValueParams  */
#line 270 "lex-yacc/parser.ypp"
                                                                              { (yyval.FP) = (yyvsp[0].FP)->addParameter(nullptr, (yyvsp[-3].DT), (yyvsp[-2].data).str);}
#line 1883 "src/parser.tab.cpp"
    break;

  case 58: /* FunctionParams: Type IDENTIFIER  */
#line 271 "lex-yacc/parser.ypp"
                                                                              { (yyval.FP) = new FunctionParametersNode(nullptr, (yyvsp[-1].DT), (yyvsp[0].data).str);}
#line 1889 "src/parser.tab.cpp"
    break;

  case 59: /* FunctionParams: %empty  */
#line 272 "lex-yacc/parser.ypp"
                                                                              { (yyval.FP) = nullptr; }
#line 1895 "src/parser.tab.cpp"
    break;

  case 60: /* FunctionDefaulValueParams: Type IDENTIFIER '=' FunctionParamOperand ',' FunctionDefaulValueParams  */
#line 275 "lex-yacc/parser.ypp"
                                                                              { (yyval.FP) = (yyvsp[0].FP)->addParameter((yyvsp[-2].Exp), (yyvsp[-5].DT), (yyvsp[-4].data).str);}
#line 1901 "src/parser.tab.cpp"
    break;

  case 61: /* FunctionDefaulValueParams: Type IDENTIFIER '=' StringOperand ',' FunctionDefaulValueParams  */
#line 276 "lex-yacc/parser.ypp"
                                                                              { (yyval.FP) = (yyvsp[0].FP)->addParameter((yyvsp[-2].Exp), (yyvsp[-5].DT), (yyvsp[-4].data).str);}
#line 1907 "src/parser.tab.cpp"
    break;

  case 62: /* FunctionDefaulValueParams: Type IDENTIFIER '=' FunctionParamOperand  */
#line 277 "lex-yacc/parser.ypp"
                                                                              { (yyval.FP) = new FunctionParametersNode((yyvsp[0].Exp), (yyvsp[-3].DT), (yyvsp[-2].data).str);}
#line 1913 "src/parser.tab.cpp"
    break;

  case 63: /* FunctionDefaulValueParams: Type IDENTIFIER '=' StringOperand  */
#line 278 "lex-yacc/parser.ypp"
                                                                              { (yyval.FP) = new FunctionParametersNode((yyvsp[0].Exp), (yyvsp[-3].DT), (yyvsp[-2].data).str);}
#line 1919 "src/parser.tab.cpp"
    break;

  case 64: /* VariableDeclaration: Type IDENTIFIER  */
#line 281 "lex-yacc/parser.ypp"
                                                        { (yyval.Node) = new DefineNode((yyvsp[0].data).line, (yyvsp[-1].DT), (yyvsp[0].data).str, nullptr); }
#line 1925 "src/parser.tab.cpp"
    break;

  case 65: /* VariableDeclaration: Type IDENTIFIER '=' Operation  */
#line 282 "lex-yacc/parser.ypp"
                                                        { (yyval.Node) = new DefineNode((yyvsp[-2].data).line, (yyvsp[-3].DT), (yyvsp[-2].data).str, (yyvsp[0].Exp)); }
#line 1931 "src/parser.tab.cpp"
    break;

  case 66: /* VariableDeclaration: VariableDeclaration ',' IDENTIFIER  */
#line 283 "lex-yacc/parser.ypp"
                                                        { (yyval.Node) = dynamic_cast<DefineNode*>((yyvsp[-2].Node))->setNextDefine( new DefineNode((yyvsp[0].data).line, (yyvsp[0].data).str, nullptr) ); }
#line 1937 "src/parser.tab.cpp"
    break;

  case 67: /* VariableDeclaration: VariableDeclaration ',' IDENTIFIER '=' Operation  */
#line 284 "lex-yacc/parser.ypp"
                                                        { (yyval.Node) = dynamic_cast<DefineNode*>((yyvsp[-4].Node))->setNextDefine( new DefineNode((yyvsp[-2].data).line, (yyvsp[-2].data).str, (yyvsp[0].Exp)) ); }
#line 1943 "src/parser.tab.cpp"
    break;

  case 68: /* VariableDeclaration: %empty  */
#line 285 "lex-yacc/parser.ypp"
      {(yyval.Node) = nullptr;}
#line 1949 "src/parser.tab.cpp"
    break;

  case 71: /* FunctionCall: IDENTIFIER '(' FunctionCallParams ')'  */
#line 292 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new FunctionCallNode( (yyvsp[-3].data).line, (yyvsp[-3].data).str, (yyvsp[-1].FCP) ); }
#line 1955 "src/parser.tab.cpp"
    break;

  case 72: /* FunctionCall: IDENTIFIER '(' ')'  */
#line 293 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new FunctionCallNode( (yyvsp[-2].data).line, (yyvsp[-2].data).str, nullptr ); }
#line 1961 "src/parser.tab.cpp"
    break;

  case 73: /* FunctionCallParams: FunctionCallParams ',' Operation  */
#line 296 "lex-yacc/parser.ypp"
                                                    { (yyval.FCP) = (yyvsp[-2].FCP)->addParameter((yyvsp[0].Exp)); }
#line 1967 "src/parser.tab.cpp"
    break;

  case 74: /* FunctionCallParams: Operation  */
#line 297 "lex-yacc/parser.ypp"
                                                    { (yyval.FCP) = new FunctionCallParametersNode((yyvsp[0].Exp)); }
#line 1973 "src/parser.tab.cpp"
    break;

  case 75: /* MathOperation: MathOperation '+' MathOperation  */
#line 300 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_ADD); }
#line 1979 "src/parser.tab.cpp"
    break;

  case 76: /* MathOperation: MathOperation '-' MathOperation  */
#line 301 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_SUB); }
#line 1985 "src/parser.tab.cpp"
    break;

  case 77: /* MathOperation: '-' MathOperation  */
#line 302 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[0].Exp), (yyvsp[0].Exp), OP_UMINUS); }
#line 1991 "src/parser.tab.cpp"
    break;

  case 78: /* MathOperation: MathOperation '*' MathOperation  */
#line 303 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_MUL); }
#line 1997 "src/parser.tab.cpp"
    break;

  case 79: /* MathOperation: MathOperation '/' MathOperation  */
#line 304 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_DIV); }
#line 2003 "src/parser.tab.cpp"
    break;

  case 80: /* MathOperation: MathOperation '%' MathOperation  */
#line 305 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_MOD); }
#line 2009 "src/parser.tab.cpp"
    break;

  case 81: /* MathOperation: MathOperation SHL MathOperation  */
#line 306 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_SHL); }
#line 2015 "src/parser.tab.cpp"
    break;

  case 82: /* MathOperation: MathOperation SHR MathOperation  */
#line 307 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_SHR); }
#line 2021 "src/parser.tab.cpp"
    break;

  case 83: /* MathOperation: MathOperation '|' MathOperation  */
#line 309 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_BW_OR);}
#line 2027 "src/parser.tab.cpp"
    break;

  case 84: /* MathOperation: MathOperation '&' MathOperation  */
#line 310 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_BW_AND);}
#line 2033 "src/parser.tab.cpp"
    break;

  case 85: /* MathOperation: MathOperation '^' MathOperation  */
#line 311 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_XOR); }
#line 2039 "src/parser.tab.cpp"
    break;

  case 86: /* MathOperation: '~' MathOperation  */
#line 312 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[0].Exp), (yyvsp[0].Exp), OP_BW_NOT); }
#line 2045 "src/parser.tab.cpp"
    break;

  case 87: /* MathOperation: MathOperation AND MathOperation  */
#line 314 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_AND); }
#line 2051 "src/parser.tab.cpp"
    break;

  case 88: /* MathOperation: MathOperation OR MathOperation  */
#line 315 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_OR);  }
#line 2057 "src/parser.tab.cpp"
    break;

  case 89: /* MathOperation: '!' MathOperation  */
#line 316 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[0].Exp), (yyvsp[0].Exp), OP_NOT); }
#line 2063 "src/parser.tab.cpp"
    break;

  case 90: /* MathOperation: MathOperation GTE MathOperation  */
#line 317 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_GE);  }
#line 2069 "src/parser.tab.cpp"
    break;

  case 91: /* MathOperation: MathOperation GT MathOperation  */
#line 318 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_GT);  }
#line 2075 "src/parser.tab.cpp"
    break;

  case 92: /* MathOperation: MathOperation LTE MathOperation  */
#line 319 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_LE);  }
#line 2081 "src/parser.tab.cpp"
    break;

  case 93: /* MathOperation: MathOperation LT MathOperation  */
#line 320 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_LT);  }
#line 2087 "src/parser.tab.cpp"
    break;

  case 94: /* MathOperation: MathOperation ISEQUAL MathOperation  */
#line 321 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_EQ);  }
#line 2093 "src/parser.tab.cpp"
    break;

  case 95: /* MathOperation: MathOperation NOTEQUAL MathOperation  */
#line 322 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_NEQ); }
#line 2099 "src/parser.tab.cpp"
    break;

  case 96: /* MathOperation: '(' MathOperation ')' MathOperation  */
#line 324 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_MUL); }
#line 2105 "src/parser.tab.cpp"
    break;

  case 97: /* MathOperation: '(' MathOperation ')'  */
#line 325 "lex-yacc/parser.ypp"
                                                    {               (yyval.Exp) = (yyvsp[-1].Exp);               }
#line 2111 "src/parser.tab.cpp"
    break;

  case 98: /* MathOperation: POW '(' MathOperation ',' MathOperation ')'  */
#line 326 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-3].Exp), (yyvsp[-1].Exp), OP_POW); }
#line 2117 "src/parser.tab.cpp"
    break;

  case 99: /* MathOperation: SQRT '(' MathOperation ')'  */
#line 327 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-1].Exp), (yyvsp[-1].Exp), OP_SQRT);}
#line 2123 "src/parser.tab.cpp"
    break;

  case 100: /* MathOperation: IDENTIFIER INCREMENT  */
#line 329 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new IdentifierContainer((yyvsp[-1].data).str, OP_POST_ADD); }
#line 2129 "src/parser.tab.cpp"
    break;

  case 101: /* MathOperation: INCREMENT IDENTIFIER  */
#line 330 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new IdentifierContainer((yyvsp[0].data).str, OP_PRE_ADD); }
#line 2135 "src/parser.tab.cpp"
    break;

  case 102: /* MathOperation: DECREMENT IDENTIFIER  */
#line 331 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new IdentifierContainer((yyvsp[0].data).str, OP_PRE_SUB); }
#line 2141 "src/parser.tab.cpp"
    break;

  case 103: /* MathOperation: IDENTIFIER DECREMENT  */
#line 332 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new IdentifierContainer((yyvsp[-1].data).str, OP_POST_SUB); }
#line 2147 "src/parser.tab.cpp"
    break;

  case 106: /* StringOperation: StringOperation '+' StringOperation  */
#line 338 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) =  new StringContainer((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_ADD); }
#line 2153 "src/parser.tab.cpp"
    break;

  case 107: /* StringOperation: StringOperation '+' MathOperation  */
#line 339 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) =  new StringContainer((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_ADD); }
#line 2159 "src/parser.tab.cpp"
    break;

  case 108: /* StringOperation: StringOperation '-' MathOperation  */
#line 340 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) =  new StringContainer((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_SUB); }
#line 2165 "src/parser.tab.cpp"
    break;

  case 109: /* StringOperation: MathOperation '+' StringOperation  */
#line 341 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) =  new StringContainer((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_ADD); }
#line 2171 "src/parser.tab.cpp"
    break;

  case 110: /* StringOperation: '(' StringOperation ')'  */
#line 342 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) =  (yyvsp[-1].Exp); }
#line 2177 "src/parser.tab.cpp"
    break;

  case 111: /* StringOperation: StringOperation SHL StringOperation  */
#line 343 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) =  new StringContainer((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_SHL); }
#line 2183 "src/parser.tab.cpp"
    break;

  case 112: /* StringOperation: StringOperation SHR StringOperation  */
#line 344 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) =  new StringContainer((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_SHR); }
#line 2189 "src/parser.tab.cpp"
    break;

  case 113: /* StringOperation: StringOperation GTE StringOperation  */
#line 346 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new StringContainer((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_GE);   }
#line 2195 "src/parser.tab.cpp"
    break;

  case 114: /* StringOperation: StringOperation GT StringOperation  */
#line 347 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new StringContainer((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_GT);   }
#line 2201 "src/parser.tab.cpp"
    break;

  case 115: /* StringOperation: StringOperation LTE StringOperation  */
#line 348 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new StringContainer((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_LE);   }
#line 2207 "src/parser.tab.cpp"
    break;

  case 116: /* StringOperation: StringOperation LT StringOperation  */
#line 349 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new StringContainer((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_LT);   }
#line 2213 "src/parser.tab.cpp"
    break;

  case 117: /* StringOperation: StringOperation ISEQUAL StringOperation  */
#line 350 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new StringContainer((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_EQ);   }
#line 2219 "src/parser.tab.cpp"
    break;

  case 118: /* StringOperation: StringOperation NOTEQUAL StringOperation  */
#line 351 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new StringContainer((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_NEQ);  }
#line 2225 "src/parser.tab.cpp"
    break;

  case 122: /* FunctionParamOperand: INTEGER  */
#line 358 "lex-yacc/parser.ypp"
                        { (yyval.Exp) = new Expression((yyvsp[0].data).str, DataType::Int());}
#line 2231 "src/parser.tab.cpp"
    break;

  case 123: /* FunctionParamOperand: FLOAT  */
#line 360 "lex-yacc/parser.ypp"
                        { (yyval.Exp) = new Expression((yyvsp[0].data).str, DataType::Float());}
#line 2237 "src/parser.tab.cpp"
    break;

  case 124: /* FunctionParamOperand: CHARACTER  */
#line 362 "lex-yacc/parser.ypp"
                        { (yyval.Exp) = new Expression((yyvsp[0].data).str, DataType::Char());}
#line 2243 "src/parser.tab.cpp"
    break;

  case 125: /* FunctionParamOperand: BOOLEAN  */
#line 364 "lex-yacc/parser.ypp"
                        { (yyval.Exp) = new Expression((yyvsp[0].data).str, DataType::Bool());}
#line 2249 "src/parser.tab.cpp"
    break;

  case 127: /* MathOperand: IDENTIFIER  */
#line 369 "lex-yacc/parser.ypp"
                        { (yyval.Exp) = new IdentifierContainer((yyvsp[0].data).str); }
#line 2255 "src/parser.tab.cpp"
    break;

  case 128: /* StringOperand: STRING  */
#line 371 "lex-yacc/parser.ypp"
                        { (yyval.Exp) = new StringContainer((yyvsp[0].data).str); }
#line 2261 "src/parser.tab.cpp"
    break;

  case 129: /* Type: CONST DATA_TYPE  */
#line 374 "lex-yacc/parser.ypp"
                        { (yyval.DT) = new DataType((yyvsp[0].data).str, true);}
#line 2267 "src/parser.tab.cpp"
    break;

  case 130: /* Type: DATA_TYPE  */
#line 375 "lex-yacc/parser.ypp"
                        { (yyval.DT) = new DataType((yyvsp[0].data).str, false);}
#line 2273 "src/parser.tab.cpp"
    break;


#line 2277 "src/parser.tab.cpp"

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

#line 377 "lex-yacc/parser.ypp"



int main(int argc, char* argv[]) {
    /* yyin = fopen("test.yapl", "r"); */
    yyin = fopen(argv[1], "r");
    yyparse();
    return 0;
}
