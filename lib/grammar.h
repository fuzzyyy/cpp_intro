#ifndef GUARD_grammar_h
#define GUARD_grammar_h

#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>

typedef std::vector<std::string> Rule;
typedef std::vector<Rule> Rule_collection;
typedef std::map<std::string, Rule_collection> Grammar;

Grammar read_grammar(std::istream&);
std::vector<std::string> gen_sentence(const Grammar&);
std::list<std::string> gen_sentence_list(const Grammar&);
#endif
