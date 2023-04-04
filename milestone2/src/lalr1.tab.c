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
#line 1 "lalr1.y"

    #include "lalr1.tab.h"
    #include<bits/stdc++.h>
    #include<fstream>
    #include "symtab.h"
    using namespace std;
    extern int yylex();
    extern FILE *yyin;
    extern FILE *yyout;
    int yyerror(const char*msg);
    extern int yylineno;
    astnode *theprogram;
    int verb=0;
    map< string, symtab_t* > symtab_top;
    symtab_t *symtab =  init_symtab_top();
    int currscope = 0;
    string fullscope = "0";
    int curr_fcnscope = 0;
    string s1,s2;
    ofstream symbolTable;
    ofstream tac;
    //splitting strings separated by comma
    vector<string> split(const string &s, char delim) {
        stringstream ss(s);
        string item;
        vector<string> tokens;
        while (getline(ss, item, delim)) {
            tokens.push_back(item);
        }
        return tokens;
    }
    map<string,string>buffer;// a,int type;
    vector<string>prog;
    int tempno=0;
    int labelno = 0;
    int line=0;
    string get_tempvar(){
        string str_t = "t";
        string ans =  str_t.append(to_string(tempno));
        tempno++;
        return ans;
    }
    string get_label(){
        string str_l = "label";
        string ans =  str_l.append(to_string(labelno));
        labelno++;
        return ans;
    }

    stack <string> if_endlabels;
    stack <string> if_bwlabels;
    stack <string> while_bwlabels;
    stack <string> while_endlabels;
    stack <string> while_exp;
    stack <string> do_bwlabels;
    stack <string> for_initlabels;
    stack <string> for_endlabels;
    stack <string> for_statlabels;
    stack <string> for_updlabels;
    stack <string> cond_bwlabels;
    stack <string> cond_endlabels;
    stack <string> cond_inlabels;
    stack <string> class_labels;
    // stack <string> for_breaklabels;	//not used
    // stack <string> for_continuelabels;

    string cname="class";
    string fname="fname";
    string temp_type="";
    string temp="";
    // string gpara="ud";
    map<string,string>m;//identifier vs label;
    map<string,string>m1;//class vs scope;

#line 146 "lalr1.tab.c"

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

