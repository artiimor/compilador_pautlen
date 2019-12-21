/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "alfa.y" /* yacc.c:339  */

	#include <stdlib.h>
	#include <stdio.h>

	#include "alfa.h"
	#include "tablahash.h"
	#include "generacion.h"

	#include "y.tab.h"
	


	extern int line;
	extern int col;
	extern FILE* fout;

	int pos_parametro_actual = 0; // Indica en que parametro estamos
	int num_parametros_actual = 0; // Contador del numero de parametros
	int num_variables_locales_actual = 0; // contador de varibles locales
	int pos_variable_local_actual = 0; // Indica en que variable local estamos
	int hayReturn = 0; // Indica si la funcion tiene return para cde
	int tiporeturn;
	int cuantos = 0;//esta variable es un contador para generar saltos unicos
	int num_parametros_llamada_actual = 0;
	int clase_actual;
	int tipo_actual;



#line 96 "alfa.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "alfa.tab.h".  */
#ifndef YY_YY_ALFA_TAB_H_INCLUDED
# define YY_YY_ALFA_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TOK_MAIN = 258,
    TOK_INT = 259,
    TOK_BOOLEAN = 260,
    TOK_ARRAY = 261,
    TOK_FUNCTION = 262,
    TOK_IF = 263,
    TOK_ELSE = 264,
    TOK_WHILE = 265,
    TOK_SCANF = 266,
    TOK_PRINTF = 267,
    TOK_RETURN = 268,
    TOK_IDENTIFICADOR = 269,
    TOK_PUNTOYCOMA = 270,
    TOK_COMA = 271,
    TOK_PARENTESISIZQUIERDO = 272,
    TOK_PARENTESISDERECHO = 273,
    TOK_CORCHETEIZQUIERDO = 274,
    TOK_CORCHETEDERECHO = 275,
    TOK_LLAVEIZQUIERDA = 276,
    TOK_LLAVEDERECHA = 277,
    TOK_ASIGNACION = 278,
    TOK_MAS = 279,
    TOK_MENOS = 280,
    TOK_DIVISION = 281,
    TOK_ASTERISCO = 282,
    TOK_AND = 283,
    TOK_OR = 284,
    TOK_NOT = 285,
    TOK_IGUAL = 286,
    TOK_DISTINTO = 287,
    TOK_MENORIGUAL = 288,
    TOK_MAYORIGUAL = 289,
    TOK_MENOR = 290,
    TOK_MAYOR = 291,
    TOK_CONSTANTE_ENTERA = 292,
    TOK_FALSE = 293,
    TOK_TRUE = 294,
    TOK_ERROR = 295,
    fn_complete_name = 296,
    if_exp = 297,
    if_exp_sentencias = 298,
    tipo_retorno = 299,
    MENOSU = 300
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 32 "alfa.y" /* yacc.c:355  */

	tipo_atributos atributos;
	

#line 187 "alfa.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ALFA_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 204 "alfa.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   181

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  164

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,     2,     2,     2,     2,     2,     2,
      57,    58,    47,    45,    56,    46,     2,    48,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    53,
      61,    59,    60,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    54,     2,    55,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,     2,    52,     2,     2,     2,     2,
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
      49
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   130,   130,   134,   140,   144,   149,   158,   163,   169,
     177,   182,   193,   212,   216,   222,   225,   234,   258,   274,
     299,   304,   309,   313,   318,   322,   334,   348,   358,   363,
     367,   371,   376,   380,   385,   389,   393,   397,   402,   406,
     415,   456,   461,   503,   507,   512,   521,   561,   570,   578,
     596,   614,   632,   650,   668,   686,   704,   723,   752,   760,
     768,   776,   784,   790,   798,   802,   810,   817,   836,   855,
     874,   893,   912,   932,   940,   949,   961,   974,   996,  1000,
    1005,  1009,  1014,  1019,  1024,  1028
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_MAIN", "TOK_INT", "TOK_BOOLEAN",
  "TOK_ARRAY", "TOK_FUNCTION", "TOK_IF", "TOK_ELSE", "TOK_WHILE",
  "TOK_SCANF", "TOK_PRINTF", "TOK_RETURN", "TOK_IDENTIFICADOR",
  "TOK_PUNTOYCOMA", "TOK_COMA", "TOK_PARENTESISIZQUIERDO",
  "TOK_PARENTESISDERECHO", "TOK_CORCHETEIZQUIERDO", "TOK_CORCHETEDERECHO",
  "TOK_LLAVEIZQUIERDA", "TOK_LLAVEDERECHA", "TOK_ASIGNACION", "TOK_MAS",
  "TOK_MENOS", "TOK_DIVISION", "TOK_ASTERISCO", "TOK_AND", "TOK_OR",
  "TOK_NOT", "TOK_IGUAL", "TOK_DISTINTO", "TOK_MENORIGUAL",
  "TOK_MAYORIGUAL", "TOK_MENOR", "TOK_MAYOR", "TOK_CONSTANTE_ENTERA",
  "TOK_FALSE", "TOK_TRUE", "TOK_ERROR", "fn_complete_name", "if_exp",
  "if_exp_sentencias", "tipo_retorno", "'+'", "'-'", "'*'", "'/'",
  "MENOSU", "'!'", "'{'", "'}'", "';'", "'['", "']'", "','", "'('", "')'",
  "'='", "'>'", "'<'", "$accept", "programa", "declaraciones",
  "declaracion", "clase", "clase_escalar", "tipo", "clase_vector",
  "identificadores", "funciones", "funcion", "fn_declaration", "fn_name",
  "parametros_funcion", "resto_parametros_funcion", "parametro_funcion",
  "idpf", "declaraciones_funcion", "sentencias", "sentencia",
  "sentencia_simple", "bloque", "asignacion", "elemento_vector",
  "condicional", "bucle", "lectura", "escritura", "retorno_funcion", "exp",
  "lista_expresiones", "resto_lista_expresiones", "comparacion",
  "constante", "constante_logica", "constante_entera",
  "cola_identificador", "alfanumerico", "letra", "digito", "identificador", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    43,    45,    42,    47,   300,
      33,   123,   125,    59,    91,    93,    44,    40,    41,    61,
      62,    60
};
# endif

