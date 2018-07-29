#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

using std::string;

bool has_ascenders(const string&);
bool has_descenders(const string&);

int main()
{
    string x;
    string longest;
    while (cin >> x)
    {   
        if (!has_ascenders(x) && !has_descenders(x)) {
            cout << x << " doesn't have any descenders or ascenders" << endl;

            if (x.size() > longest.size()) {
                longest = x;
            }
        }
    }

    if (longest.size() == 0) {
        cout << "all the words had an ascender or a descender ..." << endl;
        return 1;
    }
    cout << "longest word without any descenders or ascenders is: "
         << longest << endl;

    return 0;
}

bool has_ascenders(const string& word)
{
    for (string::const_iterator iter = word.begin(); iter != word.end(); ++iter)
    {
        if (   *iter == 'b'
            || *iter == 'd'
            || *iter == 'f'
            || *iter == 'h'
            || *iter == 'k'
            || *iter == 'l') {
                return true;
            }
    }
    return false;
}

bool has_descenders(const string& word)
{
    for (string::const_iterator iter = word.begin(); iter != word.end(); ++iter)
    {
        if (   *iter == 'g'
            || *iter == 'j'
            || *iter == 'p'
            || *iter == 'q'
            || *iter == 'y') {
                return true;
            }
    }
    return false;
}
