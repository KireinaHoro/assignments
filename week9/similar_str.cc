#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 500;
int edit[MAXN][MAXN];

int match(char *src, char *dst)
{
    /*
    char *_s = src, *_d = dst;
    while(*src == *dst && *src && *dst)
    {
        src ++;
        dst ++;
    }
    cout << src - _s << ' ' << dst - _d << endl;
    if(!*src)
        return strlen(dst);
    if(!*dst)
        return strlen(src);
    return 1 + min(match(src + 1, dst), match(src, dst + 1));
    */
    memset(edit, 0, sizeof(edit));
    int len_src = strlen(src), len_dst = strlen(dst);
    for(int i = 0; i < MAXN; i ++)
    {
        edit[0][i] = i;
        edit[i][0] = i;
    }
    for(int i = 1; i < len_dst + 1; i ++)
        for(int j = 1; j < len_src + 1; j ++)
        {
            int cost = 0;
            if(dst[i - 1] != src[j - 1])
                cost = 2;
            int min_cost;
            if(edit[i - 1][j] < edit[i][j - 1])
                min_cost = edit[i - 1][j] + 1;
            else
                min_cost = edit[i][j - 1] + 1;
            if(min_cost > edit[i - 1][j - 1] + cost)
                min_cost = edit[i - 1][j - 1] + cost;
            edit[i][j] = min_cost;
        }
    return edit[len_dst][len_src];
}

char *read_str()
{
    char *r = NULL;
    size_t nbytes = 0;
    getline(&r, &nbytes, stdin);
    r[strlen(r) - 1] = '\0';
    return r;
}

struct alter
{
    char *str;
    int diff;
    
    alter(char *_a, int _d) : str(_a), diff(_d) {}
};

bool cmp(alter a, alter b)
{
    return a.diff < b.diff;
}

int main()
{
    char *a = read_str();
    int n;
    cin >> n;
    cin.get();
    vector<alter> ans;
    while(n --)
    {
        char *temp = read_str();
        ans.push_back(alter(temp, match(a, temp)));
    }
    stable_sort(ans.begin(), ans.end(), cmp);
    for(vector<alter>::iterator it = ans.begin(); it != ans.end(); it ++)
    {
        if(it->diff > ans.begin()->diff)
            break;
        cout << it->str << endl;
    }
    return 0;
}

