#include <iostream>
#include <cstdio>

double notation()
{
    char str[10];
    std::cin >> str;
    switch(str[0])
    {
        case '+':
            return notation() + notation();
        case '-':
            return notation() - notation();
        case '*':
            return notation() * notation();
        case '/':
            return notation() / notation();
        default:
            return atof(str);
    }
}

int main()
{
    double ans = notation();
    printf("%f\n", ans);
    return 0;
}

