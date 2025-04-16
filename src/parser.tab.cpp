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
  YYSYMBOL_PLUS_EQUAL = 32,                /* PLUS_EQUAL  */
  YYSYMBOL_MINUS_EQUAL = 33,               /* MINUS_EQUAL  */
  YYSYMBOL_DIV_EQUAL = 34,                 /* DIV_EQUAL  */
  YYSYMBOL_MOD_EQUAL = 35,                 /* MOD_EQUAL  */
  YYSYMBOL_AND_EQUAL = 36,                 /* AND_EQUAL  */
  YYSYMBOL_OR_EQUAL = 37,                  /* OR_EQUAL  */
  YYSYMBOL_INTEGER = 38,                   /* INTEGER  */
  YYSYMBOL_BOOLEAN = 39,                   /* BOOLEAN  */
  YYSYMBOL_XOR_EQUAL = 40,                 /* XOR_EQUAL  */
  YYSYMBOL_MUL_EQUAL = 41,                 /* MUL_EQUAL  */
  YYSYMBOL_FLOAT = 42,                     /* FLOAT  */
  YYSYMBOL_CONST = 43,                     /* CONST  */
  YYSYMBOL_PRINT = 44,                     /* PRINT  */
  YYSYMBOL_45_ = 45,                       /* ','  */
  YYSYMBOL_46_ = 46,                       /* '='  */
  YYSYMBOL_47_ = 47,                       /* '|'  */
  YYSYMBOL_48_ = 48,                       /* '^'  */
  YYSYMBOL_49_ = 49,                       /* '&'  */
  YYSYMBOL_50_ = 50,                       /* '+'  */
  YYSYMBOL_51_ = 51,                       /* '-'  */
  YYSYMBOL_52_ = 52,                       /* '*'  */
  YYSYMBOL_53_ = 53,                       /* '/'  */
  YYSYMBOL_54_ = 54,                       /* '%'  */
  YYSYMBOL_55_ = 55,                       /* '('  */
  YYSYMBOL_56_ = 56,                       /* ')'  */
  YYSYMBOL_57_ = 57,                       /* '['  */
  YYSYMBOL_58_ = 58,                       /* ']'  */
  YYSYMBOL_59_ = 59,                       /* '~'  */
  YYSYMBOL_60_ = 60,                       /* ';'  */
  YYSYMBOL_61_ = 61,                       /* '{'  */
  YYSYMBOL_62_ = 62,                       /* '}'  */
  YYSYMBOL_63_ = 63,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 64,                  /* $accept  */
  YYSYMBOL_Program = 65,                   /* Program  */
  YYSYMBOL_Sentences = 66,                 /* Sentences  */
  YYSYMBOL_Scope = 67,                     /* Scope  */
  YYSYMBOL_Sentence = 68,                  /* Sentence  */
  YYSYMBOL_SwitchSentence = 69,            /* SwitchSentence  */
  YYSYMBOL_SwitchBody = 70,                /* SwitchBody  */
  YYSYMBOL_Case = 71,                      /* Case  */
  YYSYMBOL_ReturnSentence = 72,            /* ReturnSentence  */
  YYSYMBOL_PrintSentence = 73,             /* PrintSentence  */
  YYSYMBOL_IFSentence = 74,                /* IFSentence  */
  YYSYMBOL_ForSentence = 75,               /* ForSentence  */
  YYSYMBOL_ForPostSentence = 76,           /* ForPostSentence  */
  YYSYMBOL_WhileSentence = 77,             /* WhileSentence  */
  YYSYMBOL_DoWhileSentence = 78,           /* DoWhileSentence  */
  YYSYMBOL_FunctionDefinition = 79,        /* FunctionDefinition  */
  YYSYMBOL_FunctionParams = 80,            /* FunctionParams  */
  YYSYMBOL_VariableDeclaration = 81,       /* VariableDeclaration  */
  YYSYMBOL_VariableAssignment = 82,        /* VariableAssignment  */
  YYSYMBOL_Condition = 83,                 /* Condition  */
  YYSYMBOL_Operation = 84,                 /* Operation  */
  YYSYMBOL_FunctionCall = 85,              /* FunctionCall  */
  YYSYMBOL_FunctionCallParams = 86,        /* FunctionCallParams  */
  YYSYMBOL_MathOperation = 87,             /* MathOperation  */
  YYSYMBOL_StringOperation = 88,           /* StringOperation  */
  YYSYMBOL_Operand = 89,                   /* Operand  */
  YYSYMBOL_MathOperand = 90,               /* MathOperand  */
  YYSYMBOL_StringOperand = 91,             /* StringOperand  */
  YYSYMBOL_Type = 92                       /* Type  */
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
#define YYFINAL  76
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   489

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  112
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  235

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   299


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
       2,     2,     2,     2,     2,     2,     2,    54,    49,     2,
      55,    56,    52,    50,    45,    51,     2,    53,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    63,    60,
       2,    46,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    57,     2,    58,    48,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    61,    47,    62,    59,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    73,    73,    79,    81,    83,    85,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   103,
     104,   107,   110,   115,   116,   119,   122,   127,   128,   129,
     131,   136,   137,   139,   143,   148,   153,   159,   160,   163,
     164,   165,   166,   169,   171,   175,   181,   187,   193,   199,
     205,   211,   217,   226,   227,   228,   230,   231,   232,   233,
     234,   235,   237,   238,   239,   240,   241,   242,   244,   245,
     248,   249,   250,   253,   254,   257,   258,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   275,   276,   277,   278,   279,   282,   283,   284,   285,
     286,   287,   288,   290,   290,   293,   295,   297,   299,   301,
     303,   306,   307
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
  "CHARACTER", "INCREMENT", "DECREMENT", "PLUS_EQUAL", "MINUS_EQUAL",
  "DIV_EQUAL", "MOD_EQUAL", "AND_EQUAL", "OR_EQUAL", "INTEGER", "BOOLEAN",
  "XOR_EQUAL", "MUL_EQUAL", "FLOAT", "CONST", "PRINT", "','", "'='", "'|'",
  "'^'", "'&'", "'+'", "'-'", "'*'", "'/'", "'%'", "'('", "')'", "'['",
  "']'", "'~'", "';'", "'{'", "'}'", "':'", "$accept", "Program",
  "Sentences", "Scope", "Sentence", "SwitchSentence", "SwitchBody", "Case",
  "ReturnSentence", "PrintSentence", "IFSentence", "ForSentence",
  "ForPostSentence", "WhileSentence", "DoWhileSentence",
  "FunctionDefinition", "FunctionParams", "VariableDeclaration",
  "VariableAssignment", "Condition", "Operation", "FunctionCall",
  "FunctionCallParams", "MathOperation", "StringOperation", "Operand",
  "MathOperand", "StringOperand", "Type", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-192)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     195,   242,   431,  -192,   -35,   -31,  -192,   -15,    13,    48,
      43,    52,    55,    74,  -192,    42,   138,  -192,  -192,  -192,
     131,    89,   281,   195,   146,  -192,   195,   195,  -192,  -192,
    -192,   139,  -192,  -192,  -192,  -192,   -27,    92,  -192,  -192,
     391,    20,  -192,  -192,   161,   -16,   106,  -192,  -192,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   237,   300,
     300,   223,   223,    35,   160,   171,  -192,  -192,  -192,  -192,
    -192,   242,    -4,    72,    23,   121,  -192,  -192,  -192,    -1,
     181,  -192,  -192,   300,   300,   300,   300,   300,   300,   300,
     300,   300,   300,    11,    11,   281,   300,   -25,  -192,  -192,
    -192,  -192,  -192,  -192,  -192,  -192,  -192,  -192,  -192,  -192,
     -37,   300,   383,   309,   223,    -9,   368,   438,    19,    90,
     189,   141,   147,   151,   300,  -192,  -192,  -192,   139,   148,
     137,   137,   162,   344,   373,   205,   205,  -192,  -192,  -192,
      11,    33,    33,    84,  -192,    84,   242,    -7,   242,  -192,
     300,  -192,    28,   223,   223,    43,   300,   300,   300,   300,
     300,   300,    11,    11,    11,    11,    11,    11,    43,   223,
     175,   223,   136,   157,  -192,   242,  -192,    43,    40,   227,
    -192,   319,    28,    28,  -192,   391,   391,   391,   391,   391,
     391,    20,    20,    20,    20,    20,    20,  -192,     7,    26,
     -14,  -192,  -192,  -192,    35,    43,  -192,  -192,   295,   172,
     101,   173,  -192,    86,   195,   231,  -192,    57,  -192,  -192,
    -192,   177,  -192,  -192,  -192,  -192,   195,  -192,  -192,   295,
      43,  -192,  -192,  -192,  -192
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,   109,   110,     0,     0,   112,     0,     0,     0,
       0,     0,     0,     0,   107,     0,     0,   105,   108,   106,
       0,     0,     0,     5,     0,     2,     5,     5,    16,    15,
      14,    10,    11,    12,    13,     9,     0,     0,    44,    72,
      70,    71,    95,   102,     0,   109,     0,    91,    94,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    17,    18,    92,    93,
     111,     0,   109,     0,     0,     0,     1,     4,     3,     0,
       0,     8,     7,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    39,    25,    45,
      46,    48,    49,    50,    51,    52,    47,    43,    74,    76,
       0,     0,     0,     0,     0,     0,    68,    69,     0,     0,
       0,     0,     0,     0,    83,    99,     6,    29,    28,    41,
      86,    87,    88,    90,    89,    77,    78,    79,    80,    81,
       0,   100,   101,    97,    96,    98,     0,     0,     0,    73,
       0,    85,    55,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      39,     0,     0,     0,    82,     0,    40,     0,     0,     0,
      75,     0,    54,    53,    27,    56,    58,    59,    57,    60,
      61,    62,    64,    65,    63,    66,    67,    33,     0,     0,
       0,    26,    42,    36,     0,     0,    38,    84,     0,     0,
       0,     0,    20,     0,     5,     0,    35,     0,    31,    34,
     109,     0,   103,   104,    24,    19,     5,    21,    37,     0,
       0,    23,    22,    32,    30
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -192,  -192,   -22,   -10,  -192,  -192,  -192,    32,  -192,  -192,
     176,  -192,  -192,  -192,  -192,  -192,  -192,   188,  -191,   -53,
       1,  -192,  -192,     3,    15,  -192,    50,    53,   -50
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    24,    25,    26,    27,    28,   213,   214,    29,    30,
      31,    32,   217,    33,    34,    35,   178,    36,    37,   115,
      38,    39,   110,    40,    41,   221,    42,    43,    44
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      64,    75,    46,     6,    77,    78,   153,   154,   148,   118,
       7,   210,   211,   120,    47,    48,     3,   218,    80,   149,
      59,   146,   153,   154,    60,    73,    47,    48,    93,    94,
     147,    93,    94,    81,   153,   154,    20,    74,   233,    58,
      61,   153,   154,   153,   154,     6,    68,   155,   212,   177,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   109,
      23,   152,   112,   113,   116,   116,   140,   208,    62,   127,
      95,    96,   123,    95,    96,   168,   117,   117,    20,   125,
      83,    84,   209,    95,    96,   204,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   205,   179,   143,   145,
     182,   183,   229,    63,    23,   220,     3,    65,   141,   142,
     144,   210,   211,   230,    73,    66,   198,   116,   199,    85,
      86,    87,    88,    89,    90,    91,    92,   174,   124,   117,
      14,    85,    86,    87,    67,    80,    90,    91,    92,    17,
      18,    70,    69,    19,    71,   184,    76,   176,   225,   180,
     169,    79,    82,   181,   215,    74,   116,   116,   197,   185,
     186,   187,   188,   189,   190,    97,    98,   203,   117,   117,
      83,    84,   116,   121,   116,   122,   202,   191,   192,   193,
     194,   195,   196,   126,   117,   129,   117,    88,    89,    90,
      91,    92,   227,   170,   175,   216,   171,   200,     1,     2,
       3,     4,     5,   172,   232,     6,     7,   173,     8,     9,
      86,    87,    88,    89,    90,    91,    92,   201,    10,    11,
     234,   146,    12,    13,    14,    15,    16,    72,     3,     4,
       5,   206,   219,    17,    18,   228,   224,    19,    20,    21,
     231,    45,     3,     4,     5,   226,    45,     3,     4,     5,
      22,   119,    14,    15,    16,   128,    23,    90,    91,    92,
     222,    17,    18,   223,     0,    19,    14,    15,    16,     0,
       0,    14,    15,    16,     0,    17,    18,     0,    22,    19,
      17,    18,   114,     0,    19,    72,     3,     4,     5,     0,
       0,     0,    22,   108,     0,     0,     0,    22,     0,     2,
       3,     4,     5,     0,    72,     0,     4,     5,     0,     0,
      14,    15,    16,     0,     0,     0,     0,    83,    84,    17,
      18,     0,     0,    19,    14,    15,    16,    83,    84,    14,
      15,    16,     0,    17,    18,     0,    22,    19,    17,    18,
       0,     0,    19,     0,     0,     0,     0,     0,     0,     0,
      22,     0,    83,    84,     0,   111,    85,    86,    87,    88,
      89,    90,    91,    92,     0,   151,    85,    86,    87,    88,
      89,    90,    91,    92,     0,   207,    83,    84,     0,     0,
       0,    83,    84,     0,     0,   156,   157,   158,   159,   160,
     161,    83,    84,    87,    88,    89,    90,    91,    92,    83,
      84,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    85,    86,    87,    88,    89,
      90,    91,    92,    88,    89,    90,    91,    92,   150,     0,
      85,    86,    87,    88,    89,    90,    91,    92,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,     0,     0,
       0,     0,     0,     0,     0,   162,   163,   164,   165,   166,
     167,    47,    48,    49,    50,    51,    52,    53,    54,     0,
       0,    55,    56,     0,     0,     0,     0,    57,     0,     0,
       0,     0,     0,     0,     0,     0,    58,     0,    95,    96
};

