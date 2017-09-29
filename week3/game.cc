#include <iostream>
#include <vector>

using namespace std;

bool isSeven(int a)
{
    if(a % 10 == 7 || (a / 10) % 10 == 7 || a % 7 == 0)
        return true;
    return false;
}

int main()
{
    int n;
    cin >> n;
    int count = n;
    vector<int> students(n);
    vector<int>::iterator it;
    int i, p;
    for(it = students.begin(), i = 1, p = 1; p <= 10 * n; p ++)
    {
        if(*it == -1) { it ++, p --; /* cout << "HIT" << endl; */ goto next; }
        if(count == 1 && *it != -1) { cout << distance(students.begin(), it) + 1 << endl; break; }
        if(isSeven(i))
        {
            cout << distance(students.begin(), it) + 1 << endl;
//            cout << "DEBUG *it " << *it << endl;
            *(it++) = -1;
//            cout << "DEBUG *it " << *it << endl;
            i ++;
            count --;
            goto next;
        }
        *(it++) = (i++);
next:
        if(it == students.end()) { it = students.begin(); /* cout << "CHANGED" << endl; */ }
//        cout << "DEBUG p " << p << endl;
//        cout << "DEBUG i " << i << endl;
//        cout << "DEBUG it " << distance(students.begin(), it) + 1 << endl;
    }
    return 0;
}

