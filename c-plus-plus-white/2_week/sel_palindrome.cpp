#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string>      PalindromFilter(vector<string> words, int minLength)
{
    vector<string> palindrome;
    bool is_palindrome;

    for (auto w : words)
    {
        is_palindrome = true;
        if (w.size() >= minLength)
        {
            for (int i = 0; i < w.size() / 2; i++)
            {
                if (w[i] != w[w.size() - i - 1])
                {
                    is_palindrome = false;
                    break;
                }
            }
            if (is_palindrome)
                palindrome.push_back(w);
        }
    }
    return (palindrome);
}
int     main(void)
{
    for ( auto s : PalindromFilter({"madam", "aziza", "Makhmud"}, 4))
    {
        cout << s << endl;
    }
    return (0);
}