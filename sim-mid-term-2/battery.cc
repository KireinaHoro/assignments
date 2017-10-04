#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        int sum = 0, max = 0;
        if(n == 2)
        {
            int a, b;
            cin >> a >> b;
            cout << fixed << setprecision(1) << (double)min(a, b) << endl;
            continue;
        }
        while(n --)
        {
            int temp;
            cin >> temp;
            if(max < temp) max = temp;
            sum += temp;
        }
        if(sum < 2 * max)
            cout << fixed << setprecision(1) << (double)(sum - max) << endl;
        else
            cout << fixed << setprecision(1) << (double)sum / 2 << endl;
    }
    return 0;
}

