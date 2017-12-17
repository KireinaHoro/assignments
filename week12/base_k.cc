#include <iostream>
#include <string>

using namespace std;

struct BaseK
{
    int base;
    string cont;

    BaseK(int a, string b) : base(a), cont(b) {}

    void inc()
    {
        if(*(cont.end() - 1) - '0' + 1 == base)
        {
            if(cont.size() == 1)
                cont = "10";
            else
            {
                string a = cont;
                a.erase(a.end() - 1);
                BaseK inter(base, a);
                inter.inc();
                cont = inter.cont + "0";
            }
        }
        else
        {
            cont[cont.size() - 1] ++;
        }
    }
};

int main()
{
    int k, m;
    char tmp;
    string s;
    cin >> k >> tmp >> m >> tmp >> s;
    BaseK a(k, s);
    int counter = 0;
    for(int i = 0; i < m; i ++)
    {
        a.inc();
        cout << a.cont;
        if(counter == 4 || i == m - 1)
        {
            counter = -1;
            cout << endl;
        }
        else
            cout << ',';
        counter ++;
    }
    return 0;
}


