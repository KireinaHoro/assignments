#include <iostream>
#include <cstring>

using namespace std;

const int bill[] = {100, 50, 20, 10, 5, 1};

int main()
{
    int a, count = sizeof(bill) / sizeof(int);
    cin >> a;
    int* ret = (int*)malloc(sizeof(int) * count);
    for(int i = 0; i < count; i ++)
    {
        ret[i] = a / bill[i];
        a -= (ret[i] * bill[i]);
        cout << ret[i] << endl;
    }
    free(ret);
    return 0;
}

