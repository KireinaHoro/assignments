#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n --)
    {
        int a, ans = 0;
        cin >> a;
        while(a)
        {
            if(a % 2)
                ans ++;
            a >>= 1;
        }
        cout << ans << endl;
    }
    return 0;
}

