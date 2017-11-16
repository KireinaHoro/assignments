#include <iostream>

using namespace std;

bool take(int a, int b)
{
    if(a < b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
    if(!b)
        return false;
    if(a / b >= 2)
        return true;
    return !take(a - b, b);
}

int main()
{
    int a, b;
    while(cin >> a >> b && (a || b))
        cout << (take(a, b) ? "win" : "lose") << endl;
    return 0;
}

