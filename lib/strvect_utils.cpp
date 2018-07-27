#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::endl;

void print_vect(const vector<string>& vec)
{
    for (vector<string>::const_iterator iter = vec.begin(); iter != vec.end(); iter++)
    {
        cout << *iter << endl;
    }
}