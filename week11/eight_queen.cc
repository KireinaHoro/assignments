#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

char proc[9];
bool picked[8];
vector<char*> ans;

void pick(int num)
{
    if (num >= 8)
    {
        char *a = new char[9];
        strcpy(a, proc);
        ans.push_back(a);
        return;
    }
    for (int i = 0; i < 8; i ++)
    {
        if (!picked[i])
        {
            bool flag = true;
            for (int j = 0; j < num; j ++)
                if (abs(num - j) == abs(proc[j] - '1' - i))
                {
                    flag = false;
                    break;
                }
            if (!flag)
                continue;
            picked[i] = true;
            proc[num] = i + '1';
            pick(num + 1);
            picked[i] = false;
        }
    }
}

int main()
{
    pick(0);
    int n;
    cin >> n;
    while (n --)
    {
        int a;
        cin >> a;
        cout << ans[a - 1] << endl;
    }
    return 0;
}

