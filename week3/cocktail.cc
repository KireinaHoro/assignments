#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, sa, se;
    cin >> n;
    cin >> sa >> se;
    double s = (double)se / sa;
    for(int i = 0; i < n - 1; i ++)
    {
        int a, e;
        cin >> a >> e;
//        cout << (double)e / a - s << endl;
        if(abs((double)e / a - s) <= 0.05)
            cout << "same" << endl;
        else if((double)e / a < s)
            cout << "worse" << endl;
        else
            cout << "better" << endl;
    }
    return 0;
}

