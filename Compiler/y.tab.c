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
#line 2 "compiler_hw3.y" /* yacc.c:339  */

    #include "common.h" //Extern variables that communicate with lex
    // #define YYDEBUG 1
    // int yydebug = 1;

    #define codegen(...) \
        do { \
            for (int i = 0; i < INDENT; i++) { \
                fprintf(fout, "\t"); \
            } \
            fprintf(fout, __VA_ARGS__); \
        } while (0)

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;
    extern char* yytext;
    
    /* Other global variables */
    FILE *fout = NULL;
    bool HAS_ERROR = false;
    int INDENT = 0;
    int tag=0;
    int ltag=0;
    int itag=0;
    int elif=0;
    
    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
    }
    typedef struct variable
    {
        int index;
        char* name;
        char* type;
        int address;
        int lineno;
        char* element_type;
        struct variable* next;
    }variable;

    variable* sym_tb=NULL; //head of each symbol_tables
    int level=0; //scope level 
    int myIndex=0;//current index
    int address=0;//address
    /* Symbol table function - you can add new function if needed. */
    void dump_symbol();
    void insert_variable( char* name , char*type,int lineno,char* element_type );
     void create_symbol();
     char* eletype_of(char* name);
     char* type_of(char* name);
     int  line_of(char* name);
     bool check_whole(char* name);
     bool check_entry(char* name);
     int address_of(char* name);


#line 125 "y.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
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
    INT = 258,
    FLOAT = 259,
    BOOL = 260,
    STRING = 261,
    INC = 262,
    DEC = 263,
    SEMICOLON = 264,
    PRINT = 265,
    OR = 266,
    AND = 267,
    NOT = 268,
    WHILE = 269,
    ADD_ASSIGN = 270,
    SUB_ASSIGN = 271,
    MUL_ASSIGN = 272,
    QUO_ASSIGN = 273,
    REM_ASSIGN = 274,
    IF = 275,
    ELSE = 276,
    LEQ = 277,
    GEQ = 278,
    EQL = 279,
    NEQ = 280,
    FOR = 281,
    INT_LIT = 282,
    FLOAT_LIT = 283,
    STRING_LIT = 284,
    IDENT = 285,
    TRUE = 286,
    FALSE = 287
  };
#endif
/* Tokens.  */
#define INT 258
#define FLOAT 259
#define BOOL 260
#define STRING 261
#define INC 262
#define DEC 263
#define SEMICOLON 264
#define PRINT 265
#define OR 266
#define AND 267
#define NOT 268
#define WHILE 269
#define ADD_ASSIGN 270
#define SUB_ASSIGN 271
#define MUL_ASSIGN 272
#define QUO_ASSIGN 273
#define REM_ASSIGN 274
#define IF 275
#define ELSE 276
#define LEQ 277
#define GEQ 278
#define EQL 279
#define NEQ 280
#define FOR 281
#define INT_LIT 282
#define FLOAT_LIT 283
#define STRING_LIT 284
#define IDENT 285
#define TRUE 286
#define FALSE 287

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 66 "compiler_hw3.y" /* yacc.c:355  */

    int i_val;
    float f_val;
    char *s_val;
    /* ... */

#line 236 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 253 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  52
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   323

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  105
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  201

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    46,     2,     2,
      33,    34,    44,    42,     2,    43,     2,    45,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      41,    35,    40,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    36,     2,    37,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,    39,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   107,   107,   112,   113,   120,   121,   122,   123,   127,
     132,   137,   143,   148,   156,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   188,   188,   188,   191,   191,   191,
     191,   207,   208,   209,   212,   213,   214,   222,   222,   222,
     226,   246,   261,   277,   291,   309,   323,   345,   346,   347,
     348,   349,   350,   355,   356,   357,   358,   359,   360,   361,
     362,   363,   364,   365,   370,   370,   370,   380,   388,   392,
     398,   436,   452,   470,   482,   486,   498,   501,   529,   545,
     561,   562,   579,   595,   598,   614,   629,   632,   643,   654,
     673,   676,   677,   686,   687,   692,   704,   708,   724,   761,
     783,   805,   811,   838,   861,   882
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "BOOL", "STRING", "INC",
  "DEC", "SEMICOLON", "PRINT", "OR", "AND", "NOT", "WHILE", "ADD_ASSIGN",
  "SUB_ASSIGN", "MUL_ASSIGN", "QUO_ASSIGN", "REM_ASSIGN", "IF", "ELSE",
  "LEQ", "GEQ", "EQL", "NEQ", "FOR", "INT_LIT", "FLOAT_LIT", "STRING_LIT",
  "IDENT", "TRUE", "FALSE", "'('", "')'", "'='", "'['", "']'", "'{'",
  "'}'", "'>'", "'<'", "'+'", "'-'", "'*'", "'/'", "'%'", "$accept",
  "program", "statementlist", "typename", "literal", "id", "statement",
  "forstmt", "$@1", "$@2", "forclause", "$@3", "$@4", "$@5", "simpleexpr",
  "ifstmt", "frontif", "$@6", "$@7", "assignstmt", "whilestmt", "$@8",
  "$@9", "condition", "begin_block", "end_block", "printstmt",
  "incdecstmt", "expression", "andexpr", "cmpexpr", "addexpr", "mulexpr",
  "unaryexpr", "arraysub", "declarationstmt", YY_NULLPTR
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
     285,   286,   287,    40,    41,    61,    91,    93,   123,   125,
      62,    60,    43,    45,    42,    47,    37
};
# endif

