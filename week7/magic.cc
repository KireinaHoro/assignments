#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int> > matrix(n, vector<int>(n));
    matrix[n / 2][0] = 1;
    int x = n / 2, y = 0;
    for(int i = 2; i <= n * n; i ++)
    {
        if((x % n == n - 1 && !(y % n)) || matrix[(x + 1) % n][(y - 1) % n])
        {
            y ++;
        }
        else
        {
            x ++;
            y --;
        }
        matrix[x % n][y % n] = i;
    }
    for(int i = 0; i < n; i ++)
    {
        cout << matrix[0][i];
        for(int j = 1; j < n; j ++)
            cout << ' ' << matrix[j][i];
        cout << endl;
    }
    return 0;
}

