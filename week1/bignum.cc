#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

#define MAXN 9999
#define MAXSIZE 100
#define DLEN 4

class BigNum
{
    private:
        int a[500];
        int len;
    public:
        BigNum() { len = 1; memset(a, 0, sizeof(a)); }
        BigNum(const int);
        BigNum(const char*);
        BigNum(const BigNum&);
        BigNum& operator=(const BigNum&);

        friend istream& operator>>(istream&, BigNum&);
        friend ostream& operator<<(ostream&, BigNum&);

        BigNum operator+(const BigNum&) const;
        BigNum operator-(const BigNum&) const;
        BigNum operator*(const BigNum&) const;
        BigNum operator/(const int&) const;

        BigNum operator^(const int&) const;
        int operator%(const int&) const;
        bool operator>(const BigNum&) const;
        bool operator>(const int&) const;

        void print();
};

BigNum::BigNum(const int b)
{
    int c, d = b;
    len = 0;
    memset(a, 0, sizeof(a));
    while(d > MAXN)
    {
        c = d - (d / (MAXN + 1)) * (MAXN + 1);
        d /= (MAXN + 1);
        a[len++] = c;
    }
    a[len++] = d;
}

BigNum::BigNum(const char* s)
{
    int t, k, index, l, i;
    memset(a, 0, sizeof(0));
    l = strlen(s);
    len = l / DLEN;
    if(l % DLEN)
        len++;
    index = 0;
    for(i = l - 1; l >= 0; l -= DLEN)
    {
        t = 0;
        k = i - DLEN + 1;
        if(k < 0)
            k = 0;
        for(int j = k; j <= i; j ++)
            t = t * 10 + s[j] - '0';
        a[index++] = t;
    }
}

BigNum::BigNum(const BigNum& T) : len(T.len)
{
    int i;
    memset(a, 0, sizeof(a));
    for(i = 0; i < len; i ++)
        a[i] = T.a[i];
}

BigNum& BigNum::operator=(const BigNum& n)
{
    int i;
    len = n.len;
    memset(a, 0, sizeof(a));
    for(i = 0; i < len; i ++)
        a[i] = n.a[i];
    return *this;
}

istream& operator>>(istream& in, BigNum& b)
{
    char ch[MAXSIZE * 4];
    int i = -1;
    in >> ch;
    int l = strlen(ch);
    int count = 0; sum = 0;
    for (i = l - 1; i >= 0;)
    {
        sum = 0;
        int t = 1;
        for(int j = 0; j < 4 && i >= 0; j ++, i --, t *=10)
            sum += (ch[i] - '0') * t;
        b.a[count++] = sum;
    }
    b.len = count++;
    return in;
}

BigNum BigNum::operator+(const BigNum& T) const
{
    BigNum t(*this);
    int i, big;
    big = T.len > len ? T.len : len;
    for(i = 0; i < big; i ++)
    {
        t.a[i] += T.a[i];
        if(t.a[i] > MAXN)
        {
            t.a[i + 1]++;
            t.a[i] -= MAXN + 1;
        }
    }
    if(t.a[big] != 0)
        t.len = big + 1;
    return t;
}

BigNum BigNum::operator-(const BigNum& T) const
{
    int i, j, big;
    bool flag;
    BigNum t1, t2;
    if(*this > T)
    {
        t1 = *this;
        t2 = T;
        flag = 0;
    }
    else
    {
        t1 = T;
        t2 = *this;
        flag = 1;
    }
    big = t1.len;
    for(i = 0; i < big; i ++)
    {
        if(t1.a[i] < t2.a[i])
        {
            j = i + 1;
            while(!t1.a[j])
                j++;
            t1.a[j--]--;
            while(j > i)
                t1.a[j--] += MAXN;
            t1.a[i] += MAXN + 1 - t2.a[i];
        }
        else
            t1.a[i] -= t2.a[i];
    }
    t1.len = big;
    while(t1.a[len - 1] == 0 && t1.len > 1)
    {
        t1.len--;
        big--;
    }
    if(flag)
        t1.a[big - 1] = 0 - t1.a[big - 1];
    return t1;
}