#define YYPACT_NINF -120

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-120)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     234,  -120,  -120,  -120,  -120,   -22,   255,     3,    19,    21,
    -120,  -120,  -120,  -120,  -120,  -120,    85,  -120,   255,   255,
      24,   234,    25,   274,   114,  -120,  -120,  -120,    17,    47,
    -120,   234,  -120,    67,     8,    14,   282,   -10,    -5,  -120,
      70,   255,  -120,    46,  -120,  -120,   255,   255,    52,    -6,
    -120,  -120,  -120,  -120,     9,   255,   255,   255,   255,   255,
     255,   255,  -120,  -120,   255,   255,   255,   255,   255,   255,
     255,  -120,   -13,  -120,    48,  -120,  -120,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
    -120,    12,   255,   255,    58,    82,    62,    88,  -120,  -120,
      82,   113,  -120,   255,   255,    82,    82,    82,    82,    82,
      82,    -7,    82,    82,    82,    82,    82,    82,    -3,  -120,
     234,  -120,  -120,    14,   282,   -10,   -10,   -10,   -10,   -10,
     -10,    -5,    -5,  -120,  -120,  -120,    90,    -2,    66,    64,
      64,  -120,  -120,    46,    82,     5,   240,   284,   203,  -120,
    -120,  -120,  -120,  -120,   255,  -120,    68,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,  -120,
      64,   234,   234,  -120,   255,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,   234,   234,   234,
      95,    82,   203,    48,    48,  -120,  -120,  -120,  -120,   255,
    -120
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,     6,     8,     7,     0,     0,     0,     0,     0,
       9,    10,    11,    14,    12,    13,     0,    68,     0,     0,
       0,     2,     0,    96,    97,     4,    23,    22,    36,     0,
      19,     0,    18,     0,     0,    74,    76,    83,    86,    90,
       0,     0,    96,    97,    94,    64,     0,     0,     0,     0,
      93,    92,     1,     3,   102,     0,     0,     0,     0,     0,
       0,     0,    71,    72,     0,     0,     0,     0,     0,     0,
       0,    95,     0,    21,     0,    17,    16,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      15,     0,     0,     0,     0,    67,     0,     0,    31,    33,
      32,     0,    91,     0,     0,    53,    54,    55,    56,    57,
      52,     0,    41,    42,    43,    44,    45,    40,     0,    35,
       0,    69,    20,    73,    75,    79,    80,    81,    82,    77,
      78,    84,    85,    87,    88,    89,     0,     0,     0,     0,
       0,    27,   100,    99,   103,     0,     0,   101,     0,    70,
     101,    65,    37,    24,     0,    98,   104,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    34,
       0,     0,     0,    28,     0,    59,    61,    60,    62,    63,
      58,    47,    49,    48,    50,    51,    46,     0,    38,    25,
       0,   105,     0,     0,     0,    29,    66,    39,    26,     0,
      30
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -120,  -120,  -107,    93,     0,     6,    -9,  -120,  -120,  -120,
    -120,  -120,  -120,  -120,   -89,    39,  -120,  -120,  -120,   -46,
    -120,  -120,  -120,   -73,   -62,  -119,  -120,   -44,     2,    42,
      45,   232,   -35,    -4,   -19,  -120
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    20,    21,    22,    42,    43,    25,    26,   172,   194,
      96,   154,   190,   199,    97,    27,    28,   171,   193,    29,
      30,    93,   170,    94,    31,   122,    32,    33,    34,    35,
      36,    37,    38,    39,    71,    40
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      23,    98,    44,    99,    77,    77,    24,     8,    77,    77,
     120,    41,    53,   148,    50,    51,    77,    76,    49,    77,
     138,    23,    74,    77,    52,    17,    78,    24,   102,   169,
     146,    23,    85,    86,   147,   150,    45,    24,    72,    87,
      88,    89,   156,    91,   103,   104,   136,    23,    95,   100,
     131,   132,    46,    24,    47,    54,    73,   105,   106,   107,
     108,   109,   110,   111,   188,   189,   112,   113,   114,   115,
     116,   117,   118,   196,   197,   198,    75,   152,   153,    90,
     192,   173,    92,   133,   134,   135,   101,   121,     1,     2,
       3,     4,   139,    77,   137,    95,   140,   141,     6,   149,
     151,   142,    17,   174,   195,   144,   145,   143,   187,    48,
     200,   119,    10,    11,    12,    13,    14,    15,    16,   123,
      23,    62,    63,   124,   155,     0,    24,    18,    19,    64,
      65,    66,    67,    68,     0,     0,     0,     0,     0,    53,
      10,    11,    12,    13,    14,    15,     0,     0,    23,    69,
      70,     0,     0,    98,    24,    99,    95,     0,     0,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,    23,    23,     0,     0,     0,   191,    24,    24,    53,
      53,     0,     0,    53,     0,     0,     0,    23,    23,    23,
       0,     0,    23,    24,    24,    24,     0,     0,    24,    23,
       0,   100,     0,     0,     0,    24,     1,     2,     3,     4,
       0,     0,     0,     5,     0,     0,     6,     7,     0,     0,
       0,     0,     0,     8,     0,     0,     0,     0,     0,     9,
      10,    11,    12,    13,    14,    15,    16,     1,     2,     3,
       4,    17,   121,     0,     5,    18,    19,     6,     7,     0,
       0,     0,     0,     0,     8,   157,   158,   159,   160,   161,
       9,    10,    11,    12,    13,    14,    15,    16,     6,     0,
       0,     0,    17,     0,     0,   162,    18,    19,     0,     0,
       0,     0,    10,    11,    12,    13,    14,    15,    16,    55,
      56,    57,    58,    59,     0,     0,     0,    18,    19,   163,
     164,   165,   166,   167,    79,    80,    81,    82,     0,    60,
      61,   125,   126,   127,   128,   129,   130,     0,     0,   168,
       0,     0,    83,    84
};

static const yytype_int16 yycheck[] =
{
       0,    47,     6,    47,    11,    11,     0,    20,    11,    11,
      72,    33,    21,   120,    18,    19,    11,     9,    16,    11,
      93,    21,    31,    11,     0,    38,    12,    21,    34,   148,
      37,    31,    42,    43,    37,    37,    33,    31,    21,    44,
      45,    46,    37,    41,    35,    36,    34,    47,    46,    47,
      85,    86,    33,    47,    33,    30,     9,    55,    56,    57,
      58,    59,    60,    61,   171,   172,    64,    65,    66,    67,
      68,    69,    70,   192,   193,   194,     9,   139,   140,     9,
     187,   154,    36,    87,    88,    89,    34,    39,     3,     4,
       5,     6,    34,    11,    92,    93,    34,     9,    13,     9,
      34,   101,    38,    35,     9,   103,   104,   101,   170,    16,
     199,    72,    27,    28,    29,    30,    31,    32,    33,    77,
     120,     7,     8,    78,   143,    -1,   120,    42,    43,    15,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,    -1,   148,
      27,    28,    29,    30,    31,    32,    -1,    -1,   148,    35,
      36,    -1,    -1,   199,   148,   199,   154,    -1,    -1,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   171,   172,    -1,    -1,    -1,   174,   171,   172,   188,
     189,    -1,    -1,   192,    -1,    -1,    -1,   187,   188,   189,
      -1,    -1,   192,   187,   188,   189,    -1,    -1,   192,   199,
      -1,   199,    -1,    -1,    -1,   199,     3,     4,     5,     6,
      -1,    -1,    -1,    10,    -1,    -1,    13,    14,    -1,    -1,
      -1,    -1,    -1,    20,    -1,    -1,    -1,    -1,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,     3,     4,     5,
       6,    38,    39,    -1,    10,    42,    43,    13,    14,    -1,
      -1,    -1,    -1,    -1,    20,    15,    16,    17,    18,    19,
      26,    27,    28,    29,    30,    31,    32,    33,    13,    -1,
      -1,    -1,    38,    -1,    -1,    35,    42,    43,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32,    33,    15,
      16,    17,    18,    19,    -1,    -1,    -1,    42,    43,    15,
      16,    17,    18,    19,    22,    23,    24,    25,    -1,    35,
      36,    79,    80,    81,    82,    83,    84,    -1,    -1,    35,
      -1,    -1,    40,    41
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,    10,    13,    14,    20,    26,
      27,    28,    29,    30,    31,    32,    33,    38,    42,    43,
      48,    49,    50,    51,    52,    53,    54,    62,    63,    66,
      67,    71,    73,    74,    75,    76,    77,    78,    79,    80,
      82,    33,    51,    52,    80,    33,    33,    33,    50,    75,
      80,    80,     0,    53,    30,    15,    16,    17,    18,    19,
      35,    36,     7,     8,    15,    16,    17,    18,    19,    35,
      36,    81,    21,     9,    53,     9,     9,    11,    12,    22,
      23,    24,    25,    40,    41,    42,    43,    44,    45,    46,
       9,    75,    36,    68,    70,    75,    57,    61,    66,    74,
      75,    34,    34,    35,    36,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    62,
      71,    39,    72,    76,    77,    78,    78,    78,    78,    78,
      78,    79,    79,    80,    80,    80,    34,    75,    70,    34,
      34,     9,    51,    52,    75,    75,    37,    37,    49,     9,
      37,    34,    71,    71,    58,    81,    37,    15,    16,    17,
      18,    19,    35,    15,    16,    17,    18,    19,    35,    72,
      69,    64,    55,    70,    35,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    71,    49,    49,
      59,    75,    49,    65,    56,     9,    72,    72,    72,    60,
      61
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    50,    50,    50,    51,
      51,    51,    51,    51,    52,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    55,    56,    54,    58,    59,    60,
      57,    61,    61,    61,    62,    62,    62,    64,    65,    63,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    68,    69,    67,    70,    71,    72,
      73,    74,    74,    75,    75,    76,    76,    77,    77,    77,
      77,    77,    77,    77,    78,    78,    78,    79,    79,    79,
      79,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    81,    82,    82,    82,    82
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     1,     1,
       3,     2,     1,     1,     0,     0,     9,     0,     0,     0,
       8,     1,     1,     1,     5,     3,     1,     0,     0,     9,
       3,     3,     3,     3,     3,     3,     6,     6,     6,     6,
       6,     6,     3,     3,     3,     3,     3,     3,     6,     6,
       6,     6,     6,     6,     0,     0,     9,     1,     1,     1,
       5,     2,     2,     3,     1,     3,     1,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       1,     3,     2,     2,     2,     2,     1,     1,     5,     4,
       4,     3,     2,     4,     5,     7
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
        case 5:
#line 120 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val)="int";}
#line 1495 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 121 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val)="float";}
#line 1501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 122 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val)="string";}
#line 1507 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 123 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val)="bool";}
#line 1513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 127 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("INT_LIT %d\n", (yyval.i_val));
        codegen("ldc %d\n", (yyval.i_val));
        (yyval.s_val)="int";
    }
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 132 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("FLOAT_LIT %f\n", (yyval.f_val));
        codegen("ldc %f\n", (yyval.f_val));
        (yyval.s_val)="float";
    }
