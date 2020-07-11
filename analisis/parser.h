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

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
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
    rMkdisk = 258,
    rSize = 259,
    rFit = 260,
    rUnit = 261,
    rPath = 262,
    rRmdisk = 263,
    rFdisck = 264,
    rType = 265,
    rDelete = 266,
    rName = 267,
    rAdd = 268,
    rMount = 269,
    rRep = 270,
    rId = 271,
    rUnmount = 272,
    rExec = 273,
    punto = 274,
    er_number = 275,
    er_id = 276,
    er_cadena = 277,
    er_path = 278,
    guion = 279,
    igual = 280,
    rMkfs = 281,
    rFs = 282,
    rLogin = 283,
    rUsr = 284,
    rPwd = 285,
    rLogout = 286,
    rMkgrp = 287,
    rRmgrp = 288,
    rMkusr = 289,
    rGrp = 290,
    rRmusr = 291,
    rChmod = 292,
    rUgo = 293,
    rMkfile = 294,
    r2fs = 295,
    r3fs = 296,
    rCont = 297,
    rCat = 298,
    rFile = 299,
    rRem = 300,
    rEdit = 301,
    rPause = 302,
    rRen = 303,
    rMkdir = 304,
    rCp = 305,
    rDest = 306,
    rMv = 307,
    rRuta = 308,
    rFind = 309,
    rChown = 310,
    rChgrp = 311
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 41 "sintactico.yy" /* yacc.c:1909  */

  char TEXT [256]="";
  class instruccion * Instruccion;
  class lista_comandos *Lista_comandos;
  class lista_parametros * Lista_parametros;
  class parametro *Parametro;
//   class exec *Exec;
//   class fdisk *Fdisk;
//   class mkdisk *Mkdisk;
//   class mount *Mount;
//   class repdisk *Repdisk;
//   class repmbr *Repmbr;
//   class rmdisk *Rmdisk;
//   class unmount *Unmount;

#line 127 "parser.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */
