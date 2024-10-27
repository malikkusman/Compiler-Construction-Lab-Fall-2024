#include <iostream>
#include <deque>
#include <string>

using namespace std;

class TaskScheduler {
private:
    deque<string> taskQueue;

public:
    void addHighPriorityTask(const string& task) {
        taskQueue.push_front(task);
        cout << "High-priority task added: " << task << endl;
    }

    void addRegularTask(const string& task) {
        taskQueue.push_back(task);
        cout << "Regular task added: " << task << endl;
    }

    void removeFrontTask() {
        if (!taskQueue.empty()) {
            cout << "Task removed from front: " << taskQueue.front() << endl;
            taskQueue.pop_front();
        } else {
            cout << "No tasks to remove from front!" << endl;
        }
    }

    void removeBackTask() {
        if (!taskQueue.empty()) {
            cout << "Task removed from back: " << taskQueue.back() << endl;
            taskQueue.pop_back();
        } else {
            cout << "No tasks to remove from back!" << endl;
        }
    }

    void viewFrontTask() const {
        if (!taskQueue.empty()) {
            cout << "Task at the front: " << taskQueue.front() << endl;
        } else {
            cout << "No tasks in the queue!" << endl;
        }
    }

    void viewBackTask() const {
        if (!taskQueue.empty()) {
            cout << "Task at the back: " << taskQueue.back() << endl;
        } else {
            cout << "No tasks in the queue!" << endl;
        }
    }

    void displayTasks() const {
        if (taskQueue.empty()) {
            cout << "No tasks in the queue!" << endl;
            return;
        }

        cout << "Task queue: ";
        for (const auto& task : taskQueue) {
            cout << task << " -> ";
        }
        cout << "NULL" << endl;
    }
};

int main() {
    TaskScheduler scheduler;

    scheduler.addRegularTask("Write report");
    scheduler.addRegularTask("Email client");
    scheduler.addHighPriorityTask("Fix urgent bug");
    scheduler.addRegularTask("Code review");
    scheduler.addHighPriorityTask("Handle server outage");

    scheduler.viewFrontTask();
    scheduler.viewBackTask();

    scheduler.displayTasks();

    scheduler.removeFrontTask();
    scheduler.removeBackTask();

    scheduler.displayTasks();

    return 0;
}