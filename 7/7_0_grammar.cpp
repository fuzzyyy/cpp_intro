#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "grammar.h"
#include "strvect_utils.h"

using std::cin;
using std::cout;

int main()
{
    Grammar g = read_grammar(cin);
    print_vect(gen_sentence(g));

    return 0;
}
