#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string url;
    Node* prev;
    Node* next;

    Node(string u) : url(u), prev(nullptr), next(nullptr) {}
};

class BrowserHistory {
private:
    Node* head;
    Node* tail;
    Node* current;

public:
    BrowserHistory() : head(nullptr), tail(nullptr), current(nullptr) {}

    void addPage(string url) {
        Node* newPage = new Node(url);
        
        if (head == nullptr) {
            head = tail = current = newPage;
        } else {
            newPage->prev = current;
            if (current != nullptr) {
                current->next = newPage;
            }
            current = newPage;
            tail = current;
        }
        cout << "Navigated to: " << url << endl;
    }

    void goBack() {
        if (current == nullptr || current->prev == nullptr) {
            cout << "No previous page!" << endl;
        } else {
            current = current->prev;
            cout << "Moved back to: " << current->url << endl;
        }
    }

    void goForward() {
        if (current == nullptr || current->next == nullptr) {
            cout << "No forward page!" << endl;
        } else {
            current = current->next;
            cout << "Moved forward to: " << current->url << endl;
        }
    }

    void deleteCurrentPage() {
        if (current == nullptr) {
            cout << "No page to delete!" << endl;
            return;
        }

        Node* pageToDelete = current;

        if (current == head) {
            head = current->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            current = head;
        } else if (current == tail) {
            tail = current->prev;
            if (tail != nullptr) {
                tail->next = nullptr;
            }
            current = tail;
        } else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            current = current->next;
        }

        cout << "Deleted page: " << pageToDelete->url << endl;
        delete pageToDelete;
    }

    void displayHistory() {
        Node* temp = head;
        cout << "Browser History: ";
        while (temp != nullptr) {
            cout << temp->url << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    BrowserHistory history;

    history.addPage("www.google.com");
    history.addPage("www.github.com");
    history.addPage("www.stackoverflow.com");

    history.goBack();
    history.goBack();

    history.goForward();

    history.deleteCurrentPage();

    history.displayHistory();

    return 0;
}
