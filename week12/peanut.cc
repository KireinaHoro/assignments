#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

const int FAILED = 0x3f3f3f3f;

struct Point
{
    Point(int x, int y, int count) : x(x), y(y), count(count) {}

    int x, y;
    int count;
};

bool operator <(Point a, Point b)
{
    return a.count > b.count;
}

int dist(Point a, Point b)
{
    return abs(a.x - b.x) + abs(a.y - b.y);
}

vector<Point> points;

int pick(vector<Point>::const_iterator it, int time_left)
{
    if (time_left < it->y + 2)
        return FAILED;
    if (it == points.end())
        return 0;
    if (it == points.begin())
    {
        int rest = pick(it + 1, time_left - (it->y + 1) - (dist(*it, *(it + 1)) + 1));
        if (rest != FAILED)
            return it->count + rest;
        else
        {
            if (time_left >= 2 * it->y + 3)
                return it->count;
            else
                return 0;
        }
    }
    int inter = pick(it + 1, time_left - (dist(*it, *(it + 1)) + 1));
    if (inter == FAILED)
        return it->count;
    else
        return it->count + inter;
}

int main()
{
    int n;
    cin >> n;
    while(n --)
    {
        int rows, cols, max_t;
        cin >> rows >> cols >> max_t;
        for (int i = 0; i < rows; i ++)
            for (int j = 0; j < cols; j ++)
            {
                int tmp;
                cin >> tmp;
                if (tmp)
                    points.push_back(Point(j, i, tmp));
            }
        sort(points.begin(), points.end());
        cout << pick(points.begin(), max_t) << endl;
        points = vector<Point>();
    }
    return 0;
}


