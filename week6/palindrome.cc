#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    getline(cin, s);
    string orig = s;
    reverse(s.begin(), s.end());
    cout << (s == orig ? "yes" : "no") << endl;
    return 0;
}

