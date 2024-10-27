#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
    set<string> emailSet;

    vector<string> emails = {
        "john.doe@example.com",
        "jane.smith@example.com",
        "john.doe@example.com",
        "alice.johnson@example.com",
        "bob.brown@example.com",
        "jane.smith@example.com"
    };

    for (const auto& email : emails) {
        emailSet.insert(email);
    }

    cout << "Unique email addresses:" << endl;
    for (const auto& email : emailSet) {
        cout << email << endl;
    }

    string searchEmail = "alice.johnson@example.com";
    if (emailSet.find(searchEmail) != emailSet.end()) {
        cout << searchEmail << " is in the set." << endl;
    } else {
        cout << searchEmail << " is not in the set." << endl;
    }

    emailSet.erase("bob.brown@example.com");

    cout << "Email addresses after deletion:" << endl;
    for (const auto& email : emailSet) {
        cout << email << endl;
    }

    return 0;
}
