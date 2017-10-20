#include <iostream>
#include <vector>
#include <limits>

using namespace std;

typedef vector<int>::const_iterator it_int;

int main()
{
    int n, max = numeric_limits<int>::min(), ans = 0;
    cin >> n;
    vector<int> num(n);
    for(int i = 0; i < n; i ++)
    {
        cin >> num[i];
        if(num[i] > max)
            max = num[i];
    }
    for(it_int it = num.begin(); it != num.end(); it ++)
        if(*it != max)
            ans += *it;
    cout << ans << endl;
    return 0;
}

