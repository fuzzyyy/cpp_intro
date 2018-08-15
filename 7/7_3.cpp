#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "xref.h"

using std::cin;
using std::cout;
using std::map;
using std::string;
using std::vector;

int main()
{
    map<string, vector<int> > xrefs = xref(cin);

    for (map<string, vector<int> >::const_iterator it = xrefs.begin(); it != xrefs.end(); ++it)
    {
        cout << it->first << "\t" << it->second[0];

        for (vector<int>::const_iterator itt = it->second.begin() + 1; itt != it->second.end(); ++itt)
        {
            cout << ", " << *itt;
        }

        cout << "\n";
    }

    return 0;
}
