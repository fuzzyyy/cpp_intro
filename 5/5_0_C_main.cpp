#include <iostream>
#include <string>
#include <vector>

#include "frame.h"
#include "strvect_utils.h"

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    vector<string> words;
    string x;
    while (cin >> x)
    {
        words.push_back(x);
    }

    cout << "list of input words:" << endl;
    print_vect(words);

    cout << "framed:" << endl;
    print_vect(frame(words));

    cout << "cats:" << endl;
    print_vect(words);
    cout << endl;
    print_vect(vcat(words, frame(words)));
    cout << endl;
    print_vect(vcat2(words, frame(words)));
    cout << endl;
    vector<string> words2 = words;
    words2.push_back("JAKAPATA");
    words2.push_back("KEKEKE");
    words2.push_back("ASdFsdfasdfjasdf");
    words2.push_back("JDFJ");
    words2.push_back("dsaf");
    print_vect(hcat(words2, frame(words)));
    return 0;
}