#include "lalr1.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_OPERATOR = 3,                   /* OPERATOR  */
  YYSYMBOL_OPEN_SQ = 4,                    /* OPEN_SQ  */
  YYSYMBOL_CLOSE_SQ = 5,                   /* CLOSE_SQ  */
  YYSYMBOL_OPEN_BR = 6,                    /* OPEN_BR  */
  YYSYMBOL_CLOSE_BR = 7,                   /* CLOSE_BR  */
  YYSYMBOL_OPEN_CR = 8,                    /* OPEN_CR  */
  YYSYMBOL_CLOSE_CR = 9,                   /* CLOSE_CR  */
  YYSYMBOL_SEPERATOR = 10,                 /* SEPERATOR  */
  YYSYMBOL_INT_LIT = 11,                   /* INT_LIT  */
  YYSYMBOL_FLOAT_LIT = 12,                 /* FLOAT_LIT  */
  YYSYMBOL_CHAR_LIT = 13,                  /* CHAR_LIT  */
  YYSYMBOL_STR_LIT = 14,                   /* STR_LIT  */
  YYSYMBOL_TXT_BLK = 15,                   /* TXT_BLK  */
  YYSYMBOL_BOOL_LIT = 16,                  /* BOOL_LIT  */
  YYSYMBOL_NULL_LIT = 17,                  /* NULL_LIT  */
  YYSYMBOL_KEYWORD = 18,                   /* KEYWORD  */
  YYSYMBOL_ABSTRACT = 19,                  /* ABSTRACT  */
  YYSYMBOL_CONTINUE = 20,                  /* CONTINUE  */
  YYSYMBOL_FOR = 21,                       /* FOR  */
  YYSYMBOL_NEW = 22,                       /* NEW  */
  YYSYMBOL_SWITCH = 23,                    /* SWITCH  */
  YYSYMBOL_ASSERT = 24,                    /* ASSERT  */
  YYSYMBOL_DEFAULT = 25,                   /* DEFAULT  */
  YYSYMBOL_IF = 26,                        /* IF  */
  YYSYMBOL_PACKAGE = 27,                   /* PACKAGE  */
  YYSYMBOL_SYNCHRONIZED = 28,              /* SYNCHRONIZED  */
  YYSYMBOL_BOOLEAN = 29,                   /* BOOLEAN  */
  YYSYMBOL_DO = 30,                        /* DO  */
  YYSYMBOL_GOTO = 31,                      /* GOTO  */
  YYSYMBOL_PRIVATE = 32,                   /* PRIVATE  */
  YYSYMBOL_THIS = 33,                      /* THIS  */
  YYSYMBOL_BREAK = 34,                     /* BREAK  */
  YYSYMBOL_DOUBLE = 35,                    /* DOUBLE  */
  YYSYMBOL_IMPLEMENTS = 36,                /* IMPLEMENTS  */
  YYSYMBOL_PROTECTED = 37,                 /* PROTECTED  */
  YYSYMBOL_THROW = 38,                     /* THROW  */
  YYSYMBOL_BYTE = 39,                      /* BYTE  */
  YYSYMBOL_ELSE = 40,                      /* ELSE  */
  YYSYMBOL_IMPORT = 41,                    /* IMPORT  */
  YYSYMBOL_PUBLIC = 42,                    /* PUBLIC  */
  YYSYMBOL_THROWS = 43,                    /* THROWS  */
  YYSYMBOL_CASE = 44,                      /* CASE  */
  YYSYMBOL_ENUM = 45,                      /* ENUM  */
  YYSYMBOL_INSTANCEOF = 46,                /* INSTANCEOF  */
  YYSYMBOL_RETURN = 47,                    /* RETURN  */
  YYSYMBOL_TRANSIENT = 48,                 /* TRANSIENT  */
  YYSYMBOL_CATCH = 49,                     /* CATCH  */
  YYSYMBOL_EXTENDS = 50,                   /* EXTENDS  */
  YYSYMBOL_INT = 51,                       /* INT  */
  YYSYMBOL_SHORT = 52,                     /* SHORT  */
  YYSYMBOL_TRY = 53,                       /* TRY  */
  YYSYMBOL_CHAR = 54,                      /* CHAR  */
  YYSYMBOL_FINAL = 55,                     /* FINAL  */
  YYSYMBOL_INTERFACE = 56,                 /* INTERFACE  */
  YYSYMBOL_STATIC = 57,                    /* STATIC  */
  YYSYMBOL_VOID = 58,                      /* VOID  */
  YYSYMBOL_CLASS = 59,                     /* CLASS  */
  YYSYMBOL_FINALLY = 60,                   /* FINALLY  */
  YYSYMBOL_LONG = 61,                      /* LONG  */
  YYSYMBOL_STRICTFP = 62,                  /* STRICTFP  */
  YYSYMBOL_VOLATILE = 63,                  /* VOLATILE  */
  YYSYMBOL_CONST = 64,                     /* CONST  */
  YYSYMBOL_FLOAT = 65,                     /* FLOAT  */
  YYSYMBOL_NATIVE = 66,                    /* NATIVE  */
  YYSYMBOL_SUPER = 67,                     /* SUPER  */
  YYSYMBOL_WHILE = 68,                     /* WHILE  */
  YYSYMBOL__ = 69,                         /* _  */
  YYSYMBOL_EXPORTS = 70,                   /* EXPORTS  */
  YYSYMBOL_OPENS = 71,                     /* OPENS  */
  YYSYMBOL_REQUIRES = 72,                  /* REQUIRES  */
  YYSYMBOL_USES = 73,                      /* USES  */
  YYSYMBOL_MODULE = 74,                    /* MODULE  */
  YYSYMBOL_PERMITS = 75,                   /* PERMITS  */
  YYSYMBOL_SEALED = 76,                    /* SEALED  */
  YYSYMBOL_VAR = 77,                       /* VAR  */
  YYSYMBOL_78_NON_SEALED = 78,             /* NON-SEALED  */
  YYSYMBOL_PROVIDES = 79,                  /* PROVIDES  */
  YYSYMBOL_TO = 80,                        /* TO  */
  YYSYMBOL_WITH = 81,                      /* WITH  */
  YYSYMBOL_OPEN = 82,                      /* OPEN  */
  YYSYMBOL_RECORD = 83,                    /* RECORD  */
  YYSYMBOL_TRANSITIVE = 84,                /* TRANSITIVE  */
  YYSYMBOL_YIELD = 85,                     /* YIELD  */
  YYSYMBOL_IDENTIFIER = 86,                /* IDENTIFIER  */
  YYSYMBOL_ADD = 87,                       /* ADD  */
  YYSYMBOL_SUB = 88,                       /* SUB  */
  YYSYMBOL_MUL = 89,                       /* MUL  */
  YYSYMBOL_QUO = 90,                       /* QUO  */
  YYSYMBOL_REM = 91,                       /* REM  */
  YYSYMBOL_AND = 92,                       /* AND  */
  YYSYMBOL_OR = 93,                        /* OR  */
  YYSYMBOL_XOR = 94,                       /* XOR  */
  YYSYMBOL_SHL = 95,                       /* SHL  */
  YYSYMBOL_SHR = 96,                       /* SHR  */
  YYSYMBOL_GR = 97,                        /* GR  */
  YYSYMBOL_ADD_ASSIGN = 98,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 99,                /* SUB_ASSIGN  */
  YYSYMBOL_MUL_ASSIGN = 100,               /* MUL_ASSIGN  */
  YYSYMBOL_QUO_ASSIGN = 101,               /* QUO_ASSIGN  */
  YYSYMBOL_REM_ASSIGN = 102,               /* REM_ASSIGN  */
  YYSYMBOL_AND_ASSIGN = 103,               /* AND_ASSIGN  */
  YYSYMBOL_OR_ASSIGN = 104,                /* OR_ASSIGN  */
  YYSYMBOL_XOR_ASSIGN = 105,               /* XOR_ASSIGN  */
  YYSYMBOL_SHL_ASSIGN = 106,               /* SHL_ASSIGN  */
  YYSYMBOL_SHR_ASSIGN = 107,               /* SHR_ASSIGN  */
  YYSYMBOL_GEQUAL = 108,                   /* GEQUAL  */
  YYSYMBOL_LAND = 109,                     /* LAND  */
  YYSYMBOL_LOR = 110,                      /* LOR  */
  YYSYMBOL_INC = 111,                      /* INC  */
  YYSYMBOL_DEC = 112,                      /* DEC  */
  YYSYMBOL_EQL = 113,                      /* EQL  */
  YYSYMBOL_NEQ = 114,                      /* NEQ  */
  YYSYMBOL_LEQ = 115,                      /* LEQ  */
  YYSYMBOL_GEQ = 116,                      /* GEQ  */
  YYSYMBOL_ASSIGN = 117,                   /* ASSIGN  */
  YYSYMBOL_ARROW = 118,                    /* ARROW  */
  YYSYMBOL_GTR = 119,                      /* GTR  */
  YYSYMBOL_LSS = 120,                      /* LSS  */
  YYSYMBOL_NOT = 121,                      /* NOT  */
  YYSYMBOL_TILDE = 122,                    /* TILDE  */
  YYSYMBOL_QMARK = 123,                    /* QMARK  */
  YYSYMBOL_ELLIPSIS = 124,                 /* ELLIPSIS  */
  YYSYMBOL_COMMA = 125,                    /* COMMA  */
  YYSYMBOL_SEMICOLON = 126,                /* SEMICOLON  */
  YYSYMBOL_DCOLON = 127,                   /* DCOLON  */
  YYSYMBOL_COLON = 128,                    /* COLON  */
  YYSYMBOL_PERIOD = 129,                   /* PERIOD  */
  YYSYMBOL_AMPERSAT = 130,                 /* AMPERSAT  */
  YYSYMBOL_PRINTLN = 131,                  /* PRINTLN  */
  YYSYMBOL_YYACCEPT = 132,                 /* $accept  */
  YYSYMBOL_input = 133,                    /* input  */
  YYSYMBOL_SYMTABS = 134,                  /* SYMTABS  */
  YYSYMBOL_SYMTABE = 135,                  /* SYMTABE  */
  YYSYMBOL_IFMARK1 = 136,                  /* IFMARK1  */
  YYSYMBOL_IFEND1 = 137,                   /* IFEND1  */
  YYSYMBOL_IFEND2 = 138,                   /* IFEND2  */
  YYSYMBOL_ELSEMARK1 = 139,                /* ELSEMARK1  */
  YYSYMBOL_ELSEEND1 = 140,                 /* ELSEEND1  */
  YYSYMBOL_WHILEMARK2 = 141,               /* WHILEMARK2  */
  YYSYMBOL_WHILEMARK1 = 142,               /* WHILEMARK1  */
  YYSYMBOL_WHILEEND1 = 143,                /* WHILEEND1  */
  YYSYMBOL_DOMARK1 = 144,                  /* DOMARK1  */
  YYSYMBOL_DOEND1 = 145,                   /* DOEND1  */
  YYSYMBOL_FORMARK1 = 146,                 /* FORMARK1  */
  YYSYMBOL_FORMARK2 = 147,                 /* FORMARK2  */
  YYSYMBOL_FORMARK3 = 148,                 /* FORMARK3  */
  YYSYMBOL_FOREND1 = 149,                  /* FOREND1  */
  YYSYMBOL_CONDMARK1 = 150,                /* CONDMARK1  */
  YYSYMBOL_CONDMARK2 = 151,                /* CONDMARK2  */
  YYSYMBOL_CONDMARK3 = 152,                /* CONDMARK3  */
  YYSYMBOL_PrintStatement = 153,           /* PrintStatement  */
  YYSYMBOL_PrintArgs = 154,                /* PrintArgs  */
  YYSYMBOL_PrintArg = 155,                 /* PrintArg  */
  YYSYMBOL_Literal = 156,                  /* Literal  */
  YYSYMBOL_Type = 157,                     /* Type  */
  YYSYMBOL_PrimitiveType = 158,            /* PrimitiveType  */
  YYSYMBOL_NumericType = 159,              /* NumericType  */
  YYSYMBOL_IntegralType = 160,             /* IntegralType  */
  YYSYMBOL_FloatingPointType = 161,        /* FloatingPointType  */
  YYSYMBOL_ReferenceType = 162,            /* ReferenceType  */
  YYSYMBOL_ClassOrInterfaceType = 163,     /* ClassOrInterfaceType  */
  YYSYMBOL_ClassType = 164,                /* ClassType  */
  YYSYMBOL_InterfaceType = 165,            /* InterfaceType  */
  YYSYMBOL_ArrayType = 166,                /* ArrayType  */
  YYSYMBOL_Name = 167,                     /* Name  */
  YYSYMBOL_SingularName = 168,             /* SingularName  */
  YYSYMBOL_ComplexName = 169,              /* ComplexName  */
  YYSYMBOL_CompilationUnit = 170,          /* CompilationUnit  */
  YYSYMBOL_ImportDeclarations = 171,       /* ImportDeclarations  */
  YYSYMBOL_TypeDeclarations = 172,         /* TypeDeclarations  */
  YYSYMBOL_PackageDeclaration = 173,       /* PackageDeclaration  */
  YYSYMBOL_ImportDeclaration = 174,        /* ImportDeclaration  */
  YYSYMBOL_SingleTypeImportDeclaration = 175, /* SingleTypeImportDeclaration  */
  YYSYMBOL_TypeImportOnDemandDeclaration = 176, /* TypeImportOnDemandDeclaration  */
  YYSYMBOL_TypeDeclaration = 177,          /* TypeDeclaration  */
  YYSYMBOL_Modifiers = 178,                /* Modifiers  */
  YYSYMBOL_Modifier = 179,                 /* Modifier  */
  YYSYMBOL_ClassName = 180,                /* ClassName  */
  YYSYMBOL_ClassDeclaration = 181,         /* ClassDeclaration  */
  YYSYMBOL_Super = 182,                    /* Super  */
  YYSYMBOL_Interfaces = 183,               /* Interfaces  */
  YYSYMBOL_InterfaceTypeList = 184,        /* InterfaceTypeList  */
  YYSYMBOL_CLASSMARK1 = 185,               /* CLASSMARK1  */
  YYSYMBOL_ClassBody = 186,                /* ClassBody  */
  YYSYMBOL_ClassBodyDeclarations = 187,    /* ClassBodyDeclarations  */
  YYSYMBOL_ClassBodyDeclaration = 188,     /* ClassBodyDeclaration  */
  YYSYMBOL_ClassMemberDeclaration = 189,   /* ClassMemberDeclaration  */
  YYSYMBOL_FieldDeclaration = 190,         /* FieldDeclaration  */
  YYSYMBOL_VariableDeclarators = 191,      /* VariableDeclarators  */
  YYSYMBOL_VariableDeclarator = 192,       /* VariableDeclarator  */
  YYSYMBOL_VariableDeclaratorId = 193,     /* VariableDeclaratorId  */
  YYSYMBOL_VariableInitializer = 194,      /* VariableInitializer  */
  YYSYMBOL_MethodDeclaration = 195,        /* MethodDeclaration  */
  YYSYMBOL_MethodHeader = 196,             /* MethodHeader  */
  YYSYMBOL_MethodDeclarator = 197,         /* MethodDeclarator  */
  YYSYMBOL_FunctionName = 198,             /* FunctionName  */
  YYSYMBOL_FormalParameterLists = 199,     /* FormalParameterLists  */
  YYSYMBOL_FormalParameterList = 200,      /* FormalParameterList  */
  YYSYMBOL_FormalParameter = 201,          /* FormalParameter  */
  YYSYMBOL_Throws = 202,                   /* Throws  */
  YYSYMBOL_ClassTypeList = 203,            /* ClassTypeList  */
  YYSYMBOL_MethodBody = 204,               /* MethodBody  */
  YYSYMBOL_StaticInitializer = 205,        /* StaticInitializer  */
  YYSYMBOL_ConstructorDeclaration = 206,   /* ConstructorDeclaration  */
  YYSYMBOL_ConstructorDeclarator = 207,    /* ConstructorDeclarator  */
  YYSYMBOL_ConstructorName = 208,          /* ConstructorName  */
  YYSYMBOL_ConstructorBody = 209,          /* ConstructorBody  */
  YYSYMBOL_ExplicitConstructorInvocation = 210, /* ExplicitConstructorInvocation  */
  YYSYMBOL_InterfaceDeclaration = 211,     /* InterfaceDeclaration  */
  YYSYMBOL_ExtendsInterfaces = 212,        /* ExtendsInterfaces  */
  YYSYMBOL_InterfaceBody = 213,            /* InterfaceBody  */
  YYSYMBOL_InterfaceMemberDeclarations = 214, /* InterfaceMemberDeclarations  */
  YYSYMBOL_InterfaceMemberDeclaration = 215, /* InterfaceMemberDeclaration  */
  YYSYMBOL_ConstantDeclaration = 216,      /* ConstantDeclaration  */
  YYSYMBOL_AbstractMethodDeclaration = 217, /* AbstractMethodDeclaration  */
  YYSYMBOL_ArrayInitializer = 218,         /* ArrayInitializer  */
  YYSYMBOL_VariableInitializers = 219,     /* VariableInitializers  */
  YYSYMBOL_Block = 220,                    /* Block  */
  YYSYMBOL_BlockStatements = 221,          /* BlockStatements  */
  YYSYMBOL_BlockStatement = 222,           /* BlockStatement  */
  YYSYMBOL_LocalVariableDeclarationStatement = 223, /* LocalVariableDeclarationStatement  */
  YYSYMBOL_LocalVariableDeclaration = 224, /* LocalVariableDeclaration  */
  YYSYMBOL_Statement = 225,                /* Statement  */
  YYSYMBOL_StatementNoShortIf = 226,       /* StatementNoShortIf  */
  YYSYMBOL_StatementWithoutTrailingSubstatement = 227, /* StatementWithoutTrailingSubstatement  */
  YYSYMBOL_EmptyStatement = 228,           /* EmptyStatement  */
  YYSYMBOL_LabeledStatement = 229,         /* LabeledStatement  */
  YYSYMBOL_LabeledStatementNoShortIf = 230, /* LabeledStatementNoShortIf  */
  YYSYMBOL_ExpressionStatement = 231,      /* ExpressionStatement  */
  YYSYMBOL_StatementExpression = 232,      /* StatementExpression  */
  YYSYMBOL_IfThenStatement = 233,          /* IfThenStatement  */
  YYSYMBOL_IfThenElseStatement = 234,      /* IfThenElseStatement  */
  YYSYMBOL_IfThenElseStatementNoShortIf = 235, /* IfThenElseStatementNoShortIf  */
  YYSYMBOL_SwitchStatement = 236,          /* SwitchStatement  */
  YYSYMBOL_SwitchBlock = 237,              /* SwitchBlock  */
  YYSYMBOL_SwitchBlockStatementGroups = 238, /* SwitchBlockStatementGroups  */
  YYSYMBOL_SwitchBlockStatementGroup = 239, /* SwitchBlockStatementGroup  */
  YYSYMBOL_SwitchLabels = 240,             /* SwitchLabels  */
  YYSYMBOL_SwitchLabel = 241,              /* SwitchLabel  */
  YYSYMBOL_WhileStatement = 242,           /* WhileStatement  */
  YYSYMBOL_WhileStatementNoShortIf = 243,  /* WhileStatementNoShortIf  */
  YYSYMBOL_DoStatement = 244,              /* DoStatement  */
  YYSYMBOL_ForStatement = 245,             /* ForStatement  */
  YYSYMBOL_ForStatementNoShortIf = 246,    /* ForStatementNoShortIf  */
  YYSYMBOL_ForInit = 247,                  /* ForInit  */
  YYSYMBOL_ForUpdate = 248,                /* ForUpdate  */
  YYSYMBOL_StatementExpressionList = 249,  /* StatementExpressionList  */
  YYSYMBOL_BreakStatement = 250,           /* BreakStatement  */
  YYSYMBOL_ContinueStatement = 251,        /* ContinueStatement  */
  YYSYMBOL_ReturnStatement = 252,          /* ReturnStatement  */
  YYSYMBOL_ThrowStatement = 253,           /* ThrowStatement  */
  YYSYMBOL_SynchronizedStatement = 254,    /* SynchronizedStatement  */
  YYSYMBOL_TryStatement = 255,             /* TryStatement  */
  YYSYMBOL_Catches = 256,                  /* Catches  */
  YYSYMBOL_CatchClause = 257,              /* CatchClause  */
  YYSYMBOL_Finally = 258,                  /* Finally  */
  YYSYMBOL_Primary = 259,                  /* Primary  */
  YYSYMBOL_PrimaryNoNewArray = 260,        /* PrimaryNoNewArray  */
  YYSYMBOL_ClassInstanceCreationExpression = 261, /* ClassInstanceCreationExpression  */
  YYSYMBOL_ArgumentList = 262,             /* ArgumentList  */
  YYSYMBOL_ArrayCreationExpression = 263,  /* ArrayCreationExpression  */
  YYSYMBOL_DimExprs = 264,                 /* DimExprs  */
  YYSYMBOL_DimExpr = 265,                  /* DimExpr  */
  YYSYMBOL_Dims = 266,                     /* Dims  */
  YYSYMBOL_FieldAccess = 267,              /* FieldAccess  */
  YYSYMBOL_MethodInvocation = 268,         /* MethodInvocation  */
  YYSYMBOL_ArrayAccess = 269,              /* ArrayAccess  */
  YYSYMBOL_PostfixExpression = 270,        /* PostfixExpression  */
  YYSYMBOL_PostIncrementExpression = 271,  /* PostIncrementExpression  */
  YYSYMBOL_PostDecrementExpression = 272,  /* PostDecrementExpression  */
  YYSYMBOL_UnaryExpression = 273,          /* UnaryExpression  */
  YYSYMBOL_PreIncrementExpression = 274,   /* PreIncrementExpression  */
  YYSYMBOL_PreDecrementExpression = 275,   /* PreDecrementExpression  */
  YYSYMBOL_UnaryExpressionNotPlusMinus = 276, /* UnaryExpressionNotPlusMinus  */
  YYSYMBOL_CastExpression = 277,           /* CastExpression  */
  YYSYMBOL_MultiplicativeExpression = 278, /* MultiplicativeExpression  */
  YYSYMBOL_AdditiveExpression = 279,       /* AdditiveExpression  */
  YYSYMBOL_ShiftExpression = 280,          /* ShiftExpression  */
  YYSYMBOL_RelationalExpression = 281,     /* RelationalExpression  */
  YYSYMBOL_EqualityExpression = 282,       /* EqualityExpression  */
  YYSYMBOL_AndExpression = 283,            /* AndExpression  */
  YYSYMBOL_ExclusiveOrExpression = 284,    /* ExclusiveOrExpression  */
  YYSYMBOL_InclusiveOrExpression = 285,    /* InclusiveOrExpression  */
  YYSYMBOL_ConditionalAndExpression = 286, /* ConditionalAndExpression  */
  YYSYMBOL_ConditionalOrExpression = 287,  /* ConditionalOrExpression  */
  YYSYMBOL_ConditionalExpression = 288,    /* ConditionalExpression  */
  YYSYMBOL_AssignmentExpression = 289,     /* AssignmentExpression  */
  YYSYMBOL_Assignment = 290,               /* Assignment  */
  YYSYMBOL_LeftHandSide = 291,             /* LeftHandSide  */
  YYSYMBOL_AssignmentOperator = 292,       /* AssignmentOperator  */
  YYSYMBOL_Expression = 293,               /* Expression  */
  YYSYMBOL_ConstantExpression = 294        /* ConstantExpression  */
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
typedef yytype_int16 yy_state_t;

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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  37
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3482

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  132
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  163
/* YYNRULES -- Number of rules.  */
#define YYNRULES  382
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  717

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   386


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   101,   101,   119,   151,   186,   203,   212,   221,   230,
     240,   250,   264,   280,   289,   298,   307,   324,   337,   350,
     362,   374,   382,   397,   408,   421,   432,   443,   449,   461,
     472,   483,   494,   505,   519,   529,   541,   550,   561,   570,
     581,   590,   599,   608,   617,   628,   637,   648,   659,   671,
     684,   696,   709,   720,   731,   745,   757,   771,   789,   816,
     824,   832,   841,   850,   860,   869,   877,   887,   895,   906,
     914,   925,   937,   945,   955,   967,   981,   990,   999,  1009,
    1018,  1030,  1038,  1046,  1055,  1063,  1071,  1079,  1087,  1095,
    1103,  1114,  1128,  1143,  1157,  1171,  1184,  1198,  1211,  1224,
    1238,  1250,  1262,  1271,  1284,  1292,  1303,  1314,  1322,  1333,
    1342,  1351,  1362,  1371,  1383,  1400,  1418,  1434,  1453,  1466,
    1526,  1546,  1577,  1591,  1610,  1632,  1646,  1658,  1670,  1681,
    1694,  1706,  1718,  1731,  1744,  1755,  1769,  1796,  1817,  1828,
    1843,  1859,  1870,  1878,  1890,  1898,  1909,  1921,  1932,  1942,
    1952,  1964,  1976,  1989,  2005,  2016,  2026,  2036,  2047,  2059,
    2070,  2082,  2096,  2108,  2119,  2130,  2142,  2151,  2163,  2173,
    2184,  2192,  2203,  2211,  2221,  2231,  2243,  2270,  2295,  2315,
    2336,  2353,  2385,  2394,  2406,  2414,  2425,  2441,  2452,  2467,
    2485,  2494,  2502,  2510,  2518,  2526,  2536,  2544,  2552,  2560,
    2568,  2578,  2586,  2594,  2603,  2611,  2619,  2627,  2635,  2643,
    2651,  2659,  2669,  2679,  2695,  2711,  2724,  2734,  2744,  2754,
    2764,  2774,  2785,  2795,  2808,  2822,  2838,  2854,  2868,  2877,
    2887,  2897,  2910,  2918,  2929,  2940,  2948,  2959,  2969,  2980,
    2994,  3008,  3024,  3037,  3051,  3065,  3080,  3094,  3109,  3124,
    3142,  3155,  3169,  3183,  3198,  3212,  3227,  3242,  3260,  3269,
    3285,  3296,  3305,  3318,  3331,  3343,  3356,  3372,  3384,  3403,
    3415,  3429,  3439,  3449,  3462,  3470,  3481,  3495,  3509,  3529,
    3543,  3555,  3565,  3582,  3593,  3604,  3617,  3633,  3664,  3704,
    3714,  3728,  3745,  3762,  3779,  3799,  3810,  3824,  3842,  3852,
    3865,  3886,  3900,  3970,  4060,  4088,  4120,  4140,  4173,  4205,
    4236,  4249,  4261,  4272,  4285,  4306,  4327,  4339,  4350,  4367,
    4384,  4399,  4420,  4441,  4454,  4471,  4488,  4500,  4516,  4533,
    4545,  4563,  4576,  4612,  4648,  4686,  4699,  4736,  4774,  4787,
    4823,  4859,  4897,  4910,  4946,  4982,  5018,  5054,  5076,  5089,
    5125,  5163,  5176,  5214,  5227,  5265,  5278,  5316,  5329,  5367,
    5380,  5418,  5431,  5456,  5469,  5482,  5534,  5545,  5555,  5571,
    5580,  5589,  5598,  5607,  5616,  5625,  5634,  5643,  5652,  5661,
    5670,  5681,  5696
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "OPERATOR", "OPEN_SQ",
  "CLOSE_SQ", "OPEN_BR", "CLOSE_BR", "OPEN_CR", "CLOSE_CR", "SEPERATOR",
  "INT_LIT", "FLOAT_LIT", "CHAR_LIT", "STR_LIT", "TXT_BLK", "BOOL_LIT",
  "NULL_LIT", "KEYWORD", "ABSTRACT", "CONTINUE", "FOR", "NEW", "SWITCH",
  "ASSERT", "DEFAULT", "IF", "PACKAGE", "SYNCHRONIZED", "BOOLEAN", "DO",
  "GOTO", "PRIVATE", "THIS", "BREAK", "DOUBLE", "IMPLEMENTS", "PROTECTED",
  "THROW", "BYTE", "ELSE", "IMPORT", "PUBLIC", "THROWS", "CASE", "ENUM",
  "INSTANCEOF", "RETURN", "TRANSIENT", "CATCH", "EXTENDS", "INT", "SHORT",
  "TRY", "CHAR", "FINAL", "INTERFACE", "STATIC", "VOID", "CLASS",
  "FINALLY", "LONG", "STRICTFP", "VOLATILE", "CONST", "FLOAT", "NATIVE",
  "SUPER", "WHILE", "_", "EXPORTS", "OPENS", "REQUIRES", "USES", "MODULE",
  "PERMITS", "SEALED", "VAR", "NON-SEALED", "PROVIDES", "TO", "WITH",
  "OPEN", "RECORD", "TRANSITIVE", "YIELD", "IDENTIFIER", "ADD", "SUB",
  "MUL", "QUO", "REM", "AND", "OR", "XOR", "SHL", "SHR", "GR",
  "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "QUO_ASSIGN", "REM_ASSIGN",
  "AND_ASSIGN", "OR_ASSIGN", "XOR_ASSIGN", "SHL_ASSIGN", "SHR_ASSIGN",
  "GEQUAL", "LAND", "LOR", "INC", "DEC", "EQL", "NEQ", "LEQ", "GEQ",
  "ASSIGN", "ARROW", "GTR", "LSS", "NOT", "TILDE", "QMARK", "ELLIPSIS",
  "COMMA", "SEMICOLON", "DCOLON", "COLON", "PERIOD", "AMPERSAT", "PRINTLN",
  "$accept", "input", "SYMTABS", "SYMTABE", "IFMARK1", "IFEND1", "IFEND2",
  "ELSEMARK1", "ELSEEND1", "WHILEMARK2", "WHILEMARK1", "WHILEEND1",
  "DOMARK1", "DOEND1", "FORMARK1", "FORMARK2", "FORMARK3", "FOREND1",
  "CONDMARK1", "CONDMARK2", "CONDMARK3", "PrintStatement", "PrintArgs",
  "PrintArg", "Literal", "Type", "PrimitiveType", "NumericType",
  "IntegralType", "FloatingPointType", "ReferenceType",
  "ClassOrInterfaceType", "ClassType", "InterfaceType", "ArrayType",
  "Name", "SingularName", "ComplexName", "CompilationUnit",
  "ImportDeclarations", "TypeDeclarations", "PackageDeclaration",
  "ImportDeclaration", "SingleTypeImportDeclaration",
  "TypeImportOnDemandDeclaration", "TypeDeclaration", "Modifiers",
  "Modifier", "ClassName", "ClassDeclaration", "Super", "Interfaces",
  "InterfaceTypeList", "CLASSMARK1", "ClassBody", "ClassBodyDeclarations",
  "ClassBodyDeclaration", "ClassMemberDeclaration", "FieldDeclaration",
  "VariableDeclarators", "VariableDeclarator", "VariableDeclaratorId",
  "VariableInitializer", "MethodDeclaration", "MethodHeader",
  "MethodDeclarator", "FunctionName", "FormalParameterLists",
  "FormalParameterList", "FormalParameter", "Throws", "ClassTypeList",
  "MethodBody", "StaticInitializer", "ConstructorDeclaration",
  "ConstructorDeclarator", "ConstructorName", "ConstructorBody",
  "ExplicitConstructorInvocation", "InterfaceDeclaration",
  "ExtendsInterfaces", "InterfaceBody", "InterfaceMemberDeclarations",
  "InterfaceMemberDeclaration", "ConstantDeclaration",
  "AbstractMethodDeclaration", "ArrayInitializer", "VariableInitializers",
  "Block", "BlockStatements", "BlockStatement",
  "LocalVariableDeclarationStatement", "LocalVariableDeclaration",
  "Statement", "StatementNoShortIf",
  "StatementWithoutTrailingSubstatement", "EmptyStatement",
  "LabeledStatement", "LabeledStatementNoShortIf", "ExpressionStatement",
  "StatementExpression", "IfThenStatement", "IfThenElseStatement",
  "IfThenElseStatementNoShortIf", "SwitchStatement", "SwitchBlock",
  "SwitchBlockStatementGroups", "SwitchBlockStatementGroup",
  "SwitchLabels", "SwitchLabel", "WhileStatement",
  "WhileStatementNoShortIf", "DoStatement", "ForStatement",
  "ForStatementNoShortIf", "ForInit", "ForUpdate",
  "StatementExpressionList", "BreakStatement", "ContinueStatement",
  "ReturnStatement", "ThrowStatement", "SynchronizedStatement",
  "TryStatement", "Catches", "CatchClause", "Finally", "Primary",
  "PrimaryNoNewArray", "ClassInstanceCreationExpression", "ArgumentList",
  "ArrayCreationExpression", "DimExprs", "DimExpr", "Dims", "FieldAccess",
  "MethodInvocation", "ArrayAccess", "PostfixExpression",
  "PostIncrementExpression", "PostDecrementExpression", "UnaryExpression",
  "PreIncrementExpression", "PreDecrementExpression",
  "UnaryExpressionNotPlusMinus", "CastExpression",
  "MultiplicativeExpression", "AdditiveExpression", "ShiftExpression",
  "RelationalExpression", "EqualityExpression", "AndExpression",
  "ExclusiveOrExpression", "InclusiveOrExpression",
  "ConditionalAndExpression", "ConditionalOrExpression",
  "ConditionalExpression", "AssignmentExpression", "Assignment",
  "LeftHandSide", "AssignmentOperator", "Expression", "ConstantExpression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-457)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-369)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     344,  -457,   -24,  -457,  -457,  -457,   -24,  -457,  -457,  -457,
      76,  -457,    85,  -457,  -457,  -457,    42,  -457,  1105,  3112,
    1105,  -457,  -457,  -457,  -457,   680,  -457,  -457,  -457,  -457,
     -19,  -457,  -457,   132,    27,  -457,    51,  -457,  3112,  -457,
    -457,  1105,  3112,    95,    85,  -457,  -457,   111,  -457,   178,
     228,   -24,    32,  -457,   250,   -24,   -24,   184,   255,  -457,
    3112,    27,    51,  -457,    80,  -457,  3316,  -457,  -457,   145,
     -24,  -457,  -457,  -457,  -457,   153,  -457,  -457,   255,  -457,
    -457,    32,  -457,   184,   255,  -457,  -457,  -457,  -457,  -457,
    -457,  -457,  -457,   194,  -457,  -457,   221,   305,  -457,  -457,
    -457,  -457,  -457,   314,     4,  3356,  -457,   213,  3236,  -457,
    -457,  -457,  -457,  3396,   -24,  -457,  -457,   255,  -457,  -457,
    -457,    52,   315,   338,   -78,  -457,    15,    52,   342,   350,
     356,   194,   221,  -457,  -457,  -457,   361,   369,  3356,  3276,
    -457,  -457,  -457,  -457,     9,  -457,  -457,    77,   372,  -457,
    -457,   379,   -24,  -457,   958,   318,  -457,   386,  2910,  -457,
    -457,  -457,  -457,    52,   125,    52,  -457,   400,  -457,    77,
    -457,  -457,  -457,  -457,  -457,   402,   406,  -457,  1232,  -457,
    -457,   293,  -457,   318,   426,   310,  -457,  -457,  -457,  -457,
    2819,    43,  -457,  -457,  -457,  -457,  -457,  -457,   475,  -457,
     308,  3094,  3094,  3094,  3094,  3094,  3094,  -457,   493,  -457,
    -457,   317,   435,  -457,  -457,  2590,  -457,  2693,   277,  -457,
    -457,  -457,  -457,  -457,  -457,  -457,   235,   307,   325,   119,
     345,   319,   367,   351,   348,   102,  -457,  -457,  -457,  3125,
    -457,  -457,  -457,  -457,  -457,  2261,   406,  -457,  -457,  -457,
    2328,  -457,  -457,   460,   -24,   465,  -457,   475,   264,   829,
     473,  -457,   472,  2910,   481,   481,   482,   404,    24,  -457,
    -457,  -457,  -457,  -457,  -457,  -457,  -457,  3094,  2850,   405,
    3094,  -457,  -457,  3094,  3094,  3094,  3094,  3094,  3094,  3094,
    3094,   475,  3094,  3094,  3094,  3094,  3094,  3094,  3094,  3094,
    3094,  3094,  3094,   370,  -457,  -457,  -457,  -457,  -457,  -457,
    -457,  -457,  -457,  -457,  -457,  -457,  3094,  3094,   -48,   489,
     497,   500,   503,  -457,   -40,  3094,  2654,   361,  -457,   383,
    -457,   215,  -457,   318,    37,  -457,  1993,  -457,  -457,   387,
    -457,  -457,  -457,  -457,  -457,   389,  -457,  -457,  -457,  -457,
    -457,  -457,  -457,  -457,  -457,  -457,  -457,  -457,    38,    54,
     277,   354,   363,  -457,  -457,  -457,  -457,   510,    31,  2060,
    2127,  -457,  -457,  -457,   513,  3094,   269,  2700,   298,  1505,
    -457,  -457,    64,  3094,   515,  -457,   515,  2941,   514,   518,
    -457,    26,  -457,   519,   523,  -457,  -457,  -457,   235,   235,
     307,   307,   307,   305,  -457,   325,   325,   325,   325,   119,
     119,   345,   319,   367,   351,   348,  3094,  -457,   517,   407,
    -457,  1706,  3094,  3094,  3094,  2395,   411,  -457,   412,  -457,
     417,   197,   526,  2395,  -457,    22,  -457,  -457,   420,  2757,
    -457,  -457,  -457,  -457,  2972,  3003,  -457,  2194,  -457,  -457,
    -457,   541,  3094,  1505,  -457,  -457,  2879,   542,  2700,  -457,
     545,   545,  -457,    50,  3034,  -457,  -457,  3094,  3065,  -457,
    -457,  -457,  -457,   424,  -457,  -457,  -457,   428,   544,   550,
     551,   491,  -457,  -457,  -457,   554,   361,   197,  -457,  -457,
    3094,  -457,  -457,   215,  -457,   436,    58,   437,    59,  -457,
    -457,  -457,  -457,  -457,  -457,  -457,  -457,  -457,  -457,  -457,
    -457,    60,  -457,  -457,    62,   438,  3094,   439,   329,   561,
    -457,   361,   564,   475,  -457,  -457,  -457,   565,  -457,  -457,
     445,  -457,   447,  -457,  -457,  -457,  -457,  3094,   448,  -457,
    3094,  -457,   566,  -457,  2444,  -457,  3094,   570,  -457,  -457,
    -457,  -457,   316,   452,   456,  -457,  -457,    47,   578,   579,
    -457,   459,  -457,  -457,   548,  -457,  -457,  -457,  -457,   582,
     361,  2395,  -457,  -457,   583,   428,  1654,  2482,   476,   479,
    3094,    71,  -457,  1855,  -457,  1706,  3094,   597,  2444,  -457,
     568,   483,  -457,  -457,  2395,  -457,  -457,   604,  -457,   605,
    2511,  -457,  -457,   486,  -457,  -457,  1926,  -457,  2261,  -457,
     490,  -457,   608,  3094,  -457,  -457,  -457,  -457,  -457,  2395,
    2395,  -457,  2395,  -457,  -457,   610,  -457,  -457,  -457,  -457,
    3094,   492,  -457,   614,  2395,  -457,  -457,  -457,  -457,  2395,
    -457,  2395,  2395,  -457,  -457,   498,  -457,  3094,  2444,  -457,
    -457,  -457,  -457,  -457,  -457,  -457,  -457,  2395,  2525,   499,
     501,  -457,  -457,  2444,  -457,  -457,  -457,  -457,  -457,  -457,
     621,  2573,  2613,   504,   589,  -457,  -457,  2444,  -457,  -457,
     626,  -457,   627,  2641,  -457,  -457,  -457,  2444,  2444,  -457,
    2444,  -457,  -457,   628,  2444,  -457,  -457,  -457,  2444,  -457,
    2444,  2444,  -457,  -457,  -457,  -457,  -457,  -457,  -457,  -457,
    2444,  -457,  -457,  -457,  -457,  -457,  -457
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
      59,    85,     0,    88,    83,    82,     0,    81,    89,    86,
       0,    84,     0,    90,    87,    78,     0,     2,    65,    66,
      60,    67,    72,    73,    69,     0,    79,    76,    77,    57,
       0,    55,    56,     0,     0,    91,     0,     1,    64,    68,
      70,    61,    62,     0,     0,    80,    71,     0,    74,     0,
       3,     0,     0,   165,     3,     0,     0,     0,     0,    99,
      63,     0,     0,    58,     0,   169,     0,    51,   166,    49,
       0,   164,   106,   104,   102,   101,    50,   100,     0,    97,
      98,     0,   163,     0,     0,    95,    75,    37,    46,    40,
      42,    41,    44,     0,    43,    45,     0,    34,    36,    38,
      39,    35,    47,    48,    49,     0,   174,     0,     0,   170,
     172,   173,   167,     0,     0,    96,   162,     0,    93,    94,
     136,   132,     0,   120,     0,   116,   118,   128,     0,     0,
       0,     0,     0,   175,     4,   171,    84,    55,     0,     0,
     107,   109,   112,   113,     0,   110,   111,     0,     0,   103,
      92,     0,     0,   131,     0,     0,   115,     0,     0,   127,
      52,    54,    53,   130,     0,   126,   168,     3,   146,     0,
       4,   108,   145,   124,   144,     3,     0,   150,     0,   135,
     142,   141,   134,     0,     0,   137,   138,   120,   117,   121,
       0,     3,    28,    29,    31,    32,    30,    33,     0,   281,
       0,     0,     0,     0,     0,     0,     0,   280,   311,   119,
     123,   310,   278,   283,   279,   284,   285,   286,   323,   312,
     313,   331,   316,   317,   320,   326,   335,   338,   342,   348,
     351,   353,   355,   357,   359,   361,   363,   381,   364,     0,
     122,   129,   114,   125,   182,     0,     0,   148,   105,   157,
       0,   149,   152,     0,     0,   140,   133,     0,     0,   311,
       0,   179,     0,     0,     0,    50,     0,     0,   311,   284,
     286,   318,   319,   321,   322,   325,   324,     0,     0,     0,
       0,   314,   315,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   373,   374,   370,   371,   372,   378,
     380,   379,   375,   376,   377,   369,     0,     0,     0,     0,
       0,     0,     0,    13,     0,     0,     0,     0,    10,    57,
     212,    27,   223,     0,   366,   201,     0,   184,   186,     0,
     187,   190,   202,   191,   203,     0,   192,   193,   204,   194,
     205,   195,   206,   207,   208,   210,   209,   211,   283,   285,
       0,   219,   220,   217,   218,   216,   147,   281,     0,     0,
       0,   151,   143,   139,     0,     0,     0,     0,     0,   282,
     178,   180,     0,     0,   291,   295,   293,     0,   301,     0,
     302,     0,   289,   300,     0,   332,   333,   334,   336,   337,
     339,   340,   341,     0,   347,   345,   346,   344,   343,   349,
     350,   352,   354,   356,   358,   360,     0,   365,     0,     0,
     265,    15,     0,     0,     0,     0,     0,   263,     0,   267,
       0,     0,     0,     0,    25,     0,    23,    26,   189,     0,
       4,   185,   188,   215,     0,     0,     4,     0,     4,   298,
     327,     0,     0,     0,   329,     4,     0,     0,     0,   296,
     292,   294,   287,     0,     0,   308,   303,     0,     0,   309,
      20,   282,   266,     0,   259,   261,    15,   258,     0,     0,
       0,     0,   264,   269,   268,     0,     0,   271,   274,   272,
       0,   213,    22,    27,   183,     0,     0,     0,     0,   155,
       4,   156,   299,   328,   330,   177,     4,   181,   297,   288,
     306,     0,   290,   304,     0,     0,    16,     0,     0,     0,
       5,     0,     0,     0,   277,   275,   273,     0,    24,   159,
       0,   161,     0,   154,   176,   307,   305,     0,     0,    16,
      16,   262,     3,   227,     0,   270,     0,     0,    11,   158,
     160,    21,     0,     0,     0,    16,   228,     0,     0,     0,
      10,    57,     6,     7,   190,   197,   198,   199,   200,     0,
       0,     0,   362,    17,     0,   260,     0,     0,     0,     0,
       0,     0,   232,     0,   235,    15,     0,     0,     0,   224,
       0,     0,   276,    12,     0,    17,    17,     0,    17,     0,
       0,   238,   382,     0,     4,   233,     0,     4,   234,   236,
       0,    15,     0,     0,   214,     8,    14,   239,    18,     0,
       0,    17,     0,    17,    17,     0,   237,   229,     4,   230,
      16,     0,     5,     0,     0,   241,   242,    18,    18,     0,
      18,     0,     0,    17,   231,     0,    16,    16,     0,    11,
       9,   243,   244,    18,   246,    18,    18,     0,     0,     0,
       0,    16,     7,     0,   225,   245,   247,   248,    18,    17,
       0,     0,     0,     0,     0,    12,   249,     0,    17,    17,
       0,    17,     0,     0,     8,   240,    18,     0,     0,    17,
       0,    17,    17,     0,     0,   250,    18,    18,     0,    18,
       0,     0,    17,     9,   251,   252,    18,   254,    18,    18,
       0,   226,   253,   255,   256,    18,   257
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -457,  -457,   -53,  -136,     7,  -457,   -22,   -43,   -61,    87,
       1,   -23,  -457,  -457,  -455,  -456,   270,  2554,  -457,  -457,
    -457,  -457,  -457,   161,  -316,   -50,  -167,  -457,  -457,  -457,
     365,   -44,  -127,     5,  -457,    -2,   103,  -457,  -457,   637,
     229,  -457,   195,  -457,  -457,   374,   -34,    56,   615,  -457,
     596,    35,  -457,  -457,   296,  -457,   521,  -457,   -37,  -119,
     507,   480,  -245,  -457,   106,    -6,  -457,   488,  -457,  -251,
      97,  -457,  -457,  -457,  -457,   530,  -457,  -125,  -457,  -457,
     603,   134,  -457,   563,  -457,  -457,  -457,  -457,  -134,  -223,
    -331,  -457,  -412,  1142,   -12,  -146,  -457,  -457,  -457,  -457,
    -418,  -457,  -457,  -457,  -457,  -457,  -457,    91,    92,  -350,
    -457,  -457,  -457,  -457,  -457,    89,  -171,  -407,  -457,  -457,
    -457,  -457,  -457,  -457,  -457,   192,   203,  -457,  -457,    61,
    -351,  -457,   419,  -255,  -239,  1354,   198,  1407,   398,   535,
     672,   -62,   780,   906,  -355,  -457,   190,   136,   160,   187,
     393,   378,   385,   391,   392,  -457,   156,   380,  -108,  -457,
    -457,    40,  -457
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    16,    66,   166,   544,   589,   590,   634,   664,   432,
     571,   617,   425,   635,   473,   538,   594,   636,   303,   515,
     572,   332,   435,   436,   207,   333,    97,    98,    99,   100,
     101,   102,    77,    68,   103,   208,    31,    32,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    36,    27,
      57,    58,    75,   113,    59,   139,   140,   141,   106,   124,
     125,   126,   209,   143,   107,   121,   122,   184,   185,   186,
     153,   181,   173,   145,   146,   147,   148,   177,   369,    28,
      52,    53,   108,   109,   110,   111,   210,   382,   335,   608,
     337,   338,   339,   340,   563,   341,   342,   343,   565,   344,
     345,   346,   347,   566,   348,   543,   581,   582,   583,   584,
     349,   567,   350,   351,   568,   476,   574,   575,   352,   353,
     354,   355,   356,   357,   487,   488,   489,   211,   212,   213,
     391,   214,   384,   385,   376,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   365,   239,
     316,   392,   603
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      30,    73,   168,   475,    33,   441,   373,    67,   130,   474,
     174,    67,    76,   164,   477,   437,    96,   167,   381,   157,
     378,   517,   336,   258,   454,   180,    67,   370,   277,   492,
     278,   264,   105,   466,   248,    50,   463,   445,   419,   441,
      50,   439,    37,   278,   247,  -222,   426,   155,   156,    69,
     238,   251,   261,    69,    69,   132,   151,   509,    96,    54,
      74,  -221,    29,    96,   104,   530,   532,   535,    69,   536,
      67,   266,   579,   455,   105,   112,   142,    51,   420,   138,
     604,    45,   238,   553,   554,   175,   427,    55,   132,    96,
     127,   580,    78,   496,   498,   152,   579,    84,   504,   578,
     541,    56,   142,   104,   183,   138,   104,    46,    76,   493,
      47,   104,    69,   511,   245,   580,   441,   514,   117,   149,
     152,   366,   250,   -49,   403,   163,   165,   372,   183,   459,
     610,   459,   158,    47,   475,   172,   104,   104,   263,   271,
     272,   273,   274,   275,   276,   460,   447,   461,  -311,  -311,
      69,   467,   104,    47,   265,   238,   631,    70,   475,   475,
     267,    45,    34,  -222,  -222,   291,    47,   475,   262,   238,
     238,    35,   238,   474,   645,   467,   104,   437,   477,  -221,
    -221,    61,   475,   467,   467,   467,    71,   467,   259,   456,
     659,   660,    54,   431,    45,    82,    69,    63,   240,   268,
     268,   268,   268,   268,   268,   673,    86,   183,   238,   238,
      76,   507,   302,    39,   438,   116,   137,   238,   238,   144,
      55,   395,   396,   397,   159,   -19,   192,   193,   194,   195,
     260,   196,   197,   609,   292,   293,    39,    65,   294,   295,
     475,   137,   137,   334,   176,   144,   485,    38,   334,    42,
     155,   242,    69,   475,   475,   104,   609,   486,    48,    72,
     241,    49,   243,    54,    63,   475,   246,    64,   374,   238,
      60,   375,   547,   451,    47,   238,   452,   441,   114,   238,
     120,   268,   268,   268,   268,   268,   268,   268,   268,   104,
     268,   268,   268,   268,   268,   268,   268,   268,   268,   268,
     268,   434,   451,   240,   494,   453,   358,   123,   238,   128,
     499,   358,   501,   450,   238,   238,   238,   389,   129,   505,
     394,   154,   317,   573,   283,   284,   285,   192,   193,   194,
     195,   238,   196,   197,   334,   317,   238,   238,   198,   133,
     192,   193,   194,   195,  -136,   196,   197,   160,   238,   199,
     238,   198,   524,    79,    80,   161,   238,   418,    85,   238,
     238,   162,   199,     1,   533,   428,   430,   334,   334,   167,
     534,     2,     3,   268,   115,  -153,     4,   268,   178,   118,
     119,     5,   238,   200,   179,     6,     7,   545,   281,   282,
     503,   189,     8,    40,   286,   287,   200,   358,   564,     9,
      10,    11,    29,    12,   187,   597,   599,    13,   238,   244,
      14,   249,    40,   150,   175,    29,    40,   389,   254,   334,
     288,   289,   290,   457,   400,   401,   402,   203,   204,   625,
     358,   358,   238,   256,    40,   257,   592,   267,   238,   280,
     203,   204,   564,   359,   300,   334,   279,   331,   359,   298,
     268,   268,   405,   406,   407,   408,   470,   301,   296,   297,
     331,   299,   478,   479,   480,  -312,  -312,   371,   627,   157,
      15,   629,   238,   183,  -313,  -313,   398,   399,   238,   389,
     379,   380,   358,   409,   410,   383,   358,   670,   387,   557,
     388,   393,   644,   416,   358,   421,   240,   277,   457,   278,
     680,   682,   564,   422,    87,   238,   423,   512,   358,   424,
      88,   433,   693,   442,    89,   443,   444,   564,   449,   458,
     464,   104,   238,   465,   471,   468,    90,    91,   469,    92,
     527,   564,   490,   472,   359,   268,    94,   482,   483,   238,
      95,   564,   564,   484,   564,   155,   502,   508,   564,   451,
     516,   519,   564,   518,   564,   564,   539,   520,   521,   522,
     523,    29,   529,   531,   564,   540,   537,   359,   359,   542,
     546,   549,   548,   550,   552,   556,   614,   570,   576,   358,
     555,   334,   577,   334,   585,   586,   569,   588,  -196,   591,
     595,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,
    -366,  -366,   600,   613,   334,   358,   334,   601,   615,   616,
    -366,   621,   623,   358,   626,   632,   630,   643,   647,   359,
     602,   649,    47,   359,   658,   671,   612,   672,   678,   684,
     683,   359,   358,   689,   691,   702,   662,   358,   358,   648,
     674,   694,   711,   360,   358,   359,   358,   587,   360,   358,
     663,   675,   685,   633,   528,   358,   404,    41,    83,    62,
     171,   358,   188,   255,    81,   686,   253,   358,   169,   358,
     646,   135,   605,   606,   611,   696,   697,   412,   699,   525,
     358,   358,   703,   358,   386,   413,   706,   661,   708,   709,
     526,   411,   414,   551,   415,   358,   417,     0,   715,     1,
     358,     0,   358,   358,     0,     0,     0,     0,     3,   358,
       0,     0,     4,     0,     0,     0,   359,     5,   358,   358,
       0,     0,     7,     0,   358,     0,     0,     0,     8,     0,
       0,     0,   358,   358,   360,     9,    43,    11,   358,    44,
       0,     0,   359,    13,   358,     0,    14,     0,   358,   358,
     359,   358,     0,     0,     0,   358,     0,     0,     0,   358,
       0,   358,   358,     0,     0,     0,     0,   360,   360,   359,
       0,   358,     0,     0,   359,   359,     0,     0,     0,     0,
     361,   359,     0,   359,     0,   361,   359,     0,     0,     0,
       0,     0,   359,     0,     0,     0,     0,     0,   359,     0,
       0,     0,     0,     0,   359,     0,   359,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   359,   359,   360,
     359,     0,     0,   360,     0,     0,     0,     0,     0,     0,
       0,   360,   359,   377,     0,   278,     0,   359,     0,   359,
     359,     0,     0,     0,     0,   360,   359,     0,     0,     0,
       0,     0,     0,     0,     0,   359,   359,     0,     0,     0,
       0,   359,     0,     0,     0,   619,   620,     0,   622,   359,
     359,   361,     0,     0,     0,   359,     0,     0,     0,     0,
       0,   359,     0,     0,     0,   359,   359,     0,   359,     0,
       0,   639,   359,   641,   642,     0,   359,     0,   359,   359,
       0,     0,     0,     0,   361,   361,     0,     0,   359,     0,
       0,     0,     0,   657,     0,     0,   360,   362,     0,     0,
       0,     0,   362,     0,     0,     0,     0,  -366,  -366,  -366,
    -366,  -366,  -366,  -366,  -366,  -366,  -366,  -366,     0,   677,
       0,     0,   360,     0,     0,     0,  -366,     0,   687,   688,
     360,   690,     0,     0,     0,     0,   361,     0,    47,   698,
     361,   700,   701,     0,     0,   182,     0,     0,   361,   360,
       0,     0,   710,     0,   360,   360,     0,     0,     0,     0,
       0,   360,   361,   360,     0,     0,   360,    87,     0,     0,
       0,     0,   360,    88,     0,     0,     0,    89,   360,     0,
       0,     0,     0,     0,   360,     0,   360,     0,   362,    90,
      91,     0,    92,     0,     0,     0,     0,   360,   360,    94,
     360,     0,     0,    95,     0,   363,     0,     0,     0,     0,
     363,     0,   360,     0,     0,     0,     0,   360,     0,   360,
     360,   362,   362,     0,    29,     0,   360,     0,     0,     0,
       0,     0,     0,   361,     0,   360,   360,     0,     0,     0,
       0,   360,     0,     0,     0,     0,     0,     0,     0,   360,
     360,     0,     0,     0,     0,   360,     0,     0,     0,   361,
       0,   360,     0,     0,     0,   360,   360,   361,   360,     0,
       0,     0,   360,   362,     0,     0,   360,   362,   360,   360,
       0,     0,     0,     0,     0,   362,   361,     0,   360,     0,
       0,   361,   361,     0,     0,     0,   363,     0,   361,   362,
     361,     0,     0,   361,     1,     0,     0,     0,     0,   361,
       0,     0,     0,     3,     0,   361,     0,     4,     0,     0,
       0,   361,     5,   361,     0,     0,     6,     7,     0,   363,
     363,   364,     0,     8,   361,   361,   364,   361,     0,     0,
       9,    10,    11,     0,    12,     0,     0,     0,    13,   361,
       0,    14,     0,     0,   361,     0,   361,   361,     0,     0,
       0,     0,     0,   361,     0,     0,     0,     0,     0,     0,
     362,     0,   361,   361,     0,     0,     0,     0,   361,     0,
       0,   363,     0,     0,     0,   363,   361,   361,     0,     0,
       0,     0,   361,   363,     0,     0,   362,     0,   361,     0,
       0,     0,   361,   361,   362,   361,     0,   363,     0,   361,
       0,    15,     0,   361,     0,   361,   361,     0,     0,   252,
       0,     0,   364,   362,     0,   361,     0,     0,   362,   362,
       0,     0,     0,     0,     0,   362,     0,   362,     0,     0,
     362,    87,     0,     0,     0,     0,   362,    88,     0,     0,
       0,    89,   362,     0,     0,   364,   364,     0,   362,     0,
     362,     0,     0,    90,    91,     0,    92,     0,     0,     0,
       0,   362,   362,    94,   362,     0,     0,    95,   363,     0,
       0,     0,     0,     0,     0,     0,   362,     0,     0,     0,
       0,   362,     0,   362,   362,     0,     0,     0,    29,     0,
     362,     0,     0,     0,   363,     0,     0,   364,     0,   362,
     362,   364,   363,     0,     0,   362,     0,     0,     0,   364,
       0,     0,     0,   362,   362,     0,     0,     0,     0,   362,
       0,   363,     0,   364,     0,   362,   363,   363,     0,   362,
     362,     0,   362,   363,     0,   363,   362,     0,   363,     0,
     362,     0,   362,   362,   363,     0,     0,     0,     0,     0,
     363,     0,   362,     0,     0,     0,   363,     0,   363,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   363,
     363,     0,   363,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   363,     0,     0,     0,     0,   363,
       0,   363,   363,     0,   364,     0,     0,     0,   363,     0,
       0,     0,     0,     0,     0,     0,     0,   363,   363,     0,
       0,     0,     0,   363,     0,     0,     0,     0,     0,     0,
     364,   363,   363,     0,     0,     0,     0,   363,   364,     0,
       0,     0,     0,   363,     0,     0,     0,   363,   363,     0,
     363,     0,     0,     0,   363,     0,     0,   364,   363,     0,
     363,   363,   364,   364,     0,     0,     0,     0,     0,   364,
     363,   364,     0,     0,   364,     0,     0,     0,     0,     0,
     364,     0,     0,     0,     0,     0,   364,     0,     0,     0,
       0,   190,   364,     0,   364,     0,   192,   193,   194,   195,
       0,   196,   197,     0,     0,   364,   364,   198,   364,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   199,     0,
     364,     0,     0,     0,     0,   364,     0,   364,   364,     0,
       0,     0,     0,     0,   364,   269,   269,   269,   269,   269,
     269,     0,     0,   364,   364,     0,     0,   481,     0,   364,
       0,     0,   200,     0,     0,   491,     0,   364,   364,     0,
       0,     0,     0,   364,     0,     0,     0,     0,     0,   364,
       0,    29,     0,   364,   364,     0,   364,     0,     0,     0,
     364,     0,     0,     0,   364,     0,   364,   364,   270,   270,
     270,   270,   270,   270,     0,     0,   364,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   205,   206,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   269,   269,   269,
     269,   269,   269,   269,   269,     0,   269,   269,   269,   269,
     269,   269,   269,   269,   269,   269,   269,     0,     0,     0,
     317,   596,     0,     0,     0,   192,   193,   194,   195,     0,
     196,   197,     0,     0,     0,     0,   198,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   562,   199,     0,     0,
     270,   270,   270,   270,   270,   270,   270,   270,     0,   270,
     270,   270,   270,   270,   270,   270,   270,   270,   270,   270,
       0,     0,   317,   593,     0,     0,     0,   192,   193,   194,
     195,   200,   196,   197,     0,     0,     0,     0,   198,   269,
     491,     0,     0,   269,     0,    87,   618,     0,     0,   199,
      29,    88,     0,     0,     0,    89,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    90,    91,     0,
      92,   637,   638,     0,   640,   203,   204,    94,     0,     0,
       0,    95,     0,   200,     0,     0,   650,     0,     0,     0,
       0,   653,   270,   655,   656,   331,   270,     0,     0,     0,
     562,     0,    29,     0,     0,     0,     0,     0,     0,   668,
       0,     0,     0,     0,     0,   593,   269,   269,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   203,   204,   618,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   637,
     638,     0,   640,     0,     0,     0,   650,   331,     0,     0,
     653,     0,   655,   656,     0,     0,     0,     0,     0,     0,
       0,     0,   668,     0,     0,     0,     0,     0,     0,   270,
     270,   317,     0,   167,   607,     0,   192,   193,   194,   195,
       0,   196,   197,     0,     0,   318,   319,   198,   320,     0,
     579,   321,     0,   322,    87,   323,     0,     0,   199,   324,
      88,   269,     0,   325,    89,     0,     0,     0,     0,   580,
       0,     0,   326,     0,     0,     0,    90,    91,   327,    92,
       0,     0,     0,     0,     0,     0,    94,     0,     0,     0,
      95,     0,   200,   328,     0,     0,     0,     0,     0,     0,
       0,     0,   317,     0,   167,   628,     0,   192,   193,   194,
     195,   329,   196,   197,   270,     0,   318,   319,   198,   320,
       0,   579,   321,     0,   322,    87,   323,     0,     0,   199,
     324,    88,     0,     0,   325,    89,   203,   204,     0,     0,
     580,     0,     0,   326,     0,     0,     0,    90,    91,   327,
      92,   330,     0,     0,     0,     0,   331,    94,     0,     0,
       0,    95,     0,   200,   328,     0,     0,     0,     0,   317,
       0,   167,   440,     0,   192,   193,   194,   195,     0,   196,
     197,     0,   329,   318,   319,   198,   320,     0,     0,   321,
       0,   322,    87,   323,     0,     0,   199,   324,    88,     0,
       0,   325,    89,     0,     0,     0,     0,   203,   204,     0,
     326,     0,     0,     0,    90,    91,   327,    92,     0,     0,
       0,     0,   330,     0,    94,     0,     0,   331,    95,     0,
     200,   328,     0,     0,     0,     0,   317,     0,   167,   446,
       0,   192,   193,   194,   195,     0,   196,   197,     0,   329,
     318,   319,   198,   320,     0,     0,   321,     0,   322,    87,
     323,     0,     0,   199,   324,    88,     0,     0,   325,    89,
       0,     0,     0,     0,   203,   204,     0,   326,     0,     0,
       0,    90,    91,   327,    92,     0,     0,     0,     0,   330,
       0,    94,     0,     0,   331,    95,     0,   200,   328,     0,
       0,     0,     0,   317,     0,   167,   448,     0,   192,   193,
     194,   195,     0,   196,   197,     0,   329,   318,   319,   198,
     320,     0,     0,   321,     0,   322,    87,   323,     0,     0,
     199,   324,    88,     0,     0,   325,    89,     0,     0,     0,
       0,   203,   204,     0,   326,     0,     0,     0,    90,    91,
     327,    92,     0,     0,     0,     0,   330,     0,    94,     0,
       0,   331,    95,     0,   200,   328,     0,     0,     0,     0,
     317,     0,   167,   500,     0,   192,   193,   194,   195,     0,
     196,   197,     0,   329,   318,   319,   198,   320,     0,     0,
     321,     0,   322,    87,   323,     0,     0,   199,   324,    88,
       0,     0,   325,    89,     0,     0,     0,     0,   203,   204,
       0,   326,     0,     0,     0,    90,    91,   327,    92,     0,
       0,     0,     0,   330,     0,    94,     0,     0,   331,    95,
       0,   200,   328,     0,     0,     0,     0,   317,     0,   167,
       0,     0,   192,   193,   194,   195,     0,   196,   197,     0,
     329,   318,   319,   198,   320,     0,     0,   321,     0,   322,
      87,   323,     0,     0,   199,   324,    88,     0,     0,   325,
      89,     0,     0,     0,     0,   203,   204,     0,   326,     0,
       0,     0,    90,    91,   327,    92,     0,     0,     0,     0,
     330,     0,    94,     0,     0,   331,    95,     0,   200,   328,
       0,     0,     0,     0,   317,     0,   167,     0,     0,   192,
     193,   194,   195,     0,   196,   197,     0,   329,   318,   319,
     198,   320,     0,     0,   321,     0,   322,    87,   323,     0,
       0,   367,   324,    88,     0,     0,   325,    89,     0,     0,
       0,     0,   203,   204,     0,   326,     0,     0,     0,    90,
      91,   327,    92,     0,     0,     0,     0,   330,     0,    94,
       0,     0,   331,    95,     0,   368,   328,     0,     0,     0,
       0,   317,     0,   167,     0,     0,   192,   193,   194,   195,
       0,   196,   197,     0,   329,   318,   319,   198,   320,     0,
       0,   321,     0,   322,     0,   323,     0,     0,   199,   324,
       0,     0,     0,   325,     0,     0,     0,     0,     0,   203,
     204,     0,   326,     0,     0,     0,     0,     0,   327,     0,
     317,     0,   167,     0,   330,   192,   193,   194,   195,   331,
     196,   197,   200,   328,   318,   558,   198,   320,     0,     0,
     559,     0,   322,     0,   323,     0,     0,   199,   324,     0,
       0,   329,   325,     0,     0,     0,     0,     0,   317,   598,
       0,   326,     0,   192,   193,   194,   195,   327,   196,   197,
       0,     0,     0,     0,   198,     0,   203,   204,     0,     0,
       0,   200,   560,     0,     0,   199,     0,   317,   624,     0,
       0,   330,   192,   193,   194,   195,   331,   196,   197,     0,
     561,   317,   669,   198,     0,     0,   192,   193,   194,   195,
       0,   196,   197,     0,   199,     0,     0,   198,     0,   200,
       0,     0,     0,     0,     0,   203,   204,     0,   199,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    29,     0,
     330,     0,     0,     0,     0,   331,     0,     0,   200,   317,
     679,     0,     0,     0,   192,   193,   194,   195,     0,   196,
     197,     0,   200,   203,   204,   198,     0,    29,     0,     0,
       0,     0,     0,     0,     0,     0,   199,     0,     0,     0,
       0,    29,     0,   331,     0,     0,     0,     0,     0,   317,
     681,     0,   203,   204,   192,   193,   194,   195,     0,   196,
     197,     0,     0,     0,     0,   198,   203,   204,     0,     0,
     200,     0,   331,     0,     0,     0,   199,   317,   692,     0,
       0,     0,   192,   193,   194,   195,   331,   196,   197,    29,
     190,     0,     0,   198,     0,   192,   193,   194,   195,     0,
     196,   197,     0,     0,   199,     0,   198,     0,     0,     0,
     200,     0,     0,     0,   203,   204,     0,   199,  -367,  -367,
    -367,  -367,  -367,  -367,  -367,  -367,  -367,  -367,  -367,    29,
       0,     0,     0,     0,   331,   449,   190,  -367,   200,     0,
       0,   192,   193,   194,   195,     0,   196,   197,     0,     0,
       0,   200,   198,     0,   203,   204,     0,    29,     0,     0,
       0,     0,     0,   199,     0,     0,     0,     0,     0,     0,
      29,   201,   202,     0,   331,     0,     0,     0,     0,     0,
       0,     0,   203,   204,     0,     0,     0,     0,     0,     0,
       0,     0,   162,   190,     0,   203,   204,   200,   192,   193,
     194,   195,   331,   196,   197,   205,   206,     0,     0,   198,
     429,     0,     0,     0,     0,     0,    29,   201,   202,     0,
     199,  -368,  -368,  -368,  -368,  -368,  -368,  -368,  -368,  -368,
    -368,  -368,     0,     0,     0,     0,     0,     0,     0,     0,
    -368,   203,   204,     0,     0,     0,     0,     0,     0,     0,
       0,   205,   206,     0,   200,   190,     0,     0,     0,     0,
     192,   193,   194,   195,     0,   196,   197,     0,     0,     0,
       0,   198,     0,    29,   201,   202,     0,     0,    87,     0,
       0,     0,   199,     0,    88,     0,   190,   390,    89,     0,
       0,   192,   193,   194,   195,     0,   196,   197,   203,   204,
      90,    91,   198,    92,     0,     0,     0,     0,   205,   206,
      94,     0,     0,   199,    95,   190,   200,   191,   506,     0,
     192,   193,   194,   195,     0,   196,   197,     0,     0,     0,
       0,   198,     0,     0,     0,    29,   201,   202,     0,     0,
       0,     0,   199,     0,     0,     0,   190,   200,   191,     0,
       0,   192,   193,   194,   195,     0,   196,   197,     0,     0,
     203,   204,   198,     0,     0,     0,    29,   201,   202,     0,
     205,   206,     0,   199,     0,     0,   200,   190,   462,     0,
       0,     0,   192,   193,   194,   195,     0,   196,   197,     0,
       0,   203,   204,   198,     0,    29,   201,   202,     0,     0,
       0,   205,   206,     0,   199,     0,     0,   200,   190,   495,
       0,     0,     0,   192,   193,   194,   195,     0,   196,   197,
     203,   204,     0,     0,   198,     0,    29,   201,   202,     0,
     205,   206,     0,     0,     0,   199,     0,     0,   200,   190,
     497,     0,     0,     0,   192,   193,   194,   195,     0,   196,
     197,   203,   204,     0,     0,   198,     0,    29,   201,   202,
       0,   205,   206,     0,     0,     0,   199,     0,     0,   200,
     190,   510,     0,     0,     0,   192,   193,   194,   195,     0,
     196,   197,   203,   204,     0,     0,   198,     0,    29,   201,
     202,     0,   205,   206,     0,     0,     0,   199,     0,     0,
     200,   190,   513,     0,     0,     0,   192,   193,   194,   195,
       0,   196,   197,   203,   204,     0,     0,   198,     0,    29,
     201,   202,     0,   205,   206,     0,     0,     0,   199,     0,
     190,   200,     0,     0,     0,   192,   193,   194,   195,     0,
     196,   197,     0,     0,   203,   204,   198,     0,     0,     0,
      29,   201,   202,     0,   205,   206,     0,   199,     0,     0,
       0,     1,   200,     0,     0,     0,     0,     0,     0,     0,
       3,     0,     0,     0,     4,   203,   204,     0,     0,     5,
       0,    29,   201,   202,     7,   205,   206,     0,     0,     0,
       8,   200,     0,     0,     0,     0,     0,     9,    10,    11,
       0,    12,     0,     0,     0,    13,   203,   204,    14,     0,
      29,   201,   202,     0,     0,     0,   205,   206,     0,     0,
       0,   651,   652,     0,   654,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   203,   204,   665,     0,   666,
     667,     0,     0,     0,     0,   205,   206,     0,     0,     0,
       0,     0,   676,   304,   305,   306,   307,   308,   309,   310,
     311,   312,   313,   314,     0,     0,     0,     0,    15,     0,
     695,     0,   315,     0,     0,   134,     0,     0,     0,     0,
     704,   705,     0,   707,     0,     1,     0,     0,     0,     0,
     712,     0,   713,   714,     3,    87,     0,     0,     4,   716,
       0,    88,     0,     5,     0,    89,     0,     0,     7,     0,
       0,     0,     0,     0,     8,   170,     0,    90,    91,     0,
      92,     9,     0,    11,    93,     1,     0,    94,     0,    13,
       0,    95,    14,     0,     3,    87,     0,     0,     4,     0,
       0,    88,     0,     5,     0,    89,     0,     0,     7,     0,
       0,     0,    29,     0,     8,     0,     0,    90,    91,     0,
      92,     9,     0,   136,    93,     1,     0,    94,     0,    13,
       0,    95,    14,     0,     3,    87,     0,     0,     4,     0,
       0,    88,     0,     5,     0,    89,     0,     0,     7,     0,
       0,     0,    29,     0,     8,     0,     0,    90,    91,     0,
      92,     9,     0,    11,    93,     1,     0,    94,     0,    13,
       0,    95,    14,     0,     3,    87,     0,     0,     4,     0,
       0,    88,     0,     5,     0,    89,     0,     0,     7,     0,
       0,     0,    29,     0,     8,     0,     0,    90,    91,     0,
      92,     9,     0,    11,   131,     1,     0,    94,     0,    13,
       0,    95,    14,     0,     3,    87,     0,     0,     4,     0,
       0,    88,     0,     5,     0,    89,     0,     0,     7,     0,
       0,     0,    29,     0,     8,     0,     0,    90,    91,     0,
      92,     9,     0,   136,    93,     0,     0,    94,     0,    13,
       0,    95,    14,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    29
};

