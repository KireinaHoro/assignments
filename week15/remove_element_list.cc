#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    int n, target;
    cin >> n;
    list<int> dest;
    for (int i = 0; i < n; i ++)
    {
        int temp;
        cin >> temp;
        dest.push_back(temp);
    }
    cin >> target;
    dest.remove(target);
    list<int>::const_iterator it = dest.begin();
    cout << *(it ++);
    for (; it != dest.end(); it ++)
        cout << ' ' << *it;
    cout << endl;
    return 0;
}

