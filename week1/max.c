#include <stdio.h>
int max(int a,int b,int c){return a>b?(b>c?a:(a>c?a:c)):(b>c?b:c);}
int main(){printf("%d",max(6,3,5));return 0;}
