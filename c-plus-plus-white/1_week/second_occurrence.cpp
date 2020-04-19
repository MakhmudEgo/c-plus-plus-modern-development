#include <iostream>
#include <string>
using namespace std;

int     main(void)
{
    string word;
    int n = 0;

    cin >> word;
    for (int i = 0; i < word.size(); ++i)
    {
        if (word[i] == 'f')
            ++n;
        if (n == 2)
        {
            cout << i;
            return 0;
        }
    }
    if (n == 1)
        cout << -1;
    else if (n == 0)
        cout << -2;
    return 0;
}