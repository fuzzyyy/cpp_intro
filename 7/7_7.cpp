#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "xref.h"

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
        if (it->second.size() == 1)
        {
            cout << it->first << " occurs on line: " << it->second[0];
        }
        else
        {
            cout << it->first << " occurs on lines: " << it->second[0];           
            int initSpaces = it->first.size() + 17 + 1;
            int chars = initSpaces + digits(it->second[0]);

            for (vector<int>::const_iterator itt = it->second.begin() + 1; itt != it->second.end(); ++itt)
            {
                if (chars + 2 + digits(*itt) > rowWidth) {
                    
                    cout << endl;
                    cout << string(initSpaces, ' ');
                    cout << *itt;

                    chars = initSpaces + digits(*itt);
                }
                else {
                    cout << ", " << *itt;
                    chars += 2 + digits(*itt);
                }
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
