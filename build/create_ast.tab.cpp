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
#line 1 "create_ast.y"

#include <stdio.h>
#include <string.h>
#include "ast_str.h"
#include<iostream>
#include <math.h>
extern "C" int yylex();
extern AST_base* last_node;

#line 81 "/home/ubuntufb/ep2024spr/compiler_epr/compiler/build/create_ast.tab.cpp"

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

#include "create_ast.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMBER = 3,                     /* NUMBER  */
  YYSYMBOL_IDENTIFIER = 4,                 /* IDENTIFIER  */
  YYSYMBOL_DATA_TYPE = 5,                  /* DATA_TYPE  */
  YYSYMBOL_COMPARE_TOK = 6,                /* COMPARE_TOK  */
  YYSYMBOL_LOOP_TOK = 7,                   /* LOOP_TOK  */
  YYSYMBOL_VARDECL = 8,                    /* VARDECL  */
  YYSYMBOL_IFTOK = 9,                      /* IFTOK  */
  YYSYMBOL_ELSETOK = 10,                   /* ELSETOK  */
  YYSYMBOL_FNDECL = 11,                    /* FNDECL  */
  YYSYMBOL_12_ = 12,                       /* ';'  */
  YYSYMBOL_13_ = 13,                       /* '('  */
  YYSYMBOL_14_ = 14,                       /* ')'  */
  YYSYMBOL_15_ = 15,                       /* '{'  */
  YYSYMBOL_16_ = 16,                       /* '}'  */
  YYSYMBOL_17_ = 17,                       /* ':'  */
  YYSYMBOL_18_ = 18,                       /* ','  */
  YYSYMBOL_19_ = 19,                       /* '='  */
  YYSYMBOL_20_ = 20,                       /* '+'  */
  YYSYMBOL_21_ = 21,                       /* '-'  */
  YYSYMBOL_22_ = 22,                       /* '*'  */
  YYSYMBOL_23_ = 23,                       /* '/'  */
  YYSYMBOL_24_ = 24,                       /* '|'  */
  YYSYMBOL_25_ = 25,                       /* '!'  */
  YYSYMBOL_YYACCEPT = 26,                  /* $accept  */
  YYSYMBOL_commands = 27,                  /* commands  */
  YYSYMBOL_fn_call = 28,                   /* fn_call  */
  YYSYMBOL_fn_decl = 29,                   /* fn_decl  */
  YYSYMBOL_var_type = 30,                  /* var_type  */
  YYSYMBOL_IL_conc = 31,                   /* IL_conc  */
  YYSYMBOL_init_list = 32,                 /* init_list  */
  YYSYMBOL_if_else = 33,                   /* if_else  */
  YYSYMBOL_loop = 34,                      /* loop  */
  YYSYMBOL_condition = 35,                 /* condition  */
  YYSYMBOL_var_declaration = 36,           /* var_declaration  */
  YYSYMBOL_assign = 37,                    /* assign  */
  YYSYMBOL_exp = 38,                       /* exp  */
  YYSYMBOL_factor = 39,                    /* factor  */
  YYSYMBOL_term = 40                       /* term  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  30
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   114

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  26
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  45
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  93

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   266


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
       2,     2,     2,    25,     2,     2,     2,     2,     2,     2,
      13,    14,    22,    20,    18,    21,     2,    23,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    17,    12,
       2,    19,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    15,    24,    16,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    23,    23,    29,    36,    43,    49,    54,    61,    66,
      72,    80,    87,    92,   101,   106,   114,   123,   129,   130,
     131,   138,   139,   140,   146,   147,   155,   162,   171,   180,
     186,   191,   199,   208,   209,   210,   213,   214,   215,   218,
     225,   232,   233,   234,   235,   236
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
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER", "IDENTIFIER",
  "DATA_TYPE", "COMPARE_TOK", "LOOP_TOK", "VARDECL", "IFTOK", "ELSETOK",
  "FNDECL", "';'", "'('", "')'", "'{'", "'}'", "':'", "','", "'='", "'+'",
  "'-'", "'*'", "'/'", "'|'", "'!'", "$accept", "commands", "fn_call",
  "fn_decl", "var_type", "IL_conc", "init_list", "if_else", "loop",
  "condition", "var_declaration", "assign", "exp", "factor", "term", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-17)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      10,    37,    39,    26,    39,    29,    51,    41,    10,    10,
      10,    10,    43,    45,    39,   -17,    46,    39,    39,    39,
      39,   -17,    52,     7,   -16,   -17,     4,    56,    61,    78,
     -17,    10,   -17,   -17,   -17,   -17,    10,    37,    82,    74,
      77,     5,    20,   -17,    65,     5,    10,    39,    39,    39,
      39,    39,   -17,   -17,    10,    69,   -17,   -17,   -17,    45,
      45,   -17,   -17,    83,     5,   -16,   -16,   -17,   -17,    84,
      58,    85,    87,    88,   -17,   -17,   -17,    94,   100,   102,
      95,    93,    96,   -17,    92,   -17,   -17,    10,    10,    97,
      98,   -17,   -17
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     6,     2,
      12,     5,     0,    21,     0,    39,    40,     0,     0,     0,
       0,    45,     0,     0,    33,    36,     0,     0,     0,     0,
       1,     8,     7,     3,    13,     4,     9,    40,     0,    22,
      24,    32,     0,    43,     0,    44,     0,     0,     0,     0,
       0,     0,    31,    30,     0,    18,    11,    10,    14,    21,
      21,    42,    41,     0,    29,    34,    35,    37,    38,     0,
      40,    19,     0,     0,    23,    25,    28,    26,     0,    18,
       0,     0,     0,    17,     0,    20,    15,     0,     0,     0,
       0,    16,    27
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -17,    -7,     0,   -17,   -17,    31,    19,   -17,   -17,   108,
     -17,     2,    18,    35,    -6
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     6,    21,     8,    71,    72,    38,     9,    10,    22,
      11,    12,    40,    24,    25
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
       7,    32,    33,    34,    35,    27,    50,    51,     7,     7,
       7,     7,    43,    47,     1,    39,    52,     2,     3,     4,
      23,     5,    23,    14,    56,    48,    49,    48,    49,    57,
      26,     7,    41,    29,    61,    42,     7,    44,    45,    63,
      48,    49,    15,    16,    67,    68,     7,    69,    15,    37,
      13,    30,    17,    31,     7,    36,    14,    39,    17,    13,
      18,    39,    39,    19,    20,    64,    18,    46,    53,    19,
      20,    13,    15,    70,    73,    78,    54,    14,    74,    75,
      89,    90,    17,    65,    66,    48,    49,     7,     7,    62,
      18,    55,    59,    19,    20,    60,    58,    48,    49,    76,
      77,    80,    81,    79,    82,    83,    84,    86,    87,    78,
      85,    88,    28,    91,    92
};

static const yytype_int8 yycheck[] =
{
       0,     8,     9,    10,    11,     3,    22,    23,     8,     9,
      10,    11,    18,     6,     4,    13,    12,     7,     8,     9,
       2,    11,     4,    19,    31,    20,    21,    20,    21,    36,
       4,    31,    14,     4,    14,    17,    36,    19,    20,    46,
      20,    21,     3,     4,    50,    51,    46,    54,     3,     4,
      13,     0,    13,    12,    54,    12,    19,    55,    13,    13,
      21,    59,    60,    24,    25,    47,    21,    15,    12,    24,
      25,    13,     3,     4,    55,    17,    15,    19,    59,    60,
      87,    88,    13,    48,    49,    20,    21,    87,    88,    24,
      21,    13,    18,    24,    25,    18,    14,    20,    21,    16,
      16,    14,    14,    18,    10,     5,     4,    12,    15,    17,
      79,    15,     4,    16,    16
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     4,     7,     8,     9,    11,    27,    28,    29,    33,
      34,    36,    37,    13,    19,     3,     4,    13,    21,    24,
      25,    28,    35,    38,    39,    40,     4,    37,    35,     4,
       0,    12,    27,    27,    27,    27,    12,     4,    32,    37,
      38,    38,    38,    40,    38,    38,    15,     6,    20,    21,
      22,    23,    12,    12,    15,    13,    27,    27,    14,    18,
      18,    14,    24,    27,    38,    39,    39,    40,    40,    27,
       4,    30,    31,    32,    32,    32,    16,    16,    17,    18,
      14,    14,    10,     5,     4,    31,    12,    15,    15,    27,
      27,    16,    16
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    26,    27,    27,    27,    27,    27,    27,    27,    27,
      27,    27,    27,    27,    28,    29,    29,    30,    31,    31,
      31,    32,    32,    32,    32,    32,    33,    33,    34,    35,
      36,    36,    37,    38,    38,    38,    39,    39,    39,    40,
      40,    40,    40,    40,    40,    40
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     1,     2,     2,     2,
       3,     3,     1,     2,     4,     6,     8,     3,     0,     1,
       3,     0,     1,     3,     1,     3,     5,     9,     5,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       1,     3,     3,     2,     2,     1
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
  case 2: /* commands: if_else  */
