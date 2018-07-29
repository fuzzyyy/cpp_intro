#include <cctype>
#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;

using std::vector;
using std::string;

bool is_lowercase(const string&);
bool is_uppercase(const string&);

int main()
{
    string x;
    vector<string> words;
    while (cin >> x)
    {
        words.push_back(x);
    }

    cout << "lowercase:" << endl;
    for (vector<string>::const_iterator iter = words.begin(); iter != words.end(); ++iter)
    {
        if (is_lowercase(*iter)) {
            cout << *iter << endl;
        }
    }

    cout << "UPPERCASE:" << endl;
    for (vector<string>::const_iterator iter = words.begin(); iter != words.end(); ++iter)
    {
        if (is_uppercase(*iter)) {
            cout << *iter << endl;
        }
    }
    return 0;
}

bool is_lowercase(const string& str)
{
    for (string::const_iterator iter = str.begin(); iter != str.end(); ++iter)
    {
        if (isupper(*iter)) {
            return false;
        }
    }

    return true;
}

bool is_uppercase(const string& str)
{
    for (string::const_iterator iter = str.begin(); iter != str.end(); ++iter)
    {
        if (islower(*iter)) {
            return false;
        }
    }

    return true;
}
