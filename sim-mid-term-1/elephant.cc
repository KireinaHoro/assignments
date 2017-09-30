#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.14159;

int main()
{
    int h, r;
    cin >> h >> r;
    cout << ceil(20000 / (pow(static_cast<double>(r), 2) * PI * h)) << endl;
    return 0;
}