#define YYPACT_NINF -37

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-37)))

#define YYTABLE_NINF -85

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      11,   -11,    31,   130,   -37,   -37,   -37,    61,    61,    35,
     152,    30,   -37,   -37,   -37,    50,    35,    50,    37,    -6,
      41,    50,   -37,   -28,     4,     6,    18,    21,    28,    83,
      -5,    -5,   -36,    23,    50,    51,   -37,   -37,    46,   -37,
     -37,   -37,   -37,   -37,   -37,    85,    61,    73,    -4,    62,
      60,   -37,   -37,   -37,   -37,     6,   -37,   -37,    30,    -5,
      -5,   -37,     2,   -37,   -37,   -37,    -5,    -5,    -5,   -37,
     125,   -37,   -37,   -37,    63,   125,    -5,    -5,   -37,   -37,
     -37,    -5,   -37,   113,   111,    77,    76,    61,   -37,   -37,
     -37,    70,    97,   -37,   -37,    48,    80,    -5,    -5,    -5,
      -5,    -5,    -5,    -5,   104,   125,   125,   -37,   -37,   119,
      61,   -37,   -37,    89,   109,   110,    -5,    -5,    -5,    -5,
     -37,    -5,    -5,   -37,   -37,   -21,   -21,   -21,   -37,   -37,
      55,   105,   -37,   152,    77,   114,    50,    50,   125,   125,
     125,   125,   125,   125,    -5,   -37,   -37,   -37,   -37,   -37,
     152,   112,   115,    55,    50,   153,   -37,   -37,   116,   118,
     -37,    50,   122,   -37
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,    15,     1,    10,    11,     0,     0,    15,
       4,     0,     7,     9,     8,     0,    15,     0,     0,     0,
       0,     0,     5,    82,     0,     0,    13,     0,     0,     0,
       0,     0,     0,     0,    30,     0,    33,    34,     0,    38,
      39,    35,    36,    37,    16,     0,    22,     0,    82,     0,
       0,     6,    82,    83,    85,    78,    80,    81,     0,     0,
       0,    46,    57,    77,    76,    75,     0,     0,     0,    61,
      47,    58,    73,    74,     0,    48,     0,     0,     3,    31,
      32,     0,    17,     0,     0,    24,     0,    22,     2,    79,
      14,     0,     0,    53,    56,     0,     0,     0,     0,     0,
       0,     0,     0,    64,     0,    40,    41,    26,    25,     0,
       0,    21,    12,     0,     0,     0,     0,     0,     0,     0,
      59,     0,     0,    60,    54,    55,    49,    50,    52,    51,
      66,     0,    42,    29,    24,     0,     0,     0,    67,    68,
      70,    69,    71,    72,     0,    63,    62,    28,    18,    23,
      29,     0,     0,    66,     0,    43,    45,    65,     0,     0,
      20,     0,     0,    44
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -37,   -37,    12,   -37,   -37,   -37,     3,   -37,   108,     8,
     -37,   -37,   -37,    88,    42,    67,   -37,    29,   -13,   -37,
     -37,   -37,   -37,   -15,   -37,   -37,   -37,   -37,   -37,   -30,
     -37,    25,   -37,   -37,   -37,   -37,   126,   -37,   -20,   -37,
      -8
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,   147,    10,    11,    12,    13,    14,    24,    15,
      16,    17,    18,    84,   111,    85,   108,   148,    33,    34,
      35,    36,    37,    69,    39,    40,    41,    42,    43,    70,
     131,   145,    96,    71,    72,    73,    54,    55,    25,    57,
      74
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      38,    75,    38,    26,    45,    56,    38,    97,    50,    62,
      19,    20,    49,   -19,     1,     9,   -82,    21,    76,    38,
      52,    79,    22,    77,    44,   -84,   101,   102,   -84,    91,
      92,     4,    63,    64,    65,    56,    93,    94,    95,   -82,
       3,    66,     8,    53,    23,    67,   104,   105,    47,    83,
      26,   106,    68,   -84,    46,    48,    76,    51,    27,   -84,
      28,    29,    30,    31,    32,     5,     6,   124,   125,   126,
     127,   128,   129,   130,    58,    78,    97,    98,    59,   116,
     117,   118,   119,    97,    98,    60,   138,   139,   140,   141,
      83,   142,   143,    99,   100,   101,   102,    61,    97,    98,
      99,   100,   101,   102,    80,    81,   120,    82,   121,   122,
      86,   144,    88,    83,   153,    99,   100,   101,   102,    87,
     103,    38,    38,   151,   152,    97,    98,   107,   114,   109,
     110,   112,    97,    98,     5,     6,     7,     8,   123,    38,
     133,   158,    99,   100,   101,   102,    38,   135,   162,    99,
     100,   101,   102,    97,    98,   115,     5,     6,     7,   132,
     136,   137,   159,   146,   155,   150,    90,   156,   160,   161,
      99,   100,   101,   102,   163,   113,   149,   134,   157,   154,
       0,    89
};

