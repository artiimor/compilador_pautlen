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
	#include "tablasimbolos.h"

	#include "y.tab.h"
	
	extern int line;
	extern int col;
	extern FILE* fout;

	int pos_parametro_actual = 0; /* Indica en que parametro estamos */
	int num_parametros_actual = 0; /* Contador del numero de parametros */
	int num_variables_locales_actual = 0; /* contador de varibles locales */
	int pos_variable_local_actual = 0; /* Indica en que variable local estamos */
	int hayReturn = 0; /* Indica si la funcion tiene return para cde */
	int tiporeturn;
	int cuantos = 0;/* esta variable es un contador para generar saltos unicos */
 	int num_parametros_llamada_actual = 0;
	int clase_actual;
	int tipo_actual;
	int tamanio_vector_actual;
	int etiqueta = 0;



#line 97 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    TOK_BOOLEANO = 260,
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
/* Tokens.  */
#define TOK_MAIN 258
#define TOK_INT 259
#define TOK_BOOLEANO 260
#define TOK_ARRAY 261
#define TOK_FUNCTION 262
#define TOK_IF 263
#define TOK_ELSE 264
#define TOK_WHILE 265
#define TOK_SCANF 266
#define TOK_PRINTF 267
#define TOK_RETURN 268
#define TOK_IDENTIFICADOR 269
#define TOK_PUNTOYCOMA 270
#define TOK_COMA 271
#define TOK_PARENTESISIZQUIERDO 272
#define TOK_PARENTESISDERECHO 273
#define TOK_CORCHETEIZQUIERDO 274
#define TOK_CORCHETEDERECHO 275
#define TOK_LLAVEIZQUIERDA 276
#define TOK_LLAVEDERECHA 277
#define TOK_ASIGNACION 278
#define TOK_MAS 279
#define TOK_MENOS 280
#define TOK_DIVISION 281
#define TOK_ASTERISCO 282
#define TOK_AND 283
#define TOK_OR 284
#define TOK_NOT 285
#define TOK_IGUAL 286
#define TOK_DISTINTO 287
#define TOK_MENORIGUAL 288
#define TOK_MAYORIGUAL 289
#define TOK_MENOR 290
#define TOK_MAYOR 291
#define TOK_CONSTANTE_ENTERA 292
#define TOK_FALSE 293
#define TOK_TRUE 294
#define TOK_ERROR 295
#define fn_complete_name 296
#define if_exp 297
#define if_exp_sentencias 298
#define tipo_retorno 299
#define MENOSU 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 33 "alfa.y" /* yacc.c:355  */

	tipo_atributos atributos;
	

#line 232 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 249 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   178

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  169

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
       0,   134,   134,   139,   146,   156,   158,   161,   167,   172,
     181,   187,   193,   201,   206,   217,   236,   240,   246,   249,
     262,   286,   304,   329,   337,   342,   346,   351,   360,   381,
     393,   399,   403,   407,   412,   416,   421,   425,   429,   433,
     438,   442,   451,   512,   518,   560,   564,   573,   579,   584,
     600,   643,   652,   660,   678,   696,   714,   732,   750,   768,
     786,   805,   837,   848,   857,   866,   874,   880,   888,   892,
     900,   907,   926,   945,   964,   983,  1002,  1022,  1030,  1039,
    1051,  1064,  1086,  1091,  1096,  1100,  1105,  1110,  1116,  1141
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_MAIN", "TOK_INT", "TOK_BOOLEANO",
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
  "'='", "'>'", "'<'", "$accept", "programa", "inicio", "escritura_main",
  "escribir_fin", "declaraciones", "declaracion", "clase", "clase_escalar",
  "tipo", "clase_vector", "identificadores", "funciones", "funcion",
  "fn_declaration", "fn_name", "parametros_funcion",
  "resto_parametros_funcion", "idpf", "parametro_funcion",
  "declaraciones_funcion", "sentencias", "sentencia", "sentencia_simple",
  "bloque", "asignacion", "elemento_vector", "condicional", "bucle",
  "while", "while_exp", "lectura", "escritura", "retorno_funcion", "exp",
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

#define YYPACT_NINF -40

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-40)))

