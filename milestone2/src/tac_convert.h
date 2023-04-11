#include <bits/stdc++.h>
using namespace std;

string regs[] = {"eax", "ebx", "ecx", "edx", "esi", "edi", "ebp", "esp"};

string getReg(string var_name)
{
    return "r" + var_name;
}

void convert_tac_to_x86(string tac)
{
    string op, arg1, arg2, res;
    stringstream ss(tac);
    ss >> op >> arg1 >> arg2 >> res;
    if (op == "assign")
    {
        if (arg1[0] == 't')
        {
            cout << "mov " << getReg(res) << ", " << getReg(arg1) << endl;
        }
        else
        {
            cout << "mov " << getReg(res) << ", " << arg1 << endl;
        }
    }
    else if (op == "add")
    {
        if (arg1[0] == 't')
        {
            cout << "add " << getReg(res) << ", " << getReg(arg1) << endl;
        }
        else
        {
            cout << "add " << getReg(res) << ", " << arg1 << endl;
        }
    }
    else if (op == "sub")
    {
        if (arg1[0] == 't')
        {
            cout << "sub " << getReg(res) << ", " << getReg(arg1) << endl;
        }
        else
        {
            cout << "sub " << getReg(res) << ", " << arg1 << endl;
        }
    }
    else if (op == "mul")
    {
        if (arg1[0] == 't')
        {
            cout << "mul " << getReg(res) << ", " << getReg(arg1) << endl;
        }
        else
        {
            cout << "mul " << getReg(res) << ", " << arg1 << endl;
        }
    }
    else if (op == "div")
    {
        if (arg1[0] == 't')
        {
            cout << "div " << getReg(res) << ", " << getReg(arg1) << endl;
        }
        else
        {
            cout << "div " << getReg(res) << ", " << arg1 << endl;
        }
    }
    else if (op == "goto")
    {
        cout << "jmp " << arg1 << endl;
    }
    else if (op == "if")
    {
        if (arg1[0] == 't')
        {
            cout << "cmp " << getReg(arg1) << ", " << getReg(arg2) << endl;
        }
    }
}