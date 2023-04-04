%{
#include "lalr1.tab.h"
#include<iostream>
using namespace std;
#define yyterminate() return END;
%}
%option yylineno
DECIMAL [0-9]
BINARY [0-1]
HEXA [0-9A-Fa-f]
OCTA [0-7]
IDENTIFIER [a-zA-Z$_][a-zA-Z0-9$_]*
KEYWORD "abstract"|"continue"|"for"|"new"|"switch"|"assert"|"default"|"if"|"package"|"synchronized"|"boolean"|"do"|"goto"|"private"|"this"|"break"|"double"|"implements"|"protected"|"throw"|"byte"|"else"|"import"|"public"|"throws"|"case"|"enum"|"instanceof"|"return"|"transient"|"catch"|"extends"|"int"|"short"|"try"|"char"|"final"|"interface"|"static"|"void"|"class"|"finally"|"long"|"strictfp"|"volatile"|"const"|"float"|"native"|"super"|"while"|"_"|"exports"|"opens"|"requires"|"uses"|"module"|"permits"|"sealed"|"var"|"non-sealed"|"provides"|"to"|"with"|"open"|"record"|"transitive"|"yield"
OPERATOR "="|">"|"<"|"!"|"~"|"?"|":"|"->"|"=="|">="|"<="|"!="|"&&"|"||"|"++"|"--"|"+"|"-"|"*"|"/"|"&"|"|"|"^"|"%"|"<<"|">>"|">>>"|"+="|"-="|"*="|"/="|"&="|"|="|"^="|"%="|"<<="|">>="|">>>="
SEPARATOR "("|")"|"{"|"}"|"["|"]"|";"|","|"."|"..."|"@"|"::"
TEXT [^\\\"]
ESCAPE "\\b"|"\\s"|"\\t"|"\\n"|"\\f"|"\\r"|"\\\""|"\\\'"|"\\\\"|"\\0"|"\\1"|"\\2"|"\\3"|"\\4"|"\\5"|"\\6"|"\\7"
%%


[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]
"//"[^\n\r]*

"System.out.println(" { 
                        yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="PRINTLN";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return PRINTLN;
}

"+"					{  yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="ADD";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return ADD;
                    }
"-"					{ yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="SUB";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return SUB;
                    }
"*"					{ yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="MUL";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return MUL;
                    }
"/"					{ yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="QUO";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return QUO;
                    }
"%"					{ yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="REM";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return REM;
                    }

"&"					{ yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="AND";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return AND;
                    }

"|"					{ yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="OR";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return OR;
                    }

"^"					{ yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="XOR";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return XOR;
                    }

"<<"				{ yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="SHL";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return SHL;
                    }

">>"			    { yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="SHR";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return SHR;
                    }

">>>"				{ yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="GR";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return GR;
                    }             //

"+="				{ yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="ADD_ASSIGN";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return ADD_ASSIGN;
                    }

"-="				{ yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="SUB_ASSIGN";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return SUB_ASSIGN;
                    }

"*="			    { yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="MUL_ASSIGN";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return MUL_ASSIGN;
                    }

"/="				{ yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="QUO_ASSIGN";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return QUO_ASSIGN;
                    }

"%="				{ yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="REM_ASSIGN";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return REM_ASSIGN;
                    }

"&="				        { yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="AND_ASSIGN";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return AND_ASSIGN;}

"|="				        { yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="OR_ASSIGN";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return OR_ASSIGN;}
                        
"^="				        { yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="XOR_ASSIGN";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return XOR_ASSIGN;}

"<<="				        { yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="SHL_ASSIGN";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return SHL_ASSIGN;}

">>="				        { yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="SHR_ASSIGN";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return SHR_ASSIGN;}

">>>="				        { yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="GEQUAL";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return GEQUAL;}                   //


"&&"				        {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="LAND";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                         return LAND;}

"||"				        { yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="LOR";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return LOR;}

"++"				        {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="INC";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                         return INC;}

"--"				        { yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="DEC";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return DEC;}

"=="				        { yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="EQL";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return EQL;}

"!="				        {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="NEQ";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                         return NEQ;}

"<="				        { yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="LEQ";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return LEQ;}

">="				        { yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="GEQ";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return GEQ;}

"="					{ yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="ASSIGN";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return ASSIGN;}  

"->"				        { yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="ARROW";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return ARROW;}

">"				        { yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="GTR";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return GTR;}

"<"					{yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="LSS";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                         return LSS;}

"!"					{ yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="NOT";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return NOT;}

"~"                { yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="TILDE";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return TILDE;}

"?"                { yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="QMARK";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return QMARK;}


"..."				        { yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="ELLIPSIS";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return ELLIPSIS;}

","					{ yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="COMMA";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return COMMA;}

";"					{ yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="SEMICOLON";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return SEMICOLON;}

"::"                {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="DCOLON";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return DCOLON; }

":"					{ yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="COLON";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return COLON;}

"."					{ yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="PERIOD";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return PERIOD;}

"@"                 { yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="AMPERSAT";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return AMPERSAT; }


"[" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="OPEN_SQ";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return OPEN_SQ;}

