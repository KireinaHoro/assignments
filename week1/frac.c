#include <stdio.h>
#include <malloc.h>
struct frac
{
    int a, b;
};
int gcd(int a, int b)
{
    while(b){a%=b;a^=b;b^=a;a^=b;}return a;
    //return b?gcd(b,a%b):a;
}
int lcm(int a, int b)
{
    return a*b/gcd(a,b);
}
int main()
{
    int count, i, l=1, sum=0;
    scanf("%d", &count);
    struct frac* input = malloc(count * sizeof(struct frac));
    for(i = 0; i < count; i ++)
    {
        scanf("%d/%d", &((input + i) -> a), &((input + i) -> b));
        l = lcm(l, (input + i) -> b);
    }
    for(i = 0; i < count; i ++)
    {
        (input + i) -> a *= l / (input + i) -> b;
        sum += (input + i) -> a;
    }
    int g = gcd(sum, l);
    if(g/l==1)
        printf("%d", sum/g);
    else
        printf("%d/%d", sum/g, l/g);
    free(input);
    return 0;
}
