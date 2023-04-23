#include <bits/stdc++.h>
#include<ctype.h>
using namespace std;

string regs[] = {"eax", "ebx", "ecx", "edx", "esi", "edi", "ebp", "esp"};

vector<string> buffer_lines;
map<string, int> stack_var_map;
// int reg_counter_para=0;
string getvar_stack(string var_name)
{
    // if((var_name[0]=='-')||(isdigit(var_name[0]))){
    //     return "$" + var_name;
    // }
    for(auto it = stack_var_map.begin();it!= stack_var_map.end();++it){
        if(it->first==var_name){
            return to_string(it->second)+"("+"%rbp"+")";
        }
    }
    // stack_var_map[(reg_counter_para++)%8]=var_name;
    return "";
}

map<int, string> reg_var_map;
int reg_counter=0;
string getReg(string var_name)
{
    if((var_name[0]=='-')||(isdigit(var_name[0]))){
        return "$" + var_name;
    }
    for(auto it = reg_var_map.begin();it!= reg_var_map.end();++it){
        if(it->second==var_name){
            return "%r" + to_string(it->first);
        }
    }
    // string old=getvar_stack(reg_var_map[(reg_counter+1)%8+8]);
    // if(old!=""){
    //     buffer_lines.push_back("movq\t%r"+to_string(reg_counter+1)+", "+old+"\n");
    // }
    if(var_name[0]=='t'){
        reg_var_map[(reg_counter++)%8+8]=var_name;
        return "%r" + to_string((reg_counter-1)%8+8);
    }
    else{
        string x = getvar_stack(var_name);
        reg_var_map[(reg_counter++)%8+8]=var_name;
        string s = "movq\t"+x+", "+"%r" + to_string((reg_counter-1)%8+8)+"\n";
        buffer_lines.push_back(s);
        return "%r" + to_string((reg_counter-1)%8+8);
    }
}

// string getReg(string var_name)
// {
//     return "r" + var_name;
// }

