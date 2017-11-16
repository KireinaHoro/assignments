#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

const int MAXN = 11;

void strrev(char *str)
{
    int len = strlen(str);
    for(int i = 0; i < (len + 1) / 2; i ++)
    {
        char temp = *(str + i);
        *(str + i) = *(str + len - 1 - i);
        *(str + len - 1 - i) = temp;
    }
}

void itoa(int num, char *buf)
{
    while(num > 0)
    {
        *(buf ++) = num % 10 + '0';
        num /= 10;
    }
    *buf = '\0';
    strrev(buf);
}

bool is_palindrome(int a)
{
    char buf[MAXN], rev[MAXN];
    itoa(a, buf);
    strcpy(rev, buf);
    strrev(rev);
    if(!strcmp(rev, buf))
        return true;
    else
        return false;
}

int main()
{
    int n;
    cin >> n;
    cout << (is_palindrome(n) ? "yes" : "no") << endl;
    return 0;
}

