#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Student {
    string name;
    int grade;

    Student(string n, int g) : name(n), grade(g) {}
};

bool compare(const Student& a, const Student& b) {
    if (a.grade != b.grade) {
        return a.grade > b.grade;
    }
    return a.name < b.name;
}

int main() {
    vector<Student> students = {
        {"John", 85},
        {"Alice", 92},
        {"Bob", 85},
        {"David", 75},
        {"Eve", 92}
    };

    sort(students.begin(), students.end(), compare);

    for (const auto& student : students) {
        cout << student.name << ": " << student.grade << endl;
    }

    return 0;
}
