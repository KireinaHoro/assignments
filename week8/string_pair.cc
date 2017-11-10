#include <cstring>
#include <cstdio>
#include <iostream>

using namespace std;

char* strrstr(const char *haystack, const char *needle)
{
    char *r = NULL;
    if(!needle[0])
        return (char*)haystack + strlen(haystack);
    while(true)
    {
        char *p = strstr((char*)haystack, needle);
        if(!p)
            return r;
        r = p;
        haystack = p + 1;
    }
}

int main()
{
    char *str = NULL;
    size_t nbytes = 0;
    int nread = getline(&str, &nbytes, stdin);
    str[-- nread] = '\0';
    char *token = strtok(str, ",");
    char *args[3];
    int i = 0;
    while(token != NULL && i <= 2)
    {
        args[i] = token;
        token = strtok(NULL, ",");
        i ++;
    }
    char *start = strstr(args[0], args[1]);
    char *end = strrstr(args[0], args[2]);
    if(start + strlen(args[1]) > end)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << end - start - strlen(args[1]) << endl;
    return 0;
}

