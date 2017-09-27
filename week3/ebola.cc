#include <iostream>
#include <list>
#include <iterator>
#include <cstdio>

using namespace std;

class Patients
{
    private:
        int ttl, size;
        const int life;
    
    public:
        Patients(int l, int s) : life(l), size(s) { ttl = life; }
        Patients* infect(int speed);
        bool age();
        int getSize();
};

Patients* Patients::infect(int speed)
{
    return new Patients(life, speed * size);
}

bool Patients::age()
{
    return (--ttl);
}

int Patients::getSize()
{
    return size;
}


int main()
{
    int n, x, y, k;
    cin >> n >> x >> y >> k;

    list<Patients*> container;

    container.push_back(new Patients(y - 1, n));
    for(int i = 0; i < k - 1; i ++)
    {
//        list<Patients*> original{move(container)};
        list<Patients*> original = container;
        container.clear();
        for(list<Patients*>::const_iterator it = original.begin(), end = original.end(); it != end; it ++)
        {
//            getchar();
            if((*it)->age())
            {
                container.push_back(*it);
//                cout << "size: " << (*it)->getSize() << endl;
                container.push_back((*it)->infect(x));
//                cout << "size: " << (*it)->infect(x)->getSize() << endl;
            }
        }
//        cout << "----- day " << i + 1 << " finished -----" << endl;
    }
    int sum = 0;
    for(list<Patients*>::const_iterator it = container.begin(), end = container.end(); it != end; it ++)
        sum += (*it)->getSize();
    
    cout << sum << endl;
    return 0;

}


/*
int main()
{
    cout << Patients(4, 5).infect(3)->getSize() << endl;
    return 0;
}

*/
