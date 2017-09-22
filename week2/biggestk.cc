#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

bool cmp(int a, int b) { return (a > b); }

int main()
{
    int n, k;
    cin >> n;
    int* a = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i ++)
        cin >> *(a + i);
    sort(a, a + n, cmp);
    cin >> k;
    for(int i = 0; i < k; i ++)
        cout << *(a + i) << endl;
    free(a);
    return 0;
}