#define YYTABLE_NINF -89

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -40,    16,    48,   -40,     7,   103,   -40,   -40,    41,    41,
      50,   134,    49,   -40,   -40,   -40,   -40,    50,   147,    38,
       8,    52,   -40,   -40,   -21,    14,    -6,    24,   147,   -40,
      28,    42,    90,     4,     4,   -39,    91,   147,    59,   -40,
     -40,    61,   -40,   -40,     4,   147,   -40,   -40,   -40,    41,
      81,    71,   147,   -40,   -40,   -40,   -40,    -6,   -40,   -40,
      49,    79,     4,   -40,   -40,    -1,   -40,   -40,   -40,     4,
       4,     4,   -40,   106,   -40,   -40,   -40,    75,   106,     4,
       4,   -40,   -40,   -40,     4,    31,    84,   127,   126,    92,
      94,    41,    95,   -40,   -40,   -40,    36,   -40,   -40,    69,
      88,     4,     4,     4,     4,     4,     4,     4,   -22,   106,
     106,    99,   -40,   -40,   -40,   135,    41,   -40,   -40,   104,
     -40,   112,     4,     4,     4,     4,   -40,     4,     4,   -40,
     -40,    40,    40,    40,   -40,   -40,    77,   107,   -40,   -40,
     134,    92,   113,   -40,   147,   106,   106,   106,   106,   106,
     106,     4,   -40,   -40,   -40,   -40,   -40,   134,   114,    77,
     147,   158,   -40,   116,   118,   -40,   147,   119,   -40
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     1,     0,    18,    13,    14,     0,     0,
      18,     7,     0,    10,    12,    11,     5,    18,     0,     0,
       0,     0,     5,     8,    86,     0,     0,    16,     0,    19,
       0,     0,     0,     0,     0,     0,     0,    32,     0,    35,
      36,     0,    40,    41,     0,     0,    37,    38,    39,    25,
       0,    22,     0,     9,    86,    87,    89,    82,    84,    85,
       0,     0,     0,    48,    50,    61,    81,    80,    79,     0,
       0,     0,    65,    51,    62,    77,    78,     0,    52,     0,
       0,    20,    33,    34,     0,     0,     0,     0,     0,    27,
       0,    25,     0,    83,    17,     3,     0,    57,    60,     0,
       0,     0,     0,     0,     0,     0,     0,    68,     0,    42,
      43,     0,    47,    28,    29,     0,     0,    24,    15,     0,
       6,     0,     0,     0,     0,     0,    63,     0,     0,    64,
      58,    59,    53,    54,    56,    55,    70,     0,    44,    49,
      31,    27,     0,     2,     0,    71,    72,    74,    73,    75,
      76,     0,    67,    66,    30,    21,    26,    31,     0,    70,
       0,    45,    69,     0,     0,    23,     0,     0,    46
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -40,   -40,   -40,   148,   -40,     6,   -40,   -40,   -40,    -5,
     -40,   115,    11,   -40,   -40,   -40,    82,    33,   -40,    56,
      19,   -23,   -40,   -40,   -40,   -40,   -18,   -40,   -40,   -40,
     -40,   -40,   -40,   -40,   -32,   -40,    18,   -40,   -40,   -40,
     -40,   121,   -40,   -17,   -40,   -11
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    28,   143,   154,    11,    12,    13,    14,
      15,    25,    16,    17,    18,    19,    88,   117,   114,    89,
     155,    36,    37,    38,    39,    40,    72,    42,    43,    44,
      45,    46,    47,    48,    73,   137,   152,   100,    74,    75,
      76,    56,    57,    26,    59,    77
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      41,    27,    78,    20,    21,    61,   101,   102,    54,    58,
      41,    10,    85,   -86,    82,    79,     3,    23,    65,    41,
      80,    22,    86,   103,   104,   105,   106,    41,    29,    92,
      96,    55,   -88,   138,    41,   -88,   -86,    97,    98,    99,
      58,    66,    67,    68,    87,     6,     7,   108,   109,    27,
      69,     4,   110,    79,    70,    49,   -88,     9,     5,   101,
     102,    71,    50,    24,   101,   102,    51,    53,   101,   130,
     131,   132,   133,   134,   135,   136,   103,   104,   105,   106,
      60,   103,   104,   105,   106,    62,    87,   105,   106,   111,
     145,   146,   147,   148,   121,   149,   150,   101,   102,    63,
     122,   123,   124,   125,    64,   101,   102,     6,     7,     8,
       9,    87,    83,    81,   103,   104,   105,   106,    90,   159,
      84,   158,   103,   104,   105,   106,    41,   126,    91,   127,
     128,    95,   107,   151,   101,   102,   112,   163,     6,     7,
       8,   113,    41,   167,   115,   116,   129,   120,    41,   118,
     139,   103,   104,   105,   106,    30,   140,    31,    32,    33,
      34,    35,   142,   144,   157,   153,   161,   164,   165,   166,
      52,   168,   141,   119,   156,    94,   160,   162,    93
};

