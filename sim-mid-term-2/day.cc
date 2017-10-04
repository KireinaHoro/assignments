#include <iostream>

using namespace std;

const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
    int year, month, day, ans = 0;
    bool leap = true;
    cin >> year >> month >> day;
    if(year % 4 || (!(year % 100) && year % 400)) leap = false;
    for(int i = 0; i < month - 1; i ++)
        ans += days[i];
    ans += day;
    if(leap && month > 2) ans ++;
    cout << ans << endl;
    return 0;
}

