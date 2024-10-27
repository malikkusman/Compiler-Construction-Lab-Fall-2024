#include <iostream>
#include <queue>
#include <string>

using namespace std;

class TicketingSystem {
private:
    queue<string> customerQueue;
    deque<string> vipQueue;

public:
    void joinQueue(const string& customer) {
        customerQueue.push(customer);
        cout << customer << " has joined the regular queue." << endl;
    }

    void addVIP(const string& vipCustomer) {
        vipQueue.push_front(vipCustomer);
        cout << vipCustomer << " has joined the VIP queue." << endl;
    }

    void processTicket() {
        if (!vipQueue.empty()) {
            cout << "Processing ticket for VIP customer: " << vipQueue.front() << endl;
            vipQueue.pop_front();
        } else if (!customerQueue.empty()) {
            cout << "Processing ticket for regular customer: " << customerQueue.front() << endl;
            customerQueue.pop();
        } else {
            cout << "No customers in the queue!" << endl;
        }
    }

    void displayQueue() {
        cout << "Current Queue Status:" << endl;

        if (!vipQueue.empty()) {
            cout << "VIP Queue: ";
            for (const auto& vip : vipQueue) {
                cout << vip << " -> ";
            }
            cout << "NULL" << endl;
        }

        if (!customerQueue.empty()) {
            cout << "Regular Queue: ";
            queue<string> tempQueue = customerQueue;
            while (!tempQueue.empty()) {
                cout << tempQueue.front() << " -> ";
                tempQueue.pop();
            }
            cout << "NULL" << endl;
        }

        if (vipQueue.empty() && customerQueue.empty()) {
            cout << "No customers in the queue." << endl;
        }
    }
};

int main() {
    TicketingSystem cinema;

    cinema.joinQueue("Alice");
    cinema.joinQueue("Bob");
    cinema.joinQueue("Charlie");

    cinema.addVIP("VIP-David");

    cinema.processTicket();
    cinema.processTicket();
    cinema.processTicket();

    cinema.addVIP("VIP-Eve");

    cinema.joinQueue("Frank");

    cinema.processTicket();
    cinema.processTicket();
    cinema.processTicket();

    cinema.displayQueue();

    return 0;
}
