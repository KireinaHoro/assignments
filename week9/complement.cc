#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    int a;
    while(cin >> a)
        cout << bitset<32>(a) << endl;
    return 0;
}

