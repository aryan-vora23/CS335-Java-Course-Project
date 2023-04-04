/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_LALR1_TAB_H_INCLUDED
# define YY_YY_LALR1_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 76 "lalr1.y"

	#include "ast.h"

#line 53 "lalr1.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    OPERATOR = 258,                /* OPERATOR  */
    OPEN_SQ = 259,                 /* OPEN_SQ  */
    CLOSE_SQ = 260,                /* CLOSE_SQ  */
    OPEN_BR = 261,                 /* OPEN_BR  */
    CLOSE_BR = 262,                /* CLOSE_BR  */
    OPEN_CR = 263,                 /* OPEN_CR  */
    CLOSE_CR = 264,                /* CLOSE_CR  */
    SEPERATOR = 265,               /* SEPERATOR  */
    INT_LIT = 266,                 /* INT_LIT  */
    FLOAT_LIT = 267,               /* FLOAT_LIT  */
    CHAR_LIT = 268,                /* CHAR_LIT  */
    STR_LIT = 269,                 /* STR_LIT  */
    TXT_BLK = 270,                 /* TXT_BLK  */
    BOOL_LIT = 271,                /* BOOL_LIT  */
    NULL_LIT = 272,                /* NULL_LIT  */
    KEYWORD = 273,                 /* KEYWORD  */
    ABSTRACT = 274,                /* ABSTRACT  */
    CONTINUE = 275,                /* CONTINUE  */
    FOR = 276,                     /* FOR  */
    NEW = 277,                     /* NEW  */
    SWITCH = 278,                  /* SWITCH  */
    ASSERT = 279,                  /* ASSERT  */
    DEFAULT = 280,                 /* DEFAULT  */
    IF = 281,                      /* IF  */
    PACKAGE = 282,                 /* PACKAGE  */
    SYNCHRONIZED = 283,            /* SYNCHRONIZED  */
    BOOLEAN = 284,                 /* BOOLEAN  */
    DO = 285,                      /* DO  */
    GOTO = 286,                    /* GOTO  */
    PRIVATE = 287,                 /* PRIVATE  */
    THIS = 288,                    /* THIS  */
    BREAK = 289,                   /* BREAK  */
    DOUBLE = 290,                  /* DOUBLE  */
    IMPLEMENTS = 291,              /* IMPLEMENTS  */
    PROTECTED = 292,               /* PROTECTED  */
    THROW = 293,                   /* THROW  */
    BYTE = 294,                    /* BYTE  */
    ELSE = 295,                    /* ELSE  */
    IMPORT = 296,                  /* IMPORT  */
    PUBLIC = 297,                  /* PUBLIC  */
    THROWS = 298,                  /* THROWS  */
    CASE = 299,                    /* CASE  */
    ENUM = 300,                    /* ENUM  */
    INSTANCEOF = 301,              /* INSTANCEOF  */
    RETURN = 302,                  /* RETURN  */
    TRANSIENT = 303,               /* TRANSIENT  */
    CATCH = 304,                   /* CATCH  */
    EXTENDS = 305,                 /* EXTENDS  */
    INT = 306,                     /* INT  */
    SHORT = 307,                   /* SHORT  */
    TRY = 308,                     /* TRY  */
    CHAR = 309,                    /* CHAR  */
    FINAL = 310,                   /* FINAL  */
    INTERFACE = 311,               /* INTERFACE  */
    STATIC = 312,                  /* STATIC  */
    VOID = 313,                    /* VOID  */
    CLASS = 314,                   /* CLASS  */
    FINALLY = 315,                 /* FINALLY  */
    LONG = 316,                    /* LONG  */
    STRICTFP = 317,                /* STRICTFP  */
    VOLATILE = 318,                /* VOLATILE  */
    CONST = 319,                   /* CONST  */
    FLOAT = 320,                   /* FLOAT  */
    NATIVE = 321,                  /* NATIVE  */
    SUPER = 322,                   /* SUPER  */
    WHILE = 323,                   /* WHILE  */
    _ = 324,                       /* _  */
    EXPORTS = 325,                 /* EXPORTS  */
    OPENS = 326,                   /* OPENS  */
    REQUIRES = 327,                /* REQUIRES  */
    USES = 328,                    /* USES  */
    MODULE = 329,                  /* MODULE  */
    PERMITS = 330,                 /* PERMITS  */
    SEALED = 331,                  /* SEALED  */
    VAR = 332,                     /* VAR  */
    PROVIDES = 334,                /* PROVIDES  */
    TO = 335,                      /* TO  */
    WITH = 336,                    /* WITH  */
    OPEN = 337,                    /* OPEN  */
    RECORD = 338,                  /* RECORD  */
    TRANSITIVE = 339,              /* TRANSITIVE  */
    YIELD = 340,                   /* YIELD  */
    IDENTIFIER = 341,              /* IDENTIFIER  */
    ADD = 342,                     /* ADD  */
    SUB = 343,                     /* SUB  */
    MUL = 344,                     /* MUL  */
    QUO = 345,                     /* QUO  */
    REM = 346,                     /* REM  */
    AND = 347,                     /* AND  */
    OR = 348,                      /* OR  */
    XOR = 349,                     /* XOR  */
    SHL = 350,                     /* SHL  */
    SHR = 351,                     /* SHR  */
    GR = 352,                      /* GR  */
    ADD_ASSIGN = 353,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 354,              /* SUB_ASSIGN  */
    MUL_ASSIGN = 355,              /* MUL_ASSIGN  */
    QUO_ASSIGN = 356,              /* QUO_ASSIGN  */
    REM_ASSIGN = 357,              /* REM_ASSIGN  */
    AND_ASSIGN = 358,              /* AND_ASSIGN  */
    OR_ASSIGN = 359,               /* OR_ASSIGN  */
    XOR_ASSIGN = 360,              /* XOR_ASSIGN  */
    SHL_ASSIGN = 361,              /* SHL_ASSIGN  */
    SHR_ASSIGN = 362,              /* SHR_ASSIGN  */
    GEQUAL = 363,                  /* GEQUAL  */
    LAND = 364,                    /* LAND  */
    LOR = 365,                     /* LOR  */
    INC = 366,                     /* INC  */
    DEC = 367,                     /* DEC  */
    EQL = 368,                     /* EQL  */
    NEQ = 369,                     /* NEQ  */
    LEQ = 370,                     /* LEQ  */
    GEQ = 371,                     /* GEQ  */
    ASSIGN = 372,                  /* ASSIGN  */
    ARROW = 373,                   /* ARROW  */
    GTR = 374,                     /* GTR  */
    LSS = 375,                     /* LSS  */
    NOT = 376,                     /* NOT  */
    TILDE = 377,                   /* TILDE  */
    QMARK = 378,                   /* QMARK  */
    ELLIPSIS = 379,                /* ELLIPSIS  */
    COMMA = 380,                   /* COMMA  */
    SEMICOLON = 381,               /* SEMICOLON  */
    DCOLON = 382,                  /* DCOLON  */
    COLON = 383,                   /* COLON  */
    PERIOD = 384,                  /* PERIOD  */
    AMPERSAT = 385,                /* AMPERSAT  */
    PRINTLN = 386                  /* PRINTLN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 79 "lalr1.y"

	astnode *node;

#line 204 "lalr1.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_LALR1_TAB_H_INCLUDED  */