static const yytype_uint8 yycheck[] =
{
      18,    12,    34,     8,     9,    28,    28,    29,    14,    26,
      28,     5,    44,    14,    37,    54,     0,    11,    14,    37,
      59,    10,    45,    45,    46,    47,    48,    45,    17,    52,
      62,    37,    53,    55,    52,    56,    37,    69,    70,    71,
      57,    37,    38,    39,    49,     4,     5,    79,    80,    60,
      46,     3,    84,    54,    50,    17,    57,     7,    51,    28,
      29,    57,    54,    14,    28,    29,    14,    53,    28,   101,
     102,   103,   104,   105,   106,   107,    45,    46,    47,    48,
      56,    45,    46,    47,    48,    57,    91,    47,    48,    58,
     122,   123,   124,   125,    58,   127,   128,    28,    29,    57,
      31,    32,    33,    34,    14,    28,    29,     4,     5,     6,
       7,   116,    53,    22,    45,    46,    47,    48,    37,   151,
      59,   144,    45,    46,    47,    48,   144,    58,    57,    60,
      61,    52,    57,    56,    28,    29,    52,   160,     4,     5,
       6,    14,   160,   166,    18,    53,    58,    52,   166,    55,
      51,    45,    46,    47,    48,     8,    21,    10,    11,    12,
      13,    14,    58,    51,    51,    58,    52,     9,    52,    51,
      22,    52,   116,    91,   141,    60,   157,   159,    57
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    63,    64,     0,     3,    51,     4,     5,     6,     7,
      67,    68,    69,    70,    71,    72,    74,    75,    76,    77,
      71,    71,    74,    67,    14,    73,   105,   107,    65,    74,
       8,    10,    11,    12,    13,    14,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    17,
      54,    14,    65,    53,    14,    37,   103,   104,   105,   106,
      56,    83,    57,    57,    14,    14,    37,    38,    39,    46,
      50,    57,    88,    96,   100,   101,   102,   107,    96,    54,
      59,    22,    83,    53,    59,    96,    83,    71,    78,    81,
      37,    57,    83,   103,    73,    52,    96,    96,    96,    96,
      99,    28,    29,    45,    46,    47,    48,    57,    96,    96,
      96,    58,    52,    14,    80,    18,    53,    79,    55,    78,
      52,    58,    31,    32,    33,    34,    58,    60,    61,    58,
      96,    96,    96,    96,    96,    96,    96,    97,    55,    51,
      21,    81,    58,    66,    51,    96,    96,    96,    96,    96,
      96,    56,    98,    58,    67,    82,    79,    51,    83,    96,
      82,    52,    98,    83,     9,    52,    51,    83,    52
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    63,    63,    64,    65,    66,    67,    67,    68,
      69,    69,    70,    71,    71,    72,    73,    73,    74,    74,
      75,    76,    77,    75,    78,    78,    79,    79,    80,    81,
      82,    82,    83,    83,    84,    84,    85,    85,    85,    85,
      86,    86,    87,    87,    88,    89,    89,    90,    91,    92,
      93,    94,    95,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    97,    97,    98,
      98,    99,    99,    99,    99,    99,    99,   100,   100,   101,
     101,   102,   103,   103,   104,   104,   105,   106,   107,   107
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     9,     7,     0,     0,     0,     1,     2,     3,
       1,     1,     1,     1,     1,     5,     1,     3,     0,     2,
       3,     6,     3,    10,     2,     0,     3,     0,     1,     2,
       1,     0,     1,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     4,     7,    11,     3,     2,     4,
       2,     2,     2,     3,     3,     3,     3,     2,     3,     3,
       2,     1,     1,     3,     3,     1,     4,     2,     0,     3,
       0,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     2
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
#line 135 "alfa.y" /* yacc.c:1646  */
    {
					
					fprintf(fout, ";R1:\t<programa> ::=	main { <declaraciones> <funciones> <sentencias> }\n");
				}
#line 1463 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 140 "alfa.y" /* yacc.c:1646  */
    {
					
				fprintf(fout, ";R1:\tprograma: main { <funciones> <sentencias> }\n");
				}
#line 1472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 146 "alfa.y" /* yacc.c:1646  */
    {	crearAmbitoGlobal();
					escribir_subseccion_data(fout);
					escribir_cabecera_bss(fout); 
					pos_parametro_actual = 0;
					num_parametros_actual = 0;
					num_variables_locales_actual = 0;
					pos_variable_local_actual = 0;
					num_parametros_llamada_actual = 0;}
#line 1485 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 156 "alfa.y" /* yacc.c:1646  */
    {	escribir_inicio_main(fout);  }
#line 1491 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 158 "alfa.y" /* yacc.c:1646  */
    {	escribir_fin(fout);  }
#line 1497 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 162 "alfa.y" /* yacc.c:1646  */
    {
					
					fprintf(fout, ";R2:\t<declaraciones> ::= <declaracion>\n");
					escribir_segmento_codigo(fout);
				}
#line 1507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 168 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R3:\t<declaraciones> ::= <declaracion> <declaraciones>\n");
				}
#line 1515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 173 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R4:\t<declaracion> ::= <clase> <identificadores> ;\n");
				}
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 182 "alfa.y" /* yacc.c:1646  */
    {
					clase_actual = ESCALAR;
					
					fprintf(fout, ";R5:\t<clase> ::= <clase_escalar>\n"); clase_actual = ESCALAR;
				}
#line 1533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 188 "alfa.y" /* yacc.c:1646  */
    {
					clase_actual = VECTOR;
					fprintf(fout, ";R7:\t<clase> ::= <clase_vector>\n"); clase_actual = VECTOR;
				}
#line 1542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 194 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R9:\t<clase_escalar> ::= <tipo>\n");
				}
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 202 "alfa.y" /* yacc.c:1646  */
    {
					tipo_actual = ENTERO;
					fprintf(fout, ";R10:\t<tipo> ::= int\n");
				}
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 207 "alfa.y" /* yacc.c:1646  */
    {
					tipo_actual = BOOLEANO;
					fprintf(fout, ";R11:\t<tipo> ::= BOOLEANO\n"); tipo_actual = BOOLEANO;
				}
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 218 "alfa.y" /* yacc.c:1646  */
    {
					
					if  ((yyvsp[-1].atributos).valor_entero < 1 )
					{
						yyerror("El vector tiene un tamano menor que 1.\n");
						return -1;
					}
					else if((yyvsp[-1].atributos).valor_entero > MAX_TAMANIO_VECTOR)
					{
						yyerror("El vector tiene un tamano mayor que el permitido.\n");
						return -1;
					}

					tamanio_vector_actual = (yyvsp[-1].atributos).valor_entero;

					fprintf(fout, ";R15:\t<clase_vector>: array <tipo> [ <constante_entera> ]");
				}
#line 1590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 237 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R18:\t<identificadores> ::= <identificador> \n");
				}
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 241 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R19:\t<identificadores> ::= <identificador> , <identificadores>\n");
				}
