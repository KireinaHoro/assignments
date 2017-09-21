#include <math.h>
#include <stdio.h>

int main()
{
    int m, x, i;
    scanf("%d %d", &x, &m);
    for(i = 1; i <= 100; i ++)
        if(x * (pow(1.08, i) - 1) / 0.08 >= m * pow(1.1, i - 1))
        {
            printf("%d", i);
            return 0;
        }
    printf("Forget it.");
    return 0;
}
