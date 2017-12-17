#include <iostream>
#include <cstdlib>

using namespace std;

const int MAXN = 100;
int A[MAXN][MAXN], B[MAXN][MAXN], ans[MAXN][MAXN], n, m, k;

int main()
{
    int t;
    cin >> t;
    while(t --)
    {
        cin >> n >> m >> k;
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m; j ++)
                cin >> *(*(A + i) + j);
        for (int i = 0; i < m; i ++)
            for (int j = 0; j < k; j ++)
                cin >> *(*(B + j) + i);
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < k; j ++)
                for (int p = 0; p < m; p ++)
                    *(*(ans + i) + j) += *(*(A + i) + p) * *(*(B + j) + p);
        for (int i = 0; i < n; i ++)
        {
            cout << **(ans + i);
            for (int j = 1; j < k; j ++)
                cout << ' ' << *(*(ans + i) + j);
            cout << endl;
        }
        memset(ans, 0, sizeof(ans));
    }
    return 0;
}

