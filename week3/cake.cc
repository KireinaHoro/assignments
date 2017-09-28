#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        // int will overflow under extreme circumstances
        long long r, x1, y1, x2, y2, x3, y3;
        cin >> r >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        vector<double> c(4);
        if((x1 == 0 && y1 == 0) || (x2 == 0 && y2 == 0) || (x3 == 0 && y3 == 0))
        {
            cout << "No" << endl;
            continue;
        }
        c[0] = (x1 * x2 + y1 * y2) / sqrt((x1 * x1 + y1 * y1) * (x2 * x2 + y2 * y2));
        c[1] = (x1 * x3 + y1 * y3) / sqrt((x1 * x1 + y1 * y1) * (x3 * x3 + y3 * y3));
        c[2] = (x3 * x2 + y3 * y2) / sqrt((x3 * x3 + y3 * y3) * (x2 * x2 + y2 * y2));
        c[3] = -0.5;
        sort(c.begin(), c.end());
//        cout << c[0] << ' ' << c[1] << ' ' << c[2] << ' ' << c[3] << endl;
        if(c[0] >= -0.5)
        {
            cout << "No" << endl;
            continue;
        }
        else if(find(c.begin(), c.end(), 1) != c.end())
        {
            cout << "No" << endl;
            continue;
        }
        cout << "Yes" << endl;
    }
    return 0;
}

