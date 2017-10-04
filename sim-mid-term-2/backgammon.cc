#include <iostream>
#include <cstring>

using namespace std;

const int max_size = 100;

int board[max_size][max_size];

void print(int size)
{

    for(int i = 0; i < size; i ++)
    {
        for(int j = 0; j < size; j ++)
            cout << board[i][j] << '\t';
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int size, step, win = 0, used_step = 0;
    bool turn = 1;
    cin >> size >> step;
    while(step --)
    {
        int x, y;
        cin >> x >> y;
        if(turn)
            board[x][y] = 1;
        else
            board[x][y] = -1;
        used_step ++;
//        print(size);
        int up_border = (x < 4) ? 0 : x - 4;
        int down_border = (x > size - 5) ? (size - 1) : (x + 4);
        int left_border = (y < 4) ? 0 : y - 4;
        int right_border = (y > size - 5) ? (size - 1) : (y + 4);
        int sum = 0;
        for(int i = up_border; i + 4 <= down_border; i ++)
        {
            for(int k = 0; k < 5; k ++)
                sum += board[i + k][y];
            if((turn && sum == 5) || (!turn && sum == -5))
                goto win;
            sum = 0;
        }
        for(int i = left_border; i + 4 <= right_border; i ++)
        {
            for(int k = 0; k < 5; k ++)
                sum += board[x][i + k];
            if((turn && sum == 5) || (!turn && sum == -5))
                goto win;
            sum = 0;
        }
        for(int i = min(left_border - y, up_border - x); i + 4 <= min(right_border - y, down_border - x); i ++)
        {
            for(int k = 0; k < 5; k ++)
                sum += board[x + i + k][y + i + k];
            if((turn && sum == 5) || (!turn && sum == -5))
                goto win;
            sum = 0;
        }
        for(int i = min(x - down_border, left_border - y); i + 4 <= min(x - up_border, right_border - y); i ++)
        {
            for(int k = 0; k < 5; k ++)
                sum += board[x - i - k][y + i + k];
            if((turn && sum == 5) || (!turn && sum == -5))
                goto win;
            sum = 0;
        }

        turn ^= 1;
    }
win:
    cout << used_step << ' ' << (!turn) << endl;
    return 0;
}