string convert_tac_to_x86(string tac)
{
    string op1, op2, arg1, arg2, res;
    stringstream ss(tac);
    ss >> res>> op1 >> arg1 >> op2 >> arg2;
    // cout<<"res= "<<res<<" op1= "<<op1<<" arg1= "<<arg1<<" op2= "<<op2<<" arg2= "<<arg2<<'\n';
    if(res=="define") {
        string s=op1+"\n";
        buffer_lines.push_back(s);
    }
    else if(res=="push" && op1=="BP") return res+"\t"+"%rbp"+"\n";
    else if(res=="SP" && op1=="=" && arg1=="SP" && op2=="+"){
        string s;
        s = "addq\t$"+to_string(2*stoi(arg2))+ ", %rsp\n";
        buffer_lines.push_back(s);
    }
    else if(res=="SP" && op1=="=" && arg1=="SP" && op2=="-"){
        string s;
        s = "subq\t$"+ to_string(2*stoi(arg2))+ ", %rsp\n";
        buffer_lines.push_back(s);
    }
    else if(res=="BP" && op1=="=" && arg1=="SP") {
        string s="movq";
        s=s+"\t"+"%rsp, "+"%rbp"+"\n";
        buffer_lines.push_back(s);
    }
    else if(res!="args" && arg1=="BP" && op2=="+") {
        string s="movq";
        int offset=8*(stoi(arg2)/4);
        stack_var_map[res]=offset+8;
        // s=s+"\t"+to_string(offset)+"(%rbp), "+getReg(res)+"\n";
        // buffer_lines.push_back(s);
    }
    else if(res!="args" && arg1=="BP" && op2=="-") {
        string s="movq";
        int offset=8*(stoi(arg2)/4);
        // s=s+"\t-"+to_string(offset)+"(%rbp), "+getReg(res)+"\n";
        stack_var_map[res]=-offset-8;
        // buffer_lines.push_back(s);
    }
    else if(res=="rax") {
        string s="movq\t";
        s=s+getReg(arg1)+", %rax\n";
        buffer_lines.push_back(s);
    }
    else if(res=="Pop"&& op1=="BP_old") {
        string s="movq";
        s=s+"\t"+"%rbp, "+"%rsp"+"\n";
        buffer_lines.push_back(s);
    }
    else if(res=="BP" && op1=="="&& arg1=="BP_old") {
        string s="popq";
        s=s+"\t"+"%rbp"+"\n";
        buffer_lines.push_back(s);
    }
    else if(arg1=="call") {
        reg_var_map.clear();
        string s="call";
        s=s+"\t"+op2+"\n";
        s=s+"addq\t$"+to_string(8*stoi(arg2))+", %rsp\n";
        s=s+"movq\t%rax"+", "+getReg(res)+"\n";
        s=s+"movq\t%rax"+", "+getvar_stack(res)+"\n";
        buffer_lines.push_back(s);
        reg_var_map.clear();
    }
    else if(res=="call") {
        string s="call";
        s=s+"\t"+op1+"\n";
        s=s+"addq\t$"+to_string(8*stoi(arg1))+", %rsp\n";
        buffer_lines.push_back(s);
    }
    else if(res=="return") buffer_lines.push_back("ret\n");
    else if(res=="endfunc"){
        reg_var_map.clear();
        // stack_var_map.clear();
    }
    else if(res=="push"&&op1!="obj_ref"&&op1!="pc") {
        string s="pushq\t";
        s=s+getvar_stack(op1)+"\n";
        buffer_lines.push_back(s);
    }
    else if(res[res.length()-1]==':') {
        buffer_lines.push_back(res+"\n");
    }
    else if(res=="goto") {
        string s="jmp";
        s=s+"\t"+op1+"\n";
        buffer_lines.push_back(s);
    }
    else if(res=="sys.print") {
        string s="pushq\t";
        s=s+getvar_stack(op1)+"\n";
        s=s+"call\tSystem.println\n";
        buffer_lines.push_back(s);
    }
//--------------------If-Else---------------------
    else if(res=="if"&& arg1=="goto") {
        string con=op1.substr(1,op1.length()-2);
        string s="cmp\t\t$";
        s=s+con[con.length()-1]+", "+getReg(con.substr(0,con.length()-2))+"\n";
        s=s+"je\t"+op2+"\n";
        buffer_lines.push_back(s);
    } 
//--------------------Relational-Operators---------------------
    else if(op1=="="&&op2=="<") {
        string s="movq\t";
        s=s+getReg(arg1)+", %rsi\n";
        s=s+"cmp\t\t"+getReg(arg2)+", %rsi\n";
        s=s+"movq\t$0, "+getReg(res)+"\n";
        s=s+"movq\t$1, %rsi\n";
        s=s+"cmovl\t%rsi, "+getReg(res)+"\n";
        buffer_lines.push_back(s);
    } 
    else if(op1=="="&&op2==">") {
        string s="movq\t";
        s=s+getReg(arg1)+", %rsi\n";
        s=s+"cmp\t\t"+getReg(arg2)+", %rsi\n";
        s=s+"movq\t$0, "+getReg(res)+"\n";
        s=s+"movq\t$1, %rsi\n";
        s=s+"cmovg\t%rsi, "+getReg(res)+"\n";
        buffer_lines.push_back(s);
    } 
    else if(op1=="="&&op2=="==") {
        string s="movq\t";
        s=s+getReg(arg1)+", %rsi\n";
        s=s+"cmp\t\t"+getReg(arg2)+", %rsi\n";
        s=s+"movq\t$0, "+getReg(res)+"\n";
        s=s+"movq\t$1, %rsi\n";
        s=s+"cmove\t%rsi, "+getReg(res)+"\n";
        buffer_lines.push_back(s);
    } 
    else if(op1=="="&&op2=="!=") {
        string s="movq\t";
        s=s+getReg(arg1)+", %rsi\n";
        s=s+"cmp\t\t"+getReg(arg2)+", %rsi\n";
        s=s+"movq\t$0, "+getReg(res)+"\n";
        s=s+"movq\t$1, %rsi\n";
        s=s+"cmovne\t%rsi, "+getReg(res)+"\n";
        buffer_lines.push_back(s);
    } 
    else if(op1=="="&&op2=="<=") {
        string s="movq\t";
        s=s+getReg(arg1)+", %rsi\n";
        s=s+"cmp\t\t"+getReg(arg2)+", %rsi\n";
        s=s+"movq\t$0, "+getReg(res)+"\n";
        s=s+"movq\t$1, %rsi\n";
        s=s+"cmovle\t%rsi, "+getReg(res)+"\n";
        buffer_lines.push_back(s);
    } 
    else if(op1=="="&&op2==">=") {
        string s="movq\t";
        s=s+getReg(arg1)+", %rsi\n";
        s=s+"cmp\t\t"+getReg(arg2)+", %rsi\n";
        s=s+"movq\t$0, "+getReg(res)+"\n";
        s=s+"movq\t$1, %rsi\n";
        s=s+"cmovge\t%rsi, "+getReg(res)+"\n";
        buffer_lines.push_back(s);
    }
//--------------------Arithmetic------------------
    else if(arg1!="BP" && arg1!="SP" && op1=="=" && op2=="+") {
        string r1=getReg(res);
        string s="movq";
        s=s+"\t"+"$0, "+r1+"\n";
        s=s+"addq\t"+getReg(arg1)+", "+r1+"\n";
        s=s+"addq\t"+getReg(arg2)+", "+r1+"\n";
        buffer_lines.push_back(s);
    }
    else if(arg1!="BP" && arg1!="SP" && op1=="=" && op2=="-") {
        string r1=getReg(res);
        string s="movq";
        s=s+"\t"+"$0, "+r1+"\n";
        s=s+"addq\t"+getReg(arg1)+", "+r1+"\n";
        s=s+"subq\t"+getReg(arg2)+", "+r1+"\n";
        buffer_lines.push_back(s);
    }
    else if(arg1!="BP" && arg1!="SP" && op1=="=" && op2=="/") {
        string s="movq";
        s=s+"\t"+getReg(arg1)+", %rax\n";
        s=s+"cltd\n";
        s=s+"idivq\t"+getReg(arg2)+"\n";
        s=s+"movq\t%rax, "+getReg(res)+"\n";
        buffer_lines.push_back(s);
    }
    else if(arg1!="BP" && arg1!="SP" && op1=="=" && op2=="%") {
        string s="movq";
        s=s+"\t"+getReg(arg1)+", %rax\n";
        s=s+"cltd\n";
        s=s+"idivq\t"+getReg(arg2)+"\n";
        s=s+"movq\t%rdx, "+getReg(res)+"\n";
        buffer_lines.push_back(s);
    }
    else if(arg1!="BP" && arg1!="SP" && op1=="=" && op2=="*") {
        string r1=getReg(res);
        string s="movq";
        s=s+"\t"+"$0, "+r1+"\n";
        s=s+"addq\t"+getReg(arg1)+", "+r1+"\n";
        s=s+"imulq\t"+getReg(arg2)+", "+r1+"\n";
        buffer_lines.push_back(s);
    }
    else if(arg1!="BP" && arg1!="SP" && op1=="=" && (op2=="|"||op2=="||")) {
        string r1=getReg(res);
        string s="movq";
        s=s+"\t"+"$0, "+r1+"\n";
        s=s+"orq \t"+getReg(arg1)+", "+r1+"\n";
        s=s+"orq \t"+getReg(arg2)+", "+r1+"\n";
        buffer_lines.push_back(s);
    }
    else if(arg1!="BP" && arg1!="SP" && op1=="=" && (op2=="&"||op2=="&&")) {
        string r1=getReg(res);
        string s="movq";
        s=s+"\t"+"$1, "+r1+"\n";
        s=s+"andq\t"+getReg(arg1)+", "+r1+"\n";
        s=s+"andq\t"+getReg(arg2)+", "+r1+"\n";
        buffer_lines.push_back(s);
    }
    else if(arg1!="BP" && arg1!="SP" && op1=="=" && op2=="^") {
        string r1=getReg(res);
        string s="movq";
        s=s+"\t"+"$0, "+r1+"\n";
        s=s+"xorq\t"+getReg(arg1)+", "+r1+"\n";
        s=s+"xorq\t"+getReg(arg2)+", "+r1+"\n";
        buffer_lines.push_back(s);
    }
    else if(arg1!="BP" && arg1!="SP" && op1=="=" && arg1=="~") {
        string r1=getReg(res);
        string s="movq";
        s=s+"\t"+"$1, "+r1+"\n";
        s=s+"xorq\t"+getReg(op2)+", "+r1+"\n";
        // s=s+"orq\t"+getReg(arg2)+", "+r1+"\n";
        buffer_lines.push_back(s);
    }
    else if(arg1!="BP" && arg1!="SP" && op1=="=" && op2=="<<") {
        cout<<"hi";
        string r1=getReg(res);
        string s="movq";
        s=s+"\t"+"$0, "+r1+"\n";
        s=s+"addq\t"+getReg(arg1)+", "+r1+"\n";
        s=s+"movq\t"+getReg(arg2)+", %rcx\n";
        s=s+"salq\t%cl, "+r1+"\n";
        buffer_lines.push_back(s);
    }
    else if(arg1!="BP" && arg1!="SP" && op1=="=" && op2==">>") {
        cout<<"hi";
        string r1=getReg(res);
        string s="movq";
        s=s+"\t"+"$0, "+r1+"\n";
        s=s+"addq\t"+getReg(arg1)+", "+r1+"\n";
        s=s+"movq\t"+getReg(arg2)+", %rcx\n";
        s=s+"sarq\t%cl, "+r1+"\n";
        buffer_lines.push_back(s);
    }
    else if(arg1!="SP"&&res!="obj_ref"&&arg1!="BP"&&(op1=="="||op1=="=int")) {
        string s="movq";
        if(arg1=="true") arg1="1";
        else if(arg1=="false") arg1="0";
        s=s+"\t"+getReg(arg1)+", "+getReg(res)+"\n";
        s=s+"movq\t"+getReg(res)+", "+getvar_stack(res)+"\n";
        buffer_lines.push_back(s);
    }

    buffer_lines.push_back("");
    int i=0,l=buffer_lines.size();
    if(l==0) return "";
    string k=buffer_lines[0];
    for(i=1;i<l;i++){
        k=k+buffer_lines[i];
    }
    buffer_lines.clear();
    return k;
}