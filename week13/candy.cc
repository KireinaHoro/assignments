#include <iostream>
#include <vector>

using namespace std;

vector<int> children, candy;

int main()
{
    int n;
    cin >> n;
    while (n --)
    {
        int temp;
        cin >> temp;
        children.push_back(temp);
        candy.push_back(1);
    }
    bool flag = true;
    while(flag)
    {
        flag = false;
        for (int i = 1; i < children.size(); i ++)
        {
            if ((children[i - 1] - children[i]) * (candy[i - 1] - candy[i]) <= 0)
            {
                if (children[i - 1] < children[i])
                    candy[i] ++;
                else if (children[i - 1] > children[i])
                    candy[i - 1] ++;
                else
                    continue;
                flag = true;
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < candy.size(); i ++)
        sum += candy[i];
    cout << sum << endl;
    return 0;
}

