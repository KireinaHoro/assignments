#include <iostream>

using namespace std;

const int MAXN = 55;
int map[MAXN][MAXN], m, n;

void dfs(int x, int y)
{
    if(map[x][y] == 1 || map[x][y] == -1)
        return;
    map[x][y] = 2;
    if(map[x][y + 1] != 2)
        dfs(x, y + 1);
    if(map[x + 1][y] != 2)
        dfs(x + 1, y);
    if(x > 0)
        if(map[x - 1][y] != 2)
            dfs(x - 1, y);
    if(y > 0)
        if(map[x][y - 1] != 2)
            dfs(x, y - 1);
}

int main()
{
    for(int i = 0; i < MAXN; i ++)
        for(int j = 0; j < MAXN; j ++)
            map[i][j] = -1;
    cin >> m >> n;
    int source_x, source_y, target_x, target_y;
    for(int i = 0; i < m; i ++)
        for(int j = 0; j < n; j ++)
        {
            cin >> map[i][j];
            switch(map[i][j])
            {
                case 2:
                    source_x = i;
                    source_y = j;
                    break;
                case 3:
                    target_x = i;
                    target_y = j;
                    break;
            }
        }
    dfs(source_x, source_y);
    bool ans = map[target_x + 1][target_y] == 2 || map[target_x][target_y + 1] == 2;
    if(target_x > 0)
        ans |= map[target_x - 1][target_y] == 2;
    if(target_y > 0)
        ans |= map[target_x][target_y - 1] == 2;
    cout << (ans ? "Yes" : "No") << endl;
    return 0;
}