#line 24 "create_ast.y"
    {
        //std::cout << std::endl << "IFELS_zero" << std::endl;
        (yyval.a) = (yyvsp[0].a);
        last_node = (yyval.a);
    }
#line 1166 "/home/ubuntufb/ep2024spr/compiler_epr/compiler/build/create_ast.tab.cpp"
    break;

  case 3: /* commands: if_else commands  */
#line 30 "create_ast.y"
    {
        //std::cout << "IFELSE_COMMA" << std::endl;
        ((AST_node*)(yyvsp[-1].a))->next = (yyvsp[0].a);
        //std::cout << "NEXT: \n" << *(AST_node*)(((AST_node*)$1)->next) << std::endl;
        ((AST_node*)(yyvsp[0].a))->prev = (yyvsp[-1].a); (yyval.a) = (yyvsp[-1].a); last_node = (yyval.a);
    }
#line 1177 "/home/ubuntufb/ep2024spr/compiler_epr/compiler/build/create_ast.tab.cpp"
    break;

  case 4: /* commands: var_declaration commands  */
#line 37 "create_ast.y"
    {
        //std::cout << "var_decl commands" << std::endl;
        ((AST_node*)(yyvsp[-1].a))->next = (yyvsp[0].a);
        //std::cout << "NEXT: \n" << *(AST_node*)(((AST_node*)$1)->next) << std::endl;
        ((AST_node*)(yyvsp[0].a))->prev = (yyvsp[-1].a); (yyval.a) = (yyvsp[-1].a); last_node = (yyval.a);
    }
