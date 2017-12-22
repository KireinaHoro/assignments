#include <iostream>

using namespace std;

const int MAXM = 102;
const int MAXT = 1002;

int f[MAXM][MAXT];
int p[MAXM], t[MAXM];
int T, M;

int main()
{
    cin >> T >> M;
    for (int i = 1; i <= M; i ++)
        cin >> t[i] >> p[i];
    for (int j = 1; j <= T; j ++)
        f[1][j] = (t[1] <= j ? p[1] : 0);
    for (int i = 2; i <= M; i ++)
        for (int j = 1; j <= T; j ++)
            if (j >= t[i])
                f[i][j] = max(f[i - 1][j - t[i]] + p[i], f[i - 1][j]);
            else
                f[i][j] = f[i - 1][j];
    cout << f[M][T] << endl;
    return 0;
}

