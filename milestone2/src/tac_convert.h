#include <bits/stdc++.h>
using namespace std;

string regs[] = {"eax", "ebx", "ecx", "edx", "esi", "edi", "ebp", "esp"};

string getReg(string var_name)
{
    return "r" + var_name;
}

string convert_tac_to_x86(string tac)
{
    string op1, op2, arg1, arg2, res;
    stringstream ss(tac);
    ss >> res>> op1 >> arg1 >> op2 >> arg2;
    if (op1 == "=")
    {
        if (arg1[0] == 't')
        {
            return "mov " + getReg(res) + ", " + getReg(arg1) + "\n";
        }
        else
        {
            return "mov " + getReg(res) + ", " + arg1 + "\n";
        }
    }
    else if (op1 == "+")
    {
        if (arg1[0] == 't')
        {
            return "add " + getReg(res) + ", " + getReg(arg1) + "\n";
        }
        else
        {
            return "add " + getReg(res) + ", " + arg1 + "\n";
        }
    }
    else if (op1 == "-")
    {
        if (arg1[0] == 't')
        {
            return "sub " + getReg(res) + ", " + getReg(arg1) + "\n";
        }
        else
        {
            return "sub " + getReg(res) + ", " + arg1 + "\n";
        }
    }
    else if (op1 == "*")
    {
        if (arg1[0] == 't')
        {
            return "mul " + getReg(res) + ", " + getReg(arg1) + "\n";
        }
        else
        {
            return "mul " + getReg(res) + ", " + arg1 + "\n";
        }
    }
    else if (op1 == "/")
    {
        if (arg1[0] == 't')
        {
            return "div " + getReg(res) + ", " + getReg(arg1) + "\n";
        }
        else
        {
            return "div " + getReg(res) + ", " + arg1 + "\n";
        }
    }
    else if (op1 == "goto")
    {
        return "jmp " + arg1 + "\n";
    }
    else if (op1 == "if")
    {
        if (arg1[0] == 't')
        {
            return "cmp " + getReg(arg1) + ", " + getReg(arg2) + "\n";
        }
    }
    return "";
}