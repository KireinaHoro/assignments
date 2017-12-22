#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int ans = (2 * n) % k ? 2 * n / k + 1 : 2 * n / k
    cout << (ans < 2 ? 2 : ans) << endl;
    return 0;
}

