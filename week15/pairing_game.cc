#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input;
    getline(cin, input);
    string mod(input.size(), '#');
    char boy = input[0];
    char girl = input[input.size() - 1];
    while (input != mod)
    {
        for (int i = 0; i < input.size(); i ++)
        {
            if (input[i] == '#')
                continue;
            for (int j = i + 1; j < input.size(); j ++)
            {
                if (input[j] == '#')
                    continue;
                else if (input[j] == boy)
                    goto unmatched;
                else if (input[j] == girl)
                {
                    input[i] = '#';
                    input[j] = '#';
                    cout << i << ' ' << j << endl;
                    goto matched;
                }
            }
unmatched:
            ;
        }
matched:
        ;
    }
    return 0;
}

