#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string in;
    getline(cin, in);
    for (size_t i = 0; i < in.size(); i ++)
        if (!isdigit(in[i]))
            in[i] = ' ';
    istringstream is(in);
    vector<int> ans;
    int temp;
    while(is >> temp)
        ans.push_back(temp);
    sort(ans.begin(), ans.end());
    if (!ans.size())
    {
        cout << 0 << endl;
        return 0;
    }
    cout << ans[0];
    for (size_t i = 1; i < ans.size(); i ++)
        cout << ',' << ans[i];
    cout << endl;
    return 0;
}

