#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string itoa(int i)
{
    string ans;
    while(i > 0)
    {
        ans.append(1, i % 10 + '0');
        i /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

string encode(string in)
{
    if(!in.length())
        return "";
    if(in.length() == 1)
        return "1" + string(1, in[0]);
    int i = 0;
    while(in[i] == in[i + 1])
        i ++;
    return itoa(i + 1) + string(1, in[i]) + encode(in.substr(i + 1));
}

int main()
{
    int n;
    cin >> n;
    while(n --)
    {
        string a;
        cin >> a;
        cout << encode(a) << endl;
    }
    return 0;
}

