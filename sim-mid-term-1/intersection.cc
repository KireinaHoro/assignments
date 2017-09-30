#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

template<class ForwardIt>
ForwardIt next(ForwardIt it,
                       typename std::iterator_traits<ForwardIt>::difference_type n = 1)
{
        std::advance(it, n);
            return it;
}

int main()
{
    int read;
    char delimiter;
    vector<set<int> > numbers(2);
    for(int i = 0; i < 2; i ++)
    {
        string line;
        getline(cin, line);
        istringstream iss(line);
        iss >> read;
        numbers[i].insert(read);
//        cout << read << endl;
        while(iss >> delimiter >> read)
        {
            numbers[i].insert(read);
//            cout << read << endl;
        }
//       for(set<int>::const_iterator it = numbers[i].begin(); it != numbers[i].end(); it ++)
//           cout << *it << endl;
    }
//    cout << "Read finished" << endl;
    set<int> intersect;
    set_intersection(numbers[0].begin(), numbers[0].end(),
            numbers[1].begin(), numbers[1].end(),
            inserter(intersect, intersect.begin()));
//    cout << "Intersect finished" << endl;
    set<int>::const_iterator it = intersect.begin(), back = intersect.end();
    if(intersect.size())
        -- back;
    else
    {
        cout << "NULL" << endl;
        return 0;
    }
    for(; it != back; it ++)
        cout << *it << ',';
    cout << *it << endl;
    return 0;
}