#line 1533 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 137 "compiler_hw3.y" /* yacc.c:1646  */
    {
         printf("STRING_LIT %s\n", (yyval.s_val));
        codegen("ldc \"%s\"\n", (yyval.s_val));
         (yyval.s_val)="string";
    }
#line 1543 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 143 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("TRUE\n");
        codegen("ldc 1\n");
        (yyval.s_val)="bool";
        }
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 148 "compiler_hw3.y" /* yacc.c:1646  */
    {
        codegen("ldc 0\n");
        printf("FALSE\n");
        (yyval.s_val)="bool";
    }
#line 1563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 156 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if(check_whole((yyvsp[0].s_val))){
            printf("IDENT (name=%s, address=%d)\n",(yyvsp[0].s_val),address_of((yyvsp[0].s_val)));
            
            (yyval.s_val)=(yyvsp[0].s_val);
        }
        else{
            HAS_ERROR=true;
            printf("error:%d: undefined: %s\n",yylineno,(yyvsp[0].s_val));
            (yyval.s_val)="error";
        }
       


    }
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 188 "compiler_hw3.y" /* yacc.c:1646  */
    {fprintf(fout,"For_Body%d:\n",level-1);}
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 188 "compiler_hw3.y" /* yacc.c:1646  */
    {codegen("goto Arith%d\n",level-1);}
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 188 "compiler_hw3.y" /* yacc.c:1646  */
    {fprintf(fout,"For_End%d:\n",level);}
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 191 "compiler_hw3.y" /* yacc.c:1646  */
    {fprintf(fout,"Condition%d:\n",level); }
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 191 "compiler_hw3.y" /* yacc.c:1646  */
    {codegen("ifeq For_End%d\n",level);  codegen("goto For_Body%d\n",level);}
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 191 "compiler_hw3.y" /* yacc.c:1646  */
    {fprintf(fout,"Arith%d:\n",level);}
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 191 "compiler_hw3.y" /* yacc.c:1646  */
    { codegen("goto Condition%d\n",level);}
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 212 "compiler_hw3.y" /* yacc.c:1646  */
    {fprintf(fout,"IF_EXIT_%d:\n",level+1); if(level==0){itag+=10;} elif=0;}
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 214 "compiler_hw3.y" /* yacc.c:1646  */
    {fprintf(fout,"IF_EXIT_%d:\n",level+1); if(level==0){itag+=10;} elif=0;}
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 222 "compiler_hw3.y" /* yacc.c:1646  */
    {codegen("ifeq IF_FALSE_%d\n",level+itag+elif); }
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 222 "compiler_hw3.y" /* yacc.c:1646  */
    {codegen("goto IF_EXIT_%d\n",level);  fprintf(fout,"IF_FALSE_%d:\n",level+itag+elif); elif++; }
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 226 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.s_val)=(yyvsp[-2].s_val);
        if(strcmp(type_of((yyvsp[-2].s_val)),(yyvsp[0].s_val))!=0 && strcmp((yyvsp[-2].s_val),"error")!=0){
            HAS_ERROR=true;
            printf("error:%d: invalid operation: ASSIGN (mismatched types %s and %s)\n",yylineno,type_of((yyvsp[-2].s_val)),(yyvsp[0].s_val));       
        }
        printf("ASSIGN\n");
        if(strcmp(type_of((yyvsp[-2].s_val)),"int")==0){
            codegen("istore %d\n",address_of((yyvsp[-2].s_val)));
        }
        else if(strcmp(type_of((yyvsp[-2].s_val)),"float")==0){
            codegen("fstore %d\n",address_of((yyvsp[-2].s_val)));
        }
        else if(strcmp(type_of((yyvsp[-2].s_val)),"bool")==0){
            codegen("istore %d\n",address_of((yyvsp[-2].s_val)));
        }
        else if(strcmp(type_of((yyvsp[-2].s_val)),"string")==0){
            codegen("astore %d\n",address_of((yyvsp[-2].s_val)));
        }
    }
#line 1674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 246 "compiler_hw3.y" /* yacc.c:1646  */
    {
            printf("ADD_ASSIGN\n");
            if(strcmp(type_of((yyvsp[-2].s_val)),"int")==0){
                codegen("iload %d\n",address_of((yyvsp[-2].s_val)));
                codegen("iadd\n");
                codegen("istore %d\n",address_of((yyvsp[-2].s_val)));
            }
            else if(strcmp(type_of((yyvsp[-2].s_val)),"float")==0){
                codegen("fload %d\n",address_of((yyvsp[-2].s_val)));
                codegen("fadd\n");
                codegen("fstore %d\n",address_of((yyvsp[-2].s_val)));
            }


        }
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 261 "compiler_hw3.y" /* yacc.c:1646  */
    {
            printf("SUB_ASSIGN\n");
            if(strcmp(type_of((yyvsp[-2].s_val)),"int")==0){
                codegen("iload %d\n",address_of((yyvsp[-2].s_val)));
                codegen("isub\n");
                codegen("ineg\n");
                codegen("istore %d\n",address_of((yyvsp[-2].s_val)));
            }
            else if(strcmp(type_of((yyvsp[-2].s_val)),"float")==0){
                codegen("fload %d\n",address_of((yyvsp[-2].s_val)));
                codegen("fsub\n");
                codegen("fneg\n");
                codegen("fstore %d\n",address_of((yyvsp[-2].s_val)));
            }
    
        }
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 277 "compiler_hw3.y" /* yacc.c:1646  */
    {
            printf("MUL_ASSIGN\n");
            if(strcmp(type_of((yyvsp[-2].s_val)),"int")==0){
                codegen("iload %d\n",address_of((yyvsp[-2].s_val)));
                codegen("imul\n");
                codegen("istore %d\n",address_of((yyvsp[-2].s_val)));
            }
            else if(strcmp(type_of((yyvsp[-2].s_val)),"float")==0){
                codegen("fload %d\n",address_of((yyvsp[-2].s_val)));
                codegen("fmul\n");
                codegen("fstore %d\n",address_of((yyvsp[-2].s_val)));
            }

        }
