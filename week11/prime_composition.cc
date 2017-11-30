#include <iostream>
#include <cstdlib>

using namespace std;

const int MAXN = 1000;
bool prime[MAXN];

void init()
{
    for (int i = 0; i < MAXN; i ++)
        prime[i] = true;
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i < MAXN; i ++)
        if (prime[i])
            for (int j = 2; j * i < MAXN; j ++)
                prime[i * j] = false;
}

void composite(bool first, int n, int cur)
{
    if (n == 1)
        return;
    while (n % cur)
        while (!prime[++ cur]);
    if (!first)
        cout << '*';
    cout << cur;
    n /= cur;
    while (!(n % cur))
    {
        cout << '*' << cur;
        n /= cur;
    }
    while (!prime[++ cur]);
    composite(false, n, cur);
}

int main()
{
    init();
    int n;
    cin >> n;
    cout << n << '=';
    composite(true, n, 2);
    cout << endl;
    return 0;
}

