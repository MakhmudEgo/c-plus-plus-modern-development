#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

string    get_fullname(const map<int, string> &fullname, const int year) {
    string result;
    for (const auto &item : fullname) {
        if (item.first <= year)
            result = item.second;
        else
            break;
    }
    return result;
}

string      get_fullname_history(const map<int, string> &fullname, const int year) {
    vector<string> names;
    for (const auto &item : fullname) {
        if ((names.empty() || item.second != names.back()) && item.first <= year)
            names.push_back(item.second);
    }
    if (names.size() == 1)
        return (names[0]);
    string result = names[names.size() - 1];
    for (int i = names.size() - 2; i >= 0 ; --i) {
        if (i == names.size() - 2)
            result += " (";
        if (i >= 1)
            result += names[i] + ", ";
        if (i == 0)
            result += names[i] + ")";
    }
    return (result);
}

class Person {
public:
    Person (const string &new_f, const string &new_l, const int &new_age) {
        first_name[new_age] = new_f;
        last_name[new_age] = new_l;
        age = new_age;
    }
    void ChangeFirstName (const int &year, const string &new_f) {
        if (year > age)
            first_name[year] = new_f;
    }
    void ChangeLastName (const int &year, const string &new_l) {
        if (year > age)
            last_name[year] = new_l;
    }
    string GetFullName (const int &year) const {
        if (year < age)
            return ("No person");
        string first_n = get_fullname(first_name, year);
        string last_n = get_fullname(last_name, year);
        return first_n + " " + last_n;
    }
    string GetFullNameWithHistory (const int &year) const {
        if (year < age)
            return ("No person");
        string first_n_h = get_fullname_history(first_name, year);
        string last_n_h = get_fullname_history(last_name, year);
        return (first_n_h + " " + last_n_h);
    }
private:
    map<int, string> first_name;
    map<int, string> last_name;
    int age;

};

int main() {
    Person person("Polina", "Sergeeva", 1960);
    for (int year : {1959, 1960}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    person.ChangeFirstName(1965, "Appolinaria");
    person.ChangeLastName(1967, "Ivanova");
    for (int year : {1965, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
    }

    return 0;
}