#include <stdio.h>

int main()
{
    int a[20], i;
    a[0] = 1;
    a[1] = 1;
    for(i = 2; i < 20; i ++)
        a[i] = a[i - 1] + a[i - 2];
    int n;
    scanf("%d", &n);
    while(n--)
    {
        int p;
        scanf("%d", &p);
        printf("%d\n", a[p - 1]);
    }
    return 0;
}

