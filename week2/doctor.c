#include <stdio.h>
#include <string.h>

int max(int* max, int count)
{
    int i, ret = 0;
    for(i = 0; i < count; i ++)
        if(max[ret] < max[i])
            ret = i;
    return ret + 1;
}

int main()
{
    int n, doctor[15];
    memset(doctor, 0, sizeof(doctor));
    scanf("%d", &n);
    while(n--)
    {
        int doc;
        scanf("%d", &doc);
        doctor[doc-1]++;
    }
    printf("%d", max(doctor, 15));
    return 0;
}

