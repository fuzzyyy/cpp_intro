#include <cassert>
#include <iostream>
#include <list>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>

#include "grammar.h"
#include "random.h"
#include "string_utils.h"

#include "strvect_utils.h"
using std::cout;

using std::istream;
using std::list;
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

void gen_aux(const Grammar& g, const string& word, list<string>& ret)
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

list<string> gen_sentence_list(const Grammar& g)
{
    list<string> ret;
    gen_aux(g, "<sentence>", ret);
    return ret;
}

vector<string> gen_sentence_nonrecursive(const Grammar& g)
{
    vector<string> sentence;
    vector<string> stack;

    stack.push_back("<sentence>");
    
    while (!stack.empty())
    {
        string token = stack.back();
        stack.pop_back();

        if (!bracketed(token)) {
            sentence.push_back(token);
        } else {
            Grammar::const_iterator iter = g.find(token);
            
            if (iter == g.end()) {
                throw logic_error("empty rule");
            }

            Rule_collection coll = iter->second;
            Rule rule = coll[nrand(coll.size())];

            stack.insert(stack.end(), rule.rbegin(), rule.rend());
        }
    }

    return sentence;
}
