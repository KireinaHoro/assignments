#include <iostream>
#include <limits>
#include <algorithm>
#include <cstring>

#define eps 1e-6

using namespace std;

const int MAXN = 120;
double S[MAXN], A[MAXN];
int d[MAXN];

int n = 0;

void init()
{
    for(int i = 0; i < MAXN; i ++)
        S[i] = numeric_limits<double>::min();
    memset(d, 0, sizeof(d));
}

int BSearch(int x, int y, double v)
{
    while(x <= y)
    {
        int mid = x + (y - x) / 2;
        if(S[mid] - v >= eps) x = mid + 1;
        else y = mid - 1;
    }
    return x;
}

void dp()
{
    init();
    int ans = 0;
    for(int i = 1; i <= n; i ++)
    {
        int x = 1, y = i;
        int pos = BSearch(x, y, A[i]);
        d[i] = pos;
        S[d[i]] = max(S[d[i]], A[i]);
        ans = max(ans, d[i]);
    }
    cout << ans << endl;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++)
        cin >> A[i];
    dp();
    for(int i = 0; i < n; i ++)
        cout << S[i] << endl;
    return 0;
}

