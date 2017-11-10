#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int calc(int n, int k)
{
    int sum = 0;
    while(n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    if(sum % k)
        return -1;
    return sum / k;
}

int main()
{
    int m, n, k;
    char delim;
    string in;
    getline(cin, in);
    istringstream is(in);
    is >> m >> delim >> n >> delim >> k;
//    cout << m << ' ' << n << ' ' << k << endl;
    vector<vector<int> > ans;
    for(int i = m + 1; i < n; i ++)
    {
        int a = calc(i, k);
//        cout << i << ' ' << a << endl;
        if(a == -1)
            continue;
        if(ans.size() < a)
            ans.push_back(vector<int>(1, i));
        else
            ans[a - 1].push_back(i);
    }
//    cout << 'a' << endl;
    for(vector<vector<int> >::const_iterator it = ans.begin(); it != ans.end(); it ++)
    {
        cout << *(it->begin());
        for(vector<int>::const_iterator iit = it->begin() + 1; iit != it->end(); iit ++)
            cout << ',' << *iit;
        cout << endl;
    }
    return 0;
}

