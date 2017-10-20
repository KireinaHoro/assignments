#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if(!n)
    {
        cout << 0 << endl;
        return 0;
    }
    vector<int> patients(n);
    for(int i = 0; i < n; i ++)
        cin >> patients[i];
    sort(patients.begin(), patients.end());
    vector<int>::const_iterator it = patients.begin();
    int t = 120;
    while(t >= 0)
    {
        if(120 - t > *it - 60)
            t -= 10;
        else
            t = 120 - (*it - 60) - 10;
//        cout << t << endl;
        it ++;
    }
    cout << it - patients.begin() - 1 << endl;
    return 0;
}

