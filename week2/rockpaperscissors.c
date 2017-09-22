#include <stdio.h>

int main()
{
    int n, a = 0, b = 0;
    scanf("%d", &n);
    while(n--)
    {
       int x, y;
       scanf("%d %d", &x, &y);
       if(x == y) continue;
       if((x == 0 && y == 1) || (x == 1 && y == 2) || (x == 2 && y == 0)) { a++; }
       else { b++; }
    }
    if(a == b) { printf("Tie"); return 0; }
    printf(a > b ? "A" : "B");

    return 0;
}

