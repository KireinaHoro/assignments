#include <iostream>
#include <deque>
#include <numeric>
#include <iterator>
#include <limits>
#include <utility>

using namespace std;

int main()
{
    int n, sum_s = 0;
    cin >> n;
    deque<int> x(n), s(n);
    for(int i = 0; i < n; i ++)
    {
        cin >> x[i] >> s[i];
        sum_s += s[i];
    }
    pair<int, int> ans(numeric_limits<int>::max(), 0);
    for(int k = 0; k < n; k ++)
    {
        pair<int, int> cost(0, k);
        for(int i = 1; i < n; i ++)
        {
            int t = accumulate(s.begin(), s.begin() + i, 0);
//            cout << "t: " << t << endl;
            cost.first += x[i] * min(t, sum_s - t);
        }
        if(cost.first < ans.first)
            ans = cost;
        
        x.push_back(x.front());
        x.pop_front();
        s.push_back(s.front());
        s.pop_front();
    }
    cout << ans.second << ',' << ans.first << endl;           
    return 0;
}

