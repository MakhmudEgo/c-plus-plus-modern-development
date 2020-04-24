#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

void    chang_capital(const string &count, const string &cap, map<string, string> &caps)
{
    if (caps[count] == "")
    {
        cout << "Introduce new country " << count << " with capital " << cap << endl;
        caps[count] = cap;
    }
    else if (caps[count] == cap)
        cout << "Country " << count << " hasn't changed its capital" << endl;
    else if (caps[count] != cap)
    {
        cout << "Country " << count << " has changed its capital from " << caps[count] << " to " << cap;
        caps[count] = cap;
    }
}
int     main(void)
{
    int amount_command;
    cin >> amount_command;
    string command, country, capital;

    map<string, string> caps;

    for (int i = 0; i < amount_command; i++)
    {
        cin >> command;
        if (command == "CHANGE_CAPITAL")
        {
            cin >> country >> capital;
            chang_capital(country, capital, caps);

        }
    }
}