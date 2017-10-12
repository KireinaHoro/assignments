#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

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
    vector<int_p> a;
    for(int i = 0; i < n; i ++)
    {
        int num;
        cin >> num;
        a.push_back(pair<int, int>(i, num));
    }
    stable_sort(a.begin(), a.end(), cmp);
    cout << a.begin()->first + 1 << endl;
    return 0;
}

