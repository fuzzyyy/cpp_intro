#ifndef GUARD_grammar_h
#define GUARD_grammar_h

#include "random.h"
#include "string_utils.h"

#include <iostream>
#include <list>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>

typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Rule_collection;
typedef std::map<std::string, Rule_collection> Grammar;

Grammar read_grammar(std::istream&);
std::vector<std::string> gen_sentence(const Grammar&);
std::list<std::string> gen_sentence_list(const Grammar&);
std::vector<std::string> gen_sentence_nonrecursive(const Grammar&);

template<class OutputIterator>
OutputIterator gen_sentence(const Grammar& g, OutputIterator dest)
{
    std::vector<std::string> stack;

    stack.push_back("<sentence>");

    while (!stack.empty())
    {
        std::string token = stack.back();
        stack.pop_back();

        if (!bracketed(token))
        {
            *dest++ = token;
        }
        else
        {
            Grammar::const_iterator iter = g.find(token);

            if (iter == g.end())
            {
                throw std::logic_error("empty rule");
            }

            Rule_collection coll = iter->second;
            Rule rule            = coll[nrand(coll.size())];

            stack.insert(stack.end(), rule.rbegin(), rule.rend());
        }
    }

    return dest;
}
#endif
