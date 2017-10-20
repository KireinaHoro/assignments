#include <iostream>

using namespace std;

int main()
{
    int h, u, d, ans = 1;
    cin >> h >> u >> d;
    while(u + (ans - 1) * (u - d) < h)
        ans ++;
    cout << ans << endl;
    return 0;
}

