#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int NUM = 3;

class Student
{
    private:
        int id, score;

    public:
        Student() { id = 0; score = 0; }
        Student(int _id, int _score_math, int _score_chinese) : id(_id) { score = _score_math + _score_math; }

        friend istream& operator>>(istream&, Student&);
        friend ostream& operator<<(ostream&, const Student&);
        bool operator>(const Student&) const;
};

istream& operator>>(istream& is, Student& stu)
{
    int score_math, score_chinese;
    cin >> stu.id >> score_math >> score_chinese;
    stu.score = score_math + score_chinese;
    return is;
}

ostream& operator<<(ostream& os, const Student& stu)
{
    cout << stu.id << ' ' << stu.score;
    return os;
}

bool Student::operator>(const Student& b) const
{
    return score > b.score;
}

int main()
{
    int n;
    cin >> n;
    vector<Student> students;
    for(int i = 0; i < n; i ++)
    {
        Student temp;
        cin >> temp;
        students.push_back(temp);
    }
    stable_sort(students.begin(), students.end(), greater<Student>());
    for(int i = 0; i < NUM; i ++)
        cout << students[i] << endl;
    return 0;
}

