#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 23;
char board[MAXN][MAXN];
int xs, ys;
int x0, y0;

int solve(int x, int y)
{
    if (board[x][y] != '.')
        return 0;
    board[x][y] = '@';
    int ans = 1;
    if (x > 0)
        ans += solve(x - 1, y);
    if (y > 0)
        ans += solve(x, y - 1);
    if (x < y0 - 1)
        ans += solve(x + 1, y);
    if (y < x0 - 1)
        ans += solve(x, y + 1);
    return ans;
}

int main()
{
    while (cin >> x0 >> y0, x0 || y0)
    {
        char garbage;
        cin.get(garbage);
        for (int i = 0; i < y0; i ++)
        {
            char a;
            for (int j = 0; j < x0; j ++)
            {
                cin.get(a);
                if (a == '@')
                {
                    xs = i;
                    ys = j;
                    a = '.';
                }
                board[i][j] = a;
            }
            cin.get(a);
        }
        cout << solve(xs, ys) << endl;
        memset(board, 0, sizeof(board));
    }
    return 0;
}

