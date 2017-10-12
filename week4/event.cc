#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> int_p;

bool cmp(int_p a, int_p b)
{
    return a.second < b.second;
}

int main()
{
    int n;
    cin >> n;
    vector<int_p> events;
    while(n--)
    {
        int a, b;
        cin >> a >> b;
        events.push_back(int_p(a, b));
    }
    sort(events.begin(), events.end(), cmp);
    vector<int_p> ans;
    ans.push_back(*events.begin());
    for(vector<int_p>::const_iterator it = events.begin(); it != events.end(); it ++)
        if(it->first < (ans.end() - 1)->second)
            continue;
        else
            ans.push_back(*it);
    cout << ans.size() << endl;
    return 0;
}
