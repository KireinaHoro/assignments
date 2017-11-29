#include <iostream>

using namespace std;

int put(int M, int N)
{
    if(M == 0)
        return 1;
    if(N == 0)
        return 0;
    if(M < N)
        return put(M, N - 1);
    return put(M - N, N) + put(M, N - 1);
}

int main()
{
    int n;
    cin >> n;
    while(n --)
    {
        int M, N;
        cin >> M >> N;
        cout << put(M, N) << endl;
    }
    return 0;
}

