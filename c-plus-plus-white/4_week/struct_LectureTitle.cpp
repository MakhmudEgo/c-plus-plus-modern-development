#include <iostream>
#include <string>

using namespace std;

struct Specialization {
    string value;
    explicit Specialization (const string &new_value) {
        value = new_value;
    }
};
struct Course {
    string value;
    explicit Course(const string &new_value) {
        value = new_value;
    }
};
struct Week {
    string value;
    explicit Week(const string &new_value) {
        value = new_value;
    }
};
struct LectureTitle {
    LectureTitle(Specialization new_s, Course new_c, Week new_w) {
        specialization = new_s.value;
        course = new_c.value;
        week = new_w.value;
    }
    string specialization;
    string course;
    string week;
};

int     main(void) {
    LectureTitle title(
            Specialization("C++"),
            Course("White belt"),
            Week("4th")
    );
    cout << title.specialization << endl;
    cout << title.course << endl;
    cout << title.week << endl;
    return (0);
}