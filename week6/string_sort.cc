#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string in;
    getline(cin, in);
    int n = in.length();
    string front(in, 0, n / 2);
    sort(front.begin(), front.end(), greater<char>());
    string ans = (n % 2 ? string(in, n / 2 + 1, n / 2) + string(in, n / 2, 1) + front : string(in, n / 2, n / 2) + front);
    cout << ans << endl;
    return 0;
}