#line 1606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 246 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R21:\t<funciones> ::= \n");
				}
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 250 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R20:\t<funciones>: <funcion> <funciones>\n");
				}
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 263 "alfa.y" /* yacc.c:1646  */
    {
					printf("DECLARACION DE PUTA MADRE\n");
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
					if (buscarSimbolo((yyvsp[-2].atributos).lexema) != NULL)
					{
						yyerror("La funcion %s ha sido declarada dos veces.\n",(yyvsp[-2].atributos).lexema);
						return -1;
					}
				  //CIERRE DE AMBITO, ETC
				}
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 287 "alfa.y" /* yacc.c:1646  */
    {
					printf("ME CAGO EN MIS PUTOS MUERTOS\n");
				  //COMPROBACIONES SEMANTICAS
				  //ERROR SI YA SE HA DECLARADO UNA FUNCION CON NOMBRE $1.lexema
					if (buscarSimbolo((yyvsp[-5].atributos).lexema) != NULL)
					{
						errorSemantico("La funcion ha sido declarada dos veces.\n",(yyvsp[-5].atributos).lexema);
						return -1;
					}
				  // simbolo->num_parametros = num_parametros_actual;
				  strcpy((yyval.atributos).lexema, (yyvsp[-5].atributos).lexema);
				  (yyval.atributos).tipo = (yyvsp[-5].atributos).tipo;
				  //GENERACION DE CODIGO
					printf("HOLA AMEGO\n");
				  
				}
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 305 "alfa.y" /* yacc.c:1646  */
    {
					printf("en el nombre de la funcion\n");
  				//ERROR SI YA SE HA DECLARADO UNA FUNCION CON NOMBRE $3.lexema
					if (buscarSimbolo((yyvsp[0].atributos).lexema) != NULL)
					{
						yyerror("El identificador %s ha sido declarado dos veces.\n",(yyvsp[0].atributos).lexema);
						return -1;
					}

  				(yyval.atributos).tipo = tipo_actual;
  				strcpy((yyval.atributos).lexema, (yyvsp[0].atributos).lexema);

  				//ABRIR AMBITO EN LA TABLA DE SIMBOLOS CON IDENTIFICADOR $3.lexema
					// TODO supongo adicionales como 0
					crearAmbitoLocal((yyvsp[0].atributos).lexema, crear_info_simbolo((yyvsp[0].atributos).lexema, FUNCION, tipo_actual, clase_actual, 0, 0));

  				//RESETEAR VARIABLES QUE NECESITAMOS PARA PROCESAR LA FUNCION:
					num_variables_locales_actual = 0;
					pos_variable_local_actual = 1;
					num_parametros_actual = 0;
					pos_parametro_actual = 0;

				}
#line 1698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 330 "alfa.y" /* yacc.c:1646  */
    {
					printf("PRUEBITA\n");
					retornarFuncion(fout, tiporeturn); 
					tiporeturn=0; 
					fprintf(fout, ";R22:\t<funcion> ::= function <tipo> <identificador> ( <parametros_funcion> ) { <declaraciones_funcion> <sentencias> }\n");
				}
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 338 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R23:\t<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>\n");
				}
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 342 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R24:\t<parametros_funcion> ::= \n");
				}
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 347 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R25:\t<resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion> \n");
				}
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 351 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R26:\t<resto_parametros_funcion> ::= \n");
				}
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 361 "alfa.y" /* yacc.c:1646  */
    {
					printf("INSERTAMOS UN SIMBOLO:\n");
					errorSemantico((yyvsp[0].atributos).lexema);
					// COMPROBACIONES SEMANTICAS PARA $1.lexema
					if (buscarSimbolo((yyvsp[0].atributos).lexema) != NULL)
					{
						yyerror("El identificador %s ha sido declarado dos veces.\n",(yyvsp[0].atributos).lexema);
						return -1;
					}
    			// DECLARAR SIMBOLO EN LA TABLA
					// Categoria = FUNCION. El tipo y clase los actuales
					insertarSimbolo(crear_info_simbolo((yyvsp[0].atributos).lexema, FUNCION, tipo_actual, clase_actual, num_parametros_actual, num_variables_locales_actual));
					if (buscarSimbolo((yyvsp[0].atributos).lexema) == NULL)
					{
						printf("ME CAGO EN LA PUTA\n");
						yyerror("El identificador %s ha sido declarado dos veces.\n",(yyvsp[0].atributos).lexema);
						return -1;
					}
				}
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 382 "alfa.y" /* yacc.c:1646  */
    {
					
					printf("FUNCION\n");
					// Incrementamos contadores
					num_parametros_actual++;
					pos_parametro_actual++;

					// Imprimimos la regla
					fprintf(fout, ";R27:\t<parametro_funcion> ::= <tipo> <identificador>\n");
				}
#line 1780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 394 "alfa.y" /* yacc.c:1646  */
    {
					
					fprintf(fout, ";R28:\t<declaraciones_funcion> ::= <declaraciones>\n");
				}
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 399 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R29:\t<declaraciones_funcion> ::=\n");
				}
#line 1797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 404 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R30:\t<sentencias> ::= <sentencia> \n");
				}
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 408 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R31:\t<sentencias> ::= <sentencia> <sentencias> \n");
				}
#line 1813 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 413 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R32:\t<sentencia> ::= <sentencia_simple> ; \n");
				}
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 417 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R33:\t<sentencia> ::= <bloque>\n");
				}
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 422 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R34:\t<sentencia_simple> ::= <asignacion>\n");
				}
#line 1837 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 426 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R35:\t<sentencia_simple> ::= <lectura>\n");
				}
#line 1845 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 430 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R36:\t<sentencia_simple> ::= <escritura>\n");
				}