static const yytype_int16 yycheck[] =
{
      15,    31,    17,    11,    17,    25,    21,    28,    21,    14,
       7,     8,    20,    17,     3,     3,    14,     9,    54,    34,
      14,    34,    10,    59,    16,    53,    47,    48,    56,    59,
      60,     0,    37,    38,    39,    55,    66,    67,    68,    37,
      51,    46,     7,    37,    14,    50,    76,    77,    54,    46,
      58,    81,    57,    57,    17,    14,    54,    53,     8,    57,
      10,    11,    12,    13,    14,     4,     5,    97,    98,    99,
     100,   101,   102,   103,    56,    52,    28,    29,    57,    31,
      32,    33,    34,    28,    29,    57,   116,   117,   118,   119,
      87,   121,   122,    45,    46,    47,    48,    14,    28,    29,
      45,    46,    47,    48,    53,    59,    58,    22,    60,    61,
      37,    56,    52,   110,   144,    45,    46,    47,    48,    57,
      57,   136,   137,   136,   137,    28,    29,    14,    58,    18,
      53,    55,    28,    29,     4,     5,     6,     7,    58,   154,
      21,   154,    45,    46,    47,    48,   161,    58,   161,    45,
      46,    47,    48,    28,    29,    58,     4,     5,     6,    55,
      51,    51,     9,    58,    52,    51,    58,    52,    52,    51,
      45,    46,    47,    48,    52,    87,   134,   110,   153,   150,
      -1,    55
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    63,    51,     0,     4,     5,     6,     7,    64,
      65,    66,    67,    68,    69,    71,    72,    73,    74,    68,
      68,    71,    64,    14,    70,   100,   102,     8,    10,    11,
      12,    13,    14,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    71,    80,    17,    54,    14,   102,
      80,    53,    14,    37,    98,    99,   100,   101,    56,    57,
      57,    14,    14,    37,    38,    39,    46,    50,    57,    85,
      91,    95,    96,    97,   102,    91,    54,    59,    52,    80,
      53,    59,    22,    68,    75,    77,    37,    57,    52,    98,
      70,    91,    91,    91,    91,    91,    94,    28,    29,    45,
      46,    47,    48,    57,    91,    91,    91,    14,    78,    18,
      53,    76,    55,    75,    58,    58,    31,    32,    33,    34,
      58,    60,    61,    58,    91,    91,    91,    91,    91,    91,
      91,    92,    55,    21,    77,    58,    51,    51,    91,    91,
      91,    91,    91,    91,    56,    93,    58,    64,    79,    76,
      51,    80,    80,    91,    79,    52,    52,    93,    80,     9,
      52,    51,    80,    52
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    63,    64,    64,    65,    66,    66,    67,
      68,    68,    69,    70,    70,    71,    71,    72,    73,    74,
      72,    75,    75,    76,    76,    77,    78,    77,    79,    79,
      80,    80,    81,    81,    82,    82,    82,    82,    83,    83,
      84,    84,    85,    86,    86,    87,    88,    89,    90,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    92,    92,    93,    93,    94,    94,    94,
      94,    94,    94,    95,    95,    96,    96,    97,    98,    98,
      99,    99,   100,   101,   102,   102
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     5,     1,     2,     3,     1,     1,     1,
       1,     1,     5,     1,     3,     0,     2,     3,     6,     3,
      10,     2,     0,     3,     0,     2,     1,     2,     1,     0,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     4,     7,    11,     7,     2,     2,     2,     3,
       3,     3,     3,     2,     3,     3,     2,     1,     1,     3,
       3,     1,     4,     2,     0,     3,     0,     3,     3,     3,
       3,     3,     3,     1,     1,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 131 "alfa.y" /* yacc.c:1646  */
    {
				fprintf(fout, ";R1:\t<programa> ::=	main { <declaraciones> <funciones> <sentencias> }\n");
				}
#line 1418 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 135 "alfa.y" /* yacc.c:1646  */
    {
				fprintf(fout, ";R1:\tprograma: main { <funciones> <sentencias> }\n");
				}
#line 1426 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 141 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R2:\t<declaraciones> ::= <declaracion>\n");
				}
#line 1434 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 145 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R3:\t<declaraciones> ::= <declaracion> <declaraciones>\n");
				}
#line 1442 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 150 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R4:\t<declaracion> ::= <clase> <identificadores> ;\n");
				}
#line 1450 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 159 "alfa.y" /* yacc.c:1646  */
    {
					clase_actual = ESCALAR;
					fprintf(fout, ";R5:\t<clase> ::= <clase_escalar>\n"); clase_actual = ESCALAR;
				}
#line 1459 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 164 "alfa.y" /* yacc.c:1646  */
    {
					clase_actual = VECTOR;
					fprintf(fout, ";R7:\t<clase> ::= <clase_vector>\n"); clase_actual = VECTOR;
				}
#line 1468 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 170 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R9:\t<clase_escalar> ::= <tipo>\n");
				}
#line 1476 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 178 "alfa.y" /* yacc.c:1646  */
    {
					tipo_actual = INT;
					fprintf(fout, ";R10:\t<tipo> ::= int\n"); tipo_actual = INT;
				}
