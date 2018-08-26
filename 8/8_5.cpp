#include "grammar.h"
#include "strvect_utils.h"

#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <string>
#include <vector>

using std::back_inserter;
using std::cin;
using std::cout;
using std::list;
using std::string;
using std::vector;

int main()
{
    Grammar g = read_grammar(cin);
    list<string> sent;
    gen_sentence(g, back_inserter(sent));

    for (list<string>::const_iterator i = sent.begin(); i != sent.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << "\n";

    return 0;
}
