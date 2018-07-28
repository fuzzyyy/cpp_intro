#include <iostream>
#include <string>
#include <vector>

#include "frame.h"
#include "strvect_utils.h"

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    vector<string> words;
    string x;
    while (cin >> x)
    {
        words.push_back(x);
    }

    cout << "list of input words:" << endl;
    print_vect(words);

    cout << "centered:" << endl;
    print_vect(center(words));

    return 0;
}