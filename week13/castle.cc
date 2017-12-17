#include <iostream>

using namespace std;

const int direction[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
const int MAXN = 51;

int row, col, rooms = 0, maxArea = 0, area;

int wall[MAXN][MAXN];
bool v[MAXN][MAXN];

void dfs(int i, int j)
{
    area ++;
    v[i][j] = true;
    for (int t = 0; t < 4; t ++)
        if (!v[i + direction[t][0]][j + direction[t][1]] && !(wall[i][j] & (1 << t)))
            dfs(i + direction[t][0], j + direction[t][1]);
}

int main()
{
    cin >> row >> col;
    for (int i = 0; i < row; i ++)
        for (int j = 0; j < col; j ++)
            cin >> wall[i][j];
    for (int i = 0; i < row; i ++)
        for (int j = 0; j < col; j ++)
            if (!v[i][j])
            {
                rooms ++;
                area = 0;
                dfs(i, j);
                if (area > maxArea)
                    maxArea = area;
            }
    cout << rooms << endl << maxArea << endl;
    return 0;
}

