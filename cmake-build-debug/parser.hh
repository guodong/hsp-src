/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
     TIDENTIFIER = 258,
     TINTEGER = 259,
     TIP = 260,
     TMAC = 261,
     TLPAREN = 262,
     TRPAREN = 263,
     TLBRACE = 264,
     TRBRACE = 265,
     TCOMMA = 266,
     TEQUAL = 267,
     TIF = 268,
     TELSE = 269,
     TDOT = 270,
     TRETURN = 271,
     TINT = 272,
     TCEQ = 273,
     TCLT = 274,
     TCLE = 275,
     TCGT = 276,
     TCGE = 277
   };
#endif
/* Tokens.  */
#define TIDENTIFIER 258
#define TINTEGER 259
#define TIP 260
#define TMAC 261
#define TLPAREN 262
#define TRPAREN 263
#define TLBRACE 264
#define TRBRACE 265
#define TCOMMA 266
#define TEQUAL 267
#define TIF 268
#define TELSE 269
#define TDOT 270
#define TRETURN 271
#define TINT 272
#define TCEQ 273
#define TCLT 274
#define TCLE 275
#define TCGT 276
#define TCGE 277




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 16 "parser.yy"
{
  NBlock* block;
  NStatement* stmt;
  NExpression* expr;
  NIdentifier* ident;
  NVariableDeclaration* var_decl;
  std::vector<NVariableDeclaration*>* varvec;
  std::vector<NExpression*>* exprvec;
  std::string* string;
  int token;
  int binary_token;
  int primary_type;
}
/* Line 1529 of yacc.c.  */
#line 107 "/Users/gd/projects/hsp-src/cmake-build-debug/parser.hh"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

