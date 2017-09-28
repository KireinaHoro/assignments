#include <iostream>
#include <vector>
#include <iterator>
#include <cmath>

using namespace std;

int main()
{
    vector<int> primes;
    primes.push_back(2);
    int m, k;
    cin >> m >> k;
    // failed to come up with a sensible way to estimate numbers
    const long int maxn = 10000;
    for(int i = 3; i < maxn; i ++)
    {
        for(vector<int>::const_iterator it = primes.begin(), end = primes.end(); it != end; it ++)
            if(!(i % *it))
                goto out;
        primes.push_back(i);
//        cout << i << endl;
out: ;
    }
    vector<int>::const_iterator index = primes.begin();
    while(*(index++) < m) { if(*index > m) break; }
//    cout << *index << " &%&&^*" << endl;
    for(int i = 0; i < k - 1; i ++, index ++)
        cout << *index << ' ';
    cout << *index << endl;
    return 0;
}

