#include <iostream>
#include <set>
using namespace std;

int     main(void) {
    int amount_command;
    cin >> amount_command;
    set<string> uni_rows;
    string str;
    for (int i = 0; i < amount_command; ++i) {
        cin >> str;
        uni_rows.insert(str);
    }
    cout << uni_rows.size() << endl;
    return (0);
}