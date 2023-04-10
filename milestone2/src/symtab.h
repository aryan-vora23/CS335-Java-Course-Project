#include<bits/stdc++.h>
#include "type.h"
using namespace std;

typedef map<string,Type*> symtab_t;

extern map< string, symtab_t* >symtab_top;
extern symtab_t* symtab;
extern string fullscope;
extern int yylineno;
extern map<string,string>m1;
// extern yyerror;
// symtab_t* init_symtab_top();

symtab_t* init_symtab_top() {
    symtab_t*temp=new symtab_t;
    string keywords[] = {"abstract", "continue", "for", "new", "switch", "assert", "default", "if", "package", "synchronized", "boolean", "do", "goto", "private", "this", "break", "double", "implements", "protected", "throw", "byte", "else", "import", "public", "throws", "case", "enum", "instanceof", "return", "transient", "catch", "extends", "int", "short", "try", "char", "final", "interface", "static", "void", "class", "finally", "long", "strictfp", "volatile", "const", "float", "native", "super", "while", "_", "exports", "opens", "requires", "uses", "module", "permits", "sealed", "var", "non-sealed", "provides", "to", "with", "open", "record", "transitive", "yield"
	};
    for( int i=0; keywords[i] != "yield"; i++ ){
		(*temp)[ keywords[i] ] = NULL;
		//Type* = NULL for keywords
	}
	(*temp)[ "yield" ] = NULL;
    symtab_top["r"]=temp;

	//universe
	temp = new symtab_t;
	// (*temp)["import"] =  new Type();
	symtab_top["import"] = temp;

    temp=new symtab_t;
    symtab_top["0"]=temp;
    return temp;
}

// void symadd(string symname, Type* symtype) {
//     string scoped_name = fullscope + " " + symname;
// 	(*symtab)[scoped_name] = symtype;
// }

int getoffset(int flag) {
    int of=0;
    symtab_t*t=symtab;
    for( auto i=(t)->begin(); i != (t)->end(); i++ ){
		// symbolTable <<i->first;
		if( i->second != NULL && i->second->flag==flag) {
            of+=i->second->size;
        }
	}
    return of;
}

int getoffset(symtab_t*t,int flag){
    if(flag==0)
    {int of=0;
    for( auto i=(t)->begin(); i != (t)->end(); i++ ){
		// symbolTable <<i->first;
		if( i->second != NULL && i->second->flag==flag) {
            of+=i->second->size;
        }
	}
    return of;}
    else 
    {int of=0,x=0;
    for( auto i=(t)->begin(); i != (t)->end(); i++ ){
		// symbolTable <<i->first;
        if(i==t->begin()) x=i->second->size;
		if( i->second != NULL && i->second->flag==flag) {
            of+=i->second->size;
        }
	}
    return of+x;}
}

int getsize(vector<string>v) {
    int si=0;
    for(int i=0;i<v.size();i++) {
        if(v[i]=="byte") si+=1;
        if(v[i]=="short") si+=2;
        if(v[i]=="int") si+=4;
        if(v[i]=="long") si+=8;
        if(v[i]=="float") si+=4;
        if(v[i]=="double") si+=8;
        if(v[i]=="boolean") si+=1;
        if(v[i]=="char") si+=2;
    }
    return si;
}

void symadd(string symname, string symtype,string args) {
    // string scoped_name = fullscope + " " + symname;
	Type*type=new Type;
    type->lineno=yylineno;
    type->type=symtype;
    type->args=args;
    type->offset=getoffset(0);
    if(symtype=="byte") type->size=1;
    if(symtype=="short") type->size=2;
    if(symtype=="int") type->size=4;
    if(symtype=="long") type->size=8;
    if(symtype=="float") type->size=4;
    if(symtype=="double") type->size=8;
    if(symtype=="boolean") type->size=1;
    if(symtype=="char") type->size=2;
    if(args=="ud") type->args=""; //for function
    else if(args=="NULL") type->args="args"; //for class
    (*symtab)[symname]=type;
}

void symadd_para(string symname, string symtype,int flag) {
    // string scoped_name = fullscope + " " + symname;
	Type*type=new Type;
    type->lineno=yylineno;
    type->type=symtype;
    type->flag=flag;
    type->offset=getoffset(1);
    if(symtype=="byte") type->size=1;
    if(symtype=="short") type->size=2;
    if(symtype=="int") type->size=4;
    if(symtype=="long") type->size=8;
    if(symtype=="float") type->size=4;
    if(symtype=="double") type->size=8;
    if(symtype=="boolean") type->size=1;
    if(symtype=="char") type->size=2;
    // if(args=="ud") type->args=""; //for function
    // else if(args=="NULL") type->args="args"; //for class
    (*symtab)[symname]=type;
}

