#include <iostream>
#include <utility>
#include <vector>
#include <iterator>

using namespace std;
using point = pair<int, int>;

double det(point a, point b)
{
    return get<0>(a) * get<1>(b) - get<1>(a) * get<0>(b);
}

point operator-(point a, point b)
{
    return make_pair(get<0>(a) - get<0>(b), get<1>(a) - get<1>(b));
}

int main()
{
    int a, b, c, d, e, f, g, h;
    while(cin >> a >> b >> c >> d >> e >> f >> g >> h)
    {
        vector<point> points;
        points.push_back(make_pair(a, b));
        points.push_back(make_pair(c, d));
        points.push_back(make_pair(e, f));
        points.push_back(make_pair(g, h));
        for(auto it = points.begin(), end = points.end(); it != end; it ++)
        {
            auto n = next(it);
            if(it == end) n = points.begin();
            point segment = *n - *it;
//            cout << "checking: (" << get<0>(segment) << ',' << get<1>(segment) << ')' << endl;
            double product = 1;
            for(auto i = points.begin(), e = points.end(); i != e; i ++)
            {
                double temp = det(segment, *n - *i);
                if(*i == *n || *i == *it) continue;
//                cout << temp << endl;
                product *= temp;
            }
            if(product <= 0)
                goto fail;
        }
        cout << "yes" << endl;
        continue;

fail:
        cout << "no" << endl;
        continue;
    }

    return 0;
}

