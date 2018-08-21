#include "binsearch.h"

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> vec;
    for (int i = 0; i < 10; ++i)
    {
        vec.push_back(i);
    }

    cout << "vector contains '1': "
         << (binary_search(vec.begin(), vec.end(), 1) ? "true" : "false")
         << endl;
    cout << "vector contains '10': "
         << (binary_search(vec.begin(), vec.end(), 10) ? "true" : "false")
         << endl;

    return 0;
}
