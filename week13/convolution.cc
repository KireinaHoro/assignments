#include <iostream>
#include <vector>

using namespace std;

vector<int> conv(vector<int> A, vector<int> B)
{
    vector<int> ret;
    int M = A.size();
    int N = B.size();
    for (int i = 0; i < M + N - 1; i ++)
    {
        int sum = 0;
        for (int m = min(0, i - N); m <= max(i, M); m ++)
        {
            if (m < 0 || m > M - 1 || i - m < 0 || i - m > N - 1)
                continue;
            else
                sum += A[m] * B[i - m];
        }
        ret.push_back(sum);
    }
    return ret;
}

int main()
{
    int n;
    cin >> n;
    while(n --)
    {
        vector<int> a, b, ans;
        int p, q;
        cin >> p >> q;
        while(p --)
        {
            int tmp;
            cin >> tmp;
            a.push_back(tmp);
        }
        while(q --)
        {
            int tmp;
            cin >> tmp;
            b.push_back(tmp);
        }
        ans = conv(a, b);
        cout << ans[0];
        for (int i = 1; i < ans.size(); i ++)
            cout << ' ' << ans[i];
        cout << endl;
    }
    return 0;
}

