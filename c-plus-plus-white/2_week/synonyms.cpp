#include <iostream>
#include <set>
#include <string>
#include <map>
using namespace std;

int     main(void) {
    int num_command;
    cin >> num_command;
    string word1, word2;
    string command;
    set<set<string>> synonyms;
    map<string, int> num_syn;
    for (int i = 0; i < num_command; ++i) {
        cin >> command;
        if (command == "ADD") {
            cin >> word1 >> word2;
            int tmp = synonyms.size();
            synonyms.insert({word1, word2});
            if (tmp < synonyms.size()) {
                ++num_syn[word1];
                ++num_syn[word2];
            }
        }
        else if (command == "COUNT")
        {
            cin >> word1;
            cout << num_syn[word1] << endl;
        }
        else if (command == "CHECK") {
            cin >> word1 >> word2;
            if (synonyms.count({word1, word2}))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return (0);
}