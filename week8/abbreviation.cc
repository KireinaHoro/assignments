#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

bool isabbr(char *abbr, char *full)
{
    if(strlen(abbr) >= strlen(full))
        return false;
    while(*abbr)
    {
        if(!strchr(full, *abbr))
            return false;
        full = strchr(full, *abbr) + 1;   
        abbr ++;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    cin.get();
    while(n --)
    {
        char *in = NULL;
        size_t nbytes = 0;
        getline(&in, &nbytes, stdin);
        char *abbr = strtok(in, ":");
        char *full = strtok(NULL, ":");
        full[strlen(full) - 1] = '\0';
        cout << (isabbr(abbr, full) ? "YES" : "NO") << endl;
        free(in);
    }
    return 0;
}

