#include "string_utils.h"

#include <iostream>
#include <iterator>
#include <string>

using namespace std;

int main()
{
    string s;
    while (getline(cin, s))
    {
        split(s, ostream_iterator<string>(cout, "\n"));
    }
}