static const yytype_int16 yycheck[] =
{
       2,    54,   136,   421,     6,   336,   257,    51,     4,   421,
     144,    55,    56,   132,   421,   331,    66,     8,   263,     4,
     259,   476,   245,   190,   379,   152,    70,   250,     4,     7,
       6,   198,    66,     7,   170,     8,   387,     6,    86,   370,
       8,     4,     0,     6,   169,     7,    86,   125,   126,    51,
     158,   176,     9,    55,    56,   105,     4,     7,   108,     8,
      55,     7,    86,   113,    66,     7,     7,     7,    70,     7,
     114,   198,    25,     9,   108,    70,   113,    50,   126,   113,
       9,    25,   190,   539,   540,     8,   126,    36,   138,   139,
      96,    44,    57,   444,   445,    43,    25,    62,   453,   555,
     518,    50,   139,   105,   154,   139,   108,   126,   152,    87,
     129,   113,   114,   464,   167,    44,   447,   468,    83,   114,
      43,   246,   175,    86,   291,   131,   132,   254,   178,   384,
     585,   386,   117,   129,   552,   126,   138,   139,   191,   201,
     202,   203,   204,   205,   206,   384,   369,   386,   111,   112,
     152,   125,   154,   129,   198,   263,   611,   125,   576,   577,
     129,   105,    86,   125,   126,    46,   129,   585,   125,   277,
     278,    86,   280,   585,   630,   125,   178,   493,   585,   125,
     126,    86,   600,   125,   125,   125,    52,   125,   190,   125,
     646,   647,     8,   327,   138,    61,   198,    86,   158,   201,
     202,   203,   204,   205,   206,   661,   126,   257,   316,   317,
     254,   456,   110,    18,   333,    81,   113,   325,   326,   113,
      36,   283,   284,   285,   127,   123,    11,    12,    13,    14,
     190,    16,    17,   583,   115,   116,    41,     9,   119,   120,
     658,   138,   139,   245,   147,   139,    49,    18,   250,    20,
     125,   126,   254,   671,   672,   257,   606,    60,   126,     9,
     163,   129,   165,     8,    86,   683,   169,    89,     4,   377,
      41,     7,   523,     4,   129,   383,     7,   608,   125,   387,
      86,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,    86,     4,   263,   440,     7,   245,    86,   416,     4,
     446,   250,   448,   375,   422,   423,   424,   277,     4,   455,
     280,     6,     6,     7,    89,    90,    91,    11,    12,    13,
      14,   439,    16,    17,   336,     6,   444,   445,    22,   126,
      11,    12,    13,    14,     6,    16,    17,     5,   456,    33,
     458,    22,   486,    57,    58,     5,   464,   317,    62,   467,
     468,     5,    33,    19,   500,   325,   326,   369,   370,     8,
     506,    27,    28,   375,    78,     6,    32,   379,     6,    83,
      84,    37,   490,    67,     5,    41,    42,   521,   111,   112,
     452,     5,    48,    19,    87,    88,    67,   336,   544,    55,
      56,    57,    86,    59,    86,   576,   577,    63,   516,     9,
      66,     9,    38,   117,     8,    86,    42,   377,   125,   421,
      95,    96,    97,   383,   288,   289,   290,   111,   112,   600,
     369,   370,   540,     7,    60,   125,   570,   129,   546,     4,
     111,   112,   588,   245,    93,   447,   129,   131,   250,   130,
     452,   453,   292,   293,   294,   295,   416,   109,   113,   114,
     131,    94,   422,   423,   424,   111,   112,     7,   604,     4,
     126,   607,   580,   523,   111,   112,   286,   287,   586,   439,
       7,     9,   421,   296,   297,     4,   425,   658,     6,   542,
      86,    86,   628,   123,   433,     6,   456,     4,   458,     6,
     671,   672,   648,     6,    29,   613,     6,   467,   447,     6,
      35,   128,   683,   126,    39,   126,     6,   663,     5,     4,
       6,   523,   630,     5,     7,     6,    51,    52,     5,    54,
     490,   677,     6,   126,   336,   537,    61,   126,   126,   647,
      65,   687,   688,   126,   690,   125,     5,     5,   694,     4,
     126,     7,   698,   125,   700,   701,   516,     7,     7,    68,
       6,    86,   126,   126,   710,   126,   128,   369,   370,     8,
       6,   126,     7,   126,   126,     9,   588,     7,   126,   518,
     540,   583,   126,   585,     6,     6,   546,   128,    40,     7,
       7,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   126,     6,   606,   544,   608,   128,    40,   126,
     117,     7,     7,   552,   128,     7,   126,     7,   126,   421,
     580,     7,   129,   425,   126,   126,   586,   126,     7,    40,
     126,   433,   571,     7,     7,     7,   648,   576,   577,   632,
     662,   684,   703,   245,   583,   447,   585,   560,   250,   588,
     649,   663,   675,   613,   493,   594,   291,    20,    62,    44,
     139,   600,   155,   183,    61,   677,   178,   606,   138,   608,
     630,   108,   581,   581,   585,   687,   688,   299,   690,   487,
     619,   620,   694,   622,   265,   300,   698,   647,   700,   701,
     487,   298,   301,   537,   302,   634,   316,    -1,   710,    19,
     639,    -1,   641,   642,    -1,    -1,    -1,    -1,    28,   648,
      -1,    -1,    32,    -1,    -1,    -1,   518,    37,   657,   658,
      -1,    -1,    42,    -1,   663,    -1,    -1,    -1,    48,    -1,
      -1,    -1,   671,   672,   336,    55,    56,    57,   677,    59,
      -1,    -1,   544,    63,   683,    -1,    66,    -1,   687,   688,
     552,   690,    -1,    -1,    -1,   694,    -1,    -1,    -1,   698,
      -1,   700,   701,    -1,    -1,    -1,    -1,   369,   370,   571,
      -1,   710,    -1,    -1,   576,   577,    -1,    -1,    -1,    -1,
     245,   583,    -1,   585,    -1,   250,   588,    -1,    -1,    -1,
      -1,    -1,   594,    -1,    -1,    -1,    -1,    -1,   600,    -1,
      -1,    -1,    -1,    -1,   606,    -1,   608,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   619,   620,   421,
     622,    -1,    -1,   425,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   433,   634,     4,    -1,     6,    -1,   639,    -1,   641,
     642,    -1,    -1,    -1,    -1,   447,   648,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   657,   658,    -1,    -1,    -1,
      -1,   663,    -1,    -1,    -1,   595,   596,    -1,   598,   671,
     672,   336,    -1,    -1,    -1,   677,    -1,    -1,    -1,    -1,
      -1,   683,    -1,    -1,    -1,   687,   688,    -1,   690,    -1,
      -1,   621,   694,   623,   624,    -1,   698,    -1,   700,   701,
      -1,    -1,    -1,    -1,   369,   370,    -1,    -1,   710,    -1,
      -1,    -1,    -1,   643,    -1,    -1,   518,   245,    -1,    -1,
      -1,    -1,   250,    -1,    -1,    -1,    -1,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,    -1,   669,
      -1,    -1,   544,    -1,    -1,    -1,   117,    -1,   678,   679,
     552,   681,    -1,    -1,    -1,    -1,   421,    -1,   129,   689,
     425,   691,   692,    -1,    -1,     7,    -1,    -1,   433,   571,
      -1,    -1,   702,    -1,   576,   577,    -1,    -1,    -1,    -1,
      -1,   583,   447,   585,    -1,    -1,   588,    29,    -1,    -1,
      -1,    -1,   594,    35,    -1,    -1,    -1,    39,   600,    -1,
      -1,    -1,    -1,    -1,   606,    -1,   608,    -1,   336,    51,
      52,    -1,    54,    -1,    -1,    -1,    -1,   619,   620,    61,
     622,    -1,    -1,    65,    -1,   245,    -1,    -1,    -1,    -1,
     250,    -1,   634,    -1,    -1,    -1,    -1,   639,    -1,   641,
     642,   369,   370,    -1,    86,    -1,   648,    -1,    -1,    -1,
      -1,    -1,    -1,   518,    -1,   657,   658,    -1,    -1,    -1,
      -1,   663,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   671,
     672,    -1,    -1,    -1,    -1,   677,    -1,    -1,    -1,   544,
      -1,   683,    -1,    -1,    -1,   687,   688,   552,   690,    -1,
      -1,    -1,   694,   421,    -1,    -1,   698,   425,   700,   701,
      -1,    -1,    -1,    -1,    -1,   433,   571,    -1,   710,    -1,
      -1,   576,   577,    -1,    -1,    -1,   336,    -1,   583,   447,
     585,    -1,    -1,   588,    19,    -1,    -1,    -1,    -1,   594,
      -1,    -1,    -1,    28,    -1,   600,    -1,    32,    -1,    -1,
      -1,   606,    37,   608,    -1,    -1,    41,    42,    -1,   369,
     370,   245,    -1,    48,   619,   620,   250,   622,    -1,    -1,
      55,    56,    57,    -1,    59,    -1,    -1,    -1,    63,   634,
      -1,    66,    -1,    -1,   639,    -1,   641,   642,    -1,    -1,
      -1,    -1,    -1,   648,    -1,    -1,    -1,    -1,    -1,    -1,
     518,    -1,   657,   658,    -1,    -1,    -1,    -1,   663,    -1,
      -1,   421,    -1,    -1,    -1,   425,   671,   672,    -1,    -1,
      -1,    -1,   677,   433,    -1,    -1,   544,    -1,   683,    -1,
      -1,    -1,   687,   688,   552,   690,    -1,   447,    -1,   694,
      -1,   126,    -1,   698,    -1,   700,   701,    -1,    -1,     7,
      -1,    -1,   336,   571,    -1,   710,    -1,    -1,   576,   577,
      -1,    -1,    -1,    -1,    -1,   583,    -1,   585,    -1,    -1,
     588,    29,    -1,    -1,    -1,    -1,   594,    35,    -1,    -1,
      -1,    39,   600,    -1,    -1,   369,   370,    -1,   606,    -1,
     608,    -1,    -1,    51,    52,    -1,    54,    -1,    -1,    -1,
      -1,   619,   620,    61,   622,    -1,    -1,    65,   518,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   634,    -1,    -1,    -1,
      -1,   639,    -1,   641,   642,    -1,    -1,    -1,    86,    -1,
     648,    -1,    -1,    -1,   544,    -1,    -1,   421,    -1,   657,
     658,   425,   552,    -1,    -1,   663,    -1,    -1,    -1,   433,
      -1,    -1,    -1,   671,   672,    -1,    -1,    -1,    -1,   677,
      -1,   571,    -1,   447,    -1,   683,   576,   577,    -1,   687,
     688,    -1,   690,   583,    -1,   585,   694,    -1,   588,    -1,
     698,    -1,   700,   701,   594,    -1,    -1,    -1,    -1,    -1,
     600,    -1,   710,    -1,    -1,    -1,   606,    -1,   608,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   619,
     620,    -1,   622,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   634,    -1,    -1,    -1,    -1,   639,
      -1,   641,   642,    -1,   518,    -1,    -1,    -1,   648,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   657,   658,    -1,
      -1,    -1,    -1,   663,    -1,    -1,    -1,    -1,    -1,    -1,
     544,   671,   672,    -1,    -1,    -1,    -1,   677,   552,    -1,
      -1,    -1,    -1,   683,    -1,    -1,    -1,   687,   688,    -1,
     690,    -1,    -1,    -1,   694,    -1,    -1,   571,   698,    -1,
     700,   701,   576,   577,    -1,    -1,    -1,    -1,    -1,   583,
     710,   585,    -1,    -1,   588,    -1,    -1,    -1,    -1,    -1,
     594,    -1,    -1,    -1,    -1,    -1,   600,    -1,    -1,    -1,
      -1,     6,   606,    -1,   608,    -1,    11,    12,    13,    14,
      -1,    16,    17,    -1,    -1,   619,   620,    22,   622,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,
     634,    -1,    -1,    -1,    -1,   639,    -1,   641,   642,    -1,
      -1,    -1,    -1,    -1,   648,   201,   202,   203,   204,   205,
     206,    -1,    -1,   657,   658,    -1,    -1,   425,    -1,   663,
      -1,    -1,    67,    -1,    -1,   433,    -1,   671,   672,    -1,
      -1,    -1,    -1,   677,    -1,    -1,    -1,    -1,    -1,   683,
      -1,    86,    -1,   687,   688,    -1,   690,    -1,    -1,    -1,
     694,    -1,    -1,    -1,   698,    -1,   700,   701,   201,   202,
     203,   204,   205,   206,    -1,    -1,   710,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   121,   122,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   283,   284,   285,
     286,   287,   288,   289,   290,    -1,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,    -1,    -1,    -1,
       6,     7,    -1,    -1,    -1,    11,    12,    13,    14,    -1,
      16,    17,    -1,    -1,    -1,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   544,    33,    -1,    -1,
     283,   284,   285,   286,   287,   288,   289,   290,    -1,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,   302,
      -1,    -1,     6,   571,    -1,    -1,    -1,    11,    12,    13,
      14,    67,    16,    17,    -1,    -1,    -1,    -1,    22,   375,
     588,    -1,    -1,   379,    -1,    29,   594,    -1,    -1,    33,
      86,    35,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    -1,
      54,   619,   620,    -1,   622,   111,   112,    61,    -1,    -1,
      -1,    65,    -1,    67,    -1,    -1,   634,    -1,    -1,    -1,
      -1,   639,   375,   641,   642,   131,   379,    -1,    -1,    -1,
     648,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,   657,
      -1,    -1,    -1,    -1,    -1,   663,   452,   453,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   677,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   687,
     688,    -1,   690,    -1,    -1,    -1,   694,   131,    -1,    -1,
     698,    -1,   700,   701,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   710,    -1,    -1,    -1,    -1,    -1,    -1,   452,
     453,     6,    -1,     8,     9,    -1,    11,    12,    13,    14,
      -1,    16,    17,    -1,    -1,    20,    21,    22,    23,    -1,
      25,    26,    -1,    28,    29,    30,    -1,    -1,    33,    34,
      35,   537,    -1,    38,    39,    -1,    -1,    -1,    -1,    44,
      -1,    -1,    47,    -1,    -1,    -1,    51,    52,    53,    54,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      65,    -1,    67,    68,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     6,    -1,     8,     9,    -1,    11,    12,    13,
      14,    86,    16,    17,   537,    -1,    20,    21,    22,    23,
      -1,    25,    26,    -1,    28,    29,    30,    -1,    -1,    33,
      34,    35,    -1,    -1,    38,    39,   111,   112,    -1,    -1,
      44,    -1,    -1,    47,    -1,    -1,    -1,    51,    52,    53,
      54,   126,    -1,    -1,    -1,    -1,   131,    61,    -1,    -1,
      -1,    65,    -1,    67,    68,    -1,    -1,    -1,    -1,     6,
      -1,     8,     9,    -1,    11,    12,    13,    14,    -1,    16,
      17,    -1,    86,    20,    21,    22,    23,    -1,    -1,    26,
      -1,    28,    29,    30,    -1,    -1,    33,    34,    35,    -1,
      -1,    38,    39,    -1,    -1,    -1,    -1,   111,   112,    -1,
      47,    -1,    -1,    -1,    51,    52,    53,    54,    -1,    -1,
      -1,    -1,   126,    -1,    61,    -1,    -1,   131,    65,    -1,
      67,    68,    -1,    -1,    -1,    -1,     6,    -1,     8,     9,
      -1,    11,    12,    13,    14,    -1,    16,    17,    -1,    86,
      20,    21,    22,    23,    -1,    -1,    26,    -1,    28,    29,
      30,    -1,    -1,    33,    34,    35,    -1,    -1,    38,    39,
      -1,    -1,    -1,    -1,   111,   112,    -1,    47,    -1,    -1,
      -1,    51,    52,    53,    54,    -1,    -1,    -1,    -1,   126,
      -1,    61,    -1,    -1,   131,    65,    -1,    67,    68,    -1,
      -1,    -1,    -1,     6,    -1,     8,     9,    -1,    11,    12,
      13,    14,    -1,    16,    17,    -1,    86,    20,    21,    22,
      23,    -1,    -1,    26,    -1,    28,    29,    30,    -1,    -1,
      33,    34,    35,    -1,    -1,    38,    39,    -1,    -1,    -1,
      -1,   111,   112,    -1,    47,    -1,    -1,    -1,    51,    52,
      53,    54,    -1,    -1,    -1,    -1,   126,    -1,    61,    -1,
      -1,   131,    65,    -1,    67,    68,    -1,    -1,    -1,    -1,
       6,    -1,     8,     9,    -1,    11,    12,    13,    14,    -1,
      16,    17,    -1,    86,    20,    21,    22,    23,    -1,    -1,
      26,    -1,    28,    29,    30,    -1,    -1,    33,    34,    35,
      -1,    -1,    38,    39,    -1,    -1,    -1,    -1,   111,   112,
      -1,    47,    -1,    -1,    -1,    51,    52,    53,    54,    -1,
      -1,    -1,    -1,   126,    -1,    61,    -1,    -1,   131,    65,
      -1,    67,    68,    -1,    -1,    -1,    -1,     6,    -1,     8,
      -1,    -1,    11,    12,    13,    14,    -1,    16,    17,    -1,
      86,    20,    21,    22,    23,    -1,    -1,    26,    -1,    28,
      29,    30,    -1,    -1,    33,    34,    35,    -1,    -1,    38,
      39,    -1,    -1,    -1,    -1,   111,   112,    -1,    47,    -1,
      -1,    -1,    51,    52,    53,    54,    -1,    -1,    -1,    -1,
     126,    -1,    61,    -1,    -1,   131,    65,    -1,    67,    68,
      -1,    -1,    -1,    -1,     6,    -1,     8,    -1,    -1,    11,
      12,    13,    14,    -1,    16,    17,    -1,    86,    20,    21,
      22,    23,    -1,    -1,    26,    -1,    28,    29,    30,    -1,
      -1,    33,    34,    35,    -1,    -1,    38,    39,    -1,    -1,
      -1,    -1,   111,   112,    -1,    47,    -1,    -1,    -1,    51,
      52,    53,    54,    -1,    -1,    -1,    -1,   126,    -1,    61,
      -1,    -1,   131,    65,    -1,    67,    68,    -1,    -1,    -1,
      -1,     6,    -1,     8,    -1,    -1,    11,    12,    13,    14,
      -1,    16,    17,    -1,    86,    20,    21,    22,    23,    -1,
      -1,    26,    -1,    28,    -1,    30,    -1,    -1,    33,    34,
      -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,   111,
     112,    -1,    47,    -1,    -1,    -1,    -1,    -1,    53,    -1,
       6,    -1,     8,    -1,   126,    11,    12,    13,    14,   131,
      16,    17,    67,    68,    20,    21,    22,    23,    -1,    -1,
      26,    -1,    28,    -1,    30,    -1,    -1,    33,    34,    -1,
      -1,    86,    38,    -1,    -1,    -1,    -1,    -1,     6,     7,
      -1,    47,    -1,    11,    12,    13,    14,    53,    16,    17,
      -1,    -1,    -1,    -1,    22,    -1,   111,   112,    -1,    -1,
      -1,    67,    68,    -1,    -1,    33,    -1,     6,     7,    -1,
      -1,   126,    11,    12,    13,    14,   131,    16,    17,    -1,
      86,     6,     7,    22,    -1,    -1,    11,    12,    13,    14,
      -1,    16,    17,    -1,    33,    -1,    -1,    22,    -1,    67,
      -1,    -1,    -1,    -1,    -1,   111,   112,    -1,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,
     126,    -1,    -1,    -1,    -1,   131,    -1,    -1,    67,     6,
       7,    -1,    -1,    -1,    11,    12,    13,    14,    -1,    16,
      17,    -1,    67,   111,   112,    22,    -1,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,
      -1,    86,    -1,   131,    -1,    -1,    -1,    -1,    -1,     6,
       7,    -1,   111,   112,    11,    12,    13,    14,    -1,    16,
      17,    -1,    -1,    -1,    -1,    22,   111,   112,    -1,    -1,
      67,    -1,   131,    -1,    -1,    -1,    33,     6,     7,    -1,
      -1,    -1,    11,    12,    13,    14,   131,    16,    17,    86,
       6,    -1,    -1,    22,    -1,    11,    12,    13,    14,    -1,
      16,    17,    -1,    -1,    33,    -1,    22,    -1,    -1,    -1,
      67,    -1,    -1,    -1,   111,   112,    -1,    33,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,    86,
      -1,    -1,    -1,    -1,   131,     5,     6,   117,    67,    -1,
      -1,    11,    12,    13,    14,    -1,    16,    17,    -1,    -1,
      -1,    67,    22,    -1,   111,   112,    -1,    86,    -1,    -1,
      -1,    -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    87,    88,    -1,   131,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   111,   112,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     5,     6,    -1,   111,   112,    67,    11,    12,
      13,    14,   131,    16,    17,   121,   122,    -1,    -1,    22,
     126,    -1,    -1,    -1,    -1,    -1,    86,    87,    88,    -1,
      33,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     117,   111,   112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   121,   122,    -1,    67,     6,    -1,    -1,    -1,    -1,
      11,    12,    13,    14,    -1,    16,    17,    -1,    -1,    -1,
      -1,    22,    -1,    86,    87,    88,    -1,    -1,    29,    -1,
      -1,    -1,    33,    -1,    35,    -1,     6,     7,    39,    -1,
      -1,    11,    12,    13,    14,    -1,    16,    17,   111,   112,
      51,    52,    22,    54,    -1,    -1,    -1,    -1,   121,   122,
      61,    -1,    -1,    33,    65,     6,    67,     8,     9,    -1,
      11,    12,    13,    14,    -1,    16,    17,    -1,    -1,    -1,
      -1,    22,    -1,    -1,    -1,    86,    87,    88,    -1,    -1,
      -1,    -1,    33,    -1,    -1,    -1,     6,    67,     8,    -1,
      -1,    11,    12,    13,    14,    -1,    16,    17,    -1,    -1,
     111,   112,    22,    -1,    -1,    -1,    86,    87,    88,    -1,
     121,   122,    -1,    33,    -1,    -1,    67,     6,     7,    -1,
      -1,    -1,    11,    12,    13,    14,    -1,    16,    17,    -1,
      -1,   111,   112,    22,    -1,    86,    87,    88,    -1,    -1,
      -1,   121,   122,    -1,    33,    -1,    -1,    67,     6,     7,
      -1,    -1,    -1,    11,    12,    13,    14,    -1,    16,    17,
     111,   112,    -1,    -1,    22,    -1,    86,    87,    88,    -1,
     121,   122,    -1,    -1,    -1,    33,    -1,    -1,    67,     6,
       7,    -1,    -1,    -1,    11,    12,    13,    14,    -1,    16,
      17,   111,   112,    -1,    -1,    22,    -1,    86,    87,    88,
      -1,   121,   122,    -1,    -1,    -1,    33,    -1,    -1,    67,
       6,     7,    -1,    -1,    -1,    11,    12,    13,    14,    -1,
      16,    17,   111,   112,    -1,    -1,    22,    -1,    86,    87,
      88,    -1,   121,   122,    -1,    -1,    -1,    33,    -1,    -1,
      67,     6,     7,    -1,    -1,    -1,    11,    12,    13,    14,
      -1,    16,    17,   111,   112,    -1,    -1,    22,    -1,    86,
      87,    88,    -1,   121,   122,    -1,    -1,    -1,    33,    -1,
       6,    67,    -1,    -1,    -1,    11,    12,    13,    14,    -1,
      16,    17,    -1,    -1,   111,   112,    22,    -1,    -1,    -1,
      86,    87,    88,    -1,   121,   122,    -1,    33,    -1,    -1,
      -1,    19,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      28,    -1,    -1,    -1,    32,   111,   112,    -1,    -1,    37,
      -1,    86,    87,    88,    42,   121,   122,    -1,    -1,    -1,
      48,    67,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      -1,    59,    -1,    -1,    -1,    63,   111,   112,    66,    -1,
      86,    87,    88,    -1,    -1,    -1,   121,   122,    -1,    -1,
      -1,   637,   638,    -1,   640,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   111,   112,   653,    -1,   655,
     656,    -1,    -1,    -1,    -1,   121,   122,    -1,    -1,    -1,
      -1,    -1,   668,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,    -1,    -1,    -1,    -1,   126,    -1,
     686,    -1,   117,    -1,    -1,     9,    -1,    -1,    -1,    -1,
     696,   697,    -1,   699,    -1,    19,    -1,    -1,    -1,    -1,
     706,    -1,   708,   709,    28,    29,    -1,    -1,    32,   715,
      -1,    35,    -1,    37,    -1,    39,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    48,     9,    -1,    51,    52,    -1,
      54,    55,    -1,    57,    58,    19,    -1,    61,    -1,    63,
      -1,    65,    66,    -1,    28,    29,    -1,    -1,    32,    -1,
      -1,    35,    -1,    37,    -1,    39,    -1,    -1,    42,    -1,
      -1,    -1,    86,    -1,    48,    -1,    -1,    51,    52,    -1,
      54,    55,    -1,    57,    58,    19,    -1,    61,    -1,    63,
      -1,    65,    66,    -1,    28,    29,    -1,    -1,    32,    -1,
      -1,    35,    -1,    37,    -1,    39,    -1,    -1,    42,    -1,
      -1,    -1,    86,    -1,    48,    -1,    -1,    51,    52,    -1,
      54,    55,    -1,    57,    58,    19,    -1,    61,    -1,    63,
      -1,    65,    66,    -1,    28,    29,    -1,    -1,    32,    -1,
      -1,    35,    -1,    37,    -1,    39,    -1,    -1,    42,    -1,
      -1,    -1,    86,    -1,    48,    -1,    -1,    51,    52,    -1,
      54,    55,    -1,    57,    58,    19,    -1,    61,    -1,    63,
      -1,    65,    66,    -1,    28,    29,    -1,    -1,    32,    -1,
      -1,    35,    -1,    37,    -1,    39,    -1,    -1,    42,    -1,
      -1,    -1,    86,    -1,    48,    -1,    -1,    51,    52,    -1,
      54,    55,    -1,    57,    58,    -1,    -1,    61,    -1,    63,
      -1,    65,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    86
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,    19,    27,    28,    32,    37,    41,    42,    48,    55,
      56,    57,    59,    63,    66,   126,   133,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   181,   211,    86,
     167,   168,   169,   167,    86,    86,   180,     0,   172,   174,
     177,   171,   172,    56,    59,   179,   126,   129,   126,   129,
       8,    50,   212,   213,     8,    36,    50,   182,   183,   186,
     172,    86,   180,    86,    89,     9,   134,   163,   165,   167,
     125,   213,     9,   134,   165,   184,   163,   164,   183,   186,
     186,   212,   213,   182,   183,   186,   126,    29,    35,    39,
      51,    52,    54,    58,    61,    65,   157,   158,   159,   160,
     161,   162,   163,   166,   167,   178,   190,   196,   214,   215,
     216,   217,   165,   185,   125,   186,   213,   183,   186,   186,
      86,   197,   198,    86,   191,   192,   193,   197,     4,     4,
       4,    58,   157,   126,     9,   215,    57,   168,   178,   187,
     188,   189,   190,   195,   196,   205,   206,   207,   208,   165,
     186,     4,    43,   202,     6,   125,   126,     4,   117,   202,
       5,     5,     5,   197,   191,   197,   135,     8,   220,   207,
       9,   188,   126,   204,   220,     8,   202,   209,     6,     5,
     164,   203,     7,   157,   199,   200,   201,    86,   192,     5,
       6,     8,    11,    12,    13,    14,    16,    17,    22,    33,
      67,    87,    88,   111,   112,   121,   122,   156,   167,   194,
     218,   259,   260,   261,   263,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     293,   202,   126,   202,     9,   134,   202,   209,   135,     9,
     134,   209,     7,   199,   125,   193,     7,   125,   158,   167,
     293,     9,   125,   134,   158,   163,   164,   129,   167,   267,
     269,   273,   273,   273,   273,   273,   273,     4,     6,   129,
       4,   111,   112,    89,    90,    91,    87,    88,    95,    96,
      97,    46,   115,   116,   119,   120,   113,   114,   130,    94,
      93,   109,   110,   150,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   117,   292,     6,    20,    21,
      23,    26,    28,    30,    34,    38,    47,    53,    68,    86,
     126,   131,   153,   157,   167,   220,   221,   222,   223,   224,
     225,   227,   228,   229,   231,   232,   233,   234,   236,   242,
     244,   245,   250,   251,   252,   253,   254,   255,   261,   268,
     270,   271,   272,   274,   275,   290,   209,    33,    67,   210,
     221,     7,   164,   201,     4,     7,   266,     4,   266,     7,
       9,   194,   219,     4,   264,   265,   264,     6,    86,   293,
       7,   262,   293,    86,   293,   273,   273,   273,   278,   278,
     279,   279,   279,   158,   162,   280,   280,   280,   280,   281,
     281,   282,   283,   284,   285,   286,   123,   289,   293,    86,
     126,     6,     6,     6,     6,   144,    86,   126,   293,   126,
     293,   220,   141,   128,    86,   154,   155,   156,   191,     4,
       9,   222,   126,   126,     6,     6,     9,   221,     9,     5,
     273,     4,     7,     7,   276,     9,   125,   293,     4,   265,
     266,   266,     7,   262,     6,     5,     7,   125,     6,     5,
     293,     7,   126,   146,   224,   232,   247,   249,   293,   293,
     293,   225,   126,   126,   126,    49,    60,   256,   257,   258,
       6,   225,     7,    87,   135,     7,   262,     7,   262,   135,
       9,   135,     5,   273,   276,   135,     9,   194,     5,     7,
       7,   262,   293,     7,   262,   151,   126,   146,   125,     7,
       7,     7,    68,     6,   220,   257,   258,   293,   155,   126,
       7,   126,     7,   135,   135,     7,     7,   128,   147,   293,
     126,   232,     8,   237,   136,   220,     6,   201,     7,   126,
     126,   288,   126,   147,   147,   293,     9,   134,    21,    26,
      68,    86,   225,   226,   227,   230,   235,   243,   246,   293,
       7,   142,   152,     7,   248,   249,   126,   126,   147,    25,
      44,   238,   239,   240,   241,     6,     6,   141,   128,   137,
     138,     7,   220,   225,   148,     7,     7,   248,     7,   248,
     126,   128,   293,   294,     9,   239,   240,     9,   221,   241,
     146,   247,   293,     6,   226,    40,   126,   143,   225,   148,
     148,     7,   148,     7,     7,   248,   128,   135,     9,   135,
     126,   146,     7,   293,   139,   145,   149,   225,   225,   148,
     225,   148,   148,     7,   135,   147,   293,   126,   136,     7,
     225,   149,   149,   225,   149,   225,   225,   148,   126,   147,
     147,   293,   226,   142,   140,   149,   149,   149,   225,     7,
     248,   126,   126,   147,   138,   226,   149,   148,     7,     7,
     248,     7,   248,   126,    40,   143,   226,   148,   148,     7,
     148,     7,     7,   248,   139,   149,   226,   226,   148,   226,
     148,   148,     7,   226,   149,   149,   226,   149,   226,   226,
     148,   140,   149,   149,   149,   226,   149
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   154,   155,   155,   155,   156,   156,
     156,   156,   156,   156,   157,   157,   158,   158,   159,   159,
     160,   160,   160,   160,   160,   161,   161,   162,   162,   163,
     164,   165,   166,   166,   166,   167,   167,   168,   169,   170,
     170,   170,   170,   170,   170,   170,   170,   171,   171,   172,
     172,   173,   174,   174,   175,   176,   177,   177,   177,   178,
     178,   179,   179,   179,   179,   179,   179,   179,   179,   179,
     179,   180,   181,   181,   181,   181,   181,   181,   181,   181,
     182,   183,   184,   184,   185,   186,   186,   187,   187,   188,
     188,   188,   189,   189,   190,   190,   191,   191,   192,   192,
     193,   193,   194,   194,   195,   196,   196,   196,   196,   196,
     196,   196,   196,   197,   197,   197,   198,   199,   200,   200,
     201,   202,   203,   203,   204,   204,   205,   206,   206,   206,
     206,   207,   207,   208,   209,   209,   209,   209,   210,   210,
     210,   210,   211,   211,   211,   211,   212,   212,   213,   213,
     214,   214,   215,   215,   216,   217,   218,   218,   218,   218,
     219,   219,   220,   220,   221,   221,   222,   222,   223,   224,
     225,   225,   225,   225,   225,   225,   226,   226,   226,   226,
     226,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   228,   229,   230,   231,   232,   232,   232,   232,
     232,   232,   232,   232,   233,   234,   235,   236,   237,   237,
     237,   237,   238,   238,   239,   240,   240,   241,   241,   242,
     243,   244,   245,   245,   245,   245,   245,   245,   245,   245,
     246,   246,   246,   246,   246,   246,   246,   246,   247,   247,
     248,   249,   249,   250,   250,   251,   251,   252,   252,   253,
     254,   255,   255,   255,   256,   256,   257,   258,   259,   259,
     260,   260,   260,   260,   260,   260,   260,   261,   261,   262,
     262,   263,   263,   263,   263,   264,   264,   265,   266,   266,
     267,   267,   268,   268,   268,   268,   268,   268,   269,   269,
     270,   270,   270,   270,   271,   272,   273,   273,   273,   273,
     273,   274,   275,   276,   276,   276,   276,   277,   277,   277,
     277,   278,   278,   278,   278,   279,   279,   279,   280,   280,
     280,   280,   281,   281,   281,   281,   281,   281,   282,   282,
     282,   283,   283,   284,   284,   285,   285,   286,   286,   287,
     287,   288,   288,   289,   289,   290,   291,   291,   291,   292,
     292,   292,   292,   292,   292,   292,   292,   292,   292,   292,
     292,   293,   294
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     3,     1,     3,     1,     1,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     1,     1,     1,     3,     0,
       1,     2,     2,     3,     2,     1,     1,     1,     2,     1,
       2,     3,     1,     1,     3,     5,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     6,     5,     5,     4,     5,     4,     4,     3,
       2,     2,     1,     3,     0,     6,     2,     1,     2,     1,
       1,     1,     1,     1,     4,     3,     1,     3,     1,     3,
       1,     3,     1,     1,     2,     4,     3,     3,     2,     4,
       3,     3,     2,     4,     3,     3,     1,     1,     1,     3,
       2,     2,     1,     3,     1,     1,     2,     4,     3,     3,
       2,     4,     3,     1,     6,     5,     5,     2,     5,     4,
       5,     4,     5,     4,     4,     3,     2,     3,     5,     2,
       1,     2,     1,     1,     1,     2,     6,     5,     3,     2,
       1,     3,     2,     5,     1,     2,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     7,    11,    11,     5,     2,     5,
       5,     6,     1,     2,     2,     1,     2,     3,     2,     8,
       8,     9,    10,    11,    11,    12,    11,    12,    12,    13,
      10,    11,    11,    12,    11,    12,    12,    13,     1,     1,
       1,     1,     3,     2,     3,     2,     3,     2,     3,     3,
       5,     3,     3,     4,     1,     2,     5,     2,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     4,     5,     1,
       3,     3,     4,     3,     4,     1,     2,     3,     2,     3,
       3,     3,     3,     4,     5,     6,     5,     6,     4,     4,
       1,     1,     1,     1,     2,     2,     1,     1,     2,     2,
       1,     2,     2,     1,     2,     2,     1,     4,     5,     4,
       5,     1,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     3,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     8,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
  case 2: /* input: CompilationUnit  */
#line 101 "lalr1.y"
                       {
    theprogram=new astnode;
    theprogram->token="input";
    vector<astnode*>v;
    v.push_back((yyvsp[0].node));
    theprogram->children=v;
    // if(symtab!=nullptr)
    // delete symtab;
    // cout<<"in input";
    // cout<<endl;
    // exit(0);
    // prettyPrint($$);
    // cout<<$$->token<<" "<<(($$->children)[0])->token;
}
#line 2831 "lalr1.tab.c"
    break;

  case 3: /* SYMTABS: %empty  */
#line 119 "lalr1.y"
                  {
        // cout<<"in symtabs"<<endl;
		currscope++;
		fullscope = fullscope + "/" + to_string(currscope);

		curr_fcnscope = currscope;
		// symtab = new symtab_t;
		// symtab_top[fullscope] = symtab;
        // symtab_top.insert({fullscope,symtab});
        // symtab_top.insert(make_pair(fullscope,symtab));
        if(symtab_top.find(fullscope)==symtab_top.end()) {
            symtab = new symtab_t;
            symtab_top[fullscope]=symtab;

            // symtab_top.insert({fullscope,symtab});
        }
        // if(buffer.size()!=0) {
        //     symadd(buffer)
        // }
        for(auto i:buffer){
            symadd_para(i.first,i.second,1);
        }
        buffer.clear();
        // string s=$3->value;
        // vector<string>tokens=split(s,',');
        // // cout<<"\n executing symadd_list\n";
        // symadd_list(tokens,$2->type);
		// cout<<fullscope<<endl;
}
#line 2865 "lalr1.tab.c"
    break;

  case 4: /* SYMTABE: %empty  */
#line 151 "lalr1.y"
                  {
        // cout<<"in symtabe"<<endl;
		// fullscope = fullscope +"/"+ to_string(curr_fcnscope);	//$$ = new astnode($1->type,"Function", false, {$1, $3});

		// //Type* a = symtype("a");
		// //if( a==NULL ) *fp<<fullscope<<"-NULL-"<<endl;
		// print_symtab();
		// delete symtab;
		// symtab = symtab_top["0"];
		// fullscope = "0";
        // cout<<"executing substr"<<endl;
        fullscope = fullscope.substr(0, fullscope.find_last_of("/") );
        // cout<<fullscope<<endl;
        // cout<<"success ";
        // if(symtab!=nullptr){
        //     delete symtab;
        // }
        if(symtab_top.find(fullscope)!=symtab_top.end()) {
            // cout<<"in if ";
            symtab = symtab_top[fullscope];
        }
        else {
            // cout<<"in else";
            symtab=symtab_top["0"];
            fullscope="0";
        }
        // if(fullscope=="0"){ delete symtab;}
        // cout<<fullscope<<endl;
        // cout<<"leaved symtabe ";
        // print_symtab(symbolTable);
}
#line 2901 "lalr1.tab.c"
    break;

  case 5: /* IFMARK1: %empty  */
#line 186 "lalr1.y"
    {
        string tac,togo_label;
        togo_label=get_label();
        tac="if (t"+to_string(tempno-1)+"=1) goto "+togo_label;
        tac=to_string(line++)+" "+tac; prog.push_back(tac);

        string topush_label=get_label();
        tac="goto "+topush_label;
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        if_bwlabels.push(topush_label);

        tac=togo_label+":";
        tac=to_string(line++)+" "+tac; prog.push_back(tac);

    }
#line 2921 "lalr1.tab.c"
    break;

  case 6: /* IFEND1: %empty  */
#line 203 "lalr1.y"
    {
        string tac,toget_label;
        toget_label=if_bwlabels.top();
        if_bwlabels.pop();
	    tac = toget_label+":";
	    tac=to_string(line++)+" "+tac; prog.push_back(tac);
    }
#line 2933 "lalr1.tab.c"
    break;

  case 7: /* IFEND2: %empty  */
#line 212 "lalr1.y"
    {
        string tac,topush_label;
        topush_label=get_label();
        tac="goto "+topush_label;
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        if_endlabels.push(topush_label);
    }
#line 2945 "lalr1.tab.c"
    break;

  case 8: /* ELSEMARK1: %empty  */
#line 221 "lalr1.y"
    {
        string tac,toget_label;
        toget_label=if_bwlabels.top();
        if_bwlabels.pop();
	    tac = toget_label+":";
	    tac=to_string(line++)+" "+tac; prog.push_back(tac);
    }
#line 2957 "lalr1.tab.c"
    break;

  case 9: /* ELSEEND1: %empty  */
#line 230 "lalr1.y"
    {
        string tac,toget_label;
        toget_label=if_endlabels.top();
        if_endlabels.pop();
	    tac = toget_label+":";
	    tac=to_string(line++)+" "+tac; prog.push_back(tac);
    }
#line 2969 "lalr1.tab.c"
    break;

  case 10: /* WHILEMARK2: %empty  */
#line 240 "lalr1.y"
    {
        string tac,topush_label;
        topush_label=get_label();
        tac=topush_label+":";
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        while_bwlabels.push(topush_label);
   }
#line 2981 "lalr1.tab.c"
    break;

  case 11: /* WHILEMARK1: %empty  */
#line 250 "lalr1.y"
    {
        string tac,topush_label;
        topush_label=get_label();
        tac="if (t"+to_string(tempno-1)+"=0) goto "+topush_label;
        // while_exp.push("t"+to_string(tempno-1));
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        while_endlabels.push(topush_label);
        // topush_label=get_label();
        // tac=topush_label+":";
        // tac=to_string(line++)+" "+tac; prog.push_back(tac);
        // while_endlabels.push(topush_label);
    }
#line 2998 "lalr1.tab.c"
    break;

  case 12: /* WHILEEND1: %empty  */
#line 264 "lalr1.y"
    {
        string tac,toget_label,exp;
        toget_label=while_bwlabels.top();
        while_bwlabels.pop();
        // exp=while_exp.top();
        // while_exp.pop();
        // tac="if ("+exp+"=1) goto "+toget_label;
        tac="goto "+toget_label;
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        toget_label=while_endlabels.top();
        while_endlabels.pop();
        tac=toget_label+":";
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
    }
#line 3017 "lalr1.tab.c"
    break;

  case 13: /* DOMARK1: %empty  */
#line 280 "lalr1.y"
    {
        string tac,topush_label;
        topush_label=get_label();
        do_bwlabels.push(topush_label);
        tac=topush_label+":";
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
    }
#line 3029 "lalr1.tab.c"
    break;

  case 14: /* DOEND1: %empty  */
#line 289 "lalr1.y"
    {
        string tac,toget_label;
        toget_label=do_bwlabels.top();
        do_bwlabels.pop();
        tac="if (t"+to_string(tempno-1)+"=1) goto "+toget_label;
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
    }
#line 3041 "lalr1.tab.c"
    break;

  case 15: /* FORMARK1: %empty  */
#line 298 "lalr1.y"
    {
        string tac,topush_label;
        topush_label=get_label();
        for_initlabels.push(topush_label);
        tac=topush_label+":";
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
    }
#line 3053 "lalr1.tab.c"
    break;

  case 16: /* FORMARK2: %empty  */
#line 307 "lalr1.y"
    {
        string tac,topush_label;
        topush_label=get_label();
        for_statlabels.push(topush_label);
        tac="if (t"+to_string(tempno-1)+"=1) goto "+topush_label;
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        topush_label=get_label();
        for_endlabels.push(topush_label);
        tac="goto "+topush_label;
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        topush_label=get_label();
        for_updlabels.push(topush_label);
        tac=topush_label+":";
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
    }
#line 3073 "lalr1.tab.c"
    break;

  case 17: /* FORMARK3: %empty  */
#line 324 "lalr1.y"
    {
        string tac,toget_label;
        toget_label=for_initlabels.top();
        for_initlabels.pop();
        tac="goto "+toget_label;
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        toget_label=for_statlabels.top();
        for_statlabels.pop();
        tac=toget_label+":";
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
    }
#line 3089 "lalr1.tab.c"
    break;

  case 18: /* FOREND1: %empty  */
#line 337 "lalr1.y"
    {
        string tac,toget_label;
        toget_label=for_updlabels.top();
        for_updlabels.pop();
        tac="goto "+toget_label;
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        toget_label=for_endlabels.top();
        for_endlabels.pop();
        tac=toget_label+":";
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
    }
#line 3105 "lalr1.tab.c"
    break;

  case 19: /* CONDMARK1: %empty  */
#line 350 "lalr1.y"
    {
        string tac,topush_label=get_label();
        tac="if (t"+to_string(tempno-1)+"=0) goto "+topush_label;
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        cond_bwlabels.push(topush_label);
        topush_label=get_label();
        cond_inlabels.push(topush_label);
        tac=topush_label+":";
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
    }
#line 3120 "lalr1.tab.c"
    break;

  case 20: /* CONDMARK2: %empty  */
#line 362 "lalr1.y"
    {
        string tac,topush_label=get_label();
        tac="goto "+topush_label;
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        cond_endlabels.push(topush_label);
        topush_label=cond_bwlabels.top();
        cond_bwlabels.pop();
        tac=topush_label+":";
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
    }
#line 3135 "lalr1.tab.c"
    break;

  case 21: /* CONDMARK3: %empty  */
#line 374 "lalr1.y"
    {
        string tac,toget_label=cond_endlabels.top();
        cond_endlabels.pop();
        tac=toget_label+":";
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
    }
#line 3146 "lalr1.tab.c"
    break;

  case 22: /* PrintStatement: PRINTLN PrintArgs CLOSE_BR  */
#line 382 "lalr1.y"
                                           {
    (yyval.node)=new astnode;
    (yyval.node)->token="PrintStatement";
    vector<astnode*>v;
    v.push_back((yyvsp[-2].node));
    v.push_back((yyvsp[-1].node));
    v.push_back((yyvsp[0].node));
    (yyval.node)->children=v;
    // cout<<"in"<<$$->token;
    (yyval.node)->tac_val="sys.print "+(yyvsp[-1].node)->tac_val;
    (yyval.node)->type=(yyvsp[-2].node)->type;
    prog.push_back((yyval.node)->tac_val);
    // cout<<$$->tac_val;
    // cout<<"in PrintStatement";
}
#line 3166 "lalr1.tab.c"
    break;

  case 23: /* PrintArgs: PrintArg  */
#line 397 "lalr1.y"
                   {
        (yyval.node)=new astnode;
        (yyval.node)->token="PrintArgs";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->type=(yyvsp[0].node)->type;
        // cout<<"in PrintArgs";
        }
#line 3182 "lalr1.tab.c"
    break;

  case 24: /* PrintArgs: PrintArgs ADD PrintArg  */
#line 408 "lalr1.y"
                                {
        (yyval.node)=new astnode;
        (yyval.node)->token="PrintArgs";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[-2].node)->tac_val+(yyvsp[-1].node)->lexeme+(yyvsp[0].node)->tac_val;
        (yyval.node)->type=(yyvsp[-2].node)->type;
        // cout<<"in PrintArgs";
}
#line 3200 "lalr1.tab.c"
    break;

  case 25: /* PrintArg: IDENTIFIER  */
