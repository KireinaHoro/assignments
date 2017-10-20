#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
    int n, k;
    cin >> n;
    vector<int> num(n);
    for(int i = 0; i < n; i ++)
        cin >> num[i];
    cin >> k;
    sort(num.begin(), num.end(), greater<int>());
    for(int i = 0; i < k; i ++)
        cout << num[i] << endl;
    return 0;
}