#line 1853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 434 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R38:\t<sentencia_simple> ::= <retorno_funcion>\n");
				}
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 439 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R40:\t<bloque> ::= <condicional>\n");
				}
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 443 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R41:\t<bloque> ::= <bucle>\n");
				}
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 452 "alfa.y" /* yacc.c:1646  */
    {
					INFO_SIMBOLO *simbolo = buscarSimbolo((yyvsp[-2].atributos).lexema);

					// Comprobamos que el simbolo existe
					if (simbolo == NULL)
					{
						errorSemantico ("[ERROR] La variable no ha sido declarada.\n");
						return -1;
					}
					// Comprobamos que no es funcion
					/*if (simbolo->categoria == FUNCION)
					{
						errorSemantico ("[ERROR] Asignacion a funcion.\n");
						return -1;
					}
					// Comprobamos que no es vector
					if (simbolo->clase == VECTOR)
					{
						errorSemantico ("[ERROR] Asignacion a vector.\n");
						return -1;
					} 

					if (simbolo->tipo != $3.tipo){
						errorSemantico("[ERROR]. Los tipos no coinciden");
					} */

					// Si la variable esta en el ambito local
					if (es_local((yyvsp[-2].atributos).lexema))
					{
						printf("PENDIENTE LOCAL\n");
					}
					// Si la variable es global
					else
					{
						INFO_SIMBOLO* info = buscarSimbolo((yyvsp[-2].atributos).lexema);
					if(info == NULL)
					{
						errorSemantico("Acceso a variable no declarada\n");
						return -1;
					} else if(info->categoria == FUNCION)
					{
						errorSemantico("asignacion a funcion\n");
						return -1;
					} else if(info->clase == VECTOR)
					{
						errorSemantico("asignacion a vector\n");
						return -1;
					} else if(info->tipo != (yyvsp[0].atributos).tipo)
					{
						errorSemantico("error en los tipos.\n");
						return -1;
					}

					// DECLARAMOS
					asignar(fout, (yyvsp[-2].atributos).lexema, tipo_actual);

					// Por ultimo, imprimimos
					fprintf(fout, ";R43:\t<asigancion> ::= <identificador> = <exp>\n");
				}
				}
#line 1942 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 513 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R44:\t<asignacion> ::= <elemento_vector> = <exp>\n");
				}
#line 1950 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 519 "alfa.y" /* yacc.c:1646  */
    {
					INFO_SIMBOLO *simbolo = buscarSimbolo((yyvsp[-3].atributos).lexema);

					// Comprobamos que el simbolo existe
					if (simbolo == NULL)
					{
						errorSemantico ("[ERROR] Acceso a variable no declarada. $1.lexema\n");
						return -1;
					}

					// Comprobamos que no es funcion
					if (simbolo->categoria == FUNCION)
					{
						errorSemantico ("[ERROR] Asignacion a funcion.\n");
						return -1;
					}

					//si el ambito es local y no es una variable global dentro de un ambito local
					if(es_local((yyvsp[-3].atributos).lexema) == 1  && !(simbolo->adicional2 == -1 && simbolo->adicional1 == -1))
					{
			 			errorSemantico("No estan permitidas las variables locales de tipo no escalar.");
						return -1;
					}
					// Comprobamos que no es escalar
					if (simbolo->clase == ESCALAR)
					{
						errorSemantico ("[ERROR] Asignacion a un elemento que no es vector.\n");
						return -1;
					}

					

					printf("PENDIENTE.\n");

					// SINTESIS
					strcpy((yyval.atributos).lexema, (yyvsp[-3].atributos).lexema);
					(yyval.atributos).tipo = simbolo->tipo;

					fprintf(fout, ";R48:\t<elemento_vector> ::= <identificador> [ <exp> ]\n");
				}
#line 1995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 561 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R50:\t<condicional> ::=	if ( <exp> ) { <sentencias> } \n");
				}
#line 2003 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 565 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R51:\t<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }\n");
				}
#line 2011 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 573 "alfa.y" /* yacc.c:1646  */
    {
	
  while_fin(fout, (yyvsp[-2].atributos).etiqueta);
	fprintf(fout, ";R52:\tbucle ::= while ( <exp> ) { <sentencias> }\n");
	}
#line 2021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 579 "alfa.y" /* yacc.c:1646  */
    {
	(yyval.atributos).etiqueta = etiqueta++;
  while_inicio(fout, (yyval.atributos).etiqueta);
}
#line 2030 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 584 "alfa.y" /* yacc.c:1646  */
    {
	//COMPROBACIONES SEMANTICAS (VER SI EL TIPO DE exp ES BOOLEAN)
  printf("NENENE\n");
	if ((yyvsp[-2].atributos).tipo != BOOLEANO)
	{
		errorSemantico("BUCLE sin expresion booleana\n");
		return -1;
	}
	(yyval.atributos).etiqueta = (yyvsp[-3].atributos).etiqueta;
  while_exp_pila(fout, (yyvsp[-2].atributos).es_direccion, (yyval.atributos).etiqueta);
}
#line 2046 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 601 "alfa.y" /* yacc.c:1646  */
    {

					INFO_SIMBOLO *simbolo = buscarSimbolo((yyvsp[0].atributos).lexema);

					// Comprobamos que el simbolo existe
					if (simbolo == NULL)
					{
						printf("HOLA\n");
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
					if (simbolo->clase != ESCALAR)
					{
						errorSemantico("[ERROR] intento de scan a un no escalar.\n");
						return -1;
					}

					if (es_local((yyvsp[0].atributos).lexema) == 1)
					{
						printf("PENDIENTE1\n");
					}

					// VAMOS A ESCANEAR UNA VARIABLE GLOBAL
					else
					{
						// GENERACION CODIGO
						leer(fout, (yyvsp[0].atributos).lexema, tipo_actual);
					}


					fprintf(fout, ";R54:\t<lectura> ::= scanf <identificador> \n");
				}
#line 2092 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 644 "alfa.y" /* yacc.c:1646  */
    {
					// GENERACION
					escribir(fout, !(yyvsp[0].atributos).es_direccion, (yyvsp[0].atributos).tipo);

					fprintf(fout, ";R56:\t<escritura> ::= printf <exp>\n");
				}
#line 2103 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 653 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R61:\t<retorno_funcion> ::= return<exp>\n");
				}
