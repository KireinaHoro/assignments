#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 100;
char board[MAXN][MAXN];
int ha, la, hb, lb;
int n;

void solve(int x, int y)
{
    if (board[x][y] != '.')
        return;
    board[x][y] = '@';
    int ans = 1;
    if (x > 0)
        solve(x - 1, y);
    if (y > 0)
        solve(x, y - 1);
    if (x < n - 1)
        solve(x + 1, y);
    if (y < n - 1)
        solve(x, y + 1);
}

int main()
{
    int t;
    cin >> t;
    while (t --)
    {
        cin >> n;
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < n; j ++)
                cin >> board[i][j];
        cin >> ha >> la >> hb >> lb;
        solve(ha, la);
        if (!(board[ha][la] == '@' && board[hb][lb] == '@'))
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
        memset(board, 0, sizeof(board));
    }
    return 0;
}

