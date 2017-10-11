#include <iostream>

using namespace std;

bool three(int a)
{
    return (a % 10 == 3 || (a / 10) % 10 == 3 || (a / 100) % 100 == 3 || a % 3 == 0);
}

int main()
{
    int a;
    while(cin >> a)
        cout << (three(a) ? "TRUE" : "FALSE") << endl;
    return 0;
}