#line 421 "lalr1.y"
                    {
        (yyval.node)=new astnode;
        (yyval.node)->token="PrintArgs";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->lexeme;
        (yyval.node)->type=(yyvsp[0].node)->type;
        // cout<<"in PrintArg";
        }
#line 3216 "lalr1.tab.c"
    break;

  case 26: /* PrintArg: Literal  */
#line 432 "lalr1.y"
                 {
            (yyval.node)=new astnode;
        (yyval.node)->token="PrintArgs";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->type=(yyvsp[0].node)->type;
        // cout<<"in PrintArg";
        }
#line 3232 "lalr1.tab.c"
    break;

  case 27: /* PrintArg: %empty  */
#line 443 "lalr1.y"
          {
        // cout<<"in PrintArg";
        }
#line 3240 "lalr1.tab.c"
    break;

  case 28: /* Literal: INT_LIT  */
#line 449 "lalr1.y"
               {
        (yyval.node)=new astnode;
        (yyval.node)->token="Literal";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->lexeme;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=0;
        (yyval.node)->type="int";
        // cout<<$$->token;
    }
#line 3257 "lalr1.tab.c"
    break;

  case 29: /* Literal: FLOAT_LIT  */
#line 461 "lalr1.y"
                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="Literal";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->lexeme;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=0;
        (yyval.node)->type="float";
    }
#line 3273 "lalr1.tab.c"
    break;

  case 30: /* Literal: BOOL_LIT  */
#line 472 "lalr1.y"
                 {
        (yyval.node)=new astnode;
        (yyval.node)->token="Literal";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->lexeme;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=0;
        (yyval.node)->type="boolean";
    }
#line 3289 "lalr1.tab.c"
    break;

  case 31: /* Literal: CHAR_LIT  */
#line 483 "lalr1.y"
                 {
        (yyval.node)=new astnode;
        (yyval.node)->token="Literal";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->lexeme;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=0;
        (yyval.node)->type="char";
    }
#line 3305 "lalr1.tab.c"
    break;

  case 32: /* Literal: STR_LIT  */
#line 494 "lalr1.y"
                {
        (yyval.node)=new astnode;
        (yyval.node)->token="Literal";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->lexeme;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=0;
        (yyval.node)->type="String";
    }
#line 3321 "lalr1.tab.c"
    break;

  case 33: /* Literal: NULL_LIT  */
#line 505 "lalr1.y"
                 {
        (yyval.node)=new astnode;
        (yyval.node)->token="Literal";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->lexeme;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=0;
        (yyval.node)->type="NULL";
    }
#line 3337 "lalr1.tab.c"
    break;

  case 34: /* Type: PrimitiveType  */
#line 519 "lalr1.y"
                     {
    (yyval.node)=new astnode;
    (yyval.node)->token="Type";
    (yyval.node)->type=(yyvsp[0].node)->type;
    temp_type=(yyval.node)->type;
    vector<astnode*>v;
    v.push_back((yyvsp[0].node));
    (yyval.node)->children=v;
    // cout<<"in"<<$$->token;
}
#line 3352 "lalr1.tab.c"
    break;

  case 35: /* Type: ReferenceType  */
#line 529 "lalr1.y"
                      {
    (yyval.node)=new astnode;
    (yyval.node)->token="Type";
    (yyval.node)->type=(yyvsp[0].node)->type;
    temp_type=(yyval.node)->type;
    vector<astnode*>v;
    v.push_back((yyvsp[0].node));
    (yyval.node)->children=v;
    // cout<<"in"<<$$->token;
}
#line 3367 "lalr1.tab.c"
    break;

  case 36: /* PrimitiveType: NumericType  */
