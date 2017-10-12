#include <iostream>
#include <algorithm>
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
    int option;
    cin >> option;
    for(int i = 81; i < 343; i ++)
    {
        string seven = convert_from_decimal(i, 7);
        string nine = convert_from_decimal(i, 9);
        string temp = nine;
        reverse(temp.begin(), temp.end());
        if(seven == temp)
            switch(option)
            {
                case 1:
                    cout << i << endl;
                    break;
                case 2:
                    cout << seven << endl;
                    break;
                case 3:
                    cout << nine << endl;
                    break;
            }
    }

    return 0;
}

