#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int     main(void) {
    int num_bus = 0;
    int num_command;
    cin >> num_command;
    map<int, set<string>> buses;
    int num_stops;
    string stop;
    for (int i = 0; i < num_command; ++i) {
        cin >> num_stops;
        set<string> stops;
        for (int j = 0; j < num_stops; ++j) {
            cin >> stop;
            stops.insert(stop);
        }
        bool exist = true;
        for (const auto &item : buses) {
            if (item.second == stops) {
                cout << "Already exists for " << item.first << endl;
                exist = false;
            }
        }
        if (exist) {
            buses[++num_bus] = stops;
            cout << "New bus " << num_bus << endl;
        }
    }
    return (0);
}