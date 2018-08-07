#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::copy;
using std::vector;

int main()
{
    vector<int> u(10, 100);
    vector<int> v;
    // v.reserve(10);
    // v.resize(10);
    copy(u.begin(), u.end(), v.begin());

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