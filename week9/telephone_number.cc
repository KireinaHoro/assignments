#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cctype>
#include <utility>

using namespace std;

char lookup(char in)
{
    if(in == '-')
        return '\0';
    if(isdigit(in))
        return in;
    switch(in)
    {
        case 'A':
        case 'B':
        case 'C':
            return '2';
        case 'D':
        case 'E':
        case 'F':
            return '3';
        case 'G':
        case 'H':
        case 'I':
            return '4';
        case 'J':
        case 'K':
        case 'L':
            return '5';
        case 'M':
        case 'N':
        case 'O':
            return '6';
        case 'P':
        case 'R':
        case 'S':
            return '7';
        case 'T':
        case 'U':
        case 'V':
            return '8';
        case 'W':
        case 'X':
        case 'Y':
            return '9';
    }
}

char *parse(const char *in)
{
    char *ret = new char[9], *orig = ret;
    while(*in)
    {
        if(ret - orig == 3)
            *(ret ++) = '-';
        char tmp = lookup(*(in++));
        if(!tmp)
            continue;
        *(ret ++) = tmp;
    }
    orig[8] = '\0';
    return orig;
}

bool cmp(char *a, char *b)
{
    return strcmp(a, b) < 0;
}

int main()
{
    int n, _n;;
    cin >> n;
    _n = n;
    cin.get();
    vector<char*> ans;
    while(_n --)
    {
        char *in = NULL;
        size_t nbytes = 0;
        getline(&in, &nbytes, stdin);
        char *result = parse(in);
        ans.push_back(result);
    }
    sort(ans.begin(), ans.end(), cmp);
    bool matched = false;
    int i = 0, j = 0;
    while(i < n)
    {
        j = i;
        i ++;
        while(i < n && strcmp(ans[i], ans[j]) == 0)
            i ++;
        if(i - j > 1)
        {
            cout << ans[j] << " " << i - j << endl;
            matched = true;
        }
    }
    if(!matched)
        cout << "No duplicates." << endl;
    return 0;
}

