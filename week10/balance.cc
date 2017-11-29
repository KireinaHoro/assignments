#include <limits>
#include <cstdlib>
#include <iostream>

using namespace std;

const int N = 10;
int sum[N][N];
int a[N][N];
int maxsum, maxmin;

void maxcolsum(int l, int n)
{
    int i, j, t;
    for(i = 0; i < n; i ++)
    {
        for(j = 0; j < n; j ++)
            sum[l][j] = sum[l - 1][j] + a[l][j];
        if(l < n - 1)
            maxcolsum(l + 1, n);
        else
        {
            maxsum = sum[l][0];
            for(j = 1; j < n; j ++)
                if(maxsum < sum[l][j])
                    maxsum = sum[l][j];
            if(maxmin > maxsum)
                maxmin = maxsum;
        }
        t = a[l][0];
        for(j = 0; j < n - 1; j ++)
            a[l][j] = a[l][j + 1];
        a[l][n - 1] = t;
    }
}

int main(int argc, char *argv[])
{
    int i, j, sum0;
    int n;
    while(true)
    {
        cin >> n;
        if(n == -1)
            break;
        for(i = 0; i < n; i ++)
            for(j = 0; j < n; j ++)
                cin >> a[i][j];
        sum0 = 0;
        for(i = 0; i < n; i ++)
        {
            sum0 += a[i][0];
            sum[0][i] = a[0][i];
        }
        maxsum = sum0;
        maxmin = numeric_limits<int>::max();
        maxcolsum(1, n);
        cout << maxmin << endl;
    }
    return EXIT_SUCCESS;
}

