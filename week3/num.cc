#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int func(int a)
{
    return ((a % 10) - (a / 1000) - ((a / 100) % 10) - ((a / 10) % 10)) > 0;
}

int main()
{
    int n, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        int temp;
        cin >> temp;
        ans += func(temp);
//        cout << "func(" << temp << ") = " << func(temp) << endl;
    }
    cout << ans << endl;
    return 0;
}

    