#line 1188 "/home/ubuntufb/ep2024spr/compiler_epr/compiler/build/create_ast.tab.cpp"
    break;

  case 5: /* commands: var_declaration  */
#line 44 "create_ast.y"
    {
        //std::cout << "c _ VAR DECL\n" << std::endl;
        (yyval.a) = (yyvsp[0].a);
        last_node = (yyval.a);
    }
#line 1198 "/home/ubuntufb/ep2024spr/compiler_epr/compiler/build/create_ast.tab.cpp"
    break;

  case 6: /* commands: fn_decl  */
#line 50 "create_ast.y"
    {
        (yyval.a) = (yyvsp[0].a);
        last_node = (yyval.a);
    }
#line 1207 "/home/ubuntufb/ep2024spr/compiler_epr/compiler/build/create_ast.tab.cpp"
    break;

  case 7: /* commands: fn_decl commands  */
#line 55 "create_ast.y"
    {
        ((AST_node*)(yyvsp[-1].a))->next = (yyvsp[0].a);
        ((AST_node*)(yyvsp[0].a))->prev = (yyvsp[-1].a);
        (yyval.a) = (yyvsp[-1].a);
        last_node = (yyval.a);
    }
#line 1218 "/home/ubuntufb/ep2024spr/compiler_epr/compiler/build/create_ast.tab.cpp"
    break;

  case 8: /* commands: fn_call ';'  */