static const yytype_int16 yycheck[] =
{
      10,    23,     1,    10,    26,    27,    15,    16,    45,    62,
      11,    25,    26,    63,    30,    31,     5,   208,    45,    56,
      55,    46,    15,    16,    55,    22,    30,    31,     8,     9,
      55,     8,     9,    60,    15,    16,    43,    22,   229,    55,
      55,    15,    16,    15,    16,    10,     4,    56,    62,    56,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      61,   114,    59,    60,    61,    62,    55,    60,    55,    79,
      50,    51,    71,    50,    51,    56,    61,    62,    43,    56,
       8,     9,    56,    50,    51,    45,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    56,   147,    95,    96,
     153,   154,    45,    55,    61,     4,     5,    55,    93,    94,
      95,    25,    26,    56,   111,    60,   169,   114,   171,    47,
      48,    49,    50,    51,    52,    53,    54,   124,    56,   114,
      29,    47,    48,    49,    60,    45,    52,    53,    54,    38,
      39,    10,     4,    42,    55,   155,     0,   146,    62,   148,
      60,    12,    60,   150,   204,   140,   153,   154,   168,   156,
     157,   158,   159,   160,   161,     4,    60,   177,   153,   154,
       8,     9,   169,    13,   171,     4,   175,   162,   163,   164,
     165,   166,   167,    62,   169,     4,   171,    50,    51,    52,
      53,    54,   214,     4,    46,   205,    55,    61,     3,     4,
       5,     6,     7,    56,   226,    10,    11,    56,    13,    14,
      48,    49,    50,    51,    52,    53,    54,    60,    23,    24,
     230,    46,    27,    28,    29,    30,    31,     4,     5,     6,
       7,     4,    60,    38,    39,     4,    63,    42,    43,    44,
      63,     4,     5,     6,     7,   213,     4,     5,     6,     7,
      55,    63,    29,    30,    31,    79,    61,    52,    53,    54,
     210,    38,    39,   210,    -1,    42,    29,    30,    31,    -1,
      -1,    29,    30,    31,    -1,    38,    39,    -1,    55,    42,
      38,    39,    59,    -1,    42,     4,     5,     6,     7,    -1,
      -1,    -1,    55,    56,    -1,    -1,    -1,    55,    -1,     4,
       5,     6,     7,    -1,     4,    -1,     6,     7,    -1,    -1,
      29,    30,    31,    -1,    -1,    -1,    -1,     8,     9,    38,
      39,    -1,    -1,    42,    29,    30,    31,     8,     9,    29,
      30,    31,    -1,    38,    39,    -1,    55,    42,    38,    39,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      55,    -1,     8,     9,    -1,    55,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    56,    47,    48,    49,    50,
      51,    52,    53,    54,    -1,    56,     8,     9,    -1,    -1,
      -1,     8,     9,    -1,    -1,    17,    18,    19,    20,    21,
      22,     8,     9,    49,    50,    51,    52,    53,    54,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    47,    48,    49,    50,    51,
      52,    53,    54,    50,    51,    52,    53,    54,    45,    -1,
      47,    48,    49,    50,    51,    52,    53,    54,    47,    48,
      49,    50,    51,    52,    53,    54,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    18,    19,    20,    21,
      22,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      -1,    40,    41,    -1,    -1,    -1,    -1,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,    50,    51
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    10,    11,    13,    14,
      23,    24,    27,    28,    29,    30,    31,    38,    39,    42,
      43,    44,    55,    61,    65,    66,    67,    68,    69,    72,
      73,    74,    75,    77,    78,    79,    81,    82,    84,    85,
      87,    88,    90,    91,    92,     4,    84,    30,    31,    32,
      33,    34,    35,    36,    37,    40,    41,    46,    55,    55,
      55,    55,    55,    55,    67,    55,    60,    60,     4,     4,
      10,    55,     4,    87,    88,    66,     0,    66,    66,    12,
      45,    60,    60,     8,     9,    47,    48,    49,    50,    51,
      52,    53,    54,     8,     9,    50,    51,     4,    60,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    56,    84,
      86,    55,    87,    87,    59,    83,    87,    88,    83,    81,
      92,    13,     4,    84,    56,    56,    62,    67,    74,     4,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      55,    88,    88,    87,    88,    87,    46,    55,    45,    56,
      45,    56,    83,    15,    16,    56,    17,    18,    19,    20,
      21,    22,    17,    18,    19,    20,    21,    22,    56,    60,
       4,    55,    56,    56,    87,    46,    84,    56,    80,    92,
      84,    87,    83,    83,    67,    87,    87,    87,    87,    87,
      87,    88,    88,    88,    88,    88,    88,    67,    83,    83,
      61,    60,    84,    67,    45,    56,     4,    56,    60,    56,
      25,    26,    62,    70,    71,    92,    67,    76,    82,    60,
       4,    89,    90,    91,    63,    62,    71,    66,     4,    45,
      56,    63,    66,    82,    67
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    64,    65,    66,    66,    66,    67,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    69,
      69,    70,    70,    71,    71,    72,    73,    74,    74,    74,
      75,    76,    76,    77,    78,    79,    79,    80,    80,    81,
      81,    81,    81,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    83,    83,    83,    83,    83,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      84,    84,    84,    85,    85,    86,    86,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    88,    88,    88,    88,
      88,    88,    88,    89,    89,    90,    90,    90,    90,    90,
      91,    92,    92
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     0,     3,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     7,
       6,     2,     3,     3,     2,     3,     5,     5,     3,     3,
       9,     1,     3,     5,     7,     6,     5,     4,     2,     2,
       4,     3,     5,     3,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     1,     4,     3,     3,     1,     3,     3,     3,
       3,     3,     4,     3,     6,     4,     3,     3,     3,     3,
       3,     2,     2,     2,     2,     1,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1
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
#line 73 "lex-yacc/parser.ypp"
                    {
    ScopeNode* scopeNode = new ScopeNode((yyvsp[0].Node));
    scopeNode->run();
}
#line 1382 "src/parser.tab.cpp"
    break;

  case 3: /* Sentences: Sentence Sentences  */
#line 79 "lex-yacc/parser.ypp"
                                { (yyval.Node) = (yyvsp[-1].Node)->setNext((yyvsp[0].Node)); }
#line 1388 "src/parser.tab.cpp"
    break;

  case 4: /* Sentences: Scope Sentences  */
#line 81 "lex-yacc/parser.ypp"
                                { (yyval.Node) = (yyvsp[-1].Node)->setNext((yyvsp[0].Node)); }
#line 1394 "src/parser.tab.cpp"
    break;

  case 5: /* Sentences: %empty  */
#line 83 "lex-yacc/parser.ypp"
                                { (yyval.Node) = nullptr; }
#line 1400 "src/parser.tab.cpp"
    break;

  case 6: /* Scope: '{' Sentences '}'  */
#line 85 "lex-yacc/parser.ypp"
                                { (yyval.Node) = new ScopeNode((yyvsp[-1].Node)); }
#line 1406 "src/parser.tab.cpp"
    break;

  case 7: /* Sentence: VariableAssignment ';'  */
#line 89 "lex-yacc/parser.ypp"
                                { (yyval.Node) = (yyvsp[-1].Node); }
#line 1412 "src/parser.tab.cpp"
    break;

  case 8: /* Sentence: VariableDeclaration ';'  */
#line 90 "lex-yacc/parser.ypp"
                                    { (yyval.Node) = (yyvsp[-1].Node); }
#line 1418 "src/parser.tab.cpp"
    break;

  case 9: /* Sentence: FunctionDefinition  */
#line 91 "lex-yacc/parser.ypp"
                                { (yyval.Node) = (yyvsp[0].Node); }
#line 1424 "src/parser.tab.cpp"
    break;

  case 10: /* Sentence: IFSentence  */
#line 92 "lex-yacc/parser.ypp"
                                { (yyval.Node) = (yyvsp[0].Node); }
#line 1430 "src/parser.tab.cpp"
    break;

  case 11: /* Sentence: ForSentence  */
#line 93 "lex-yacc/parser.ypp"
                                { (yyval.Node) = (yyvsp[0].Node); }
#line 1436 "src/parser.tab.cpp"
    break;

  case 12: /* Sentence: WhileSentence  */
#line 94 "lex-yacc/parser.ypp"
                                { (yyval.Node) = (yyvsp[0].Node); }
#line 1442 "src/parser.tab.cpp"
    break;

  case 13: /* Sentence: DoWhileSentence  */
#line 95 "lex-yacc/parser.ypp"
                                { (yyval.Node) = (yyvsp[0].Node); }
#line 1448 "src/parser.tab.cpp"
    break;

  case 14: /* Sentence: PrintSentence  */
#line 96 "lex-yacc/parser.ypp"
                                { (yyval.Node) = (yyvsp[0].Node); }
#line 1454 "src/parser.tab.cpp"
    break;

  case 15: /* Sentence: ReturnSentence  */
#line 97 "lex-yacc/parser.ypp"
                                { (yyval.Node) = (yyvsp[0].Node); }
#line 1460 "src/parser.tab.cpp"
    break;

  case 16: /* Sentence: SwitchSentence  */
#line 98 "lex-yacc/parser.ypp"
                                { (yyval.Node) = (yyvsp[0].Node); }
#line 1466 "src/parser.tab.cpp"
    break;

  case 17: /* Sentence: CONTINUE ';'  */
#line 99 "lex-yacc/parser.ypp"
                                { (yyval.Node) = new ContinueNode();}
#line 1472 "src/parser.tab.cpp"
    break;

  case 18: /* Sentence: BREAK ';'  */
#line 100 "lex-yacc/parser.ypp"
                                { (yyval.Node) = new BreakNode();}
#line 1478 "src/parser.tab.cpp"
    break;

  case 19: /* SwitchSentence: SWITCH '(' IDENTIFIER ')' '{' SwitchBody '}'  */
#line 103 "lex-yacc/parser.ypp"
                                                   { (yyval.Node) = new SwitchNode((yyvsp[-4].str), (yyvsp[-1].SB)); }
#line 1484 "src/parser.tab.cpp"
    break;

  case 20: /* SwitchSentence: SWITCH '(' IDENTIFIER ')' '{' '}'  */
#line 104 "lex-yacc/parser.ypp"
                                                   { (yyval.Node) = new SwitchNode((yyvsp[-3].str), nullptr); }
#line 1490 "src/parser.tab.cpp"
    break;

  case 21: /* SwitchBody: Case Sentences  */
#line 107 "lex-yacc/parser.ypp"
                                    { 
        (yyval.SB) = new SwitchBody(dynamic_cast<CaseNode*>((yyvsp[-1].Node))->assignBody((yyvsp[0].Node))); 
    }
#line 1498 "src/parser.tab.cpp"
    break;

  case 22: /* SwitchBody: SwitchBody Case Sentences  */
#line 110 "lex-yacc/parser.ypp"
                                    { 
        (yyval.SB) = dynamic_cast<SwitchBody*>((yyvsp[-2].SB))->addCase(dynamic_cast<CaseNode*>((yyvsp[-1].Node))->assignBody((yyvsp[0].Node))); 
    }
#line 1506 "src/parser.tab.cpp"
    break;

  case 23: /* Case: CASE Operand ':'  */
#line 115 "lex-yacc/parser.ypp"
                                    { (yyval.Node) = new CaseNode((yyvsp[-1].Exp)); }
#line 1512 "src/parser.tab.cpp"
    break;

  case 24: /* Case: DEFAULT ':'  */
#line 116 "lex-yacc/parser.ypp"
                                    { (yyval.Node) = new CaseNode();}
#line 1518 "src/parser.tab.cpp"
    break;

  case 25: /* ReturnSentence: RETURN Operation ';'  */
#line 119 "lex-yacc/parser.ypp"
                                    { (yyval.Node) = new ReturnNode((yyvsp[-1].Exp));}
#line 1524 "src/parser.tab.cpp"
    break;

  case 26: /* PrintSentence: PRINT '(' Operation ')' ';'  */
#line 122 "lex-yacc/parser.ypp"
                                    {
                                        (yyval.Node) = new PrintNode((yyvsp[-2].Exp));
                                    }
#line 1532 "src/parser.tab.cpp"
    break;

  case 27: /* IFSentence: IF '(' Condition ')' Scope  */
#line 127 "lex-yacc/parser.ypp"
                                   { (yyval.Node) = new IfNode((yyvsp[-2].Exp), (yyvsp[0].Node));   }
#line 1538 "src/parser.tab.cpp"
    break;

  case 28: /* IFSentence: IFSentence ELSE IFSentence  */
#line 128 "lex-yacc/parser.ypp"
                                   { (yyval.Node) = dynamic_cast<IfNode*>((yyvsp[-2].Node))->setElse((yyvsp[0].Node));  }
#line 1544 "src/parser.tab.cpp"
    break;

  case 29: /* IFSentence: IFSentence ELSE Scope  */
#line 129 "lex-yacc/parser.ypp"
                                   { (yyval.Node) = dynamic_cast<IfNode*>((yyvsp[-2].Node))->setElse((yyvsp[0].Node));  }
#line 1550 "src/parser.tab.cpp"
    break;

  case 30: /* ForSentence: FOR '(' VariableDeclaration ';' Condition ';' ForPostSentence ')' Scope  */
#line 131 "lex-yacc/parser.ypp"
                                                                                     {
    (yyval.Node) = new ForNode(dynamic_cast<DefineNode*>((yyvsp[-6].Node)), (yyvsp[-4].Exp), dynamic_cast<AssignNode*>((yyvsp[-2].Node)), dynamic_cast<ScopeNode*>((yyvsp[0].Node)));
}
#line 1558 "src/parser.tab.cpp"
    break;

  case 31: /* ForPostSentence: VariableAssignment  */
#line 136 "lex-yacc/parser.ypp"
                                                 { (yyval.Node) = (yyvsp[0].Node);  }
#line 1564 "src/parser.tab.cpp"
    break;

  case 32: /* ForPostSentence: ForPostSentence ',' VariableAssignment  */
#line 137 "lex-yacc/parser.ypp"
                                                 { (yyval.Node) = dynamic_cast<AssignNode*>((yyvsp[-2].Node))->setNextAssignment((yyvsp[0].Node)); }
#line 1570 "src/parser.tab.cpp"
    break;

  case 33: /* WhileSentence: WHILE '(' Condition ')' Scope  */
#line 139 "lex-yacc/parser.ypp"
                                             {
    (yyval.Node) = new WhileNode((yyvsp[-2].Exp), dynamic_cast<ScopeNode*>((yyvsp[0].Node)));
}
#line 1578 "src/parser.tab.cpp"
    break;

  case 34: /* DoWhileSentence: DO Scope WHILE '(' Condition ')' ';'  */
#line 143 "lex-yacc/parser.ypp"
                                                      {
    (yyval.Node) = new DoWhileNode((yyvsp[-2].Exp), dynamic_cast<ScopeNode*>((yyvsp[-5].Node)));
}
#line 1586 "src/parser.tab.cpp"
    break;

  case 35: /* FunctionDefinition: Type IDENTIFIER '(' FunctionParams ')' Scope  */
#line 148 "lex-yacc/parser.ypp"
                                                   { 
        dynamic_cast<ScopeNode*>((yyvsp[0].Node))->returnable = true;
        (yyval.Node) = new FunctionDefintionNode((yyvsp[-5].DT), (yyvsp[-4].str), (yyvsp[-2].FP), dynamic_cast<ScopeNode*>((yyvsp[0].Node))); 
    }
#line 1595 "src/parser.tab.cpp"
    break;

  case 36: /* FunctionDefinition: Type IDENTIFIER '(' ')' Scope  */
#line 153 "lex-yacc/parser.ypp"
                                                   { 
        dynamic_cast<ScopeNode*>((yyvsp[0].Node))->returnable = true;
        (yyval.Node) = new FunctionDefintionNode((yyvsp[-4].DT), (yyvsp[-3].str), nullptr, dynamic_cast<ScopeNode*>((yyvsp[0].Node))); 
    }
#line 1604 "src/parser.tab.cpp"
    break;

  case 37: /* FunctionParams: FunctionParams ',' Type IDENTIFIER  */
#line 159 "lex-yacc/parser.ypp"
                                                        { (yyval.FP) = (yyvsp[-3].FP)->addParameter((yyvsp[-1].DT), (yyvsp[0].str));}
#line 1610 "src/parser.tab.cpp"
    break;

  case 38: /* FunctionParams: Type IDENTIFIER  */
#line 160 "lex-yacc/parser.ypp"
                                                        { (yyval.FP) = new FunctionParametersNode((yyvsp[-1].DT), (yyvsp[0].str));}
#line 1616 "src/parser.tab.cpp"
    break;

  case 39: /* VariableDeclaration: Type IDENTIFIER  */
#line 163 "lex-yacc/parser.ypp"
                                                        { (yyval.Node) = new DefineNode((yyvsp[-1].DT), (yyvsp[0].str), nullptr); }
#line 1622 "src/parser.tab.cpp"
    break;

  case 40: /* VariableDeclaration: Type IDENTIFIER '=' Operation  */
#line 164 "lex-yacc/parser.ypp"
                                                        { (yyval.Node) = new DefineNode((yyvsp[-3].DT), (yyvsp[-2].str), (yyvsp[0].Exp)); }
#line 1628 "src/parser.tab.cpp"
    break;

  case 41: /* VariableDeclaration: VariableDeclaration ',' IDENTIFIER  */
#line 165 "lex-yacc/parser.ypp"
                                                        { (yyval.Node) = dynamic_cast<DefineNode*>((yyvsp[-2].Node))->setNextDefine( new DefineNode((yyvsp[0].str), nullptr) ); }
#line 1634 "src/parser.tab.cpp"
    break;

  case 42: /* VariableDeclaration: VariableDeclaration ',' IDENTIFIER '=' Operation  */
#line 166 "lex-yacc/parser.ypp"
                                                        { (yyval.Node) = dynamic_cast<DefineNode*>((yyvsp[-4].Node))->setNextDefine( new DefineNode((yyvsp[-2].str), (yyvsp[0].Exp)) ); }
#line 1640 "src/parser.tab.cpp"
    break;

  case 43: /* VariableAssignment: IDENTIFIER '=' Operation  */
#line 169 "lex-yacc/parser.ypp"
                                      { (yyval.Node) = new AssignNode((yyvsp[-2].str), (yyvsp[0].Exp)); }
#line 1646 "src/parser.tab.cpp"
    break;

  case 44: /* VariableAssignment: Operation  */
#line 171 "lex-yacc/parser.ypp"
                {
        (yyval.Node) = new AssignNode("", (yyvsp[0].Exp));
    }
#line 1654 "src/parser.tab.cpp"
    break;

  case 45: /* VariableAssignment: IDENTIFIER PLUS_EQUAL Operation  */
#line 175 "lex-yacc/parser.ypp"
                                         { 
        Expression* id = new IdentifierContainer((yyvsp[-2].str));
        Expression* exp = new Expression(id, (yyvsp[0].Exp), OP_ADD);
        (yyval.Node) = new AssignNode((yyvsp[-2].str), exp); 
    }
#line 1664 "src/parser.tab.cpp"
    break;

  case 46: /* VariableAssignment: IDENTIFIER MINUS_EQUAL Operation  */
#line 181 "lex-yacc/parser.ypp"
                                          { 
        Expression* id = new IdentifierContainer((yyvsp[-2].str));
        Expression* exp = new Expression(id, (yyvsp[0].Exp), OP_SUB);
        (yyval.Node) = new AssignNode((yyvsp[-2].str), exp); 
    }
#line 1674 "src/parser.tab.cpp"
    break;

  case 47: /* VariableAssignment: IDENTIFIER MUL_EQUAL Operation  */
#line 187 "lex-yacc/parser.ypp"
                                        { 
        Expression* id = new IdentifierContainer((yyvsp[-2].str));
        Expression* exp = new Expression(id, (yyvsp[0].Exp), OP_MUL);
        (yyval.Node) = new AssignNode((yyvsp[-2].str), exp); 
    }
#line 1684 "src/parser.tab.cpp"
    break;

  case 48: /* VariableAssignment: IDENTIFIER DIV_EQUAL Operation  */
#line 193 "lex-yacc/parser.ypp"
                                        { 
        Expression* id = new IdentifierContainer((yyvsp[-2].str));
        Expression* exp = new Expression(id, (yyvsp[0].Exp), OP_DIV);
        (yyval.Node) = new AssignNode((yyvsp[-2].str), exp); 
    }
#line 1694 "src/parser.tab.cpp"
    break;

  case 49: /* VariableAssignment: IDENTIFIER MOD_EQUAL Operation  */
#line 199 "lex-yacc/parser.ypp"
                                        { 
        Expression* id = new IdentifierContainer((yyvsp[-2].str));
        Expression* exp = new Expression(id, (yyvsp[0].Exp), OP_MOD);
        (yyval.Node) = new AssignNode((yyvsp[-2].str), exp); 
    }
#line 1704 "src/parser.tab.cpp"
    break;

  case 50: /* VariableAssignment: IDENTIFIER AND_EQUAL Operation  */
#line 205 "lex-yacc/parser.ypp"
                                        { 
        Expression* id = new IdentifierContainer((yyvsp[-2].str));
        Expression* exp = new Expression(id, (yyvsp[0].Exp), OP_AND);
        (yyval.Node) = new AssignNode((yyvsp[-2].str), exp); 
    }
#line 1714 "src/parser.tab.cpp"
    break;

  case 51: /* VariableAssignment: IDENTIFIER OR_EQUAL Operation  */
#line 211 "lex-yacc/parser.ypp"
                                       { 
        Expression* id = new IdentifierContainer((yyvsp[-2].str));
        Expression* exp = new Expression(id, (yyvsp[0].Exp), OP_OR);
        (yyval.Node) = new AssignNode((yyvsp[-2].str), exp); 
    }
#line 1724 "src/parser.tab.cpp"
    break;

  case 52: /* VariableAssignment: IDENTIFIER XOR_EQUAL Operation  */
#line 217 "lex-yacc/parser.ypp"
                                        { 
        Expression* id = new IdentifierContainer((yyvsp[-2].str));
        Expression* exp = new Expression(id, (yyvsp[0].Exp), OP_XOR);
        (yyval.Node) = new AssignNode((yyvsp[-2].str), exp); 
    }
#line 1734 "src/parser.tab.cpp"
    break;

  case 53: /* Condition: Condition OR Condition  */
#line 226 "lex-yacc/parser.ypp"
                                                      { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_OR);  }
