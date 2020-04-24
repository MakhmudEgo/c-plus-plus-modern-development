#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int     main(void) {
    const vector<string> qwebus_stodps = {"NEW_BUS", "BUSES_FOR_STOP", "STOPS_FOR_BUS", "ALL_BUSES"};
    int amount_command;
    cin >> amount_command;
    string stop;
    string bus;
    string command;
    map<string, vector<string>> bus_stops;
    int amount_stops;

    for (int i = 0; i < amount_command; ++i) {
        cin >> command;
        if (command == "NEW_BUS") {
            cin >> bus >> amount_stops;
            for (int j = 1; j < amount_stops; ++j) {
                cin >> stop;
                bus_stops[bus].push_back(stop);
            }
        } else if (command == "ALL_BUSES") {
            if (bus_stops.empty())
                cout << "No buses" << endl;
            else {
                for (auto &item : bus_stops)
                {
                    cout << "Bus " << item.first << ": ";
                    for (auto &i : item.second)
                        cout << i << " ";
                    cout << endl;
                }
            }
        } else if (command == "STOPS_FOR_BUS") {
            cin >> bus;
            if (bus_stops.count(bus))
                cout << "No buses" << endl;
            else {

            }
        }
    }
}