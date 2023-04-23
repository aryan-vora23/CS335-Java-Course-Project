%{
    #include "lalr1.tab.h"
    #include<bits/stdc++.h>
    #include<fstream>
    #include "symtab.h"
    #include "tac_convert.h"
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
%}
%define parse.error verbose
%code requires{
	#include "ast.h"
}
%union {
	astnode *node;
}

%token<node> OPERATOR OPEN_SQ CLOSE_SQ OPEN_BR CLOSE_BR OPEN_CR CLOSE_CR SEPERATOR INT_LIT FLOAT_LIT CHAR_LIT STR_LIT TXT_BLK BOOL_LIT NULL_LIT KEYWORD ABSTRACT CONTINUE FOR NEW SWITCH ASSERT DEFAULT IF PACKAGE SYNCHRONIZED BOOLEAN DO GOTO PRIVATE THIS BREAK DOUBLE IMPLEMENTS PROTECTED THROW BYTE ELSE IMPORT PUBLIC THROWS CASE ENUM INSTANCEOF RETURN TRANSIENT CATCH EXTENDS INT SHORT TRY CHAR FINAL INTERFACE STATIC VOID CLASS FINALLY LONG STRICTFP VOLATILE CONST FLOAT NATIVE SUPER WHILE _ EXPORTS OPENS REQUIRES USES MODULE PERMITS SEALED VAR NON-SEALED PROVIDES TO WITH OPEN RECORD TRANSITIVE YIELD IDENTIFIER
%token<node> ADD SUB MUL QUO REM AND OR XOR SHL SHR GR ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN QUO_ASSIGN REM_ASSIGN AND_ASSIGN OR_ASSIGN XOR_ASSIGN SHL_ASSIGN SHR_ASSIGN GEQUAL LAND LOR INC DEC EQL NEQ LEQ GEQ ASSIGN ARROW GTR LSS NOT TILDE QMARK ELLIPSIS COMMA SEMICOLON DCOLON COLON PERIOD AMPERSAT PRINTLN
%type<node> SYMTABE SYMTABS
%type<node> input Literal Type PrimitiveType NumericType IntegralType FloatingPointType ReferenceType ClassOrInterfaceType ClassType ArrayType Name SingularName ComplexName CompilationUnit ImportDeclarations TypeDeclarations 
%type<node>PackageDeclaration ImportDeclaration SingleTypeImportDeclaration TypeImportOnDemandDeclaration TypeDeclaration Modifiers Modifier ClassDeclaration Super Interfaces InterfaceType InterfaceTypeList ClassBody ClassBodyDeclarations
%type<node>ClassBodyDeclaration ClassMemberDeclaration FieldDeclaration VariableDeclarators VariableDeclarator VariableDeclaratorId VariableInitializer MethodDeclaration MethodHeader MethodDeclarator FormalParameterList 
%type<node>FormalParameter Throws ClassTypeList MethodBody StaticInitializer ConstructorDeclaration ConstructorDeclarator ConstructorBody ExplicitConstructorInvocation InterfaceDeclaration ExtendsInterfaces InterfaceBody
%type<node>InterfaceMemberDeclarations InterfaceMemberDeclaration ConstantDeclaration AbstractMethodDeclaration ArrayInitializer VariableInitializers Block BlockStatements BlockStatement LocalVariableDeclarationStatement 
%type<node>LocalVariableDeclaration Statement StatementNoShortIf StatementWithoutTrailingSubstatement EmptyStatement LabeledStatement LabeledStatementNoShortIf ExpressionStatement StatementExpression IfThenStatement 
%type<node>IfThenElseStatement IfThenElseStatementNoShortIf SwitchStatement SwitchBlock SwitchBlockStatementGroups SwitchBlockStatementGroup  SwitchLabels SwitchLabel WhileStatement WhileStatementNoShortIf DoStatement 
%type<node>ForStatement ForStatementNoShortIf ForInit ForUpdate StatementExpressionList BreakStatement ContinueStatement ReturnStatement ThrowStatement Catches CatchClause Finally 
%type<node>Primary PrimaryNoNewArray ClassInstanceCreationExpression ArgumentList ArrayCreationExpression DimExprs DimExpr  Dims FieldAccess MethodInvocation ArrayAccess PostfixExpression PostIncrementExpression 
%type<node>PostDecrementExpression  UnaryExpression PreIncrementExpression PreDecrementExpression UnaryExpressionNotPlusMinus CastExpression MultiplicativeExpression  AdditiveExpression ShiftExpression  RelationalExpression
%type<node>EqualityExpression AndExpression ExclusiveOrExpression ConditionalOrExpression ConditionalExpression AssignmentExpression  Assignment LeftHandSide AssignmentOperator  Expression ConstantExpression
%type<node>SynchronizedStatement TryStatement InclusiveOrExpression ConditionalAndExpression FunctionName FormalParameterLists ClassName ConstructorName
%type<node>PrintStatement PrintArgs PrintArg
%%
//-----------------------Syntactic-------------------------
input: CompilationUnit {
    theprogram=new astnode;
    theprogram->token="input";
    vector<astnode*>v;
    v.push_back($1);
    theprogram->children=v;
    // if(symtab!=nullptr)
    // delete symtab;
    // cout<<"in input";
    // cout<<endl;
    // exit(0);
    // prettyPrint($$);
    // cout<<$$->token<<" "<<(($$->children)[0])->token;
}
;

