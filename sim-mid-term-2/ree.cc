#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    double ans = 0;
    cin >> n;
    while(n --)
    {
        char s;
        int w, h, a;
        cin >> s >> w >> h >> a;
        if(s == 'F')
            ans += 655 + 9.6 * w + 1.7 * h - 4.7 * a;
        else
            ans += 66 + 13.7 * w + 5.0 * h - 6.8 * a;
    }
    cout << fixed << setprecision(1) << ans << endl;
    return 0;
}

