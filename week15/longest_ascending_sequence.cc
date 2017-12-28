#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, ans;
    cin >> n;
    vector<int> d;
    for (int i = 0; i < n; i ++)
    {
        int x;
        cin >> x;
        vector<int>::iterator it = lower_bound(d.begin(), d.end(), x);
        if (it == d.end())
            d.push_back(x);
        else
            *it = x;
    }
    cout << d.size() << endl;
    return 0;
}