#line 1485 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 183 "alfa.y" /* yacc.c:1646  */
    {
					tipo_actual = BOOLEAN;
					fprintf(fout, ";R11:\t<tipo> ::= boolean\n"); tipo_actual = BOOLEAN;
				}
#line 1494 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 194 "alfa.y" /* yacc.c:1646  */
    {
					
					if  (((yyvsp[-1].atributos).valor_entero < 1 )
					{
						yyerror("El vector tiene un tamano menor que 1.\n");
						return -1;
					}
					else if((yyvsp[-1].atributos).valor_entero > MAX_TAMANIO_VECTOR 1))
					{
						yyerror("El vector tiene un tamano mayor que el permitido.\n");
						return -1;
					}

					tamanio_vector_actual = (yyvsp[-1].atributos).valor_entero;

					fprintf(fout, ";R15:\t<clase_vector>: array <tipo> [ <constante_entera> ]");
				}
#line 1516 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 213 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R18:\t<identificadores> ::= <identificador> \n");
				}
#line 1524 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 217 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R19:\t<identificadores> ::= <identificador> , <identificadores>\n");
				}
#line 1532 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 222 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R21:\t<funciones> ::= \n");
				}
#line 1540 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 226 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R20:\t<funciones>: <funcion> <funciones>\n");
				}
#line 1548 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 235 "alfa.y" /* yacc.c:1646  */
    {
				  //COMPROBACIONES SEMANTICAS
				  //ERROR SI LA FUNCION NO TIENE SENTENCIA DE RETORNO
					if (hayReturn == 0)
					{
						yyerror("ERROR, la funcion no tiene sentencia de retorno\n");
						return -1;
					}
					if ((yyval.atributos).tipo != (yyvsp[-2].atributos).tipo)
					{
						yyerror("ERROR, el tipo de la funcion no coincide\n");
						return -1;
					}
				  //ERROR SI YA SE HA DECLARADO UNA FUNCION CON NOMBRE $1.lexema
					if (buscar_simbolo(TGLOBAL, (yyvsp[-2].atributos).lexema) != NULL)
					{
						yyerror("La funcion %s ha sido declarada dos veces.\n",(yyvsp[-2].atributos).lexema);
						return -1;
					}
				  //CIERRE DE AMBITO, ETC
				  simbolo->num_parametros = num_parametros;
				}
#line 1575 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 259 "alfa.y" /* yacc.c:1646  */
    {
				  //COMPROBACIONES SEMANTICAS
				  //ERROR SI YA SE HA DECLARADO UNA FUNCION CON NOMBRE $1.lexema
					if (buscar_simbolo(TGLOBAL, (yyvsp[-5].atributos).lexema) != NULL)
					{
						yyerror("La funcion %s ha sido declarada dos veces.\n",(yyvsp[-5].atributos).lexema);
						return -1;
					}
				  simbolo->num_parametros = num_parametros;
				  strcpy((yyval.atributos).lexema, (yyvsp[-5].atributos).lexema);
				  (yyval.atributos).tipo = (yyvsp[-5].atributos).tipo;
				  //GENERACION DE CODIGO
				  declararFuncion(out, (yyvsp[-5].atributos).lexema, num_variables_locales_actual);
				}
#line 1594 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 275 "alfa.y" /* yacc.c:1646  */
    {
  				//ERROR SI YA SE HA DECLARADO UNA FUNCION CON NOMBRE $3.lexema
					if (buscar_simbolo(TGLOBAL, (yyvsp[0].atributos).lexema) != NULL)
					{
						yyerror("El identificador %s ha sido declarado dos veces.\n",(yyvsp[0].atributos).lexema);
						return -1;
					}
  				simbolo.identificador = (yyvsp[0].atributos).lexema;
  				simbolo.cat_simbolo = FUNCION;
  				simbolo.tipo = tipo_actual;
  				(yyval.atributos).tipo = tipo_actual;
  				strcpy((yyval.atributos).lexema, (yyvsp[0].atributos).lexema);

  				//ABRIR AMBITO EN LA TABLA DE SIMBOLOS CON IDENTIFICADOR $3.lexema
					// TODO supongo adicionales como 0
					insertar_simbolo(TGLOBAL, (yyvsp[0].atributos).lexema, FUNCION, tipo_actual, clase_actual, 0, 0);

  				//RESETEAR VARIABLES QUE NECESITAMOS PARA PROCESAR LA FUNCION:
					num_variables_locales_actual = 0;
					pos_variable_local_actual = 1;
					num_parametros_actual = 0;
					pos_parametro_actual = 0;
				}
#line 1622 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 300 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R22:\t<funcion> ::= function <tipo> <identificador> ( <parametros_funcion> ) { <declaraciones_funcion> <sentencias> }\n");
				}
#line 1630 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 305 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R23:\t<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>\n");
				}
#line 1638 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 309 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R24:\t<parametros_funcion> ::= \n");
				}
#line 1646 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 314 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R25:\t<resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion> \n");
				}
#line 1654 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 318 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R26:\t<resto_parametros_funcion> ::= \n");
				}
#line 1662 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 323 "alfa.y" /* yacc.c:1646  */
    {
				  //INCREMENTAR CONTADORES, POR EJEMPLO
				  num_parametros++;
				  pos_parametro_actual++;
				}
