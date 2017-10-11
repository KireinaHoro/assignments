#include <iostream>
#include <vector>

using namespace std;

typedef vector<int>::const_iterator itint_t;

int main()
{
    vector<int> a, b, ans;
    itint_t it, it_a, it_b;
    for(int i = 0; i < 10; i ++)
    {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    for(int i = 0; i < 10; i ++)
    {
        int temp;
        cin >> temp;
        b.push_back(temp);
    }
    for(it_a = a.begin(), it_b = b.begin(); it_a != a.end() && it_b != b.end(); )
    {
        if(*it_a < *it_b)   
        {
            ans.push_back(*it_a);
            it_a ++;
            continue;
        }
        else
        {
            ans.push_back(*it_b);
            it_b ++;
            continue;
        }
    }
    while(it_a != a.end())
        ans.push_back(*it_a++);
    while(it_b != b.end())
        ans.push_back(*it_b++);
    for(it = ans.begin(); it != ans.end() - 1; it ++)
        cout << *it << ' ';
    cout << *it << endl;
    return 0;
}

