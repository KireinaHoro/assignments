//
//  main.cpp
//  loop_number
//
//  Created by Johnson Steward on 2017/12/28.
//  Copyright © 2017年 JSteward Tech. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

string mod_add(string a, string b)
{
    int len = a.size();
    string ans;
    bool shift = false;
    for (int i = len - 1; i >= 0; i --)
    {
        char tmp = a[i] - '0' + b[i] - '0' + shift;
        shift = false;
        if (tmp > 9)
        {
            shift = true;
            tmp -= 10;
        }
        tmp += '0';
        ans.push_back(tmp);
    }
    if (ans.size() > len)
        //ans.pop_back();
        ans.erase(ans.end() - 1);
    reverse(ans.begin(), ans.end());
    return ans;
}

string mod_multiply(string a, int b)
{
    string ans(a);
    for (int i = 0; i < b - 1; i ++)
        ans = mod_add(ans, a);
    return ans;
}

int main()
{
    string input;
    while (getline(cin, input))
    {
        int i = 0;
        string tmp(input), mod(input.size(), '9');
        //cout << input.size() << endl;
        while (i ++ <= input.size())
        {
            if ((tmp = mod_add(tmp, input)) == mod)
                goto succeeded;
        }
        cout << input << " is not cyclic" << endl;
        continue;
    succeeded:
        cout << input << " is cyclic" << endl;
    }
    return 0;
}

