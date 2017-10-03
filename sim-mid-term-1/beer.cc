#include <iostream>
#include <vector>
#include <limits>
#include <utility>

using namespace std;

int main()
{
    int n, sum_s = 0;
    cin >> n;
    vector<int> x(n), s(n);
    for(int i = 0; i < n; i ++)
    {
        cin >> x[i] >> s[i];
        sum_s += s[i];
    }
    pair<int, int> ans(numeric_limits<int>::max(), 0);
    for(int k = 0; k < n; k ++)
    {
        pair<int, int> cost(0, k);
        int t = 0;
        for(int i = 1; i < n; i ++)
        {
            t += s[((i - 1) + k) % n];
            cost.first += x[(i + k) % n] * min(t, sum_s - t);
        }
        if(cost.first < ans.first)
            ans = cost;
    }
    cout << ans.second << ',' << ans.first << endl;           
    return 0;
}

