#include "median.h"

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int i;
    vector<double> ii;
    while (cin >> i)
    {
        ii.push_back(i);
    }
    cout << median(ii) << endl;

    return 0;
}