#line 1734 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 291 "compiler_hw3.y" /* yacc.c:1646  */
    {
            printf("QUO_ASSIGN\n");
            if(strcmp(type_of((yyvsp[-2].s_val)),"int")==0){
                codegen("istore 84\n");
                codegen("iload %d\n",address_of((yyvsp[-2].s_val)));
                codegen("iload 84\n");
                codegen("idiv\n");
                codegen("istore %d\n",address_of((yyvsp[-2].s_val)));
            }
            else if(strcmp(type_of((yyvsp[-2].s_val)),"float")==0){
                codegen("fstore 84\n");
                codegen("fload %d\n",address_of((yyvsp[-2].s_val)));
                codegen("fload 84\n");
                codegen("fdiv\n");
                codegen("fstore %d\n",address_of((yyvsp[-2].s_val)));
            }

        }
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 309 "compiler_hw3.y" /* yacc.c:1646  */
    {
        
            printf("REM_ASSIGN\n");
            if(strcmp(type_of((yyvsp[-2].s_val)),"int")==0){
                codegen("istore 85\n");
                codegen("iload %d\n",address_of((yyvsp[-2].s_val)));
                codegen("iload 85\n");
                codegen("irem\n");
                codegen("istore %d\n",address_of((yyvsp[-2].s_val)));
                
            }


        }
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 323 "compiler_hw3.y" /* yacc.c:1646  */
    {
            printf("ASSIGN\n");

            if(strcmp(eletype_of((yyvsp[-5].s_val)),"int")==0){
                codegen("istore 82\n"); 
                codegen("istore 83\n");   
                codegen("aload %d\n",address_of((yyvsp[-5].s_val)));
                codegen("iload 83\n");  
                codegen("iload 82\n");  
                codegen("iastore\n");
            }
            else if(strcmp(eletype_of((yyvsp[-5].s_val)),"float")==0){
                codegen("fstore 82\n"); 
                codegen("istore 83\n");   
                codegen("aload %d\n",address_of((yyvsp[-5].s_val)));
                codegen("iload 83\n");  
                codegen("fload 82\n");  
                codegen("fastore\n");
            }
            
            
        }
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 345 "compiler_hw3.y" /* yacc.c:1646  */
    {printf("ADD_ASSIGN\n");}
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 346 "compiler_hw3.y" /* yacc.c:1646  */
    {printf("MUL_ASSIGN\n");}
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 347 "compiler_hw3.y" /* yacc.c:1646  */
    {printf("SUB_ASSIGN\n");}
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 348 "compiler_hw3.y" /* yacc.c:1646  */
    {printf("QUO_ASSIGN\n");}
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 349 "compiler_hw3.y" /* yacc.c:1646  */
    {printf("REM_ASSIGN\n");}
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 350 "compiler_hw3.y" /* yacc.c:1646  */
    {   
        HAS_ERROR=true;
        printf("error:%d: cannot assign to %s\n",yylineno,(yyvsp[-2].s_val));
        printf("ASSIGN\n");
        }
#line 1843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 355 "compiler_hw3.y" /* yacc.c:1646  */
    {HAS_ERROR=true;printf("error:%d: cannot assign to %s\n",yylineno,(yyvsp[-2].s_val)); printf("ADD_ASSIGN\n");}
#line 1849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 356 "compiler_hw3.y" /* yacc.c:1646  */
    {HAS_ERROR=true; printf("error:%d: cannot assign to %s\n",yylineno,(yyvsp[-2].s_val)); printf("SUB_ASSIGN\n");}
#line 1855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 357 "compiler_hw3.y" /* yacc.c:1646  */
    {HAS_ERROR=true;printf("error:%d: cannot assign to %s\n",yylineno,(yyvsp[-2].s_val)); printf("MUL_ASSIGN\n");}
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 358 "compiler_hw3.y" /* yacc.c:1646  */
    {HAS_ERROR=true;printf("error:%d: cannot assign to %s\n",yylineno,(yyvsp[-2].s_val)); printf("QUO_ASSIGN\n");}
#line 1867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 359 "compiler_hw3.y" /* yacc.c:1646  */
    {HAS_ERROR=true;printf("error:%d: cannot assign to %s\n",yylineno,(yyvsp[-2].s_val)); printf("REM_ASSIGN\n");}
#line 1873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 360 "compiler_hw3.y" /* yacc.c:1646  */
    {HAS_ERROR=true;printf("error:%d: cannot assign to %s\n",yylineno,(yyvsp[-5].s_val)); printf("ASSIGN\n");}
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 361 "compiler_hw3.y" /* yacc.c:1646  */
    {HAS_ERROR=true;printf("error:%d: cannot assign to %s\n",yylineno,(yyvsp[-5].s_val)); printf("ADD_ASSIGN\n");}
#line 1885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 362 "compiler_hw3.y" /* yacc.c:1646  */
    {HAS_ERROR=true;printf("error:%d: cannot assign to %s\n",yylineno,(yyvsp[-5].s_val)); printf("MUL_ASSIGN\n");}
#line 1891 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 363 "compiler_hw3.y" /* yacc.c:1646  */
    {HAS_ERROR=true;printf("error:%d: cannot assign to %s\n",yylineno,(yyvsp[-5].s_val)); printf("SUB_ASSIGN\n");}
#line 1897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 364 "compiler_hw3.y" /* yacc.c:1646  */
    {HAS_ERROR=true;printf("error:%d: cannot assign to %s\n",yylineno,(yyvsp[-5].s_val)); printf("QUO_ASSIGN\n");}
#line 1903 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 365 "compiler_hw3.y" /* yacc.c:1646  */
    {HAS_ERROR=true;printf("error:%d: cannot assign to %s\n",yylineno,(yyvsp[-5].s_val)); printf("REM_ASSIGN\n");}
#line 1909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 370 "compiler_hw3.y" /* yacc.c:1646  */
    { fprintf(fout,"While_begin_%d :\n",level+ltag);}
#line 1915 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 370 "compiler_hw3.y" /* yacc.c:1646  */
    {codegen("ifeq While_exit_%d\n",level+ltag);}
#line 1921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 370 "compiler_hw3.y" /* yacc.c:1646  */
    {
            codegen("goto While_begin_%d\n",level+ltag);
            fprintf(fout,"While_exit_%d:\n",level+ltag);
            if(level==0){
                ltag+=10;
            }
            
    }
