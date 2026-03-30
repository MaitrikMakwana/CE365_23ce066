
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     FOR = 258,
     DATATYPE = 259,
     ID = 260,
     NUM = 261,
     INC = 262,
     DEC = 263,
     ADD_ASSIGN = 264,
     SUB_ASSIGN = 265,
     MUL_ASSIGN = 266,
     DIV_ASSIGN = 267,
     EQ = 268,
     NEQ = 269,
     LE = 270,
     GE = 271,
     LT = 272,
     GT = 273,
     LPAREN = 274,
     RPAREN = 275,
     LBRACE = 276,
     RBRACE = 277,
     SEMICOLON = 278,
     ASSIGN = 279,
     COMMA = 280,
     OR = 281,
     AND = 282
   };
#endif
/* Tokens.  */
#define FOR 258
#define DATATYPE 259
#define ID 260
#define NUM 261
#define INC 262
#define DEC 263
#define ADD_ASSIGN 264
#define SUB_ASSIGN 265
#define MUL_ASSIGN 266
#define DIV_ASSIGN 267
#define EQ 268
#define NEQ 269
#define LE 270
#define GE 271
#define LT 272
#define GT 273
#define LPAREN 274
#define RPAREN 275
#define LBRACE 276
#define RBRACE 277
#define SEMICOLON 278
#define ASSIGN 279
#define COMMA 280
#define OR 281
#define AND 282




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


