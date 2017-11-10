#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

bool match(char *rule, char *string)
{
    if(*string == '\0' || *rule == '\0')
    {
        if(*string == '\0' && *rule == '\0')
            return true;
        else
            if(*rule == '*' && match(++ rule, string))
                return true;
            else
                return false;
    }
    switch(*rule)
    {
        case '?':
            return match(++ rule, ++ string);
        case '*':
            if(!(*(rule + 1)))
                return true;
//            while(!match(rule + 1, string ++) && *string != '\0');
            while(*string)
                if(match(rule + 1, string ++))
                    return true;
            return false;
        default:
            return (*rule == *string) && match(++ rule, ++ string);
    }
}

int main()
{
    char *rule = NULL, *string = NULL;
    size_t nb_a = 0, nb_b = 0;
    getline(&rule, &nb_a, stdin);
    getline(&string, &nb_b, stdin);
    rule[strlen(rule) - 1] = '\0';
    string[strlen(string) - 1] = '\0';
    cout << (match(rule, string) ? "matched" : "not matched") << endl;
    return 0;
}