void symaddimp(string symname) {
    // string scoped_name = fullscope + " " + symname;
	Type*type=new Type;
    type->lineno=yylineno;
    type->type="import";
    // type->dims=dims;
    // type->offset=getoffset(0);
    // if(args=="ud") type->args=""; //for function
    // else if(args=="NULL") type->args="args"; //for class
    (*(symtab_top["import"]))[symname]=type;
}

void symadd(string symname, string symtype,int dims) {
    // string scoped_name = fullscope + " " + symname;
	Type*type=new Type;
    type->lineno=yylineno;
    type->type=symtype;
    type->dims=dims;
    type->offset=getoffset(0);
    if(symtype=="byte") type->size=1;
    if(symtype=="short") type->size=2;
    if(symtype=="int") type->size=4;
    if(symtype=="long") type->size=8;
    if(symtype=="float") type->size=4;
    if(symtype=="double") type->size=8;
    if(symtype=="boolean") type->size=1;
    if(symtype=="char") type->size=2;
    // if(args=="ud") type->args=""; //for function
    // else if(args=="NULL") type->args="args"; //for class
    (*symtab)[symname]=type;
}

void symadd(string symname, string symtype) {
    string scoped_name = fullscope + " " + symname;
    symtab_t *t=symtab_top[fullscope];
    if((*t).find(symname)!=(*t).end()) {
        cout<<"ERROR: redeclaration"<<endl;
        // exit(0);
    }
    t=symtab_top["r"];
    if((*t).find(symname)!=(*t).end()) {
        cout<<"ERROR: reserved word"<<endl;
        // exit(0);
    }
	Type*type=new Type;
    type->lineno=yylineno;
    type->type=symtype;
    type->offset=getoffset(0);
     if(symtype=="byte") type->size=1;
    if(symtype=="short") type->size=2;
    if(symtype=="int") type->size=4;
    if(symtype=="long") type->size=8;
    if(symtype=="float") type->size=4;
    if(symtype=="double") type->size=8;
    if(symtype=="boolean") type->size=1;
    if(symtype=="char") type->size=2;
    // type->args="("+args+")";
    // if(args=="ud") type->args="()"; 
    // else if(args=="NULL") type->args="args";
    (*symtab)[symname]=type;
}

void symadd_list(vector<string>tokens, string symtype) {
    string scoped_name;
    int l=tokens.size();
    int i;
    symtab_t *t=symtab_top[fullscope];
    symtab_t*t1=symtab_top["r"];
    // cout<<"\n"<<l<<endl;
    for(i=0;i<l;i++) {
    // scoped_name = fullscope + " " + tokens[i];
        
        if((*t).find(tokens[i])!=(*t).end()) {
            cout<<"ERROR: redeclaration"<<endl;
            // exit(0);
        }
        if((*t1).find(tokens[i])!=(*t1).end()) {
            cout<<"ERROR: reserved word"<<endl;
            // exit(0);
        }
        Type*type=new Type;
        if(symtype=="byte") type->size=1;
        if(symtype=="short") type->size=2;
        if(symtype=="int") type->size=4;
        if(symtype=="long") type->size=8;
        if(symtype=="float") type->size=4;
        if(symtype=="double") type->size=8;
        if(symtype=="boolean") type->size=1;
        if(symtype=="char") type->size=2;
        type->lineno=yylineno;
        type->type=symtype;
        type->offset=getoffset(0);
        (*symtab)[tokens[i]]=type;

    }
    // for(i=0;i<l;i++) {
    //     cout<<(*(symtab_top[fullscope]))[tokens[i]]<<" ";
    // }
}

