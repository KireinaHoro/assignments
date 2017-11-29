#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void swap(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void reverse(char *first, char *last)
{
    for(int i = 0; i < (last - first) / 2; i ++)
        swap(first + i, last - 1 - i);
}

bool next_permutation(char *first, char *last)
{
    if(first == last)
        return false;
    char *i = last;
    if(first == --i)
        return false;
    while(true)
    {
        char *i1, *i2;
        i1 = i;
        if(*--i < *i1)
        {
            i2 = last;
            while(!(*i < *--i2))
                ;
            swap(i, i2);
            reverse(i1, last);
            return true;
        }
        if(i == first)
        {
            reverse(first, last);
            return false;
        }
    }
}

int main()
{
    char *in = NULL;
    size_t nbytes = 0;
    getline(&in, &nbytes, stdin);
    int len = strlen(in);
    in[-- len] = '\0';
    printf("%s\n", in);
    while(next_permutation(in, in + len))
        printf("%s\n", in);
    free(in);
    return 0;
}


