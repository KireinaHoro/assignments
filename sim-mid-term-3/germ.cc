#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int mat[9][9], new_mat[9][9];
    memset(mat, 0, sizeof(mat)); 
    int m, n;
    cin >> m >> n;
    mat[4][4] = m;
    while(n --)
    {
        memcpy(new_mat, mat, sizeof(mat));
        for(int i = 0; i < 9; i ++)
            for(int j = 0; j < 9; j ++)
            {
                new_mat[i][j] += mat[i][j];
                new_mat[i - 1][j] += mat[i][j];
                new_mat[i + 1][j] += mat[i][j];
                new_mat[i][j - 1] += mat[i][j];
                new_mat[i][j + 1] += mat[i][j];
                new_mat[i + 1][j + 1] += mat[i][j];
                new_mat[i - 1][j - 1] += mat[i][j];
                new_mat[i - 1][j + 1] += mat[i][j];
                new_mat[i + 1][j - 1] += mat[i][j];
            }
        memcpy(mat, new_mat, sizeof(mat));
    }
    for(int i = 0; i < 9; i ++)
    {
        cout << mat[i][0];
        for(int j = 1; j < 9; j ++)
            cout << ' ' << mat[i][j];
        cout << endl;
    }
    return 0;
}

