#include <iostream>
#include <string>

using namespace std;

int convert_to_decimal(string num, int base)
{
    if(!num.length())
        return 0;
    char a = *(num.end() - 1);
    int tmp;
    if(a >= 'a')
        tmp = 10 + a - 'a';
    else
        tmp = a - '0';
//    cout << "tmp: " << tmp << endl;
    return convert_to_decimal(num.erase(num.length() - 1, 1), base) * base + tmp;
}

string convert_from_decimal(int num, int base)
{
    if(!num)
        return "";
    char tmp;
    int a = num % base;
    if(a >= 10)
        tmp = a + 'a' - 10;
    else
        tmp = a + '0';
    return convert_from_decimal(num / base, base).append(1, tmp);
}

int main()
{
    string a, b;
    int base_a, base_b, base_ans;
    cin >> base_a >> a >> base_b >> b;
    cin >> base_ans;
//    cout << convert_to_decimal(a, base_a) << ' ' << convert_to_decimal(b, base_b) << endl;
    cout << convert_from_decimal(convert_to_decimal(a, base_a) + convert_to_decimal(b, base_b), base_ans);
    return 0;
}

