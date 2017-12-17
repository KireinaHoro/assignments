#include <iostream>
#include <iomanip>
#include <cmath>

const double eps = 1e-6;

using namespace std;

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap(double *a, double *b)
{
    double tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort3(int *x, int *y, int *z)
{
    if (*x > *y)
        swap(x, y);
    if (*y > *z)
        swap(y, z);
    if (*x > *y)
        swap(x, y);
}

void sort3(double *x, double *y, double *z)
{
    if (*x > *y)
        swap(x, y);
    if (*y > *z)
        swap(y, z);
    if (*x > *y)
        swap(x, y);
}

int main()
{
    double a, b, c;
    char comma;
    cin >> a >> comma >> b >> comma >> c; 
    sort3(&a, &b, &c);
    if (abs((int) a - a) < eps)
        cout << (int)a;
    else
        cout << fixed << setprecision(2) << a;
    if (abs((int) b - b) < eps)
        cout << ',' << (int)b;
    else
        cout << ',' << fixed << setprecision(2) << b;
    if (abs((int) c - c) < eps)
        cout << ',' << (int)c;
    else
        cout << ',' << fixed << setprecision(2) << c;
    cout << endl;
    return 0;
}

