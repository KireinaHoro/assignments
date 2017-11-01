#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int year, month;
    cin >> year >> month;
    int d = 1;
    int m = month;
    int y = year;
    int w = (d += m < 3 ? y-- : y - 2, 23*m/9 + d + 4 + y/4- y/100 + y/400)%7; 
    if(w < 0)
        w += 7;
    cout << " Sun Mon Tue Wed Thu Fri Sat" << endl;
    for(int i = 0; i < w; i ++)
        cout << setfill(' ') << setw(4) << ' ';
    int days, cur_day = 1;
    switch(month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            days = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            days = 30;
            break;
        case 2:
            if(year % 4 || year % 400)
                days = 28;
            else
                days = 29;
    }
    while(cur_day <= days)
    {
        cout << setfill(' ') << setw(4) << cur_day;
        if(!((cur_day + w) % 7))
            cout << setfill(' ') << setw(4) << endl;
        cur_day ++;
    }
    cout << endl;
    return 0;
}

