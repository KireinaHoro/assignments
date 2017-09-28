#include <iostream>
#include <utility>
#include <vector>
#include <iterator>

using namespace std;
//using point = pair<int, int>;
typedef pair<int, int> point;

double det(point a, point b)
{
//    return get<0>(a) * get<1>(b) - get<1>(a) * get<0>(b);
    return a.first * b.second - a.second * b.first;
}

point operator-(point a, point b)
{
//    return make_pair(get<0>(a) - get<0>(b), get<1>(a) - get<1>(b));
    return make_pair(a.first - b.first, a.second - b.second);
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
        for(vector<point>::const_iterator it = points.begin(), end = points.end(); it != end; it ++)
        {
            vector<point>::const_iterator n = it;
            advance(n, 1);
            if(n == end) n = points.begin();
            point segment = *n - *it;
            cout << "checking: (" << segment.first << ',' << segment.second << ')' << endl;
            double product = 1;
            for(vector<point>::const_iterator i = points.begin(), e = points.end(); i != e; i ++)
            {
                double temp = det(segment, *n - *i);
                if(*i == *n || *i == *it) continue;
                cout << temp << endl;
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

