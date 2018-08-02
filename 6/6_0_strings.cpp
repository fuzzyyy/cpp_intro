#include <iostream>
#include <string>
#include <vector>

#include "string_utils.h"
#include "strvect_utils.h"

using std::string;
using std::vector;

using std::cout;
using std::cin;
using std::endl;

int main()
{
    string testSplit = "test the split";
    vector<string> vecSplit = split(testSplit);

    print_vect(vecSplit);

    if (is_palindrome("asdfdsa")) {
        cout << "jupiii, asdfdsa je palindrom" << endl;
    }
    if (is_palindrome("dddd")) {
        cout << "juchuu, dddd je palindrom" << endl;
    }

    string testURL = "aff htp://kapppa.com sfdajdsf as f http://google.com";
    string testURL2 = "h://goo.com asdf ht://s";
    vector<string> urls = find_urls(testURL);
    print_vect(urls);
    urls = find_urls(testURL2);
    print_vect(urls);

    return 0;
}