#line 62 "create_ast.y"
    {
        (yyval.a) = (yyvsp[-1].a);
        last_node = (yyval.a);
    }
#line 1227 "/home/ubuntufb/ep2024spr/compiler_epr/compiler/build/create_ast.tab.cpp"
    break;

  case 9: /* commands: assign ';'  */
#line 67 "create_ast.y"
    {
        //printf("ASSIGN\n");
        (yyval.a) = (yyvsp[-1].a);
        last_node = (yyval.a);
    }
#line 1237 "/home/ubuntufb/ep2024spr/compiler_epr/compiler/build/create_ast.tab.cpp"
    break;

  case 10: /* commands: assign ';' commands  */
#line 73 "create_ast.y"
    {
        //printf("ASSIGN_COMMANDS\n");
        ((AST_node*)(yyvsp[-2].a))->next = (yyvsp[0].a);
        ((AST_node*)(yyvsp[0].a))->prev = (yyvsp[-2].a);
        (yyval.a) = (yyvsp[-2].a);
        last_node = (yyval.a);
    }
#line 1249 "/home/ubuntufb/ep2024spr/compiler_epr/compiler/build/create_ast.tab.cpp"
    break;

  case 11: /* commands: fn_call ';' commands  */
#line 81 "create_ast.y"
    {
        ((AST_node*)(yyvsp[-2].a))->next = (yyvsp[0].a);
        ((AST_node*)(yyvsp[0].a))->prev = (yyvsp[-2].a);
        (yyval.a) = (yyvsp[-2].a);
        last_node = (yyval.a);
    }
#line 1260 "/home/ubuntufb/ep2024spr/compiler_epr/compiler/build/create_ast.tab.cpp"
    break;

  case 12: /* commands: loop  */
#line 88 "create_ast.y"
    {
        (yyval.a) = (yyvsp[0].a);
        last_node = (yyval.a);
    }
#line 1269 "/home/ubuntufb/ep2024spr/compiler_epr/compiler/build/create_ast.tab.cpp"
    break;

  case 13: /* commands: loop commands  */
#line 93 "create_ast.y"
    {
        ((AST_node*)(yyvsp[-1].a))->next = (yyvsp[0].a);
        ((AST_node*)(yyvsp[0].a))->prev = (yyvsp[-1].a);
        (yyval.a) = (yyvsp[-1].a);
        last_node = (yyval.a);
    }
#line 1280 "/home/ubuntufb/ep2024spr/compiler_epr/compiler/build/create_ast.tab.cpp"
    break;

  case 14: /* fn_call: IDENTIFIER '(' init_list ')'  */
#line 102 "create_ast.y"
    {
        auto a = newleaf(NT_IDENT, (yyvsp[-3].d));
        (yyval.a) = newast(NT_FN_CALL, {a, (yyvsp[-1].a)});
    }
#line 1289 "/home/ubuntufb/ep2024spr/compiler_epr/compiler/build/create_ast.tab.cpp"
    break;

  case 15: /* fn_decl: FNDECL IDENTIFIER '(' IL_conc ')' ';'  */
#line 107 "create_ast.y"
    {
        //printf("FNDECL wtht commands\n");
        auto a = newleaf(NT_IDENT, (yyvsp[-4].d));
        auto b = newast(NT_NULL, {});
        (yyval.a) = newast(NT_FNDECL,{a, (yyvsp[-2].a), b});

    }
#line 1301 "/home/ubuntufb/ep2024spr/compiler_epr/compiler/build/create_ast.tab.cpp"
    break;

  case 16: /* fn_decl: FNDECL IDENTIFIER '(' init_list ')' '{' commands '}'  */
#line 115 "create_ast.y"
    {
        //printf("FNDECL\n");
        auto a = newleaf(NT_IDENT, (yyvsp[-6].d));
        (yyval.a) = newast(NT_FNDECL,{a, (yyvsp[-4].a), (yyvsp[-1].a)});
        ((AST_node*)(yyvsp[-1].a))->prev = (yyval.a); // см. readme


    }
