#include <iostream>
#include <limits>
#include <cstring>

using namespace std;

const int MAXN = 30;

int _kids[MAXN], kids[MAXN], _kids_size, kids_size;

int main()
{
    int k;
    while(cin >> k, k != 0)
    {
        //vector<int> _kids(2 * k);
        for(int i = 0; i < k; i ++)
            _kids[i] = 1;
        _kids_size = 2 * k;
        int m = k + 1;
        for(; m < numeric_limits<int>::max(); m ++)
        {
            int cur = 0;
            //vector<int> kids = _kids;
            memcpy(kids, _kids, sizeof(kids));
            kids_size = _kids_size;
            for(int j = 0; j < k; j ++)
            {
                /*
                for(int t = 0; t < m - 1; t ++, cur ++)
                    if(kids[cur % (2 * k)] == -1)
                        t --;
                while(kids[cur % (2 * k)] == -1)
                    cur ++;
                if(kids[cur % (2 * k)] == 1)
                    goto failed;
                //cout << cur % (2 * k) << endl;
                kids[(cur ++) % (2 * k)] = -1;
                */
                cur += m - 1;
                cur %= kids_size;
                if(kids[cur] == 1)
                    goto failed;
                //kids.erase(kids.begin() + cur);
                kids_size --;
                for(int i = cur; i < kids_size; i ++)
                    kids[i] = kids[i + 1];
            }
            break;

failed:
            continue;
        }
        cout << m << endl;
    }
    return 0;
}


