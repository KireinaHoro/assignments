#include <stdio.h>
#include <math.h>

int main()
{
    double x, y;
    scanf("%lf,%lf", &x, &y);
    printf((fabs(x) <= 1 && fabs(y) <= 1) ? "yes" : "no");
    return 0;
}

