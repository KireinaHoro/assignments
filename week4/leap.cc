#include <iostream>

using namespace std;

int main()
{
    int a;
    cin >> a;
    cout << (a % 4 || (!(a % 100) && (a % 400)) ? 'N' : 'Y') << endl;
    return 0;
}