#line 1314 "/home/ubuntufb/ep2024spr/compiler_epr/compiler/build/create_ast.tab.cpp"
    break;

  case 17: /* var_type: IDENTIFIER ':' DATA_TYPE  */
#line 124 "create_ast.y"
    {
        auto a = newleaf(NT_IDENT, (yyvsp[-2].d));
        auto b = newleaf(NT_DATA_TYPE, (yyvsp[0].d));
        (yyval.a) = newast(NT_TYPED_VAR, {a,b});
    }
#line 1324 "/home/ubuntufb/ep2024spr/compiler_epr/compiler/build/create_ast.tab.cpp"
    break;

  case 18: /* IL_conc: %empty  */
#line 129 "create_ast.y"
         {(yyval.a) = newast(NT_NULL,{});}
#line 1330 "/home/ubuntufb/ep2024spr/compiler_epr/compiler/build/create_ast.tab.cpp"
    break;

  case 19: /* IL_conc: var_type  */
#line 130 "create_ast.y"
               {(yyval.a) = newast(NT_IL_conc, {(yyvsp[0].a)});}
#line 1336 "/home/ubuntufb/ep2024spr/compiler_epr/compiler/build/create_ast.tab.cpp"
    break;

  case 20: /* IL_conc: var_type ',' IL_conc  */
#line 132 "create_ast.y"
    {
        printf("ident + inlist in INITLIST\n");
        std::vector<AST_base*> vec = {(yyvsp[-2].a)};
        vec.insert(vec.end(),(((AST_node*)(yyvsp[0].a))->subtrees).begin(), (((AST_node*)(yyvsp[0].a))->subtrees).end());
        (yyval.a) = newast(NT_IL_conc, vec);
    }
#line 1347 "/home/ubuntufb/ep2024spr/compiler_epr/compiler/build/create_ast.tab.cpp"
    break;

  case 21: /* init_list: %empty  */
#line 138 "create_ast.y"
           {(yyval.a) = newast(NT_NULL,{});}
#line 1353 "/home/ubuntufb/ep2024spr/compiler_epr/compiler/build/create_ast.tab.cpp"
    break;

  case 22: /* init_list: assign  */
#line 139 "create_ast.y"
             {(yyval.a) = newast(NT_INIT_LIST, {(yyvsp[0].a)});}
#line 1359 "/home/ubuntufb/ep2024spr/compiler_epr/compiler/build/create_ast.tab.cpp"
    break;

  case 23: /* init_list: assign ',' init_list  */
#line 141 "create_ast.y"
    {
        std::vector<AST_base*> vec = {(yyvsp[-2].a)};
        vec.insert(vec.end(),(((AST_node*)(yyvsp[0].a))->subtrees).begin(), (((AST_node*)(yyvsp[0].a))->subtrees).end());
        (yyval.a) = newast(NT_INIT_LIST, vec);
    }
#line 1369 "/home/ubuntufb/ep2024spr/compiler_epr/compiler/build/create_ast.tab.cpp"
    break;

  case 24: /* init_list: exp  */
#line 146 "create_ast.y"
          {(yyval.a) = newast(NT_INIT_LIST, {(yyvsp[0].a)});}
#line 1375 "/home/ubuntufb/ep2024spr/compiler_epr/compiler/build/create_ast.tab.cpp"
    break;

  case 25: /* init_list: exp ',' init_list  */
#line 148 "create_ast.y"
    {
        std::vector<AST_base*> vec = {(yyvsp[-2].a)};
        vec.insert(vec.end(),(((AST_node*)(yyvsp[0].a))->subtrees).begin(), (((AST_node*)(yyvsp[0].a))->subtrees).end());
        (yyval.a) = newast(NT_INIT_LIST, vec);
    }
#line 1385 "/home/ubuntufb/ep2024spr/compiler_epr/compiler/build/create_ast.tab.cpp"
    break;

  case 26: /* if_else: IFTOK condition '{' commands '}'  */