string symtypeEvaluate(string type1, string type2)
{
    // cout<<endl<<type1<<" "<<type2<<endl;
    if(type1==type2)
    {
        return type2;
    }

    if(type1=="byte" && type2=="short") {return "short";}
    if(type1=="byte" && type2=="char") {return "char";}
    if(type1=="byte" && type2=="int"){return "int";}
    if(type1=="byte" && type2=="long"){return "long";}
    if(type1=="byte" && type2=="float"){return "float";}
    if(type1=="byte" && type2=="double"){return "double";}

    if(type1=="short" && type2=="char") {return "char";}
    if(type1=="short" && type2=="int"){return "int";}
    if(type1=="short" && type2=="long"){return "long";}
    if(type1=="short" && type2=="float"){return "float";}
    if(type1=="short" && type2=="double"){return "double";}

    if(type1=="char" && type2=="int"){return "int";}
    if(type1=="char" && type2=="long"){return "long";}
    if(type1=="char" && type2=="float"){return "float";}
    if(type1=="char" && type2=="double"){return "double";}

    if(type1=="int" && type2=="long"){return "long";}
    if(type1=="int" && type2=="float"){return "float";}
    if(type1=="int" && type2=="double"){return "double";}

    if(type1=="long" && type2=="float"){return "float";}
    if(type1=="long" && type2=="double"){return "double";}

    if(type1=="float" && type2=="double"){return "double";}

    if(type1=="String" && (type2=="byte" || type2=="short" || type2=="char" || type2=="int" || type2=="long" || type2=="float" | type2=="double"))
    {
        return "String";
    }
    


    //swap type1 and type 2 in above comparisions
    if(type2=="byte" && type1=="short") {return "short";}
    if(type2=="byte" && type1=="char") {return "char";}
    if(type2=="byte" && type1=="int"){return "int";}
    if(type2=="byte" && type1=="long"){return "long";}
    if(type2=="byte" && type1=="float"){return "float";}
    if(type2=="byte" && type1=="double"){return "double";}

    if(type2=="short" && type1=="char") {return "char";}
    if(type2=="short" && type1=="int"){return "int";}
    if(type2=="short" && type1=="long"){return "long";}
    if(type2=="short" && type1=="float"){return "float";}
    if(type2=="short" && type1=="double"){return "double";}

    if(type2=="char" && type1=="int"){return "int";}
    if(type2=="char" && type1=="long"){return "long";}
    if(type2=="char" && type1=="float"){return "float";}
    if(type2=="char" && type1=="double"){return "double";}

    if(type2=="int" && type1=="long"){return "long";}
    if(type2=="int" && type1=="float"){return "float";}
    if(type2=="int" && type1=="double"){return "double";}

    if(type2=="long" && type1=="float"){return "float";}
    if(type2=="long" && type1=="double"){return "double";}

    if(type2=="float" && type1=="double"){return "double";}

    if(type1=="String" && (type2=="byte" || type2=="short" || type2=="char" || type2=="int" || type2=="long" || type2=="float" | type2=="double"))
    {
        return "String";
    }

    return "0";
}


string symtypeEvaluate(string type1, string type2, string op)
{
    // cout<<op<<" "<<type1<<" "<<type2<<endl;
    if(op=="+") {
        if(type1=="boolean"|| type2=="boolean") return "0";
        else return symtypeEvaluate(type1,type2);
    }
    else if(op=="*"||op=="/"||op=="-") {
        if(type1=="boolean"|| type2=="boolean"||type1=="String"|| type2=="String") return "0";
        else return symtypeEvaluate(type1,type2);
    }
    else if(op=="%"){
        if(type1=="boolean"||type1=="String") return "0";
        else if(type2=="long"||type2=="float"||type2=="double") return "0";
        return type1;
    }
    else if(op=="=="||op=="!=") {
        if(type1=="boolean"|| type2=="boolean") return "0";
        else return "boolean";
    }
    else if(op==">="||op=="<="||op==">"||op=="<") {
        if(type1=="boolean"|| type2=="boolean"||type1=="String"|| type2=="String") return "0";
        else return "boolean";
    }
    else if(op==">>"||op=="<<") {
        if((type1=="int"||type1=="short")&&(type2=="int"||type2=="short"||type2=="long")) return "int";
        if((type1=="long")&&(type2=="int"||type2=="short"||type2=="long")) return "long";
        return "0";
    }
    else if(op=="&&"||op=="||"||op=="^"||op=="!"||op=="~") {
        if(type1=="boolean"&&type2=="boolean") return "boolean";
    }
    return "0";
}



