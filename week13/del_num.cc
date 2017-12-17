#include <iostream>
#include <string>

using namespace std;

const int MAXN = 102;

void del(string &a, int n)
{
    if (n <= 0 || !a.size())
        return;
    string ans = a;
    ans.erase(ans.begin());
    for (int i = 1; i < a.size(); i ++)
    {
        string tmp = a;
        tmp.erase(tmp.begin() + i);
        if (tmp < ans)
            ans = tmp;
    }
    a = ans;
    del(a, n - 1);
}

int main()
{
    string str;
    int n;
    cin >> str >> n;
    del(str, n);
    while (!(*(str.begin()) - '0'))
        str.erase(str.begin());
    cout << (str.size() ? str : "0") << endl;
    return 0;
}

