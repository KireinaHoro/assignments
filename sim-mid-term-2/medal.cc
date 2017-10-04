#include <iostream>

using namespace std;

int main()
{
    int n, gold = 0, silver = 0, bronze = 0;
    cin >> n;
    while(n --)
    {
        int a, b, c;
        cin >> a >> b >> c;
        gold += a;
        silver += b;
        bronze += c;
    }
    cout << gold << ' ' << silver << ' ' << bronze << ' ' << gold + silver + bronze << endl;
    return 0;
}

