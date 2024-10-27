#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct Patient {
    string name;
    int severity;

    Patient(string n, int s) : name(n), severity(s) {}

    bool operator<(const Patient& other) const {
        return severity < other.severity;
    }
};

class EmergencyRoom {
private:
    priority_queue<Patient> pq;

public:
    void addPatient(string name, int severity) {
        pq.push(Patient(name, severity));
        cout << name << " (Severity: " << severity << ") has been added to the queue." << endl;
    }

    void treatPatient() {
        if (pq.empty()) {
            cout << "No patients in the queue!" << endl;
            return;
        }

        Patient nextPatient = pq.top();
        pq.pop();
        cout << "Treating patient: " << nextPatient.name << " (Severity: " << nextPatient.severity << ")" << endl;
    }

    void nextPatient() {
        if (pq.empty()) {
            cout << "No patients in the queue!" << endl;
        } else {
            Patient nextPatient = pq.top();
            cout << "Next patient to be treated: " << nextPatient.name << " (Severity: " << nextPatient.severity << ")" << endl;
        }
    }

    bool hasPatients() {
        return !pq.empty();
    }
};

int main() {
    EmergencyRoom er;

    er.addPatient("Alice", 5);
    er.addPatient("Bob", 3);
    er.addPatient("Charlie", 10);
    er.addPatient("David", 7);

    er.nextPatient();
    er.treatPatient();

    er.nextPatient();
    er.treatPatient();

    er.addPatient("Eve", 9);
    er.treatPatient();

    while (er.hasPatients()) {
        er.treatPatient();
    }

    return 0;
}
