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
        cout << "Country " << count << " has changed its capital from " << caps[count] << " to " << cap << endl;
        caps[count] = cap;
    }
}

void    rename(const string &count, const string &new_count, map<string, string> &caps)
{
    if (caps[count] == "" || caps[new_count] != "")
    {
        cout << "Incorrect rename, skip" << endl;
        caps.erase(count);
    }
    else
    {
        caps[new_count] = caps[count];
        cout << "Country " << count << " with capital " <<
            caps[count] << " has been renamed to " << new_count << endl;
        caps.erase(count);
    }
}

void    about(const string &count, map<string, string> &caps)
{
    if (caps[count] == "")
    {
        cout << "Country " << count << " doesn't exist" << endl;
        caps.erase(count);
    }
    else
        cout << "Country " << count << " has capital " << caps[count] << endl;
}
void    dump(const map<string, string> &caps)
{
    if (caps.size() == 0)
        cout << "There are no countries in the world" << endl;
    else
    {
        for (const auto &item : caps)
            cout << item.first << "/" << item.second << " ";
    }
}

int     main(void)
{
    int amount_command;
    cin >> amount_command;
    string command, country, new_country, capital;

    map<string, string> caps;

    for (int i = 0; i < amount_command; i++)
    {
        cin >> command;
        if (command == "CHANGE_CAPITAL")
        {
            cin >> country >> capital;
            chang_capital(country, capital, caps);
        }
        else if (command == "RENAME")
        {
            cin >> country >> new_country;
            rename(country, new_country, caps);
        }
        else if (command == "ABOUT")
        {
            cin >> country;
            about(country, caps);
        }
        else if (command == "DUMP")
            dump(caps);
    }
}