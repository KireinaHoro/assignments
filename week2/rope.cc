#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int* a = (int*)malloc(sizeof(int) * n);
    int k = 0, ans = 0;
    for(int i = 0; i < n; i ++) cin >> a[i];
    for(int i = 1; i <= 60; i ++)
    {
        if(i == a[k] + k * 3) { i += 3; k++; }
        ans ++;
    }
    cout << ans << endl;
    return 0;
}