"]" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="CLOSE_SQ";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return CLOSE_SQ;}

"{" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="OPEN_CR";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return OPEN_CR;}

"}" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="CLOSE_CR";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return CLOSE_CR;}

"(" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="OPEN_BR";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return OPEN_BR;}

")" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="CLOSE_BR";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return CLOSE_BR;}

"0"[lL]?|[1-9]{DECIMAL}*([0-9_]*{DECIMAL}+)?[lL]?|("0x"|"0X"){HEXA}+([0-9a-fA-F_]*{HEXA}+)?[lL]?|("0b"|"0B"){BINARY}+([0-1_]*{BINARY}+)?[lL]?|"0"{OCTA}+([0-7_]*{OCTA}+)?[lL]? {
    yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="INT_LIT";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return INT_LIT;}

({DECIMAL}+([0-9_]*{DECIMAL}+)?)"."({DECIMAL}+([0-9_]*{DECIMAL}+)?)?([eE][+-]?{DECIMAL}+([0-9_]*{DECIMAL}+)?)?[fFdD]?|({DECIMAL}+([0-9_]*{DECIMAL}+)?)?"."({DECIMAL}+([0-9_]*{DECIMAL}+)?)([eE][+-]?{DECIMAL}+([0-9_]*{DECIMAL}+)?)?[fFdD]?|("0x"|"0X")({HEXA}+([0-9a-fA-F_]*{HEXA}+)?)"."({HEXA}+([0-9a-fA-F_]*{HEXA}+)?)?([pP][+-]?{HEXA}+([0-9a-fA-F_]*{HEXA}+)?)?[fFdD]?|("0x"|"0X")({HEXA}+([0-9a-fA-F_]*{HEXA}+)?)?"."({HEXA}+([0-9a-fA-F_]*{HEXA}+)?)([pP][+-]?{HEXA}+([0-9a-fA-F_]*{HEXA}+)?)?[fFdD]? {
    yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="FLOAT_LIT";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return FLOAT_LIT;}

"\'"[^\n\'\\]"\'" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="CHAR_LIT";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return CHAR_LIT;}

"\""[^\n\\\"]*({ESCAPE}[^\n\\\"]*)*[^\n\\\"]*"\"" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="STR_LIT";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return STR_LIT;}

"\'""\\"{ESCAPE}"\'" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="CHAR_LIT";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return CHAR_LIT;}

"\"\"\""[ \t\f]*[\n\r]+({TEXT}|{ESCAPE})*(\"{0,2}({TEXT}|{ESCAPE})+)*({TEXT}|{ESCAPE})*"\"\"\"" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="TXT_BLK";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return TXT_BLK;}


"true"|"false" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="BOOL_LIT";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return BOOL_LIT;}

"null" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="NULL_LIT";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return NULL_LIT;}

"abstract" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="ABSTRACT";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return ABSTRACT;}

"continue" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="CONTINUE";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return CONTINUE;}

"for" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="FOR";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return FOR;}

"new" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="NEW";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return NEW;}

"switch" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="SWITCH";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return SWITCH;}

"assert" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="ASSERT";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return ASSERT;}

"default" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="DEFAULT";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return DEFAULT;}

"if" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="IF";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return IF;}

"package" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="PACKAGE";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return PACKAGE;}

"synchronized" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="SYNCHRONIZED";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return SYNCHRONIZED;}

"boolean" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="BOOLEAN";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return BOOLEAN;}

"do" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="DO";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return DO;}

"goto" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="GOTO";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return GOTO;}

"private" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="PRIVATE";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return PRIVATE;}

"this" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="THIS";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return THIS;}

"break" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="BREAK";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return BREAK;}

"double" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="DOUBLE";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return DOUBLE;}

"implements" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="IMPLEMENTS";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return IMPLEMENTS;}

"protected" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="PROTECTED";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return PROTECTED;}

"throw" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="THROW";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return THROW;}

"byte" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="BYTE";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return BYTE;}

"else" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="ELSE";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return ELSE;}

"import" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="IMPORT";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return IMPORT;}

"public" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="PUBLIC";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return PUBLIC;}

"throws" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="THROWS";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return THROWS;}

"case" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="CASE";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return CASE;}

"enum" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="ENUM";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return ENUM;}

