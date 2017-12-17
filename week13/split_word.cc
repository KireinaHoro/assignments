#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<char *> dict;
const char *blank = "####################";

int main()
{
    int dictSize, testCaseNum;
    cin >> dictSize >> testCaseNum;
    cin.get();
    while (dictSize --)
    {
        char *a = NULL;
        size_t nbytes = 0;
        getline(&a, &nbytes, stdin);
        a[strlen(a) - 1] = '\0';
        dict.push_back(a);
    }
    int dictLen = strlen(dict[0]);
    while (testCaseNum --)
    {
        char *str = NULL;
        size_t nbytes = 0;
        getline(&str, &nbytes, stdin);
        int len = strlen(str);
        str[-- len] = '\0';
        int dictPtr = 0;
        while(len > 0 && dictPtr < dict.size())
        {
            char *loc = NULL;
            while (loc = strstr(str, dict[dictPtr]))
            {
                strncpy(loc, blank, dictLen);
                len -= dictLen;
            }
            dictPtr ++;
        }
        if (len)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
        free(str);
    }
    return 0;
}

