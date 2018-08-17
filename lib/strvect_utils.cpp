#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::endl;

void print_vect(const vector<string>& vec)
{
    if (!vec.empty()) {
        cout << vec[0];

        for (vector<string>::const_iterator iter = vec.begin() + 1; iter != vec.end(); iter++)
        {
            cout << " " << *iter;
        }
    }
    cout << endl;
}