#line 1672 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 335 "alfa.y" /* yacc.c:1646  */
    {
					// COMPROBACIONES SEMANTICAS PARA $1.lexema
					if (buscar_simbolo(TGLOBAL, (yyvsp[0].atributos).lexema) != NULL)
					{
						yyerror("El identificador %s ha sido declarado dos veces.\n",(yyvsp[0].atributos).lexema);
						return -1;
					}
    			
    			// DECLARAR SIMBOLO EN LA TABLA
					// Categoria = FUNCION. El tipo y clase los actuales
					insertar_simbolo(TGLOBAL, (yyvsp[0].atributos).lexema, FUNCION, tipo_actual, clase_actual, num_parametros_actual, pos_parametro_actual);
				}
#line 1689 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 349 "alfa.y" /* yacc.c:1646  */
    {
					// Incrementamos contadores
					num_parametros_actual++;
					pos_parametro_actual++;

					// Imprimimos la regla
					fprintf(fout, ";R27:\t<parametro_funcion> ::= <tipo> <identificador>\n");
				}
#line 1702 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 359 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R28:\t<declaraciones_funcion> ::= <declaraciones>\n");
				}
#line 1710 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 363 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R29:\t<declaraciones_funcion> ::=\n");
				}
#line 1718 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 368 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R30:\t<sentencias> ::= <sentencia> \n");
				}
#line 1726 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 372 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R31:\t<sentencias> ::= <sentencia> <sentencias> \n");
				}
#line 1734 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 377 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R32:\t<sentencia> ::= <sentencia_simple> ; \n");
				}
#line 1742 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 381 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R33:\t<sentencia> ::= <bloque>\n");
				}
#line 1750 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 386 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R34:\t<sentencia_simple> ::= <asignacion>\n");
				}
#line 1758 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 390 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R35:\t<sentencia_simple> ::= <lectura>\n");
				}
#line 1766 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 394 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R36:\t<sentencia_simple> ::= <escritura>\n");
				}
#line 1774 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 398 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R38:\t<sentencia_simple> ::= <retorno_funcion>\n");
				}
#line 1782 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 403 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R40:\t<bloque> ::= <condicional>\n");
				}
#line 1790 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 407 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R41:\t<bloque> ::= <bucle>\n");
				}
#line 1798 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 416 "alfa.y" /* yacc.c:1646  */
    {
					INFO_SIMBOLO simbolo = buscarSimbolo((yyvsp[-2].atributos).lexema);

					// Comprobamos que el simbolo existe
					if (simbolo == NULL)
					{
						errorSemantico ("[ERROR] Acceso a variable no declarada.\n");
						return -1;
					}
					// Comprobamos que no es funcion
					if (info->categoria == FUNCION)
					{
						errorSemantico ("[ERROR] Asignacion a funcion.\n");
						return -1;
					}
					// Comprobamos que no es vector
					if (info->clase == VECTOR)
					{
						errorSemantico ("[ERROR] Asignacion a vector.\n");
						return -1;
					}

					if (simbolo->tipo != (yyvsp[0].atributos).tipo){
						errorSemantico("[ERROR]. Los tipos no coinciden");
					}

					// Si la variable esta en el ambito local
					if (ambito_local((yyvsp[-2].atributos).lexema))
					{
						printf("PENDIENTE\n");
					}
					// Si la variable es global
					else
					{
						printf("PENDIENTE\n");
					}

					// Por ultimo, imprimimos
					fprintf(fout, ";R43:\t<asigancion> ::= <identificador> = <exp>\n");
				}
#line 1843 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 457 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R44:\t<asignacion> ::= <elemento_vector> = <exp>\n");
				}
#line 1851 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 462 "alfa.y" /* yacc.c:1646  */
    {
					INFO_SIMBOLO simbolo = buscarSimbolo((yyvsp[-3].atributos).lexema);

					// Comprobamos que el simbolo existe
					if (simbolo == NULL)
					{
						errorSemantico ("[ERROR] Acceso a variable no declarada.\n");
						return -1;
					}

					// Comprobamos que no es funcion
					if (info->categoria == FUNCION)
					{
						errorSemantico ("[ERROR] Asignacion a funcion.\n");
						return -1;
					}

					//si el ambito es local y no es una variable global dentro de un ambito local
					if(ambito_local((yyvsp[-3].atributos).lexema) == 1  && !(info->adicional2 == -1 && info->adicional1 == -1))
					{
			 			errorSemantico("No estan permitidas las variables locales de tipo no escalar.");
						return -1;
					}
					// Comprobamos que no es escalar
					if (info->clase == ESCALAR)
					{
						errorSemantico ("[ERROR] Asignacion a un elemento que no es vector.\n");
						return -1;
					}

					

					printf("PENDIENTE.\n");

					// SINTESIS
					strcpy((yyval.atributos).lexema, (yyvsp[-3].atributos).lexema);
					(yyval.atributos).tipo = info->tipo;

					fprintf(fout, ";R48:\t<elemento_vector> ::= <identificador> [ <exp> ]\n");
				}
#line 1896 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 504 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R50:\t<condicional> ::=	if ( <exp> ) { <sentencias> } \n");
				}
#line 1904 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 508 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R51:\t<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }\n");
				}
#line 1912 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 513 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R52:\tbucle ::= while ( <exp> ) { <sentencias> }\n");
				}