#line 1934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 380 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if(strcmp((yyvsp[0].s_val),"bool")!=0){
            HAS_ERROR=true;
            printf("error:%d: non-bool (type %s) used as for condition\n",yylineno+1,(yyvsp[0].s_val));
        }
    }
#line 1945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 388 "compiler_hw3.y" /* yacc.c:1646  */
    {create_symbol();}
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 392 "compiler_hw3.y" /* yacc.c:1646  */
    {
    dump_symbol();
    }
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 398 "compiler_hw3.y" /* yacc.c:1646  */
    { 
          printf("PRINT %s\n",(yyvsp[-2].s_val));
          if(strcmp((yyvsp[-2].s_val),"int")==0){
                codegen("getstatic java/lang/System/out Ljava/io/PrintStream;\n");
                codegen("swap\n");
                codegen("invokevirtual java/io/PrintStream/print(I)V\n");
          }
          else  if(strcmp((yyvsp[-2].s_val),"float")==0){
                codegen("getstatic java/lang/System/out Ljava/io/PrintStream;\n");
                codegen("swap\n");
                codegen("invokevirtual java/io/PrintStream/print(F)V\n");
          }
          else  if(strcmp((yyvsp[-2].s_val),"bool")==0){
                codegen("ifne BOOL_%d\n",tag);
                tag++;
                codegen("ldc \"false\"\n");
                codegen("goto BOOL_%d\n",tag);
                fprintf(fout,"BOOL_%d:\n",tag-1);
                codegen("ldc \"true\"\n");
                fprintf(fout,"BOOL_%d:\n",tag);
                codegen("getstatic java/lang/System/out Ljava/io/PrintStream;\n");
                codegen("swap\n");
                codegen("invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
                tag++;

          }
          else  if(strcmp((yyvsp[-2].s_val),"string")==0){
                codegen("getstatic java/lang/System/out Ljava/io/PrintStream;\n");
                codegen("swap\n");
                codegen("invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
          }
                              
    }
#line 1997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 436 "compiler_hw3.y" /* yacc.c:1646  */
    { 
          (yyval.s_val)=(yyvsp[-1].s_val);
            if(strcmp(type_of((yyvsp[-1].s_val)),"int")==0){
                    codegen("iload %d\n",address_of((yyvsp[-1].s_val)));
                    codegen("ldc 1\n");
                    codegen("iadd\n");
                    codegen("istore %d\n",address_of((yyvsp[-1].s_val)));
            }
             else if(strcmp(type_of((yyvsp[-1].s_val)),"float")==0){
                    codegen("fload %d\n",address_of((yyvsp[-1].s_val)));
                    codegen("ldc 1.0\n");
                    codegen("fadd\n");
                    codegen("fstore %d\n",address_of((yyvsp[-1].s_val)));
            }
          printf("INC\n");
          }
#line 2018 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 452 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        (yyval.s_val)=(yyvsp[-1].s_val);
        if(strcmp(type_of((yyvsp[-1].s_val)),"int")==0){
                    codegen("iload %d\n",address_of((yyvsp[-1].s_val)));
                    codegen("ldc 1\n");
                    codegen("isub\n");
                    codegen("istore %d\n",address_of((yyvsp[-1].s_val)));
        }
        else if(strcmp(type_of((yyvsp[-1].s_val)),"float")==0){
                    codegen("fload %d\n",address_of((yyvsp[-1].s_val)));
                    codegen("ldc 1.0\n");
                    codegen("fsub\n");
                    codegen("fstore %d\n",address_of((yyvsp[-1].s_val)));
            }
        printf("DEC\n");
        }
#line 2039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 470 "compiler_hw3.y" /* yacc.c:1646  */
    {
        codegen("ior\n");
        if(strcmp((yyvsp[-2].s_val),"bool")!=0){
            HAS_ERROR=true;
            printf("error:%d: invalid operation: (operator OR not defined on %s)\n",yylineno,(yyvsp[-2].s_val));
        }
        if(strcmp((yyvsp[0].s_val),"bool")!=0){
            HAS_ERROR=true;
            printf("error:%d: invalid operation: (operator OR not defined on %s)\n",yylineno,(yyvsp[0].s_val));
        }
            printf("OR\n"); (yyval.s_val)="bool";
        }
#line 2056 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 486 "compiler_hw3.y" /* yacc.c:1646  */
    {
        codegen("iand\n");
        if(strcmp((yyvsp[-2].s_val),"bool")!=0){
            HAS_ERROR=true;
            printf("error:%d: invalid operation: (operator AND not defined on %s)\n",yylineno,(yyvsp[-2].s_val));
        }
        if(strcmp((yyvsp[0].s_val),"bool")!=0){
            HAS_ERROR=true;
            printf("error:%d: invalid operation: (operator AND not defined on %s)\n",yylineno,(yyvsp[0].s_val));
        }
        printf("AND\n"); (yyval.s_val)="bool";
        }
#line 2073 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 501 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("GTR\n"); (yyval.s_val)="bool";
        if(strcmp((yyvsp[-2].s_val),(yyvsp[0].s_val))==0){
            if(strcmp((yyvsp[-2].s_val),"int")==0){
                codegen("isub\n");
                codegen("ifgt GTR_%d\n",tag);
                tag++;
                codegen("iconst_0\n");
                codegen("goto GTR_%d\n",tag);
                fprintf(fout,"GTR_%d:\n",tag-1);
                codegen("iconst_1\n");
                fprintf(fout,"GTR_%d:\n",tag);
                tag++;
            }
            else if(strcmp((yyvsp[-2].s_val),"float")==0){
                codegen("fcmpl\n");
                codegen("ifgt GTR_%d\n",tag);
                tag++;
                codegen("iconst_0\n");
                codegen("goto GTR_%d\n",tag);
                fprintf(fout,"GTR_%d:\n",tag-1);
                codegen("iconst_1\n");
                fprintf(fout,"GTR_%d:\n",tag);
                tag++;
            }
        }

        }
#line 2106 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 529 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("LSS\n"); (yyval.s_val)="bool";
         if(strcmp((yyvsp[-2].s_val),(yyvsp[0].s_val))==0){
                if(strcmp((yyvsp[-2].s_val),"int")==0){
                    codegen("isub\n");
                    codegen("iflt LSS_%d\n",tag);
                    tag++;
                    codegen("iconst_0\n");
                    codegen("goto LSS_%d\n",tag);
                    fprintf(fout,"LSS_%d:\n",tag-1);
                    codegen("iconst_1\n");
                    fprintf(fout,"LSS_%d:\n",tag);
                    tag++;
                }
            }
        }
#line 2127 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 545 "compiler_hw3.y" /* yacc.c:1646  */
    {
            printf("LEQ\n"); (yyval.s_val)="bool";
            if(strcmp((yyvsp[-2].s_val),(yyvsp[0].s_val))==0){
                if(strcmp((yyvsp[-2].s_val),"int")==0){
                    codegen("isub\n");
                    codegen("ifle LEQ_%d\n",tag);
                    tag++;
                    codegen("iconst_0\n");
                    codegen("goto LEQ_%d\n",tag);
                    fprintf(fout,"LEQ_%d:\n",tag-1);
                    codegen("iconst_1\n");
                    fprintf(fout,"LEQ_%d:\n",tag);
                    tag++;
                }
            }
        }
