#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int> > matrix(n, vector<int>(n));
    pair<int, int> pos = pair<int, int>(0, 0);
    for(int i = 1; i <= n * n; i ++)
    {
        matrix[pos.first][pos.second] = i;
        if(((!(pos.second || pos.first % 2) && pos.first != n - 1)) || ((pos.second == n - 1) && ((n % 2) ? pos.first % 2 : !(pos.first % 2))))
        {
//            cout << "first: " << pos.first << endl;
            pos.first ++;
        }
        else if(((!pos.first && pos.second % 2) && pos.second != n - 1) || ((pos.first == n - 1) && ((n % 2) ? !(pos.second % 2) : (pos.second % 2))))
        {
//            cout << "second: " << pos.second << endl;
            pos.second ++;
        }
        else if((pos.first + pos.second) % 2)
        {
            pos.first --;
            pos.second ++;
        }
        else
        {
            pos.first ++;
            pos.second --;
        }
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

