#include <iostream>
#include <vector>
using namespace std;

struct Task {
    string description;
    bool completed;
};

vector<Task> tasks;

// Add Task
void addTask() {
    Task t;
    cout << "Enter task: ";
    cin.ignore();
    getline(cin, t.description);
    t.completed = false;
    tasks.push_back(t);
    cout << "Task added successfully!\n";
}

// View Tasks
void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }

    cout << "\nTo-Do List:\n";
    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].description;
        if (tasks[i].completed)
            cout << " [Completed]";
        else
            cout << " [Pending]";
        cout << endl;
    }
}

// Mark Task as Completed
void markCompleted() {
    int num;
    viewTasks();
    cout << "Enter task number to mark as completed: ";
    cin >> num;

    if (num > 0 && num <= tasks.size()) {
        tasks[num - 1].completed = true;
        cout << "Task marked as completed!\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

// Remove Task
void removeTask() {
    int num;
    viewTasks();
    cout << "Enter task number to remove: ";
    cin >> num;

    if (num > 0 && num <= tasks.size()) {
        tasks.erase(tasks.begin() + (num - 1));
        cout << "Task removed successfully!\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n===== TO-DO LIST MANAGER =====\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: markCompleted(); break;
            case 4: removeTask(); break;
            case 5: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}