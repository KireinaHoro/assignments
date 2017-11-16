#include <cstdio>

using namespace std;

int gcd(int a, int b)
{
    if(a < b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
    if(b == 1)
        return 1;
    if(a == b)
        return a;
    return gcd(a - b, b);
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int main()
{
    int a, b;
    scanf("%d,%d", &a, &b);
    printf("%d\n", lcm(a, b));
    return 0;
}

