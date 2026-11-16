#include <iostream>
#include <string>

struct Patient {
    int id;
    std::string name;
    int urgency;
    int treatmentTime;
};
class PatientQueue {
private:
    struct Node {
        Patient data;
        Node* next;
        Node(Patient p) {
            data = p;
            next = nullptr;
        }
    };
    Node* front;
    Node* rear;
    int count;
public:
    PatientQueue() {
        front = nullptr;
        rear = nullptr;
        count = 0;
    }
    ~PatientQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
    void enqueue(Patient p) {
        Node* newNode = new Node(p);
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
        count++;
    }
    Patient dequeue() {
        if (isEmpty()) {
            return Patient{};
        }
        Node* temp = front;
        Patient p = temp->data;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        count--;
        return p;
    }
    Patient peek() {
        if (isEmpty()) {
            return Patient{};
        }
        return front->data;
    }
    bool isEmpty() {
        return front == nullptr;
    }
    int size() {
        return count;
    }
    void display() {
        if (isEmpty()) {
            std::cout << "No patients waiting.\n";
            return;
        }
        Node* temp = front;
        while (temp != nullptr) {
            std::cout << "ID: " << temp->data.id
                      << " | Name: " << temp->data.name
                      << " | Time Left: " << temp->data.treatmentTime
                      << " minutes\n";
            temp = temp->next;
        }
    }
};
PatientQueue criticalQueue;
PatientQueue standardQueue;

const int Q = 10;
int totalElapsedTime = 0;

void registerPatient() {
    Patient p;
    std::cout << "\nEnter Patient ID: ";
    std::cin >> p.id;
    std::cout << "Enter Patient Name: ";
    std::getline(std::cin >> std::ws, p.name);
    std::cout << "Enter Urgency (1 = Critical, 2 = Standard): ";
    std::cin >> p.urgency;
    std::cout << "Enter Treatment Time (minutes): ";
    std::cin >> p.treatmentTime;
    if (p.urgency != 1 && p.urgency != 2) {
        std::cout << "\nInvalid urgency level!\n";
        return;
    }
    if (p.treatmentTime <= 0) {
        std::cout << "\nTreatment time must be greater than zero!\n";
        return;
    }
    if (p.urgency == 1) {
        criticalQueue.enqueue(p);
        std::cout << "\nPatient added to Critical Queue.\n";
    }
    else {
        standardQueue.enqueue(p);
        std::cout << "\nPatient added to Standard Queue.\n";
    }
}

void simulateOneTurn() {
    Patient p;
    int timeSpent;
    if (!criticalQueue.isEmpty()) {
        p = criticalQueue.dequeue();
        std::cout << "\nTreating Critical Patient: " << p.name << "\n";
    }
    else if (!standardQueue.isEmpty()) {
        p = standardQueue.dequeue();
        std::cout << "\nTreating Standard Patient: " << p.name << "\n";
    }
    else {
        std::cout << "\nNo patients available in the ER.\n";
        return;
    }
    if (p.treatmentTime > Q) {
        timeSpent = Q;
    }
    else {
        timeSpent = p.treatmentTime;
    }
    p.treatmentTime -= timeSpent;
    totalElapsedTime += timeSpent;

    std::cout << "Patient ID: " << p.id << "\n";
    std::cout << "Time Spent: " << timeSpent << " minutes\n";
    std::cout << "Total Elapsed Time: " << totalElapsedTime << " minutes\n";

    if (p.treatmentTime <= 0) {
        std::cout << "Status: Patient Discharged!\n";
        std::cout << "Discharged at minute: " << totalElapsedTime << "\n";
    }
    else {
        std::cout << "Remaining Treatment Time: " << p.treatmentTime << " minutes\n";
        std::cout << "Status: Patient Re-queued.\n";
        if (p.urgency == 1) {
            criticalQueue.enqueue(p);
        }
        else {
            standardQueue.enqueue(p);
        }
    }
}

void simulateAll() {
    if (criticalQueue.isEmpty() && standardQueue.isEmpty()) {
        std::cout << "\nNo patients available to treat.\n";
        return;
    }
    std::cout << "\n========== FULL ER SIMULATION ==========\n";
    while (!criticalQueue.isEmpty() || !standardQueue.isEmpty()) {
        simulateOneTurn();
        std::cout << "----------------------------------------\n";
    }
    std::cout << "\n========== SIMULATION COMPLETED ==========\n";
    std::cout << "All patients have been discharged.\n";
    std::cout << "Total ER Time: " << totalElapsedTime << " minutes\n";
}

void displayWaitingRoom() {
    std::cout << "\n========== WAITING ROOM ==========\n";
    std::cout << "\nCritical Queue:\n";
    criticalQueue.display();
    std::cout << "\nStandard Queue:\n";
    standardQueue.display();
    std::cout << "\nTotal Patients Waiting: "
              << criticalQueue.size() + standardQueue.size() << "\n";
    std::cout << "==================================\n";
}

int main() {
    int choice;
    do {
        std::cout << "\n\n";
        std::cout << "====================================\n";
        std::cout << "       EMERGENCY ROOM SYSTEM        \n";
        std::cout << "====================================\n";
        std::cout << "1. Register Patient\n";
        std::cout << "2. Simulate One Turn\n";
        std::cout << "3. Simulate Until All Queues Empty\n";
        std::cout << "4. Display Waiting Room\n";
        std::cout << "5. Exit\n";
        std::cout << "====================================\n";
        std::cout << "Enter Your Choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                registerPatient();
                break;
            case 2:
                simulateOneTurn();
                break;
            case 3:
                simulateAll();
                break;
            case 4:
                displayWaitingRoom();
                break;
            case 5:
                std::cout << "\nExiting ER Management System.\n";
                break;
            default:
                std::cout << "\nInvalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
