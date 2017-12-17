#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

const int MAXN = 502;
int times[MAXN];

pair<int, vector<char *> > strspl(char *str, int n)
{
    memset(times, 0, sizeof(times));
    int l = strlen(str);
    int max_occur = 0;
    vector<char *> ans;
    for (int i = 0; i < l - n + 1; i ++)
    {
        for (int j = 0; j <= i; j ++)
            if (!strncmp(str + i, str + j, n))
                times[i] ++;
        int j = 0;
        for (j = 0; j <= i; j ++)
            if (!strncmp(str + i, str + j, n))
            {
                times[j] = times[i];
                times[i] = 0;
                break;
            }
        if (times[j] > max_occur)
            max_occur = times[j];
    }
    for (int i = 0; i < l - n + 1; i ++)
        if (times[i] == max_occur)
            ans.push_back(str + i);
    return pair<int, vector<char *> >(max_occur, ans);
}

int main()
{
    int n;
    cin >> n;
    cin.get();
    char *a = NULL;
    size_t nbytes = 0;
    getline(&a, &nbytes, stdin);
    a[strlen(a) - 1] = '\0';
    pair<int, vector<char *> > ans = strspl(a, n);
    if (ans.first)
        cout << ans.first << endl;
    else
    {
        cout << "NO" << endl;
        return 0;
    }
    for (vector<char *>::const_iterator it = ans.second.begin(); it != ans.second.end(); it ++)
    {
        for (int i = 0; i < n; i ++)
            cout << *(*it + i);
        cout << endl;
    }
    return 0;
}

