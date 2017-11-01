#include <iostream>
#include <vector>

using namespace std;

int take(bool turn, int _times, vector<vector<int> >& mat)
{
    int n = mat.size(), times;
    if(turn)
        times = _times;
    else
        times = n * n - _times - 1;
    int t = 0, ret;
    while(true)
    {
        if(times - (n - 1 - t * 2) * 4 < 0)
            break;
        else if(times - (n - 1 - t * 2) * 4 == 0)
        {
            times = 0;
            t ++;
            break;
        }
        times -= (n - 1 - t * 2) * 4;
        t ++;
    }
    int single = n - 1 - t * 2;
//    cout << times << ' ' << single << endl;
    if(!single)
        return mat[n / 2][n / 2];
    switch(times / single)
    {
        case 0:
            ret = mat[t + times % single][t];
            break;
        case 1:
            ret = mat[n - 1 - t][t + times % single];
            break;
        case 2:
            ret = mat[n - 1 - t - times % single][n - 1 - t];
            break;
        case 3:
            ret = mat[t][n - 1 - t - times % single];
            break;
    }
    return ret;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int> > matrix(n, vector<int>(n));
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            cin >> matrix[j][i];
    if(n == 1)
    {
        cout << matrix[0][0] << endl;
        return 0;
    }
    cout << take(true, 0, matrix) << ' ' << take(false, 0, matrix);
    for(int i = 1; i < n * n / 2; i ++)
        cout << ' ' << take(true, i, matrix) << ' ' << take(false, i, matrix);
    if(n % 2)
        cout << ' ' << take(true, n * n / 2, matrix);
    cout << endl;
//    cout << take(false, 0, matrix) << endl;
    return 0;
}

