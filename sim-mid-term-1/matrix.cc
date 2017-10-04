#include <iostream>
#include <limits>

using namespace std;

const int maxm = 100, maxn = 100;

int base[maxm][maxn], predicate[maxm][maxn];

int main()
{
    int m, n, r, s;
    int ans = numeric_limits<int>::max(), ans_p = 0, ans_q = 0;
    cin >> m >> n;
    for(int i = 0; i < m; i ++)
        for(int j = 0; j < n; j ++)
            cin >> base[i][j];
    cin >> r >> s;
    for(int i = 0; i < r; i ++)
        for(int j = 0; j < s; j ++)
            cin >> predicate[i][j];
    for(int p = 0; p <= m - r; p ++)
        for(int q = 0; q <= n - s; q ++)
        {
            int temp = 0;
            for(int u = 0; u < r; u ++)
                for(int v = 0; v < s; v ++)
                    temp += abs(predicate[u][v] - base[u + p][v + q]);
            if(temp < ans)
            {
                ans = temp;
                ans_p = p;
                ans_q = q;
            }
//            cout << "temp: " << temp << endl;
        }
    for(int i = 0; i < r; i ++)
    {
        for(int j = 0; j < s; j ++)
            cout << base[ans_p + i][ans_q + j] << ' ';
        cout << endl;
    }

    return 0;
}

