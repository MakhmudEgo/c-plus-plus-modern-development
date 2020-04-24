#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

vector<string>      get_routes(const int amount_route) {
    vector<string> route;
    string stop;
    for (int i = 0; i < amount_route; ++i) {
        cin >> stop;
        route.push_back(stop);
    }
    return (route);
}
int     main (void) {
    int amount_command;
    cin >> amount_command;
    int amount_route;
    map<int, vector<string>> routes;
    int route_num = 0;

    for (int i = 0; i < amount_command; ++i) {
        cin >> amount_route;
        bool exist = true;
        vector<string> route = get_routes(amount_route);
        for (auto &item : routes) {
            exist = false;
            if (item.second ==  route) {
                cout << "Already exists for " << item.first << endl;
                break;
            } else
                exist = true;
        }
        if (exist) {
            routes[++route_num] = route;
            cout << "New bus " << route_num << endl;
        }
    }
    return (0);
}