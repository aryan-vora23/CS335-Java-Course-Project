#include<bits/stdc++.h>
using namespace std;

struct Type {
    int lineno=0;
    string type="ud";
    string value;
    int size=0;
    string args="args";
    int dims=0;
    string length;
    int flag=0; //para=1, local=0;
    int offset=0;
    int access_specifier=1; //1-> public, 0-> private
};
