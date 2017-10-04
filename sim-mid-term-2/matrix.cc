#include <iostream>

using namespace std;

const int maxn = 100;

int n, m, a[maxn], dp[maxn][maxn];

int main()
{
    cin >> n >> m;
    long long int ans = 0;
    for(int line = 0; line < n; line ++)
    {
        for(int i = 1; i <= m; i ++)
        {
            cin >> a[i];
            dp[i][i] = m * a[i];
        }
        for(int l = 2; l <= m; l ++)
            for(int i = 1; i <= m - 1; i ++)
            {
                int j = i + l - 1;
                dp[i][j] = max(dp[i + 1][j] + a[i] * (m - l + 1), dp[i][j - 1] + a[j] * (m - l + 1));
            }
        ans += dp[1][m];
    }
    cout << ans << endl;
    return 0;
}

