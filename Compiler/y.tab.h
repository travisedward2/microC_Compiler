/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 66 "compiler_hw3.y" /* yacc.c:1909  */

    int i_val;
    float f_val;
    char *s_val;
    /* ... */

#line 125 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