#line 2148 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 561 "compiler_hw3.y" /* yacc.c:1646  */
    {printf("GEQ\n"); (yyval.s_val)="bool";}
#line 2154 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 562 "compiler_hw3.y" /* yacc.c:1646  */
    {

            printf("EQL\n"); (yyval.s_val)="bool";
            if(strcmp((yyvsp[-2].s_val),(yyvsp[0].s_val))==0){
                if(strcmp((yyvsp[-2].s_val),"int")==0){
                    codegen("isub\n");
                    codegen("ifeq EQL_%d\n",tag);
                    tag++;
                    codegen("iconst_0\n");
                    codegen("goto EQL_%d\n",tag);
                    fprintf(fout,"EQL_%d:\n",tag-1);
                    codegen("iconst_1\n");
                    fprintf(fout,"EQL_%d:\n",tag);
                    tag++;
                }
            }
        }
#line 2176 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 579 "compiler_hw3.y" /* yacc.c:1646  */
    {
        printf("NEQ\n"); (yyval.s_val)="bool";
            if(strcmp((yyvsp[-2].s_val),(yyvsp[0].s_val))==0){
                if(strcmp((yyvsp[-2].s_val),"int")==0){
                    codegen("isub\n");
                    codegen("ifne NEQ_%d\n",tag);
                    tag++;
                    codegen("iconst_0\n");
                    codegen("goto NEQ_%d\n",tag);
                    fprintf(fout,"NEQ_%d:\n",tag-1);
                    codegen("iconst_1\n");
                    fprintf(fout,"NEQ_%d:\n",tag);
                    tag++;
                }
            }
        }
#line 2197 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 598 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if(strcmp((yyvsp[-2].s_val),(yyvsp[0].s_val))==0){
            if(strcmp((yyvsp[-2].s_val),"int")==0){
                codegen("iadd\n");   
            }
            else if(strcmp((yyvsp[-2].s_val),"float")==0){
                codegen("fadd\n");   
            }
        }
        if(strcmp((yyvsp[-2].s_val),(yyvsp[0].s_val))!=0){
            HAS_ERROR=true;
            printf("error:%d: invalid operation: ADD (mismatched types %s and %s)\n",yylineno,(yyvsp[-2].s_val),(yyvsp[0].s_val));      
             
        }
         printf("ADD\n"); (yyval.s_val)=(yyvsp[0].s_val);
         }
#line 2218 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 614 "compiler_hw3.y" /* yacc.c:1646  */
    { 
        if(strcmp((yyvsp[-2].s_val),(yyvsp[0].s_val))==0){
            if(strcmp((yyvsp[-2].s_val),"int")==0){
                codegen("isub\n");   
            }
            else if(strcmp((yyvsp[-2].s_val),"float")==0){
                codegen("fsub\n");   
            }
        }
        if(strcmp((yyvsp[-2].s_val),(yyvsp[0].s_val))!=0){
            HAS_ERROR=true;
            printf("error:%d: invalid operation: SUB (mismatched types %s and %s)\n",yylineno,(yyvsp[-2].s_val),(yyvsp[0].s_val));       
        }
        printf("SUB\n"); (yyval.s_val)=(yyvsp[0].s_val);
        }
#line 2238 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 629 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val)=(yyvsp[0].s_val);}
#line 2244 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 632 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if(strcmp((yyvsp[-2].s_val),(yyvsp[0].s_val))==0){
            if(strcmp((yyvsp[-2].s_val),"int")==0){
                codegen("imul\n");   
            }
            else if(strcmp((yyvsp[-2].s_val),"float")==0){
                codegen("fmul\n");   
            }
        }
         printf("MUL\n"); (yyval.s_val)=(yyvsp[0].s_val);
         }
#line 2260 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 643 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if(strcmp((yyvsp[-2].s_val),(yyvsp[0].s_val))==0){
            if(strcmp((yyvsp[-2].s_val),"int")==0){
                codegen("idiv\n");   
            }
            else if(strcmp((yyvsp[-2].s_val),"float")==0){
                codegen("fdiv\n");   
            }
        }   
        printf("QUO\n"); (yyval.s_val)=(yyvsp[0].s_val);
        }
#line 2276 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 654 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if(strcmp((yyvsp[-2].s_val),(yyvsp[0].s_val))==0){
            if(strcmp((yyvsp[-2].s_val),"int")==0){
                codegen("irem\n");   
            }
            else if(strcmp((yyvsp[-2].s_val),"float")==0){
                codegen("frem\n");   
            }
        }
        if(strcmp((yyvsp[-2].s_val),"int")!=0){
            HAS_ERROR=true;
            printf("error:%d: invalid operation: (operator REM not defined on %s)\n",yylineno,(yyvsp[-2].s_val));
        }
        if(strcmp((yyvsp[0].s_val),"int")!=0){
            HAS_ERROR=true;
            printf("error:%d: invalid operation: (operator REM not defined on %s)\n",yylineno,(yyvsp[0].s_val));
        }
         printf("REM\n"); (yyval.s_val)=(yyvsp[0].s_val);
         }
#line 2300 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 673 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val)=(yyvsp[0].s_val);}
#line 2306 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 676 "compiler_hw3.y" /* yacc.c:1646  */
    {(yyval.s_val)=(yyvsp[-1].s_val);}
#line 2312 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 677 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if(strcmp((yyvsp[0].s_val),"int")==0){
             codegen("ineg\n");
        }
        else if(strcmp((yyvsp[0].s_val),"float")==0){
             codegen("fneg\n");
        }       
        printf("NEG\n"); (yyval.s_val)=(yyvsp[0].s_val)
        ;}
#line 2326 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 686 "compiler_hw3.y" /* yacc.c:1646  */
    {printf("POS\n"); (yyval.s_val)=(yyvsp[0].s_val);}
#line 2332 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 687 "compiler_hw3.y" /* yacc.c:1646  */
    {
        codegen("ldc 1\n");
        codegen("ixor\n");
        printf("NOT\n");   (yyval.s_val)="bool";
        }
#line 2342 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 692 "compiler_hw3.y" /* yacc.c:1646  */
    {
            (yyval.s_val)= eletype_of((yyvsp[-1].s_val)); 
           
            codegen("aload %d\n",address_of((yyvsp[-1].s_val)));
            codegen("iload 86\n");    
             if(strcmp(eletype_of((yyvsp[-1].s_val)),"int")==0){
                codegen("iaload\n");
            }
            else if(strcmp(eletype_of((yyvsp[-1].s_val)),"float")==0){
                codegen("faload\n");
            }
        }
#line 2359 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 704 "compiler_hw3.y" /* yacc.c:1646  */
    {
        (yyval.s_val)=(yyvsp[0].s_val);

        }
