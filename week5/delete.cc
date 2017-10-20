#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int n, num;
    cin >> n;
    vector<int> ns(n);
    for(int i = 0; i < n; i ++)
        cin >> ns[i];
    cin >> num;
    for(int i = 0; i < n; i ++)
        if(num == ns[i])
        {
            for(int j = i; j < n - 1; j ++)
                swap(ns[j], ns[j + 1]);
            i --;
            n --;
        }
    cout << ns[0];
    for(int i = 1; i < n; i ++)
        cout << ' ' << ns[i];
    cout << endl;
    return 0;
}

