#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <iterator>

using namespace std;

vector<int>::iterator next(vector<int>::iterator a)
{
    advance(a, 1);
    return a;
}

struct MatchLength
{
    MatchLength(const int& l) : l_(l) {}
    bool operator()(const vector<int>& obj) const
    {
        return obj.size() == l_;
    }
    private:
        const int& l_;
};

int calc(int i)
{
    int sum = 0;
    while(i)
    {
        sum += i % 10;
        i /= 10;
    }
    return sum;
}

int main()
{
    int m, n, k;
    scanf("%d,%d,%d", &m, &n, &k);
    vector<vector<int> > sets;
    for(int i = m + 1; i < n; i ++)
    {
        int temp = calc(i), index = temp / k;
        if(temp % k) continue;
//        vector<vector<int> >::iterator result = find_if(sets.begin(), sets.end(), MatchLength(temp));
//        if(result == sets.end())
        if(sets.size() < index)
        {
            vector<int> a(1, i);
            sets.push_back(a);
        }
        else
            sets[index - 1].push_back(i);
    }
    for(vector<vector<int> >::iterator it = sets.begin(); it != sets.end(); it ++)
    {
        vector<int>::iterator i;
        for(i = it->begin(); next(i) != it->end(); i ++)
            cout << *i << ',';
        cout << *i << endl;
    }
    return 0;
}

