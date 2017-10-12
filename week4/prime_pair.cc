#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int m, n;
    scanf("%d,%d", &m, &n);
    //vector<int> primes;
    vector<bool> primes(n + 1, true);
//    primes.push_back(2);
    primes[0] = false, primes[1] = false;
    /*
    for(int i = 3; i <= n; i ++)
    {
        for(vector<int>::const_iterator it = primes.begin(); it != primes.end(); it ++)
            if(!(i % *it))
                goto out;
        primes.push_back(i);
out: ;
    }
    */
    for(int i = 1; i <= n; i ++)
        if(primes[i])
            for(int j = 2; i * j <= n; j ++)
                primes[i * j] = false;
/*    
    for(int i = 1; i <= n; i ++)
        if(primes[i])
            cout << i << endl;
*/     
//    for(auto i : primes) cout << i << endl;
    // [start, end)
    int start;
    for(start = m; !primes[start]; start ++);
    /*
    vector<int>::const_iterator start_it, i, j;
    for(start_it = primes.begin(); *start_it < m; start_it ++);
//    cout << "afdsf " <<  *start_it << endl;
    bool flag = false;
    vector<int> memo(*(primes.end() - 1) - *start_it + 1, -1);
    
    for(i = start_it; i != primes.end(); i ++)
        for(j = i + 1; j != primes.end(); j ++)
        {
            if(memo[*j - *i] == -1)
                memo[*j - *i] = find(primes.begin(), primes.end(), *j - *i) != primes.end() ? 1 : 0;
            if(memo[*j - *i])
            {
                flag = true;
                cout << '(' << *i << ',' << *j << ')' << endl;
            }
        }

   
    if(!flag)
        cout << "NULL" << endl;
        */
    bool flag = false;
    for(int i = start; i <= n; i ++)
        if(i == 2)
            for(int j = i + 1; j <= n; j ++)
            {
//                cout << "=====" << j << "=======" << endl;
                if(!primes[j]) continue;
//                cout << j - i << ' ' << primes[j - i] << endl;
                if(!primes[j - i]) continue;
                flag = true;
                cout << '(' << i << ',' << j << ')' << endl;
            }
        else if(primes[i] && i + 2 <= n)
            if(primes[i + 2])
            {
                flag = true;
                cout << '(' << i << ',' << i + 2 << ')' << endl;
            }
    if(!flag)
        cout << "NULL" << endl;
    return 0;
}

