#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if (a < b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
    if (b == 1)
        return 1;
    if (!b)
        return a;
    return gcd(a - b, b);
}

int main()
{
    int n;
    cin >> n;
    while (n --)
    {
        int a, b;
        cin >> a >> b;
        cout << gcd(a, b) << endl;
    }
    return 0;
}

