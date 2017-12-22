#include <iostream>

using namespace std;

const int MAXN = 102;
int f[MAXN][MAXN], m, n, ans;

int main()
{
    cin >> m >> n;
    for (int i = 0; i < m; i ++)
    {
        int zeroCount = 0, x = 0;
        for (int j = 0; j < n; j ++)
        {
            cin >> x;
            if (!x)
            {
                zeroCount ++;
                f[i][j] = zeroCount;
            }
            else
                zeroCount = 0;
        }
    }
    for (int i = 0; i < m; i ++)
    {
        for (int j = 0; j < n; j ++)
        {
            if (!f[i][j])
                continue;
            int p = i, q = i;
            while ((p > 0 && f[p][j]) && f[p - 1][j] >= f[i][j])
                p --;
            while ((q < m - 1 && f[q][j]) && f[q + 1][j] >= f[i][j])
                q ++;
            ans = max(ans, (q - p + 1) * f[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}