#line 2111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 661 "alfa.y" /* yacc.c:1646  */
    {
					// El tipo tiene que ser entero.
					if((yyvsp[-2].atributos).tipo != ENTERO || (yyvsp[0].atributos).tipo != ENTERO)
					{
						errorSemantico("Operacion logica con operandos enteros.");
						return -1;
					}

					// GENERACION DE CODIGO
					sumar(fout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);

					// SINTESIS
					(yyval.atributos).es_direccion = 0;
					(yyval.atributos).tipo = ENTERO;

					fprintf(fout, ";R72:\t<exp> ::= <exp> + <exp>\n");
				}
#line 2133 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 679 "alfa.y" /* yacc.c:1646  */
    {
					// El tipo tiene que ser entero.
					if((yyvsp[-2].atributos).tipo != ENTERO || (yyvsp[0].atributos).tipo != ENTERO)
					{
						errorSemantico("Operacion logica con operandos enteros.");
						return -1;
					}

					// GENERACION DE CODIGO
					restar(fout, !(yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);

					// SINTESIS
					(yyval.atributos).es_direccion = 0;
					(yyval.atributos).tipo = ENTERO;

					fprintf(fout, ";R73:\t<exp> ::=  <exp> - <exp>\n");
				}
#line 2155 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 697 "alfa.y" /* yacc.c:1646  */
    {
					// El tipo tiene que ser entero.
					if((yyvsp[-2].atributos).tipo != ENTERO || (yyvsp[0].atributos).tipo != ENTERO)
					{
						errorSemantico("Operacion logica con operandos enteros.");
						return -1;
					}

					// GENERACION DE CODIGO
					dividir(fout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);

					// SINTESIS
					(yyval.atributos).es_direccion = 0;
					(yyval.atributos).tipo = ENTERO;

					fprintf(fout, ";R74:\t<exp> ::=  <exp> / <exp>\n");
				}
#line 2177 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 715 "alfa.y" /* yacc.c:1646  */
    {
					// El tipo tiene que ser entero.
					if((yyvsp[-2].atributos).tipo != ENTERO || (yyvsp[0].atributos).tipo != ENTERO)
					{
						errorSemantico("Operacion logica con operandos enteros.");
						return -1;
					}

					// GENERACION DE CODIGO
					multiplicar(fout, !(yyvsp[-2].atributos).es_direccion, !(yyvsp[0].atributos).es_direccion);

					// SINTESIS
					(yyval.atributos).es_direccion = 0;
					(yyval.atributos).tipo = ENTERO;

					fprintf(fout, ";R75:\t<exp> ::= <exp> * <exp>\n");
				}
#line 2199 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 733 "alfa.y" /* yacc.c:1646  */
    {
					// El tipo tiene que ser entero.
					if((yyvsp[0].atributos).tipo != ENTERO)
					{
						errorSemantico("Operacion logica con operandos enteros.");
						return -1;
					}

					// GENERACION DE CODIGO
					cambiar_signo(fout, (yyvsp[0].atributos).es_direccion);

					// SINTESIS
					(yyval.atributos).es_direccion = 0;
					(yyval.atributos).tipo = ENTERO;

					fprintf(fout, ";R76:\t<exp> ::= -<exp>\n");
				}
#line 2221 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 751 "alfa.y" /* yacc.c:1646  */
    {
					// El tipo tiene que ser entero.
					if((yyvsp[-2].atributos).tipo != BOOLEANO || (yyvsp[0].atributos).tipo != BOOLEANO)
					{
						errorSemantico("Operacion logica con operandos enteros.");
						return -1;
					}

					// GENERACION DE CODIGO
					y(fout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);

					// SINTESIS
					(yyval.atributos).es_direccion = 0;
					(yyval.atributos).tipo = BOOLEANO;

					fprintf(fout, ";R77:\t<exp> ::= <exp> && <exp>\n");
				}
#line 2243 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 769 "alfa.y" /* yacc.c:1646  */
    {
					// El tipo tiene que ser entero.
					if((yyvsp[-2].atributos).tipo != BOOLEANO || (yyvsp[0].atributos).tipo != BOOLEANO)
					{
						errorSemantico("Operacion logica con operandos enteros.");
						return -1;
					}

					// GENERACION DE CODIGO
					o(fout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);

					// SINTESIS
					(yyval.atributos).es_direccion = 0;
					(yyval.atributos).tipo = BOOLEANO;

					fprintf(fout, ";R78:\t<exp> ::= <exp> || <exp>\n");
				}
#line 2265 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 787 "alfa.y" /* yacc.c:1646  */
    {
					// El tipo tiene que ser entero.
					if((yyvsp[0].atributos).tipo != BOOLEANO)
					{
						errorSemantico("Operacion logica con operandos enteros.");
						return -1;
					}

					// GENERACION DE CODIGO
					no(fout, (yyvsp[0].atributos).es_direccion, cuantos);
					cuantos++;

					// SINTESIS
					(yyval.atributos).es_direccion = 0;
					(yyval.atributos).tipo = BOOLEANO;

					fprintf(fout, ";R79:\t<exp> ::= !<exp>\n");
				}
#line 2288 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 806 "alfa.y" /* yacc.c:1646  */
    {
					
					INFO_SIMBOLO *simbolo = buscarSimbolo((yyvsp[0].atributos).lexema);

					// Comprobamos que el simbolo existe
					printf("HOLA\n");
					if (simbolo == 0)
					{
						errorSemantico ("[ERROR] Acceso a variable no declarada.\n");
						errorSemantico((yyvsp[0].atributos).lexema);
						return -1;
					}
					
					// Si la categoria es una funcion
					printf("%d\n",simbolo);
					if (simbolo->categoria == FUNCION)
					{
						errorSemantico ("[ERROR] intento de scan a una funcion\n");
					}
					
					// Si la clase es un vector
					if (simbolo->clase == VECTOR)
					{
						errorSemantico("[ERROR] intento de scan a un vector.\n");
						return -1;
					}

					printf("PENDIENTE\n");
					escribir_operando(fout, (yyvsp[0].atributos).lexema, !(yyvsp[0].atributos).es_direccion);
					fprintf(fout, ";R80:\t<exp> ::= <identificador>\n");
				}
#line 2324 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 838 "alfa.y" /* yacc.c:1646  */
    {
					//SINTESIS
					(yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
					(yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;

					// GENERACION
					escribir_operando(fout, (yyvsp[0].atributos).lexema, (yyvsp[0].atributos).es_direccion);

					fprintf(fout, ";R81:\t<exp> ::= <constante> \n");
				}
#line 2339 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 849 "alfa.y" /* yacc.c:1646  */
    {
					printf("VENGA YA\n");
					// SINTESIS
					(yyval.atributos).tipo = (yyvsp[-1].atributos).tipo;
					(yyval.atributos).es_direccion = (yyvsp[-1].atributos).es_direccion;

					fprintf(fout, ";R82:\t<exp> ::= ( <exp> )\n");
				}
#line 2352 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 858 "alfa.y" /* yacc.c:1646  */
    {
					printf("COJONUDO\n");
					// SINTESIS
					(yyval.atributos).tipo = BOOLEANO;
					(yyval.atributos).es_direccion = (yyvsp[-1].atributos).es_direccion;

					fprintf(fout, ";R83:\t<exp> ::= ( <comparacion> )\n");
				}
#line 2365 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 867 "alfa.y" /* yacc.c:1646  */
    {
					// SINTESIS 
					(yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
					(yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;

					fprintf(fout, ";R85:\t<exp> ::= <elemento_vector>\n");
				}
#line 2377 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 875 "alfa.y" /* yacc.c:1646  */
    {
					printf("PENDIENTE\n");
					fprintf(fout, ";R88:\t<exp> ::= <identificador> ( <lista_expresiones> )\n");
				}
#line 2386 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 881 "alfa.y" /* yacc.c:1646  */
    {
					 // SINTESIS
					num_parametros_llamada_actual++;

					fprintf(fout, ";R89:\t<lista_expresiones> ::= <exp> <resto_lista_expresiones> \n");
				}
#line 2397 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 888 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R90:\t<lista_expresiones> ::= \n");
				}
#line 2405 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 893 "alfa.y" /* yacc.c:1646  */
    {
					// SINTESIS
					num_parametros_llamada_actual++;

					fprintf(fout, ";R91:\t<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones> \n");
				}
#line 2416 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 900 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R92:\t<resto_lista_expresiones> ::=  \n");
				}
#line 2424 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 908 "alfa.y" /* yacc.c:1646  */
    {
					// El tipo tiene que ser entero.
					if((yyvsp[-2].atributos).tipo != ENTERO || (yyvsp[0].atributos).tipo != ENTERO)
					{
						errorSemantico("Comparacion con operandos BOOLEANOs.");
						return -1;
					}

					// GENERACION DE CODIGO
					igual(fout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, cuantos);
					cuantos++;

					// SINTESIS
					(yyval.atributos).es_direccion = 0;
					(yyval.atributos).tipo = BOOLEANO;

					fprintf(fout, ";R93:\t<comparacion> ::= <exp> == <exp> \n");
				}
#line 2447 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 927 "alfa.y" /* yacc.c:1646  */
    {
					// El tipo tiene que ser entero.
					if((yyvsp[-2].atributos).tipo != ENTERO || (yyvsp[0].atributos).tipo != ENTERO)
					{
						errorSemantico("Comparacion con operandos BOOLEANOs.");
						return -1;
					}

					// GENERACION DE CODIGO
					distinto(fout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, cuantos);
					cuantos++;

					// SINTESIS
					(yyval.atributos).es_direccion = 0;
					(yyval.atributos).tipo = BOOLEANO;

					fprintf(fout, ";R94:\t<comparacion> ::= <exp> != exp\n");
				}
#line 2470 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 946 "alfa.y" /* yacc.c:1646  */
    {
					// El tipo tiene que ser entero.
					if((yyvsp[-2].atributos).tipo != ENTERO || (yyvsp[0].atributos).tipo != ENTERO)
					{
						errorSemantico("Comparacion con operandos BOOLEANOs.");
						return -1;
					}

					// GENERACION DE CODIGO
					mayor_igual(fout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, cuantos);
					cuantos++;

					// SINTESIS
					(yyval.atributos).es_direccion = 0;
					(yyval.atributos).tipo = BOOLEANO;

					fprintf(fout, ";R95:\t<comparacion> ::= <exp> >= exp\n");
				}
#line 2493 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 965 "alfa.y" /* yacc.c:1646  */
    {
					// El tipo tiene que ser entero.
					if((yyvsp[-2].atributos).tipo != ENTERO || (yyvsp[0].atributos).tipo != ENTERO)
					{
						errorSemantico("Comparacion con operandos BOOLEANOs.");
						return -1;
					}

					// GENERACION DE CODIGO
					menor_igual(fout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, cuantos);
					cuantos++;

					// SINTESIS
					(yyval.atributos).es_direccion = 0;
					(yyval.atributos).tipo = BOOLEANO;

					fprintf(fout, ";R96:\t<comparacion> ::= <exp> TOK_MENORIGUAL exp\n");
				}
#line 2516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 984 "alfa.y" /* yacc.c:1646  */
    {
					// El tipo tiene que ser entero.
					if((yyvsp[-2].atributos).tipo != ENTERO || (yyvsp[0].atributos).tipo != ENTERO)
					{
						errorSemantico("Comparacion con operandos BOOLEANOs.");
						return -1;
					}

					// GENERACION DE CODIGO
					mayor(fout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, cuantos);
					cuantos++;

					// SINTESIS
					(yyval.atributos).es_direccion = 0;
					(yyval.atributos).tipo = BOOLEANO;

					fprintf(fout, ";R98:\t<comparacion> ::= exp > <exp>\n");
				}
#line 2539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1003 "alfa.y" /* yacc.c:1646  */
    {
					// El tipo tiene que ser entero.
					if((yyvsp[-2].atributos).tipo != ENTERO || (yyvsp[0].atributos).tipo != ENTERO)
					{
						errorSemantico("Comparacion con operandos BOOLEANOs.");
						return -1;
					}

					// GENERACION DE CODIGO
					menor(fout, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion, cuantos);
					cuantos++;

					// SINTESIS
					(yyval.atributos).es_direccion = 0;
					(yyval.atributos).tipo = BOOLEANO;

					fprintf(fout, ";R97:\t<comparacion> ::= exp < <exp>\n");
				}
#line 2562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 1023 "alfa.y" /* yacc.c:1646  */
    {
					// SINTESIS
					(yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
					(yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;

					fprintf(fout, ";R99:\t<constante> ::= <constante_logica> \n");
				}
#line 2574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 1031 "alfa.y" /* yacc.c:1646  */
    {
					// SINTESIS
					(yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
					(yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;

					fprintf(fout, ";R100:\t<constante> ::= <constante_entera> \n");
				}
#line 2586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1040 "alfa.y" /* yacc.c:1646  */
    {
					// SINTESIS
					(yyval.atributos).tipo = BOOLEANO;
					(yyval.atributos).es_direccion = FALSE;
					(yyval.atributos).valor_entero = TRUE;

					// GENERACION
					escribir_operando(fout, "1", 0);

					fprintf(fout, ";R102:\t<constante_logica> ::= true \n");
				}
#line 2602 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1052 "alfa.y" /* yacc.c:1646  */
    {
					// SINTESIS
					(yyval.atributos).tipo = BOOLEANO;
					(yyval.atributos).es_direccion = FALSE;
					(yyval.atributos).valor_entero = TRUE;

					// GENERACION
					escribir_operando(fout, "0", 0);

					fprintf(fout, ";R103:\t<constante_logica> ::= false \n");
				}
#line 2618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1065 "alfa.y" /* yacc.c:1646  */
    {
					
					// SINTESIS
					(yyval.atributos).tipo = ENTERO;
					(yyval.atributos).es_direccion = FALSE;
					(yyval.atributos).valor_entero = (yyvsp[0].atributos).valor_entero;

					
					
					fprintf(fout, ";R104:\t<constante_entera> ::= <numero> \n");
				}
#line 2634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1087 "alfa.y" /* yacc.c:1646  */
    {
					
					fprintf(fout, ";R110:\t<cola_identificador> ::= <alfanumerico> \n");
				}
#line 2643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1092 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R111:\t<cola_identificador> ::= <alfanumerico><cola_identificador> \n");
				}
#line 2651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1097 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R112:\t<alfanumerico> ::= <letra> \n");
				}
#line 2659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1101 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R113:\t<alfanumerico> ::= <digito> \n");
				}
#line 2667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1106 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R114:\t<letra> ::= a|b|...|z|A|B|...|Z \n");
				}
#line 2675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1111 "alfa.y" /* yacc.c:1646  */
    {
					
					fprintf(fout, ";R115:\t<digito> ::= 0|1|2|3|4|5|6|7|8|9 \n");
				}
#line 2684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1117 "alfa.y" /* yacc.c:1646  */
    {

					if (existe_local() == 0)
					{	
						// NO HAY AMBITO LOCAL
						if (clase_actual == ESCALAR){
							pos_variable_local_actual++;
							num_variables_locales_actual++;
							printf("declaramos\n");

							// ANADIMOS A LA TABLA HASH
							insertarSimbolo(crear_info_simbolo((yyvsp[0].atributos).lexema, VARIABLE, tipo_actual, clase_actual, 0, 0));

							//GENERAMOS EL CODIGO
							declarar_variable(fout, (yyvsp[0].atributos).lexema, (yyvsp[0].atributos).tipo, clase_actual);
						}
						else{
							errorSemantico("ERROR. Variable de tipo no escalar");
							return -1;
						}
					}

					fprintf(fout, ";R108:\t<identificador> ::= TOK_IDENTIFICADOR \n");
				}
#line 2713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1142 "alfa.y" /* yacc.c:1646  */
    {
					fprintf(fout, ";R109:\t<identificador> ::= <letra><cola_identificador> \n");
				}
#line 2721 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2725 "y.tab.c" /* yacc.c:1646  */
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
#line 1146 "alfa.y" /* yacc.c:1906  */


void yyerror(char* s) {
	fprintf(stdout,"****Error sintactico en [lin %d, col %d]\n", line, col);
}

void errorSemantico (char *s)
{
  fprintf(stderr,"****Error semantico en lin %d: %s\n", line, s);
}
