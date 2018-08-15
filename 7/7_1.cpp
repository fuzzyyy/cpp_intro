#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

#include "strvect_utils.h"

using std::sort;
using std::cin;
using std::cout;
using std::map;
using std::pair;
using std::string;
using std::vector;

bool compare(pair<const string, int> a, pair<const string, int> b)
{
    return a.second < b.second;
}

int main()
{
    string s;
    map<string, int> counters;
    while (cin >> s)
    {
        ++counters[s];
    }

    map<int, vector<string> > reversed;
    for (map<string, int>::const_iterator it = counters.begin(); it != counters.end(); ++it)
    {
        reversed[it->second].push_back(it->first);
    }

    for (map<int, vector<string> >::const_iterator it = reversed.begin(); it != reversed.end(); ++it)
    {
        cout << it->first << ": ";
        print_vect(it->second);
    }

    return 0;
}