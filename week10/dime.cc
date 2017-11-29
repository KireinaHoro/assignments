#include <iostream>
#include <iomanip>

using namespace std;

int counter = 1;

void solve(int m, int n, int p)
{
    cout << setfill('0') << setw(3) << counter
        << setfill(' ') << setw(12) << m
        << setfill(' ') << setw(12) << n
        << setfill(' ') << setw(12) << p
        << endl;
    counter ++;
    if(m >= 2)
    {
        solve(m - 2, n + 1, p);
    }
    if(m + n * 2 < 5)
        exit(0);
    if(m + n * 2 >= 5)
    {
        solve(m + n * 2 - 5, 0, p + 1);
    }
}

int main()
{
    int n;
    cin >> n;
    solve(n, 0, 0);
    return 0;
}


