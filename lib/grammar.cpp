#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>

#include "grammar.h"
#include "random.h"
#include "string_utils.h"

using std::istream;
using std::logic_error;
using std::map;
using std::string;
using std::vector;

Grammar read_grammar(istream& in)
{
    Grammar ret;
    string line;

    while (getline(in, line))
    {
        vector<string> entry = split(line);
        if (!entry.empty()) {
            ret[entry[0]].push_back( Rule(entry.begin() + 1, entry.end()) );
        }
    }

    return ret;
}

void gen_aux(const Grammar& g, const string& word, vector<string>& ret)
{
    if (!bracketed(word)) {
        ret.push_back(word);
    }
    else {
        Grammar::const_iterator it = g.find(word);

        if (it == g.end()) {
            throw logic_error("empty rule");
        }

        const Rule_collection& c = it->second;
        const Rule& r = c[nrand(c.size())];

        for (Rule::const_iterator iter = r.begin(); iter != r.end(); ++iter)
        {
            gen_aux(g, *iter, ret);
        }

    }
}

vector<string> gen_sentence(const Grammar& g)
{
    vector<string> ret;
    gen_aux(g, "<sentence>", ret);
    return ret;
}
