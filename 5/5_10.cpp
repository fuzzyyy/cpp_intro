#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

using std::string;
using std::vector;

bool is_palindrome(const string&);

int main()
{
    vector<string> words;
    string x;
    while (cin >> x)
    {
        words.push_back(x);
    }

    vector<string> palindromes;
    for (vector<string>::const_iterator iter = words.begin(); iter != words.end(); ++iter)
    {
        if (is_palindrome(*iter)) {
            cout << *iter << endl;
            palindromes.push_back(*iter);
        }
    }

    if (words.size() == 0) {
        cout << "please input some words" << endl;
        return 1;
    }

    string longest;
    for (vector<string>::const_iterator iter = palindromes.begin(); iter != palindromes.end(); ++iter)
    {
        if (iter->size() > longest.size()) {
            longest = *iter;
        }
    }
    if (longest.size() == 0) {
        longest = "there weren't any palindromes! :D";
    }
    cout << "the longest palindrome is: " << longest << endl;

    return 0;
}

bool is_palindrome(const string& word)
{
    string::size_type half = word.size() / 2;
    for (string::size_type i = 0; i < half; ++i)
    {
        if (word[i] != word[word.size() - 1 - i]) {
            return false;
        }
    }

    return true;
}
