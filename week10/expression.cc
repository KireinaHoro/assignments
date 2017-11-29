#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int calc(int a, int b, char oper)
{
    switch(oper)
    {
        case '+':
            return a + b;
        case '-':
            return b - a;
        case '*':
            return a * b;
        case '/':
            return b / a;
    }
    return 0;
}

int pred(char c)
{
    switch(c)
    {
        case '-':
        case '+':
            return 1;
        case '*':
        case '/':
            return 2;
        case 'n':
        case 'p':
            return 3;
        default:
            return 0;
    }
}

int solve(string a)
{
    istringstream is(a);
    stack<char> oper;
    stack<int> output;
    int num;
    char op, c;
    bool first = true;
    while(is.get(c))
    {
        op = '#';
        if(isdigit(c))
        {
            is.unget();
            is >> num;
        }
        else
            op = c;
        char temp;
        if(first)
        {
            if(op == '-')
                op = 'n';
            if(op == '+')
                op = 'p';
            first = false;
        }
        //cout << op << endl;
        switch(op)
        {
            case '#':
                output.push(num);
                continue;
            case '(':
                //cout << "here" << endl;
                oper.push('(');
                temp = is.peek();
                if(temp == '-')
                {
                    // ====== HERE ======
                    is.get();
                    oper.push('n');
                    //cout << "hit" << endl;
                }
                if(temp == '+')
                {
                    // ====== HERE ======
                    is.get();
                    oper.push('p');
                    //cout << "hit" << endl;
                }
                continue;
            case ')':
                while(oper.top() != '(')
                {
//                    output.push(oper.top());
                    if(oper.top() != 'n' && oper.top() != 'p')
                    {
                        int a = output.top();
                        output.pop();
                        int b = output.top();
                        output.pop();
                        output.push(calc(a, b, oper.top()));
                    }
                    else
                    {
                        int a = output.top();
                        output.pop();
                        if(oper.top() == 'n')
                            output.push(-a);
                        else
                            output.push(a);
                    }
                    oper.pop();
                }
                oper.pop();
                continue;
            default:
                while(!oper.empty() && pred(oper.top()) >= pred(op))
                {
                    if(oper.top() != 'n' && oper.top() != 'p')
                    {
                        int a = output.top();
                        output.pop();
                        int b = output.top();
                        output.pop();
                        output.push(calc(a, b, oper.top()));
                    }
                    else
                    {
                        int a = output.top();
                        output.pop();
                        if(oper.top() == 'n')
                            output.push(-a);
                        else
                            output.push(a);
                    }
                    oper.pop();
                }
                oper.push(op);
                continue;
        }
        // =====
        /*
        stack<double> operand;
        for(stack<char*>::iterator it = output.begin(); it != output.end(); it ++)
            if(isoperand(*it))
                operand.push(atof(*it));
            else
            {
                double a = operand.top();
                operand.pop();
                double b = operand.top();
                operand.pop();
                switch(
        */
    }

    while(!oper.empty())
    {
        if(oper.top() != 'n' && oper.top() != 'p')
        {
            int a = output.top();
            output.pop();
            int b = output.top();
            output.pop();
            output.push(calc(a, b, oper.top()));
        }
        else
        {
            int a = output.top();
            output.pop();
            if(oper.top() == 'n')
                output.push(-a);
            else
                output.push(a);
        }
        oper.pop();
    }

    //cout << output.size() << endl;
    return output.top();
}

int main()
{
    string a;
    while(getline(cin, a))
    {
        //cout << a << endl;
        cout << int(solve(a)) << endl;
    }
    return 0;
}

