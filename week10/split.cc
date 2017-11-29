#include <iostream>
#include <cmath>

using namespace std;

int solve(int i, int n)
{
    int ret = 1;
    for(; i <= sqrt(n); i ++)
        if(n % i == 0)
            ret += solve(i, n / i);
    return ret;
}

int main()
{
    int n;
    cin >> n;
    while(n --)
    {
        int a;
        cin >> a;
        cout << solve(2, a) << endl;
    }
    return 0;
}

