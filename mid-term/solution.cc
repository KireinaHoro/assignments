#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<double> > sequence(vector<double> in)
{
    if(in.size() == 1)
        return vector<vector<double> >(1, in);
    double head = *(in.begin());
    in.erase(in.begin());
    vector<vector<double> > tmp = sequence(in), ret = tmp; 
    for(vector<vector<double> >::const_iterator it = tmp.begin(); it != tmp.end(); it ++)
        if(head >= *(it->end() - 1))
        {
            vector<double> a = *it;
            a.push_back(head);
            ret.push_back(a);
        }
    ret.push_back(vector<double>(1, head));
    return ret;
}

bool cmp(vector<double> a, vector<double> b)
{
    return a.size() > b.size();
}

int main()
{
    int n;
    cin >> n;
    vector<double> in(n);
    for(int i = 0; i < n; i ++)
        cin >> in[i];
    vector<vector<double> > ans = sequence(in);
    int ans_int = 0;
    vector<vector<double> >::const_iterator it, ans_it = ans.begin();
    for(it = ans.begin(); it != ans.end(); it ++)
        if(ans_int < it->size())
        {
            ans_it = it;
            ans_int = it->size();
        }
    /*
    for(vector<double>::const_iterator it = ans_it->begin(); it != ans_it->end(); it ++)
        cout << *it << endl;
    */
    cout << ans_int << endl;
    return 0;
}

