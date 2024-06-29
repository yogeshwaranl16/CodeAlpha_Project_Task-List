#include <iostream>
#include <vector>
#include <string>

class TodoList {
public:
    TodoList() {}

    void addTask(const std::string& task) {
        tasks.push_back(task);
        std::cout << "Task added successfully!" << std::endl;
    }

    void removeTask(const std::string& task) {
        for (auto it = tasks.begin(); it != tasks.end(); ++it) {
            if (*it == task) {
                tasks.erase(it);
                std::cout << "Task removed successfully!" << std::endl;
                return;
            }
        }
        std::cout << "Task not found in the list." << std::endl;
    }

    void displayTasks() {
        if (!tasks.empty()) {
            std::cout << "Your To-Do List:" << std::endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
                std::cout << i + 1 << ". " << tasks[i] << std::endl;
            }
        } else {
            std::cout << "Your To-Do List is empty." << std::endl;
        }
    }

private:
    std::vector<std::string> tasks;
};

int main() {
    TodoList todoList;

    while (true) {
        std::cout << "\n1. Add Task" << std::endl;
        std::cout << "2. Remove Task" << std::endl;
        std::cout << "3. Display Tasks" << std::endl;
        std::cout << "4. Exit" << std::endl;

        std::string choice;
        std::getline(std::cin, choice);

        if (choice == "1") {
            std::string task;
            std::cout << "Enter the task: ";
            std::getline(std::cin, task);
            todoList.addTask(task);
        } else if (choice == "2") {
            std::string task;
            std::cout << "Enter the task to remove: ";
            std::getline(std::cin, task);
            todoList.removeTask(task);
        } else if (choice == "3") {
            todoList.displayTasks();
        } else if (choice == "4") {
            std::cout << "Exiting program." << std::endl;
            break;
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
