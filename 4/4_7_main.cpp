#include <iostream>
#include <vector>

#include "4_7_average.h"

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    double x;
    vector<double> vec;
    while (cin >> x)
    {
        vec.push_back(x);
    }

    cout << "average = " << average(vec) << endl;

    return 0;
}