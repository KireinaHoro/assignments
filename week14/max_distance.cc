#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string haystack, needle1, needle2;
    getline(cin, haystack, ',');
    getline(cin, needle1, ',');
    getline(cin, needle2);
    string rev_haystack = haystack;
    reverse(rev_haystack.begin(), rev_haystack.end());
    reverse(needle2.begin(), needle2.end());
    size_t s = haystack.find(needle1) + needle1.size();
    size_t e = haystack.size() - rev_haystack.find(needle2) - needle2.size();
    cout << (s > e ? -1 : int(e - s)) << endl;
    return 0;
}