//-----------------------Symbol table T---------------------
SYMTABS:
	/*empty*/ {
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
;

SYMTABE:
	/*empty*/ {
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
;

//----------------------Markers---------------------------
IFMARK1:
    {
        string tac,togo_label;
        togo_label=get_label();
        tac="if (t"+to_string(tempno-1)+"=1) goto "+togo_label;
         prog.push_back(tac);

        string topush_label=get_label();
        tac="goto "+topush_label;
         prog.push_back(tac);
        if_bwlabels.push(topush_label);

        tac=togo_label+":";
         prog.push_back(tac);

    }
;
IFEND1:
    {
        string tac,toget_label;
        toget_label=if_bwlabels.top();
        if_bwlabels.pop();
	    tac = toget_label+":";
	     prog.push_back(tac);
    }
;
IFEND2:
    {
        string tac,topush_label;
        topush_label=get_label();
        tac="goto "+topush_label;
         prog.push_back(tac);
        if_endlabels.push(topush_label);
    }
;
ELSEMARK1:
    {
        string tac,toget_label;
        toget_label=if_bwlabels.top();
        if_bwlabels.pop();
	    tac = toget_label+":";
	     prog.push_back(tac);
    }
;
ELSEEND1:
    {
        string tac,toget_label;
        toget_label=if_endlabels.top();
        if_endlabels.pop();
	    tac = toget_label+":";
	     prog.push_back(tac);
    }
;

WHILEMARK2:
    {
        string tac,topush_label;
        topush_label=get_label();
        tac=topush_label+":";
         prog.push_back(tac);
        while_bwlabels.push(topush_label);
   }
;

WHILEMARK1:
    {
        string tac,topush_label;
        topush_label=get_label();
        tac="if (t"+to_string(tempno-1)+"=0) goto "+topush_label;
        // while_exp.push("t"+to_string(tempno-1));
         prog.push_back(tac);
        while_endlabels.push(topush_label);
        // topush_label=get_label();
        // tac=topush_label+":";
        //  prog.push_back(tac);
        // while_endlabels.push(topush_label);
    }
;
WHILEEND1:
    {
        string tac,toget_label,exp;
        toget_label=while_bwlabels.top();
        while_bwlabels.pop();
        // exp=while_exp.top();
        // while_exp.pop();
        // tac="if ("+exp+"=1) goto "+toget_label;
        tac="goto "+toget_label;
         prog.push_back(tac);
        toget_label=while_endlabels.top();
        while_endlabels.pop();
        tac=toget_label+":";
         prog.push_back(tac);
    }
;
DOMARK1:
    {
        string tac,topush_label;
        topush_label=get_label();
        do_bwlabels.push(topush_label);
        tac=topush_label+":";
         prog.push_back(tac);
    }
;
DOEND1:
    {
        string tac,toget_label;
        toget_label=do_bwlabels.top();
        do_bwlabels.pop();
        tac="if (t"+to_string(tempno-1)+"=1) goto "+toget_label;
         prog.push_back(tac);
    }
;
FORMARK1:
    {
        string tac,topush_label;
        topush_label=get_label();
        for_initlabels.push(topush_label);
        tac=topush_label+":";
         prog.push_back(tac);
    }
;
FORMARK2:
    {
        string tac,topush_label;
        topush_label=get_label();
        for_statlabels.push(topush_label);
        tac="if (t"+to_string(tempno-1)+"=1) goto "+topush_label;
         prog.push_back(tac);
        topush_label=get_label();
        for_endlabels.push(topush_label);
        tac="goto "+topush_label;
         prog.push_back(tac);
        topush_label=get_label();
        for_updlabels.push(topush_label);
        tac=topush_label+":";
         prog.push_back(tac);
    }
;
FORMARK3:
    {
        string tac,toget_label;
        toget_label=for_initlabels.top();
        for_initlabels.pop();
        tac="goto "+toget_label;
         prog.push_back(tac);
        toget_label=for_statlabels.top();
        for_statlabels.pop();
        tac=toget_label+":";
         prog.push_back(tac);
    }
;
FOREND1:
    {
        string tac,toget_label;
        toget_label=for_updlabels.top();
        for_updlabels.pop();
        tac="goto "+toget_label;
         prog.push_back(tac);
        toget_label=for_endlabels.top();
        for_endlabels.pop();
        tac=toget_label+":";
         prog.push_back(tac);
    }
;
CONDMARK1:
    {
        string tac,topush_label=get_label();
        tac="if (t"+to_string(tempno-1)+"=0) goto "+topush_label;
         prog.push_back(tac);
        cond_bwlabels.push(topush_label);
        topush_label=get_label();
        cond_inlabels.push(topush_label);
        tac=topush_label+":";
         prog.push_back(tac);
    }
;
CONDMARK2:
    {
        string tac,topush_label=get_label();
        tac="goto "+topush_label;
         prog.push_back(tac);
        cond_endlabels.push(topush_label);
        topush_label=cond_bwlabels.top();
        cond_bwlabels.pop();
        tac=topush_label+":";
         prog.push_back(tac);
    }
;
CONDMARK3:
    {
        string tac,toget_label=cond_endlabels.top();
        cond_endlabels.pop();
        tac=toget_label+":";
         prog.push_back(tac);
    }
;

PrintStatement: PRINTLN PrintArgs CLOSE_BR {
    $$=new astnode;
    $$->token="PrintStatement";
    vector<astnode*>v;
    v.push_back($1);
    v.push_back($2);
    v.push_back($3);
    $$->children=v;
    // cout<<"in"<<$$->token;
    $$->tac_val="sys.print "+$2->tac_val;
    $$->type=$1->type;
    prog.push_back($$->tac_val);
    // cout<<$$->tac_val;
    // cout<<"in PrintStatement";
};
PrintArgs: PrintArg{
        $$=new astnode;
        $$->token="PrintArgs";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
        $$->tac_val=$1->tac_val;
        $$->type=$1->type;
        // cout<<"in PrintArgs";
        }
        | PrintArgs ADD PrintArg{
        $$=new astnode;
        $$->token="PrintArgs";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        // cout<<"in"<<$$->token;
        $$->tac_val=$1->tac_val+$2->lexeme+$3->tac_val;
        $$->type=$1->type;
        // cout<<"in PrintArgs";
};
PrintArg: IDENTIFIER{
        $$=new astnode;
        $$->token="PrintArgs";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
        $$->tac_val=$1->lexeme;
        $$->type=$1->type;
        // cout<<"in PrintArg";
        }
        | Literal{
            $$=new astnode;
            $$->token="PrintArgs";
            vector<astnode*>v;
            v.push_back($1);
            $$->children=v;
            // cout<<"in"<<$$->token;
            $$->tac_val=$1->tac_val;
            $$->type=$1->type;
        // cout<<"in PrintArg";
        }
        | MethodInvocation{
            $$=new astnode;
            $$->token="PrintArgs";
            vector<astnode*>v;
            v.push_back($1);
            $$->children=v;
            // cout<<"in"<<$$->token;
            $$->tac_val=$1->tac_val;
            $$->type=$1->type;
        // cout<<"in PrintArg";
        }
        | {
        // cout<<"in PrintArg";
        }
;
//-----------------------Lexical---------------------------
Literal:
	INT_LIT{
        $$=new astnode;
        $$->token="Literal";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->tac_val=$1->lexeme;
        // cout<<"in"<<$$->token;
        $$->flag=0;
        $$->type="int";
        // cout<<$$->token;
    }
	|FLOAT_LIT{
        $$=new astnode;
        $$->token="Literal";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->tac_val=$1->lexeme;
        // cout<<"in"<<$$->token;
        $$->flag=0;
        $$->type="float";
    }
	|BOOL_LIT{
        $$=new astnode;
        $$->token="Literal";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->tac_val=$1->lexeme;
        // cout<<"in"<<$$->token;
        $$->flag=0;
        $$->type="boolean";
    }
	|CHAR_LIT{
        $$=new astnode;
        $$->token="Literal";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->tac_val=$1->lexeme;
        // cout<<"in"<<$$->token;
        $$->flag=0;
        $$->type="char";
    }
	|STR_LIT{
        $$=new astnode;
        $$->token="Literal";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->tac_val=$1->lexeme;
        // cout<<"in"<<$$->token;
        $$->flag=0;
        $$->type="String";
    }
	|NULL_LIT{
        $$=new astnode;
        $$->token="Literal";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->tac_val=$1->lexeme;
        // cout<<"in"<<$$->token;
        $$->flag=0;
        $$->type="NULL";
    }
;
//-------------------------Types----------------------------
Type:
	PrimitiveType{
    $$=new astnode;
    $$->token="Type";
    $$->type=$1->type;
    temp_type=$$->type;
    vector<astnode*>v;
    v.push_back($1);
    $$->children=v;
    // cout<<"in"<<$$->token;
}
	|ReferenceType{
    $$=new astnode;
    $$->token="Type";
    $$->type=$1->type;
    temp_type=$$->type;
    vector<astnode*>v;
    v.push_back($1);
    $$->children=v;
    // cout<<"in"<<$$->token;
}
;
PrimitiveType:
	NumericType{
        $$=new astnode;
        $$->token="PrimitiveType";
        $$->type=$1->type;
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
	|BOOLEAN{
        $$=new astnode;
        $$->token="PrimitiveType";
        $$->type=$1->lexeme;
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
NumericType:
	IntegralType{
        $$=new astnode;
        $$->token="NumericType";
        $$->type=$1->type;
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
	|FloatingPointType{
        $$=new astnode;
        $$->token="NumericType";
        $$->type=$1->type;
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
IntegralType:
	BYTE{
        $$=new astnode;
        $$->token="IntegralType";
        $$->type="byte";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    |SHORT{
        $$=new astnode;
        $$->token="IntegralType";
        $$->type="short";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    |INT{
        $$=new astnode;
        $$->token="IntegralType";
        $$->type="int";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    |LONG{
        $$=new astnode;
        $$->token="IntegralType";
        $$->type="long";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    |CHAR{
        $$=new astnode;
        $$->token="IntegralType";
        $$->type="char";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
FloatingPointType: 
    FLOAT{
        $$=new astnode;
        $$->token="FloatingPointType";
        $$->type="float";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    |DOUBLE{
        $$=new astnode;
        $$->token="FloatingPointType";
        $$->type="double";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
ReferenceType:
	ClassOrInterfaceType{
        $$=new astnode;
        $$->token="ReferenceType";
        // $$->type="Classorinterface";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
        $$->tac_val=$1->tac_val;
        $$->type=$1->type;
    }
	|ArrayType{
        $$=new astnode;
        $$->token="ReferenceType";
        // $$->type="array";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
        $$->type=$1->type;
    }
;
ClassOrInterfaceType:
	Name{
        $$=new astnode;
        $$->token="ClassOrInterfaceType";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->value=$1->value;
        // cout<<"in"<<$$->token;
        $$->tac_val=$1->tac_val;
        $$->type=$1->type;
    }
;
ClassType:
	ClassOrInterfaceType{
        $$=new astnode;
        $$->token="ClassType";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
        $$->tac_val=$1->tac_val;
        $$->type=$1->type;
    }
;
InterfaceType:
	ClassOrInterfaceType{
        $$=new astnode;
        $$->token="InterfaceType";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->value=$1->value;
        // cout<<"in"<<$$->token;
        $$->tac_val=$1->tac_val;
        $$->type=$1->type;
    }
;
ArrayType:
	PrimitiveType OPEN_SQ CLOSE_SQ{
        $$=new astnode;
        $$->token="ArrayType";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        // cout<<"in"<<$$->token;
        $$->type=$1->type;
    }
	|Name OPEN_SQ CLOSE_SQ{
        $$=new astnode;
        $$->token="ArrayType";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        // cout<<"in"<<$$->token;
        $$->type=$1->type;
    }
	|ArrayType OPEN_SQ CLOSE_SQ{
        $$=new astnode;
        $$->token="ArrayType";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        // cout<<"in"<<$$->token;
        $$->type=$1->type;
    }
;
//------------------------Names--------------------------------
Name:
	SingularName{
        $$=new astnode;
        $$->token="Name";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->value=$1->value;
        $$->tac_val=$1->tac_val;
        // cout<<"in"<<$$->token;
        $$->flag=$1->flag;
        $$->type=$1->type;
    }
	|ComplexName{
        $$=new astnode;
        $$->token="Name";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->value=$1->value;
        $$->tac_val=$1->tac_val;
        // cout<<"in"<<$$->token;
        $$->flag=$1->flag;
        $$->type=$1->type;
    }
;
SingularName:
	IDENTIFIER{
        $$=new astnode;
        $$->token="SingularName";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->value=$1->lexeme;
        $$->tac_val=$1->lexeme;
        // cout<<"in"<<$$->token;
        $$->flag=0;
        // symtab_t* t=symtab_top[fullscope];
        $$->type=symtabGetType(fullscope,$$->value);
        if($$->type=="0"||$$->type=="constructor"){
            $$->type=$1->lexeme;
        }
    }
;
ComplexName:
	Name PERIOD IDENTIFIER{
        $$=new astnode;
        $$->token="ComplexName";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        $$->value=$1->value+"."+$3->lexeme;    //changed
        $$->tac_val=$1->tac_val+"."+$3->lexeme;
        // cout<<"in"<<$$->token;
        $$->flag=0;
        $$->type=symtabGetType(fullscope,$$->tac_val);
        if($$->type=="0"){
            // cout<<fullscope;
            string s=symtabGetType(fullscope,$1->value);
            // if(s=="0") cout<<"no object created";
            // cout<<s;
            if(s!="0"){
                symtab_t*t=symtab_top[m1[s]];
                Type*t1=(*t)[$3->lexeme];
                $$->type=t1->type;
            }
            // cout<<$$->type;
        }
         else $$->type=$1->lexeme;
    }
;
//--------------------------Packages----------------------------
CompilationUnit:{
        $$=new astnode;
        $$->token="CompilationUnit";
        vector<astnode*>v;
        v.push_back(NULL);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    |PackageDeclaration{
        $$=new astnode;
        $$->token="CompilationUnit";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    |PackageDeclaration ImportDeclarations{
        $$=new astnode;
        $$->token="CompilationUnit";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    |PackageDeclaration TypeDeclarations{
        $$=new astnode;
        $$->token="CompilationUnit";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    |PackageDeclaration ImportDeclarations TypeDeclarations{
        $$=new astnode;
        $$->token="CompilationUnit";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    |ImportDeclarations TypeDeclarations{
        $$=new astnode;
        $$->token="CompilationUnit";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    |ImportDeclarations{
        $$=new astnode;
        $$->token="SingularName";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    |TypeDeclarations{
        $$=new astnode;
        $$->token="CompilationUnit";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
ImportDeclarations:
	ImportDeclaration{
        $$=new astnode;
        $$->token="ImportDeclarations";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
	|ImportDeclarations ImportDeclaration{
        $$=new astnode;
        $$->token="ImportDeclarations";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
TypeDeclarations:
    TypeDeclaration{
        $$=new astnode;
        $$->token="TypeDeclarations";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
	|TypeDeclarations TypeDeclaration{
        $$=new astnode;
        $$->token="TypeDeclarations";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
PackageDeclaration:
	PACKAGE Name SEMICOLON{
        $$=new astnode;
        $$->token="PackageDeclaration";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
ImportDeclaration:
	SingleTypeImportDeclaration{
        $$=new astnode;
        $$->token="ImportDeclaration";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        symaddimp($1->tac_val);
        // cout<<"in"<<$$->token;
    }
	|TypeImportOnDemandDeclaration{
        $$=new astnode;
        $$->token="ImportDeclaration";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        symaddimp($1->tac_val);
        // cout<<"in"<<$$->token;
    }
;
SingleTypeImportDeclaration:
	IMPORT Name SEMICOLON{
        $$=new astnode;
        $$->token="SingleTypeImportDeclaration";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        $$->tac_val=$2->tac_val;
        // cout<<"in"<<$$->token;
    }
;
TypeImportOnDemandDeclaration:
	IMPORT Name PERIOD MUL SEMICOLON{
        $$=new astnode;
        $$->token="TypeImportOnDemandDeclaration";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($4);
        v.push_back($5);
        $$->children=v;
        $$->tac_val=$2->tac_val+$3->lexeme+$4->lexeme;
        // cout<<"in"<<$$->token;
    }
;
TypeDeclaration:
	ClassDeclaration{
        $$=new astnode;
        $$->token="TypeDeclaration";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->type=$1->type;
        // cout<<"in"<<$$->token;
    }
	|InterfaceDeclaration{
        $$=new astnode;
        $$->token="TypeDeclaration";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->type=$1->type;
        // cout<<"in"<<$$->token;
    }
	|SEMICOLON{
        $$=new astnode;
        $$->token="TypeDeclaration";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
Modifiers:
	Modifier{
        $$=new astnode;
        $$->token="Modifiers";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->access_specifier=$1->access_specifier;
        // cout<<"in"<<$$->token;
    }
	|Modifiers Modifier{
        $$=new astnode;
        $$->token="Modifiers";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        $$->children=v;
        if($1->access_specifier==0||$2->access_specifier==0) $$->access_specifier=0;
        // cout<<"in"<<$$->token;
    }
;
Modifier:
	PUBLIC{
        $$=new astnode;
        $$->token="Modifier";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
	|PROTECTED{
        $$=new astnode;
        $$->token="Modifier";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
	|PRIVATE{
        $$=new astnode;
        $$->token="Modifier";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->access_specifier=0;
        // cout<<"in"<<$$->token;
    }
	|STATIC{
        $$=new astnode;
        $$->token="Modifier";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
	|ABSTRACT{
        $$=new astnode;
        $$->token="Modifier";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
	|FINAL{
        $$=new astnode;
        $$->token="Modifier";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
	|NATIVE{
        $$=new astnode;
        $$->token="Modifier";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
	|SYNCHRONIZED{
        $$=new astnode;
        $$->token="Modifier";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
	|TRANSIENT{
        $$=new astnode;
        $$->token="Modifier";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
	|VOLATILE{
        $$=new astnode;
        $$->token="Modifier";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
//---------------------------------Classes------------------------------------
ClassName:
    IDENTIFIER {
        $$=new astnode;
        $$->token="ClassName";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        cname=$1->lexeme;
        fname=cname;
        $$->value=$1->lexeme;
        $$->type=$1->type;
        class_labels.push($1->lexeme);
    }
;
ClassDeclaration:
	Modifiers CLASS ClassName Super Interfaces ClassBody{
        $$=new astnode;
        $$->token="ClassDeclaration";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($4);
        v.push_back($5);
        v.push_back($6);
        $$->children=v;
        symadd($3->value,"class_"+$3->value,$5->value);
        $$->type=$3->type;
        // cout<<"in"<<$$->token;
    }
	|Modifiers CLASS ClassName Super ClassBody{
        $$=new astnode;
        $$->token="ClassDeclaration";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($4);
        v.push_back($5);
        $$->children=v;
        symadd($3->value,"class_"+$3->value,"NULL");
        $$->type=$3->type;
        // cout<<"in"<<$$->token;
    }
	|Modifiers CLASS ClassName Interfaces ClassBody{
        $$=new astnode;
        $$->token="ClassDeclaration";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($4);
        v.push_back($5);
        $$->children=v;
        symadd($3->value,"class_"+$3->value,$4->value);
        $$->type=$3->type;
        // cout<<"in"<<$$->token;
    }
	|Modifiers CLASS ClassName ClassBody{
        $$=new astnode;
        $$->token="ClassDeclaration";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($4);
        $$->children=v;
        symadd($3->value,"class_"+$3->value,"NULL");
        $$->type=$3->type;
        // cout<<"in"<<$$->token;
    }
	|CLASS ClassName Super Interfaces ClassBody{
        $$=new astnode;
        $$->token="ClassDeclaration";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($4);
        v.push_back($5);
        $$->children=v;
        symadd($2->value,"class_"+$2->value,$4->value);
        $$->type=$2->type;
        // cout<<"in"<<$$->token;
    }
	|CLASS ClassName Super ClassBody{
        $$=new astnode;
        $$->token="ClassDeclaration";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($4);
        $$->children=v;
        symadd($2->value,"class_"+$2->value,"NULL");
        $$->type=$2->type;
        // cout<<"in"<<$$->token;
    }
	|CLASS ClassName Interfaces ClassBody{
        $$=new astnode;
        $$->token="ClassDeclaration";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($4);
        $$->children=v;
        symadd($2->value,"class_"+$2->value,$3->value);
        $$->type=$2->type;
        // cout<<"in"<<$$->token;
    }
	|CLASS ClassName ClassBody{
        $$=new astnode;
        $$->token="ClassDeclaration";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        symadd($2->value,"class_"+$2->value,"NULL");
        $$->type=$2->type;
        // cout<<"in"<<$$->token;
    }
;
Super:
	EXTENDS ClassType{
        $$=new astnode;
        $$->token="Super";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        $$->children=v;
        // cout<<"in"<<$$->token;
        $$->type=$2->type;
    }
;
Interfaces:
	IMPLEMENTS InterfaceTypeList{
        $$=new astnode;
        $$->token="Interfaces";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        $$->children=v;
        $$->value=$2->value;
        // cout<<"in"<<$$->token;
    }
;
InterfaceTypeList:
	InterfaceType{
        $$=new astnode;
        $$->token="InterfaceTypeList";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->value=$1->value;
        // cout<<"in"<<$$->token;
    }
	|InterfaceTypeList COMMA InterfaceType{
        $$=new astnode;
        $$->token="InterfaceTypeList";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        $$->value=$1->value+","+$3->value;
        // cout<<"in"<<$$->token;
    }
;
CLASSMARK1:
    {
        string n=class_labels.top();
        class_labels.pop();
        m1[n]=fullscope;
        // cout<<fullscope<<" ";
    }
;
ClassBody:
	OPEN_CR SYMTABS CLASSMARK1 ClassBodyDeclarations CLOSE_CR SYMTABE{
        // cout<<"entered in classBody ";
        $$=new astnode;
        $$->token="ClassBody";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($4);
        v.push_back($5);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
	|OPEN_CR CLOSE_CR{
        $$=new astnode;
        $$->token="ClassBody";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
ClassBodyDeclarations:
	ClassBodyDeclaration{
        $$=new astnode;
        $$->token="ClassBodyDeclarations";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
	|ClassBodyDeclarations ClassBodyDeclaration{
        $$=new astnode;
        $$->token="ClassBodyDeclarations";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
ClassBodyDeclaration:
	ClassMemberDeclaration{
        $$=new astnode;
        $$->token="ClassBodyDeclaration";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->type=$1->type;
        // cout<<"in"<<$$->token;
    }
	|StaticInitializer{
        $$=new astnode;
        $$->token="ClassBodyDeclaration";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->type=$1->type;
        // cout<<"in"<<$$->token;
    }
	|ConstructorDeclaration{
        $$=new astnode;
        $$->token="ClassBodyDeclaration";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->type=$1->type;
        // cout<<"in"<<$$->token;
    }
;
ClassMemberDeclaration:
	FieldDeclaration{
        $$=new astnode;
        $$->token="ClassMemberDeclarations";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->type=$1->type;
        // cout<<"in"<<$$->token;
    }
	|MethodDeclaration{
        $$=new astnode;
        $$->token="ClassMemberDeclarations";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->type=$1->type;
        // cout<<"in"<<$$->token;
    }
;
//---------------------Field declarations----------------------
FieldDeclaration:
	Modifiers Type VariableDeclarators SEMICOLON{
        $$=new astnode;
        $$->token="FieldDeclaration";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($4);
        $$->children=v;
        string s=$3->value;
        vector<string>tokens=split(s,',');
        // cout<<"\n executing symadd_list\n";
        symadd_list(tokens,$2->type);
        // cout<<"in"<<$$->token;
        $3->type=$2->type;
        temp_type="";
    }
	|Type VariableDeclarators SEMICOLON{
        $$=new astnode;
        $$->token="FieldDeclaration";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        string s=$2->value;
        vector<string>tokens=split(s,',');
        // cout<<"\n executing symadd_list\n";
        symadd_list(tokens,$1->type);
        // cout<<"in"<<$$->token;
        $2->type=$1->type;
        temp_type="";
    }
;
VariableDeclarators:
	VariableDeclarator{
        $$=new astnode;
        $$->token="VariableDeclarators";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->value=$1->value;
        // cout<<"in"<<$$->token;
        $$->type=temp_type;
        $$->flag=$1->flag;
        if($1->flag==4) {
            // $$->tuples=$1->tuples;
            $$->length=$1->length;
        }
        $$->dims=$1->dims;
    }
	|VariableDeclarators COMMA VariableDeclarator{
        $$=new astnode;
        $$->token="VariableDeclarators";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        $$->value = $1->value+","+$3->value;
        // cout<<"in"<<$$->token;
        temp=symtypeEvaluate($1->type,$3->type);
        if(temp=="0")
        {
            cout<<"Not all variables are of same type";
        }
        $$->type=temp;
    }
;
VariableDeclarator:
	VariableDeclaratorId{
        $$=new astnode;
        $$->token="VariableDeclarator";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->value=$1->value;
        // cout<<"in"<<$$->token;
        $$->flag=$1->flag;
        $$->dims=$1->dims;
        $$->tac_val=$1->tac_val;
        $$->type=$1->type;
    }
	|VariableDeclaratorId ASSIGN VariableInitializer{
        $$=new astnode;
        $$->token="VariableDeclarator";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        $$->value=$1->value;
        // cout<<"in"<<$$->token;
        $$->tac_val=$1->tac_val;
        string tac;
        temp=symAssignment($1->type,$3->type);
        // cout<<$1->type<<" "<<$3->type;
        if(temp=="0")
        {
            cout<<"type mismatch";
            //uncomment
        }
        if($1->type != $3->type)
        {    string t=get_tempvar();
             s1=t+" =cast_to_"+temp+" "+$3->tac_val;
            prog.push_back(s1);
        }
        
        $$->type=temp;
        if(fname==cname)
        tac=fname+"."+$1->tac_val+" = "+$3->tac_val;
        else if($3->flag==1) tac=$1->tac_val+" = t"+to_string(tempno-1);
        else tac=$1->tac_val+" = "+$3->tac_val;
         prog.push_back(tac);
        if($3->flag==3) {
            tac="*"+$1->tac_val+" = t"+to_string(tempno-1);
             prog.push_back(tac);
        }
        if($3->flag==4) {
            tac=$1->tac_val+" = "+"&t"+to_string(tempno-1);
             prog.push_back(tac);
            vector<string>v1=split($3->value,',');
            int l=$3->length;
            for(int i=0;i<l;i++) {
                string s1="*(";
                string s2="+";
                string s3=") = ";
                tac=s1+$1->tac_val+s2+to_string(i*4)+s3+v1[i];
                 prog.push_back(tac);
            }
            $$->length=$3->length;
            // $$->tuples=$3->tuples;
            if($1->dims!=$3->dims && $1->flag==4){
            cout<<"Arrays not of same dimension";
        }
        }
        // cout<<"\n"<<$1->dims<<" "<<$3->dims;
        
        $$->flag=$1->flag;
        $$->dims=$1->dims;
    }
;
VariableDeclaratorId:
	IDENTIFIER{
        $$=new astnode;
        $$->token="VariableDeclaratorId";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->value=$1->lexeme;
        // cout<<"in"<<$$->token;
        $$->tac_val=$1->lexeme;
        // gpara=$1->lexeme;
        $$->flag=$1->flag;
        $$->dims=$1->dims;
        if(temp_type!="")
            $$->type=temp_type;
        // else
        // {
        //     symtab_t* t=symtab_top[fullscope];
        //     $$->type=symtabGetType(t,$$->value);
        // }
    }
	|VariableDeclaratorId OPEN_SQ CLOSE_SQ{
        $$=new astnode;
        $$->token="VariableDeclaratorId";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        $$->value=$1->value;
        // cout<<"in"<<$$->token;
        $$->tac_val=$1->tac_val+"[]";
        $$->dims=$1->dims+1;
        // gpara=$$->tac;
        if($$->value!="args")
        {
            if(temp_type!="")
            $$->type=temp_type;
            // else
            // {
            //     symtab_t* t=symtab_top[fullscope];
            //     $$->type=symtabGetType(t,$$->value);
            // }
        }
        else
        {
            $$->type="String";
        }
        $$->flag=4;
    }
;
VariableInitializer:
	Expression{
        $$=new astnode;
        $$->token="VariableInitializer";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
        $$->tac_val=$1->tac_val;
        $$->flag=$1->flag;
        $$->type=$1->type;
        $$->dims=$1->dims;
        $$->space=$1->space;
        $$->value=$1->tac_val;
    }
	|ArrayInitializer{
        $$=new astnode;
        $$->token="VariableInitializer";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
        $$->flag=$1->flag;
        $$->tac_val=$1->tac_val;
        // $$->tuples=$1->tuples;
        $$->length=$1->length;
        $$->type=$1->type;
        $$->dims=$1->dims;
        $$->space=$1->space;
        $$->value=$1->value;
    }
;
//--------------------Method declarations------------------------
MethodDeclaration:
	MethodHeader MethodBody{
        $$=new astnode;
        $$->token="MethodDeclaration";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        $$->children=v;
        // cout<<"in"<<$$->token;
        $$->type=$1->type;
        fname=cname;
        string tac;
        // string scope;
        // scope=fullscope+"/"+to_string(currscope);
        // cout<<scope<<endl;
        // symtab_t* tab=symtab_top[scope];
        // tac="SP = SP +"+getoffset(tab,0); prog.push_back(tac);
        tac="Pop BP_old";
         prog.push_back(tac);
        tac="BP = BP_old";
         prog.push_back(tac);
        tac="return";
         prog.push_back(tac);
        tac="endfunc";
        prog.push_back(tac);
    }
;
MethodHeader:
	Modifiers Type MethodDeclarator Throws{
        $$=new astnode;
        $$->token="MethodHeader";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($4);
        $$->children=v;
        symadd($3->name,$2->type,$3->value,$1->access_specifier);
        $$->type=$2->type;
        // cout<<"in"<<$$->token;

    }
	|Modifiers Type MethodDeclarator{
        $$=new astnode;
        $$->token="MethodHeader";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        symadd($3->name,$2->type,$3->value,$1->access_specifier);
        $$->type=$2->type;
        // cout<<"in"<<$$->token;
    }
	|Type MethodDeclarator Throws{
        $$=new astnode;
        $$->token="MethodHeader";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        symadd($2->name,$1->type,$2->value);
        $$->type=$1->type;
        // cout<<"in"<<$$->token;
    }
	|Type MethodDeclarator{
        $$=new astnode;
        $$->token="MethodHeader";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        $$->children=v;
        symadd($2->name,$1->type,$2->value);
        $$->type=$1->type;
        // cout<<"in"<<$$->token;
    }
	|Modifiers VOID MethodDeclarator Throws{
        $$=new astnode;
        $$->token="MethodHeader";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($4);
        $$->children=v;
        symadd($3->name,"void",$3->value,$1->access_specifier);
        $$->type="void";
        // cout<<"in"<<$$->token;
    }
	|Modifiers VOID MethodDeclarator{
        $$=new astnode;
        $$->token="MethodHeader";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        symadd($3->name,"void",$3->value,$1->access_specifier);
        $$->type="void";
        // cout<<"in"<<$$->token;
    }
	|VOID MethodDeclarator Throws{
        $$=new astnode;
        $$->token="MethodHeader";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        symadd($2->name,"void",$2->value);
        $$->type="void";
        // cout<<"in"<<$$->token;
    }
	|VOID MethodDeclarator{
        $$=new astnode;
        $$->token="MethodHeader";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        $$->children=v;
        symadd($2->name,"void",$2->value);
        $$->type="void";
        // cout<<"in"<<$$->token;
    }
;
MethodDeclarator:
	FunctionName OPEN_BR FormalParameterLists CLOSE_BR{
        $$=new astnode;
        $$->token="MethodDeclarator";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($4);
        $$->children=v;
        $$->name=$1->name;
        $$->value=$3->type;
        // cout<<"in"<<$$->token;
    }
	|FunctionName OPEN_BR CLOSE_BR{
        $$=new astnode;
        $$->token="MethodDeclarator";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        $$->name=$1->name;
        // cout<<"in"<<$$->token;
    }
	|MethodDeclarator OPEN_SQ CLOSE_SQ{
        $$=new astnode;
        $$->token="MethodDeclarator";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        $$->name=$1->name;
        $$->value=$1->type;
        // cout<<"in"<<$$->token;
    }
;
FunctionName:
    IDENTIFIER{
        $$=new astnode;
        $$->token="FunctionName";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->name=$1->lexeme;
        $$->value=$1->type;
        // cout<<"in"<<$$->token;
        string tac;
        if($1->lexeme!="main")
        tac="define "+cname+"."+$1->lexeme+":";
        else tac="define "+$1->lexeme+":";
         prog.push_back(tac);
        fname="fname";
        tac="beginfunc";
        prog.push_back(tac);
        // string tac;
        tac="obj_ref = popparam";
        prog.push_back(tac);
        tac="return_addr = SP + 4";
        
        prog.push_back(tac);
        tac="push BP";
        
        prog.push_back(tac);
        tac="BP = SP";
        
        prog.push_back(tac);

    }
;
FormalParameterLists:
    FormalParameterList{
        $$=new astnode;
        $$->token="FormalParameterLists";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->type=$1->type;
        $$->value=$1->value;
        // cout<<"in"<<$$->token;
        string s=$1->tac_val,tac;
        vector<string>token=split(s,',');
        tac="args_num "+to_string(token.size());
         prog.push_back(tac);
        for(int i=token.size()-1;i>=0;i--) {
            tac="pop "+fullscope+"/"+to_string(currscope+1)+" "+token[i];
             prog.push_back(tac);
        }
        
    }
;
FormalParameterList:
	FormalParameter{
        $$=new astnode;
        $$->token="FormalParameterList";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->type=$1->type;
        $$->value=$1->value;
        // cout<<"in"<<$$->token;
        $$->tac_val=$1->tac_val;
    }
	|FormalParameterList COMMA FormalParameter{
        $$=new astnode;
        $$->token="FormalParameterList";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        $$->type=$1->type+","+$3->type;
        $$->value=$1->value+","+$3->value;
        // cout<<"in"<<$$->token;
        $$->tac_val=$1->tac_val+","+$3->tac_val;
    }
;
FormalParameter:
	Type VariableDeclaratorId{
        $$=new astnode;
        $$->token="FormalParameter";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        $$->children=v;
        $$->type=$1->type;
        $$->value=$2->value;
        buffer[$2->value]=$1->type;
        // cout<<"in"<<$$->token;
        $$->tac_val=$2->tac_val;
        $2->type=$1->type;
    }
;
Throws:
	THROWS ClassTypeList{
        $$=new astnode;
        $$->token="Throws";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
ClassTypeList:
	ClassType{
        $$=new astnode;
        $$->token="ClassTypeList";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
	|ClassTypeList COMMA ClassType{
        $$=new astnode;
        $$->token="ClassTypeList";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
MethodBody:
	Block {
        $$=new astnode;
        $$->token="MethodBody";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
	|SEMICOLON{
        $$=new astnode;
        $$->token="MethodBody";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
//-------------------------------Static-------------------------
StaticInitializer:
	STATIC Block{
        $$=new astnode;
        $$->token="StaticInitializer";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
//------------------------------Constructor Declarations---------------------------------
ConstructorDeclaration:
	Modifiers ConstructorDeclarator Throws ConstructorBody{
        $$=new astnode;
        $$->token="ConstructorDeclaration";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($4);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
	|Modifiers ConstructorDeclarator ConstructorBody{
        $$=new astnode;
        $$->token="ConstructorDeclaration";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
	|ConstructorDeclarator Throws ConstructorBody{
        $$=new astnode;
        $$->token="ConstructorDeclaration";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
	|ConstructorDeclarator ConstructorBody{
        $$=new astnode;
        $$->token="ConstructorDeclaration";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;

ConstructorDeclarator:
	ConstructorName OPEN_BR FormalParameterLists CLOSE_BR{
        $$=new astnode;
        $$->token="ConstructorDeclarator";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($4);
        $$->children=v;
        symadd($1->name,"constructor",$3->type);
        // cout<<"in"<<$$->token;
    }
	|ConstructorName OPEN_BR CLOSE_BR{
        $$=new astnode;
        $$->token="ConstructorDeclarator";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        symadd($1->name,"constructor");
        // cout<<"in"<<$$->token;
    }
;
ConstructorName:
    SingularName{
        $$=new astnode;
        $$->token="ConstructorName";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->name=$1->value;
        // $$->value=$1->type;
        // cout<<"in"<<$$->token;
        if(cname!=$1->tac_val) cout<<"Invalid cunstructor name";
        string tac;
        tac="define "+cname+"."+"ctor"+":";
         prog.push_back(tac);
         tac="begin_func";
        prog.push_back(tac);
        tac="obj_ref = popparam";
        prog.push_back(tac);
    }
;
ConstructorBody:
	OPEN_CR SYMTABS ExplicitConstructorInvocation BlockStatements CLOSE_CR SYMTABE{
        $$=new astnode;
        $$->token="ConstructorBody";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($3);
        v.push_back($4);
        v.push_back($5);
        $$->children=v;
        string tac;
        tac="push obj_ref";
        prog.push_back(tac);
        tac="endfunc";
        prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
	|OPEN_CR SYMTABS ExplicitConstructorInvocation CLOSE_CR SYMTABE{
        $$=new astnode;
        $$->token="ConstructorBody";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($3);
        v.push_back($4);
        $$->children=v;
        string tac;
        tac="push obj_ref";
        prog.push_back(tac);
        tac="endfunc";
        prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
	|OPEN_CR SYMTABS BlockStatements CLOSE_CR SYMTABE{
        $$=new astnode;
        $$->token="ConstructorBody";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($3);
        v.push_back($4);
        $$->children=v;
        string tac;
        tac="push obj_ref";
        prog.push_back(tac);
        tac="endfunc";
        prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
	|OPEN_CR  CLOSE_CR{
        $$=new astnode;
        $$->token="ConstructorBody";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        $$->children=v;
        string tac;
        tac="push obj_ref";
        prog.push_back(tac);
        tac="endfunc";
        prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
;
ExplicitConstructorInvocation:
	THIS OPEN_BR ArgumentList CLOSE_BR SEMICOLON{
        $$=new astnode;
        $$->token="ExplicitConstructorInvocation";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($4);
        v.push_back($5);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
	|THIS OPEN_BR CLOSE_BR SEMICOLON{
        $$=new astnode;
        $$->token="ExplicitConstructorInvocation";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($4);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
	|SUPER OPEN_BR ArgumentList CLOSE_BR SEMICOLON{
        $$=new astnode;
        $$->token="ExplicitConstructorInvocation";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($4);
        v.push_back($5);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
	|SUPER OPEN_BR CLOSE_BR SEMICOLON{
        $$=new astnode;
        $$->token="ExplicitConstructorInvocation";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($4);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
//----------------------------------------Interfaces-----------------------------------
InterfaceDeclaration:
	Modifiers INTERFACE IDENTIFIER ExtendsInterfaces InterfaceBody{
        $$=new astnode;
        $$->token="InterfaceDeclaration";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($4);
        v.push_back($5);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
	|Modifiers INTERFACE IDENTIFIER InterfaceBody{
        $$=new astnode;
        $$->token="InterfaceDeclaration";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($4);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
	|INTERFACE IDENTIFIER ExtendsInterfaces InterfaceBody{
        $$=new astnode;
        $$->token="InterfaceDeclaration";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($4);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
	|INTERFACE IDENTIFIER InterfaceBody{
        $$=new astnode;
        $$->token="InterfaceDeclaration";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
ExtendsInterfaces:
	EXTENDS InterfaceType{
        $$=new astnode;
        $$->token="ExtendsInterfaces";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
	|ExtendsInterfaces COMMA InterfaceType{
        $$=new astnode;
        $$->token="ExtendsInterfaces";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
InterfaceBody:
	OPEN_CR SYMTABS InterfaceMemberDeclarations CLOSE_CR SYMTABE{
        $$=new astnode;
        $$->token="InterfaceBody";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($3);
        v.push_back($4);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
	|OPEN_CR  CLOSE_CR{
        $$=new astnode;
        $$->token="InterfaceBody";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
InterfaceMemberDeclarations:
	InterfaceMemberDeclaration{
        $$=new astnode;
        $$->token="InterfaceMemberDeclarations";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
	|InterfaceMemberDeclarations InterfaceMemberDeclaration{
        $$=new astnode;
        $$->token="InterfaceMemberDeclarations";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
InterfaceMemberDeclaration:
	ConstantDeclaration{
        $$=new astnode;
        $$->token="InterfaceMemberDeclaration";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
	|AbstractMethodDeclaration{
        $$=new astnode;
        $$->token="InterfaceMemberDeclaration";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
ConstantDeclaration:
	FieldDeclaration{
        $$=new astnode;
        $$->token="ConstantDeclaration";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
AbstractMethodDeclaration:
	MethodHeader SEMICOLON{
        $$=new astnode;
        $$->token="AbstractMethodDeclaration";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
//---------------------------------------Arrays-----------------------------------
ArrayInitializer:
	OPEN_CR SYMTABS VariableInitializers COMMA CLOSE_CR SYMTABE{
        $$=new astnode;
        $$->token="ArrayInitializer";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($3);
        v.push_back($4);
        v.push_back($5);
        $$->children=v;
        // cout<<"in"<<$$->token;
        string s=$3->tac_val;
        if(temp_type=="ud") temp_type=$3->type;
        vector<string>token=split(s,',');
        string tac,temp1=get_tempvar();
        tac="Lcall_Alloc\n"; 
        tac=tac+temp1+" = "+temp_type+"["+to_string(token.size())+"]";
        $$->tac_val=tac;
        $$->flag=4;
        $$->length=token.size();
        $$->value=$3->value;
        // $$->tuples=token;
        $$->type=$3->type;
        $$->dims=$3->dims+1;
        $$->space=$3->space;
        // cout<<"Dims: "<<$$->dims;
// Type check kardo idhar
    }
	|OPEN_CR SYMTABS VariableInitializers CLOSE_CR SYMTABE{
        $$=new astnode;
        $$->token="ArrayInitializer";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($3);
        v.push_back($4);
        $$->children=v;
        // cout<<"in"<<$$->token;
        string s=$3->tac_val;
        vector<string>token=split(s,',');
        if(temp_type=="ud") temp_type=$3->type;
        string tac,temp=get_tempvar();
        tac="Lcall_Alloc\n"; 
        tac=tac+temp+" = "+temp_type+"["+to_string(token.size())+"]";
        $$->tac_val=tac;
        $$->flag=4;
        $$->length=token.size();
        $$->value=$3->value;
        // $$->tuples=token;
        $$->type=$3->type;
        $$->dims=$3->dims+1;
        $$->space=$3->space;
        // cout<<"Dims: "<<$$->dims;
    }
	|OPEN_CR COMMA CLOSE_CR{
        $$=new astnode;
        $$->token="ArrayInitializer";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        // cout<<"in"<<$$->token;
        string tac,temp=get_tempvar();
        tac="Lcall_Alloc\n"; 
        tac=tac+temp+" = "+temp_type+"[1]";
        $$->tac_val=tac;
        $$->flag=4;
        $$->length=0;
        $$->type="nd";
        $$->dims=1;
        $$->value=",";
        // $$->tuples=NULL;
    }
	|OPEN_CR CLOSE_CR{
        $$=new astnode;
        $$->token="ArrayInitializer";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        $$->children=v;
        // cout<<"in"<<$$->token;
        string tac,temp=get_tempvar();
        tac="Lcall_Alloc\n"; 
        tac=tac+temp+" = "+temp_type+"[0]";
        $$->tac_val=tac;
        $$->flag=4;
        $$->length=0;
        $$->type="nd";
        $$->dims=1;
        $$->value="";
        // $$->tuples=NULL;
    }
;
VariableInitializers:
	VariableInitializer{
        $$=new astnode;
        $$->token="VariableInitializers";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
        $$->tac_val=$1->tac_val;
        $$->type=$1->type;
        // $$->length=$1->length;
        $$->dims=$1->dims;
        $$->space=$1->space;
        $$->length=$1->length;
        $$->value=$1->tac_val;
        // $$->tuples=$1->tuples;
        // cout<<"in VariableInitializer Length: "<<$$->length<<" Space:"<<$$->space;
    }
	|VariableInitializers COMMA VariableInitializer{
        $$=new astnode;
        $$->token="VariableInitializers";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        // cout<<"in"<<$$->token;
        $$->tac_val=$1->tac_val+","+$3->tac_val;
        temp=symtypeEvaluate($1->type,$3->type);
        // cout<<"\n"<<$1->type<<" "<<$3->type;
        if(temp=="0")
        {
            //uncomment
            cout<<"Error, type mismatch in array initializer";
        }
        $$->type=temp;
        $$->dims=$1->dims;
        if(($1->length!=$3->length)||($1->dims!=$3->dims)){
            cout<<"Unequal length elements appended";
        }
        $$->length=$1->length;
        $$->space=$1->space+$3->space;
        $$->value=$$->tac_val;
        // cout<<"in VariableInitializers Length: "<<$$->length<<" Space:"<<$$->space;
    }
;

//---------------------------------Blocks--------------------------------------------

Block:
    OPEN_CR  CLOSE_CR{
        $$=new astnode;
        $$->token="Block";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    | OPEN_CR SYMTABS BlockStatements CLOSE_CR SYMTABE{
        $$=new astnode;
        $$->token="Block";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($3);
        v.push_back($4);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
BlockStatements:
    BlockStatement{
        $$=new astnode;
        $$->token="BlockStatements";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    | BlockStatements BlockStatement{
        $$=new astnode;
        $$->token="BlockStatements";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
BlockStatement:
    LocalVariableDeclarationStatement{
        $$=new astnode;
        $$->token="BlockStatement";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
        if($1->type!="ud"){
        string s=$1->value;
        vector<string>tokens=split(s,',');
        symadd_list(tokens,$1->type);
        if($1->flag==4) {
            symadd(s,$1->type,$1->dims);
        }
        }
    }
    | Statement{
        $$=new astnode;
        $$->token="BlockStatement";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->tac_val=$1->tac_val;
        // cout<<"in"<<$$->token;
    }
;
LocalVariableDeclarationStatement:
    LocalVariableDeclaration SEMICOLON{
        $$=new astnode;
        $$->token="LocalVariableDeclarationStatement";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        $$->children=v;
        // cout<<"in"<<$$->token;
        $$->value=$1->value;
        $$->type=$1->type;
        $$->flag=$1->flag;
        $$->dims=$1->dims;
    }
;
LocalVariableDeclaration:
    Type VariableDeclarators{
        $$=new astnode;
        $$->token="LocalVariableDeclaration";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        $$->children=v;
        // cout<<"in"<<$$->token;
        $$->value=$2->value;
        $$->type=$1->type;
        $$->flag=$2->flag;
        $$->dims=$2->dims;
        // string s=$2->value;
        // vector<string>tokens=split(s,',');
        // symadd_list(tokens,$1->type);
    }
;
Statement:
    StatementWithoutTrailingSubstatement{
        $$=new astnode;
        $$->token="Statement";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->tac_val=$1->tac_val;
        // cout<<"in"<<$$->token;
    }
    | LabeledStatement{
        $$=new astnode;
        $$->token="Statement";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    | IfThenStatement{
        $$=new astnode;
        $$->token="Statement";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    | IfThenElseStatement{
        $$=new astnode;
        $$->token="Statement";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    | WhileStatement{
        $$=new astnode;
        $$->token="Statement";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    | ForStatement{
        $$=new astnode;
        $$->token="Statement";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
StatementNoShortIf:
    StatementWithoutTrailingSubstatement{
        $$=new astnode;
        $$->token="StatementNoShortIf";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    | LabeledStatementNoShortIf{
        $$=new astnode;
        $$->token="StatementNoShortIf";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    | IfThenElseStatementNoShortIf{
        $$=new astnode;
        $$->token="StatementNoShortIf";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    | WhileStatementNoShortIf{
        $$=new astnode;
        $$->token="StatementNoShortIf";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    | ForStatementNoShortIf{
        $$=new astnode;
        $$->token="StatementNoShortIf";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
StatementWithoutTrailingSubstatement:
    Block{
        $$=new astnode;
        $$->token="StatementWithoutTrailingSubstatement";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    | EmptyStatement{
        $$=new astnode;
        $$->token="StatementWithoutTrailingSubstatement";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    | ExpressionStatement{
        $$=new astnode;
        $$->token="StatementWithoutTrailingSubstatement";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->tac_val=$1->tac_val;
        // cout<<"in"<<$$->token;
    }
    | SwitchStatement{
        $$=new astnode;
        $$->token="StatementWithoutTrailingSubstatement";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    | DoStatement{
        $$=new astnode;
        $$->token="StatementWithoutTrailingSubstatement";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    | BreakStatement{
        $$=new astnode;
        $$->token="StatementWithoutTrailingSubstatement";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    | ContinueStatement{
        $$=new astnode;
        $$->token="StatementWithoutTrailingSubstatement";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    | ReturnStatement{
        $$=new astnode;
        $$->token="StatementWithoutTrailingSubstatement";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    | SynchronizedStatement{
        $$=new astnode;
        $$->token="StatementWithoutTrailingSubstatement";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    | ThrowStatement{
        $$=new astnode;
        $$->token="StatementWithoutTrailingSubstatement";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    | TryStatement{
        $$=new astnode;
        $$->token="StatementWithoutTrailingSubstatement";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
EmptyStatement:
    SEMICOLON{
        $$=new astnode;
        $$->token="EmptyStatement";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
LabeledStatement:
    IDENTIFIER COLON Statement{
        $$=new astnode;
        $$->token="LabeledStatement";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        // cout<<"in"<<$$->token;
        string tac,topush_label=get_label();
        tac=topush_label+":";
         prog.push_back(tac);
        m[$1->lexeme]=topush_label;
    }
;
LabeledStatementNoShortIf:
    IDENTIFIER COLON StatementNoShortIf{
        $$=new astnode;
        $$->token="LabeledStatementNoShortIf";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        // cout<<"in"<<$$->token;
        string tac,topush_label=get_label();
        tac=topush_label+":";
         prog.push_back(tac);
        m[$1->lexeme]=topush_label;
    }
;
ExpressionStatement:
    StatementExpression SEMICOLON{
        $$=new astnode;
        $$->token="ExpressionStatement";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        $$->children=v;
        // cout<<"in"<<$$->token;
        $$->tac_val=$1->tac_val;
        $$->type=$1->type;
    }
;
StatementExpression:
    Assignment{
        $$=new astnode;
        $$->token="StatementExpression";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
        $$->tac_val=$1->tac_val;
        $$->type=$1->type;
    }
    | PreIncrementExpression{
        $$=new astnode;
        $$->token="StatementExpression";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
        $$->tac_val=$1->tac_val;
        $$->type=$1->type;
    }
    | PreDecrementExpression{
        $$=new astnode;
        $$->token="StatementExpression";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
        $$->tac_val=$1->tac_val;
        $$->type=$1->type;
    }
    | PostIncrementExpression{
        $$=new astnode;
        $$->token="StatementExpression";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
        $$->tac_val=$1->tac_val;
        $$->type=$1->type;
    }
    | PostDecrementExpression{
        $$=new astnode;
        $$->token="StatementExpression";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
        $$->tac_val=$1->tac_val;
        $$->type=$1->type;
    }
    | MethodInvocation{
        $$=new astnode;
        $$->token="StatementExpression";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
        // string tac="push pc+1";
        // prog.push_back(tac);
        // tac="push obj_ref";
        // prog.push_back(tac);
        $$->tac_val=$1->tac_val;
        $$->type=$1->type;
        prog.push_back($1->tac_val);
    }
    | ClassInstanceCreationExpression{
        $$=new astnode;
        $$->token="StatementExpression";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
        $$->tac_val=$1->tac_val;
        $$->type=$1->type;
    }
    | PrintStatement{
        $$=new astnode;
        $$->token="StatementExpression";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
        $$->tac_val=$1->tac_val;
        $$->type=$1->type;
        // cout<<"in StatementExpression";
    }
;
IfThenStatement:
    IF OPEN_BR Expression CLOSE_BR IFMARK1 Statement IFEND1 { 
        $$=new astnode;
        $$->token="IfThenStatement";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($4);
        v.push_back($6);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
IfThenElseStatement:
    IF OPEN_BR Expression CLOSE_BR IFMARK1 StatementNoShortIf IFEND2 ELSE ELSEMARK1 Statement ELSEEND1{
        $$=new astnode;
        $$->token="IfThenElseStatement";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($4);
        v.push_back($6);
        v.push_back($8);
        v.push_back($10);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
IfThenElseStatementNoShortIf:
    IF OPEN_BR Expression CLOSE_BR IFMARK1 StatementNoShortIf IFEND2 ELSE ELSEMARK1 StatementNoShortIf ELSEEND1{
        $$=new astnode;
        $$->token="IfThenElseStatementNoShortIf";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($4);
        v.push_back($6);
        v.push_back($8);
        v.push_back($10);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
SwitchStatement:
    SWITCH OPEN_BR Expression CLOSE_BR SwitchBlock{
        $$=new astnode;
        $$->token="SwitchStatement";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($4);
        v.push_back($5);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
SwitchBlock:
    OPEN_CR  CLOSE_CR{
        $$=new astnode;
        $$->token="SwitchBlock";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    |OPEN_CR SYMTABS SwitchBlockStatementGroups CLOSE_CR SYMTABE{
        $$=new astnode;
        $$->token="SwitchBlock";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($3);
        v.push_back($4);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    |OPEN_CR SYMTABS  SwitchLabels CLOSE_CR SYMTABE{
        $$=new astnode;
        $$->token="SwitchBlock";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($3);
        v.push_back($4);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    |OPEN_CR SYMTABS SwitchBlockStatementGroups SwitchLabels CLOSE_CR SYMTABE{
        $$=new astnode;
        $$->token="SwitchBlock";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($3);
        v.push_back($4);
        v.push_back($5);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
SwitchBlockStatementGroups:
    SwitchBlockStatementGroup{
        $$=new astnode;
        $$->token="SwitchBlockStatementGroups";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    | SwitchBlockStatementGroups SwitchBlockStatementGroup{
        $$=new astnode;
        $$->token="SwitchBlockStatementGroups";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
SwitchBlockStatementGroup:
    SwitchLabels BlockStatements{
        $$=new astnode;
        $$->token="SwitchBlockStatementGroup";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
SwitchLabels:
    SwitchLabel{
        $$=new astnode;
        $$->token="SwitchLabels";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    | SwitchLabels SwitchLabel{
        $$=new astnode;
        $$->token="SwitchLabels";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
SwitchLabel:
    CASE ConstantExpression COLON{
        $$=new astnode;
        $$->token="SwitchLabel";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    | DEFAULT COLON{
        $$=new astnode;
        $$->token="SwitchLabel";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
WhileStatement:
    WHILE WHILEMARK2 OPEN_BR Expression CLOSE_BR WHILEMARK1 Statement WHILEEND1{
        $$=new astnode;
        $$->token="WhileStatement";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($3);
        v.push_back($4);
        v.push_back($5);
        v.push_back($7);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
WhileStatementNoShortIf:
    WHILE WHILEMARK2 OPEN_BR Expression CLOSE_BR WHILEMARK1 StatementNoShortIf WHILEEND1{
        $$=new astnode;
        $$->token="WhileStatementNoShortIf";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($3);
        v.push_back($4);
        v.push_back($5);
        v.push_back($7);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
DoStatement:
    DO DOMARK1 Statement WHILE OPEN_BR Expression CLOSE_BR SEMICOLON DOEND1{
        $$=new astnode;
        $$->token="DoStatement";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($3);
        v.push_back($4);
        v.push_back($5);
        v.push_back($6);
        v.push_back($7);
        v.push_back($8);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
ForStatement:
    FOR OPEN_BR FORMARK1 SEMICOLON FORMARK2 SEMICOLON CLOSE_BR FORMARK3 Statement FOREND1{
        $$=new astnode;
        $$->token="ForStatement";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($4);
        v.push_back($6);
        v.push_back($7);
        v.push_back($9);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    | FOR OPEN_BR FORMARK1 SEMICOLON FORMARK2 SEMICOLON ForUpdate CLOSE_BR FORMARK3 Statement FOREND1{
        $$=new astnode;
        $$->token="ForStatement";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($4);
        v.push_back($6);
        v.push_back($7);
        v.push_back($8);
        v.push_back($10);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    | FOR OPEN_BR FORMARK1 SEMICOLON Expression FORMARK2 SEMICOLON CLOSE_BR FORMARK3 Statement FOREND1{
        $$=new astnode;
        $$->token="ForStatement";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($4);
        v.push_back($5);
        v.push_back($7);
        v.push_back($8);
        v.push_back($10);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    | FOR OPEN_BR FORMARK1 SEMICOLON Expression FORMARK2 SEMICOLON ForUpdate CLOSE_BR FORMARK3 Statement FOREND1{
        $$=new astnode;
        $$->token="ForStatement";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($4);
        v.push_back($5);
        v.push_back($7);
        v.push_back($8);
        v.push_back($9);
        v.push_back($11);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    | FOR OPEN_BR ForInit FORMARK1 SEMICOLON FORMARK2 SEMICOLON CLOSE_BR FORMARK3 Statement FOREND1{
        $$=new astnode;
        $$->token="ForStatement";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($5);
        v.push_back($7);
        v.push_back($8);
        v.push_back($10);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    | FOR OPEN_BR ForInit FORMARK1 SEMICOLON FORMARK2 SEMICOLON ForUpdate CLOSE_BR FORMARK3 Statement FOREND1{
        $$=new astnode;
        $$->token="ForStatement";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($5);
        v.push_back($7);
        v.push_back($8);
        v.push_back($9);
        v.push_back($11);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    | FOR OPEN_BR ForInit FORMARK1 SEMICOLON Expression FORMARK2 SEMICOLON CLOSE_BR FORMARK3 Statement FOREND1{
        $$=new astnode;
        $$->token="ForStatement";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($5);
        v.push_back($6);
        v.push_back($8);
        v.push_back($9);
        v.push_back($11);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    | FOR OPEN_BR ForInit FORMARK1 SEMICOLON Expression FORMARK2 SEMICOLON ForUpdate CLOSE_BR FORMARK3 Statement FOREND1{
        $$=new astnode;
        $$->token="ForStatement";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($5);
        v.push_back($6);
        v.push_back($8);
        v.push_back($9);
        v.push_back($10);
        v.push_back($12);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
ForStatementNoShortIf:
    FOR OPEN_BR FORMARK1 SEMICOLON FORMARK2 SEMICOLON CLOSE_BR FORMARK3 StatementNoShortIf FOREND1{
        $$=new astnode;
        $$->token="ForStatementNoShortIf";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($4);
        v.push_back($6);
        v.push_back($7);
        v.push_back($9);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    | FOR OPEN_BR FORMARK1 SEMICOLON FORMARK2 SEMICOLON ForUpdate CLOSE_BR FORMARK3 StatementNoShortIf FOREND1{
        $$=new astnode;
        $$->token="ForStatementNoShortIf";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($4);
        v.push_back($6);
        v.push_back($7);
        v.push_back($8);
        v.push_back($10);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    | FOR OPEN_BR FORMARK1 SEMICOLON Expression FORMARK2 SEMICOLON CLOSE_BR FORMARK3 StatementNoShortIf FOREND1{
        $$=new astnode;
        $$->token="ForStatementNoShortIf";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($4);
        v.push_back($5);
        v.push_back($7);
        v.push_back($8);
        v.push_back($10);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    | FOR OPEN_BR FORMARK1 SEMICOLON Expression FORMARK2 SEMICOLON ForUpdate CLOSE_BR FORMARK3 StatementNoShortIf FOREND1{
        $$=new astnode;
        $$->token="ForStatementNoShortIf";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($4);
        v.push_back($5);
        v.push_back($7);
        v.push_back($8);
        v.push_back($9);
        v.push_back($11);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    | FOR OPEN_BR ForInit FORMARK1 SEMICOLON FORMARK2 SEMICOLON CLOSE_BR FORMARK3 StatementNoShortIf FOREND1{
        $$=new astnode;
        $$->token="ForStatementNoShortIf";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($5);
        v.push_back($7);
        v.push_back($8);
        v.push_back($10);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    | FOR OPEN_BR ForInit FORMARK1 SEMICOLON FORMARK2 SEMICOLON ForUpdate CLOSE_BR FORMARK3 StatementNoShortIf FOREND1{
        $$=new astnode;
        $$->token="ForStatementNoShortIf";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($5);
        v.push_back($7);
        v.push_back($8);
        v.push_back($9);
        v.push_back($11);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    | FOR OPEN_BR ForInit FORMARK1 SEMICOLON Expression FORMARK2 SEMICOLON CLOSE_BR FORMARK3 StatementNoShortIf FOREND1{
        $$=new astnode;
        $$->token="ForStatementNoShortIf";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($5);
        v.push_back($6);
        v.push_back($8);
        v.push_back($9);
        v.push_back($11);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    | FOR OPEN_BR ForInit FORMARK1 SEMICOLON Expression FORMARK2 SEMICOLON ForUpdate CLOSE_BR FORMARK3 StatementNoShortIf FOREND1{
        $$=new astnode;
        $$->token="ForStatementNoShortIf";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($5);
        v.push_back($6);
        v.push_back($8);
        v.push_back($9);
        v.push_back($10);
        v.push_back($12);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
ForInit:
    StatementExpressionList{
        $$=new astnode;
        $$->token="ForInit";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
        $$->tac_val=$1->tac_val;
    }
    | LocalVariableDeclaration{
        $$=new astnode;
        $$->token="ForInit";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        string s=$1->value;
        vector<string>tokens=split(s,',');
        for(int i=0;i<tokens.size();i++) {
            buffer[tokens[i]]=$1->type;
        }
        // buffer[$1->value]=$1->type;
        // cout<<"in"<<$$->token;
    }
;
ForUpdate:
    StatementExpressionList{
        $$=new astnode;
        $$->token="ForUpdate";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
        $$->tac_val=$1->tac_val;
    }
;
StatementExpressionList:
    StatementExpression{
        $$=new astnode;
        $$->token="StatementExpressionList";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
        $$->tac_val=$1->tac_val;
    }
    | StatementExpressionList COMMA StatementExpression{
        $$=new astnode;
        $$->token="StatementExpressionList";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        // cout<<"in"<<$$->token;
        $$->tac_val=$1->tac_val=","+$1->tac_val;
    }
;
BreakStatement:
    BREAK SEMICOLON{
        $$=new astnode;
        $$->token="BreakStatement";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        $$->children=v;
        // cout<<"in"<<$$->token;
        string tac,toget_label;
        toget_label=while_endlabels.top();
        tac="goto "+toget_label;
         prog.push_back(tac);
    }
    | BREAK IDENTIFIER SEMICOLON{
        $$=new astnode;
        $$->token="BreakStatement";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
ContinueStatement:
    CONTINUE SEMICOLON{
        $$=new astnode;
        $$->token="ContinueStatement";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        $$->children=v;
        // cout<<"in"<<$$->token;
        string tac,toget_label;
        toget_label=while_bwlabels.top();
        tac="goto "+toget_label;
         prog.push_back(tac);
    }
    | CONTINUE IDENTIFIER SEMICOLON{
        $$=new astnode;
        $$->token="ContinueStatement";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        // cout<<"in"<<$$->token;
        string tac,toget_label;
        toget_label=m[$2->lexeme];
        tac="goto "+toget_label;
         prog.push_back(tac);
    }
;
ReturnStatement:
    RETURN SEMICOLON{
        $$=new astnode;
        $$->token="ReturnStatement";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        $$->children=v;
        // cout<<"in"<<$$->token;
        // prog.push_back("return");
        $$->tac_val="return";
        $$->type="void";
    }
    | RETURN Expression SEMICOLON{
        $$=new astnode;
        $$->token="ReturnStatement";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        // cout<<"in"<<$$->token;
        string tac;
        if($2->flag)
        tac="rax = t"+to_string(tempno-1);
        else tac = "rax = "+$2->tac_val;
         prog.push_back(tac);
        $$->tac_val=tac;
        $$->type=$2->type;
    }
;
ThrowStatement:
    THROW Expression SEMICOLON{
        $$=new astnode;
        $$->token="ThrowStatement";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
SynchronizedStatement:
    SYNCHRONIZED OPEN_BR Expression CLOSE_BR Block{
        $$=new astnode;
        $$->token="SynchronizedStatement";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($4);
        v.push_back($5);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
TryStatement:
    TRY Block Catches{
        $$=new astnode;
        $$->token="TryStatement";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    | TRY Block Finally {
        $$=new astnode;
        $$->token="TryStatement";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    | TRY Block Catches Finally{
        $$=new astnode;
        $$->token="TryStatement";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($4);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
Catches:
    CatchClause{
        $$=new astnode;
        $$->token="Catches";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
    | Catches CatchClause{
        $$=new astnode;
        $$->token="Catches";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
CatchClause:
    CATCH OPEN_BR FormalParameter CLOSE_BR Block{
        $$=new astnode;
        $$->token="CatchClause";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($4);
        v.push_back($5);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;
Finally:
    FINALLY Block{
        $$=new astnode;
        $$->token="Finally";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        $$->children=v;
        // cout<<"in"<<$$->token;
    }
;

//----------------------------EXPRESSION---------------------------

Primary:
    PrimaryNoNewArray {
        $$=new astnode;
        $$->token="Primary";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->tac_val=$1->tac_val;
        $$->code=$1->code;
        // cout<<"in"<<$$->token;
        $$->flag=$1->flag;
        $$->type=$1->type;
        $$->dims=$1->dims;
        if($$->flag==4) {
            Type*t=symtabGetTypep(fullscope,$1->value);
            cout<<t->dims<<" ";
            cout<<$$->dims;
            if(t)
            if($$->dims!=t->dims) cout<<"Error array of not same dimension";
        }
    }
    |ArrayCreationExpression{
        $$=new astnode;
        $$->token="Primary";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
        $$->tac_val=$1->tac_val;
        $$->flag=$1->flag;
        $$->type=$1->type;
        $$->dims=$1->dims;
    }
;
PrimaryNoNewArray:
    Literal{
        $$=new astnode;
        $$->token="PrimaryNoNewArray";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->tac_val=$1->tac_val;
        $$->code=$1->code;
        // cout<<"in"<<$$->token;
        $$->flag=$1->flag;
        $$->type=$1->type;
    }
    |THIS{
        $$=new astnode;
        $$->token="PrimaryNoNewArray";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
        $$->tac_val=$1->lexeme;
        $$->type="this";
    }
    | OPEN_BR Expression CLOSE_BR{
        $$=new astnode;
        $$->token="PrimaryNoNewArray";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        // cout<<"in"<<$$->token;
        if($2->flag==1) {
            $$->tac_val="t"+to_string(tempno-1);
        }
        else {
            $$->tac_val=$2->tac_val;
        }
        $$->type=$2->type;
    }
    |ClassInstanceCreationExpression{
        $$=new astnode;
        $$->token="PrimaryNoNewArray";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
        $$->tac_val=$1->tac_val;
        $$->flag=$1->flag;
         $$->type=$1->type; // NEED TO SEE
    }
    |FieldAccess{
        $$=new astnode;
        $$->token="PrimaryNoNewArray";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
        $$->tac_val=$1->tac_val;
        $$->type=$1->type;
        $$->flag=$1->flag;
    }
    |MethodInvocation{
        $$=new astnode;
        $$->token="PrimaryNoNewArray";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->tac_val=$1->tac_val;
        // cout<<"in"<<$$->token;
        // symtab_t* t=symtab_top[fullscope];
        // $$->type=symtabGetType(t,$1->value);
        $$->flag=$1->flag;
        $$->type=$1->type;
    }
    |ArrayAccess{
        $$=new astnode;
        $$->token="PrimaryNoNewArray";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
        $$->tac_val=$1->tac_val;
        $$->flag=$1->flag;
        $$->dims=$1->dims;
        $$->type=$1->type;
        $$->value=$1->value;
    }

;
ClassInstanceCreationExpression:
    NEW ClassType OPEN_BR CLOSE_BR{
        $$=new astnode;
        $$->token="ClassInstanceCreationExpression";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($4);
        $$->children=v;
        // cout<<"in"<<$$->token;
        string tac,temp=get_tempvar();
        tac="Lcall_Alloc\n"; 
        tac=tac+temp+" = "+$2->tac_val;
        tac=tac+"\n"+"call "+$2->tac_val+".ctor 0";

        string scope=m1[$2->tac_val];
        // cout<<scope;
        symtab_t*t=symtab_top[scope];
        if((*t).find($2->tac_val)!=(*t).end()){
            Type*t1=(*t)[$2->tac_val];
            // cout<<endl<<t1->args;
            string s3=t1->args;
            vector<string>token1=split(s3,',');
            if(token1.size()>1) cout<<"arg length mismatch";
            else if(token1.size()==1&&token1[0]!="args") cout<<"arg mismatch";
        }
        
        $$->tac_val=tac;
        $$->flag=3;
        $$->type=$2->type;
    }
    | NEW ClassType OPEN_BR ArgumentList CLOSE_BR{
        $$=new astnode;
        $$->token="ClassInstanceCreationExpression";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($4);
        v.push_back($5);
        $$->children=v;
        // cout<<"in"<<$$->token;
        string tac,temp=get_tempvar();
        tac="Lcall_Alloc\n"; 
        tac=tac+temp+" = "+$2->tac_val;
        string s=$4->tac_val;
        vector<string>token=split(s,',');
        for(int i=0;i<token.size();i++) {
            tac="push "+token[i];
             prog.push_back(tac);
        }
        string scope=m1[$2->tac_val];
        // cout<<scope;
        symtab_t*t=symtab_top[scope];
        if((*t).find($2->tac_val)!=(*t).end()) cout<<"no constructor present";
        Type*t1=(*t)[$2->tac_val];
        // cout<<endl<<t1->args;
        string s3=t1->args;
        vector<string>token3=split($4->type,',');
        vector<string>token1=split(s3,',');
        if(token1.size()!=token3.size()) cout<<"arg length mismatch";
        for(int i=0;i<token3.size();i++) if(token3[i]!=token1[i]) cout<<"arg mismatch";
        // if(t1->args!=$4->tac_val) yyerror("arg mismatch");

        tac=tac+"\n"+"call "+$2->tac_val+".ctor "+to_string(token.size());
        $$->tac_val=tac;
        $$->flag=3;
        $$->type=$2->type;
    }
;
ArgumentList:
    Expression{
        $$=new astnode;
        $$->token="ArgumentList";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
        $$->tac_val=$1->tac_val;
        $$->type=$1->type;
    }
	| ArgumentList COMMA Expression{
        $$=new astnode;
        $$->token="ArgumentList";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        // cout<<"in"<<$$->token;
        $$->tac_val=$1->tac_val+","+$3->tac_val;
        $$->type=$1->type+","+$3->type;
    }
;
ArrayCreationExpression:
	NEW PrimitiveType DimExprs {
        $$=new astnode;
        $$->token="ArrayCreationExpression";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        // cout<<"in"<<$$->token;
        string tac,temp=get_tempvar();
        tac="Lcall_Alloc\n"; 
        tac=tac+temp+" = "+$2->type+$3->tac_val;
        $$->tac_val=tac;
        $$->flag=4;
        $$->type=$2->type;
        $$->dims=$3->dims;
    }
    | NEW PrimitiveType DimExprs Dims {
        $$=new astnode;
        $$->token="ArrayCreationExpression";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        // cout<<"in"<<$$->token;
        string tac,temp=get_tempvar();
        tac="Lcall_Alloc\n"; 
        tac=tac+temp+" = "+$2->type+$3->tac_val+$4->tac_val;
        $$->tac_val=tac;
        $$->flag=4;
        $$->type=$2->type;
        $$->dims=$3->dims+$4->dims;
    }
    | NEW ClassOrInterfaceType DimExprs {
        $$=new astnode;
        $$->token="ArrayCreationExpression";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        // cout<<"in"<<$$->token;
        string tac,temp=get_tempvar();
        tac="Lcall_Alloc\n"; 
        tac=tac+temp+" = "+$2->tac_val+$3->tac_val;
        $$->tac_val=tac;
        $$->flag=4;
        $$->type=$2->type;
        $$->dims=$3->dims;
    }
	| NEW ClassOrInterfaceType DimExprs Dims{
        $$=new astnode;
        $$->token="ArrayCreationExpression";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($4);
        $$->children=v;
        // cout<<"in"<<$$->token;
        string tac,temp=get_tempvar();
        tac="Lcall_Alloc\n"; 
        tac=tac+temp+" = "+$2->tac_val+$3->tac_val+$4->tac_val;
        $$->tac_val=tac;
        $$->flag=4;
        $$->type=$2->type;
        $$->dims=$3->dims+$4->dims;
    }
;
DimExprs:
	DimExpr {
        $$=new astnode;
        $$->token="DimExprs";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
        $$->tac_val=$1->tac_val;
        $$->dims=$1->dims;
        $$->flag=$1->flag;
    }
	| DimExprs DimExpr {
        $$=new astnode;
        $$->token="DimExprs";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        $$->children=v;
        // cout<<"in"<<$$->token;
        $$->tac_val=$1->tac_val+$2->tac_val;
        $$->dims=$1->dims+1;
        $$->flag=$1->flag;
    }
;
DimExpr:
	OPEN_SQ Expression CLOSE_SQ {
        $$=new astnode;
        $$->token="DimExpr";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        // cout<<"in"<<$$->token;
        if($2->flag!=1&&$2->flag!=0) cout<<"array axis not defined";
        if($2->flag)
        $$->tac_val="[t"+to_string(tempno-1)+"]";
        else $$->tac_val="["+$2->tac_val+"]";
        $$->dims=1;
        $$->flag=4;
    }
;
Dims:
	OPEN_SQ CLOSE_SQ {
        $$=new astnode;
        $$->token="Dims";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        $$->children=v;
        // cout<<"in"<<$$->token;
        $$->tac_val="[]";
    }
	|Dims OPEN_SQ CLOSE_SQ {
        $$=new astnode;
        $$->token="Dims";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        // cout<<"in"<<$$->token;
        $$->tac_val=$1->tac_val+"[]";
    }
;
FieldAccess:
	Primary PERIOD IDENTIFIER {
        $$=new astnode;
        $$->token="FieldAccess";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        // cout<<"in"<<$$->token;
        $$->tac_val=$1->tac_val+"."+$3->lexeme;
        $$->type="fieldaccess";
        if($1->type=="this") {
            string scope=searchthis(fullscope);
            symtab_t*t=symtab_top[scope];
            if((*t).find($3->lexeme)!=(*t).end()){
                Type*t1=(*t)[$3->lexeme];
                $$->type=t1->type;
            }
            $$->flag=0;
        }
    }
	| SUPER PERIOD IDENTIFIER{
        $$=new astnode;
        $$->token="FieldAccess";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        // cout<<"in"<<$$->token;
        $$->tac_val=$1->lexeme+"."+$3->lexeme;
        $$->type="fieldaccess";
    }
;
MethodInvocation:
	Name OPEN_BR CLOSE_BR{
        $$=new astnode;
        $$->token="MethodInvocation";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        // symadd($1->value,"nd","ud");
        // cout<<"in"<<$$->token;
        $$->tac_val="call "+cname+"."+$1->tac_val+" 0";
        // symtab_t* t=symtab_top[fullscope];
        vector<string>tokens=split($1->value,'.');
        string x=m1[tokens[0]];
        if(fullscope.find(x)!=0){
            if($1->access_specifier==1)
            {
                cout<<"Method not accessible";
            }
        }
        // cout<<fullscope<<endl;
        string tac;
        tac="push pc + 1 ";
        prog.push_back(tac);
        tac="push obj_ref";
        prog.push_back(tac);
        $$->type=symtabGetType(fullscope,$1->tac_val);
        if($$->type!="0"){
            if(symtabGetArgs(fullscope,$1->value)!=""){
            cout<<"Argument list mismatch1";
        }
        }
        else{
            string s=$1->tac_val;
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
                $$->type=t1->type;
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
        $$->tac_val=$$->tac_val+"\n"+"deallocate 0";
        $$->flag=2;                
    }
    | Name OPEN_BR ArgumentList CLOSE_BR{
        $$=new astnode;
        $$->token="MethodInvocation";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($4);
        $$->children=v;
        vector<string>tokens=split($1->value,'.');
        if(m1.find(tokens[0])!=m1.end()){
            string x=m1[tokens[0]];
            if(fullscope.find(x)!=0){
                if($1->access_specifier==1)
                {
                    cout<<"Method not accessible";
                }
            }
        }
        
        // symadd($1->value,"nd","ud");
        // cout<<"in"<<$$->token;
        string s=$3->tac_val,tac;
        vector<string>token=split(s,',');
        for(int i=0;i<token.size();i++) {
            tac="push "+token[i];
             prog.push_back(tac);
        }
        tac="push pc + 1 ";
        prog.push_back(tac);
        tac="push obj_ref";
        prog.push_back(tac);
        $$->tac_val="call "+cname+"."+$1->tac_val+" "+to_string(token.size());
        // symtab_t* t=symtab_top[fullscope];
        $$->type=symtabGetType(fullscope,$1->value);
        if($$->type!="0")
        {
            vector<string>args=split($3->type,',');
            vector<string>args1=split(symtabGetArgs(fullscope,$1->value),',');
            if(args.size()!=args1.size()) cout<<"Argument mismatch2";
            for(int i=0;i<args.size();i++){
                if(args[i]!=args1[i]) cout<<"Argument mismatch2";
            }
            int si=getsize(args1);
            $$->tac_val=$$->tac_val+"\n"+"deallocate "+to_string(si);
        }
        else{
            string s=$1->tac_val;
            vector<string>tokens=split(s,'.');
            s=symtabGetType(fullscope,tokens[0]);
            // if(s=="0") {
            //     if(m1.find(tokens[0])!=m1.end()){
            //     // for(auto k : m1){
            //     //     if(k.first==tokens[0]){
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
            //         // }
            //     }
            // }
            // else{
                symtab_t*t=symtab_top[m1[s]];
                Type*t1=(*t)[tokens[1]];
                $$->type=t1->type;
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
                vector<string>args=split($3->type,',');
                vector<string>args1=split(t1->args,',');
                if(args.size()!=args1.size()) cout<<"Argument mismatch2";
                for(int i=0;i<args.size();i++){
                    if(args[i]!=args1[i]) cout<<"Argument mismatch2";
                }
                int si=getsize(args1);
                $$->tac_val=$$->tac_val+"\n"+"deallocate "+to_string(si);
            // }
            
        }
        $$->flag=2; 
    }
    | Primary PERIOD IDENTIFIER OPEN_BR  CLOSE_BR{
        $$=new astnode;
        $$->token="MethodInvocation";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($4);
        v.push_back($5);
        $$->children=v;
        // symadd($1->value,"nd","ud");
        // cout<<"in"<<$$->token;
        $$->tac_val="call "+$1->tac_val+$2->lexeme+$3->lexeme+" 0";
        
        // symtab_t*t=symtab_top[$1->tac_val];
        // Type*t1=(*t)[$3->lexeme];
        // $$->type=t1->type;
        // cout<<$$->type<<" ";
        // cout<<t1->args;
        // if(t1->args!=""){
        //     yyerror("Argument list mismatch3");
        // }
        $$->type=symtabGetType(fullscope,$1->value);
        if(symtabGetArgs(fullscope,$1->value)!=""){
            cout<<"Argument list mismatch1";
        }
        $$->flag=2;     
    }
	| Primary PERIOD IDENTIFIER OPEN_BR ArgumentList CLOSE_BR{
        $$=new astnode;
        $$->token="MethodInvocation";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($4);
        v.push_back($5);
        v.push_back($6);
        $$->children=v;
        // symadd($1->value,"nd","ud");
        // cout<<"in"<<$$->token;
        string s=$5->tac_val,tac;
        vector<string>token=split(s,',');
        for(int i=0;i<token.size();i++) {
            tac="push "+token[i];
             prog.push_back(tac);
        }
        $$->tac_val="call "+$1->tac_val+$2->lexeme+$3->lexeme+" "+to_string(token.size());
        $$->type=symtabGetType(fullscope,$3->lexeme);
        // cout<<$$->type<<endl;
        // cout<<$3->type<<endl;
        vector<string>args=split($5->type,',');
        
        vector<string>args1=split(symtabGetArgs(fullscope,$3->lexeme),',');
        if(args.size()!=args1.size()) cout<<"Argument mismatch4";
        for(int i=0;i<args.size();i++){
            if(args[i]!=args1[i]) cout<<"Argument mismatch4";
        }
        $$->flag=2;   
    }
    | SUPER PERIOD IDENTIFIER OPEN_BR CLOSE_BR{
        $$=new astnode;
        $$->token="MethodInvocation";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($4);
        v.push_back($4);
        $$->children=v;
        // symadd($1->value,"nd","ud");
        // cout<<"in"<<$$->token;
        $$->tac_val="call "+$1->lexeme+$2->lexeme+$3->lexeme+" 0";
        $$->tac_val="call "+$1->tac_val+$2->lexeme+$3->lexeme+" 0";
        $$->type=symtabGetType(fullscope,$3->lexeme);
        if(symtabGetArgs(fullscope,$3->lexeme)!=""){
            cout<<"Argument list mismatch";
        }  
        $$->flag=2;   
    }
	| SUPER PERIOD IDENTIFIER OPEN_BR ArgumentList CLOSE_BR{
        $$=new astnode;
        $$->token="MethodInvocation";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($4);
        v.push_back($5);
        v.push_back($6);
        $$->children=v;
        // symadd($1->value,"nd","ud");
        // cout<<"in"<<$$->token;
        string s=$5->tac_val,tac;
        vector<string>token=split(s,',');
        for(int i=0;i<token.size();i++) {
            tac="push "+token[i];
             prog.push_back(tac);
        }
        $$->tac_val="call "+$1->lexeme+$2->lexeme+$3->lexeme+" "+to_string(token.size());
        $$->type=symtabGetType(fullscope,$3->lexeme);
        // cout<<$$->type<<endl;
        // cout<<$3->type<<endl;
        vector<string>args=split($5->type,',');
        $$->flag=2;   
        vector<string>args1=split(symtabGetArgs(fullscope,$3->lexeme),',');
        if(args.size()!=args1.size()) cout<<"Argument mismatch";
        for(int i=0;i<args.size();i++){
            if(args[i]!=args1[i]) cout<<"Argument mismatch";
        }
    }
;
ArrayAccess:
	Name OPEN_SQ Expression CLOSE_SQ{
        $$=new astnode;
        $$->token="ArrayAccess";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($4);
        $$->children=v;
        // cout<<"in"<<$$->token;
        if($3->type!="int") {
            cout<<"array index not defined";
        }
        string tac,var;
        if($3->flag) {
            var=get_tempvar();
            tac=var+" = t"+to_string(tempno-2)+"*8";
        }
        else{
            var=get_tempvar();
            tac=var+" = "+$3->tac_val+"*8";
        }
        $$->flag=4;
        $$->dims=$$->dims+1;
         prog.push_back(tac);
        var=get_tempvar();
        tac=var+" = "+$1->tac_val+"[t"+to_string(tempno-2)+"]";
        $$->tac_val=var;
         prog.push_back(tac);
        $$->type=$1->type;
        $$->value=$1->value;
    }
	| PrimaryNoNewArray OPEN_SQ Expression CLOSE_SQ{
        $$=new astnode;
        $$->token="ArrayAccess";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($4);
        $$->children=v;
        // cout<<"in"<<$$->token;
        string tac,var;
        if($3->flag) {
            var=get_tempvar();
            tac=var+" = t"+to_string(tempno-2)+"*8";
        }
        else{
            var=get_tempvar();
            tac=var+" = "+$3->tac_val+"*8";
        }
        $$->flag=4;
        $$->dims=$1->dims+1;
         prog.push_back(tac);
        var=get_tempvar();
        tac=var+" = "+$1->tac_val+"[t"+to_string(tempno-2)+"]";
        $$->tac_val=var;
         prog.push_back(tac);
        $$->type=$1->type;
        $$->value=$1->value;
    }
;
PostfixExpression:
	Primary{
        $$=new astnode;
        $$->token="PostfixExpression";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->tac_val=$1->tac_val;
        $$->code=$1->code;
        // cout<<"in"<<$$->token;
        $$->flag=$1->flag;
        $$->dims=$1->dims;
        $$->type=$1->type;
    }
	| Name {
        $$=new astnode;
        $$->token="PostfixExpression";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->tac_val=$1->tac_val;
        $$->code=$1->code;
        // cout<<"in"<<$$->token;
        $$->flag=$1->flag;
        $$->type=$1->type;
    }
	| PostIncrementExpression {
        $$=new astnode;
        $$->token="PostfixExpression";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->tac_val=$1->tac_val;
        $$->code=$1->code;
        // cout<<"in"<<$$->token;
        $$->type=$1->type;
    }
	| PostDecrementExpression{
        $$=new astnode;
        $$->token="PostfixExpression";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->tac_val=$1->tac_val;
        $$->code=$1->code;
        // cout<<"in"<<$$->token;
        $$->type=$1->type;
    }
;
PostIncrementExpression:
	PostfixExpression INC {
        $$=new astnode;
        $$->token="PostfixIncrementExpression";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        $$->children=v;
        string temp=get_tempvar();
        $$->tac_val=temp;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+","+temp;
        tac=temp+" = "+$1->tac_val;
        $$->code=tac+"\n";
         prog.push_back(tac);
        tac=$1->tac_val+" = "+$1->tac_val+" + 1";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
        $$->type=$1->type;
    }
;
PostDecrementExpression:
	PostfixExpression DEC{
        $$=new astnode;
        $$->token="PostfixDecrementExpression";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        $$->children=v;
        string temp=get_tempvar();
        $$->tac_val=temp;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+","+temp;
        tac=temp+" = "+$1->tac_val;
        $$->code=tac+"\n";
         prog.push_back(tac);
        tac=$1->tac_val+" = "+$1->tac_val+" - 1";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
        $$->type=$1->type;
    }
;
UnaryExpression:
	PreIncrementExpression{
        $$=new astnode;
        $$->token="UnaryExpression";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->tac_val=$1->tac_val;
        $$->code=$1->code;
        // cout<<"in"<<$$->token;
        $$->flag=$1->flag;
        $$->type=$1->type;
    }
	| PreDecrementExpression{
        $$=new astnode;
        $$->token="UnaryExpression";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->tac_val=$1->tac_val;
        $$->code=$1->code;
        // cout<<"in"<<$$->token;
        $$->type=$1->type;
    }
	| ADD UnaryExpression{
        $$=new astnode;
        $$->token="UnaryExpression";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        $$->children=v;
        string temp=get_tempvar();
        $$->tac_val=temp;
        string tac="";
        // tac=tac+$1->lexeme+","+$2->tac_val+","+","+temp;
        tac=temp+" = "+$1->lexeme+$2->tac_val;
        $$->code=tac+"\n";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
        $$->type=$2->type;
    }
	| SUB UnaryExpression{
        $$=new astnode;
        $$->token="UnaryExpression";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        $$->children=v;
        string temp=get_tempvar();
        $$->tac_val=temp;
        string tac="";
        // tac=tac+$1->lexeme+","+$2->tac_val+","+","+temp;
        tac=temp+" = "+$1->lexeme+$2->tac_val;
        $$->code=tac+"\n";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
        $$->type=$2->type;
    }
	| UnaryExpressionNotPlusMinus{
        $$=new astnode;
        $$->token="UnaryExpression";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->tac_val=$1->tac_val;
        $$->code=$1->code;
        // cout<<"in"<<$$->token;
        $$->flag=$1->flag;
        $$->type=$1->type;
        $$->dims=$1->dims;
    }
;
PreIncrementExpression:
	INC UnaryExpression{
        $$=new astnode;
        $$->token="PreIncrementExpression";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        $$->children=v;
        string temp=get_tempvar();
        $$->tac_val=temp;
        string tac="";
        // tac=tac+$1->lexeme+","+$2->tac_val+","+","+temp;
        tac=$2->tac_val+" = "+$2->tac_val+" + 1";
        $$->code=tac+"\n";
         prog.push_back(tac);
        tac=temp+" = "+$2->tac_val;
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
        $$->type=$1->type;
    }
;
PreDecrementExpression:
	DEC UnaryExpression{
        $$=new astnode;
        $$->token="PreDecrementExpression";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        $$->children=v;
        string temp=get_tempvar();
        $$->tac_val=temp;
        string tac="";
        // tac=tac+$1->lexeme+","+$2->tac_val+","+","+temp;
        tac=$2->tac_val+" = "+$2->tac_val+" - 1";
        $$->code=tac+"\n";
         prog.push_back(tac);
        tac=temp+" = "+$2->tac_val;
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
        $$->type=$1->type;
    }
;
UnaryExpressionNotPlusMinus:
	PostfixExpression{
        $$=new astnode;
        $$->token="UnaryExpressionNotPlusMinus";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->tac_val=$1->tac_val;
        $$->code=$1->code;
        // cout<<"in"<<$$->token;
        $$->flag=$1->flag;
        $$->type=$1->type;
        $$->dims=$1->dims;
    }
	| TILDE UnaryExpression {
        $$=new astnode;
        $$->token="UnaryExpressionNotPlusMinus";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        $$->children=v;
        string temp=get_tempvar();
        $$->tac_val=temp;
        string tac="";
        // tac=tac+$1->lexeme+","+$2->tac_val+","+","+temp;
        tac=temp+" = "+$1->lexeme+" "+$2->tac_val;
        $$->code=tac+"\n";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
        $$->type=$2->type;
    }
	| NOT UnaryExpression{
        $$=new astnode;
        $$->token="UnaryExpressionNotPlusMinus";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        $$->children=v;
        string temp=get_tempvar();
        $$->tac_val=temp;
        string tac="";
        // tac=tac+$1->lexeme+","+$2->tac_val+","+","+temp;
        tac=temp+" = "+$1->lexeme+" "+$2->tac_val;
        $$->code=tac+"\n";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
        $$->type=$2->type;
    }
	| CastExpression{
        $$=new astnode;
        $$->token="UnaryExpressionNotPlusMinus";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->tac_val=$1->tac_val;
        // cout<<"in"<<$$->token;
        $$->type=$1->type;
    }
;
CastExpression:
	OPEN_BR PrimitiveType CLOSE_BR UnaryExpression{
        $$=new astnode;
        $$->token="CastExpression";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($4);
        $$->children=v;
        // cout<<"in"<<$$->token;
        string tac,temp=get_tempvar();
        tac=temp+" =cast_to_"+$2->type+" "+$4->tac_val;
         prog.push_back(tac);
        $$->tac_val=temp;
        $$->type=$2->type;
    }
    | OPEN_BR PrimitiveType Dims CLOSE_BR UnaryExpression{
        $$=new astnode;
        $$->token="CastExpression";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($4);
        v.push_back($5);
        $$->children=v;
        // cout<<"in"<<$$->token;
        string tac,temp=get_tempvar();
        tac=temp+" =cast_to_"+$2->type+$3->tac_val+" "+$5->tac_val;
         prog.push_back(tac);
        $$->tac_val=temp;
        $$->type=$2->type;
    }
	| OPEN_BR Expression CLOSE_BR UnaryExpressionNotPlusMinus{
        $$=new astnode;
        $$->token="CastExpression";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($4);
        $$->children=v;
        // cout<<"in"<<$$->token;
        $$->type=$2->type;
    }
	| OPEN_BR Name Dims CLOSE_BR UnaryExpressionNotPlusMinus{
        $$=new astnode;
        $$->token="CastExpression";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        v.push_back($4);
        v.push_back($5);
        $$->children=v;
        // cout<<"in"<<$$->token;
        $$->type=$2->type;
        // string tac,var=get_tempvar();
        // tac=var+" =cast_to_"+$2->type+$3->tac_val+" "+$5->tac_val;
        //  prog.push_back(tac);
    }
;
MultiplicativeExpression:
	UnaryExpression{
        $$=new astnode;
        $$->token="MultiplicativeExpression";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->tac_val=$1->tac_val;
        $$->code=$1->code;
        // cout<<"in"<<$$->token;
        $$->flag=$1->flag;
        $$->type=$1->type;
        $$->dims=$1->dims;
    }
	|MultiplicativeExpression MUL UnaryExpression{
        $$=new astnode;
        $$->token="MultiplicativeExpression";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        temp=symtypeEvaluate($1->type,$3->type,$2->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if($1->type != $3->type)
        {   if($1->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" =cast_to_"+temp+" "+$3->tac_val;
                prog.push_back(s1);
                $3->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+$1->tac_val;
        }
        s2=temp+"*";
        $$->type=temp;
        string temp1=get_tempvar();
        $$->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+$1->tac_val+" "+$2->lexeme+" "+$3->tac_val;
        $$->code=tac+"\n";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
	|MultiplicativeExpression QUO UnaryExpression{
        $$=new astnode;
        $$->token="MultiplicativeExpression";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        temp=symtypeEvaluate($1->type,$3->type,$2->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if($1->type != $3->type)
        {   if($1->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" =cast_to_"+temp+" "+$3->tac_val;
                prog.push_back(s1);
                $3->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+$1->tac_val;
        }
        s2=temp+"/";
        $$->type=temp;
        string temp1=get_tempvar();
        $$->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+$1->tac_val+" "+$2->lexeme+" "+$3->tac_val;
        $$->code=tac+"\n";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
	|MultiplicativeExpression REM UnaryExpression{
        $$=new astnode;
        $$->token="MultiplicativeExpression";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        temp=symtypeEvaluate($1->type,$3->type,$2->lexeme);
       if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if($1->type != $3->type)
        {   if($1->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" =cast_to_"+temp+" "+$3->tac_val;
                prog.push_back(s1);
                $3->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+$1->tac_val;
        }
        s2=temp+"%";
        $$->type=temp;
        string temp1=get_tempvar();
        $$->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+$1->tac_val+" "+$2->lexeme+" "+$3->tac_val;
        $$->code=tac+"\n";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
;
AdditiveExpression:
	MultiplicativeExpression{
        $$=new astnode;
        $$->token="AdditiveExpression";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->tac_val=$1->tac_val;
        $$->code=$1->code;
        // cout<<"in"<<$$->token;
        $$->flag=$1->flag;
        $$->type=$1->type;
        $$->dims=$1->dims;
    }
	|AdditiveExpression ADD MultiplicativeExpression{
        $$=new astnode;
        $$->token="AdditiveExpression";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        string temp=get_tempvar();
        temp=symtypeEvaluate($1->type,$3->type,$2->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if($1->type != $3->type)
        {   if($1->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" =cast_to_"+temp+" "+$3->tac_val;
                prog.push_back(s1);
                $3->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+$1->tac_val;
        }
        s2=temp+"+";
        $$->type=temp;
        string temp1=get_tempvar();
        $$->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+$1->tac_val+" "+$2->lexeme+" "+$3->tac_val;
        $$->code=tac+"\n";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
	|AdditiveExpression SUB MultiplicativeExpression{
        $$=new astnode;
        $$->token="AdditiveExpression";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        temp=symtypeEvaluate($1->type,$3->type,$2->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if($1->type != $3->type)
        {   if($1->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" =cast_to_"+temp+" "+$3->tac_val;
                prog.push_back(s1);
                $3->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+$1->tac_val;
        }
        s2=temp+"-";
        $$->type=temp;
        string temp1=get_tempvar();
        $$->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+$1->tac_val+" "+$2->lexeme+" "+$3->tac_val;
        $$->code=tac+"\n";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
;
ShiftExpression:
	AdditiveExpression{
        $$=new astnode;
        $$->token="ShiftExpression";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->tac_val=$1->tac_val;
        $$->code=$1->code;
        // cout<<"in"<<$$->token;
        $$->flag=$1->flag;
        $$->type=$1->type;
        $$->dims=$1->dims;
    }
	|ShiftExpression SHL AdditiveExpression{
        $$=new astnode;
        $$->token="ShiftExpression";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
       temp=symtypeEvaluate($1->type,$3->type,$2->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if($1->type != $3->type)
        {   if($1->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" =cast_to_"+temp+" "+$3->tac_val;
                prog.push_back(s1);
                $3->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+$1->tac_val;
        }
        s2=temp+"<<";
        $$->type=temp;
        string temp1=get_tempvar();
        $$->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+$1->tac_val+" "+$2->lexeme+" "+$3->tac_val;
        $$->code=tac+"\n";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
	|ShiftExpression SHR AdditiveExpression {
        $$=new astnode;
        $$->token="ShiftExpression";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        temp=symtypeEvaluate($1->type,$3->type,$2->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if($1->type != $3->type)
        {   if($1->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" =cast_to_"+temp+" "+$3->tac_val;
                prog.push_back(s1);
                $3->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+$1->tac_val;
        }
        s2=temp+">>";
        $$->type=temp;
        string temp1=get_tempvar();
        $$->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+$1->tac_val+" "+$2->lexeme+" "+$3->tac_val;
        $$->code=tac+"\n";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
	|ShiftExpression GR AdditiveExpression{
        $$=new astnode;
        $$->token="ShiftExpression";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        temp=symtypeEvaluate($1->type,$3->type,$2->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if($1->type != $3->type)
        {   if($1->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" =cast_to_"+temp+" "+$3->tac_val;
                prog.push_back(s1);
                $3->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+$1->tac_val;
        }
        s2=temp+">>>";
        $$->type=temp;
        string temp1=get_tempvar();
        $$->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+$1->tac_val+" "+$2->lexeme+" "+$3->tac_val;
        $$->code=tac+"\n";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
;
RelationalExpression:
	ShiftExpression{
        $$=new astnode;
        $$->token="RelationalExpression";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->tac_val=$1->tac_val;
        $$->code=$1->code;
        // cout<<"in"<<$$->token;
        $$->flag=$1->flag;
        $$->type=$1->type;
        $$->dims=$1->dims;
    }
	|RelationalExpression LSS ShiftExpression{
        $$=new astnode;
        $$->token="RelationalExpression";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        temp=symtypeEvaluate($1->type,$3->type,$2->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if($1->type != $3->type)
        {   if($1->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" =cast_to_"+temp+" "+$3->tac_val;
                prog.push_back(s1);
                $3->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+$1->tac_val;
        }
        s2=temp+"<";
        $$->type="boolean";
        string temp1=get_tempvar();
        $$->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+$1->tac_val+" "+$2->lexeme+" "+$3->tac_val;
        $$->code=tac+"\n";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
	|RelationalExpression GTR ShiftExpression{
        $$=new astnode;
        $$->token="RelationalExpression";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        temp=symtypeEvaluate($1->type,$3->type,$2->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if($1->type != $3->type)
        {   if($1->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" =cast_to_"+temp+" "+$3->tac_val;
                prog.push_back(s1);
                $3->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+$1->tac_val;
        }
        s2=temp+">";
        $$->type="boolean";
        string temp1=get_tempvar();
        $$->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+$1->tac_val+" "+$2->lexeme+" "+$3->tac_val;
        $$->code=tac+"\n";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
	|RelationalExpression LEQ ShiftExpression{
        $$=new astnode;
        $$->token="RelationalExpression";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        temp=symtypeEvaluate($1->type,$3->type,$2->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if($1->type != $3->type)
        {   if($1->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" =cast_to_"+temp+" "+$3->tac_val;
                prog.push_back(s1);
                $3->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+$1->tac_val;
        }
        s2=temp+"<=";
        $$->type="boolean";
        string temp1=get_tempvar();
        $$->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+$1->tac_val+" "+$2->lexeme+" "+$3->tac_val;
        $$->code=tac+"\n";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
	|RelationalExpression GEQ ShiftExpression{
        $$=new astnode;
        $$->token="RelationalExpression";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        temp=symtypeEvaluate($1->type,$3->type,$2->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if($1->type != $3->type)
        {   if($1->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" =cast_to_"+temp+" "+$3->tac_val;
                prog.push_back(s1);
                $3->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+$1->tac_val;
        }
        s2=temp+">=";
        $$->type="boolean";
        string temp1=get_tempvar();
        $$->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+$1->tac_val+" "+$2->lexeme+" "+$3->tac_val;
        $$->code=tac+"\n";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
	|RelationalExpression INSTANCEOF ReferenceType{
        $$=new astnode;
        $$->token="RelationalExpression";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        // cout<<"in"<<$$->token;
        temp=symAssignment($1->type,$3->type);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        $$->type="boolean";
        string tac,temp1=get_tempvar();
        tac=temp1+" = "+$1->tac_val+" "+$2->lexeme+" "+$3->tac_val;
         prog.push_back(tac);
        $$->tac_val=temp1;
    }
;
EqualityExpression:
	RelationalExpression{
        $$=new astnode;
        $$->token="EqualityExpression";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->tac_val=$1->tac_val;
        $$->code=$1->code;
        // cout<<"in"<<$$->token;
        $$->flag=$1->flag;
        $$->type=$1->type;
        $$->dims=$1->dims;
    }
	|EqualityExpression EQL RelationalExpression{
        $$=new astnode;
        $$->token="EqualityExpression";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        temp=symtypeEvaluate($1->type,$3->type,$2->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if($1->type != $3->type)
        {   if($1->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" =cast_to_"+temp+" "+$3->tac_val;
                prog.push_back(s1);
                $3->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+$1->tac_val;
        }
        s2=temp+"==";
        $$->type="boolean";
        string temp1=get_tempvar();
        $$->tac_val=temp1;
        string tac="";
        // tac=$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+$1->tac_val+" "+$2->lexeme+" "+$3->tac_val;
        $$->code=tac+"\n";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
	|EqualityExpression NEQ RelationalExpression{
        $$=new astnode;
        $$->token="EqualityExpression";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        temp=symtypeEvaluate($1->type,$3->type,$2->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if($1->type != $3->type)
        {   if($1->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" =cast_to_"+temp+" "+$3->tac_val;
                prog.push_back(s1);
                $3->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+$1->tac_val;
        }
        s2=temp+"!=";
        $$->type="boolean";
        string temp1=get_tempvar();
        $$->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+$1->tac_val+" "+$2->lexeme+" "+$3->tac_val;
        $$->code=tac+"\n";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
;
AndExpression:
	EqualityExpression{
        $$=new astnode;
        $$->token="AndExpression";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->tac_val=$1->tac_val;
        $$->code=$1->code;
        // cout<<"in"<<$$->token;
        $$->flag=$1->flag;
        $$->type=$1->type;
        $$->dims=$1->dims;
    }
	|AndExpression AMPERSAT EqualityExpression{
        $$=new astnode;
        $$->token="AndExpression";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        temp=symtypeEvaluate($1->type,$3->type,$2->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if($1->type != $3->type)
        {   if($1->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" =cast_to_"+temp+" "+$3->tac_val;
                prog.push_back(s1);
                $3->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+$1->tac_val;
        }
        s2=temp+"&";
        $$->type="boolean";
        string temp1=get_tempvar();
        $$->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+$1->tac_val+" "+$2->lexeme+" "+$3->tac_val;
        $$->code=tac+"\n";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
;
ExclusiveOrExpression:
	AndExpression{
        $$=new astnode;
        $$->token="ExclusiveOrExpression";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->tac_val=$1->tac_val;
        $$->code=$1->code;
        // cout<<"in"<<$$->token;
        $$->flag=$1->flag;
        $$->type=$1->type;
        $$->dims=$1->dims;
    }
	|ExclusiveOrExpression XOR AndExpression{
        $$=new astnode;
        $$->token="ExclusiveOrExpression";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        temp=symtypeEvaluate($1->type,$3->type,$2->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if($1->type != $3->type)
        {   if($1->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" =cast_to_"+temp+" "+$3->tac_val;
                prog.push_back(s1);
                $3->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+$1->tac_val;
        }
        s2=temp+"^";
        $$->type="boolean";
        string temp1=get_tempvar();
        $$->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+$1->tac_val+" "+$2->lexeme+" "+$3->tac_val;
        $$->code=tac+"\n";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
;
InclusiveOrExpression:
	ExclusiveOrExpression{
        $$=new astnode;
        $$->token="InclusiveOrExpression";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->tac_val=$1->tac_val;
        $$->code=$1->code;
        // cout<<"in"<<$$->token;
        $$->flag=$1->flag;
        $$->type=$1->type;
        $$->dims=$1->dims;
    }
	|InclusiveOrExpression OR ExclusiveOrExpression{
        $$=new astnode;
        $$->token="InclusiveOrExpression";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        temp=symtypeEvaluate($1->type,$3->type,$2->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if($1->type != $3->type)
        {   if($1->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" =cast_to_"+temp+" "+$3->tac_val;
                prog.push_back(s1);
                $3->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+$1->tac_val;
        }
        s2=temp+"|";
        $$->type="boolean";
        string temp1=get_tempvar();
        $$->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+$1->tac_val+" "+$2->lexeme+" "+$3->tac_val;
        $$->code=tac+"\n";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
;
ConditionalAndExpression:
	InclusiveOrExpression{
        $$=new astnode;
        $$->token="ConditionalAndExpression";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->tac_val=$1->tac_val;
        $$->code=$1->code;
        // cout<<"in"<<$$->token;
        $$->flag=$1->flag;
        $$->type=$1->type;
        $$->dims=$1->dims;
    }
	|ConditionalAndExpression LAND InclusiveOrExpression{
        $$=new astnode;
        $$->token="ConditionalAndExpression";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        temp=symtypeEvaluate($1->type,$3->type,$2->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if($1->type != $3->type)
        {   if($1->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" =cast_to_"+temp+" "+$3->tac_val;
                prog.push_back(s1);
                $3->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+$1->tac_val;
        }
        s2=temp+"&&";
        $$->type="boolean";
        string temp1=get_tempvar();
        $$->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+$1->tac_val+" "+$2->lexeme+" "+$3->tac_val;
        $$->code=tac+"\n";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
;
ConditionalOrExpression:
	ConditionalAndExpression{
        $$=new astnode;
        $$->token="ConditionalOrExpression";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->tac_val=$1->tac_val;
        $$->code=$1->code;
        // cout<<"in"<<$$->token;
        $$->flag=$1->flag;
        $$->type=$1->type;
        $$->dims=$1->dims;
    }
	|ConditionalOrExpression LOR ConditionalAndExpression{
        $$=new astnode;
        $$->token="ConditionalOrExpression";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        temp=symtypeEvaluate($1->type,$3->type,$2->lexeme);
        if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        if($1->type != $3->type)
        {   if($1->type==temp){
                string t1=get_tempvar(),t2;
                s1=t1+" =cast_to_"+temp+" "+$3->tac_val;
                prog.push_back(s1);
                $3->tac_val=t1;
                // t2=get_tempvar();

            }
                
            else s1="cast_to_"+temp+" "+$1->tac_val;
        }
        s2=temp+"||";
        $$->type="boolean";
        string temp1=get_tempvar();
        $$->tac_val=temp1;
        string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        tac=temp1+" = "+$1->tac_val+" "+$2->lexeme+" "+$3->tac_val;
        $$->code=tac+"\n";
         prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
;
ConditionalExpression:
	ConditionalOrExpression{
        $$=new astnode;
        $$->token="ConditionalExpression";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->tac_val=$1->tac_val;
        $$->code=$1->code;
        // cout<<"in"<<$$->token;
        $$->flag=$1->flag;
        $$->type=$1->type;
        $$->dims=$1->dims;
    }
	|ConditionalOrExpression CONDMARK1 QMARK Expression CONDMARK2 COLON  ConditionalExpression CONDMARK3{
        $$=new astnode;
        $$->token="ConditionalExpression";
        vector<astnode*>v;
        v.push_back($1);
        v.push_back($3);
        v.push_back($4);
        v.push_back($6);
        v.push_back($7);
        $$->children=v;
        temp=symtypeEvaluate($4->type,$7->type);
        if(temp=="0")
        {
            // yyerror("Error, type incompatible");
        }
        $$->type=temp;
        // string temp=get_tempvar();
        // $$->tac_val=temp;
        // string tac="";
        // tac=tac+$2->lexeme+","+$1->tac_val+","+$3->tac_val+","+temp;
        //  prog.push_back(tac);
        // cout<<"in"<<$$->token;
    }
;
AssignmentExpression:
	ConditionalExpression{
        $$=new astnode;
        $$->token="AssignmentExpression";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->tac_val=$1->tac_val;
        $$->code=$1->code;
        // cout<<"in"<<$$->token;
        $$->flag=$1->flag;
        $$->type=$1->type;
        $$->dims=$1->dims;
    }
	|Assignment{
        $$=new astnode;
        $$->token="AssignmentExpression";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->tac_val=$1->tac_val;
        $$->code=$1->code;
        // cout<<"in"<<$$->token;
        $$->type=$1->type;
    }
;
Assignment:
	LeftHandSide AssignmentOperator AssignmentExpression{
        $$=new astnode;
        $$->token="Assignment";
        vector<astnode*>v;
        // cout<<$3->tac_val<<endl;
        v.push_back($1);
        v.push_back($2);
        v.push_back($3);
        $$->children=v;
        // string temp=get_tempvar();
        $$->tac_val=$1->tac_val;
        string tac="";
        // tac=tac+$2->tac_val+","+$1->tac_val+","+$3->tac_val+","+$1->tac_val;
        // cout<<"in"<<$$->token;
        if($3->type=="String" && !($2->lexeme=="+="||$2->lexeme=="="))
        {
            cout<<"String operation undefined";
            // exit(0);
        }
        // check for Strings once
        temp=symAssignment($1->type,$3->type);
        // cout<<$1->type<<" "<<$3->type;
       if(temp=="0")
        {
            cout<<"Error, type incompatible";
        }
        // if(($1->flag==4&&$3->flag!=4)||($1->flag!=4&&$3->flag==4)) cout<<"Error, type incompatible";
        // cout<<$1->flag<<" "<<$3->flag;
        if($1->flag==4||$3->flag==4) {
            Type*t=symtabGetTypep(fullscope,$1->value);
            if(t){
                // cout<<" "<<t->dims<<" "<<$1->value<<" "<<$3->dims<<endl;
                if(t->dims!=$3->dims) cout<<"Error, dims are different";
            }
        }
        if($1->type != $3->type)
        {   
            s1="typecast_to_"+temp+" t"+to_string(tempno-1);
            string t=get_tempvar();
            s1=t+" ="+s1;
            prog.push_back(s1);
        }
        s2=$2->tac_val+temp;
        // temp="int";
        if($3->flag==1)
        tac=$1->tac_val+" "+s2+" t"+to_string(tempno-1);
        else tac=$1->tac_val+" "+s2+" "+$3->tac_val;
        $$->code=tac+"\n";
        vector<string>v2=split($1->tac_val,'.');
        if(v2[0]=="this"){
            string s3=searchthis(fullscope);
            string classname="";
            map<string,string>::iterator it=m1.begin();
            while(it!=m1.end()){
                if(s3==it->second) {
                    classname=it->first;
                    break;
                }
                it++;
            }
            tac=get_tempvar()+" = symtable("+classname+","+v2[1]+")\n"+"*(obj_ref+t"+to_string(tempno)+") = "+$3->tac_val;
        }
        v2=split($3->tac_val,'.');
        if(v2[0]=="this"){
            string s3=searchthis(fullscope);
            string classname="";
            map<string,string>::iterator it=m1.begin();
            while(it!=m1.end()){
                if(s3==it->second) {
                    classname=it->first;
                    break;
                }
                it++;
            }
            tac=get_tempvar()+" = symtable("+classname+","+v2[1]+")\n"+$1->tac_val+" = *(obj_ref+t"+to_string(tempno)+")";
        }
         prog.push_back(tac);
        //  cout<<tac<<endl;
        $$->type=temp;
    }
;
LeftHandSide:
	Name{
        $$=new astnode;
        $$->token="LeftHandSide";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->tac_val=$1->tac_val;
        $$->value=$1->value;
        // cout<<"in"<<$$->token;
        $$->type=$1->type;
    }
	|FieldAccess{
        $$=new astnode;
        $$->token="LeftHandSide";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
        $$->tac_val=$1->tac_val;
        $$->type=$1->type;
    }
	|ArrayAccess{
        $$=new astnode;
        $$->token="LeftHandSide";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        // cout<<"in"<<$$->token;
        $$->tac_val=$1->tac_val;
        $$->type=$1->type;
        Type*t=symtabGetTypep(fullscope,$1->value);
        if(t){
            if(t->dims!=$1->dims) cout<<"Error dimension incorrect";
        }
    }
;
AssignmentOperator:
    ASSIGN{
        $$=new astnode;
        $$->token="AssignmentOperator";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->tac_val=$1->lexeme;
        // cout<<"in"<<$$->token;
    }
    | MUL_ASSIGN{
        $$=new astnode;
        $$->token="AssignmentOperator";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->tac_val=$1->lexeme;
        // cout<<"in"<<$$->token;
    }
    | QUO_ASSIGN{
        $$=new astnode;
        $$->token="AssignmentOperator";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->tac_val=$1->lexeme;
        // cout<<"in"<<$$->token;
    }
    | REM_ASSIGN{
        $$=new astnode;
        $$->token="AssignmentOperator";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->tac_val=$1->lexeme;
        // cout<<"in"<<$$->token;
    }
    | ADD_ASSIGN{
        $$=new astnode;
        $$->token="AssignmentOperator";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->tac_val=$1->lexeme;
        // cout<<"in"<<$$->token;
    }
    | SUB_ASSIGN{
        $$=new astnode;
        $$->token="AssignmentOperator";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->tac_val=$1->lexeme;
        // cout<<"in"<<$$->token;
    }
    | SHL_ASSIGN{
        $$=new astnode;
        $$->token="AssignmentOperator";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->tac_val=$1->lexeme;
        // cout<<"in"<<$$->token;
    }
    | SHR_ASSIGN{
        $$=new astnode;
        $$->token="AssignmentOperator";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->tac_val=$1->lexeme;
        // cout<<"in"<<$$->token;
    }
    | GEQUAL{
        $$=new astnode;
        $$->token="AssignmentOperator";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->tac_val=$1->lexeme;
        // cout<<"in"<<$$->token;
    }
    | AND_ASSIGN{
        $$=new astnode;
        $$->token="AssignmentOperator";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->tac_val=$1->lexeme;
        // cout<<"in"<<$$->token;
    }
    | XOR_ASSIGN{
        $$=new astnode;
        $$->token="AssignmentOperator";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->tac_val=$1->lexeme;
        // cout<<"in"<<$$->token;
    }
    | OR_ASSIGN{
        $$=new astnode;
        $$->token="AssignmentOperator";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->tac_val=$1->lexeme;
        // cout<<"in"<<$$->token;
    }
;
Expression:
	AssignmentExpression{
        $$=new astnode;
        $$->token="Expression";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->tac_val=$1->tac_val;
        $$->code=$1->code;
        // cout<<"in"<<$$->token;
        $$->flag=$1->flag;
        $$->type=$1->type;
        $$->dims=$1->dims;
    }
;
ConstantExpression:
	Expression{
        $$=new astnode;
        $$->token="ConstantExpression";
        vector<astnode*>v;
        v.push_back($1);
        $$->children=v;
        $$->tac_val=$1->tac_val;
        $$->code=$1->code;
        // cout<<"in"<<$$->token;
        $$->flag=$1->flag;
        $$->type=$1->type;
    }
;
%%


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
	int i=0,l=prog.size(),of=0;
    for(i=0;i<l;i++) {
        vector<string> words=split(prog[i],' ');
        if((words[0]=="Pop")&&(of!=0)){tac<<"SP = SP + "<<of<<endl;tac<<prog[i]<<endl;}
        else if(words[0]!="pop"){
            tac<<prog[i]<<endl;
        }
        else {
            symtab_t* table;
            while(words[0]=="pop"){
                i+=1;
                table=symtab_top[words[1]];
                // tac<<prog[i]<<endl;
                words=split(prog[i],' ');
            }
            i-=1;
            of=getoffset(table, 0);
            tac<<"SP = SP - "<<getoffset(table, 0)<<endl;
            for(auto i=table->begin();i!=table->end();i++){
                if(i->second->flag){
                    tac<<i->first<<" = BP + "<<4+i->second->offset<<endl;
                }
                else {tac<<i->first<<" = BP - "<<i->second->offset<<endl;}
            } 
        }
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
    ifstream tac_file("tac.txt");
    ofstream x86_file("Assembly.s");
    string tac_line;
    string s=".LC0:\n\t";
    s=s+".string  \"%d\\n\"\n\t.text\n\t.globl main\n";
    x86_file<<s;
    s="System.println:\n";
    s=s+"\tpushq	%rbp\n\tmovq	%rsp, %rbp\n\tmovq	16(%rbp), %rsi\n\tleaq	.LC0(%rip), %rdi\n\tmovq	$0, %rax\n\tcall printf@PLT\n\tmovq	$0, %rax\n\tmovq	%rbp, %rsp\n\tpopq	%rbp\n\tret\n";
    x86_file<<s;
    while(getline(tac_file,tac_line)){
        x86_file << convert_tac_to_x86(tac_line);
    }
    tac_file.close();
    x86_file.close();
    return 0;
}


int yyerror(const char*msg) {
	cout<<"ERROR in: "<<yylineno<<'\n';
    if(verb==1)
    cout<<msg<<'\n';
    exit(0);
    // return 0;
};