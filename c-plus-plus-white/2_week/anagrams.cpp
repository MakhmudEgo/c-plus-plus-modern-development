#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

bool    BuildCharCounters(const vector<string> &words)
{
    vector<map<char, int>> ann(2);
    for (int i = 0; i < words.size(); ++i)
    {
        for (auto a : words[i])
            ++ann[i][a];
    }
    for (auto a : ann[0])
    {
        if (ann[0][a.first] != ann[1][a.first])
            return  (false);
    }
    return (true);
}

int     main(void)
{
    int amount_command;
    cin >> amount_command;
    vector<string> words(2);

    for (int i = 0; i < amount_command; ++i) {
        cin >> words[0] >> words[1];
        if (words[0].size() == words[1].size() && BuildCharCounters(words))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return (0);
}