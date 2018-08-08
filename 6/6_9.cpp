#include <iostream>
#include <numeric>
#include <string>
#include <vector>

#include "strvect_utils.h"

using std::cout;
using std::cin;
using std::endl;

using std::string;
using std::vector;
using std::accumulate;

int main()
{
    vector<string> input;
    string x;
    while (cin >> x)
    {
        input.push_back(x);
    }
    print_vect(input);
    string catenated = accumulate(input.begin(), input.end(), string());
    cout << "\n" 
        << catenated << "\n";
    return 0;
}