#include <stdio.h>

double judge_accu(int accu)
{
    if(accu < 100 || accu > 400)
        return 1;
    else if(accu < 150)
        return 0.8;
    else if(accu < 400)
        return 0.5;
    return 1;
}

int judge_fare(int dis)
{
    if(dis <= 6)
        return 3;
    else if(dis <= 12)
        return 4;
    else if(dis <= 32)
        return judge_fare(12) + ((dis - 12) % 10 ? (dis - 12) / 10 + 1 : (dis - 12) / 10);
    else if(32 < dis)
        return judge_fare(32) + ((dis - 32) % 20 ? (dis - 32) / 20 + 1 : (dis - 32) / 20);
    return 0;
}

int main()
{
    int accu, dis;
    scanf("%d %d", &accu, &dis);
    printf("%.2f", judge_accu(accu) * judge_fare(dis));
    return 0;
}