#line 156 "create_ast.y"
    {
        auto b = newast(NT_NULL, {});
        (yyval.a) = newast(NT_IFELSE, {(yyvsp[-3].a), (yyvsp[-1].a), b});
        ((AST_node*)(yyvsp[-1].a))->prev = (yyval.a); // см. readme
       // printf("IFELSE\n");
    }
#line 1396 "/home/ubuntufb/ep2024spr/compiler_epr/compiler/build/create_ast.tab.cpp"
    break;

  case 27: /* if_else: IFTOK condition '{' commands '}' ELSETOK '{' commands '}'  */
#line 163 "create_ast.y"
    {
        //printf("IFELSE_WITH_ELSE\n");
        (yyval.a) = newast(NT_IFELSE, {(yyvsp[-7].a), (yyvsp[-5].a), (yyvsp[-1].a)});
        ((AST_node*)(yyvsp[-5].a))->prev = (yyval.a);
        ((AST_node*)(yyvsp[-1].a))->prev = (yyval.a);


    }
#line 1409 "/home/ubuntufb/ep2024spr/compiler_epr/compiler/build/create_ast.tab.cpp"
    break;

  case 28: /* loop: LOOP_TOK condition '{' commands '}'  */
#line 172 "create_ast.y"
    {
       // printf("LOOP\n");
        auto a = newleaf(NT_IDENT,(yyvsp[-4].d));
        (yyval.a) = newast(NT_LOOP, {a,(yyvsp[-3].a),(yyvsp[-1].a)});
        ((AST_node*)(yyvsp[-1].a))->prev = (yyval.a);

    }
#line 1421 "/home/ubuntufb/ep2024spr/compiler_epr/compiler/build/create_ast.tab.cpp"
    break;

  case 29: /* condition: exp COMPARE_TOK exp  */
#line 181 "create_ast.y"
    {
        auto a = newleaf(NT_COMPARE, (yyvsp[-1].d));
        (yyval.a) = newast(NT_COND, {a, (yyvsp[-2].a), (yyvsp[0].a)});
    }
#line 1430 "/home/ubuntufb/ep2024spr/compiler_epr/compiler/build/create_ast.tab.cpp"
    break;

  case 30: /* var_declaration: VARDECL assign ';'  */
#line 187 "create_ast.y"
    {
        //printf("variable declared \n");
        (yyval.a) = newast(NT_VARDECL,{(yyvsp[-1].a)});
    }
#line 1439 "/home/ubuntufb/ep2024spr/compiler_epr/compiler/build/create_ast.tab.cpp"
    break;

  case 31: /* var_declaration: VARDECL IDENTIFIER ';'  */
#line 192 "create_ast.y"
    {
        AST_leaf* a = newleaf(NT_IDENT, (yyvsp[-1].d));
        (yyval.a) = newast(NT_VARDECL, {a});
    }
#line 1448 "/home/ubuntufb/ep2024spr/compiler_epr/compiler/build/create_ast.tab.cpp"
    break;

  case 32: /* assign: IDENTIFIER '=' exp  */
#line 200 "create_ast.y"
    {
        char* ch1 = (char*)calloc(strlen((yyvsp[-2].d)), sizeof(char));
        strncpy(ch1, (yyvsp[-2].d), strlen((yyvsp[-2].d)));
        AST_leaf* a = newleaf(NT_IDENT, ch1);

        (yyval.a) = newast(NT_ASSIGN, std::vector<AST_base*>{a,(yyvsp[0].a)});
    }
#line 1460 "/home/ubuntufb/ep2024spr/compiler_epr/compiler/build/create_ast.tab.cpp"
    break;

  case 33: /* exp: factor  */
#line 208 "create_ast.y"
            {(yyval.a) = (yyvsp[0].a);}
#line 1466 "/home/ubuntufb/ep2024spr/compiler_epr/compiler/build/create_ast.tab.cpp"
    break;

  case 34: /* exp: exp '+' factor  */
