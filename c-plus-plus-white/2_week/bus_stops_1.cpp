#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

vector<string>      get_stops(const int &amount_stops)
{
    vector<string> result;
    string stop;
    for (int j = 0; j < amount_stops; j++) {
        cin >> stop;
        result.push_back(stop);
    }
    return (result);
}

void    all_buses(vector<map<string, vector<string>>> bus_stops)
{
    if (bus_stops.empty())
        cout << "No buses" << endl;
    else {
        sort(begin(bus_stops), end(bus_stops));
        for (auto &item : bus_stops){
            for (auto &itm : item) {
                cout << "Bus " << itm.first << ": ";
                for (auto &i : itm.second)
                    cout << i << " ";
                cout << endl;
            }
        }
    }
}

bool    exist_buses(const vector<map<string, vector<string>>> &bus_stops, const string &bus) {
    if (bus_stops.empty())
        return (true);
    for (auto &item : bus_stops)
    {
        if (item.count(bus))
            return (false);
    }
    return (true);
}
void    stops_for_bus(vector<map<string, vector<string>>> bus_stops) {
    string bus;
    cin >> bus;
    if (exist_buses(bus_stops, bus))
        cout << "No bus" << endl;
    for (auto item : bus_stops)
    {
        for ( auto itm : item)
        {
            if (itm.first == bus)
            {
                for (auto it : item[bus])
                {
                    cout << "Stop " << it << ": ";
                    bool exist = true;
                    for (auto item_new : bus_stops)
                    {
                        for (auto item_new_item : item_new)
                        {
                            for ( auto i : item_new_item.second) {
                                if (item_new_item.first != bus && i == it)
                                {
                                    exist = false;
                                    cout << item_new_item.first << " ";
                                }
                            }
                        }
                    }
                    if (exist)
                        cout << "no interchange" << endl;
                    else
                        cout << endl;
                }
            }
        }
    }


}

void        buses_for_stop(const vector<map<string, vector<string>>> &bus_stops) {
    string stop;
    cin >> stop;
    bool exist = true;
    for (const auto &item : bus_stops) {
        for (auto &itm : item) {
            for (auto &i : itm.second) {
                if (i == stop) {
                    cout << itm.first << " ";
                    exist = false;
                }
            }
        }
    }
    if (exist)
        cout << "No stop" << endl;
    else
        cout << endl;
}

int     main(void) {
    int amount_command;
    cin >> amount_command;
    string stop;
    string bus;
    string command;
    vector<map<string, vector<string>>> bus_stops;
    int amount_stops;

    for (int i = 0; i < amount_command; ++i) {
        cin >> command;
        if (command == "NEW_BUS") {
            cin >> bus >> amount_stops;
            bus_stops.push_back({{bus, get_stops(amount_stops)}});
        } else if (command == "ALL_BUSES") {
            //all busse
            all_buses(bus_stops);
        } else if (command == "STOPS_FOR_BUS") {
            //stops
            stops_for_bus(bus_stops);
        } else if (command == "BUSES_FOR_STOP")
            buses_for_stop(bus_stops);
    }
    return (0);
}