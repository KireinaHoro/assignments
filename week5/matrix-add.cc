#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int> > matrix;

int main()
{
    int n;
    cin >> n;
    matrix a(n), b(n);
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
        {
            int temp;
            cin >> temp;
            a[i].push_back(temp);
        }
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
        {
            int temp;
            cin >> temp;
            b[i].push_back(temp);
        }
    for(int i = 0; i < n; i ++)
    {
        cout << a[i][0] + b[i][0];
        for(int j = 1; j < n; j ++)
            cout << ' ' << a[i][j] + b[i][j];
        cout << endl;
    }
    return 0;
}

