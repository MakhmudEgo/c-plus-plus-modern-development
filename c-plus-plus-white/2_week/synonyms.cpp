#include <iostream>
#include <set>
#include <string>
using namespace std;

void    add_synonyms(set<set<string>>& synonyms) {
    string word1, word2;
    cin >> word1 >> word2;
    synonyms.insert({word1, word2});
}

int    count_synonyms(const set<set<string>>& synonyms) {
    int n = 0;
    string word;
    cin >> word;
    for (const auto& item : synonyms) {
        if (item.count(word))
            n++;
    }
    return (n);
}

bool    check_synonyms(const set<set<string>>& synonyms) {
    string word1, word2;
    cin >> word1 >> word2;
    if (synonyms.count({word1, word2}))
        return (true);
    return (false);
}

int     main(void) {
    int num_command;
    cin >> num_command;
    string command;
    set<set<string>> synonyms;
    for (int i = 0; i < num_command; ++i) {
        cin >> command;
        if (command == "ADD")
            add_synonyms(synonyms);
        else if (command == "COUNT")
            cout << count_synonyms(synonyms) << endl;
        else if (command == "CHECK") {
            if (check_synonyms(synonyms))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return (0);
}