#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdio>

#define EPS 1e-6

using namespace std;

int main()
{
    int a;
    while(cin >> a)
    {
        int times = 1;
        double x = a;
        while(abs(pow(x, 2) - a) > EPS)
        {
            x = x - (pow(x, 2) - a) / (2 * x);
            times++;
        }
        cout << times << ' ' << fixed << setprecision(2) << x << endl;
    }
    return 0;
}