#line 1920 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 522 "alfa.y" /* yacc.c:1646  */
    {

					INFO_SIMBOLO simbolo = buscarSimbolo((yyvsp[0].atributos).lexema);

					// Comprobamos que el simbolo existe
					if (simbolo == NULL)
					{
						errorSemantico ("[ERROR] Acceso a variable no declarada.\n");
						return -1;
					}

					// Si la categoria es una funcion
					if (simbolo->categoria == FUNCION)
					{
						errorSemantico ("[ERROR] intento de scan a una funcion\n");
						return -1;
					}

					// Si la clase no es escalar
					if (simbolo->clase != escalar)
					{
						errorSemantico("[ERROR] intento de scan a un no escalar.\n");
						return -1;
					}

					if (es_local((yyvsp[0].atributos).lexema) == 1)
					{
						printf("PENDIENTE\n");
					}

					else
					{
						printf("PENDIENTE\n");
					}


					fprintf(fout, ";R54:\t<lectura> ::= scanf <identificador> \n");
				}
#line 1963 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 562 "alfa.y" /* yacc.c:1646  */
    {
					// GENERACION
					escribir(output, (yyvsp[0].atributos).es_direccion, (yyvsp[0].atributos).tipo);

					fprintf(fout, ";R56:\t<escritura> ::= printf <exp>\n");
				}
#line 1974 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 571 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R61:\t<retorno_funcion> ::= return<exp>\n");
				}
#line 1982 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 579 "alfa.y" /* yacc.c:1646  */
    {
					// El tipo tiene que ser entero.
					if((yyvsp[-2].atributos).tipo != ENTERO || (yyvsp[0].atributos).tipo != ENTERO)
					{
						errorSemantico("Operacion logica con operandos enteros.");
						return -1;
					}

					// GENERACION DE CODIGO
					sumar(output, (yyvsp[-2].atributos).es_variable, (yyvsp[0].atributos).es_variable);

					// SINTESIS
					(yyval.atributos).es_direccion = 0;
					(yyval.atributos).tipo = 1;

					fprintf(fout, ";R72:\t<exp> ::= <exp> + <exp>\n");
				}
#line 2004 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 597 "alfa.y" /* yacc.c:1646  */
    {
					// El tipo tiene que ser entero.
					if((yyvsp[-2].atributos).tipo != ENTERO || (yyvsp[0].atributos).tipo != ENTERO)
					{
						errorSemantico("Operacion logica con operandos enteros.");
						return -1;
					}

					// GENERACION DE CODIGO
					restar(output, (yyvsp[-2].atributos).es_variable, (yyvsp[0].atributos).es_variable);

					// SINTESIS
					(yyval.atributos).es_direccion = 0;
					(yyval.atributos).tipo = 1;

					fprintf(fout, ";R73:\t<exp> ::=  <exp> - <exp>\n");
				}
#line 2026 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 615 "alfa.y" /* yacc.c:1646  */
    {
					// El tipo tiene que ser entero.
					if((yyvsp[-2].atributos).tipo != ENTERO || (yyvsp[0].atributos).tipo != ENTERO)
					{
						errorSemantico("Operacion logica con operandos enteros.");
						return -1;
					}

					// GENERACION DE CODIGO
					dividir(output, (yyvsp[-2].atributos).es_variable, (yyvsp[0].atributos).es_variable);

					// SINTESIS
					(yyval.atributos).es_direccion = 0;
					(yyval.atributos).tipo = ENTERO;

					fprintf(fout, ";R74:\t<exp> ::=  <exp> / <exp>\n");
				}
#line 2048 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 633 "alfa.y" /* yacc.c:1646  */
    {
					// El tipo tiene que ser entero.
					if((yyvsp[-2].atributos).tipo != ENTERO || (yyvsp[0].atributos).tipo != ENTERO)
					{
						errorSemantico("Operacion logica con operandos enteros.");
						return -1;
					}

					// GENERACION DE CODIGO
					multiplicar(output, (yyvsp[-2].atributos).es_variable, (yyvsp[0].atributos).es_variable);

					// SINTESIS
					(yyval.atributos).es_direccion = 0;
					(yyval.atributos).tipo = ENTERO;

					fprintf(fout, ";R75:\t<exp> ::= <exp> * <exp>\n");
				}
#line 2070 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 651 "alfa.y" /* yacc.c:1646  */
    {
					// El tipo tiene que ser entero.
					if((yyvsp[0].atributos).tipo != ENTERO)
					{
						errorSemantico("Operacion logica con operandos enteros.");
						return -1;
					}

					// GENERACION DE CODIGO
					cambiar_signo(output, (yyvsp[0].atributos).es_variable);

					// SINTESIS
					(yyval.atributos).es_direccion = 0;
					(yyval.atributos).tipo = ENTERO;

					fprintf(fout, ";R76:\t<exp> ::= -<exp>\n");
				}
#line 2092 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 669 "alfa.y" /* yacc.c:1646  */
    {
					// El tipo tiene que ser entero.
					if((yyvsp[-2].atributos).tipo != BOOLEANO || (yyvsp[0].atributos).tipo != BOOLEANO)
					{
						errorSemantico("Operacion logica con operandos enteros.");
						return -1;
					}

					// GENERACION DE CODIGO
					y(output, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);

					// SINTESIS
					(yyval.atributos).es_direccion = 0;
					(yyval.atributos).tipo = BOOLEANO;

					fprintf(fout, ";R77:\t<exp> ::= <exp> && <exp>\n");
				}
#line 2114 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 687 "alfa.y" /* yacc.c:1646  */
    {
					// El tipo tiene que ser entero.
					if((yyvsp[-2].atributos).tipo != BOOLEANO || (yyvsp[0].atributos).tipo != BOOLEANO)
					{
						errorSemantico("Operacion logica con operandos enteros.");
						return -1;
					}

					// GENERACION DE CODIGO
					o(output, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);

					// SINTESIS
					(yyval.atributos).es_direccion = 0;
					(yyval.atributos).tipo = BOOLEANO;

					fprintf(fout, ";R78:\t<exp> ::= <exp> || <exp>\n");
				}
