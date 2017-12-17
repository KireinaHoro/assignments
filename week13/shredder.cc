#include <iostream>
#include <string>
#include <vector>

using namespace std;

int maxSum, ansSum, sum, ansCount;
vector<int> ansPath, path;

void dfs(string str)
{
    if (!str.size())
    {
        if (sum <= maxSum && sum == ansSum)
        {
            ansCount ++;
        }
        else if (sum <= maxSum && sum > ansSum)
        {
            ansCount = 1;
            ansSum = sum;
        }
        ansPath = path;
        return;
    }

    for (int i = str.size() - 1; i >= 0; i --)
    {
        string strLeft = str.substr(0, i);
        string strRight = str.substr(i);
        int left = atoi(strLeft.c_str());
        int right = atoi(strRight.c_str());
        if (sum + right > maxSum)
            continue;
        if (ansSum == maxSum && ansCount > 1)
            break;
        sum += right;
        path.push_back(right);

        dfs(strLeft);

        sum -= right;
        path.pop_back();
    }
}

int main()
{
    string str;
    cin >> maxSum >> str;

    while (maxSum || str.size() != 1 || str[0] - '0')
    {
        int num = atoi(str.c_str());
        if (num <= maxSum)
            cout << num << ' ' << num << endl;
        else
        {
            sum = 0;
            path.clear();
            ansSum = -1;
            dfs(str);
            if (ansSum == -1)
                cout << "error" << endl;
            else if (ansCount > 1)
                cout << "rejected" << endl;
            else
            {
                cout << ansSum;
                for (int i = ansPath.size() - 1; i >= 0; i --)
                    cout << ' ' << ansPath[i];
                cout << endl;
            }
        }
        cin >> maxSum >> str;
    }
    return 0;
}

