#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const char *month_haab[] =
{
    "pop", "no", "zip", "zotz", "tzec", "xul",
    "yoxkin", "mol", "chen", "yax", "zac", "ceh",
    "mac", "kankin", "muan", "pax", "koyab", "cumhu",
    "uayet"
};

const char *day_tzolkin[] =
{
    "imix", "ik", "akbal", "kan", "chicchan", "cimi",
    "manik", "lamat", "muluk", "ok", "chuen", "eb",
    "ben", "ix", "mem", "cib", "caban", "eznab",
    "canac", "ahau"
};

int convert_month_haab(char *month)
{
    int ret = 0;
    while(strcmp(month_haab[ret], month))
        ret ++;
    return ret;
}

int calc_days_haab(int day, int month, int year)
{
    return day + 20 * month + 365 * year + 1;
}

int main()
{
    int n;
    cin >> n;
    cout << n << endl;
    while(n --)
    {
        int day, year;
        cin >> day;
        cin.get();
        cin.get();
        char *month = NULL;
        size_t nbytes = 0;
        getdelim(&month, &nbytes, ' ', stdin);
        month[strlen(month) - 1] = '\0';
        cin >> year;
        int days = calc_days_haab(day, convert_month_haab(month), year);
        cout << (days % 13 ? days % 13 : 13)  << ' ' << day_tzolkin[(days - 1) % 20] << ' ' << (days - 1) / 260 << endl;
    }
    return 0;
}

