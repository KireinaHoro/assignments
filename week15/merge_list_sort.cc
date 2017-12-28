#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> ans;
    int n_A, n_B;
    cin >> n_A;
    for (int i = 0; i < n_A; i ++)
    {
        int tmp;
        cin >> tmp;
        ans.push_back(tmp);
    }
    cin >> n_B;
    for (int i = 0; i < n_B; i ++)
    {
        int tmp;
        cin >> tmp;
        ans.push_back(tmp);
    }
    sort(ans.begin(), ans.end());
    cout << ans[0];
    for (int i = 1; i < int(ans.size()); i ++)
        cout << ' ' << ans[i];
    cout << endl;
    return 0;
}

