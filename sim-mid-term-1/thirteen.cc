#include <iostream>
#include <vector>

using namespace std;

class Date
{
    public:
        int year, month, day, week;
        void inc();
        Date(int y, int m, int d) : year(y), month(m), day(d) { week = -1; }
        Date(int y, int m, int d, int w) : year(y), month(m), day(d), week(w) {}
        bool operator!=(Date p);
};

bool Date::operator!=(Date p)
{
    return !((year == p.year) && (month == p.month) && (day == p.day));
}

void Date::inc()
{
    int day_limit;
    switch(month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            day_limit = 31;
            break;
        case 2:
            if(year % 4 || (!(year % 100) && (year % 400)))
                day_limit = 28;
            else
                day_limit = 29;
            break;
        default:
            day_limit = 30;
    }
    if(day == day_limit)
    {
        if(month == 12)
        {
            year ++;
            month = 1;
            day = 1;
        }
        else
        {
            month ++;
            day = 1;
        }
    }
    else
        day ++;
    if(week == 6) week = 0;
    else week ++;
}

int main()
{
    int n;
    cin >> n;
    Date a(1900, 1, 1, 1), end(1900 + n, 1, 1);
    vector<int> ans(7);
    for(; a != end; a.inc())
        if(a.day == 13) ans[a.week] ++;
    cout << ans[6] << ' ' << ans[0] << ' ' << ans[1] << ' '
        << ans[2] << ' ' << ans[3] << ' ' << ans[4] << ' '
        << ans[5] << endl;
    return 0;
}

