#include <iostream>
#include <map>
#include <string>

using namespace std;

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        name = first_name;
        history_name[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        surname = last_name;
        history_surname[year] = last_name;
    }
    string GetFullName(int year) {
        string n = "";
        string s = "";
        for (const auto &item : history_name) {
            if (item.first <= year) {
                n = item.second;
            }
        }
        for (const auto &item : history_surname) {
            if (item.first <= year) {
                s = item.second;
            }
        }
        if (n == "" && s == "")
            return ("Incognito");
        if (s == "")
            return (n + " with unknown last name");
        if (n == "")
            return (s + "with unknown first name");
        return (n + " " + s);
    }
private:
    string name = "";
    string surname = "";
    map<int, string> history_name;
    map<int, string> history_surname;
};

int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }
    return 0;
}
