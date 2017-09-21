#include <stdio.h>

int main()
{
    int a;
    scanf("%d", &a);
    if(!(a%3)&&!(a%5)&&!(a%7)){printf("3 5 7");return 0;}
    if(!(a%3)&&!(a%7)){printf("3 7");return 0;}
    if(!(a%3)&&!(a%5)){printf("3 5");return 0;}
    if(!(a%5)&&!(a%7)){printf("5 7");return 0;}
    if(!(a%3)){printf("3");return 0;}
    if(!(a%5)){printf("5");return 0;}
    if(!(a%7)){printf("7");return 0;}
    printf("n");return 0;
}
