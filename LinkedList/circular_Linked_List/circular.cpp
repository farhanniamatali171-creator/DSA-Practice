#include <iostream>
#include <string>

struct Node {
    std::string name;
    std::string status;
    int priority;
    int person;
    Node* next;

    Node(std::string taskName, int taskPriority, std::string taskStatus) {
        name = taskName;
        status = taskStatus;
        priority = taskPriority;
        person = 0;
        next = nullptr;
    }

    Node(int number) {
        name = "";
        status = "";
        priority = 0;
        person = number;
        next = nullptr;
    }
};

class CircularLinkedList {
public:
    Node* head;
    Node* current;

    CircularLinkedList() {
        head = nullptr;
        current = nullptr;
    }
    //addTask
    void addTask(std::string name, int priority, std::string status) {
        Node* newNode = new Node(name, priority, status);

        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
            current = head;
        } else {
            Node* temp = head;

            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
        std::cout << "Task added: " << name << "\n";
    }
    //removeTask
    void removeTask(std::string name) {
        if (head == nullptr) {
            std::cout << "Task list is empty!\n";
            return;
        }
        Node* curr = head;
        Node* prev = nullptr;

        do {
            if (curr->name == name) {
                break;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);

        if (curr->name != name) {
            std::cout << "Task not found!\n";
            return;
        }

        if (curr->next == curr) {
            head = nullptr;
            current = nullptr;
        } else {
            if (curr == head) {
                Node* last = head;

                while (last->next != head) {
                    last = last->next;
                }
                head = head->next;
                last->next = head;
            } else {
                prev->next = curr->next;
            }
            if (current == curr) {
                current = curr->next;
            }
        }
        delete curr;
        std::cout << "Task removed: " << name << "\n";
    }
    //getNextTask
    void getNextTask() {
        if (head == nullptr) {
            std::cout << "No tasks available!\n";
            return;
        }
        Node* start = current;
        do {
            if (current->status == "Pending") {
                std::cout << "Next Task: " << current->name << "\n";
                std::cout << "Priority: " << current->priority << "\n";

                current = current->next;
                return;
            }
            current = current->next;
        } while (current != start);
        std::cout << "No pending tasks available!\n";
    }

    void displayTasks() {
        if (head == nullptr) {
            std::cout << "No tasks available!\n";
            return;
        }
        Node* curr = head;
        do {
            std::cout << "Task: " << curr->name
                      << ", Priority: " << curr->priority
                      << ", Status: " << curr->status << "\n";

            curr = curr->next;
        } while (curr != head);
    }
    //updateStatus
    void updateStatus(std::string name, std::string newStatus) {
        if (head == nullptr) {
            std::cout << "Task list is empty!\n";
            return;
        }
        Node* curr = head;

        do {
            if (curr->name == name) {
               curr->status = newStatus;
               std::cout << "Task: " << curr->name
                          << ", Updated Status: " << curr->status << "\n";
                return;
            }
            curr = curr->next;
        } while (curr != head);
        std::cout << "Task not found!\n";
    }

    ~CircularLinkedList() {
        if (head == nullptr) {
            return;
        }
        Node* curr = head->next;
        while (curr != head) {
            Node* nextNode = curr->next;
            delete curr;
            curr = nextNode;
        }
        delete head;
    }
};
//josephusProblem
void josephusProblem(int N, int M) {
    if (N <= 0 || M <= 0) {
        std::cout << "N and M must be greater than zero!\n";
        return;
    }
    Node* head = new Node(1);
    Node* last = head;

    for (int i = 2; i <= N; i++) {
        Node* newNode = new Node(i);
        last->next = newNode;
        last = newNode;
    }
    last->next = head;
    Node* curr = head;
    Node* prev = last;

    while (curr->next != curr) {
        for (int i = 1; i < M; i++) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        delete curr;
        curr = prev->next;
    }
    std::cout << "Survivor is person " << curr->person << "\n";
    delete curr;
}

int main() {
    CircularLinkedList tasks;

    //Josephus Problem
    std::cout << "Activity 1: Josephus Problem\n";
    josephusProblem(7, 3);

    //Add Tasks
    std::cout << "\nActivity 2: Add Tasks\n";
    tasks.addTask("Design", 1, "Pending");
    tasks.addTask("Coding", 2, "Pending");
    tasks.addTask("Testing", 3, "Completed");

    //Display All Tasks
    std::cout << "\nActivity 3: Display All Tasks\n";
    tasks.displayTasks();

    //Get Next Task
    std::cout << "\nActivity 4: Get Next Task\n";
    tasks.getNextTask();

    //Update Task Status
    std::cout << "\nActivity 5: Update Task Status\n";
    tasks.updateStatus("Design", "Completed");

    //Get Next Task Again
    std::cout << "\nActivity 6: Get Next Task Again\n";
    tasks.getNextTask();

    //Remove a Task
    std::cout << "\nActivity 7: Remove a Task\n";
    tasks.removeTask("Coding");

    // Display Remaining Tasks
    std::cout << "\nActivity 8: Display Remaining Tasks\n";
    tasks.displayTasks();



   return 0;
}
