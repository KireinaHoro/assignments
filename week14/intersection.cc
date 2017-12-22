#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

set<int> A, B;
vector<int> ans;

int main()
{
    string a, b;
    getline(cin, a);
    getline(cin, b);
    istringstream isa(a), isb(b);
    int temp;
    char comma;
    isa >> temp;
    A.insert(temp);
    while (isa >> comma >> temp)
        A.insert(temp);
    isb >> temp;
    B.insert(temp);
    while (isb >> comma >> temp)
        B.insert(temp);
    set_intersection(A.begin(), A.end(), B.begin(), B.end(), back_inserter(ans));
    if (!ans.size())
    {
        cout << "NULL" << endl;
        return 0;
    }
    vector<int>::const_iterator it = ans.begin();
    cout << *it;
    for (it ++; it != ans.end(); it ++)
        cout << ',' << *it;
    cout << endl;
    return 0;
}

