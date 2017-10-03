#include <iostream>

using namespace std;

int main()
{
    int n, m, k, p, last = 0, maxa = 0, maxb = 0, tmp;
    cin >> m >> n;
    cin >> k;
    for(int i = 0; i < k; i ++)
    {
        cin >> tmp;
        if(maxa < tmp - last - 1)
            maxa = tmp - last - 1;
        last = tmp;
    }
    if(n - tmp > maxa) maxa = n - tmp;
    last = 0;
    cin >> p;
    for(int i = 0; i < p; i ++)
    {
        cin >> tmp;
        if(maxb < tmp - last - 1)
            maxb = tmp - last - 1;
        last = tmp;
    }
    if(m - tmp > maxb) maxb = m - tmp;
    cout << maxa * maxb << endl;
    return 0;
}

