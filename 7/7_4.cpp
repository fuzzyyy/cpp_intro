#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "xref.h"
#include "string_utils.h"

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;

int digits(int);

int main()
{
    map<string, vector<int> > xrefs = xref(cin);

    const int rowWidth = 80;

    for (map<string, vector<int> >::const_iterator it = xrefs.begin(); it != xrefs.end(); ++it)
    {
        cout << it->first << "\t" << it->second[0];

        int tabs = (it->first.size() / 8) + 1;
        int chars = tabs*8 + digits(it->second[0]);

        for (vector<int>::const_iterator itt = it->second.begin() + 1; itt != it->second.end(); ++itt)
        {
            if (chars + 2 + digits(*itt) > rowWidth) {
                
                cout << endl;
                for (int i = 0; i < tabs; ++i)  { cout << '\t'; }
                cout << *itt;

                chars = tabs*8 + digits(*itt);
            }
            else {
                cout << ", " << *itt;
                chars += 2 + digits(*itt);
            }
        }

        cout << endl;
    }

    return 0;
}

int digits(int n)
{
    int ret = 0;
    while (n > 0)
    {
        n /= 10;
        ++ret;
    }

    return ret;
}
