#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    cin >> n;
    getchar();
    while(n--)
    {
        string a, b;
        getline(cin, a);
        getline(cin, b);
        int l_a = a.length(), l_b = b.length(), m = max(l_a, l_b);
        vector<int> v_a(m), v_b(m), ans(m + 1);
        istringstream s_a(a), s_b(b);
        for(int i_a = 0; i_a < l_a; i_a ++)
        {
            char tmp;
            s_a >> tmp;
            v_a[l_a - i_a - 1] = tmp - '0';
//            cout << "a: " << v_a[l_a - i_a - 1] << endl;
        }
        for(int i_b = 0; i_b < l_b; i_b ++)
        {
            char tmp;
            s_b >> tmp;
            v_b[l_b - i_b - 1] = tmp - '0';
//            cout << "b: " << v_b[l_b - i_b - 1] << endl;
        }
        for(int i = 0; i < m; i ++)
        {
//            cout << "a:: " << v_a[i] << " b:: " << v_b[i] << endl;
            ans[i] += v_a[i] + v_b[i];
            if(ans[i] > 1)
            {
                ans[i + 1] ++;
                ans[i] -= 2;
            }
        }
        if(ans[m])
            cout << ans[m] /* << ' ' */;
        for(int i = m - 1; i >= 0; i --)
            cout << ans[i] /* << ' ' */ ;
        cout << endl;

    }
    return 0;
}
