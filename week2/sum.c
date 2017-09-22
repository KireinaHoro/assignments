#include <stdio.h>
#include <malloc.h>

int main()
{
    int m, n, max = 0, sum = 0;
    scanf("%d", &n);
    m = n;
    int* a = malloc(n * sizeof(int));
    while(n--)
    {
        int tmp;
        scanf("%d", &tmp);
        if(max < tmp) max = tmp;
        a[n] = tmp;
    }
    while(m--)
        if(a[m] != max) sum += a[m];
    printf("%d", sum);
    free(a);
    return 0;
}

