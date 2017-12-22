#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> dict;
vector<int> used;
string unmatched, temp, ans, temp_ans;
bool orig;

void search()
{
    for (int i = 0; i < dict.size(); i ++)
    {
        if (used[i] == 2)
            continue;
        if (unmatched == dict[i])
        {
            if (unmatched == temp)
                continue;
            orig = !orig;
            if (orig)
                temp = temp + dict[i];
            temp_ans = temp;
            if (temp_ans.size() < ans.size())
                ans = temp_ans;
            else if (temp_ans.size() == ans.size())
                if (temp_ans < ans)
                    ans = temp_ans;
            orig = !orig;
        }
        else if (!unmatched.find(dict[i]))
        {
            orig = !orig;
            used[i] ++;
            string temp_store = temp;
            string unmatched_store = unmatched;
            if (orig)
                temp = temp + dict[i];
            unmatched = unmatched.substr(dict[i].size());
            search();
            orig = !orig;
            used[i] --;
            temp = temp_store;
            unmatched = unmatched_store;
        }
        else if (!dict[i].find(unmatched))
        {
            orig = !orig;
            used[i] ++;
            string temp_store = temp;
            string unmatched_store = unmatched;
            if (orig)
                temp = temp + dict[i];
            unmatched = dict[i].substr(unmatched.size());
            search();
            orig = !orig;
            used[i] --;
            temp = temp_store;
            unmatched = unmatched_store;
        }
    }
}

int main()
{
    for (int i = 0; i < 400; i ++)
        ans += 'a';
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++)
    {
        string tmp;
        cin >> tmp;
        dict.push_back(tmp);
    }
    for (int i = 0; i < n; i ++)
    {
        used = vector<int>(n, 0);
        orig = true;
        temp = dict[i];
        unmatched = dict[i];
        search();
    }
    cout << ans << endl;
    return 0;
}

