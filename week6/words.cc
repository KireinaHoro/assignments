#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> words;
    string in;
    while(cin >> in)
        words.push_back(in);
    cout << *(words.end() - 1);
    for(vector<string>::const_iterator it = words.end() - 2;
            it - words.begin() >= 0;
            it --)
        cout << ' ' << *it;
    cout << endl;
    return 0;
}