#line 1740 "src/parser.tab.cpp"
    break;

  case 54: /* Condition: Condition AND Condition  */
#line 227 "lex-yacc/parser.ypp"
                                                      { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_AND); }
#line 1746 "src/parser.tab.cpp"
    break;

  case 55: /* Condition: '~' Condition  */
#line 228 "lex-yacc/parser.ypp"
                                                      { (yyval.Exp) = new Expression((yyvsp[0].Exp), (yyvsp[0].Exp), OP_NOT); }
#line 1752 "src/parser.tab.cpp"
    break;

  case 56: /* Condition: MathOperation GTE MathOperation  */
#line 230 "lex-yacc/parser.ypp"
                                                        { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_GE);  }
#line 1758 "src/parser.tab.cpp"
    break;

  case 57: /* Condition: MathOperation GT MathOperation  */
#line 231 "lex-yacc/parser.ypp"
                                                        { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_GT);  }
#line 1764 "src/parser.tab.cpp"
    break;

  case 58: /* Condition: MathOperation LTE MathOperation  */
#line 232 "lex-yacc/parser.ypp"
                                                        { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_LE);  }
#line 1770 "src/parser.tab.cpp"
    break;

  case 59: /* Condition: MathOperation LT MathOperation  */
#line 233 "lex-yacc/parser.ypp"
                                                        { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_LT);  }
