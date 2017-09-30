#include <iostream>

using namespace std;

int main()
{
    int p, e, i, d;
    while(cin >> p >> e >> i >> d)
    {
        bool bp = false, be = false, bi = false;
        int k;
        for(k = d + 1; ; k ++, bp = false, be = false, bi = false)
        {
            if(!((k - p) % 23)) bp = true;
            if(!((k - e) % 28)) be = true;
            if(!((k - i) % 33)) bi = true;
            if(bp && be && bi) break;
        }
        cout << k - d << endl;
    }
    return 0;
}

