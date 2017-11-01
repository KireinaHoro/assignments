#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second - a.first < b.second - b.first;
}

int main()
{
    string in;
    getline(cin, in);
    istringstream is(in);
    stack<int> waiting;
    vector<pair<int, int> > ans;
    int pos = 0;
    char a;
    while(is >> a)
    {
        int match = 0;
        switch(a)
        {
            case '(':
                waiting.push(pos);
                break;
            case ')':
                if(!waiting.size())
                {
                    cout << "mismatch" << endl;
                    return 0;
                }
                match = waiting.top();
                waiting.pop();
                ans.push_back(pair<int, int>(match, pos));
                break;
            default:
                ;
        }
        pos ++;
    }
    if(waiting.size())
    {
        cout << "mismatch" << endl;
        return 0;
    }
    stable_sort(ans.begin(), ans.end(), cmp);
    if(!ans.size())
    {
        cout << "0,0" << endl;
        return 0;
    }
    for(vector<pair<int, int> >::const_iterator it = ans.begin(); it != ans.end(); it ++)
        cout << it->first + 1 << ',' << it->second + 1 << endl;
    return 0;
}