#line 2136 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 705 "alfa.y" /* yacc.c:1646  */
    {
					// El tipo tiene que ser entero.
					if((yyvsp[0].atributos).tipo != BOOLEANO)
					{
						errorSemantico("Operacion logica con operandos enteros.");
						return -1;
					}

					// GENERACION DE CODIGO
					no(output, (yyvsp[0].atributos).es_direccion, cuantos);
					cuantos++;

					// SINTESIS
					(yyval.atributos).es_direccion = 0;
					(yyval.atributos).tipo = BOOLEANO;

					fprintf(fout, ";R79:\t<exp> ::= !<exp>\n");
				}
#line 2159 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 724 "alfa.y" /* yacc.c:1646  */
    {
					INFO_SIMBOLO simbolo = buscarSimbolo((yyvsp[0].atributos).lexema);

					// Comprobamos que el simbolo existe
					if (simbolo == NULL)
					{
						errorSemantico ("[ERROR] Acceso a variable no declarada.\n");
						return -1;
					}

					// Si la categoria es una funcion
					if (simbolo->categoria == FUNCION)
					{
						errorSemantico ("[ERROR] intento de scan a una funcion\n");
						return -1;
					}

					// Si la clase es un vector
					if (simbolo->clase == VECTOR)
					{
						errorSemantico("[ERROR] intento de scan a un vector.\n");
						return -1;
					}

					printf("PENDIENTE\n");

					fprintf(fout, ";R80:\t<exp> ::= <identificador>\n");
				}