#line 541 "lalr1.y"
                   {
        (yyval.node)=new astnode;
        (yyval.node)->token="PrimitiveType";
        (yyval.node)->type=(yyvsp[0].node)->type;
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3381 "lalr1.tab.c"
    break;

  case 37: /* PrimitiveType: BOOLEAN  */
#line 550 "lalr1.y"
                {
        (yyval.node)=new astnode;
        (yyval.node)->token="PrimitiveType";
        (yyval.node)->type=(yyvsp[0].node)->lexeme;
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3395 "lalr1.tab.c"
    break;

  case 38: /* NumericType: IntegralType  */
#line 561 "lalr1.y"
                    {
        (yyval.node)=new astnode;
        (yyval.node)->token="NumericType";
        (yyval.node)->type=(yyvsp[0].node)->type;
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3409 "lalr1.tab.c"
    break;

  case 39: /* NumericType: FloatingPointType  */
#line 570 "lalr1.y"
                          {
        (yyval.node)=new astnode;
        (yyval.node)->token="NumericType";
        (yyval.node)->type=(yyvsp[0].node)->type;
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3423 "lalr1.tab.c"
    break;

  case 40: /* IntegralType: BYTE  */
#line 581 "lalr1.y"
            {
        (yyval.node)=new astnode;
        (yyval.node)->token="IntegralType";
        (yyval.node)->type="byte";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3437 "lalr1.tab.c"
    break;

  case 41: /* IntegralType: SHORT  */
#line 590 "lalr1.y"
          {
        (yyval.node)=new astnode;
        (yyval.node)->token="IntegralType";
        (yyval.node)->type="short";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3451 "lalr1.tab.c"
    break;

  case 42: /* IntegralType: INT  */
#line 599 "lalr1.y"
        {
        (yyval.node)=new astnode;
        (yyval.node)->token="IntegralType";
        (yyval.node)->type="int";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3465 "lalr1.tab.c"
    break;

  case 43: /* IntegralType: LONG  */
#line 608 "lalr1.y"
         {
        (yyval.node)=new astnode;
        (yyval.node)->token="IntegralType";
        (yyval.node)->type="long";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3479 "lalr1.tab.c"
    break;

  case 44: /* IntegralType: CHAR  */
#line 617 "lalr1.y"
         {
        (yyval.node)=new astnode;
        (yyval.node)->token="IntegralType";
        (yyval.node)->type="char";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3493 "lalr1.tab.c"
    break;

  case 45: /* FloatingPointType: FLOAT  */
#line 628 "lalr1.y"
         {
        (yyval.node)=new astnode;
        (yyval.node)->token="FloatingPointType";
        (yyval.node)->type="float";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3507 "lalr1.tab.c"
    break;

  case 46: /* FloatingPointType: DOUBLE  */
#line 637 "lalr1.y"
           {
        (yyval.node)=new astnode;
        (yyval.node)->token="FloatingPointType";
        (yyval.node)->type="double";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3521 "lalr1.tab.c"
    break;

  case 47: /* ReferenceType: ClassOrInterfaceType  */
#line 648 "lalr1.y"
                            {
        (yyval.node)=new astnode;
        (yyval.node)->token="ReferenceType";
        // $$->type="Classorinterface";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 3537 "lalr1.tab.c"
    break;

  case 48: /* ReferenceType: ArrayType  */
#line 659 "lalr1.y"
                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="ReferenceType";
        // $$->type="array";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 3552 "lalr1.tab.c"
    break;

  case 49: /* ClassOrInterfaceType: Name  */
#line 671 "lalr1.y"
            {
        (yyval.node)=new astnode;
        (yyval.node)->token="ClassOrInterfaceType";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->value=(yyvsp[0].node)->value;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 3568 "lalr1.tab.c"
    break;

  case 50: /* ClassType: ClassOrInterfaceType  */
#line 684 "lalr1.y"
                            {
        (yyval.node)=new astnode;
        (yyval.node)->token="ClassType";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 3583 "lalr1.tab.c"
    break;

  case 51: /* InterfaceType: ClassOrInterfaceType  */
#line 696 "lalr1.y"
                            {
        (yyval.node)=new astnode;
        (yyval.node)->token="InterfaceType";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->value=(yyvsp[0].node)->value;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 3599 "lalr1.tab.c"
    break;

  case 52: /* ArrayType: PrimitiveType OPEN_SQ CLOSE_SQ  */
#line 709 "lalr1.y"
                                      {
        (yyval.node)=new astnode;
        (yyval.node)->token="ArrayType";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->type=(yyvsp[-2].node)->type;
    }
#line 3615 "lalr1.tab.c"
    break;

  case 53: /* ArrayType: Name OPEN_SQ CLOSE_SQ  */
#line 720 "lalr1.y"
                              {
        (yyval.node)=new astnode;
        (yyval.node)->token="ArrayType";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->type=(yyvsp[-2].node)->type;
    }
#line 3631 "lalr1.tab.c"
    break;

  case 54: /* ArrayType: ArrayType OPEN_SQ CLOSE_SQ  */
#line 731 "lalr1.y"
                                   {
        (yyval.node)=new astnode;
        (yyval.node)->token="ArrayType";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->type=(yyvsp[-2].node)->type;
    }
#line 3647 "lalr1.tab.c"
    break;

  case 55: /* Name: SingularName  */
#line 745 "lalr1.y"
                    {
        (yyval.node)=new astnode;
        (yyval.node)->token="Name";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->value=(yyvsp[0].node)->value;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 3664 "lalr1.tab.c"
    break;

  case 56: /* Name: ComplexName  */
#line 757 "lalr1.y"
                    {
        (yyval.node)=new astnode;
        (yyval.node)->token="Name";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->value=(yyvsp[0].node)->value;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 3681 "lalr1.tab.c"
    break;

  case 57: /* SingularName: IDENTIFIER  */
#line 771 "lalr1.y"
                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="SingularName";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->value=(yyvsp[0].node)->lexeme;
        (yyval.node)->tac_val=(yyvsp[0].node)->lexeme;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=0;
        // symtab_t* t=symtab_top[fullscope];
        (yyval.node)->type=symtabGetType(fullscope,(yyval.node)->value);
        if((yyval.node)->type=="0"||(yyval.node)->type=="constructor"){
            (yyval.node)->type=(yyvsp[0].node)->lexeme;
        }
    }
#line 3702 "lalr1.tab.c"
    break;

  case 58: /* ComplexName: Name PERIOD IDENTIFIER  */
#line 789 "lalr1.y"
                              {
        (yyval.node)=new astnode;
        (yyval.node)->token="ComplexName";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->value=(yyvsp[-2].node)->value+"."+(yyvsp[0].node)->lexeme;    //changed
        (yyval.node)->tac_val=(yyvsp[-2].node)->tac_val+"."+(yyvsp[0].node)->lexeme;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=0;
        (yyval.node)->type=symtabGetType(fullscope,(yyval.node)->tac_val);
        if((yyval.node)->type=="0"){
            // cout<<fullscope;
            string s=symtabGetType(fullscope,(yyvsp[-2].node)->value);
            if(s=="0") cout<<"no object created";
            // cout<<s;
            symtab_t*t=symtab_top[m1[s]];
            Type*t1=(*t)[(yyvsp[0].node)->lexeme];
            (yyval.node)->type=t1->type;
            // cout<<$$->type;
        }
         else (yyval.node)->type=(yyvsp[-2].node)->lexeme;
    }
#line 3732 "lalr1.tab.c"
    break;

  case 59: /* CompilationUnit: %empty  */
#line 816 "lalr1.y"
                {
        (yyval.node)=new astnode;
        (yyval.node)->token="CompilationUnit";
        vector<astnode*>v;
        v.push_back(NULL);
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3745 "lalr1.tab.c"
    break;

  case 60: /* CompilationUnit: PackageDeclaration  */
#line 824 "lalr1.y"
                       {
        (yyval.node)=new astnode;
        (yyval.node)->token="CompilationUnit";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3758 "lalr1.tab.c"
    break;

  case 61: /* CompilationUnit: PackageDeclaration ImportDeclarations  */
#line 832 "lalr1.y"
                                          {
        (yyval.node)=new astnode;
        (yyval.node)->token="CompilationUnit";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3772 "lalr1.tab.c"
    break;

  case 62: /* CompilationUnit: PackageDeclaration TypeDeclarations  */
#line 841 "lalr1.y"
                                        {
        (yyval.node)=new astnode;
        (yyval.node)->token="CompilationUnit";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3786 "lalr1.tab.c"
    break;

  case 63: /* CompilationUnit: PackageDeclaration ImportDeclarations TypeDeclarations  */
#line 850 "lalr1.y"
                                                           {
        (yyval.node)=new astnode;
        (yyval.node)->token="CompilationUnit";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3801 "lalr1.tab.c"
    break;

  case 64: /* CompilationUnit: ImportDeclarations TypeDeclarations  */
#line 860 "lalr1.y"
                                        {
        (yyval.node)=new astnode;
        (yyval.node)->token="CompilationUnit";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3815 "lalr1.tab.c"
    break;

  case 65: /* CompilationUnit: ImportDeclarations  */
#line 869 "lalr1.y"
                       {
        (yyval.node)=new astnode;
        (yyval.node)->token="SingularName";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3828 "lalr1.tab.c"
    break;

  case 66: /* CompilationUnit: TypeDeclarations  */
#line 877 "lalr1.y"
                     {
        (yyval.node)=new astnode;
        (yyval.node)->token="CompilationUnit";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3841 "lalr1.tab.c"
    break;

  case 67: /* ImportDeclarations: ImportDeclaration  */
#line 887 "lalr1.y"
                         {
        (yyval.node)=new astnode;
        (yyval.node)->token="ImportDeclarations";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3854 "lalr1.tab.c"
    break;

  case 68: /* ImportDeclarations: ImportDeclarations ImportDeclaration  */
#line 895 "lalr1.y"
                                             {
        (yyval.node)=new astnode;
        (yyval.node)->token="ImportDeclarations";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3868 "lalr1.tab.c"
    break;

  case 69: /* TypeDeclarations: TypeDeclaration  */
#line 906 "lalr1.y"
                   {
        (yyval.node)=new astnode;
        (yyval.node)->token="TypeDeclarations";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3881 "lalr1.tab.c"
    break;

  case 70: /* TypeDeclarations: TypeDeclarations TypeDeclaration  */
#line 914 "lalr1.y"
                                         {
        (yyval.node)=new astnode;
        (yyval.node)->token="TypeDeclarations";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3895 "lalr1.tab.c"
    break;

  case 71: /* PackageDeclaration: PACKAGE Name SEMICOLON  */
#line 925 "lalr1.y"
                              {
        (yyval.node)=new astnode;
        (yyval.node)->token="PackageDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3910 "lalr1.tab.c"
    break;

  case 72: /* ImportDeclaration: SingleTypeImportDeclaration  */
#line 937 "lalr1.y"
                                   {
        (yyval.node)=new astnode;
        (yyval.node)->token="ImportDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3923 "lalr1.tab.c"
    break;

  case 73: /* ImportDeclaration: TypeImportOnDemandDeclaration  */
#line 945 "lalr1.y"
                                      {
        (yyval.node)=new astnode;
        (yyval.node)->token="ImportDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3936 "lalr1.tab.c"
    break;

  case 74: /* SingleTypeImportDeclaration: IMPORT Name SEMICOLON  */
#line 955 "lalr1.y"
                             {
        (yyval.node)=new astnode;
        (yyval.node)->token="SingleTypeImportDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3951 "lalr1.tab.c"
    break;

  case 75: /* TypeImportOnDemandDeclaration: IMPORT Name PERIOD MUL SEMICOLON  */
#line 967 "lalr1.y"
                                        {
        (yyval.node)=new astnode;
        (yyval.node)->token="TypeImportOnDemandDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 3968 "lalr1.tab.c"
    break;

  case 76: /* TypeDeclaration: ClassDeclaration  */
#line 981 "lalr1.y"
                        {
        (yyval.node)=new astnode;
        (yyval.node)->token="TypeDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->type=(yyvsp[0].node)->type;
        // cout<<"in"<<$$->token;
    }
#line 3982 "lalr1.tab.c"
    break;

  case 77: /* TypeDeclaration: InterfaceDeclaration  */
#line 990 "lalr1.y"
                             {
        (yyval.node)=new astnode;
        (yyval.node)->token="TypeDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->type=(yyvsp[0].node)->type;
        // cout<<"in"<<$$->token;
    }
#line 3996 "lalr1.tab.c"
    break;

  case 78: /* TypeDeclaration: SEMICOLON  */
#line 999 "lalr1.y"
                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="TypeDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 4009 "lalr1.tab.c"
    break;

  case 79: /* Modifiers: Modifier  */
#line 1009 "lalr1.y"
                {
        (yyval.node)=new astnode;
        (yyval.node)->token="Modifiers";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->access_specifier=(yyvsp[0].node)->access_specifier;
        // cout<<"in"<<$$->token;
    }
#line 4023 "lalr1.tab.c"
    break;

  case 80: /* Modifiers: Modifiers Modifier  */
#line 1018 "lalr1.y"
                           {
        (yyval.node)=new astnode;
        (yyval.node)->token="Modifiers";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        if((yyvsp[-1].node)->access_specifier==0||(yyvsp[0].node)->access_specifier==0) (yyval.node)->access_specifier=0;
        // cout<<"in"<<$$->token;
    }
#line 4038 "lalr1.tab.c"
    break;

  case 81: /* Modifier: PUBLIC  */
#line 1030 "lalr1.y"
              {
        (yyval.node)=new astnode;
        (yyval.node)->token="Modifier";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 4051 "lalr1.tab.c"
    break;

  case 82: /* Modifier: PROTECTED  */
#line 1038 "lalr1.y"
                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="Modifier";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 4064 "lalr1.tab.c"
    break;

  case 83: /* Modifier: PRIVATE  */
#line 1046 "lalr1.y"
                {
        (yyval.node)=new astnode;
        (yyval.node)->token="Modifier";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->access_specifier=0;
        // cout<<"in"<<$$->token;
    }
#line 4078 "lalr1.tab.c"
    break;

  case 84: /* Modifier: STATIC  */
#line 1055 "lalr1.y"
               {
        (yyval.node)=new astnode;
        (yyval.node)->token="Modifier";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 4091 "lalr1.tab.c"
    break;

  case 85: /* Modifier: ABSTRACT  */
#line 1063 "lalr1.y"
                 {
        (yyval.node)=new astnode;
        (yyval.node)->token="Modifier";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 4104 "lalr1.tab.c"
    break;

  case 86: /* Modifier: FINAL  */
#line 1071 "lalr1.y"
              {
        (yyval.node)=new astnode;
        (yyval.node)->token="Modifier";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 4117 "lalr1.tab.c"
    break;

  case 87: /* Modifier: NATIVE  */
#line 1079 "lalr1.y"
               {
        (yyval.node)=new astnode;
        (yyval.node)->token="Modifier";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 4130 "lalr1.tab.c"
    break;

  case 88: /* Modifier: SYNCHRONIZED  */
#line 1087 "lalr1.y"
                     {
        (yyval.node)=new astnode;
        (yyval.node)->token="Modifier";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 4143 "lalr1.tab.c"
    break;

  case 89: /* Modifier: TRANSIENT  */
#line 1095 "lalr1.y"
                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="Modifier";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 4156 "lalr1.tab.c"
    break;

  case 90: /* Modifier: VOLATILE  */
#line 1103 "lalr1.y"
                 {
        (yyval.node)=new astnode;
        (yyval.node)->token="Modifier";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 4169 "lalr1.tab.c"
    break;

  case 91: /* ClassName: IDENTIFIER  */
#line 1114 "lalr1.y"
               {
        (yyval.node)=new astnode;
        (yyval.node)->token="ClassName";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        cname=(yyvsp[0].node)->lexeme;
        fname=cname;
        (yyval.node)->value=(yyvsp[0].node)->lexeme;
        (yyval.node)->type=(yyvsp[0].node)->type;
        class_labels.push((yyvsp[0].node)->lexeme);
    }
#line 4186 "lalr1.tab.c"
    break;

  case 92: /* ClassDeclaration: Modifiers CLASS ClassName Super Interfaces ClassBody  */
#line 1128 "lalr1.y"
                                                            {
        (yyval.node)=new astnode;
        (yyval.node)->token="ClassDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[-5].node));
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        symadd((yyvsp[-3].node)->value,"class_"+(yyvsp[-3].node)->value,(yyvsp[-1].node)->value);
        (yyval.node)->type=(yyvsp[-3].node)->type;
        // cout<<"in"<<$$->token;
    }
#line 4206 "lalr1.tab.c"
    break;

  case 93: /* ClassDeclaration: Modifiers CLASS ClassName Super ClassBody  */
#line 1143 "lalr1.y"
                                                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="ClassDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        symadd((yyvsp[-2].node)->value,"class_"+(yyvsp[-2].node)->value,"NULL");
        (yyval.node)->type=(yyvsp[-2].node)->type;
        // cout<<"in"<<$$->token;
    }
#line 4225 "lalr1.tab.c"
    break;

  case 94: /* ClassDeclaration: Modifiers CLASS ClassName Interfaces ClassBody  */
#line 1157 "lalr1.y"
                                                       {
        (yyval.node)=new astnode;
        (yyval.node)->token="ClassDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        symadd((yyvsp[-2].node)->value,"class_"+(yyvsp[-2].node)->value,(yyvsp[-1].node)->value);
        (yyval.node)->type=(yyvsp[-2].node)->type;
        // cout<<"in"<<$$->token;
    }
#line 4244 "lalr1.tab.c"
    break;

  case 95: /* ClassDeclaration: Modifiers CLASS ClassName ClassBody  */
#line 1171 "lalr1.y"
                                            {
        (yyval.node)=new astnode;
        (yyval.node)->token="ClassDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        symadd((yyvsp[-1].node)->value,"class_"+(yyvsp[-1].node)->value,"NULL");
        (yyval.node)->type=(yyvsp[-1].node)->type;
        // cout<<"in"<<$$->token;
    }
#line 4262 "lalr1.tab.c"
    break;

  case 96: /* ClassDeclaration: CLASS ClassName Super Interfaces ClassBody  */
#line 1184 "lalr1.y"
                                                   {
        (yyval.node)=new astnode;
        (yyval.node)->token="ClassDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        symadd((yyvsp[-3].node)->value,"class_"+(yyvsp[-3].node)->value,(yyvsp[-1].node)->value);
        (yyval.node)->type=(yyvsp[-3].node)->type;
        // cout<<"in"<<$$->token;
    }
#line 4281 "lalr1.tab.c"
    break;

  case 97: /* ClassDeclaration: CLASS ClassName Super ClassBody  */
#line 1198 "lalr1.y"
                                        {
        (yyval.node)=new astnode;
        (yyval.node)->token="ClassDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        symadd((yyvsp[-2].node)->value,"class_"+(yyvsp[-2].node)->value,"NULL");
        (yyval.node)->type=(yyvsp[-2].node)->type;
        // cout<<"in"<<$$->token;
    }
#line 4299 "lalr1.tab.c"
    break;

  case 98: /* ClassDeclaration: CLASS ClassName Interfaces ClassBody  */
#line 1211 "lalr1.y"
                                             {
        (yyval.node)=new astnode;
        (yyval.node)->token="ClassDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        symadd((yyvsp[-2].node)->value,"class_"+(yyvsp[-2].node)->value,(yyvsp[-1].node)->value);
        (yyval.node)->type=(yyvsp[-2].node)->type;
        // cout<<"in"<<$$->token;
    }
#line 4317 "lalr1.tab.c"
    break;

  case 99: /* ClassDeclaration: CLASS ClassName ClassBody  */
#line 1224 "lalr1.y"
                                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="ClassDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        symadd((yyvsp[-1].node)->value,"class_"+(yyvsp[-1].node)->value,"NULL");
        (yyval.node)->type=(yyvsp[-1].node)->type;
        // cout<<"in"<<$$->token;
    }
#line 4334 "lalr1.tab.c"
    break;

  case 100: /* Super: EXTENDS ClassType  */
#line 1238 "lalr1.y"
                         {
        (yyval.node)=new astnode;
        (yyval.node)->token="Super";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 4349 "lalr1.tab.c"
    break;

  case 101: /* Interfaces: IMPLEMENTS InterfaceTypeList  */
#line 1250 "lalr1.y"
                                    {
        (yyval.node)=new astnode;
        (yyval.node)->token="Interfaces";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->value=(yyvsp[0].node)->value;
        // cout<<"in"<<$$->token;
    }
#line 4364 "lalr1.tab.c"
    break;

  case 102: /* InterfaceTypeList: InterfaceType  */
#line 1262 "lalr1.y"
                     {
        (yyval.node)=new astnode;
        (yyval.node)->token="InterfaceTypeList";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->value=(yyvsp[0].node)->value;
        // cout<<"in"<<$$->token;
    }
#line 4378 "lalr1.tab.c"
    break;

  case 103: /* InterfaceTypeList: InterfaceTypeList COMMA InterfaceType  */
#line 1271 "lalr1.y"
                                              {
        (yyval.node)=new astnode;
        (yyval.node)->token="InterfaceTypeList";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->value=(yyvsp[-2].node)->value+","+(yyvsp[0].node)->value;
        // cout<<"in"<<$$->token;
    }
#line 4394 "lalr1.tab.c"
    break;

  case 104: /* CLASSMARK1: %empty  */
#line 1284 "lalr1.y"
    {
        string n=class_labels.top();
        class_labels.pop();
        m1[n]=fullscope;
        // cout<<fullscope<<" ";
    }
#line 4405 "lalr1.tab.c"
    break;

  case 105: /* ClassBody: OPEN_CR SYMTABS CLASSMARK1 ClassBodyDeclarations CLOSE_CR SYMTABE  */
#line 1292 "lalr1.y"
                                                                         {
        // cout<<"entered in classBody ";
        (yyval.node)=new astnode;
        (yyval.node)->token="ClassBody";
        vector<astnode*>v;
        v.push_back((yyvsp[-5].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 4421 "lalr1.tab.c"
    break;

  case 106: /* ClassBody: OPEN_CR CLOSE_CR  */
#line 1303 "lalr1.y"
                         {
        (yyval.node)=new astnode;
        (yyval.node)->token="ClassBody";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 4435 "lalr1.tab.c"
    break;

  case 107: /* ClassBodyDeclarations: ClassBodyDeclaration  */
#line 1314 "lalr1.y"
                            {
        (yyval.node)=new astnode;
        (yyval.node)->token="ClassBodyDeclarations";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 4448 "lalr1.tab.c"
    break;

  case 108: /* ClassBodyDeclarations: ClassBodyDeclarations ClassBodyDeclaration  */
#line 1322 "lalr1.y"
                                                   {
        (yyval.node)=new astnode;
        (yyval.node)->token="ClassBodyDeclarations";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 4462 "lalr1.tab.c"
    break;

  case 109: /* ClassBodyDeclaration: ClassMemberDeclaration  */
#line 1333 "lalr1.y"
                              {
        (yyval.node)=new astnode;
        (yyval.node)->token="ClassBodyDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->type=(yyvsp[0].node)->type;
        // cout<<"in"<<$$->token;
    }
#line 4476 "lalr1.tab.c"
    break;

  case 110: /* ClassBodyDeclaration: StaticInitializer  */
#line 1342 "lalr1.y"
                          {
        (yyval.node)=new astnode;
        (yyval.node)->token="ClassBodyDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->type=(yyvsp[0].node)->type;
        // cout<<"in"<<$$->token;
    }
#line 4490 "lalr1.tab.c"
    break;

  case 111: /* ClassBodyDeclaration: ConstructorDeclaration  */
#line 1351 "lalr1.y"
                               {
        (yyval.node)=new astnode;
        (yyval.node)->token="ClassBodyDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->type=(yyvsp[0].node)->type;
        // cout<<"in"<<$$->token;
    }
#line 4504 "lalr1.tab.c"
    break;

  case 112: /* ClassMemberDeclaration: FieldDeclaration  */
#line 1362 "lalr1.y"
                        {
        (yyval.node)=new astnode;
        (yyval.node)->token="ClassMemberDeclarations";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->type=(yyvsp[0].node)->type;
        // cout<<"in"<<$$->token;
    }
#line 4518 "lalr1.tab.c"
    break;

  case 113: /* ClassMemberDeclaration: MethodDeclaration  */
#line 1371 "lalr1.y"
                          {
        (yyval.node)=new astnode;
        (yyval.node)->token="ClassMemberDeclarations";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->type=(yyvsp[0].node)->type;
        // cout<<"in"<<$$->token;
    }
#line 4532 "lalr1.tab.c"
    break;

  case 114: /* FieldDeclaration: Modifiers Type VariableDeclarators SEMICOLON  */
#line 1383 "lalr1.y"
                                                    {
        (yyval.node)=new astnode;
        (yyval.node)->token="FieldDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        string s=(yyvsp[-1].node)->value;
        vector<string>tokens=split(s,',');
        // cout<<"\n executing symadd_list\n";
        symadd_list(tokens,(yyvsp[-2].node)->type);
        // cout<<"in"<<$$->token;
        (yyvsp[-1].node)->type=(yyvsp[-2].node)->type;
        temp_type="";
    }
#line 4554 "lalr1.tab.c"
    break;

  case 115: /* FieldDeclaration: Type VariableDeclarators SEMICOLON  */
#line 1400 "lalr1.y"
                                           {
        (yyval.node)=new astnode;
        (yyval.node)->token="FieldDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        string s=(yyvsp[-1].node)->value;
        vector<string>tokens=split(s,',');
        // cout<<"\n executing symadd_list\n";
        symadd_list(tokens,(yyvsp[-2].node)->type);
        // cout<<"in"<<$$->token;
        (yyvsp[-1].node)->type=(yyvsp[-2].node)->type;
        temp_type="";
    }
#line 4575 "lalr1.tab.c"
    break;

  case 116: /* VariableDeclarators: VariableDeclarator  */
#line 1418 "lalr1.y"
                          {
        (yyval.node)=new astnode;
        (yyval.node)->token="VariableDeclarators";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->value=(yyvsp[0].node)->value;
        // cout<<"in"<<$$->token;
        (yyval.node)->type=temp_type;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        if((yyvsp[0].node)->flag==4) {
            // $$->tuples=$1->tuples;
            (yyval.node)->length=(yyvsp[0].node)->length;
        }
        (yyval.node)->dims=(yyvsp[0].node)->dims;
    }
#line 4596 "lalr1.tab.c"
    break;

  case 117: /* VariableDeclarators: VariableDeclarators COMMA VariableDeclarator  */
#line 1434 "lalr1.y"
                                                     {
        (yyval.node)=new astnode;
        (yyval.node)->token="VariableDeclarators";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->value = (yyvsp[-2].node)->value+","+(yyvsp[0].node)->value;
        // cout<<"in"<<$$->token;
        temp=symtypeEvaluate((yyvsp[-2].node)->type,(yyvsp[0].node)->type);
        if(temp=="0")
        {
            cout<<"Not all variables are of same type";
        }
        (yyval.node)->type=temp;
    }
#line 4618 "lalr1.tab.c"
    break;

  case 118: /* VariableDeclarator: VariableDeclaratorId  */
#line 1453 "lalr1.y"
                            {
        (yyval.node)=new astnode;
        (yyval.node)->token="VariableDeclarator";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->value=(yyvsp[0].node)->value;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 4636 "lalr1.tab.c"
    break;

  case 119: /* VariableDeclarator: VariableDeclaratorId ASSIGN VariableInitializer  */
#line 1466 "lalr1.y"
                                                        {
        (yyval.node)=new astnode;
        (yyval.node)->token="VariableDeclarator";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->value=(yyvsp[-2].node)->value;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[-2].node)->tac_val;
        string tac;
        temp=symAssignment((yyvsp[-2].node)->type,(yyvsp[0].node)->type);
        // cout<<$1->type<<" "<<$3->type;
        if(temp=="0")
        {
            cout<<"type mismatch";
            //uncomment
        }
        if((yyvsp[-2].node)->type != (yyvsp[0].node)->type)
        {    string t=get_tempvar();
             s1=t+" = cast_to_"+temp+" "+(yyvsp[0].node)->tac_val;
            prog.push_back(s1);
        }
        
        (yyval.node)->type=temp;
        if(fname==cname)
        tac=fname+"."+(yyvsp[-2].node)->tac_val+" = "+(yyvsp[0].node)->tac_val;
        else if((yyvsp[0].node)->flag==1) tac=(yyvsp[-2].node)->tac_val+" = t"+to_string(tempno-1);
        else tac=(yyvsp[-2].node)->tac_val+" = "+(yyvsp[0].node)->tac_val;
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        if((yyvsp[0].node)->flag==3) {
            tac="*"+(yyvsp[-2].node)->tac_val+" = t"+to_string(tempno-1);
            tac=to_string(line++)+" "+tac; prog.push_back(tac);
        }
        if((yyvsp[0].node)->flag==4) {
            tac=(yyvsp[-2].node)->tac_val+" = "+"&t"+to_string(tempno-1);
            tac=to_string(line++)+" "+tac; prog.push_back(tac);
            vector<string>v1=split((yyvsp[0].node)->value,',');
            int l=(yyvsp[0].node)->length;
            for(int i=0;i<l;i++) {
                string s1="*(";
                string s2="+";
                string s3=") = ";
                tac=s1+(yyvsp[-2].node)->tac_val+s2+to_string(i*4)+s3+v1[i];
                tac=to_string(line++)+" "+tac; prog.push_back(tac);
            }
            (yyval.node)->length=(yyvsp[0].node)->length;
            // $$->tuples=$3->tuples;
            if((yyvsp[-2].node)->dims!=(yyvsp[0].node)->dims && (yyvsp[-2].node)->flag==4){
            cout<<"Arrays not of same dimension";
        }
        }
        // cout<<"\n"<<$1->dims<<" "<<$3->dims;
        
        (yyval.node)->flag=(yyvsp[-2].node)->flag;
        (yyval.node)->dims=(yyvsp[-2].node)->dims;
    }
#line 4699 "lalr1.tab.c"
    break;

  case 120: /* VariableDeclaratorId: IDENTIFIER  */
#line 1526 "lalr1.y"
                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="VariableDeclaratorId";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->value=(yyvsp[0].node)->lexeme;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->lexeme;
        // gpara=$1->lexeme;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
        if(temp_type!="")
            (yyval.node)->type=temp_type;
        // else
        // {
        //     symtab_t* t=symtab_top[fullscope];
        //     $$->type=symtabGetType(t,$$->value);
        // }
    }
#line 4724 "lalr1.tab.c"
    break;

  case 121: /* VariableDeclaratorId: VariableDeclaratorId OPEN_SQ CLOSE_SQ  */
#line 1546 "lalr1.y"
                                              {
        (yyval.node)=new astnode;
        (yyval.node)->token="VariableDeclaratorId";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->value=(yyvsp[-2].node)->value;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[-2].node)->tac_val+"[]";
        (yyval.node)->dims=(yyvsp[-2].node)->dims+1;
        // gpara=$$->tac;
        if((yyval.node)->value!="args")
        {
            if(temp_type!="")
            (yyval.node)->type=temp_type;
            // else
            // {
            //     symtab_t* t=symtab_top[fullscope];
            //     $$->type=symtabGetType(t,$$->value);
            // }
        }
        else
        {
            (yyval.node)->type="String";
        }
        (yyval.node)->flag=4;
    }
#line 4758 "lalr1.tab.c"
    break;

  case 122: /* VariableInitializer: Expression  */
#line 1577 "lalr1.y"
                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="VariableInitializer";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
        (yyval.node)->space=(yyvsp[0].node)->space;
        (yyval.node)->value=(yyvsp[0].node)->tac_val;
    }
#line 4777 "lalr1.tab.c"
    break;

  case 123: /* VariableInitializer: ArrayInitializer  */
#line 1591 "lalr1.y"
                         {
        (yyval.node)=new astnode;
        (yyval.node)->token="VariableInitializer";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        // $$->tuples=$1->tuples;
        (yyval.node)->length=(yyvsp[0].node)->length;
        (yyval.node)->type=(yyvsp[0].node)->type;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
        (yyval.node)->space=(yyvsp[0].node)->space;
        (yyval.node)->value=(yyvsp[0].node)->value;
    }
#line 4798 "lalr1.tab.c"
    break;

  case 124: /* MethodDeclaration: MethodHeader MethodBody  */
#line 1610 "lalr1.y"
                               {
        (yyval.node)=new astnode;
        (yyval.node)->token="MethodDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->type=(yyvsp[-1].node)->type;
        fname=cname;
        string tac;
        tac="pop BP_old";
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        tac="BP=BP_old";
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        tac="return";
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        
        
    }
#line 4823 "lalr1.tab.c"
    break;

  case 125: /* MethodHeader: Modifiers Type MethodDeclarator Throws  */
#line 1632 "lalr1.y"
                                              {
        (yyval.node)=new astnode;
        (yyval.node)->token="MethodHeader";
        vector<astnode*>v;
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        symadd((yyvsp[-1].node)->name,(yyvsp[-2].node)->type,(yyvsp[-1].node)->value,(yyvsp[-3].node)->access_specifier);
        (yyval.node)->type=(yyvsp[-2].node)->type;
        // cout<<"in"<<$$->token;

    }
#line 4842 "lalr1.tab.c"
    break;

  case 126: /* MethodHeader: Modifiers Type MethodDeclarator  */
#line 1646 "lalr1.y"
                                        {
        (yyval.node)=new astnode;
        (yyval.node)->token="MethodHeader";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        symadd((yyvsp[0].node)->name,(yyvsp[-1].node)->type,(yyvsp[0].node)->value,(yyvsp[-2].node)->access_specifier);
        (yyval.node)->type=(yyvsp[-1].node)->type;
        // cout<<"in"<<$$->token;
    }
#line 4859 "lalr1.tab.c"
    break;

  case 127: /* MethodHeader: Type MethodDeclarator Throws  */
#line 1658 "lalr1.y"
                                     {
        (yyval.node)=new astnode;
        (yyval.node)->token="MethodHeader";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        symadd((yyvsp[-1].node)->name,(yyvsp[-2].node)->type,(yyvsp[-1].node)->value);
        (yyval.node)->type=(yyvsp[-2].node)->type;
        // cout<<"in"<<$$->token;
    }
#line 4876 "lalr1.tab.c"
    break;

  case 128: /* MethodHeader: Type MethodDeclarator  */
#line 1670 "lalr1.y"
                              {
        (yyval.node)=new astnode;
        (yyval.node)->token="MethodHeader";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        symadd((yyvsp[0].node)->name,(yyvsp[-1].node)->type,(yyvsp[0].node)->value);
        (yyval.node)->type=(yyvsp[-1].node)->type;
        // cout<<"in"<<$$->token;
    }
#line 4892 "lalr1.tab.c"
    break;

  case 129: /* MethodHeader: Modifiers VOID MethodDeclarator Throws  */
#line 1681 "lalr1.y"
                                               {
        (yyval.node)=new astnode;
        (yyval.node)->token="MethodHeader";
        vector<astnode*>v;
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        symadd((yyvsp[-1].node)->name,"void",(yyvsp[-1].node)->value,(yyvsp[-3].node)->access_specifier);
        (yyval.node)->type="void";
        // cout<<"in"<<$$->token;
    }
#line 4910 "lalr1.tab.c"
    break;

  case 130: /* MethodHeader: Modifiers VOID MethodDeclarator  */
#line 1694 "lalr1.y"
                                        {
        (yyval.node)=new astnode;
        (yyval.node)->token="MethodHeader";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        symadd((yyvsp[0].node)->name,"void",(yyvsp[0].node)->value,(yyvsp[-2].node)->access_specifier);
        (yyval.node)->type="void";
        // cout<<"in"<<$$->token;
    }
#line 4927 "lalr1.tab.c"
    break;

  case 131: /* MethodHeader: VOID MethodDeclarator Throws  */
#line 1706 "lalr1.y"
                                     {
        (yyval.node)=new astnode;
        (yyval.node)->token="MethodHeader";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        symadd((yyvsp[-1].node)->name,"void",(yyvsp[-1].node)->value);
        (yyval.node)->type="void";
        // cout<<"in"<<$$->token;
    }
#line 4944 "lalr1.tab.c"
    break;

  case 132: /* MethodHeader: VOID MethodDeclarator  */
#line 1718 "lalr1.y"
                              {
        (yyval.node)=new astnode;
        (yyval.node)->token="MethodHeader";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        symadd((yyvsp[0].node)->name,"void",(yyvsp[0].node)->value);
        (yyval.node)->type="void";
        // cout<<"in"<<$$->token;
    }
#line 4960 "lalr1.tab.c"
    break;

  case 133: /* MethodDeclarator: FunctionName OPEN_BR FormalParameterLists CLOSE_BR  */
#line 1731 "lalr1.y"
                                                          {
        (yyval.node)=new astnode;
        (yyval.node)->token="MethodDeclarator";
        vector<astnode*>v;
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->name=(yyvsp[-3].node)->name;
        (yyval.node)->value=(yyvsp[-1].node)->type;
        // cout<<"in"<<$$->token;
    }
#line 4978 "lalr1.tab.c"
    break;

  case 134: /* MethodDeclarator: FunctionName OPEN_BR CLOSE_BR  */
#line 1744 "lalr1.y"
                                      {
        (yyval.node)=new astnode;
        (yyval.node)->token="MethodDeclarator";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->name=(yyvsp[-2].node)->name;
        // cout<<"in"<<$$->token;
    }
#line 4994 "lalr1.tab.c"
    break;

  case 135: /* MethodDeclarator: MethodDeclarator OPEN_SQ CLOSE_SQ  */
#line 1755 "lalr1.y"
                                          {
        (yyval.node)=new astnode;
        (yyval.node)->token="MethodDeclarator";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->name=(yyvsp[-2].node)->name;
        (yyval.node)->value=(yyvsp[-2].node)->type;
        // cout<<"in"<<$$->token;
    }
#line 5011 "lalr1.tab.c"
    break;

  case 136: /* FunctionName: IDENTIFIER  */
#line 1769 "lalr1.y"
              {
        (yyval.node)=new astnode;
        (yyval.node)->token="FunctionName";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->name=(yyvsp[0].node)->lexeme;
        (yyval.node)->value=(yyvsp[0].node)->type;
        // cout<<"in"<<$$->token;
        string tac;
        tac="define "+cname+"."+(yyvsp[0].node)->lexeme+":";
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        fname="fname";
        // string tac;
        tac="return_addr = PC+1";
        tac=to_string(line++)+" "+tac;
        prog.push_back(tac);
        tac="push BP";
        tac=to_string(line++)+" "+tac;
        prog.push_back(tac);
        tac="BP = SP";
        tac=to_string(line++)+" "+tac;
        prog.push_back(tac);

    }
#line 5041 "lalr1.tab.c"
    break;

  case 137: /* FormalParameterLists: FormalParameterList  */
#line 1796 "lalr1.y"
                       {
        (yyval.node)=new astnode;
        (yyval.node)->token="FormalParameterLists";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->type=(yyvsp[0].node)->type;
        (yyval.node)->value=(yyvsp[0].node)->value;
        // cout<<"in"<<$$->token;
        string s=(yyvsp[0].node)->tac_val,tac;
        vector<string>token=split(s,',');
        tac="args_num "+to_string(token.size());
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        for(int i=token.size()-1;i>=0;i--) {
            tac="pop "+token[i];
            tac=to_string(line++)+" "+tac; prog.push_back(tac);
        }
        
    }
#line 5065 "lalr1.tab.c"
    break;

  case 138: /* FormalParameterList: FormalParameter  */
#line 1817 "lalr1.y"
                       {
        (yyval.node)=new astnode;
        (yyval.node)->token="FormalParameterList";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->type=(yyvsp[0].node)->type;
        (yyval.node)->value=(yyvsp[0].node)->value;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
    }
#line 5081 "lalr1.tab.c"
    break;

  case 139: /* FormalParameterList: FormalParameterList COMMA FormalParameter  */
#line 1828 "lalr1.y"
                                                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="FormalParameterList";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->type=(yyvsp[-2].node)->type+","+(yyvsp[0].node)->type;
        (yyval.node)->value=(yyvsp[-2].node)->value+","+(yyvsp[0].node)->value;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[-2].node)->tac_val+","+(yyvsp[0].node)->tac_val;
    }
#line 5099 "lalr1.tab.c"
    break;

  case 140: /* FormalParameter: Type VariableDeclaratorId  */
#line 1843 "lalr1.y"
                                 {
        (yyval.node)=new astnode;
        (yyval.node)->token="FormalParameter";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->type=(yyvsp[-1].node)->type;
        (yyval.node)->value=(yyvsp[0].node)->value;
        buffer[(yyvsp[0].node)->value]=(yyvsp[-1].node)->type;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyvsp[0].node)->type=(yyvsp[-1].node)->type;
    }
#line 5118 "lalr1.tab.c"
    break;

  case 141: /* Throws: THROWS ClassTypeList  */
#line 1859 "lalr1.y"
                            {
        (yyval.node)=new astnode;
        (yyval.node)->token="Throws";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5132 "lalr1.tab.c"
    break;

  case 142: /* ClassTypeList: ClassType  */
#line 1870 "lalr1.y"
                 {
        (yyval.node)=new astnode;
        (yyval.node)->token="ClassTypeList";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5145 "lalr1.tab.c"
    break;

  case 143: /* ClassTypeList: ClassTypeList COMMA ClassType  */
#line 1878 "lalr1.y"
                                      {
        (yyval.node)=new astnode;
        (yyval.node)->token="ClassTypeList";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5160 "lalr1.tab.c"
    break;

  case 144: /* MethodBody: Block  */
#line 1890 "lalr1.y"
              {
        (yyval.node)=new astnode;
        (yyval.node)->token="MethodBody";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5173 "lalr1.tab.c"
    break;

  case 145: /* MethodBody: SEMICOLON  */
#line 1898 "lalr1.y"
                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="MethodBody";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5186 "lalr1.tab.c"
    break;

  case 146: /* StaticInitializer: STATIC Block  */
#line 1909 "lalr1.y"
                    {
        (yyval.node)=new astnode;
        (yyval.node)->token="StaticInitializer";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5200 "lalr1.tab.c"
    break;

  case 147: /* ConstructorDeclaration: Modifiers ConstructorDeclarator Throws ConstructorBody  */
#line 1921 "lalr1.y"
                                                              {
        (yyval.node)=new astnode;
        (yyval.node)->token="ConstructorDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5216 "lalr1.tab.c"
    break;

  case 148: /* ConstructorDeclaration: Modifiers ConstructorDeclarator ConstructorBody  */
#line 1932 "lalr1.y"
                                                        {
        (yyval.node)=new astnode;
        (yyval.node)->token="ConstructorDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5231 "lalr1.tab.c"
    break;

  case 149: /* ConstructorDeclaration: ConstructorDeclarator Throws ConstructorBody  */
#line 1942 "lalr1.y"
                                                     {
        (yyval.node)=new astnode;
        (yyval.node)->token="ConstructorDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5246 "lalr1.tab.c"
    break;

  case 150: /* ConstructorDeclaration: ConstructorDeclarator ConstructorBody  */
#line 1952 "lalr1.y"
                                              {
        (yyval.node)=new astnode;
        (yyval.node)->token="ConstructorDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5260 "lalr1.tab.c"
    break;

  case 151: /* ConstructorDeclarator: ConstructorName OPEN_BR FormalParameterLists CLOSE_BR  */
#line 1964 "lalr1.y"
                                                             {
        (yyval.node)=new astnode;
        (yyval.node)->token="ConstructorDeclarator";
        vector<astnode*>v;
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        symadd((yyvsp[-3].node)->name,"constructor",(yyvsp[-1].node)->type);
        // cout<<"in"<<$$->token;
    }
#line 5277 "lalr1.tab.c"
    break;

  case 152: /* ConstructorDeclarator: ConstructorName OPEN_BR CLOSE_BR  */
#line 1976 "lalr1.y"
                                         {
        (yyval.node)=new astnode;
        (yyval.node)->token="ConstructorDeclarator";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        symadd((yyvsp[-2].node)->name,"constructor");
        // cout<<"in"<<$$->token;
    }
#line 5293 "lalr1.tab.c"
    break;

  case 153: /* ConstructorName: SingularName  */
#line 1989 "lalr1.y"
                {
        (yyval.node)=new astnode;
        (yyval.node)->token="ConstructorName";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->name=(yyvsp[0].node)->value;
        // $$->value=$1->type;
        // cout<<"in"<<$$->token;
        if(cname!=(yyvsp[0].node)->tac_val) cout<<"Invalid cunstructor name";
        string tac;
        tac="define "+cname+"."+"ctor"+":";
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
    }
#line 5312 "lalr1.tab.c"
    break;

  case 154: /* ConstructorBody: OPEN_CR SYMTABS ExplicitConstructorInvocation BlockStatements CLOSE_CR SYMTABE  */
#line 2005 "lalr1.y"
                                                                                      {
        (yyval.node)=new astnode;
        (yyval.node)->token="ConstructorBody";
        vector<astnode*>v;
        v.push_back((yyvsp[-5].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5328 "lalr1.tab.c"
    break;

  case 155: /* ConstructorBody: OPEN_CR SYMTABS ExplicitConstructorInvocation CLOSE_CR SYMTABE  */
#line 2016 "lalr1.y"
                                                                       {
        (yyval.node)=new astnode;
        (yyval.node)->token="ConstructorBody";
        vector<astnode*>v;
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5343 "lalr1.tab.c"
    break;

  case 156: /* ConstructorBody: OPEN_CR SYMTABS BlockStatements CLOSE_CR SYMTABE  */
#line 2026 "lalr1.y"
                                                         {
        (yyval.node)=new astnode;
        (yyval.node)->token="ConstructorBody";
        vector<astnode*>v;
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5358 "lalr1.tab.c"
    break;

  case 157: /* ConstructorBody: OPEN_CR CLOSE_CR  */
#line 2036 "lalr1.y"
                          {
        (yyval.node)=new astnode;
        (yyval.node)->token="ConstructorBody";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5372 "lalr1.tab.c"
    break;

  case 158: /* ExplicitConstructorInvocation: THIS OPEN_BR ArgumentList CLOSE_BR SEMICOLON  */
#line 2047 "lalr1.y"
                                                    {
        (yyval.node)=new astnode;
        (yyval.node)->token="ExplicitConstructorInvocation";
        vector<astnode*>v;
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5389 "lalr1.tab.c"
    break;

  case 159: /* ExplicitConstructorInvocation: THIS OPEN_BR CLOSE_BR SEMICOLON  */
#line 2059 "lalr1.y"
                                        {
        (yyval.node)=new astnode;
        (yyval.node)->token="ExplicitConstructorInvocation";
        vector<astnode*>v;
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5405 "lalr1.tab.c"
    break;

  case 160: /* ExplicitConstructorInvocation: SUPER OPEN_BR ArgumentList CLOSE_BR SEMICOLON  */
#line 2070 "lalr1.y"
                                                      {
        (yyval.node)=new astnode;
        (yyval.node)->token="ExplicitConstructorInvocation";
        vector<astnode*>v;
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5422 "lalr1.tab.c"
    break;

  case 161: /* ExplicitConstructorInvocation: SUPER OPEN_BR CLOSE_BR SEMICOLON  */
#line 2082 "lalr1.y"
                                         {
        (yyval.node)=new astnode;
        (yyval.node)->token="ExplicitConstructorInvocation";
        vector<astnode*>v;
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5438 "lalr1.tab.c"
    break;

  case 162: /* InterfaceDeclaration: Modifiers INTERFACE IDENTIFIER ExtendsInterfaces InterfaceBody  */
#line 2096 "lalr1.y"
                                                                      {
        (yyval.node)=new astnode;
        (yyval.node)->token="InterfaceDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5455 "lalr1.tab.c"
    break;

  case 163: /* InterfaceDeclaration: Modifiers INTERFACE IDENTIFIER InterfaceBody  */
#line 2108 "lalr1.y"
                                                     {
        (yyval.node)=new astnode;
        (yyval.node)->token="InterfaceDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5471 "lalr1.tab.c"
    break;

  case 164: /* InterfaceDeclaration: INTERFACE IDENTIFIER ExtendsInterfaces InterfaceBody  */
#line 2119 "lalr1.y"
                                                             {
        (yyval.node)=new astnode;
        (yyval.node)->token="InterfaceDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5487 "lalr1.tab.c"
    break;

  case 165: /* InterfaceDeclaration: INTERFACE IDENTIFIER InterfaceBody  */
#line 2130 "lalr1.y"
                                           {
        (yyval.node)=new astnode;
        (yyval.node)->token="InterfaceDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5502 "lalr1.tab.c"
    break;

  case 166: /* ExtendsInterfaces: EXTENDS InterfaceType  */
#line 2142 "lalr1.y"
                             {
        (yyval.node)=new astnode;
        (yyval.node)->token="ExtendsInterfaces";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5516 "lalr1.tab.c"
    break;

  case 167: /* ExtendsInterfaces: ExtendsInterfaces COMMA InterfaceType  */
#line 2151 "lalr1.y"
                                              {
        (yyval.node)=new astnode;
        (yyval.node)->token="ExtendsInterfaces";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5531 "lalr1.tab.c"
    break;

  case 168: /* InterfaceBody: OPEN_CR SYMTABS InterfaceMemberDeclarations CLOSE_CR SYMTABE  */
#line 2163 "lalr1.y"
                                                                    {
        (yyval.node)=new astnode;
        (yyval.node)->token="InterfaceBody";
        vector<astnode*>v;
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5546 "lalr1.tab.c"
    break;

  case 169: /* InterfaceBody: OPEN_CR CLOSE_CR  */
#line 2173 "lalr1.y"
                          {
        (yyval.node)=new astnode;
        (yyval.node)->token="InterfaceBody";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5560 "lalr1.tab.c"
    break;

  case 170: /* InterfaceMemberDeclarations: InterfaceMemberDeclaration  */
#line 2184 "lalr1.y"
                                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="InterfaceMemberDeclarations";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5573 "lalr1.tab.c"
    break;

  case 171: /* InterfaceMemberDeclarations: InterfaceMemberDeclarations InterfaceMemberDeclaration  */
#line 2192 "lalr1.y"
                                                               {
        (yyval.node)=new astnode;
        (yyval.node)->token="InterfaceMemberDeclarations";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5587 "lalr1.tab.c"
    break;

  case 172: /* InterfaceMemberDeclaration: ConstantDeclaration  */
#line 2203 "lalr1.y"
                           {
        (yyval.node)=new astnode;
        (yyval.node)->token="InterfaceMemberDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5600 "lalr1.tab.c"
    break;

  case 173: /* InterfaceMemberDeclaration: AbstractMethodDeclaration  */
#line 2211 "lalr1.y"
                                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="InterfaceMemberDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5613 "lalr1.tab.c"
    break;

  case 174: /* ConstantDeclaration: FieldDeclaration  */
#line 2221 "lalr1.y"
                        {
        (yyval.node)=new astnode;
        (yyval.node)->token="ConstantDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5626 "lalr1.tab.c"
    break;

  case 175: /* AbstractMethodDeclaration: MethodHeader SEMICOLON  */
#line 2231 "lalr1.y"
                              {
        (yyval.node)=new astnode;
        (yyval.node)->token="AbstractMethodDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5640 "lalr1.tab.c"
    break;

  case 176: /* ArrayInitializer: OPEN_CR SYMTABS VariableInitializers COMMA CLOSE_CR SYMTABE  */
#line 2243 "lalr1.y"
                                                                   {
        (yyval.node)=new astnode;
        (yyval.node)->token="ArrayInitializer";
        vector<astnode*>v;
        v.push_back((yyvsp[-5].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        string s=(yyvsp[-3].node)->tac_val;
        if(temp_type=="ud") temp_type=(yyvsp[-3].node)->type;
        vector<string>token=split(s,',');
        string tac,temp1=get_tempvar();
        tac="Lcall_Alloc\n"; tac=tac+to_string(line++)+" ";
        tac=tac+temp1+" = "+temp_type+"["+to_string(token.size())+"]";
        (yyval.node)->tac_val=tac;
        (yyval.node)->flag=4;
        (yyval.node)->length=token.size();
        (yyval.node)->value=(yyvsp[-3].node)->value;
        // $$->tuples=token;
        (yyval.node)->type=(yyvsp[-3].node)->type;
        (yyval.node)->dims=(yyvsp[-3].node)->dims+1;
        (yyval.node)->space=(yyvsp[-3].node)->space;
        // cout<<"Dims: "<<$$->dims;
// Type check kardo idhar
    }
#line 5672 "lalr1.tab.c"
    break;

  case 177: /* ArrayInitializer: OPEN_CR SYMTABS VariableInitializers CLOSE_CR SYMTABE  */
#line 2270 "lalr1.y"
                                                              {
        (yyval.node)=new astnode;
        (yyval.node)->token="ArrayInitializer";
        vector<astnode*>v;
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        string s=(yyvsp[-2].node)->tac_val;
        vector<string>token=split(s,',');
        if(temp_type=="ud") temp_type=(yyvsp[-2].node)->type;
        string tac,temp=get_tempvar();
        tac="Lcall_Alloc\n"; tac=tac+to_string(line++)+" ";
        tac=tac+temp+" = "+temp_type+"["+to_string(token.size())+"]";
        (yyval.node)->tac_val=tac;
        (yyval.node)->flag=4;
        (yyval.node)->length=token.size();
        (yyval.node)->value=(yyvsp[-2].node)->value;
        // $$->tuples=token;
        (yyval.node)->type=(yyvsp[-2].node)->type;
        (yyval.node)->dims=(yyvsp[-2].node)->dims+1;
        (yyval.node)->space=(yyvsp[-2].node)->space;
        // cout<<"Dims: "<<$$->dims;
    }
#line 5702 "lalr1.tab.c"
    break;

  case 178: /* ArrayInitializer: OPEN_CR COMMA CLOSE_CR  */
#line 2295 "lalr1.y"
                               {
        (yyval.node)=new astnode;
        (yyval.node)->token="ArrayInitializer";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        string tac,temp=get_tempvar();
        tac="Lcall_Alloc\n"; tac=tac+to_string(line++)+" ";
        tac=tac+temp+" = "+temp_type+"[1]";
        (yyval.node)->tac_val=tac;
        (yyval.node)->flag=4;
        (yyval.node)->length=0;
        (yyval.node)->type="nd";
        (yyval.node)->dims=1;
        (yyval.node)->value=",";
        // $$->tuples=NULL;
    }
#line 5727 "lalr1.tab.c"
    break;

  case 179: /* ArrayInitializer: OPEN_CR CLOSE_CR  */
#line 2315 "lalr1.y"
                         {
        (yyval.node)=new astnode;
        (yyval.node)->token="ArrayInitializer";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        string tac,temp=get_tempvar();
        tac="Lcall_Alloc\n"; tac=tac+to_string(line++)+" ";
        tac=tac+temp+" = "+temp_type+"[0]";
        (yyval.node)->tac_val=tac;
        (yyval.node)->flag=4;
        (yyval.node)->length=0;
        (yyval.node)->type="nd";
        (yyval.node)->dims=1;
        (yyval.node)->value="";
        // $$->tuples=NULL;
    }
#line 5751 "lalr1.tab.c"
    break;

  case 180: /* VariableInitializers: VariableInitializer  */
#line 2336 "lalr1.y"
                           {
        (yyval.node)=new astnode;
        (yyval.node)->token="VariableInitializers";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->type=(yyvsp[0].node)->type;
        // $$->length=$1->length;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
        (yyval.node)->space=(yyvsp[0].node)->space;
        (yyval.node)->length=(yyvsp[0].node)->length;
        (yyval.node)->value=(yyvsp[0].node)->tac_val;
        // $$->tuples=$1->tuples;
        // cout<<"in VariableInitializer Length: "<<$$->length<<" Space:"<<$$->space;
    }
#line 5773 "lalr1.tab.c"
    break;

  case 181: /* VariableInitializers: VariableInitializers COMMA VariableInitializer  */
#line 2353 "lalr1.y"
                                                       {
        (yyval.node)=new astnode;
        (yyval.node)->token="VariableInitializers";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[-2].node)->tac_val+","+(yyvsp[0].node)->tac_val;
        temp=symtypeEvaluate((yyvsp[-2].node)->type,(yyvsp[0].node)->type);
        // cout<<"\n"<<$1->type<<" "<<$3->type;
        if(temp=="0")
        {
            //uncomment
            cout<<"Error, type mismatch in array initializer";
        }
        (yyval.node)->type=temp;
        (yyval.node)->dims=(yyvsp[-2].node)->dims;
        if(((yyvsp[-2].node)->length!=(yyvsp[0].node)->length)||((yyvsp[-2].node)->dims!=(yyvsp[0].node)->dims)){
            cout<<"Unequal length elements appended";
        }
        (yyval.node)->length=(yyvsp[-2].node)->length;
        (yyval.node)->space=(yyvsp[-2].node)->space+(yyvsp[0].node)->space;
        (yyval.node)->value=(yyval.node)->tac_val;
        // cout<<"in VariableInitializers Length: "<<$$->length<<" Space:"<<$$->space;
    }
#line 5805 "lalr1.tab.c"
    break;

  case 182: /* Block: OPEN_CR CLOSE_CR  */
#line 2385 "lalr1.y"
                     {
        (yyval.node)=new astnode;
        (yyval.node)->token="Block";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5819 "lalr1.tab.c"
    break;

  case 183: /* Block: OPEN_CR SYMTABS BlockStatements CLOSE_CR SYMTABE  */
#line 2394 "lalr1.y"
                                                      {
        (yyval.node)=new astnode;
        (yyval.node)->token="Block";
        vector<astnode*>v;
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5834 "lalr1.tab.c"
    break;

  case 184: /* BlockStatements: BlockStatement  */
#line 2406 "lalr1.y"
                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="BlockStatements";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5847 "lalr1.tab.c"
    break;

  case 185: /* BlockStatements: BlockStatements BlockStatement  */
#line 2414 "lalr1.y"
                                    {
        (yyval.node)=new astnode;
        (yyval.node)->token="BlockStatements";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5861 "lalr1.tab.c"
    break;

  case 186: /* BlockStatement: LocalVariableDeclarationStatement  */
#line 2425 "lalr1.y"
                                     {
        (yyval.node)=new astnode;
        (yyval.node)->token="BlockStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        if((yyvsp[0].node)->type!="ud"){
        string s=(yyvsp[0].node)->value;
        vector<string>tokens=split(s,',');
        symadd_list(tokens,(yyvsp[0].node)->type);
        if((yyvsp[0].node)->flag==4) {
            symadd(s,(yyvsp[0].node)->type,(yyvsp[0].node)->dims);
        }
        }
    }
#line 5882 "lalr1.tab.c"
    break;

  case 187: /* BlockStatement: Statement  */
#line 2441 "lalr1.y"
               {
        (yyval.node)=new astnode;
        (yyval.node)->token="BlockStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        // cout<<"in"<<$$->token;
    }
#line 5896 "lalr1.tab.c"
    break;

  case 188: /* LocalVariableDeclarationStatement: LocalVariableDeclaration SEMICOLON  */
#line 2452 "lalr1.y"
                                      {
        (yyval.node)=new astnode;
        (yyval.node)->token="LocalVariableDeclarationStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->value=(yyvsp[-1].node)->value;
        (yyval.node)->type=(yyvsp[-1].node)->type;
        (yyval.node)->flag=(yyvsp[-1].node)->flag;
        (yyval.node)->dims=(yyvsp[-1].node)->dims;
    }
#line 5914 "lalr1.tab.c"
    break;

  case 189: /* LocalVariableDeclaration: Type VariableDeclarators  */
#line 2467 "lalr1.y"
                            {
        (yyval.node)=new astnode;
        (yyval.node)->token="LocalVariableDeclaration";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->value=(yyvsp[0].node)->value;
        (yyval.node)->type=(yyvsp[-1].node)->type;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
        // string s=$2->value;
        // vector<string>tokens=split(s,',');
        // symadd_list(tokens,$1->type);
    }
#line 5935 "lalr1.tab.c"
    break;

  case 190: /* Statement: StatementWithoutTrailingSubstatement  */
#line 2485 "lalr1.y"
                                        {
        (yyval.node)=new astnode;
        (yyval.node)->token="Statement";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        // cout<<"in"<<$$->token;
    }
#line 5949 "lalr1.tab.c"
    break;

  case 191: /* Statement: LabeledStatement  */
#line 2494 "lalr1.y"
                      {
        (yyval.node)=new astnode;
        (yyval.node)->token="Statement";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5962 "lalr1.tab.c"
    break;

  case 192: /* Statement: IfThenStatement  */
#line 2502 "lalr1.y"
                     {
        (yyval.node)=new astnode;
        (yyval.node)->token="Statement";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5975 "lalr1.tab.c"
    break;

  case 193: /* Statement: IfThenElseStatement  */
#line 2510 "lalr1.y"
                         {
        (yyval.node)=new astnode;
        (yyval.node)->token="Statement";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 5988 "lalr1.tab.c"
    break;

  case 194: /* Statement: WhileStatement  */
#line 2518 "lalr1.y"
                    {
        (yyval.node)=new astnode;
        (yyval.node)->token="Statement";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6001 "lalr1.tab.c"
    break;

  case 195: /* Statement: ForStatement  */
#line 2526 "lalr1.y"
                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="Statement";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6014 "lalr1.tab.c"
    break;

  case 196: /* StatementNoShortIf: StatementWithoutTrailingSubstatement  */
#line 2536 "lalr1.y"
                                        {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementNoShortIf";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6027 "lalr1.tab.c"
    break;

  case 197: /* StatementNoShortIf: LabeledStatementNoShortIf  */
#line 2544 "lalr1.y"
                               {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementNoShortIf";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6040 "lalr1.tab.c"
    break;

  case 198: /* StatementNoShortIf: IfThenElseStatementNoShortIf  */
#line 2552 "lalr1.y"
                                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementNoShortIf";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6053 "lalr1.tab.c"
    break;

  case 199: /* StatementNoShortIf: WhileStatementNoShortIf  */
#line 2560 "lalr1.y"
                             {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementNoShortIf";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6066 "lalr1.tab.c"
    break;

  case 200: /* StatementNoShortIf: ForStatementNoShortIf  */
#line 2568 "lalr1.y"
                           {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementNoShortIf";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6079 "lalr1.tab.c"
    break;

  case 201: /* StatementWithoutTrailingSubstatement: Block  */
#line 2578 "lalr1.y"
         {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementWithoutTrailingSubstatement";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6092 "lalr1.tab.c"
    break;

  case 202: /* StatementWithoutTrailingSubstatement: EmptyStatement  */
#line 2586 "lalr1.y"
                    {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementWithoutTrailingSubstatement";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6105 "lalr1.tab.c"
    break;

  case 203: /* StatementWithoutTrailingSubstatement: ExpressionStatement  */
#line 2594 "lalr1.y"
                         {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementWithoutTrailingSubstatement";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        // cout<<"in"<<$$->token;
    }
#line 6119 "lalr1.tab.c"
    break;

  case 204: /* StatementWithoutTrailingSubstatement: SwitchStatement  */
#line 2603 "lalr1.y"
                     {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementWithoutTrailingSubstatement";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6132 "lalr1.tab.c"
    break;

  case 205: /* StatementWithoutTrailingSubstatement: DoStatement  */
#line 2611 "lalr1.y"
                 {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementWithoutTrailingSubstatement";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6145 "lalr1.tab.c"
    break;

  case 206: /* StatementWithoutTrailingSubstatement: BreakStatement  */
#line 2619 "lalr1.y"
                    {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementWithoutTrailingSubstatement";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6158 "lalr1.tab.c"
    break;

  case 207: /* StatementWithoutTrailingSubstatement: ContinueStatement  */
#line 2627 "lalr1.y"
                       {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementWithoutTrailingSubstatement";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6171 "lalr1.tab.c"
    break;

  case 208: /* StatementWithoutTrailingSubstatement: ReturnStatement  */
#line 2635 "lalr1.y"
                     {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementWithoutTrailingSubstatement";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6184 "lalr1.tab.c"
    break;

  case 209: /* StatementWithoutTrailingSubstatement: SynchronizedStatement  */
#line 2643 "lalr1.y"
                           {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementWithoutTrailingSubstatement";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6197 "lalr1.tab.c"
    break;

  case 210: /* StatementWithoutTrailingSubstatement: ThrowStatement  */
#line 2651 "lalr1.y"
                    {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementWithoutTrailingSubstatement";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6210 "lalr1.tab.c"
    break;

  case 211: /* StatementWithoutTrailingSubstatement: TryStatement  */
#line 2659 "lalr1.y"
                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementWithoutTrailingSubstatement";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6223 "lalr1.tab.c"
    break;

  case 212: /* EmptyStatement: SEMICOLON  */
#line 2669 "lalr1.y"
             {
        (yyval.node)=new astnode;
        (yyval.node)->token="EmptyStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6236 "lalr1.tab.c"
    break;

  case 213: /* LabeledStatement: IDENTIFIER COLON Statement  */
#line 2679 "lalr1.y"
                              {
        (yyval.node)=new astnode;
        (yyval.node)->token="LabeledStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        string tac,topush_label=get_label();
        tac=topush_label+":";
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        m[(yyvsp[-2].node)->lexeme]=topush_label;
    }
#line 6255 "lalr1.tab.c"
    break;

  case 214: /* LabeledStatementNoShortIf: IDENTIFIER COLON StatementNoShortIf  */
#line 2695 "lalr1.y"
                                       {
        (yyval.node)=new astnode;
        (yyval.node)->token="LabeledStatementNoShortIf";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        string tac,topush_label=get_label();
        tac=topush_label+":";
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        m[(yyvsp[-2].node)->lexeme]=topush_label;
    }
#line 6274 "lalr1.tab.c"
    break;

  case 215: /* ExpressionStatement: StatementExpression SEMICOLON  */
#line 2711 "lalr1.y"
                                 {
        (yyval.node)=new astnode;
        (yyval.node)->token="ExpressionStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[-1].node)->tac_val;
        (yyval.node)->type=(yyvsp[-1].node)->type;
    }
#line 6290 "lalr1.tab.c"
    break;

  case 216: /* StatementExpression: Assignment  */
#line 2724 "lalr1.y"
              {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 6305 "lalr1.tab.c"
    break;

  case 217: /* StatementExpression: PreIncrementExpression  */
#line 2734 "lalr1.y"
                            {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 6320 "lalr1.tab.c"
    break;

  case 218: /* StatementExpression: PreDecrementExpression  */
#line 2744 "lalr1.y"
                            {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 6335 "lalr1.tab.c"
    break;

  case 219: /* StatementExpression: PostIncrementExpression  */
#line 2754 "lalr1.y"
                             {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 6350 "lalr1.tab.c"
    break;

  case 220: /* StatementExpression: PostDecrementExpression  */
#line 2764 "lalr1.y"
                             {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 6365 "lalr1.tab.c"
    break;

  case 221: /* StatementExpression: MethodInvocation  */
#line 2774 "lalr1.y"
                      {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->type=(yyvsp[0].node)->type;
        prog.push_back((yyvsp[0].node)->tac_val);
    }
#line 6381 "lalr1.tab.c"
    break;

  case 222: /* StatementExpression: ClassInstanceCreationExpression  */
#line 2785 "lalr1.y"
                                     {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 6396 "lalr1.tab.c"
    break;

  case 223: /* StatementExpression: PrintStatement  */
#line 2795 "lalr1.y"
                    {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->type=(yyvsp[0].node)->type;
        // cout<<"in StatementExpression";
    }
#line 6412 "lalr1.tab.c"
    break;

  case 224: /* IfThenStatement: IF OPEN_BR Expression CLOSE_BR IFMARK1 Statement IFEND1  */
#line 2808 "lalr1.y"
                                                            { 
        (yyval.node)=new astnode;
        (yyval.node)->token="IfThenStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-6].node));
        v.push_back((yyvsp[-5].node));
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6429 "lalr1.tab.c"
    break;

  case 225: /* IfThenElseStatement: IF OPEN_BR Expression CLOSE_BR IFMARK1 StatementNoShortIf IFEND2 ELSE ELSEMARK1 Statement ELSEEND1  */
#line 2822 "lalr1.y"
                                                                                                      {
        (yyval.node)=new astnode;
        (yyval.node)->token="IfThenElseStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-10].node));
        v.push_back((yyvsp[-9].node));
        v.push_back((yyvsp[-8].node));
        v.push_back((yyvsp[-7].node));
        v.push_back((yyvsp[-5].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6448 "lalr1.tab.c"
    break;

  case 226: /* IfThenElseStatementNoShortIf: IF OPEN_BR Expression CLOSE_BR IFMARK1 StatementNoShortIf IFEND2 ELSE ELSEMARK1 StatementNoShortIf ELSEEND1  */
#line 2838 "lalr1.y"
                                                                                                               {
        (yyval.node)=new astnode;
        (yyval.node)->token="IfThenElseStatementNoShortIf";
        vector<astnode*>v;
        v.push_back((yyvsp[-10].node));
        v.push_back((yyvsp[-9].node));
        v.push_back((yyvsp[-8].node));
        v.push_back((yyvsp[-7].node));
        v.push_back((yyvsp[-5].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6467 "lalr1.tab.c"
    break;

  case 227: /* SwitchStatement: SWITCH OPEN_BR Expression CLOSE_BR SwitchBlock  */
#line 2854 "lalr1.y"
                                                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="SwitchStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6484 "lalr1.tab.c"
    break;

  case 228: /* SwitchBlock: OPEN_CR CLOSE_CR  */
#line 2868 "lalr1.y"
                     {
        (yyval.node)=new astnode;
        (yyval.node)->token="SwitchBlock";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6498 "lalr1.tab.c"
    break;

  case 229: /* SwitchBlock: OPEN_CR SYMTABS SwitchBlockStatementGroups CLOSE_CR SYMTABE  */
#line 2877 "lalr1.y"
                                                                {
        (yyval.node)=new astnode;
        (yyval.node)->token="SwitchBlock";
        vector<astnode*>v;
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6513 "lalr1.tab.c"
    break;

  case 230: /* SwitchBlock: OPEN_CR SYMTABS SwitchLabels CLOSE_CR SYMTABE  */
#line 2887 "lalr1.y"
                                                   {
        (yyval.node)=new astnode;
        (yyval.node)->token="SwitchBlock";
        vector<astnode*>v;
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6528 "lalr1.tab.c"
    break;

  case 231: /* SwitchBlock: OPEN_CR SYMTABS SwitchBlockStatementGroups SwitchLabels CLOSE_CR SYMTABE  */
#line 2897 "lalr1.y"
                                                                             {
        (yyval.node)=new astnode;
        (yyval.node)->token="SwitchBlock";
        vector<astnode*>v;
        v.push_back((yyvsp[-5].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6544 "lalr1.tab.c"
    break;

  case 232: /* SwitchBlockStatementGroups: SwitchBlockStatementGroup  */
#line 2910 "lalr1.y"
                             {
        (yyval.node)=new astnode;
        (yyval.node)->token="SwitchBlockStatementGroups";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6557 "lalr1.tab.c"
    break;

  case 233: /* SwitchBlockStatementGroups: SwitchBlockStatementGroups SwitchBlockStatementGroup  */
#line 2918 "lalr1.y"
                                                          {
        (yyval.node)=new astnode;
        (yyval.node)->token="SwitchBlockStatementGroups";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6571 "lalr1.tab.c"
    break;

  case 234: /* SwitchBlockStatementGroup: SwitchLabels BlockStatements  */
#line 2929 "lalr1.y"
                                {
        (yyval.node)=new astnode;
        (yyval.node)->token="SwitchBlockStatementGroup";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6585 "lalr1.tab.c"
    break;

  case 235: /* SwitchLabels: SwitchLabel  */
#line 2940 "lalr1.y"
               {
        (yyval.node)=new astnode;
        (yyval.node)->token="SwitchLabels";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6598 "lalr1.tab.c"
    break;

  case 236: /* SwitchLabels: SwitchLabels SwitchLabel  */
#line 2948 "lalr1.y"
                              {
        (yyval.node)=new astnode;
        (yyval.node)->token="SwitchLabels";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6612 "lalr1.tab.c"
    break;

  case 237: /* SwitchLabel: CASE ConstantExpression COLON  */
#line 2959 "lalr1.y"
                                 {
        (yyval.node)=new astnode;
        (yyval.node)->token="SwitchLabel";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6627 "lalr1.tab.c"
    break;

  case 238: /* SwitchLabel: DEFAULT COLON  */
#line 2969 "lalr1.y"
                   {
        (yyval.node)=new astnode;
        (yyval.node)->token="SwitchLabel";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6641 "lalr1.tab.c"
    break;

  case 239: /* WhileStatement: WHILE WHILEMARK2 OPEN_BR Expression CLOSE_BR WHILEMARK1 Statement WHILEEND1  */
#line 2980 "lalr1.y"
                                                                               {
        (yyval.node)=new astnode;
        (yyval.node)->token="WhileStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-7].node));
        v.push_back((yyvsp[-5].node));
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6658 "lalr1.tab.c"
    break;

  case 240: /* WhileStatementNoShortIf: WHILE WHILEMARK2 OPEN_BR Expression CLOSE_BR WHILEMARK1 StatementNoShortIf WHILEEND1  */
#line 2994 "lalr1.y"
                                                                                        {
        (yyval.node)=new astnode;
        (yyval.node)->token="WhileStatementNoShortIf";
        vector<astnode*>v;
        v.push_back((yyvsp[-7].node));
        v.push_back((yyvsp[-5].node));
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6675 "lalr1.tab.c"
    break;

  case 241: /* DoStatement: DO DOMARK1 Statement WHILE OPEN_BR Expression CLOSE_BR SEMICOLON DOEND1  */
#line 3008 "lalr1.y"
                                                                           {
        (yyval.node)=new astnode;
        (yyval.node)->token="DoStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-8].node));
        v.push_back((yyvsp[-6].node));
        v.push_back((yyvsp[-5].node));
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6694 "lalr1.tab.c"
    break;

  case 242: /* ForStatement: FOR OPEN_BR FORMARK1 SEMICOLON FORMARK2 SEMICOLON CLOSE_BR FORMARK3 Statement FOREND1  */
#line 3024 "lalr1.y"
                                                                                         {
        (yyval.node)=new astnode;
        (yyval.node)->token="ForStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-9].node));
        v.push_back((yyvsp[-8].node));
        v.push_back((yyvsp[-6].node));
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6712 "lalr1.tab.c"
    break;

  case 243: /* ForStatement: FOR OPEN_BR FORMARK1 SEMICOLON FORMARK2 SEMICOLON ForUpdate CLOSE_BR FORMARK3 Statement FOREND1  */
#line 3037 "lalr1.y"
                                                                                                     {
        (yyval.node)=new astnode;
        (yyval.node)->token="ForStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-10].node));
        v.push_back((yyvsp[-9].node));
        v.push_back((yyvsp[-7].node));
        v.push_back((yyvsp[-5].node));
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6731 "lalr1.tab.c"
    break;

  case 244: /* ForStatement: FOR OPEN_BR FORMARK1 SEMICOLON Expression FORMARK2 SEMICOLON CLOSE_BR FORMARK3 Statement FOREND1  */
#line 3051 "lalr1.y"
                                                                                                      {
        (yyval.node)=new astnode;
        (yyval.node)->token="ForStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-10].node));
        v.push_back((yyvsp[-9].node));
        v.push_back((yyvsp[-7].node));
        v.push_back((yyvsp[-6].node));
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6750 "lalr1.tab.c"
    break;

  case 245: /* ForStatement: FOR OPEN_BR FORMARK1 SEMICOLON Expression FORMARK2 SEMICOLON ForUpdate CLOSE_BR FORMARK3 Statement FOREND1  */
#line 3065 "lalr1.y"
                                                                                                                {
        (yyval.node)=new astnode;
        (yyval.node)->token="ForStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-11].node));
        v.push_back((yyvsp[-10].node));
        v.push_back((yyvsp[-8].node));
        v.push_back((yyvsp[-7].node));
        v.push_back((yyvsp[-5].node));
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6770 "lalr1.tab.c"
    break;

  case 246: /* ForStatement: FOR OPEN_BR ForInit FORMARK1 SEMICOLON FORMARK2 SEMICOLON CLOSE_BR FORMARK3 Statement FOREND1  */
#line 3080 "lalr1.y"
                                                                                                   {
        (yyval.node)=new astnode;
        (yyval.node)->token="ForStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-10].node));
        v.push_back((yyvsp[-9].node));
        v.push_back((yyvsp[-8].node));
        v.push_back((yyvsp[-6].node));
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6789 "lalr1.tab.c"
    break;

  case 247: /* ForStatement: FOR OPEN_BR ForInit FORMARK1 SEMICOLON FORMARK2 SEMICOLON ForUpdate CLOSE_BR FORMARK3 Statement FOREND1  */
#line 3094 "lalr1.y"
                                                                                                             {
        (yyval.node)=new astnode;
        (yyval.node)->token="ForStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-11].node));
        v.push_back((yyvsp[-10].node));
        v.push_back((yyvsp[-9].node));
        v.push_back((yyvsp[-7].node));
        v.push_back((yyvsp[-5].node));
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6809 "lalr1.tab.c"
    break;

  case 248: /* ForStatement: FOR OPEN_BR ForInit FORMARK1 SEMICOLON Expression FORMARK2 SEMICOLON CLOSE_BR FORMARK3 Statement FOREND1  */
#line 3109 "lalr1.y"
                                                                                                              {
        (yyval.node)=new astnode;
        (yyval.node)->token="ForStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-11].node));
        v.push_back((yyvsp[-10].node));
        v.push_back((yyvsp[-9].node));
        v.push_back((yyvsp[-7].node));
        v.push_back((yyvsp[-6].node));
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6829 "lalr1.tab.c"
    break;

  case 249: /* ForStatement: FOR OPEN_BR ForInit FORMARK1 SEMICOLON Expression FORMARK2 SEMICOLON ForUpdate CLOSE_BR FORMARK3 Statement FOREND1  */
#line 3124 "lalr1.y"
                                                                                                                        {
        (yyval.node)=new astnode;
        (yyval.node)->token="ForStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-12].node));
        v.push_back((yyvsp[-11].node));
        v.push_back((yyvsp[-10].node));
        v.push_back((yyvsp[-8].node));
        v.push_back((yyvsp[-7].node));
        v.push_back((yyvsp[-5].node));
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6850 "lalr1.tab.c"
    break;

  case 250: /* ForStatementNoShortIf: FOR OPEN_BR FORMARK1 SEMICOLON FORMARK2 SEMICOLON CLOSE_BR FORMARK3 StatementNoShortIf FOREND1  */
#line 3142 "lalr1.y"
                                                                                                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="ForStatementNoShortIf";
        vector<astnode*>v;
        v.push_back((yyvsp[-9].node));
        v.push_back((yyvsp[-8].node));
        v.push_back((yyvsp[-6].node));
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6868 "lalr1.tab.c"
    break;

  case 251: /* ForStatementNoShortIf: FOR OPEN_BR FORMARK1 SEMICOLON FORMARK2 SEMICOLON ForUpdate CLOSE_BR FORMARK3 StatementNoShortIf FOREND1  */
#line 3155 "lalr1.y"
                                                                                                              {
        (yyval.node)=new astnode;
        (yyval.node)->token="ForStatementNoShortIf";
        vector<astnode*>v;
        v.push_back((yyvsp[-10].node));
        v.push_back((yyvsp[-9].node));
        v.push_back((yyvsp[-7].node));
        v.push_back((yyvsp[-5].node));
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6887 "lalr1.tab.c"
    break;

  case 252: /* ForStatementNoShortIf: FOR OPEN_BR FORMARK1 SEMICOLON Expression FORMARK2 SEMICOLON CLOSE_BR FORMARK3 StatementNoShortIf FOREND1  */
#line 3169 "lalr1.y"
                                                                                                               {
        (yyval.node)=new astnode;
        (yyval.node)->token="ForStatementNoShortIf";
        vector<astnode*>v;
        v.push_back((yyvsp[-10].node));
        v.push_back((yyvsp[-9].node));
        v.push_back((yyvsp[-7].node));
        v.push_back((yyvsp[-6].node));
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6906 "lalr1.tab.c"
    break;

  case 253: /* ForStatementNoShortIf: FOR OPEN_BR FORMARK1 SEMICOLON Expression FORMARK2 SEMICOLON ForUpdate CLOSE_BR FORMARK3 StatementNoShortIf FOREND1  */
#line 3183 "lalr1.y"
                                                                                                                         {
        (yyval.node)=new astnode;
        (yyval.node)->token="ForStatementNoShortIf";
        vector<astnode*>v;
        v.push_back((yyvsp[-11].node));
        v.push_back((yyvsp[-10].node));
        v.push_back((yyvsp[-8].node));
        v.push_back((yyvsp[-7].node));
        v.push_back((yyvsp[-5].node));
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6926 "lalr1.tab.c"
    break;

  case 254: /* ForStatementNoShortIf: FOR OPEN_BR ForInit FORMARK1 SEMICOLON FORMARK2 SEMICOLON CLOSE_BR FORMARK3 StatementNoShortIf FOREND1  */
#line 3198 "lalr1.y"
                                                                                                            {
        (yyval.node)=new astnode;
        (yyval.node)->token="ForStatementNoShortIf";
        vector<astnode*>v;
        v.push_back((yyvsp[-10].node));
        v.push_back((yyvsp[-9].node));
        v.push_back((yyvsp[-8].node));
        v.push_back((yyvsp[-6].node));
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6945 "lalr1.tab.c"
    break;

  case 255: /* ForStatementNoShortIf: FOR OPEN_BR ForInit FORMARK1 SEMICOLON FORMARK2 SEMICOLON ForUpdate CLOSE_BR FORMARK3 StatementNoShortIf FOREND1  */
#line 3212 "lalr1.y"
                                                                                                                      {
        (yyval.node)=new astnode;
        (yyval.node)->token="ForStatementNoShortIf";
        vector<astnode*>v;
        v.push_back((yyvsp[-11].node));
        v.push_back((yyvsp[-10].node));
        v.push_back((yyvsp[-9].node));
        v.push_back((yyvsp[-7].node));
        v.push_back((yyvsp[-5].node));
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6965 "lalr1.tab.c"
    break;

  case 256: /* ForStatementNoShortIf: FOR OPEN_BR ForInit FORMARK1 SEMICOLON Expression FORMARK2 SEMICOLON CLOSE_BR FORMARK3 StatementNoShortIf FOREND1  */
#line 3227 "lalr1.y"
                                                                                                                       {
        (yyval.node)=new astnode;
        (yyval.node)->token="ForStatementNoShortIf";
        vector<astnode*>v;
        v.push_back((yyvsp[-11].node));
        v.push_back((yyvsp[-10].node));
        v.push_back((yyvsp[-9].node));
        v.push_back((yyvsp[-7].node));
        v.push_back((yyvsp[-6].node));
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 6985 "lalr1.tab.c"
    break;

  case 257: /* ForStatementNoShortIf: FOR OPEN_BR ForInit FORMARK1 SEMICOLON Expression FORMARK2 SEMICOLON ForUpdate CLOSE_BR FORMARK3 StatementNoShortIf FOREND1  */
#line 3242 "lalr1.y"
                                                                                                                                 {
        (yyval.node)=new astnode;
        (yyval.node)->token="ForStatementNoShortIf";
        vector<astnode*>v;
        v.push_back((yyvsp[-12].node));
        v.push_back((yyvsp[-11].node));
        v.push_back((yyvsp[-10].node));
        v.push_back((yyvsp[-8].node));
        v.push_back((yyvsp[-7].node));
        v.push_back((yyvsp[-5].node));
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 7006 "lalr1.tab.c"
    break;

  case 258: /* ForInit: StatementExpressionList  */
#line 3260 "lalr1.y"
                           {
        (yyval.node)=new astnode;
        (yyval.node)->token="ForInit";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
    }
#line 7020 "lalr1.tab.c"
    break;

  case 259: /* ForInit: LocalVariableDeclaration  */
#line 3269 "lalr1.y"
                              {
        (yyval.node)=new astnode;
        (yyval.node)->token="ForInit";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        string s=(yyvsp[0].node)->value;
        vector<string>tokens=split(s,',');
        for(int i=0;i<tokens.size();i++) {
            buffer[tokens[i]]=(yyvsp[0].node)->type;
        }
        // buffer[$1->value]=$1->type;
        // cout<<"in"<<$$->token;
    }
#line 7039 "lalr1.tab.c"
    break;

  case 260: /* ForUpdate: StatementExpressionList  */
#line 3285 "lalr1.y"
                           {
        (yyval.node)=new astnode;
        (yyval.node)->token="ForUpdate";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
    }
#line 7053 "lalr1.tab.c"
    break;

  case 261: /* StatementExpressionList: StatementExpression  */
#line 3296 "lalr1.y"
                       {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementExpressionList";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
    }
#line 7067 "lalr1.tab.c"
    break;

  case 262: /* StatementExpressionList: StatementExpressionList COMMA StatementExpression  */
#line 3305 "lalr1.y"
                                                       {
        (yyval.node)=new astnode;
        (yyval.node)->token="StatementExpressionList";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[-2].node)->tac_val=","+(yyvsp[-2].node)->tac_val;
    }
#line 7083 "lalr1.tab.c"
    break;

  case 263: /* BreakStatement: BREAK SEMICOLON  */
#line 3318 "lalr1.y"
                   {
        (yyval.node)=new astnode;
        (yyval.node)->token="BreakStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        string tac,toget_label;
        toget_label=while_endlabels.top();
        tac="goto "+toget_label;
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
    }
#line 7101 "lalr1.tab.c"
    break;

  case 264: /* BreakStatement: BREAK IDENTIFIER SEMICOLON  */
#line 3331 "lalr1.y"
                                {
        (yyval.node)=new astnode;
        (yyval.node)->token="BreakStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 7116 "lalr1.tab.c"
    break;

  case 265: /* ContinueStatement: CONTINUE SEMICOLON  */
#line 3343 "lalr1.y"
                      {
        (yyval.node)=new astnode;
        (yyval.node)->token="ContinueStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        string tac,toget_label;
        toget_label=while_bwlabels.top();
        tac="goto "+toget_label;
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
    }
#line 7134 "lalr1.tab.c"
    break;

  case 266: /* ContinueStatement: CONTINUE IDENTIFIER SEMICOLON  */
#line 3356 "lalr1.y"
                                   {
        (yyval.node)=new astnode;
        (yyval.node)->token="ContinueStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        string tac,toget_label;
        toget_label=m[(yyvsp[-1].node)->lexeme];
        tac="goto "+toget_label;
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
    }
#line 7153 "lalr1.tab.c"
    break;

  case 267: /* ReturnStatement: RETURN SEMICOLON  */
#line 3372 "lalr1.y"
                    {
        (yyval.node)=new astnode;
        (yyval.node)->token="ReturnStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        prog.push_back("return");
        (yyval.node)->tac_val="return";
        (yyval.node)->type="void";
    }
#line 7170 "lalr1.tab.c"
    break;

  case 268: /* ReturnStatement: RETURN Expression SEMICOLON  */
#line 3384 "lalr1.y"
                                 {
        (yyval.node)=new astnode;
        (yyval.node)->token="ReturnStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        string tac;
        if((yyvsp[-1].node)->flag)
        tac="return t"+to_string(tempno-1);
        else tac = "return "+(yyvsp[-1].node)->tac_val;
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        (yyval.node)->tac_val=tac;
        (yyval.node)->type=(yyvsp[-1].node)->type;
    }
#line 7192 "lalr1.tab.c"
    break;

  case 269: /* ThrowStatement: THROW Expression SEMICOLON  */
#line 3403 "lalr1.y"
                              {
        (yyval.node)=new astnode;
        (yyval.node)->token="ThrowStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 7207 "lalr1.tab.c"
    break;

  case 270: /* SynchronizedStatement: SYNCHRONIZED OPEN_BR Expression CLOSE_BR Block  */
#line 3415 "lalr1.y"
                                                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="SynchronizedStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 7224 "lalr1.tab.c"
    break;

  case 271: /* TryStatement: TRY Block Catches  */
#line 3429 "lalr1.y"
                     {
        (yyval.node)=new astnode;
        (yyval.node)->token="TryStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 7239 "lalr1.tab.c"
    break;

  case 272: /* TryStatement: TRY Block Finally  */
#line 3439 "lalr1.y"
                        {
        (yyval.node)=new astnode;
        (yyval.node)->token="TryStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 7254 "lalr1.tab.c"
    break;

  case 273: /* TryStatement: TRY Block Catches Finally  */
#line 3449 "lalr1.y"
                               {
        (yyval.node)=new astnode;
        (yyval.node)->token="TryStatement";
        vector<astnode*>v;
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 7270 "lalr1.tab.c"
    break;

  case 274: /* Catches: CatchClause  */
#line 3462 "lalr1.y"
               {
        (yyval.node)=new astnode;
        (yyval.node)->token="Catches";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 7283 "lalr1.tab.c"
    break;

  case 275: /* Catches: Catches CatchClause  */
#line 3470 "lalr1.y"
                         {
        (yyval.node)=new astnode;
        (yyval.node)->token="Catches";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 7297 "lalr1.tab.c"
    break;

  case 276: /* CatchClause: CATCH OPEN_BR FormalParameter CLOSE_BR Block  */
#line 3481 "lalr1.y"
                                                {
        (yyval.node)=new astnode;
        (yyval.node)->token="CatchClause";
        vector<astnode*>v;
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 7314 "lalr1.tab.c"
    break;

  case 277: /* Finally: FINALLY Block  */
#line 3495 "lalr1.y"
                 {
        (yyval.node)=new astnode;
        (yyval.node)->token="Finally";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
    }
#line 7328 "lalr1.tab.c"
    break;

  case 278: /* Primary: PrimaryNoNewArray  */
#line 3509 "lalr1.y"
                      {
        (yyval.node)=new astnode;
        (yyval.node)->token="Primary";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
        if((yyval.node)->flag==4) {
            Type*t=symtabGetTypep(fullscope,(yyvsp[0].node)->value);
            cout<<t->dims<<" ";
            cout<<(yyval.node)->dims;
            if(t)
            if((yyval.node)->dims!=t->dims) cout<<"Error array of not same dimension";
        }
    }
#line 7353 "lalr1.tab.c"
    break;

  case 279: /* Primary: ArrayCreationExpression  */
#line 3529 "lalr1.y"
                            {
        (yyval.node)=new astnode;
        (yyval.node)->token="Primary";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
    }
#line 7370 "lalr1.tab.c"
    break;

  case 280: /* PrimaryNoNewArray: Literal  */
#line 3543 "lalr1.y"
           {
        (yyval.node)=new astnode;
        (yyval.node)->token="PrimaryNoNewArray";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 7387 "lalr1.tab.c"
    break;

  case 281: /* PrimaryNoNewArray: THIS  */
#line 3555 "lalr1.y"
         {
        (yyval.node)=new astnode;
        (yyval.node)->token="PrimaryNoNewArray";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->lexeme;
        (yyval.node)->type="this";
    }
#line 7402 "lalr1.tab.c"
    break;

  case 282: /* PrimaryNoNewArray: OPEN_BR Expression CLOSE_BR  */
#line 3565 "lalr1.y"
                                 {
        (yyval.node)=new astnode;
        (yyval.node)->token="PrimaryNoNewArray";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        if((yyvsp[-1].node)->flag==1) {
            (yyval.node)->tac_val="t"+to_string(tempno-1);
        }
        else {
            (yyval.node)->tac_val=(yyvsp[-1].node)->tac_val;
        }
        (yyval.node)->type=(yyvsp[-1].node)->type;
    }
#line 7424 "lalr1.tab.c"
    break;

  case 283: /* PrimaryNoNewArray: ClassInstanceCreationExpression  */
#line 3582 "lalr1.y"
                                    {
        (yyval.node)=new astnode;
        (yyval.node)->token="PrimaryNoNewArray";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
         (yyval.node)->type=(yyvsp[0].node)->type; // NEED TO SEE
    }
#line 7440 "lalr1.tab.c"
    break;

  case 284: /* PrimaryNoNewArray: FieldAccess  */
#line 3593 "lalr1.y"
                {
        (yyval.node)=new astnode;
        (yyval.node)->token="PrimaryNoNewArray";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->type=(yyvsp[0].node)->type;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
    }
#line 7456 "lalr1.tab.c"
    break;

  case 285: /* PrimaryNoNewArray: MethodInvocation  */
#line 3604 "lalr1.y"
                     {
        (yyval.node)=new astnode;
        (yyval.node)->token="PrimaryNoNewArray";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        // cout<<"in"<<$$->token;
        // symtab_t* t=symtab_top[fullscope];
        // $$->type=symtabGetType(t,$1->value);
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 7474 "lalr1.tab.c"
    break;

  case 286: /* PrimaryNoNewArray: ArrayAccess  */
#line 3617 "lalr1.y"
                {
        (yyval.node)=new astnode;
        (yyval.node)->token="PrimaryNoNewArray";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
        (yyval.node)->type=(yyvsp[0].node)->type;
        (yyval.node)->value=(yyvsp[0].node)->value;
    }
#line 7492 "lalr1.tab.c"
    break;

  case 287: /* ClassInstanceCreationExpression: NEW ClassType OPEN_BR CLOSE_BR  */
#line 3633 "lalr1.y"
                                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="ClassInstanceCreationExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        string tac,temp=get_tempvar();
        tac="Lcall_Alloc\n"; tac=tac+to_string(line++)+" ";
        tac=tac+temp+" = "+(yyvsp[-2].node)->tac_val;
        tac=tac+"\n"+"call "+(yyvsp[-2].node)->tac_val+".ctor 0";

        string scope=m1[(yyvsp[-2].node)->tac_val];
        // cout<<scope;
        symtab_t*t=symtab_top[scope];
        if((*t).find((yyvsp[-2].node)->tac_val)!=(*t).end()){
            Type*t1=(*t)[(yyvsp[-2].node)->tac_val];
            // cout<<endl<<t1->args;
            string s3=t1->args;
            vector<string>token1=split(s3,',');
            if(token1.size()>1) cout<<"arg length mismatch";
            else if(token1.size()==1&&token1[0]!="args") cout<<"arg mismatch";
        }
        
        (yyval.node)->tac_val=tac;
        (yyval.node)->flag=3;
        (yyval.node)->type=(yyvsp[-2].node)->type;
    }
#line 7528 "lalr1.tab.c"
    break;

  case 288: /* ClassInstanceCreationExpression: NEW ClassType OPEN_BR ArgumentList CLOSE_BR  */
#line 3664 "lalr1.y"
                                                 {
        (yyval.node)=new astnode;
        (yyval.node)->token="ClassInstanceCreationExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        string tac,temp=get_tempvar();
        tac="Lcall_Alloc\n"; tac=tac+to_string(line++)+" ";
        tac=tac+temp+" = "+(yyvsp[-3].node)->tac_val;
        string s=(yyvsp[-1].node)->tac_val;
        vector<string>token=split(s,',');
        for(int i=0;i<token.size();i++) {
            tac="push "+token[i];
            tac=to_string(line++)+" "+tac; prog.push_back(tac);
        }
        string scope=m1[(yyvsp[-3].node)->tac_val];
        // cout<<scope;
        symtab_t*t=symtab_top[scope];
        if((*t).find((yyvsp[-3].node)->tac_val)!=(*t).end()) cout<<"no constructor present";
        Type*t1=(*t)[(yyvsp[-3].node)->tac_val];
        // cout<<endl<<t1->args;
        string s3=t1->args;
        vector<string>token3=split((yyvsp[-1].node)->type,',');
        vector<string>token1=split(s3,',');
        if(token1.size()!=token3.size()) cout<<"arg length mismatch";
        for(int i=0;i<token3.size();i++) if(token3[i]!=token1[i]) cout<<"arg mismatch";
        // if(t1->args!=$4->tac_val) yyerror("arg mismatch");

        tac=tac+"\n"+"call "+(yyvsp[-3].node)->tac_val+".ctor "+to_string(token.size());
        (yyval.node)->tac_val=tac;
        (yyval.node)->flag=3;
        (yyval.node)->type=(yyvsp[-3].node)->type;
    }
#line 7571 "lalr1.tab.c"
    break;

  case 289: /* ArgumentList: Expression  */
#line 3704 "lalr1.y"
              {
        (yyval.node)=new astnode;
        (yyval.node)->token="ArgumentList";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 7586 "lalr1.tab.c"
    break;

  case 290: /* ArgumentList: ArgumentList COMMA Expression  */
#line 3714 "lalr1.y"
                                       {
        (yyval.node)=new astnode;
        (yyval.node)->token="ArgumentList";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[-2].node)->tac_val+","+(yyvsp[0].node)->tac_val;
        (yyval.node)->type=(yyvsp[-2].node)->type+","+(yyvsp[0].node)->type;
    }
#line 7603 "lalr1.tab.c"
    break;

  case 291: /* ArrayCreationExpression: NEW PrimitiveType DimExprs  */
#line 3728 "lalr1.y"
                                   {
        (yyval.node)=new astnode;
        (yyval.node)->token="ArrayCreationExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        string tac,temp=get_tempvar();
        tac="Lcall_Alloc\n"; tac=tac+to_string(line++)+" ";
        tac=tac+temp+" = "+(yyvsp[-1].node)->type+(yyvsp[0].node)->tac_val;
        (yyval.node)->tac_val=tac;
        (yyval.node)->flag=4;
        (yyval.node)->type=(yyvsp[-1].node)->type;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
    }
#line 7625 "lalr1.tab.c"
    break;

  case 292: /* ArrayCreationExpression: NEW PrimitiveType DimExprs Dims  */
#line 3745 "lalr1.y"
                                      {
        (yyval.node)=new astnode;
        (yyval.node)->token="ArrayCreationExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        string tac,temp=get_tempvar();
        tac="Lcall_Alloc\n"; tac=tac+to_string(line++)+" ";
        tac=tac+temp+" = "+(yyvsp[-2].node)->type+(yyvsp[-1].node)->tac_val+(yyvsp[0].node)->tac_val;
        (yyval.node)->tac_val=tac;
        (yyval.node)->flag=4;
        (yyval.node)->type=(yyvsp[-2].node)->type;
        (yyval.node)->dims=(yyvsp[-1].node)->dims+(yyvsp[0].node)->dims;
    }
#line 7647 "lalr1.tab.c"
    break;

  case 293: /* ArrayCreationExpression: NEW ClassOrInterfaceType DimExprs  */
#line 3762 "lalr1.y"
                                        {
        (yyval.node)=new astnode;
        (yyval.node)->token="ArrayCreationExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        string tac,temp=get_tempvar();
        tac="Lcall_Alloc\n"; tac=tac+to_string(line++)+" ";
        tac=tac+temp+" = "+(yyvsp[-1].node)->tac_val+(yyvsp[0].node)->tac_val;
        (yyval.node)->tac_val=tac;
        (yyval.node)->flag=4;
        (yyval.node)->type=(yyvsp[-1].node)->type;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
    }
#line 7669 "lalr1.tab.c"
    break;

  case 294: /* ArrayCreationExpression: NEW ClassOrInterfaceType DimExprs Dims  */
#line 3779 "lalr1.y"
                                                {
        (yyval.node)=new astnode;
        (yyval.node)->token="ArrayCreationExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        string tac,temp=get_tempvar();
        tac="Lcall_Alloc\n"; tac=tac+to_string(line++)+" ";
        tac=tac+temp+" = "+(yyvsp[-2].node)->tac_val+(yyvsp[-1].node)->tac_val+(yyvsp[0].node)->tac_val;
        (yyval.node)->tac_val=tac;
        (yyval.node)->flag=4;
        (yyval.node)->type=(yyvsp[-2].node)->type;
        (yyval.node)->dims=(yyvsp[-1].node)->dims+(yyvsp[0].node)->dims;
    }
#line 7692 "lalr1.tab.c"
    break;

  case 295: /* DimExprs: DimExpr  */
#line 3799 "lalr1.y"
                {
        (yyval.node)=new astnode;
        (yyval.node)->token="DimExprs";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
    }
#line 7708 "lalr1.tab.c"
    break;

  case 296: /* DimExprs: DimExprs DimExpr  */
#line 3810 "lalr1.y"
                           {
        (yyval.node)=new astnode;
        (yyval.node)->token="DimExprs";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[-1].node)->tac_val+(yyvsp[0].node)->tac_val;
        (yyval.node)->dims=(yyvsp[-1].node)->dims+1;
        (yyval.node)->flag=(yyvsp[-1].node)->flag;
    }
#line 7725 "lalr1.tab.c"
    break;

  case 297: /* DimExpr: OPEN_SQ Expression CLOSE_SQ  */
#line 3824 "lalr1.y"
                                    {
        (yyval.node)=new astnode;
        (yyval.node)->token="DimExpr";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        if((yyvsp[-1].node)->flag!=1&&(yyvsp[-1].node)->flag!=0) cout<<"array axis not defined";
        if((yyvsp[-1].node)->flag)
        (yyval.node)->tac_val="[t"+to_string(tempno-1)+"]";
        else (yyval.node)->tac_val="["+(yyvsp[-1].node)->tac_val+"]";
        (yyval.node)->dims=1;
        (yyval.node)->flag=4;
    }
#line 7746 "lalr1.tab.c"
    break;

  case 298: /* Dims: OPEN_SQ CLOSE_SQ  */
#line 3842 "lalr1.y"
                         {
        (yyval.node)=new astnode;
        (yyval.node)->token="Dims";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val="[]";
    }
#line 7761 "lalr1.tab.c"
    break;

  case 299: /* Dims: Dims OPEN_SQ CLOSE_SQ  */
#line 3852 "lalr1.y"
                               {
        (yyval.node)=new astnode;
        (yyval.node)->token="Dims";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[-2].node)->tac_val+"[]";
    }
#line 7777 "lalr1.tab.c"
    break;

  case 300: /* FieldAccess: Primary PERIOD IDENTIFIER  */
#line 3865 "lalr1.y"
                                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="FieldAccess";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[-2].node)->tac_val+"."+(yyvsp[0].node)->lexeme;
        (yyval.node)->type="fieldaccess";
        if((yyvsp[-2].node)->type=="this") {
            string scope=searchthis(fullscope);
            symtab_t*t=symtab_top[scope];
            if((*t).find((yyvsp[0].node)->lexeme)!=(*t).end()){
                Type*t1=(*t)[(yyvsp[0].node)->lexeme];
                (yyval.node)->type=t1->type;
            }
            (yyval.node)->flag=0;
        }
    }
#line 7803 "lalr1.tab.c"
    break;

  case 301: /* FieldAccess: SUPER PERIOD IDENTIFIER  */
#line 3886 "lalr1.y"
                                 {
        (yyval.node)=new astnode;
        (yyval.node)->token="FieldAccess";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[-2].node)->lexeme+"."+(yyvsp[0].node)->lexeme;
        (yyval.node)->type="fieldaccess";
    }
#line 7820 "lalr1.tab.c"
    break;

  case 302: /* MethodInvocation: Name OPEN_BR CLOSE_BR  */
#line 3900 "lalr1.y"
                             {
        (yyval.node)=new astnode;
        (yyval.node)->token="MethodInvocation";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // symadd($1->value,"nd","ud");
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val="call "+(yyvsp[-2].node)->tac_val+" 0";
        // symtab_t* t=symtab_top[fullscope];
        vector<string>tokens=split((yyvsp[-2].node)->value,'.');
        string x=m1[tokens[0]];
        if(fullscope.find(x)!=0){
            if((yyvsp[-2].node)->access_specifier==1)
            {
                cout<<"Method not accessible";
            }
        }
        // cout<<fullscope<<endl;
        (yyval.node)->type=symtabGetType(fullscope,(yyvsp[-2].node)->tac_val);
        if((yyval.node)->type!="0"){
            if(symtabGetArgs(fullscope,(yyvsp[-2].node)->value)!=""){
            cout<<"Argument list mismatch1";
        }
        }
        else{
            string s=(yyvsp[-2].node)->tac_val;
            vector<string>tokens=split(s,'.');
            s=symtabGetType(fullscope,tokens[0]);
            // cout<<"in"<<tokens[0]<<" "<<tokens[1]<<"out";
            // if(s=="0") {
            //     for(auto i: m1){
            //         cout<<"\n"<<i.second<<" "<<i.first;
            //         if(i.first==tokens[0]){
            //             string scope=i.second;
            //             cout<<scope;
            //             // symtab_t *t=symtab_top[scope];
            //             // Type*t1=(*t)[tokens[1]];
            //             // $$->type=t1->type;
            //             // cout<<$$->type<<" ";
            //             // cout<<t1->args;
            //             // if(t1->args!=""){
            //             //     yyerror("Argument list mismatch3");
            //             // }
            //         }
            //     }
            // }
            // else{
                symtab_t*t=symtab_top[m1[s]];
                Type*t1=(*t)[tokens[1]];
                (yyval.node)->type=t1->type;
                string x=m1[s];
                if(fullscope.find(x)!=0){
                    if(t1->access_specifier==0)
                    {
                        cout<<"Method not accessible";
                    }
                }
                // cout<<$$->type<<" ";
                // cout<<t1->args;
                if(t1->args!=""){
                    cout<<"Argument list mismatch3";
                }
            // }
        }
        (yyval.node)->tac_val=(yyval.node)->tac_val+"\n"+"deallocate 0";
        (yyval.node)->flag=2;                
    }
#line 7895 "lalr1.tab.c"
    break;

  case 303: /* MethodInvocation: Name OPEN_BR ArgumentList CLOSE_BR  */
#line 3970 "lalr1.y"
                                        {
        (yyval.node)=new astnode;
        (yyval.node)->token="MethodInvocation";
        vector<astnode*>v;
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        vector<string>tokens=split((yyvsp[-3].node)->value,'.');
        string x=m1[tokens[0]];
        if(fullscope.find(x)!=0){
            if((yyvsp[-3].node)->access_specifier==1)
            {
                cout<<"Method not accessible";
            }
        }
        // symadd($1->value,"nd","ud");
        // cout<<"in"<<$$->token;
        string s=(yyvsp[-1].node)->tac_val,tac;
        vector<string>token=split(s,',');
        for(int i=0;i<token.size();i++) {
            tac="push "+token[i];
            tac=to_string(line++)+" "+tac; prog.push_back(tac);
        }
        (yyval.node)->tac_val="call "+(yyvsp[-3].node)->tac_val+" "+to_string(token.size());
        // symtab_t* t=symtab_top[fullscope];
        (yyval.node)->type=symtabGetType(fullscope,(yyvsp[-3].node)->value);
        if((yyval.node)->type!="0")
        {
            vector<string>args=split((yyvsp[-1].node)->type,',');
            vector<string>args1=split(symtabGetArgs(fullscope,(yyvsp[-3].node)->value),',');
            if(args.size()!=args1.size()) cout<<"Argument mismatch2";
            for(int i=0;i<args.size();i++){
                if(args[i]!=args1[i]) cout<<"Argument mismatch2";
            }
            int si=getsize(args1);
            (yyval.node)->tac_val=(yyval.node)->tac_val+"\n"+"deallocate "+to_string(si);
        }
        else{
            string s=(yyvsp[-3].node)->tac_val;
            vector<string>tokens=split(s,'.');
            s=symtabGetType(fullscope,tokens[0]);
            // if(s=="0") {
            //     for(auto i: m1){
            //         if(i.first==tokens[0]){
            //             string scope=m1[tokens[0]];
            //             symtab_t *t=symtab_top[scope];
            //             Type*t1=(*t)[tokens[1]];
            //             $$->type=t1->type;
            //             cout<<$$->type<<" ";
            //             cout<<t1->args;
            //             vector<string>args=split($3->type,',');
            //             vector<string>args1=split(t1->args,',');
            //             if(args.size()!=args1.size()) yyerror("Argument mismatch2");
            //             for(int i=0;i<args.size();i++){
            //                 if(args[i]!=args1[i]) yyerror("Argument mismatch2");
            //             }
            //         }
            //     }
            // }
            // else{
                symtab_t*t=symtab_top[m1[s]];
                Type*t1=(*t)[tokens[1]];
                (yyval.node)->type=t1->type;
                string x=m1[s];
                // cout<<endl<<"x: "<<x<<" fullscope: "<<fullscope<<" prefix: "<<fullscope.find(x)<<endl;
                if(fullscope.find(x)!=0){
                    // cout<<"hi2"<<endl;
                    if(t1->access_specifier==0)
                    {
                        cout<<"Method not accessible";
                    }
                    // cout<<"Token: "<<tokens[1]<<" "<<symtabGetAccess(fullscope,tokens[1]);
                }
                // cout<<$$->type<<" ";
                // cout<<t1->args;
                vector<string>args=split((yyvsp[-1].node)->type,',');
                vector<string>args1=split(t1->args,',');
                if(args.size()!=args1.size()) cout<<"Argument mismatch2";
                for(int i=0;i<args.size();i++){
                    if(args[i]!=args1[i]) cout<<"Argument mismatch2";
                }
                int si=getsize(args1);
                (yyval.node)->tac_val=(yyval.node)->tac_val+"\n"+"deallocate "+to_string(si);
            // }
            
        }
        (yyval.node)->flag=2; 
    }
#line 7990 "lalr1.tab.c"
    break;

  case 304: /* MethodInvocation: Primary PERIOD IDENTIFIER OPEN_BR CLOSE_BR  */
#line 4060 "lalr1.y"
                                                 {
        (yyval.node)=new astnode;
        (yyval.node)->token="MethodInvocation";
        vector<astnode*>v;
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // symadd($1->value,"nd","ud");
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val="call "+(yyvsp[-4].node)->tac_val+(yyvsp[-3].node)->lexeme+(yyvsp[-2].node)->lexeme+" 0";
        
        // symtab_t*t=symtab_top[$1->tac_val];
        // Type*t1=(*t)[$3->lexeme];
        // $$->type=t1->type;
        // cout<<$$->type<<" ";
        // cout<<t1->args;
        // if(t1->args!=""){
        //     yyerror("Argument list mismatch3");
        // }
        (yyval.node)->type=symtabGetType(fullscope,(yyvsp[-4].node)->value);
        if(symtabGetArgs(fullscope,(yyvsp[-4].node)->value)!=""){
            cout<<"Argument list mismatch1";
        }
        (yyval.node)->flag=2;     
    }
#line 8023 "lalr1.tab.c"
    break;

  case 305: /* MethodInvocation: Primary PERIOD IDENTIFIER OPEN_BR ArgumentList CLOSE_BR  */
#line 4088 "lalr1.y"
                                                                 {
        (yyval.node)=new astnode;
        (yyval.node)->token="MethodInvocation";
        vector<astnode*>v;
        v.push_back((yyvsp[-5].node));
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // symadd($1->value,"nd","ud");
        // cout<<"in"<<$$->token;
        string s=(yyvsp[-1].node)->tac_val,tac;
        vector<string>token=split(s,',');
        for(int i=0;i<token.size();i++) {
            tac="push "+token[i];
            tac=to_string(line++)+" "+tac; prog.push_back(tac);
        }
        (yyval.node)->tac_val="call "+(yyvsp[-5].node)->tac_val+(yyvsp[-4].node)->lexeme+(yyvsp[-3].node)->lexeme+" "+to_string(token.size());
        (yyval.node)->type=symtabGetType(fullscope,(yyvsp[-3].node)->lexeme);
        // cout<<$$->type<<endl;
        // cout<<$3->type<<endl;
        vector<string>args=split((yyvsp[-1].node)->type,',');
        
        vector<string>args1=split(symtabGetArgs(fullscope,(yyvsp[-3].node)->lexeme),',');
        if(args.size()!=args1.size()) cout<<"Argument mismatch4";
        for(int i=0;i<args.size();i++){
            if(args[i]!=args1[i]) cout<<"Argument mismatch4";
        }
        (yyval.node)->flag=2;   
    }
#line 8060 "lalr1.tab.c"
    break;

  case 306: /* MethodInvocation: SUPER PERIOD IDENTIFIER OPEN_BR CLOSE_BR  */
#line 4120 "lalr1.y"
                                              {
        (yyval.node)=new astnode;
        (yyval.node)->token="MethodInvocation";
        vector<astnode*>v;
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        // symadd($1->value,"nd","ud");
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val="call "+(yyvsp[-4].node)->lexeme+(yyvsp[-3].node)->lexeme+(yyvsp[-2].node)->lexeme+" 0";
        (yyval.node)->tac_val="call "+(yyvsp[-4].node)->tac_val+(yyvsp[-3].node)->lexeme+(yyvsp[-2].node)->lexeme+" 0";
        (yyval.node)->type=symtabGetType(fullscope,(yyvsp[-2].node)->lexeme);
        if(symtabGetArgs(fullscope,(yyvsp[-2].node)->lexeme)!=""){
            cout<<"Argument list mismatch";
        }  
        (yyval.node)->flag=2;   
    }
#line 8085 "lalr1.tab.c"
    break;

  case 307: /* MethodInvocation: SUPER PERIOD IDENTIFIER OPEN_BR ArgumentList CLOSE_BR  */
#line 4140 "lalr1.y"
                                                               {
        (yyval.node)=new astnode;
        (yyval.node)->token="MethodInvocation";
        vector<astnode*>v;
        v.push_back((yyvsp[-5].node));
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // symadd($1->value,"nd","ud");
        // cout<<"in"<<$$->token;
        string s=(yyvsp[-1].node)->tac_val,tac;
        vector<string>token=split(s,',');
        for(int i=0;i<token.size();i++) {
            tac="push "+token[i];
            tac=to_string(line++)+" "+tac; prog.push_back(tac);
        }
        (yyval.node)->tac_val="call "+(yyvsp[-5].node)->lexeme+(yyvsp[-4].node)->lexeme+(yyvsp[-3].node)->lexeme+" "+to_string(token.size());
        (yyval.node)->type=symtabGetType(fullscope,(yyvsp[-3].node)->lexeme);
        // cout<<$$->type<<endl;
        // cout<<$3->type<<endl;
        vector<string>args=split((yyvsp[-1].node)->type,',');
        (yyval.node)->flag=2;   
        vector<string>args1=split(symtabGetArgs(fullscope,(yyvsp[-3].node)->lexeme),',');
        if(args.size()!=args1.size()) cout<<"Argument mismatch";
        for(int i=0;i<args.size();i++){
            if(args[i]!=args1[i]) cout<<"Argument mismatch";
        }
    }
#line 8121 "lalr1.tab.c"
    break;

  case 308: /* ArrayAccess: Name OPEN_SQ Expression CLOSE_SQ  */
#line 4173 "lalr1.y"
                                        {
        (yyval.node)=new astnode;
        (yyval.node)->token="ArrayAccess";
        vector<astnode*>v;
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        if((yyvsp[-1].node)->type!="int") {
            cout<<"array index not defined";
        }
        string tac,var;
        if((yyvsp[-1].node)->flag) {
            var=get_tempvar();
            tac=var+" = t"+to_string(tempno-2)+"*8";
        }
        else{
            var=get_tempvar();
            tac=var+" = "+(yyvsp[-1].node)->tac_val+"*8";
        }
        (yyval.node)->flag=4;
        (yyval.node)->dims=(yyval.node)->dims+1;
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        var=get_tempvar();
        tac=var+" = "+(yyvsp[-3].node)->tac_val+"[t"+to_string(tempno-2)+"]";
        (yyval.node)->tac_val=var;
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        (yyval.node)->type=(yyvsp[-3].node)->type;
        (yyval.node)->value=(yyvsp[-3].node)->value;
    }
#line 8158 "lalr1.tab.c"
    break;

  case 309: /* ArrayAccess: PrimaryNoNewArray OPEN_SQ Expression CLOSE_SQ  */
#line 4205 "lalr1.y"
                                                       {
        (yyval.node)=new astnode;
        (yyval.node)->token="ArrayAccess";
        vector<astnode*>v;
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        string tac,var;
        if((yyvsp[-1].node)->flag) {
            var=get_tempvar();
            tac=var+" = t"+to_string(tempno-2)+"*8";
        }
        else{
            var=get_tempvar();
            tac=var+" = "+(yyvsp[-1].node)->tac_val+"*8";
        }
        (yyval.node)->flag=4;
        (yyval.node)->dims=(yyvsp[-3].node)->dims+1;
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        var=get_tempvar();
        tac=var+" = "+(yyvsp[-3].node)->tac_val+"[t"+to_string(tempno-2)+"]";
        (yyval.node)->tac_val=var;
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        (yyval.node)->type=(yyvsp[-3].node)->type;
        (yyval.node)->value=(yyvsp[-3].node)->value;
    }
#line 8192 "lalr1.tab.c"
    break;

  case 310: /* PostfixExpression: Primary  */
#line 4236 "lalr1.y"
               {
        (yyval.node)=new astnode;
        (yyval.node)->token="PostfixExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 8210 "lalr1.tab.c"
    break;

  case 311: /* PostfixExpression: Name  */
#line 4249 "lalr1.y"
               {
        (yyval.node)=new astnode;
        (yyval.node)->token="PostfixExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 8227 "lalr1.tab.c"
    break;

  case 312: /* PostfixExpression: PostIncrementExpression  */
#line 4261 "lalr1.y"
                                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="PostfixExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 8243 "lalr1.tab.c"
    break;

  case 313: /* PostfixExpression: PostDecrementExpression  */
#line 4272 "lalr1.y"
                                 {
        (yyval.node)=new astnode;
        (yyval.node)->token="PostfixExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 8259 "lalr1.tab.c"
    break;

  case 314: /* PostIncrementExpression: PostfixExpression INC  */
#line 4285 "lalr1.y"
                              {
        (yyval.node)=new astnode;
        (yyval.node)->token="PostfixIncrementExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        string temp=get_tempvar();
        (yyval.node)->tac_val=temp;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+","+temp;
        tac=temp+" = "+(yyvsp[-1].node)->tac_val;
        (yyval.node)->code=tac+"\n";
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        tac=(yyvsp[-1].node)->tac_val+" = "+(yyvsp[-1].node)->tac_val+" + 1";
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        // cout<<"in"<<$$->token;
        (yyval.node)->type=(yyvsp[-1].node)->type;
    }
#line 8283 "lalr1.tab.c"
    break;

  case 315: /* PostDecrementExpression: PostfixExpression DEC  */
#line 4306 "lalr1.y"
                             {
        (yyval.node)=new astnode;
        (yyval.node)->token="PostfixDecrementExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        string temp=get_tempvar();
        (yyval.node)->tac_val=temp;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+","+temp;
        tac=temp+" = "+(yyvsp[-1].node)->tac_val;
        (yyval.node)->code=tac+"\n";
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        tac=(yyvsp[-1].node)->tac_val+" = "+(yyvsp[-1].node)->tac_val+" - 1";
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        // cout<<"in"<<$$->token;
        (yyval.node)->type=(yyvsp[-1].node)->type;
    }
#line 8307 "lalr1.tab.c"
    break;

  case 316: /* UnaryExpression: PreIncrementExpression  */
#line 4327 "lalr1.y"
                              {
        (yyval.node)=new astnode;
        (yyval.node)->token="UnaryExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 8324 "lalr1.tab.c"
    break;

  case 317: /* UnaryExpression: PreDecrementExpression  */
#line 4339 "lalr1.y"
                                {
        (yyval.node)=new astnode;
        (yyval.node)->token="UnaryExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 8340 "lalr1.tab.c"
    break;

  case 318: /* UnaryExpression: ADD UnaryExpression  */
#line 4350 "lalr1.y"
                             {
        (yyval.node)=new astnode;
        (yyval.node)->token="UnaryExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        string temp=get_tempvar();
        (yyval.node)->tac_val=temp;
        string tac="";
        // tac=tac+$1->lexeme+","+$2->tac_val+","+","+temp;
        tac=temp+" = "+(yyvsp[-1].node)->lexeme+" "+(yyvsp[0].node)->tac_val;
        (yyval.node)->code=tac+"\n";
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        // cout<<"in"<<$$->token;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 8362 "lalr1.tab.c"
    break;

  case 319: /* UnaryExpression: SUB UnaryExpression  */
#line 4367 "lalr1.y"
                             {
        (yyval.node)=new astnode;
        (yyval.node)->token="UnaryExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        string temp=get_tempvar();
        (yyval.node)->tac_val=temp;
        string tac="";
        // tac=tac+$1->lexeme+","+$2->tac_val+","+","+temp;
        tac=temp+" = "+(yyvsp[-1].node)->lexeme+" "+(yyvsp[0].node)->tac_val;
        (yyval.node)->code=tac+"\n";
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        // cout<<"in"<<$$->token;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 8384 "lalr1.tab.c"
    break;

  case 320: /* UnaryExpression: UnaryExpressionNotPlusMinus  */
#line 4384 "lalr1.y"
                                     {
        (yyval.node)=new astnode;
        (yyval.node)->token="UnaryExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
    }
#line 8402 "lalr1.tab.c"
    break;

  case 321: /* PreIncrementExpression: INC UnaryExpression  */
#line 4399 "lalr1.y"
                           {
        (yyval.node)=new astnode;
        (yyval.node)->token="PreIncrementExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        string temp=get_tempvar();
        (yyval.node)->tac_val=temp;
        string tac="";
        // tac=tac+$1->lexeme+","+$2->tac_val+","+","+temp;
        tac=(yyvsp[0].node)->tac_val+" = "+(yyvsp[0].node)->tac_val+" + 1";
        (yyval.node)->code=tac+"\n";
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        tac=temp+" = "+(yyvsp[0].node)->tac_val;
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        // cout<<"in"<<$$->token;
        (yyval.node)->type=(yyvsp[-1].node)->type;
    }
#line 8426 "lalr1.tab.c"
    break;

  case 322: /* PreDecrementExpression: DEC UnaryExpression  */
#line 4420 "lalr1.y"
                           {
        (yyval.node)=new astnode;
        (yyval.node)->token="PreDecrementExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        string temp=get_tempvar();
        (yyval.node)->tac_val=temp;
        string tac="";
        // tac=tac+$1->lexeme+","+$2->tac_val+","+","+temp;
        tac=(yyvsp[0].node)->tac_val+" = "+(yyvsp[0].node)->tac_val+" - 1";
        (yyval.node)->code=tac+"\n";
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        tac=temp+" = "+(yyvsp[0].node)->tac_val;
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        // cout<<"in"<<$$->token;
        (yyval.node)->type=(yyvsp[-1].node)->type;
    }
#line 8450 "lalr1.tab.c"
    break;

  case 323: /* UnaryExpressionNotPlusMinus: PostfixExpression  */
#line 4441 "lalr1.y"
                         {
        (yyval.node)=new astnode;
        (yyval.node)->token="UnaryExpressionNotPlusMinus";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
    }
#line 8468 "lalr1.tab.c"
    break;

  case 324: /* UnaryExpressionNotPlusMinus: TILDE UnaryExpression  */
#line 4454 "lalr1.y"
                                {
        (yyval.node)=new astnode;
        (yyval.node)->token="UnaryExpressionNotPlusMinus";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        string temp=get_tempvar();
        (yyval.node)->tac_val=temp;
        string tac="";
        // tac=tac+$1->lexeme+","+$2->tac_val+","+","+temp;
        tac=temp+" = "+(yyvsp[-1].node)->lexeme+" "+(yyvsp[0].node)->tac_val;
        (yyval.node)->code=tac+"\n";
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        // cout<<"in"<<$$->token;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 8490 "lalr1.tab.c"
    break;

  case 325: /* UnaryExpressionNotPlusMinus: NOT UnaryExpression  */
#line 4471 "lalr1.y"
                             {
        (yyval.node)=new astnode;
        (yyval.node)->token="UnaryExpressionNotPlusMinus";
        vector<astnode*>v;
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        string temp=get_tempvar();
        (yyval.node)->tac_val=temp;
        string tac="";
        // tac=tac+$1->lexeme+","+$2->tac_val+","+","+temp;
        tac=temp+" = "+(yyvsp[-1].node)->lexeme+" "+(yyvsp[0].node)->tac_val;
        (yyval.node)->code=tac+"\n";
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        // cout<<"in"<<$$->token;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 8512 "lalr1.tab.c"
    break;

  case 326: /* UnaryExpressionNotPlusMinus: CastExpression  */
#line 4488 "lalr1.y"
                        {
        (yyval.node)=new astnode;
        (yyval.node)->token="UnaryExpressionNotPlusMinus";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        // cout<<"in"<<$$->token;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 8527 "lalr1.tab.c"
    break;

  case 327: /* CastExpression: OPEN_BR PrimitiveType CLOSE_BR UnaryExpression  */
#line 4500 "lalr1.y"
                                                      {
        (yyval.node)=new astnode;
        (yyval.node)->token="CastExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        string tac,temp=get_tempvar();
        tac=temp+" = cast_to_"+(yyvsp[-2].node)->type+" "+(yyvsp[0].node)->tac_val;
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        (yyval.node)->tac_val=temp;
        (yyval.node)->type=(yyvsp[-2].node)->type;
    }
#line 8548 "lalr1.tab.c"
    break;

  case 328: /* CastExpression: OPEN_BR PrimitiveType Dims CLOSE_BR UnaryExpression  */
#line 4516 "lalr1.y"
                                                         {
        (yyval.node)=new astnode;
        (yyval.node)->token="CastExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        string tac,temp=get_tempvar();
        tac=temp+" = cast_to_"+(yyvsp[-3].node)->type+(yyvsp[-2].node)->tac_val+" "+(yyvsp[0].node)->tac_val;
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        (yyval.node)->tac_val=temp;
        (yyval.node)->type=(yyvsp[-3].node)->type;
    }
#line 8570 "lalr1.tab.c"
    break;

  case 329: /* CastExpression: OPEN_BR Expression CLOSE_BR UnaryExpressionNotPlusMinus  */
#line 4533 "lalr1.y"
                                                                 {
        (yyval.node)=new astnode;
        (yyval.node)->token="CastExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->type=(yyvsp[-2].node)->type;
    }
#line 8587 "lalr1.tab.c"
    break;

  case 330: /* CastExpression: OPEN_BR Name Dims CLOSE_BR UnaryExpressionNotPlusMinus  */
#line 4545 "lalr1.y"
                                                                {
        (yyval.node)=new astnode;
        (yyval.node)->token="CastExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-3].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->type=(yyvsp[-3].node)->type;
        // string tac,var=get_tempvar();
        // tac=var+" = cast_to_"+$2->type+$3->tac_val+" "+$5->tac_val;
        // tac=to_string(line++)+" "+tac; prog.push_back(tac);
    }
#line 8608 "lalr1.tab.c"
    break;

  case 331: /* MultiplicativeExpression: UnaryExpression  */
#line 4563 "lalr1.y"
                       {
        (yyval.node)=new astnode;
        (yyval.node)->token="MultiplicativeExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
    }
#line 8626 "lalr1.tab.c"
    break;

  case 332: /* MultiplicativeExpression: MultiplicativeExpression MUL UnaryExpression  */
#line 4576 "lalr1.y"
                                                     {
        (yyval.node)=new astnode;
        (yyval.node)->token="MultiplicativeExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        temp=symtypeEvaluate((yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if((yyvsp[-2].node)->type != (yyvsp[0].node)->type)
        {   if((yyvsp[-2].node)->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" = cast_to_"+temp+" "+(yyvsp[0].node)->tac_val;
                prog.push_back(s1);
                (yyvsp[0].node)->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+(yyvsp[-2].node)->tac_val;
        }
        s2=temp+"*";
        (yyval.node)->type=temp;
        string temp1=get_tempvar();
        (yyval.node)->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+(yyvsp[-2].node)->tac_val+" "+(yyvsp[-1].node)->lexeme+" "+(yyvsp[0].node)->tac_val;
        (yyval.node)->code=tac+"\n";
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
#line 8667 "lalr1.tab.c"
    break;

  case 333: /* MultiplicativeExpression: MultiplicativeExpression QUO UnaryExpression  */
#line 4612 "lalr1.y"
                                                     {
        (yyval.node)=new astnode;
        (yyval.node)->token="MultiplicativeExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        temp=symtypeEvaluate((yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if((yyvsp[-2].node)->type != (yyvsp[0].node)->type)
        {   if((yyvsp[-2].node)->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" = cast_to_"+temp+" "+(yyvsp[0].node)->tac_val;
                prog.push_back(s1);
                (yyvsp[0].node)->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+(yyvsp[-2].node)->tac_val;
        }
        s2=temp+"/";
        (yyval.node)->type=temp;
        string temp1=get_tempvar();
        (yyval.node)->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+(yyvsp[-2].node)->tac_val+" "+(yyvsp[-1].node)->lexeme+" "+(yyvsp[0].node)->tac_val;
        (yyval.node)->code=tac+"\n";
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
#line 8708 "lalr1.tab.c"
    break;

  case 334: /* MultiplicativeExpression: MultiplicativeExpression REM UnaryExpression  */
#line 4648 "lalr1.y"
                                                     {
        (yyval.node)=new astnode;
        (yyval.node)->token="MultiplicativeExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        temp=symtypeEvaluate((yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
       if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if((yyvsp[-2].node)->type != (yyvsp[0].node)->type)
        {   if((yyvsp[-2].node)->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" = cast_to_"+temp+" "+(yyvsp[0].node)->tac_val;
                prog.push_back(s1);
                (yyvsp[0].node)->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+(yyvsp[-2].node)->tac_val;
        }
        s2=temp+"%";
        (yyval.node)->type=temp;
        string temp1=get_tempvar();
        (yyval.node)->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+(yyvsp[-2].node)->tac_val+" "+(yyvsp[-1].node)->lexeme+" "+(yyvsp[0].node)->tac_val;
        (yyval.node)->code=tac+"\n";
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
#line 8749 "lalr1.tab.c"
    break;

  case 335: /* AdditiveExpression: MultiplicativeExpression  */
#line 4686 "lalr1.y"
                                {
        (yyval.node)=new astnode;
        (yyval.node)->token="AdditiveExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
    }
#line 8767 "lalr1.tab.c"
    break;

  case 336: /* AdditiveExpression: AdditiveExpression ADD MultiplicativeExpression  */
#line 4699 "lalr1.y"
                                                        {
        (yyval.node)=new astnode;
        (yyval.node)->token="AdditiveExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        string temp=get_tempvar();
        temp=symtypeEvaluate((yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if((yyvsp[-2].node)->type != (yyvsp[0].node)->type)
        {   if((yyvsp[-2].node)->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" = cast_to_"+temp+" "+(yyvsp[0].node)->tac_val;
                prog.push_back(s1);
                (yyvsp[0].node)->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+(yyvsp[-2].node)->tac_val;
        }
        s2=temp+"+";
        (yyval.node)->type=temp;
        string temp1=get_tempvar();
        (yyval.node)->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+(yyvsp[-2].node)->tac_val+" "+(yyvsp[-1].node)->lexeme+" "+(yyvsp[0].node)->tac_val;
        (yyval.node)->code=tac+"\n";
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
#line 8809 "lalr1.tab.c"
    break;

  case 337: /* AdditiveExpression: AdditiveExpression SUB MultiplicativeExpression  */
#line 4736 "lalr1.y"
                                                        {
        (yyval.node)=new astnode;
        (yyval.node)->token="AdditiveExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        temp=symtypeEvaluate((yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if((yyvsp[-2].node)->type != (yyvsp[0].node)->type)
        {   if((yyvsp[-2].node)->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" = cast_to_"+temp+" "+(yyvsp[0].node)->tac_val;
                prog.push_back(s1);
                (yyvsp[0].node)->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+(yyvsp[-2].node)->tac_val;
        }
        s2=temp+"-";
        (yyval.node)->type=temp;
        string temp1=get_tempvar();
        (yyval.node)->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+(yyvsp[-2].node)->tac_val+" "+(yyvsp[-1].node)->lexeme+" "+(yyvsp[0].node)->tac_val;
        (yyval.node)->code=tac+"\n";
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
#line 8850 "lalr1.tab.c"
    break;

  case 338: /* ShiftExpression: AdditiveExpression  */
#line 4774 "lalr1.y"
                          {
        (yyval.node)=new astnode;
        (yyval.node)->token="ShiftExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
    }
#line 8868 "lalr1.tab.c"
    break;

  case 339: /* ShiftExpression: ShiftExpression SHL AdditiveExpression  */
#line 4787 "lalr1.y"
                                               {
        (yyval.node)=new astnode;
        (yyval.node)->token="ShiftExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
       temp=symtypeEvaluate((yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if((yyvsp[-2].node)->type != (yyvsp[0].node)->type)
        {   if((yyvsp[-2].node)->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" = cast_to_"+temp+" "+(yyvsp[0].node)->tac_val;
                prog.push_back(s1);
                (yyvsp[0].node)->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+(yyvsp[-2].node)->tac_val;
        }
        s2=temp+"<<";
        (yyval.node)->type=temp;
        string temp1=get_tempvar();
        (yyval.node)->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+(yyvsp[-2].node)->tac_val+" "+(yyvsp[-1].node)->lexeme+" "+(yyvsp[0].node)->tac_val;
        (yyval.node)->code=tac+"\n";
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
#line 8909 "lalr1.tab.c"
    break;

  case 340: /* ShiftExpression: ShiftExpression SHR AdditiveExpression  */
#line 4823 "lalr1.y"
                                                {
        (yyval.node)=new astnode;
        (yyval.node)->token="ShiftExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        temp=symtypeEvaluate((yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if((yyvsp[-2].node)->type != (yyvsp[0].node)->type)
        {   if((yyvsp[-2].node)->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" = cast_to_"+temp+" "+(yyvsp[0].node)->tac_val;
                prog.push_back(s1);
                (yyvsp[0].node)->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+(yyvsp[-2].node)->tac_val;
        }
        s2=temp+">>";
        (yyval.node)->type=temp;
        string temp1=get_tempvar();
        (yyval.node)->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+(yyvsp[-2].node)->tac_val+" "+(yyvsp[-1].node)->lexeme+" "+(yyvsp[0].node)->tac_val;
        (yyval.node)->code=tac+"\n";
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
#line 8950 "lalr1.tab.c"
    break;

  case 341: /* ShiftExpression: ShiftExpression GR AdditiveExpression  */
#line 4859 "lalr1.y"
                                              {
        (yyval.node)=new astnode;
        (yyval.node)->token="ShiftExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        temp=symtypeEvaluate((yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if((yyvsp[-2].node)->type != (yyvsp[0].node)->type)
        {   if((yyvsp[-2].node)->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" = cast_to_"+temp+" "+(yyvsp[0].node)->tac_val;
                prog.push_back(s1);
                (yyvsp[0].node)->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+(yyvsp[-2].node)->tac_val;
        }
        s2=temp+">>>";
        (yyval.node)->type=temp;
        string temp1=get_tempvar();
        (yyval.node)->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+(yyvsp[-2].node)->tac_val+" "+(yyvsp[-1].node)->lexeme+" "+(yyvsp[0].node)->tac_val;
        (yyval.node)->code=tac+"\n";
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
#line 8991 "lalr1.tab.c"
    break;

  case 342: /* RelationalExpression: ShiftExpression  */
#line 4897 "lalr1.y"
                       {
        (yyval.node)=new astnode;
        (yyval.node)->token="RelationalExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
    }
#line 9009 "lalr1.tab.c"
    break;

  case 343: /* RelationalExpression: RelationalExpression LSS ShiftExpression  */
#line 4910 "lalr1.y"
                                                 {
        (yyval.node)=new astnode;
        (yyval.node)->token="RelationalExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        temp=symtypeEvaluate((yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if((yyvsp[-2].node)->type != (yyvsp[0].node)->type)
        {   if((yyvsp[-2].node)->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" = cast_to_"+temp+" "+(yyvsp[0].node)->tac_val;
                prog.push_back(s1);
                (yyvsp[0].node)->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+(yyvsp[-2].node)->tac_val;
        }
        s2=temp+"<";
        (yyval.node)->type="boolean";
        string temp1=get_tempvar();
        (yyval.node)->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+(yyvsp[-2].node)->tac_val+" "+(yyvsp[-1].node)->lexeme+" "+(yyvsp[0].node)->tac_val;
        (yyval.node)->code=tac+"\n";
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
#line 9050 "lalr1.tab.c"
    break;

  case 344: /* RelationalExpression: RelationalExpression GTR ShiftExpression  */
#line 4946 "lalr1.y"
                                                 {
        (yyval.node)=new astnode;
        (yyval.node)->token="RelationalExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        temp=symtypeEvaluate((yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if((yyvsp[-2].node)->type != (yyvsp[0].node)->type)
        {   if((yyvsp[-2].node)->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" = cast_to_"+temp+" "+(yyvsp[0].node)->tac_val;
                prog.push_back(s1);
                (yyvsp[0].node)->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+(yyvsp[-2].node)->tac_val;
        }
        s2=temp+">";
        (yyval.node)->type="boolean";
        string temp1=get_tempvar();
        (yyval.node)->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+(yyvsp[-2].node)->tac_val+" "+(yyvsp[-1].node)->lexeme+" "+(yyvsp[0].node)->tac_val;
        (yyval.node)->code=tac+"\n";
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
#line 9091 "lalr1.tab.c"
    break;

  case 345: /* RelationalExpression: RelationalExpression LEQ ShiftExpression  */
#line 4982 "lalr1.y"
                                                 {
        (yyval.node)=new astnode;
        (yyval.node)->token="RelationalExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        temp=symtypeEvaluate((yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if((yyvsp[-2].node)->type != (yyvsp[0].node)->type)
        {   if((yyvsp[-2].node)->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" = cast_to_"+temp+" "+(yyvsp[0].node)->tac_val;
                prog.push_back(s1);
                (yyvsp[0].node)->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+(yyvsp[-2].node)->tac_val;
        }
        s2=temp+"<=";
        (yyval.node)->type="boolean";
        string temp1=get_tempvar();
        (yyval.node)->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+(yyvsp[-2].node)->tac_val+" "+(yyvsp[-1].node)->lexeme+" "+(yyvsp[0].node)->tac_val;
        (yyval.node)->code=tac+"\n";
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
#line 9132 "lalr1.tab.c"
    break;

  case 346: /* RelationalExpression: RelationalExpression GEQ ShiftExpression  */
#line 5018 "lalr1.y"
                                                 {
        (yyval.node)=new astnode;
        (yyval.node)->token="RelationalExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        temp=symtypeEvaluate((yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if((yyvsp[-2].node)->type != (yyvsp[0].node)->type)
        {   if((yyvsp[-2].node)->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" = cast_to_"+temp+" "+(yyvsp[0].node)->tac_val;
                prog.push_back(s1);
                (yyvsp[0].node)->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+(yyvsp[-2].node)->tac_val;
        }
        s2=temp+">=";
        (yyval.node)->type="boolean";
        string temp1=get_tempvar();
        (yyval.node)->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+(yyvsp[-2].node)->tac_val+" "+(yyvsp[-1].node)->lexeme+" "+(yyvsp[0].node)->tac_val;
        (yyval.node)->code=tac+"\n";
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
#line 9173 "lalr1.tab.c"
    break;

  case 347: /* RelationalExpression: RelationalExpression INSTANCEOF ReferenceType  */
#line 5054 "lalr1.y"
                                                      {
        (yyval.node)=new astnode;
        (yyval.node)->token="RelationalExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        temp=symAssignment((yyvsp[-2].node)->type,(yyvsp[0].node)->type);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        (yyval.node)->type="boolean";
        string tac,temp1=get_tempvar();
        tac=temp1+" = "+(yyvsp[-2].node)->tac_val+" "+(yyvsp[-1].node)->lexeme+" "+(yyvsp[0].node)->tac_val;
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        (yyval.node)->tac_val=temp1;
    }
#line 9198 "lalr1.tab.c"
    break;

  case 348: /* EqualityExpression: RelationalExpression  */
#line 5076 "lalr1.y"
                            {
        (yyval.node)=new astnode;
        (yyval.node)->token="EqualityExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
    }
#line 9216 "lalr1.tab.c"
    break;

  case 349: /* EqualityExpression: EqualityExpression EQL RelationalExpression  */
#line 5089 "lalr1.y"
                                                    {
        (yyval.node)=new astnode;
        (yyval.node)->token="EqualityExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        temp=symtypeEvaluate((yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if((yyvsp[-2].node)->type != (yyvsp[0].node)->type)
        {   if((yyvsp[-2].node)->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" = cast_to_"+temp+" "+(yyvsp[0].node)->tac_val;
                prog.push_back(s1);
                (yyvsp[0].node)->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+(yyvsp[-2].node)->tac_val;
        }
        s2=temp+"==";
        (yyval.node)->type="boolean";
        string temp1=get_tempvar();
        (yyval.node)->tac_val=temp1;
        string tac="";
        // tac=$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+(yyvsp[-2].node)->tac_val+" "+(yyvsp[-1].node)->lexeme+" "+(yyvsp[0].node)->tac_val;
        (yyval.node)->code=tac+"\n";
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
#line 9257 "lalr1.tab.c"
    break;

  case 350: /* EqualityExpression: EqualityExpression NEQ RelationalExpression  */
#line 5125 "lalr1.y"
                                                    {
        (yyval.node)=new astnode;
        (yyval.node)->token="EqualityExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        temp=symtypeEvaluate((yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if((yyvsp[-2].node)->type != (yyvsp[0].node)->type)
        {   if((yyvsp[-2].node)->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" = cast_to_"+temp+" "+(yyvsp[0].node)->tac_val;
                prog.push_back(s1);
                (yyvsp[0].node)->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+(yyvsp[-2].node)->tac_val;
        }
        s2=temp+"!=";
        (yyval.node)->type="boolean";
        string temp1=get_tempvar();
        (yyval.node)->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+(yyvsp[-2].node)->tac_val+" "+(yyvsp[-1].node)->lexeme+" "+(yyvsp[0].node)->tac_val;
        (yyval.node)->code=tac+"\n";
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
#line 9298 "lalr1.tab.c"
    break;

  case 351: /* AndExpression: EqualityExpression  */
#line 5163 "lalr1.y"
                          {
        (yyval.node)=new astnode;
        (yyval.node)->token="AndExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
    }
#line 9316 "lalr1.tab.c"
    break;

  case 352: /* AndExpression: AndExpression AMPERSAT EqualityExpression  */
#line 5176 "lalr1.y"
                                                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="AndExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        temp=symtypeEvaluate((yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if((yyvsp[-2].node)->type != (yyvsp[0].node)->type)
        {   if((yyvsp[-2].node)->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" = cast_to_"+temp+" "+(yyvsp[0].node)->tac_val;
                prog.push_back(s1);
                (yyvsp[0].node)->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+(yyvsp[-2].node)->tac_val;
        }
        s2=temp+"&";
        (yyval.node)->type="boolean";
        string temp1=get_tempvar();
        (yyval.node)->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+(yyvsp[-2].node)->tac_val+" "+(yyvsp[-1].node)->lexeme+" "+(yyvsp[0].node)->tac_val;
        (yyval.node)->code=tac+"\n";
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
#line 9357 "lalr1.tab.c"
    break;

  case 353: /* ExclusiveOrExpression: AndExpression  */
#line 5214 "lalr1.y"
                     {
        (yyval.node)=new astnode;
        (yyval.node)->token="ExclusiveOrExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
    }
#line 9375 "lalr1.tab.c"
    break;

  case 354: /* ExclusiveOrExpression: ExclusiveOrExpression XOR AndExpression  */
#line 5227 "lalr1.y"
                                                {
        (yyval.node)=new astnode;
        (yyval.node)->token="ExclusiveOrExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        temp=symtypeEvaluate((yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if((yyvsp[-2].node)->type != (yyvsp[0].node)->type)
        {   if((yyvsp[-2].node)->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" = cast_to_"+temp+" "+(yyvsp[0].node)->tac_val;
                prog.push_back(s1);
                (yyvsp[0].node)->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+(yyvsp[-2].node)->tac_val;
        }
        s2=temp+"^";
        (yyval.node)->type="boolean";
        string temp1=get_tempvar();
        (yyval.node)->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+(yyvsp[-2].node)->tac_val+" "+(yyvsp[-1].node)->lexeme+" "+(yyvsp[0].node)->tac_val;
        (yyval.node)->code=tac+"\n";
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
#line 9416 "lalr1.tab.c"
    break;

  case 355: /* InclusiveOrExpression: ExclusiveOrExpression  */
#line 5265 "lalr1.y"
                             {
        (yyval.node)=new astnode;
        (yyval.node)->token="InclusiveOrExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
    }
#line 9434 "lalr1.tab.c"
    break;

  case 356: /* InclusiveOrExpression: InclusiveOrExpression OR ExclusiveOrExpression  */
#line 5278 "lalr1.y"
                                                       {
        (yyval.node)=new astnode;
        (yyval.node)->token="InclusiveOrExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        temp=symtypeEvaluate((yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if((yyvsp[-2].node)->type != (yyvsp[0].node)->type)
        {   if((yyvsp[-2].node)->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" = cast_to_"+temp+" "+(yyvsp[0].node)->tac_val;
                prog.push_back(s1);
                (yyvsp[0].node)->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+(yyvsp[-2].node)->tac_val;
        }
        s2=temp+"|";
        (yyval.node)->type="boolean";
        string temp1=get_tempvar();
        (yyval.node)->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+(yyvsp[-2].node)->tac_val+" "+(yyvsp[-1].node)->lexeme+" "+(yyvsp[0].node)->tac_val;
        (yyval.node)->code=tac+"\n";
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
#line 9475 "lalr1.tab.c"
    break;

  case 357: /* ConditionalAndExpression: InclusiveOrExpression  */
#line 5316 "lalr1.y"
                             {
        (yyval.node)=new astnode;
        (yyval.node)->token="ConditionalAndExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
    }
#line 9493 "lalr1.tab.c"
    break;

  case 358: /* ConditionalAndExpression: ConditionalAndExpression LAND InclusiveOrExpression  */
#line 5329 "lalr1.y"
                                                            {
        (yyval.node)=new astnode;
        (yyval.node)->token="ConditionalAndExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        temp=symtypeEvaluate((yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if((yyvsp[-2].node)->type != (yyvsp[0].node)->type)
        {   if((yyvsp[-2].node)->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" = cast_to_"+temp+" "+(yyvsp[0].node)->tac_val;
                prog.push_back(s1);
                (yyvsp[0].node)->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+(yyvsp[-2].node)->tac_val;
        }
        s2=temp+"&&";
        (yyval.node)->type="boolean";
        string temp1=get_tempvar();
        (yyval.node)->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+(yyvsp[-2].node)->tac_val+" "+(yyvsp[-1].node)->lexeme+" "+(yyvsp[0].node)->tac_val;
        (yyval.node)->code=tac+"\n";
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
#line 9534 "lalr1.tab.c"
    break;

  case 359: /* ConditionalOrExpression: ConditionalAndExpression  */
#line 5367 "lalr1.y"
                                {
        (yyval.node)=new astnode;
        (yyval.node)->token="ConditionalOrExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
    }
#line 9552 "lalr1.tab.c"
    break;

  case 360: /* ConditionalOrExpression: ConditionalOrExpression LOR ConditionalAndExpression  */
#line 5380 "lalr1.y"
                                                             {
        (yyval.node)=new astnode;
        (yyval.node)->token="ConditionalOrExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        temp=symtypeEvaluate((yyvsp[-2].node)->type,(yyvsp[0].node)->type,(yyvsp[-1].node)->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if((yyvsp[-2].node)->type != (yyvsp[0].node)->type)
        {   if((yyvsp[-2].node)->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" = cast_to_"+temp+" "+(yyvsp[0].node)->tac_val;
                prog.push_back(s1);
                (yyvsp[0].node)->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+(yyvsp[-2].node)->tac_val;
        }
        s2=temp+"||";
        (yyval.node)->type="boolean";
        string temp1=get_tempvar();
        (yyval.node)->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+(yyvsp[-2].node)->tac_val+" "+(yyvsp[-1].node)->lexeme+" "+(yyvsp[0].node)->tac_val;
        (yyval.node)->code=tac+"\n";
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
#line 9593 "lalr1.tab.c"
    break;

  case 361: /* ConditionalExpression: ConditionalOrExpression  */
#line 5418 "lalr1.y"
                               {
        (yyval.node)=new astnode;
        (yyval.node)->token="ConditionalExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
    }
#line 9611 "lalr1.tab.c"
    break;

  case 362: /* ConditionalExpression: ConditionalOrExpression CONDMARK1 QMARK Expression CONDMARK2 COLON ConditionalExpression CONDMARK3  */
#line 5431 "lalr1.y"
                                                                                                            {
        (yyval.node)=new astnode;
        (yyval.node)->token="ConditionalExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[-7].node));
        v.push_back((yyvsp[-5].node));
        v.push_back((yyvsp[-4].node));
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        (yyval.node)->children=v;
        temp=symtypeEvaluate((yyvsp[-4].node)->type,(yyvsp[-1].node)->type);
        if(temp=="0")
        {
            // yyerror("Error, type incompatible");
        }
        (yyval.node)->type=temp;
        // string temp=get_tempvar();
        // $$->tac_val=temp;
        // string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        // tac=to_string(line++)+" "+tac; prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
#line 9639 "lalr1.tab.c"
    break;

  case 363: /* AssignmentExpression: ConditionalExpression  */
#line 5456 "lalr1.y"
                             {
        (yyval.node)=new astnode;
        (yyval.node)->token="AssignmentExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
    }
#line 9657 "lalr1.tab.c"
    break;

  case 364: /* AssignmentExpression: Assignment  */
#line 5469 "lalr1.y"
                   {
        (yyval.node)=new astnode;
        (yyval.node)->token="AssignmentExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 9673 "lalr1.tab.c"
    break;

  case 365: /* Assignment: LeftHandSide AssignmentOperator AssignmentExpression  */
#line 5482 "lalr1.y"
                                                            {
        (yyval.node)=new astnode;
        (yyval.node)->token="Assignment";
        vector<astnode*>v;
        v.push_back((yyvsp[-2].node));
        v.push_back((yyvsp[-1].node));
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // string temp=get_tempvar();
        (yyval.node)->tac_val=(yyvsp[-2].node)->tac_val;
        string tac="";
        // tac=tac+$2->tac_val+","+$1->tac_val+","+$3->tac_val+","+$1->tac_val;
        // cout<<"in"<<$$->token;
        if((yyvsp[0].node)->type=="String" && !((yyvsp[-1].node)->lexeme=="+="||(yyvsp[-1].node)->lexeme=="="))
        {
            cout<<"String operation undefined";
            // exit(0);
        }
        // check for Strings once
        temp=symAssignment((yyvsp[-2].node)->type,(yyvsp[0].node)->type);
        // cout<<$1->type<<" "<<$3->type;
       if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        // if(($1->flag==4&&$3->flag!=4)||($1->flag!=4&&$3->flag==4)) cout<<"Error, type incompatible";
        // cout<<$1->flag<<" "<<$3->flag;
        if((yyvsp[-2].node)->flag==4||(yyvsp[0].node)->flag==4) {
            Type*t=symtabGetTypep(fullscope,(yyvsp[-2].node)->value);
            if(t){
                // cout<<" "<<t->dims<<" "<<$1->value<<" "<<$3->dims<<endl;
                if(t->dims!=(yyvsp[0].node)->dims) cout<<"Error, dims are different";
            }
        }
        if((yyvsp[-2].node)->type != (yyvsp[0].node)->type)
        {   
            s1="typecast_to_"+temp+" t"+to_string(tempno-1);
            string t=get_tempvar();
            s1=t+" ="+s1;
            prog.push_back(s1);
        }
        s2=(yyvsp[-1].node)->tac_val+temp;
        // temp="int";
        if((yyvsp[0].node)->flag==1)
        tac=(yyvsp[-2].node)->tac_val+" "+s2+" t"+to_string(tempno-1);
        else tac=(yyvsp[-2].node)->tac_val+" "+s2+" "+(yyvsp[0].node)->tac_val;
        (yyval.node)->code=tac+"\n";
        tac=to_string(line++)+" "+tac; prog.push_back(tac);
        (yyval.node)->type=temp;
    }
#line 9728 "lalr1.tab.c"
    break;

  case 366: /* LeftHandSide: Name  */
#line 5534 "lalr1.y"
            {
        (yyval.node)=new astnode;
        (yyval.node)->token="LeftHandSide";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->value=(yyvsp[0].node)->value;
        // cout<<"in"<<$$->token;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 9744 "lalr1.tab.c"
    break;

  case 367: /* LeftHandSide: FieldAccess  */
#line 5545 "lalr1.y"
                    {
        (yyval.node)=new astnode;
        (yyval.node)->token="LeftHandSide";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 9759 "lalr1.tab.c"
    break;

  case 368: /* LeftHandSide: ArrayAccess  */
#line 5555 "lalr1.y"
                    {
        (yyval.node)=new astnode;
        (yyval.node)->token="LeftHandSide";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        // cout<<"in"<<$$->token;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->type=(yyvsp[0].node)->type;
        Type*t=symtabGetTypep(fullscope,(yyvsp[0].node)->value);
        if(t){
            if(t->dims!=(yyvsp[0].node)->dims) cout<<"Error dimension incorrect";
        }
    }
#line 9778 "lalr1.tab.c"
    break;

  case 369: /* AssignmentOperator: ASSIGN  */
#line 5571 "lalr1.y"
          {
        (yyval.node)=new astnode;
        (yyval.node)->token="AssignmentOperator";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->lexeme;
        // cout<<"in"<<$$->token;
    }
#line 9792 "lalr1.tab.c"
    break;

  case 370: /* AssignmentOperator: MUL_ASSIGN  */
#line 5580 "lalr1.y"
                {
        (yyval.node)=new astnode;
        (yyval.node)->token="AssignmentOperator";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->lexeme;
        // cout<<"in"<<$$->token;
    }
#line 9806 "lalr1.tab.c"
    break;

  case 371: /* AssignmentOperator: QUO_ASSIGN  */
#line 5589 "lalr1.y"
                {
        (yyval.node)=new astnode;
        (yyval.node)->token="AssignmentOperator";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->lexeme;
        // cout<<"in"<<$$->token;
    }
#line 9820 "lalr1.tab.c"
    break;

  case 372: /* AssignmentOperator: REM_ASSIGN  */
#line 5598 "lalr1.y"
                {
        (yyval.node)=new astnode;
        (yyval.node)->token="AssignmentOperator";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->lexeme;
        // cout<<"in"<<$$->token;
    }
#line 9834 "lalr1.tab.c"
    break;

  case 373: /* AssignmentOperator: ADD_ASSIGN  */
#line 5607 "lalr1.y"
                {
        (yyval.node)=new astnode;
        (yyval.node)->token="AssignmentOperator";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->lexeme;
        // cout<<"in"<<$$->token;
    }
#line 9848 "lalr1.tab.c"
    break;

  case 374: /* AssignmentOperator: SUB_ASSIGN  */
#line 5616 "lalr1.y"
                {
        (yyval.node)=new astnode;
        (yyval.node)->token="AssignmentOperator";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->lexeme;
        // cout<<"in"<<$$->token;
    }
#line 9862 "lalr1.tab.c"
    break;

  case 375: /* AssignmentOperator: SHL_ASSIGN  */
#line 5625 "lalr1.y"
                {
        (yyval.node)=new astnode;
        (yyval.node)->token="AssignmentOperator";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->lexeme;
        // cout<<"in"<<$$->token;
    }
#line 9876 "lalr1.tab.c"
    break;

  case 376: /* AssignmentOperator: SHR_ASSIGN  */
#line 5634 "lalr1.y"
                {
        (yyval.node)=new astnode;
        (yyval.node)->token="AssignmentOperator";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->lexeme;
        // cout<<"in"<<$$->token;
    }
#line 9890 "lalr1.tab.c"
    break;

  case 377: /* AssignmentOperator: GEQUAL  */
#line 5643 "lalr1.y"
            {
        (yyval.node)=new astnode;
        (yyval.node)->token="AssignmentOperator";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->lexeme;
        // cout<<"in"<<$$->token;
    }
#line 9904 "lalr1.tab.c"
    break;

  case 378: /* AssignmentOperator: AND_ASSIGN  */
#line 5652 "lalr1.y"
                {
        (yyval.node)=new astnode;
        (yyval.node)->token="AssignmentOperator";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->lexeme;
        // cout<<"in"<<$$->token;
    }
#line 9918 "lalr1.tab.c"
    break;

  case 379: /* AssignmentOperator: XOR_ASSIGN  */
#line 5661 "lalr1.y"
                {
        (yyval.node)=new astnode;
        (yyval.node)->token="AssignmentOperator";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->lexeme;
        // cout<<"in"<<$$->token;
    }
#line 9932 "lalr1.tab.c"
    break;

  case 380: /* AssignmentOperator: OR_ASSIGN  */
#line 5670 "lalr1.y"
               {
        (yyval.node)=new astnode;
        (yyval.node)->token="AssignmentOperator";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->lexeme;
        // cout<<"in"<<$$->token;
    }
#line 9946 "lalr1.tab.c"
    break;

  case 381: /* Expression: AssignmentExpression  */
#line 5681 "lalr1.y"
                            {
        (yyval.node)=new astnode;
        (yyval.node)->token="Expression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
        (yyval.node)->dims=(yyvsp[0].node)->dims;
    }
#line 9964 "lalr1.tab.c"
    break;

  case 382: /* ConstantExpression: Expression  */
#line 5696 "lalr1.y"
                  {
        (yyval.node)=new astnode;
        (yyval.node)->token="ConstantExpression";
        vector<astnode*>v;
        v.push_back((yyvsp[0].node));
        (yyval.node)->children=v;
        (yyval.node)->tac_val=(yyvsp[0].node)->tac_val;
        (yyval.node)->code=(yyvsp[0].node)->code;
        // cout<<"in"<<$$->token;
        (yyval.node)->flag=(yyvsp[0].node)->flag;
        (yyval.node)->type=(yyvsp[0].node)->type;
    }
#line 9981 "lalr1.tab.c"
    break;


#line 9985 "lalr1.tab.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 5709 "lalr1.y"



int nodeId = 0;
void prettyPrint(ofstream&astfile,astnode* root){
    // if((root->children.size()==1)&&(root->children[0]!=NULL)){
    //     while((root->children.size()==1)&&(root->children[0]!=NULL)){
    //         root=root->children[0];
    //     }
    // }
    if(root->token=="STR_LIT"){
        string str=root->token;
        str+="(";
        string str1=root->lexeme;
        str1=str1.substr(1,str1.length()-2);
        str+=str1;
        str+=")";
        astfile << nodeId << " [label=\"" << str << "\"]" << endl;
    }
    else if(root->lexeme!="lexeme"){
        string str=root->token;
        str+="(";
        str+=root->lexeme;
        str+=")";
        astfile << nodeId << " [label=\"" << str << "\"]" << endl;
    }
    else {
        astfile << nodeId << " [label=\"" << root->token << "\"]" << endl;
        
    }
	int parentId = nodeId;
	for(auto child : root->children){
        if(child) {
            astfile << parentId << "->" << ++nodeId << endl;
            prettyPrint(astfile,child);
        }
	}
}

// int main (int argc, char **argv) {
//     if(argc==2) {
//         yyin=fopen(argv[1],"r");
//         yyparse();
//     }
// 	// yyparse ( );
// 	// redirect ostream to file
// 	ofstream myfile;
// 	myfile.open ("ast.dot");
// 	cout.rdbuf(myfile.rdbuf());
// 	cout << "digraph \"src/parser.ypp\" \n { \n node [fontname = courier, shape = box, colorscheme = paired6] \n edge [fontname = courier]" << endl;
// 	prettyPrint(theprogram);
// 	cout << "}" << endl;
// }

void print_tac( ofstream& tac){
    // tac<<"op"<<","<<"arg1"<<","<<"arg2"<<","<<"result"<<endl;
	int i=0,l=prog.size();
    for(i=0;i<l;i++) {
        tac<<prog[i]<<endl;
    }
}

void print_symtab( ){
    ofstream symtabf;
    int count=0;
	string curr_fcn_scope = "";
    symtab_t* sym;
    
	for( auto symt : symtab_top ){

        symtabf.open("SymbolTable"+to_string(count++)+".csv");
        symtabf<<"name"<<","<<"lineno"<<","<<"type"<<","<<"size"<<","<<"args"<<","<<"access_specifier"<<","<<"dims"<<","<<"flag"<<","<<"offset"<<endl;
		curr_fcn_scope = symt.first;
	    symtabf <<"----Symbtab for scope "<< curr_fcn_scope <<"----"<<endl;
	// symbolTable <<"Scope_num Sym_name"<<endl;
	for( auto i=(symt.second)->begin(); i != (symt.second)->end(); i++ ){
		// symbolTable <<i->first;
		if( i->second != NULL ) {
			// symbolTable << " " << i->second->type <<endl;
            // if(i->second->args!="args") symbolTable<<i->second->access_specifier<<" "<<i->second->type<< " " <<i->first  <<" "<<i->second->args <<endl;
            // else symbolTable  << i->second->type<<" " <<i->first<<endl;
            symtabf<<i->first<<","<<i->second->lineno<<","<<i->second->type<<","<<i->second->size<<","<<i->second->args<<","<<i->second->access_specifier<<","<<i->second->dims<<","<<i->second->flag<<","<<i->second->offset<<endl;
        }
	}
	symtabf <<endl<<"----DONE----"<<endl<<endl;
    symtabf.close();
}
}

// void print_symtab( ofstream& symbolTable){
// 	string curr_fcn_scope = "";
//     symtab_t* sym;
//     symbolTable<<"name"<<","<<"lineno"<<","<<"type"<<","<<"size"<<","<<"args"<<","<<"access_specifier"<<endl;
// 	for( auto symt : symtab_top ){
// 		// if( symtab == i.second ){
// 			curr_fcn_scope = symt.first;
// 		// 	break;
// 		// }
// 	// sym=symt.second;
// 	symbolTable <<"----Symbtab for scope "<< curr_fcn_scope <<"----"<<endl;
// 	// symbolTable <<"Scope_num Sym_name"<<endl;
// 	for( auto i=(symt.second)->begin(); i != (symt.second)->end(); i++ ){
// 		// symbolTable <<i->first;
// 		if( i->second != NULL ) {
// 			// symbolTable << " " << i->second->type <<endl;
//             // if(i->second->args!="args") symbolTable<<i->second->access_specifier<<" "<<i->second->type<< " " <<i->first  <<" "<<i->second->args <<endl;
//             // else symbolTable  << i->second->type<<" " <<i->first<<endl;
//             symbolTable<<i->first<<","<<i->second->lineno<<","<<i->second->type<<","<<i->second->size<<","<<i->second->args<<","<<i->second->access_specifier<<endl;
//         }
// 	}
// 	symbolTable <<endl<<"----DONE----"<<endl<<endl;
// }
// }

// int nodeId = 0;
// void prettyPrint(ofstream& astFile, astnode* root){
//     if(root->token=="STR_LIT"){
//         string str=root->token;
//         str+="(";
//         string str1=root->lexeme;
//         str1=str1.substr(1,str1.length()-2);
//         str+=str1;
//         str+=")";
//         astFile << nodeId << " [label=\"" << str << "\"]" << endl;
//     }
//     else if(root->lexeme!="lexeme"){
//         string str=root->token;
//         str+="(";
//         str+=root->lexeme;
//         str+=")";
//         astFile << nodeId << " [label=\"" << str << "\"]" << endl;
//     }
//     else {
//         if(root->children.size()!=1)
//         astFile << nodeId << " [label=\"" << root->token << "\"]" << endl;
        
//     }
// 	int parentId = nodeId;
// 	for(auto child : root->children){
//         if(child) {
//             if(root->children.size()!=1)
//                 astFile << parentId << "->" << ++nodeId << endl;
//             prettyPrint(astFile,child);
//         }
// 	}
// }

int main (int argc, char **argv) {
    string outputfile="ast.dot";
    // cout<<"hello"<<argc<<" "<<*argv<<argv[1];
    // if(argv[1]=="-help"){
    //                 cout<<"For the given AST generator, we have to run the file using the following command: ./a.out <command-line arguments>\n_________________\n-help    option is passed as the first argument to know how to pass command line arguments to AST generator\nThe first command line argument is always the input file if \"-help\" option is not used.\n-verbose    option is used for verbose error displaying\n-output    option is used to set the name of the output dot file. This is done using the following syntax: =<filename.dot>. For example -output=hi.dot\n_________________";
    //                 exit(0);
    //             }
    string y;
    switch(argc){
        case 2: y=argv[1];if(y=="-help"){
                    cout<<"For the given AST generator, we have to run the file using the following command: ./a.out <command-line arguments>\n_________________\n-help    option is passed as the first argument to know how to pass command line arguments to AST generator\nThe first command line argument is always the input file if \"-help\" option is not used.\n-verbose    option is used for verbose error displaying\n-output    option is used to set the name of the output dot file. This is done using the following syntax: =<filename.dot>. For example -output=hi.dot\n_________________";
                    return 0;
                }
                else break;
        case 3: y=argv[2];if(y=="-verbose"){
                    verb=1;
                    break;
                }
                else{
                    string x=argv[2];
                    outputfile=x.substr(8);
                    break;
                }
        case 4: y=argv[2];if(y=="-verbose"){
                    string x=argv[3];
                    outputfile=x.substr(8);
                }
                else{
                    string x=argv[2];
                    outputfile=x.substr(8);
                }
                verb=1;
                break;
        default: cout<<"Incorrect command line arguments, please use -help option to understand how to use them!";
    }

    // map<string,Type*>::iterator it=(*(symtab_top["r"])).begin();
    // while(it!=(*(symtab_top["r"])).end()){
    //     cout<<it->first<<" ";
    //     ++it;
    // }cout<<'\n';
    // map<string,Type*>m=(*(symtab_top["0"]));

	yyin=fopen(argv[1],"r");
    symbolTable.open("symbolTable.csv");
    tac.open("tac.txt");
    yyparse();
    // cout<<"\n"<<symtab_top.size()<<"\n";
	// ofstream myfile(outputfile);
    // //  ofstream myfile("ast.dot");

	// cout.rdbuf(myfile.rdbuf());
	// cout << "digraph \"src/parser.ypp\" \n { \n node [fontname = courier, shape = box, colorscheme = paired6] \n edge [fontname = courier]" << endl;
    // cout << "0" << " [label=\"" << theprogram->token << "\"]" << endl;
    // cout << "0" << "->" << ++nodeId << endl;
	// prettyPrint(theprogram);
	// cout << "}" << endl;

    ofstream astFile;
	astFile.open("ast.dot" );
    astFile << "digraph \"src/parser.ypp\" \n { \n node [fontname = courier, shape = box, colorscheme = paired6] \n edge [fontname = courier]" << endl;
	prettyPrint(astFile, theprogram);
	astFile << "}" << endl;
	astFile.close();
    cout<<"\ndone ast file\n";

    // print_symtab(symbolTable);
    print_symtab();
    cout<<"\ndone print symtab\n";

    // for(int i=0;i<prog.size();i++) {
    //     cout<<prog[i]<<endl;
    // }
    print_tac(tac);
    cout<<"\ndone prog\n";
    return 0;
}


int yyerror(const char*msg) {
	cout<<"ERROR in: "<<yylineno<<'\n';
    if(verb==1)
    cout<<msg<<'\n';
    exit(0);
    // return 0;
};
