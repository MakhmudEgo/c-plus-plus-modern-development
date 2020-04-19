#include <iostream>
#include <string>
using namespace std;

bool    IsPalindrom(string word)
{
    string palindrome;
    for (int i = word.size() - 1; i >= 0; --i)
    {
        palindrome += word[i];
    }
    if (palindrome == word)
        return  (true);
    return (false);
}

int     main(void)
{
    if (IsPalindrom("madam"))
        cout << "this is palindrome" << endl;
    else
        cout << "not is palindrome" << endl;
    return (0);
}