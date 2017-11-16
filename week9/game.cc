#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

void take(char *in)
{
    if(*in == '#') return;
    char *start = in, *end = in;
    do
    {
        start = end;
        while(*start == '#') start ++;
        end = start + 1;
        while(*end == '#') end ++;
    } while(*start == *end && *start && *end);
    cout << start - in << ' ' << end - in << endl;
    *start = '#';
    *end = '#';
    take(in);
}

int main()
{
    char *in = NULL;
    size_t nbytes = 0;
    getline(&in, &nbytes, stdin);
    take(in);
    return 0;
}

