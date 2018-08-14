#include "xref.h"

using std::istream;
using std::map;
using std::string;
using std::vector;

map<string, vector<int> >
    xref(istream& in, vector<string> (*find_words)(const string& s) = split)
{
    string line;
    int lineNumber = 0;
    map<string, vector<int> > ret;

    while (getline(in, line))
    {
        ++lineNumber;

        vector<string> words = find_words(line);

        for (vector<string>::const_iterator it = words.begin(); it != words.end(); ++it)
        {
            ret[*it].push_back(lineNumber);
        }
    }

    return ret;
}