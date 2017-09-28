#include <iostream>
#include <iomanip>

using namespace std;

int fac(int n)
{
    if(!n) return 1;
    return n * fac(n - 1);
}

int main()
{
    int n;
    cin >> n;
    double ans = 0;
    for(int i = 0; i <= n; i ++)
        ans += 1 / (double)fac(i);
    cout << setprecision(7) << ans << endl;
    return 0;
}

