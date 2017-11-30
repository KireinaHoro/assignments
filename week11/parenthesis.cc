#include <iostream>
#include <cstring>

using namespace std;

char buf[120];
char a, b;

void solve()
{
    char *s = buf;
    if (!*s)
        return;
    if (*s == ' ')
        return;
    char *e = s + 1;
    while (*e == ' ')
        e ++;
    while (*e == a)
    {
        s = e ++;
        while (*e == ' ')
            e ++;
    }
    if (*e == b)
    {
        cout << s - buf << ' ' << e - buf << endl;
        *s = ' ';
        *e = ' ';
    }
    solve();
}

int main()
{
    cin.getline(buf, 120);
    a = buf[0];
    b = buf[strlen(buf) - 1];
    solve();
    return 0;
}

