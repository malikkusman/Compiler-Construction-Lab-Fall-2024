#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

struct Student {
    string name;
    vector<int> grades;

    Student() {}

    Student(string n, vector<int> g) : name(n), grades(g) {}
};

class StudentRecordSystem {
private:
    map<int, Student> studentRecords;

public:
    void addStudent(int id, string name, vector<int> grades) {
        studentRecords[id] = Student(name, grades);
        cout << "Student with ID " << id << " has been added." << endl;
    }

    void deleteStudent(int id) {
        if (studentRecords.erase(id)) {
            cout << "Student with ID " << id << " has been deleted." << endl;
        } else {
            cout << "Student with ID " << id << " not found." << endl;
        }
    }

    void retrieveStudent(int id) {
        if (studentRecords.find(id) != studentRecords.end()) {
            Student student = studentRecords[id];
            cout << "Student ID: " << id << ", Name: " << student.name << ", Grades: ";
            for (int grade : student.grades) {
                cout << grade << " ";
            }
            cout << endl;
        } else {
            cout << "Student with ID " << id << " not found." << endl;
        }
    }

    void displayAllStudents() {
        if (studentRecords.empty()) {
            cout << "No student records available." << endl;
        } else {
            for (const auto& record : studentRecords) {
                cout << "ID: " << record.first << ", Name: " << record.second.name << ", Grades: ";
                for (int grade : record.second.grades) {
                    cout << grade << " ";
                }
                cout << endl;
            }
        }
    }
};

int main() {
    StudentRecordSystem srs;

    srs.addStudent(101, "John Doe", {85, 90, 88});
    srs.addStudent(102, "Jane Smith", {78, 84, 91});
    srs.addStudent(103, "Alice Johnson", {92, 89, 95});

    srs.retrieveStudent(102);

    srs.deleteStudent(101);

    srs.displayAllStudents();

    return 0;
}
