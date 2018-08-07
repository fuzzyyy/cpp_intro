#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using std::cout;
using std::copy;
using std::vector;
using std::back_inserter;
using std::inserter;

int main()
{
    int tmp[] = { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
    vector<int> u(tmp, tmp + sizeof(tmp)/sizeof(tmp[0]));
    vector<int> v;
    copy(u.begin(), u.end(), inserter(v, v.begin()));
    // copy(u.begin(), u.end(), back_inserter(v));

    for (vector<int>::const_iterator i = u.begin(); i != u.end(); ++i)
    {
        cout << *i << "\n";
    }
    cout << "\n\n";
    for (vector<int>::const_iterator i = v.begin(); i != v.end(); ++i)
    {
        cout << *i << "\n";
    }
}