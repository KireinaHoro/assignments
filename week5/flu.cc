#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    const char EMPTY='#', HEALTHY='.', INFECTED='@';
    int n, m;
    cin >> n;
    vector<vector<char> > room(n, vector<char>(n));
    for(int i = 0; i < n; i ++)
    {
        string input;
        cin >> input;
        istringstream is(input);
        for(int j = 0; j < n; j ++)
            is >> room[i][j];
    }
    cin >> m;
    while(--m)
    {
        vector<vector<char> > temp = room;
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++)
                if(temp[i][j] == INFECTED)
                {
                    if(j - 1 >= 0)
                        room[i][j - 1] != EMPTY ? room[i][j - 1] = INFECTED : ' ';
                    if(j + 1 <= n - 1)
                        room[i][j + 1] != EMPTY ? room[i][j + 1] = INFECTED : ' ';
                    if(i + 1 <= n - 1)
                        room[i + 1][j] != EMPTY ? room[i + 1][j] = INFECTED : ' ';
                    if(i - 1 >= 0)
                        room[i - 1][j] != EMPTY ? room[i - 1][j] = INFECTED : ' ';
                }
    }
    int ans = 0;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            room[i][j] == INFECTED ? ans ++ : 0;
    /*
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < n; j ++)
            cout << room[i][j];
        cout << endl;
    }
    */
    cout << ans << endl;
    return 0;
}