string symAssignment(string type1, string type2)
{
    // cout<<endl<<type1<<" "<<type2<<endl;
    if(type1==type2)
    {
        return type2;
    }

    if(type2=="byte" && type1=="short") {return "short";}
    if(type2=="byte" && type1=="char") {return "char";}
    if(type2=="byte" && type1=="int"){return "int";}
    if(type2=="byte" && type1=="long"){return "long";}
    if(type2=="byte" && type1=="float"){return "float";}
    if(type2=="byte" && type1=="double"){return "double";}

    if(type2=="short" && type1=="char") {return "char";}
    if(type2=="short" && type1=="int"){return "int";}
    if(type2=="short" && type1=="long"){return "long";}
    if(type2=="short" && type1=="float"){return "float";}
    if(type2=="short" && type1=="double"){return "double";}

    if(type2=="char" && type1=="int"){return "int";}
    if(type2=="char" && type1=="long"){return "long";}
    if(type2=="char" && type1=="float"){return "float";}
    if(type2=="char" && type1=="double"){return "double";}

    if(type2=="int" && type1=="long"){return "long";}
    if(type2=="int" && type1=="float"){return "float";}
    if(type2=="int" && type1=="double"){return "double";}

    if(type2=="long" && type1=="float"){return "float";}
    if(type2=="long" && type1=="double"){return "double";}

    if(type2=="float" && type1=="double"){return "double";}

    if(type1=="String" && (type2=="byte" || type2=="short" || type2=="char" || type2=="int" || type2=="long" || type2=="float" | type2=="double"))
    {
        return "String";
    }
    return "0";
}

void symtabPrint(symtab_t *t)
{
    for (symtab_t::iterator it = t->begin(); it != t->end(); ++it)
    {
        cout << it->first << " => " << it->second->type << endl;
    }
}

// string symtabGetType(symtab_t *t, string id)
// {
//     if(t->find(id) != t->end())
//     {
//         return t->find(id)->second->type;
//     }
//     else
//     {
//         return "0";
//     }
// }
// string symtabGetArgs(symtab_t *t, string id)
// {
//     if(t->find(id) != t->end())
//     {
//         return t->find(id)->second->args;
//     }
//     else
//     {
//         return "0";
//     }
// }

void symadd(string symname, string symtype,string args, int accessspecifier) {
    // string scoped_name = fullscope + " " + symname;
	Type*type=new Type;
    type->lineno=yylineno;
    type->type=symtype;
    type->args=args;
    type->access_specifier=accessspecifier;
    type->offset=getoffset(0);
     if(symtype=="byte") type->size=1;
    if(symtype=="short") type->size=2;
    if(symtype=="int") type->size=4;
    if(symtype=="long") type->size=8;
    if(symtype=="float") type->size=4;
    if(symtype=="double") type->size=8;
    if(symtype=="boolean") type->size=1;
    if(symtype=="char") type->size=2;
    if(args=="ud") type->args=""; //for function
    else if(args=="NULL") type->args="args"; //for class
    (*symtab)[symname]=type;
}

string symtabGetType(string fullscope, string symname){
    string scope=fullscope;
    symtab_t*t=symtab_top[scope];
    while(scope!="0"){
        if(t->find(symname) != t->end()){
            return t->find(symname)->second->type;
        }
        size_t pos = scope.find_last_of("/");
		if(pos == string::npos) break;
		scope = scope.substr(0, pos);
        t=symtab_top[scope];
    }
    return "0";
}

string symtabGetArgs(string fullscope, string symname){
    string scope=fullscope;
    symtab_t*t=symtab_top[scope];
    while(scope!="0"){
        if(t->find(symname) != t->end()){
            return t->find(symname)->second->args;
        }
        size_t pos = scope.find_last_of("/");
		if(pos == string::npos) break;
		scope = scope.substr(0, pos);
        t=symtab_top[scope];
    }
    return "0";
}

string searchthis(string scope) {
    size_t pos = scope.find_last_of("/");
		// if(pos == string::npos) break;
		scope = scope.substr(0, pos);
        while(scope!="0") {
            map<string,string>::iterator it=m1.begin();
            while(it!=m1.end()){
                if(scope==it->second) return scope;
                it++;
            }
        pos = scope.find_last_of("/");
		if(pos == string::npos) break;
		scope = scope.substr(0, pos);
        }
    return "0";
}

Type* symtabGetTypep(string fullscope, string symname){
    string scope=fullscope;
    symtab_t*t=symtab_top[scope];
    while(scope!="0"){
        if(t->find(symname) != t->end()){
            return t->find(symname)->second;
        }
        size_t pos = scope.find_last_of("/");
		if(pos == string::npos) break;
		scope = scope.substr(0, pos);
        t=symtab_top[scope];
    }
    return NULL;
}