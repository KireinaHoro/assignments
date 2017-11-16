#include <iostream>

using namespace std;

void calc(int a)
{
    if(a == 1)
    {
        cout << "End" << endl;
        return;
    }
    if(a % 2)
    {
        cout << a << "*3+1=" << a * 3 + 1 << endl;
        calc(a * 3 + 1);
    }
    else
    {
        cout << a << "/2=" << a / 2 << endl;
        calc(a / 2);
    }
}

int main()
{
    int n;
    cin >> n;
    calc(n);
    return 0;
}