"instanceof" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="INSTANCEOF";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return INSTANCEOF;}

"return" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="RETURN";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return RETURN;}

"transient" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="TRANSIENT";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return TRANSIENT;}

"catch" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="CATCH";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return CATCH;}

"extends" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="EXTENDS";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        return EXTENDS;}

"int" {
    yylval.node=new astnode;
    (yylval.node)->lexeme=strdup(yytext);
    (yylval.node)->token="INT";
    vector<astnode*>v;
    v.push_back(NULL);
    (yylval.node)->children=v;
    // cout<<(yylval.node)->lexeme<<(yylval.node)->children[0]<<'\n';
//    yylval.str=strdup(yytext);
    return INT;
}
"short" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="SHORT";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        
//    yylval.str=strdup(yytext);
    return SHORT;
}
"try" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="TRY";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        
//    yylval.str=strdup(yytext);
    return TRY;
}
"char" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="CHAR";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        
//    yylval.str=strdup(yytext);
    return CHAR;
}
"final" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="FINAL";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        
//    yylval.str=strdup(yytext);
    return FINAL;
}
"interface" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="INTERFACE";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        
//    yylval.str=strdup(yytext);
    return INTERFACE;
}
"static" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="STATIC";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        
//    yylval.str=strdup(yytext);
    return STATIC;
}
"void" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="VOID";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        
//    yylval.str=strdup(yytext);
    return VOID;
}
"class" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="CLASS";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        
//    yylval.str=strdup(yytext);
    return CLASS;
}
"finally" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="FINALLY";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        
//    yylval.str=strdup(yytext);
    return FINALLY;
}
"long" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="LONG";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        
//    yylval.str=strdup(yytext);
    return LONG;
}
"strictfp" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="STRICTFP";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        
//    yylval.str=strdup(yytext);
    return STRICTFP;
}
"volatile" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="VOLATILE";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        
//    yylval.str=strdup(yytext);
    return VOLATILE;
}
"const" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="CONST";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        
//    yylval.str=strdup(yytext);
    return CONST;
}
"float" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="FLOAT";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        
//    yylval.str=strdup(yytext);
    return FLOAT;
}
"native" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="NATIVE";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        
//    yylval.str=strdup(yytext);
    return NATIVE;
}
"super" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="SUPER";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        
//    yylval.str=strdup(yytext);
    return SUPER;
}
"while" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="WHILE";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        
//    yylval.str=strdup(yytext);
    return WHILE;
}
"_" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="_";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        
//    yylval.str=strdup(yytext);
    return _;
}
"exports" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="EXPORTS";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        
//    yylval.str=strdup(yytext);
    return EXPORTS;
}
"opens" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="OPENS";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        
//    yylval.str=strdup(yytext);
    return OPENS;
}
"requires" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="REQUIRES";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        
//    yylval.str=strdup(yytext);
    return REQUIRES;
}
"uses" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="USES";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        
//    yylval.str=strdup(yytext);
    return USES;
}
"module" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="MODULE";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        
//    yylval.str=strdup(yytext);
    return MODULE;
}
"permits" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="PERMITS";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        
//    yylval.str=strdup(yytext);
    return PERMITS;
}
"sealed" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="SEALED";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        
//    yylval.str=strdup(yytext);
    return SEALED;
}
"var" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="VAR";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        
//    yylval.str=strdup(yytext);
    return VAR;
}

"provides" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="PROVIDES";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        
//    yylval.str=strdup(yytext);
    return PROVIDES;
}
"to" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="TO";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        
//    yylval.str=strdup(yytext);
    return TO;
}
"with" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="WITH";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        
//    yylval.str=strdup(yytext);
    return WITH;
}
"open" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="OPEN";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        
//    yylval.str=strdup(yytext);
    return OPEN;
}
"record" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="RECORD";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        
//    yylval.str=strdup(yytext);
    return RECORD;
}
"transitive" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="TRANSITIVE";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        
//    yylval.str=strdup(yytext);
    return TRANSITIVE;
}
"yield" {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="YIELD";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        
//    yylval.str=strdup(yytext);
    return YIELD;
}

{IDENTIFIER}+ {yylval.node=new astnode;
                        (yylval.node)->lexeme=strdup(yytext);
                        (yylval.node)->token="IDENTIFIER";
                         vector<astnode*>v;
                         v.push_back(NULL);
                        (yylval.node)->children=v;
                        
    // yylval.str=strdup(yytext);
    return IDENTIFIER;
}

[ \t\f\n\r]+

. {
    cout<<"ERROR in Line Number: "<<yylineno<<" in sequence: "<<yytext<<'\n';
}

<<EOF>> {return 0;}

%%
int yywrap(){
    return 1;
}