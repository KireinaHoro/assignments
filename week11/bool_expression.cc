#include <iostream>
#include <stack>

using namespace std;

stack<bool> ans;
stack<char> oper;
char buf[100];

bool calc(bool a, bool b, char oper)
{
    switch(oper)
    {
        case '&':
            return a && b;
        case '|':
            return a || b;
    }
    return false;
}

int pred(char a)
{
    switch(a)
    {
        case '|':
            return 1;
        case '&':
            return 2;
        case '!':
            return 3;
        default:
            return 0;
    }
}

void one_calc()
{
    if (oper.top() != '!')
    {
        bool a = ans.top();
        ans.pop();
        bool b = ans.top();
        ans.pop();
        ans.push(calc(a, b, oper.top()));
    }
    else
    {
        int a = ans.top();
        ans.pop();
        ans.push(!a);
    }
    oper.pop();
}


void calc()
{
    char *ptr = buf;
    while (*ptr == ' ')
        ptr ++;
    if (!*ptr)
    {
        while (!oper.empty())
            one_calc();
        return;
    }
    switch (*ptr)
    {
        case 'V':
            ans.push(true);
            break;
        case 'F':
            ans.push(false);
            break;
        case '(':
            oper.push('(');
            break;
        case ')':
            while (oper.top() != '(')
                one_calc();
            oper.pop();         // pop the '('
            break;
        default:
            while(!oper.empty() && pred(oper.top()) > pred(*ptr))
                one_calc();
            oper.push(*ptr);
            break;
    }
    *ptr = ' ';
    calc();
}

int main()
{
    while (cin.getline(buf, 100))
    {
        calc();
        cout << (ans.top() ? 'V' : 'F') << endl;
        ans.pop();
    }
    return 0;
}

