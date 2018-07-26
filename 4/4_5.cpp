#include <iostream>
#include <string>
#include <vector>

#include "4_5_funcs.h"

using std::string;
using std::vector;

using std::cin;
using std::cout;
using std::endl;

int main()
{
    vector<string> words;
    read_vector(cin, words);
    word_count(words);
    word_occurrences(words);
    return 0;
}