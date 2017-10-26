#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<string, int> p_str_int_t;

struct MatchKey
{
    MatchKey(const string& _s) : s(_s) {}
    bool operator()(const p_str_int_t& obj) const
    {
        return obj.first == s;
    }
    private:
        const string& s;
};

int main()
{
    string in;
    getline(cin, in);
    size_t start, end = 0;
    vector<p_str_int_t> words;
    while(end < in.size())
    {
        start = end;
        while(start < in.size() && !(isalpha(in[start]) || in[start] == '\''))
            start ++;
        end = start;
        while(end < in.size() && (isalpha(in[end]) || in[end] == '\''))
            end ++;
        if(end - start != 0)
        {
            string word = string(in, start, end - start);
            vector<p_str_int_t>::iterator it = find_if(words.begin(), words.end(), MatchKey(word));
            if(it == words.end())
                words.push_back(p_str_int_t(word, 1));
            else
                it->second ++;
        }
    }
    for(vector<p_str_int_t>::const_iterator it = words.begin(); it != words.end(); it ++)
        cout << it->first << ' ' << it->second << endl;
    return 0;
}

