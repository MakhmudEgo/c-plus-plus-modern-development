#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>

using namespace std;

string  get_name_or_surname(const map<int, string> &s, const int &year) {
    string n = "";
    for (const auto &item : s) {
        if (item.first <= year) {
            n = item.second;
        }
    }
    return (n);
}

string      get_full_name(const map<int, string> &s, const int &year) {
    string n = "";
    vector<string> ns;
    for (const auto &item : s) {
        if (item.first <= year) {
            ns.push_back(item.second);
        }
    }
    auto dubl = unique(begin(ns), end(ns));
    ns.erase(dubl, end(ns));
    if (ns.size() == 1)
        return (ns[0]);
    for (int i = ns.size() - 1; i >= 0; --i) {
        if(i == ns.size() - 1)
            n += ns[i];
        if (i == ns.size() - 2)
            n += " (" + ns[i];
        else if (i != ns.size() - 1 && i >= 0)
            n += ", " + ns[i];
        if (i == 0)
            n += ")";
    }
    return (n);
}

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        history_name[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        history_surname[year] = last_name;
    }
    string GetFullName(int year) {
        string n = "" + get_name_or_surname(history_name, year);
        string s = "" + get_name_or_surname(history_surname, year);
        if (n == "" && s == "")
            return ("Incognito");
        if (s == "")
            return (n + " with unknown last name");
        if (n == "")
            return (s + " with unknown first name");
        return (n + " " + s);
    }
    string GetFullNameWithHistory(int year) {
        string n = "" + get_full_name(history_name, year);
        string s = "" + get_full_name(history_surname, year);
        if (n == "" && s == "")
            return ("Incognito");
        if (s == "")
            return (n + " with unknown last name");
        if (n == "")
            return (s + " with unknown first name");
        return (n + " " + s);
    }
private:
    map<int, string> history_name;
    map<int, string> history_surname;
};

int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeFirstName(1964, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1990, "Polina");
    person.ChangeLastName(1990, "Volkova-Sergeeva");
    cout << person.GetFullNameWithHistory(1990) << endl;

    person.ChangeFirstName(1966, "Pauline");
    cout << person.GetFullNameWithHistory(1966) << endl;

    person.ChangeLastName(1960, "Sergeeva");
    for (int year : {1960, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeLastName(1961, "Ivanova");
    cout << person.GetFullNameWithHistory(1967) << endl;

    return 0;
}