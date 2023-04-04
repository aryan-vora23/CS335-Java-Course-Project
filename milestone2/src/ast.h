#include<bits/stdc++.h>
// #include "type.h"
using namespace std;

struct astnode {
    string lexeme="lexeme";
    string token="token";
    vector<astnode*> children;
    // Type*type=NULL;
    string type="ud";  //Type of that node, return type for function
    string name; //function name if it is function
    string value="ud"; //non terminals, synthesized from terminals, int,float (args) for function
    string tac_val;//tac value
    string code;//redundant
    int length=1; //array length
    int space=1; 
    // vector<string>tuples;//entries of an array
    int dims=0;
    int flag=1;//1->evaluate expr, 0-> terminal only, 3->classinstancecreation //4->array //5->function44
    int access_specifier=1; //1-> public, 0-> private
};
