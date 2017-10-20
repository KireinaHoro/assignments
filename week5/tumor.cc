#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, perimeter = 0, area = 0;
    cin >> n;
    vector<vector<int> > point(n, vector<int>(n));
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            cin >> point[i][j];
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
        {
            if(point[i][j] <= 50)
                area ++;
            if((!(i && j) || !((i != n - 1) && (j != n - 1))))
            {
                if(point[i][j] <= 50)
                    perimeter ++;
            }
            else
            {
                if(point[i][j] <= 50)
                    if(point[i][j - 1] > 50 || point[i][j + 1] > 50 || point[i - 1][j] > 50 || point[i + 1][j] > 50)
                        perimeter ++;
            }
        }
    cout << area << ' ' << perimeter << endl;
    return 0;
}

