#include <iostream>
#include <string>
#include <iomanip>
#include <cassert>
#include <stdexcept>

using namespace std;

double calc()
{
    string s;
    cin >> s;
    double ans = 0;
    ans = atof(s.c_str());
    assert(s.size() > 0);
    if (!isdigit(s[0]))
    {
        switch (s[0])
        {
            case '+':
                ans = calc() + calc();
                break;
            case '-':
                ans = calc() - calc();
                break;
            case '*':
                ans = calc() * calc();
                break;
            case '/':
                ans = calc() / calc();
                break;
        }
    }
    return ans;
}

int main()
{
    cout << fixed << setprecision(6) << calc() << endl;
    return 0;
}

