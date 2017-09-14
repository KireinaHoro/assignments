#include <stdio.h>
#include <malloc.h>

void bubble_sort(int* arr, int count)
{
    int i;
    for(i=0; i<count; i++)
    {
        int j;
        for(j=i; j<count; j++)
            if(arr[j]<arr[i])
            {
                int tmp;
                tmp=arr[j];
                arr[j]=arr[i];
                arr[i]=tmp;
            }
    }
}
int main()
{
    int count, i;
    scanf("%d", &count);
    int* num = malloc(count * sizeof(int));
    for(i=0; i<count; i++)
        scanf("%d", &num[i]);
    bubble_sort(num, count);
    for(i=0; i<count; i++)
        printf("%d\n", num[i]);
    return 0;
}
