#include <iostream>
#include <list>
#include <map>
#include <string>

#include "grammar.h"

using std::cin;
using std::cout;
using std::list;
using std::string;

int main()
{
    Grammar g = read_grammar(cin);
    list<string> sentence = gen_sentence_list(g);

    if (sentence.empty()) {
        return 0;
    }

    cout << *sentence.begin();

    for (list<string>::const_iterator it = ++sentence.begin(); it != sentence.end(); ++it)
    {
        cout << ' ' << *it;
    }
    cout << '\n';

    return 0;
}