#line 209 "create_ast.y"
                     {std::cout << "plus\n"; (yyval.a) = newast(NT_ADD, {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1472 "/home/ubuntufb/ep2024spr/compiler_epr/compiler/build/create_ast.tab.cpp"
    break;

  case 35: /* exp: exp '-' factor  */
#line 210 "create_ast.y"
                     { (yyval.a) = newast(NT_SUB, {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1478 "/home/ubuntufb/ep2024spr/compiler_epr/compiler/build/create_ast.tab.cpp"
    break;

  case 36: /* factor: term  */
#line 213 "create_ast.y"
             {(yyval.a) = (yyvsp[0].a); std::cout << "TERM\n";}
#line 1484 "/home/ubuntufb/ep2024spr/compiler_epr/compiler/build/create_ast.tab.cpp"
    break;

  case 37: /* factor: factor '*' term  */
#line 214 "create_ast.y"
                      { (yyval.a) = newast(NT_MUL, {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1490 "/home/ubuntufb/ep2024spr/compiler_epr/compiler/build/create_ast.tab.cpp"
    break;

  case 38: /* factor: factor '/' term  */
#line 215 "create_ast.y"
                      { (yyval.a) = newast(NT_DIV, {(yyvsp[-2].a), (yyvsp[0].a)}); }
#line 1496 "/home/ubuntufb/ep2024spr/compiler_epr/compiler/build/create_ast.tab.cpp"
    break;

  case 39: /* term: NUMBER  */
#line 219 "create_ast.y"
    {
        //printf("NT_NUM\n");
        char* ch1 = (char*)malloc(strlen((yyvsp[0].d)) * sizeof(char));
        strncpy(ch1, (yyvsp[0].d), strlen((yyvsp[0].d)));
        (yyval.a) = newleaf(NT_NUM, (yyvsp[0].d));
    }
#line 1507 "/home/ubuntufb/ep2024spr/compiler_epr/compiler/build/create_ast.tab.cpp"
    break;

  case 40: /* term: IDENTIFIER  */
#line 226 "create_ast.y"
    {
        // printf("NT_IDENT\n");
        char* ch1 = (char*)calloc(strlen((yyvsp[0].d)), sizeof(char));
        strncpy(ch1, (yyvsp[0].d), strlen((yyvsp[0].d)));
        (yyval.a) = newleaf(NT_IDENT, ch1);
    }
#line 1518 "/home/ubuntufb/ep2024spr/compiler_epr/compiler/build/create_ast.tab.cpp"
    break;

  case 41: /* term: '|' exp '|'  */
#line 232 "create_ast.y"
                  { (yyval.a) = newast(NT_ABS, {(yyvsp[-1].a)}); }
#line 1524 "/home/ubuntufb/ep2024spr/compiler_epr/compiler/build/create_ast.tab.cpp"
    break;

  case 42: /* term: '(' exp ')'  */
#line 233 "create_ast.y"
                  { (yyval.a) = (yyvsp[-1].a); }
#line 1530 "/home/ubuntufb/ep2024spr/compiler_epr/compiler/build/create_ast.tab.cpp"
    break;

  case 43: /* term: '-' term  */
#line 234 "create_ast.y"
                  { (yyval.a) = newast(NT_NEG, {(yyvsp[0].a)}); }
#line 1536 "/home/ubuntufb/ep2024spr/compiler_epr/compiler/build/create_ast.tab.cpp"
    break;

  case 44: /* term: '!' exp  */
#line 235 "create_ast.y"
                  { (yyval.a) = newast(NT_NOT, {(yyvsp[0].a)});}
#line 1542 "/home/ubuntufb/ep2024spr/compiler_epr/compiler/build/create_ast.tab.cpp"
    break;

  case 45: /* term: fn_call  */
#line 236 "create_ast.y"
                  { (yyval.a) = (yyvsp[0].a); }
#line 1548 "/home/ubuntufb/ep2024spr/compiler_epr/compiler/build/create_ast.tab.cpp"
    break;


#line 1552 "/home/ubuntufb/ep2024spr/compiler_epr/compiler/build/create_ast.tab.cpp"

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

#line 239 "create_ast.y"

