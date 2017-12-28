#include <iostream>

using namespace std;

const int MAXN = 102;
int input[MAXN][MAXN], f[MAXN][MAXN], n;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= i; j ++)
            cin >> input[i][j];
    f[1][1] = input[1][1];
    for (int i = 2; i <= n; i ++)
        for (int j = 1; j <= i; j ++)
        {
            if (j == 1)
                f[i][j] = f[i - 1][j] + input[i][j];
            else if (j == i)
                f[i][j] = f[i - 1][j - 1] + input[i][j];
            else
                f[i][j] = max(f[i - 1][j - 1], f[i - 1][j]) + input[i][j];
        }
    int ans = 0;
    for (int i = 1; i <= n; i ++)
        ans = max(ans, f[n][i]);
    cout << ans << endl;
    return 0;
}