#line 1776 "src/parser.tab.cpp"
    break;

  case 60: /* Condition: MathOperation ISEQUAL MathOperation  */
#line 234 "lex-yacc/parser.ypp"
                                                        { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_EQ);  }
#line 1782 "src/parser.tab.cpp"
    break;

  case 61: /* Condition: MathOperation NOTEQUAL MathOperation  */
#line 235 "lex-yacc/parser.ypp"
                                                        { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_NEQ); }
#line 1788 "src/parser.tab.cpp"
    break;

  case 62: /* Condition: StringOperation GTE StringOperation  */
#line 237 "lex-yacc/parser.ypp"
                                                           { (yyval.Exp) = new StringContainer((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_GE);   }
#line 1794 "src/parser.tab.cpp"
    break;

  case 63: /* Condition: StringOperation GT StringOperation  */
#line 238 "lex-yacc/parser.ypp"
                                                           { (yyval.Exp) = new StringContainer((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_GT);   }
#line 1800 "src/parser.tab.cpp"
    break;

  case 64: /* Condition: StringOperation LTE StringOperation  */
#line 239 "lex-yacc/parser.ypp"
                                                           { (yyval.Exp) = new StringContainer((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_LE);   }
#line 1806 "src/parser.tab.cpp"
    break;

  case 65: /* Condition: StringOperation LT StringOperation  */
#line 240 "lex-yacc/parser.ypp"
                                                           { (yyval.Exp) = new StringContainer((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_LT);   }
#line 1812 "src/parser.tab.cpp"
    break;

  case 66: /* Condition: StringOperation ISEQUAL StringOperation  */
#line 241 "lex-yacc/parser.ypp"
                                                           { (yyval.Exp) = new StringContainer((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_EQ);   }
#line 1818 "src/parser.tab.cpp"
    break;

  case 67: /* Condition: StringOperation NOTEQUAL StringOperation  */
#line 242 "lex-yacc/parser.ypp"
                                                           { (yyval.Exp) = new StringContainer((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_NEQ);  }
#line 1824 "src/parser.tab.cpp"
    break;

  case 68: /* Condition: MathOperation  */
#line 244 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = (yyvsp[0].Exp); }
#line 1830 "src/parser.tab.cpp"
    break;

  case 69: /* Condition: StringOperation  */
#line 245 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = (yyvsp[0].Exp); }
#line 1836 "src/parser.tab.cpp"
    break;

  case 70: /* Operation: MathOperation  */
#line 248 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = (yyvsp[0].Exp); }
#line 1842 "src/parser.tab.cpp"
    break;

  case 71: /* Operation: StringOperation  */
#line 249 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = (yyvsp[0].Exp); }
#line 1848 "src/parser.tab.cpp"
    break;

  case 72: /* Operation: FunctionCall  */
#line 250 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = (yyvsp[0].Exp); }
#line 1854 "src/parser.tab.cpp"
    break;

  case 73: /* FunctionCall: IDENTIFIER '(' FunctionCallParams ')'  */
#line 253 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new FunctionCallNode( (yyvsp[-3].str), (yyvsp[-1].FCP) ); }
#line 1860 "src/parser.tab.cpp"
    break;

  case 74: /* FunctionCall: IDENTIFIER '(' ')'  */
#line 254 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new FunctionCallNode( (yyvsp[-2].str), nullptr ); }
#line 1866 "src/parser.tab.cpp"
    break;

  case 75: /* FunctionCallParams: FunctionCallParams ',' Operation  */
#line 257 "lex-yacc/parser.ypp"
                                                    { (yyval.FCP) = (yyvsp[-2].FCP)->addParameter((yyvsp[0].Exp)); }
#line 1872 "src/parser.tab.cpp"
    break;

  case 76: /* FunctionCallParams: Operation  */
#line 258 "lex-yacc/parser.ypp"
                                                    { (yyval.FCP) = new FunctionCallParametersNode((yyvsp[0].Exp)); }
#line 1878 "src/parser.tab.cpp"
    break;

  case 77: /* MathOperation: MathOperation '+' MathOperation  */
#line 261 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_ADD); }
#line 1884 "src/parser.tab.cpp"
    break;

  case 78: /* MathOperation: MathOperation '-' MathOperation  */
#line 262 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_SUB); }
#line 1890 "src/parser.tab.cpp"
    break;

  case 79: /* MathOperation: MathOperation '*' MathOperation  */
#line 263 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_MUL); }
#line 1896 "src/parser.tab.cpp"
    break;

  case 80: /* MathOperation: MathOperation '/' MathOperation  */
#line 264 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_DIV); }
#line 1902 "src/parser.tab.cpp"
    break;

  case 81: /* MathOperation: MathOperation '%' MathOperation  */
#line 265 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_MOD); }
#line 1908 "src/parser.tab.cpp"
    break;

  case 82: /* MathOperation: '(' MathOperation ')' MathOperation  */
#line 266 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_MUL); }
#line 1914 "src/parser.tab.cpp"
    break;

  case 83: /* MathOperation: '(' MathOperation ')'  */
#line 267 "lex-yacc/parser.ypp"
                                                    {                   (yyval.Exp) = (yyvsp[-1].Exp);               }
#line 1920 "src/parser.tab.cpp"
    break;

  case 84: /* MathOperation: POW '(' MathOperation ',' MathOperation ')'  */
#line 268 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-3].Exp), (yyvsp[-1].Exp), OP_POW);  }
#line 1926 "src/parser.tab.cpp"
    break;

  case 85: /* MathOperation: SQRT '(' MathOperation ')'  */
#line 269 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-1].Exp), (yyvsp[-1].Exp), OP_SQRT); }
#line 1932 "src/parser.tab.cpp"
    break;

  case 86: /* MathOperation: MathOperation SHL MathOperation  */
#line 270 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_SHL); }
#line 1938 "src/parser.tab.cpp"
    break;

  case 87: /* MathOperation: MathOperation SHR MathOperation  */
#line 271 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_SHR); }
#line 1944 "src/parser.tab.cpp"
    break;

  case 88: /* MathOperation: MathOperation '|' MathOperation  */
#line 272 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_BW_OR); }
#line 1950 "src/parser.tab.cpp"
    break;

  case 89: /* MathOperation: MathOperation '&' MathOperation  */
#line 273 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_BW_AND); }
#line 1956 "src/parser.tab.cpp"
    break;

  case 90: /* MathOperation: MathOperation '^' MathOperation  */
#line 274 "lex-yacc/parser.ypp"
                                                    { (yyval.Exp) = new Expression((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_XOR); }
#line 1962 "src/parser.tab.cpp"
    break;

  case 91: /* MathOperation: IDENTIFIER INCREMENT  */
#line 275 "lex-yacc/parser.ypp"
                                                      { (yyval.Exp) = new IdentifierContainer((yyvsp[-1].str), OP_POST_ADD); }
#line 1968 "src/parser.tab.cpp"
    break;

  case 92: /* MathOperation: INCREMENT IDENTIFIER  */
#line 276 "lex-yacc/parser.ypp"
                                                      { (yyval.Exp) = new IdentifierContainer((yyvsp[0].str), OP_PRE_ADD); }
#line 1974 "src/parser.tab.cpp"
    break;

  case 93: /* MathOperation: DECREMENT IDENTIFIER  */
#line 277 "lex-yacc/parser.ypp"
                                                      { (yyval.Exp) = new IdentifierContainer((yyvsp[0].str), OP_PRE_SUB); }
#line 1980 "src/parser.tab.cpp"
    break;

  case 94: /* MathOperation: IDENTIFIER DECREMENT  */
#line 278 "lex-yacc/parser.ypp"
                                                      { (yyval.Exp) = new IdentifierContainer((yyvsp[-1].str), OP_POST_ADD); }
#line 1986 "src/parser.tab.cpp"
    break;

  case 96: /* StringOperation: StringOperation '+' StringOperation  */
#line 282 "lex-yacc/parser.ypp"
                                                        { (yyval.Exp) =  new StringContainer((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_ADD); }
#line 1992 "src/parser.tab.cpp"
    break;

  case 97: /* StringOperation: StringOperation '+' MathOperation  */
#line 283 "lex-yacc/parser.ypp"
                                                        { (yyval.Exp) =  new StringContainer((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_ADD); }
#line 1998 "src/parser.tab.cpp"
    break;

  case 98: /* StringOperation: StringOperation '-' MathOperation  */
#line 284 "lex-yacc/parser.ypp"
                                                        { (yyval.Exp) =  new StringContainer((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_SUB); }
#line 2004 "src/parser.tab.cpp"
    break;

  case 99: /* StringOperation: '(' StringOperation ')'  */
#line 285 "lex-yacc/parser.ypp"
                                                        { (yyval.Exp) =  (yyvsp[-1].Exp); }
#line 2010 "src/parser.tab.cpp"
    break;

  case 100: /* StringOperation: StringOperation SHL StringOperation  */
#line 286 "lex-yacc/parser.ypp"
                                                        { (yyval.Exp) =  new StringContainer((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_SHL); }
#line 2016 "src/parser.tab.cpp"
    break;

  case 101: /* StringOperation: StringOperation SHR StringOperation  */
#line 287 "lex-yacc/parser.ypp"
                                                        { (yyval.Exp) =  new StringContainer((yyvsp[-2].Exp), (yyvsp[0].Exp), OP_SHR); }
#line 2022 "src/parser.tab.cpp"
    break;

  case 105: /* MathOperand: INTEGER  */
#line 293 "lex-yacc/parser.ypp"
                        { (yyval.Exp) = new Expression((yyvsp[0].str), DataType::Int());}
#line 2028 "src/parser.tab.cpp"
    break;

  case 106: /* MathOperand: FLOAT  */
#line 295 "lex-yacc/parser.ypp"
                        { (yyval.Exp) = new Expression((yyvsp[0].str), DataType::Float());}
#line 2034 "src/parser.tab.cpp"
    break;

  case 107: /* MathOperand: CHARACTER  */
#line 297 "lex-yacc/parser.ypp"
                        { (yyval.Exp) = new Expression((yyvsp[0].str), DataType::Char());}
#line 2040 "src/parser.tab.cpp"
    break;

  case 108: /* MathOperand: BOOLEAN  */
#line 299 "lex-yacc/parser.ypp"
                        { (yyval.Exp) = new Expression((yyvsp[0].str), DataType::Bool());}
#line 2046 "src/parser.tab.cpp"
    break;

  case 109: /* MathOperand: IDENTIFIER  */
#line 301 "lex-yacc/parser.ypp"
                        { (yyval.Exp) = new IdentifierContainer((yyvsp[0].str)); }
#line 2052 "src/parser.tab.cpp"
    break;

  case 110: /* StringOperand: STRING  */
#line 303 "lex-yacc/parser.ypp"
                        { (yyval.Exp) = new StringContainer((yyvsp[0].str)); }
#line 2058 "src/parser.tab.cpp"
    break;

  case 111: /* Type: CONST DATA_TYPE  */
#line 306 "lex-yacc/parser.ypp"
                        { (yyval.DT) = new DataType((yyvsp[0].str), true);}
#line 2064 "src/parser.tab.cpp"
    break;

  case 112: /* Type: DATA_TYPE  */
#line 307 "lex-yacc/parser.ypp"
                        { (yyval.DT) = new DataType((yyvsp[0].str), false);}
#line 2070 "src/parser.tab.cpp"
    break;


#line 2074 "src/parser.tab.cpp"

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

#line 309 "lex-yacc/parser.ypp"



int main() {
    ScopeNode* x = new ScopeNode();
    yyin = fopen("test.yapl", "r");
    yyparse();
    return 0;
}
