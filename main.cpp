#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool isCompleted;
};

void showMenu() {
    cout << "\n===== TO-DO LIST MENU =====" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Complete" << endl;
    cout << "4. Delete Task" << endl;
    cout << "5. Exit" << endl;
    cout << "Choose an option: ";
}

void addTask(vector<Task>& tasks) {
    string desc;
    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, desc);
    tasks.push_back({desc, false});
    cout << "Task added successfully!" << endl;
}

void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to show." << endl;
        return;
    }

    cout << "\nYour Tasks:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". [" << (tasks[i].isCompleted ? "DONE" : " ") << "] " << tasks[i].description << endl;
    }
}

void completeTask(vector<Task>& tasks) {
    int index;
    cout << "Enter task number to mark as complete: ";
    cin >> index;
    if (index >= 1 && index <= tasks.size()) {
        tasks[index - 1].isCompleted = true;
        cout << "Task marked as complete!" << endl;
    } else {
        cout << "Invalid task number!" << endl;
    }
}

void deleteTask(vector<Task>& tasks) {
    int index;
    cout << "Enter task number to delete: ";
    cin >> index;
    if (index >= 1 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task deleted!" << endl;
    } else {
        cout << "Invalid task number!" << endl;
    }
}

int main() {
    vector<Task> tasks;
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: addTask(tasks); break;
            case 2: viewTasks(tasks); break;
            case 3: completeTask(tasks); break;
            case 4: deleteTask(tasks); break;
            case 5: cout << "Goodbye!" << endl; break;
            default: cout << "Invalid option. Try again!" << endl;
        }
    } while (choice != 5);

    return 0;
}
