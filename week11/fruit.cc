#include <iostream>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

const char fruits[][15] =
{
    "apples", "bananas", "peaches", "cherries",
    "pears", "oranges", "strawberries"
};

const char brussels[] = "Brussels sprouts";

int main()
{
    string line;
    while (getline(cin, line))
    {
        char *li = new char[line.size() + 1];
        strcpy(li, line.c_str());
        char *tok = strtok(li, " ");
        bool flag = false;
        vector<string> ans;
        while (tok != NULL)
        {
            bool onetime = false;
            //tok[strlen(tok)] = '\0';
            int i;
            for (i = 0; i < 7; i ++)
            {
                if (strstr(tok, fruits[i]) != NULL)
                {
                    onetime = true;
                    flag = true;
                }
                if (onetime)
                    break;
            }
            if (onetime)
            {
                string aa = string(brussels);
                if (strcmp(tok, fruits[i]))
                    aa += tok[strlen(tok) - 1];
                ans.push_back(aa);
            }
            else
                ans.push_back(string(tok));
            tok = strtok(NULL, " ");
        }
        if (flag)
        {
            cout << ans[0];
            for (int i = 1; i < ans.size(); i ++)
                cout << ' ' << ans[i];
            cout << endl;
        }
        else
            cout << "You must not enjoy fruit." << endl;
    }
    return 0;
}


