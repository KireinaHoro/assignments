#include <iostream>
#include <string>

using namespace std;

const string days[] =
{
    "Sun.",
    "Mon.",
    "Tue.",
    "Wed.",
    "Thu.",
    "Fri.",
    "Sat."
};

int calc_days(int y, int m, int d)
{
    int ret = 0;
    for(int i = 1; i <= y - 1; i ++)
    {
        ret += 366;
        if(i % 4 || (!(i % 100) && i % 400))
            ret --;
    }
    for(int i = 1; i <= m - 1; i ++)
        switch(i)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                ret += 31;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                ret += 30;
                break;
            case 2:
                ret += 29;
                if(y % 4 || (!(y % 100) && y % 400))
                    ret --;
                break;
        }
    ret += d;
    return ret;
}

int main()
{
    int n;
    cin >> n;
    while(n --)
    {
        int y, m, d;
        cin >> y >> m >> d;
        cout << calc_days(y, m, d) << endl;
        cout << days[calc_days(y, m, d) % 7] << endl;
    }
    return 0;
}

