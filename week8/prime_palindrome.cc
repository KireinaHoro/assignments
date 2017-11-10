#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

const int MAXN = 10010;
bool prime[MAXN];

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
    char buf[6], rev[6];
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
    for(int i = 1; i <= n; i ++)
        prime[i] = true;
    prime[1] = false;
    for(int i = 2; i <= n; i ++)
        if(prime[i])
            for(int j = 2; j * i <= n; j ++)
                prime[j * i] = false;
    int ans = 0;
    for(int i = 11; i <= n; i ++)
        if(prime[i] && is_palindrome(i))
            ans ++;
    cout << ans << endl;
    return 0;
}