#line 2192 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 753 "alfa.y" /* yacc.c:1646  */
    {
					//SINTESIS
					(yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
					(yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;

					fprintf(fout, ";R81:\t<exp> ::= <constante> \n");
				}
#line 2204 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 761 "alfa.y" /* yacc.c:1646  */
    {
					// SINTESIS
					(yyval.atributos).tipo = (yyvsp[-1].atributos).tipo;
					(yyval.atributos).es_direccion = (yyvsp[-1].atributos).es_direccion;

					fprintf(fout, ";R82:\t<exp> ::= ( <exp> )\n");
				}
#line 2216 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 769 "alfa.y" /* yacc.c:1646  */
    {
					// SINTESIS
					(yyval.atributos).tipo = (yyvsp[-1].atributos).tipo;
					(yyval.atributos).es_direccion = (yyvsp[-1].atributos).es_direccion;

					fprintf(fout, ";R83:\t<exp> ::= ( <comparacion> )\n");
				}
#line 2228 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 777 "alfa.y" /* yacc.c:1646  */
    {
					// SINTESIS 
					(yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
					(yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;

					fprintf(fout, ";R85:\t<exp> ::= <elemento_vector>\n");
				}
#line 2240 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 785 "alfa.y" /* yacc.c:1646  */
    {
					printf("PENDIENTE\n");
					fprintf(fout, ";R88:\t<exp> ::= <identificador> ( <lista_expresiones> )\n");
				}
#line 2249 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 791 "alfa.y" /* yacc.c:1646  */
    {
					 // SINTESIS
					num_parametros_llamada_actual++;

					fprintf(fout, ";R89:\t<lista_expresiones> ::= <exp> <resto_lista_expresiones> \n");
				}
#line 2260 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 798 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R90:\t<lista_expresiones> ::= \n");
				}
#line 2268 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 803 "alfa.y" /* yacc.c:1646  */
    {
					// SINTESIS
					num_parametros_llamada_actual++;

					fprintf(fout, ";R91:\t<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones> \n");
				}
#line 2279 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 810 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R92:\t<resto_lista_expresiones> ::=  \n");
				}
#line 2287 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 818 "alfa.y" /* yacc.c:1646  */
    {
					// El tipo tiene que ser entero.
					if((yyvsp[-2].atributos).tipo != ENTERO || (yyvsp[0].atributos).tipo != ENTERO)
					{
						errorSemantico("Comparacion con operandos booleanos.");
						return -1;
					}

					// GENERACION DE CODIGO
					igual(output, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, cuantos);
					cuantos++;

					// SINTESIS
					(yyval.atributos).es_direccion = 0;
					(yyval.atributos).tipo = BOOLEANO;

					fprintf(fout, ";R93:\t<comparacion> ::= <exp> == <exp> \n");
				}
#line 2310 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 837 "alfa.y" /* yacc.c:1646  */
    {
					// El tipo tiene que ser entero.
					if((yyvsp[-2].atributos).tipo != ENTERO || (yyvsp[0].atributos).tipo != ENTERO)
					{
						errorSemantico("Comparacion con operandos booleanos.");
						return -1;
					}

					// GENERACION DE CODIGO
					distinto(output, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, cuantos);
					cuantos++;

					// SINTESIS
					(yyval.atributos).es_direccion = 0;
					(yyval.atributos).tipo = BOOLEANO;

					fprintf(fout, ";R94:\t<comparacion> ::= <exp> != exp\n");
				}
#line 2333 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 856 "alfa.y" /* yacc.c:1646  */
    {
					// El tipo tiene que ser entero.
					if((yyvsp[-2].atributos).tipo != ENTERO || (yyvsp[0].atributos).tipo != ENTERO)
					{
						errorSemantico("Comparacion con operandos booleanos.");
						return -1;
					}

					// GENERACION DE CODIGO
					mayor_igual(output, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, cuantos);
					cuantos++;

					// SINTESIS
					(yyval.atributos).es_direccion = 0;
					(yyval.atributos).tipo = BOOLEANO;

					fprintf(fout, ";R95:\t<comparacion> ::= <exp> >= exp\n");
				}
#line 2356 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 875 "alfa.y" /* yacc.c:1646  */
    {
					// El tipo tiene que ser entero.
					if((yyvsp[-2].atributos).tipo != ENTERO || (yyvsp[0].atributos).tipo != ENTERO)
					{
						errorSemantico("Comparacion con operandos booleanos.");
						return -1;
					}

					// GENERACION DE CODIGO
					menor_igual(output, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, cuantos);
					cuantos++;

					// SINTESIS
					(yyval.atributos).es_direccion = 0;
					(yyval.atributos).tipo = BOOLEANO;

					fprintf(fout, ";R96:\t<comparacion> ::= <exp> TOK_MENORIGUAL exp\n");
				}
#line 2379 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 894 "alfa.y" /* yacc.c:1646  */
    {
					// El tipo tiene que ser entero.
					if((yyvsp[-2].atributos).tipo != ENTERO || (yyvsp[0].atributos).tipo != ENTERO)
					{
						errorSemantico("Comparacion con operandos booleanos.");
						return -1;
					}

					// GENERACION DE CODIGO
					mayor(output, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, cuantos);
					cuantos++;

					// SINTESIS
					(yyval.atributos).es_direccion = 0;
					(yyval.atributos).tipo = BOOLEANO;

					fprintf(fout, ";R97:\t<comparacion> ::= exp > <exp>\n");
				}
#line 2402 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 913 "alfa.y" /* yacc.c:1646  */
    {
					// El tipo tiene que ser entero.
					if((yyvsp[-2].atributos).tipo != ENTERO || (yyvsp[0].atributos).tipo != ENTERO)
					{
						errorSemantico("Comparacion con operandos booleanos.");
						return -1;
					}

					// GENERACION DE CODIGO
					menor(output, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, cuantos);
					cuantos++;

					// SINTESIS
					(yyval.atributos).es_direccion = 0;
					(yyval.atributos).tipo = BOOLEANO;

					fprintf(fout, ";R98:\t<comparacion> ::= exp < <exp>\n");
				}
#line 2425 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 933 "alfa.y" /* yacc.c:1646  */
    {
					// SINTESIS
					(yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
					(yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;

					fprintf(fout, ";R99:\t<constante> ::= <constante_logica> \n");
				}
#line 2437 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 941 "alfa.y" /* yacc.c:1646  */
    {
					// SINTESIS
					(yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
					(yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;

					fprintf(fout, ";R100:\t<constante> ::= <constante_entera> \n");
				}
#line 2449 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 950 "alfa.y" /* yacc.c:1646  */
    {
					// SINTESIS
					(yyval.atributos).tipo = BOOLEANO;
					(yyval.atributos).es_direccion = FALSE;
					(yyval.atributos).valor_entero = TRUE;

					// GENERACION
					escribir_operando(output, "1", 0);

					fprintf(fout, ";R102:\t<constante_logica> ::= true \n");
				}
#line 2465 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 962 "alfa.y" /* yacc.c:1646  */
    {
					// SINTESIS
					(yyval.atributos).tipo = BOOLEANO;
					(yyval.atributos).es_direccion = FALSE;
					(yyval.atributos).valor_entero = TRUE;

					// GENERACION
					escribir_operando(output, "0", 0);

					fprintf(fout, ";R103:\t<constante_logica> ::= false \n");
				}
#line 2481 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 975 "alfa.y" /* yacc.c:1646  */
    {
					// SINTESIS
					(yyval.atributos).tipo = ENTERO;
					(yyval.atributos).es_direccion = FALSE;
					(yyval.atributos).valor_entero = (yyvsp[0].atributos).valor_entero;

					// GENERACION
					escribir_operando(output, (yyvsp[0].atributos).lexema, 0);//en $1.lexema guardo la string del valor_entero 
					
					fprintf(fout, ";R104:\t<constante_entera> ::= <numero> \n");
				}
#line 2497 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 997 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R110:\t<cola_identificador> ::= <alfanumerico> \n");
				}
#line 2505 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1001 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R111:\t<cola_identificador> ::= <alfanumerico><cola_identificador> \n");
				}
#line 2513 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1006 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R112:\t<alfanumerico> ::= <letra> \n");
				}
#line 2521 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1010 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R113:\t<alfanumerico> ::= <digito> \n");
				}
#line 2529 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1015 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R114:\t<letra> ::= a|b|...|z|A|B|...|Z \n");
				}
#line 2537 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1020 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R115:\t<digito> ::= 0|1|2|3|4|5|6|7|8|9 \n");
				}
#line 2545 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1025 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R108:\t<identificador> ::= TOK_IDENTIFICADOR \n");
				}
#line 2553 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1029 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R109:\t<identificador> ::= <letra><cola_identificador> \n");
				}
#line 2561 "alfa.tab.c" /* yacc.c:1646  */
    break;


#line 2565 "alfa.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1033 "alfa.y" /* yacc.c:1906  */


void yyerror(char* s) {
	fprintf(stdout,"****Error sintactico en [lin %d, col %d]\n", line, col);
}


void errorSemantico (char *msg)
{
  fprintf(stderr,"****Error semantico en lin %d: %s\n", line, msg);
}
