#include <stdio.h>

int main()
{
    int max = 0, min = 0x7fffffff, i;
    for(i = 0; i < 3; i ++)
    {
        int tmp;
        scanf("%d", &tmp);
        if(tmp > max) max = tmp;
        if(tmp < min) min = tmp;
    }
    printf("%d", max - min);
    return 0;
}