#line 2368 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 708 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if(strcmp(type_of((yyvsp[0].s_val)),"int")==0 ){
            codegen("iload %d\n", address_of((yyvsp[0].s_val)));
        }
        else if(strcmp(type_of((yyvsp[0].s_val)),"float")==0){
            codegen("fload %d\n", address_of((yyvsp[0].s_val)));
        }
        else if(strcmp(type_of((yyvsp[0].s_val)),"bool")==0){
            codegen("iload %d\n", address_of((yyvsp[0].s_val)));
        }
        else if(strcmp(type_of((yyvsp[0].s_val)),"string")==0){
            codegen("aload %d\n", address_of((yyvsp[0].s_val)));
        }

        (yyval.s_val)=type_of((yyvsp[0].s_val));
        }
#line 2389 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 724 "compiler_hw3.y" /* yacc.c:1646  */
    {
        // if(strcmp($2,"int")==0 && strcmp(eletype_of($4),"float")==0){
            
        //     printf("F to I\n");
        //     $$="int";
        // }
        // else  if(strcmp(eletype_of($4),"int")==0 && strcmp($2,"float")==0){
        //     printf("I to F\n");
        //     $$="float";
        // }
        if(strcmp((yyvsp[-3].s_val),"int")==0 && strcmp(eletype_of((yyvsp[-1].s_val)),"float")==0){
            codegen("aload %d\n",address_of((yyvsp[-1].s_val)));
            codegen("iload 86\n");    
             if(strcmp(eletype_of((yyvsp[-1].s_val)),"int")==0){
                codegen("iaload\n");
            }
            else if(strcmp(eletype_of((yyvsp[-1].s_val)),"float")==0){
                codegen("faload\n");
            }
            codegen("f2i\n");
            (yyval.s_val)="int";

        }
        else  if(strcmp(eletype_of((yyvsp[-1].s_val)),"int")==0 && strcmp((yyvsp[-3].s_val),"float")==0){
            codegen("aload %d\n",address_of((yyvsp[-1].s_val)));
            codegen("iload 86\n");    
             if(strcmp(eletype_of((yyvsp[-1].s_val)),"int")==0){
                codegen("iaload\n");
            }
            else if(strcmp(eletype_of((yyvsp[-1].s_val)),"float")==0){
                codegen("faload\n");
            }
            codegen("i2f\n");
            (yyval.s_val)="float";
        }
    
    }
#line 2431 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 761 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if(strcmp((yyvsp[-2].s_val),"int")==0 && strcmp(type_of((yyvsp[0].s_val)),"float")==0){
            
            printf("F to I\n");
            (yyval.s_val)="int";
        }
        else  if(strcmp(type_of((yyvsp[0].s_val)),"int")==0 && strcmp((yyvsp[-2].s_val),"float")==0){
            printf("I to F\n");
            (yyval.s_val)="float";
        }
        if(strcmp((yyvsp[-2].s_val),"int")==0 && strcmp(type_of((yyvsp[0].s_val)),"float")==0){
            codegen("fload %d\n", address_of((yyvsp[0].s_val)));
            codegen("f2i\n");

        }
        else  if(strcmp(type_of((yyvsp[0].s_val)),"int")==0 && strcmp((yyvsp[-2].s_val),"float")==0){
            codegen("iload %d\n", address_of((yyvsp[0].s_val)));
            codegen("i2f\n");

        }
    
    }
#line 2458 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 783 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if(strcmp((yyvsp[-2].s_val),"int")==0 && strcmp((yyvsp[0].s_val),"float")==0){
            printf("F to I\n");
            (yyval.s_val)="int";
        }
        else  if(strcmp((yyvsp[0].s_val),"int")==0 && strcmp((yyvsp[-2].s_val),"float")==0){
            printf("I to F\n");
            (yyval.s_val)="float";
        }
        if(strcmp((yyvsp[-2].s_val),"int")==0 && strcmp((yyvsp[0].s_val),"float")==0){

            codegen("f2i\n");

        }
        else  if(strcmp((yyvsp[0].s_val),"int")==0 && strcmp((yyvsp[-2].s_val),"float")==0){
            codegen("i2f\n");
        }
    
    }
#line 2482 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 805 "compiler_hw3.y" /* yacc.c:1646  */
    { codegen("istore 86\n");  (yyval.s_val)="array";}
#line 2488 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 811 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if(!check_entry((yyvsp[0].s_val))){
            insert_variable((yyvsp[0].s_val),(yyvsp[-1].s_val),yylineno,"-");
            printf("> Insert {%s} into symbol table (scope level: %d)\n",(yyvsp[0].s_val),level);
        }
        else{
            HAS_ERROR=true;
            printf("error:%d: %s redeclared in this block. previous declaration at line %d\n",yylineno,(yyvsp[0].s_val),line_of((yyvsp[0].s_val)));
        }
         if(strcmp(type_of((yyvsp[0].s_val)),"int")==0){
             codegen("ldc 0\n");
            codegen("istore %d\n",address_of((yyvsp[0].s_val)));
        }
        else if(strcmp(type_of((yyvsp[0].s_val)),"float")==0){
           codegen("ldc 0.0\n");
            codegen("fstore %d\n",address_of((yyvsp[0].s_val)));
        }
         else if(strcmp(type_of((yyvsp[0].s_val)),"string")==0){
            codegen("ldc \"\"\n");
            codegen("astore %d\n",address_of((yyvsp[0].s_val)));
        }
         else if(strcmp(type_of((yyvsp[0].s_val)),"bool")==0){
            codegen("ldc 0\n");
            codegen("istore %d\n",address_of((yyvsp[0].s_val)));
        }
      
    }
#line 2520 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 838 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if(!check_entry((yyvsp[-2].s_val))){
            insert_variable((yyvsp[-2].s_val),(yyvsp[-3].s_val),yylineno,"-");
            printf("> Insert {%s} into symbol table (scope level: %d)\n",(yyvsp[-2].s_val),level);
        }
        else{
            HAS_ERROR=true;
            printf("error:%d: %s redeclared in this block. previous declaration at line %d\n",yylineno,(yyvsp[-2].s_val),line_of((yyvsp[-2].s_val)));
        }
         if(strcmp(type_of((yyvsp[-2].s_val)),"int")==0){
            codegen("istore %d\n",address_of((yyvsp[-2].s_val)));
        }
        else if(strcmp(type_of((yyvsp[-2].s_val)),"float")==0){
            codegen("fstore %d\n",address_of((yyvsp[-2].s_val)));
        }
         else if(strcmp(type_of((yyvsp[-2].s_val)),"string")==0){
            codegen("astore %d\n",address_of((yyvsp[-2].s_val)));
        }
         else if(strcmp(type_of((yyvsp[-2].s_val)),"bool")==0){
            codegen("istore %d\n",address_of((yyvsp[-2].s_val)));
        }

    }
#line 2548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 861 "compiler_hw3.y" /* yacc.c:1646  */
    {


        if(!check_entry((yyvsp[-3].s_val))){
            insert_variable((yyvsp[-3].s_val),"array",yylineno,(yyvsp[-4].s_val));
            printf("> Insert {%s} into symbol table (scope level: %d)\n",(yyvsp[-3].s_val),level);
        }
        else{
            HAS_ERROR=true;
            printf("error:%d: %s redeclared in this block. previous declaration at line %d\n",yylineno,(yyvsp[-3].s_val),line_of((yyvsp[-3].s_val)));
        }
        if( strcmp((yyvsp[-4].s_val),"int")==0){
            codegen("newarray int\n");
            codegen("astore %d\n",address_of((yyvsp[-3].s_val)));
        }
        else if(strcmp((yyvsp[-4].s_val),"float")==0){
            codegen("newarray float\n");
            codegen("astore %d\n",address_of((yyvsp[-3].s_val)));
        }

    }
#line 2574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 882 "compiler_hw3.y" /* yacc.c:1646  */
    {
        if(!check_entry((yyvsp[-5].s_val))){
            insert_variable((yyvsp[-5].s_val),"array",yylineno,(yyvsp[-6].s_val));
            printf("> Insert {%s} into symbol table (scope level: %d)\n",(yyvsp[-5].s_val),level);
        }
        else{
            HAS_ERROR=true;
            printf("error:%d: %s redeclared in this block. previous declaration at line %d\n",yylineno,(yyvsp[-5].s_val),line_of((yyvsp[-5].s_val)));
        }

    }
#line 2590 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2594 "y.tab.c" /* yacc.c:1646  */
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
#line 895 "compiler_hw3.y" /* yacc.c:1906  */


/* C code section */
int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }

    /* Codegen output init */
    char *bytecode_filename = "hw3.j";
    fout = fopen(bytecode_filename, "w");
    codegen(".source hw3.j\n");
    codegen(".class public Main\n");
    codegen(".super java/lang/Object\n");
    codegen(".method public static main([Ljava/lang/String;)V\n");
    codegen(".limit stack 100\n");
    codegen(".limit locals 100\n");
    INDENT++;

    yyparse();

	printf("Total lines: %d\n", yylineno);

    /* Codegen end */
    codegen("return\n");
    INDENT--;
    codegen(".end method\n");
    fclose(fout);
    fclose(yyin);

    if (HAS_ERROR) {
        remove(bytecode_filename);
    }
    return 0;
}


    int address_of(char* name){
        if(sym_tb==NULL){
            return -1;
        }
        for(int i=level ; i>=0;i--){
            variable *trasverse=&sym_tb[i];
            while(1){
                if (trasverse->next == NULL)
                {
                    break;
                }
                else{
                    if(!strcmp(trasverse->next->name,name)){
                            return trasverse->next->address;
                        }
                    trasverse=trasverse->next;
                }

            }
        }
        

        return -1;

}
bool check_entry(char* name){
        if(sym_tb==NULL){
            return 0;
        }

        variable *trasverse=&sym_tb[level];
        while(1){
            if (trasverse->next == NULL)
            {
                break;
            }
            else{
                if(!strcmp(trasverse->next->name,name)){
                        return 1;
                    }
                trasverse=trasverse->next;
            }
        }            
         

        return 0;
}

bool check_whole(char* name){
        if(sym_tb==NULL){
            return 0;
        }
         for(int i=level ; i>=0;i--){
             variable *trasverse=&sym_tb[i];
            while(1){
                if (trasverse->next == NULL)
                {
                    break;
                }
                else{
                    if(!strcmp(trasverse->next->name,name)){
                            return 1;
                        }
                    trasverse=trasverse->next;
                }
            }            
         }

        return 0;
}
    int  line_of(char* name){
        
        if(sym_tb==NULL){
            return -1;
        }
         for(int i=level ; i>=0;i--){
             variable *trasverse=&sym_tb[i];
            while(1){
                if (trasverse->next == NULL)
                {
                    break;
                }
                else{
                    if(!strcmp(trasverse->next->name,name)){
                            return trasverse->next->lineno;
                        }
                    trasverse=trasverse->next;
                }
            }            
         }

        return -1;

}
    char* type_of(char* name){
        
        if(sym_tb==NULL){
            return "sym_tb null";
        }
         for(int i=level ; i>=0;i--){
             variable *trasverse=&sym_tb[i];
            while(1){
                if (trasverse->next == NULL)
                {
                    break;
                }
                else{
                    if(!strcmp(trasverse->next->name,name)){
                            return trasverse->next->type;
                        }
                    trasverse=trasverse->next;
                }
            }            
         }

        return "error";

}
    char* eletype_of(char* name){

        if(sym_tb==NULL){
            return "sym_tb null";
        }
         for(int i=level ; i>=0;i--){
            variable *trasverse=&sym_tb[i];
            while(1){
                if (trasverse->next == NULL)
                {
                    break;
                }
                else{
                    if(!strcmp(trasverse->next->name,name)){
                            return trasverse->next->element_type;
                        }
                    trasverse=trasverse->next;
                }

            }
         }

        return "error";

}
     void create_symbol(){
        myIndex=0;
        if(sym_tb!=NULL){
            level++;
            sym_tb = (variable*)realloc(sym_tb,(level+1)*sizeof(variable));
            sym_tb[level].next=NULL;
        }
        else{
            level=0;
            sym_tb= (variable*)malloc((level+1)*sizeof(variable));
            sym_tb[level].next=NULL;
        }

        // if(level==0){
        //     level++;
        // }
    }

    void insert_variable( char* name , char*type,int lineno,char* element_type ){
        // printf("fuck you");
        if(sym_tb==NULL){
            // printf("fuck you");
            level=0;
            sym_tb= (variable*)malloc((level+1)*sizeof(variable));
            sym_tb[level].next=NULL;
        }
        variable *trasverse=&sym_tb[level];
        while(1){
            if (trasverse->next == NULL)
            {
                break;
            }
            else{
                trasverse=trasverse->next;
            }
        }
        trasverse->next=(variable*)malloc(sizeof(variable));
        variable*tmp=trasverse->next;
        tmp->next=NULL;
        tmp->index=myIndex;
        tmp->name=name;
        tmp->type=type;
        tmp->address=address;
        tmp->lineno=lineno;
        tmp->element_type=element_type;



        myIndex++;
        

        address++;
        

        // printf("> Insert {%s} into symbol table (scope level: %d)\n", name,level);
    }

    void dump_symbol(){
        printf("> Dump symbol table (scope level: %d)\n", level);
        printf("%-10s%-10s%-10s%-10s%-10s%s\n", "Index", "Name", "Type", "Address", "Lineno","Element type");
        variable *trasverse=&sym_tb[level];
        if(sym_tb==NULL){
            return;
        }
        while(1){
            if(trasverse->next==NULL){
                break;
            }
            printf("%-10d%-10s%-10s%-10d%-10d%s"
            ,trasverse->next->index
            ,trasverse->next->name
            ,trasverse->next->type
            ,trasverse->next->address
            ,trasverse->next->lineno,
            trasverse->next->element_type);

            variable *tmp=trasverse;
            trasverse=trasverse->next;
            if(tmp!=&sym_tb[level]){
                free(tmp);
            }
    
            if(trasverse==NULL){
                break;
            }
            else{
                printf("\n");
            }
        }
        
        level--;
        variable* stmp= realloc(sym_tb,(level+1)*sizeof(variable));
        if(stmp!=NULL){
            sym_tb=stmp;
        }
        if(level<0){
            sym_tb=NULL;
            level=0;
            return;
        }
        trasverse=&sym_tb[level];
        while(1){
            
            if(trasverse->next==NULL){
                if(trasverse!=&sym_tb[level]){
                    myIndex=trasverse->index+1;
                }
                else{
                    myIndex=0;
                }
                break;
            }
            else{
                trasverse=trasverse->next;
            }
        }

        
    }
