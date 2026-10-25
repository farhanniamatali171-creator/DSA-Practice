#include <iostream>
#include <string>

class Que{
public:
    int size;
    int* q;
    int front = -1;
    int rear = -1;

    Que(){
        size = 10;
        q = new int[size];
    }

    Que(int x){
        size = x > 0 ? x : 10;
        q = new int[size];
    }

    bool isEmpty(){
        return rear == -1;
    }

    bool isFull(){
        return rear == size - 1;
    }

    void enqueue(int x){
        if (isFull()) {
            std::cout << "Queue is Full!\n";
        } else {
            if (isEmpty()){
                front = rear = 0;
            } else {
                rear++;
            }
            q[rear] = x;
        }
    }

    int dequeue(){
        if (isEmpty()) {
            std::cout << "Queue is Empty!\n";
            return -1;
        } else {
            int x = q[front];
            if (front == rear) {
                front = rear = -1;
            } else {
                front++;
            }
            return x;
        }
    }

    void display(){
        if (isEmpty()) {
            std::cout << "Queue is Empty!\n";
        } else {
            for (int i = front; i <= rear; i++) {
                std::cout << q[i] << " ";
            }
            std::cout << "\n";
        }
    }

    ~Que(){
        delete[] q;
    }
};

class ShiftQueue{
public:
    int size;
    int* q;
    int front = -1;
    int rear = -1;

    ShiftQueue(int x = 10){
        size = x > 0 ? x : 10;
        q = new int[size];
    }

    bool isEmpty(){
        return rear == -1;
    }

    bool isFull(){
        return rear == size - 1;
    }

    void enqueue(int x){
        if (isFull()){
            std::cout << "Queue is Full!\n";
        } else{
            if (isEmpty()) {
                front = rear = 0;
            }else{
                rear++;
            }
            q[rear] = x;
        }
    }

    int dequeue() {
        if (isEmpty()){
            std::cout << "Queue is Empty!\n";
            return -1;
        } else {
            int x = q[front];
            for (int i = front; i < rear; i++){
                q[i] = q[i + 1];
            }
            rear--;
            if (rear == -1) {
                front = -1;
            }
            return x;
        }
    }

    void display(){
        if (isEmpty()){
            std::cout << "Queue is Empty!\n";
        } else {
            for (int i = front; i <= rear; i++) {
                std::cout << q[i] << " ";
            }
            std::cout << "\n";
        }
    }

    ~ShiftQueue(){
        delete[] q;
    }
};

class CircularQueue{
public:
    int q[10];
    int front = 0;
    int rear = 0;
    int count = 0;

    bool isEmpty(){
        return count == 0;
    }

    bool isFull(){
        return count == 10;
    }

    void enqueue(int x){
        if (isFull()) {
            std::cout << "Circular Queue is Full!\n";
        } else {
            q[rear] = x;
            rear = (rear + 1) % 10;
            count++;
        }
    }

    int dequeue(){
        if (isEmpty()) {
            std::cout << "Circular Queue is Empty!\n";
            return -1;
        } else {
            int x = q[front];
            front = (front + 1) % 10;
            count--;
            return x;
        }
    }

    void display(){
        if (isEmpty()) {
            std::cout << "Circular Queue is Empty!\n";
        } else {
            for (int i = 0; i < count; i++) {
                std::cout << q[(front + i) % 10] << " ";
            }
            std::cout << "\n";
        }
    }
};

class ArrayDeque{
public:
    int q[10];
    int front = -1;
    int rear = -1;

    bool isEmpty(){
        return front == -1;
    }

    void insertAtBeg(int x){
        if (isEmpty()) {
            front = rear = 0;
            q[front] = x;
        } else if (front == 0){
            std::cout << "No space at beginning!\n";
        } else {
            front--;
            q[front] = x;
        }
    }

    void insertAtEnd(int x){
        if (rear == 9) {
            std::cout << "No space at end!\n";
        } else {
            if (isEmpty()){
                front = rear = 0;
            } else {
                rear++;
            }
            q[rear] = x;
        }
    }

    void deleteFromFront(){
        if (isEmpty()) {
            std::cout << "Deque is Empty!\n";
        } else {
            std::cout << "Deleted: " << q[front] << "\n";
            if (front == rear){
                front = rear = -1;
            } else {
                front++;
            }
        }
    }

    void deleteFromRear(){
        if (isEmpty()) {
            std::cout << "Deque is Empty!\n";
        } else {
            std::cout << "Deleted: " << q[rear] << "\n";
            if (front == rear){
                front = rear = -1;
            } else {
                rear--;
            }
        }
    }

    void display(){
        if (isEmpty()) {
            std::cout << "Deque is Empty!\n";
        } else {
            for (int i = front; i <= rear; i++) {
                std::cout << q[i] << " ";
            }
            std::cout << "\n";
        }
    }
};

struct Node{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = nullptr;
    }
};

class LinkedQueue{
public:
    Node* front = nullptr;
    Node* rear = nullptr;

    bool isEmpty(){
        return front == nullptr;
    }

    void enqueue(int x){
        Node* newNode = new Node(x);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue(){
        if (isEmpty()) {
            std::cout << "Queue is Empty!\n";
            return -1;
        } else {
            Node* temp = front;
            int x = temp->data;
            front = front->next;
            if (front == nullptr){
                rear = nullptr;
            }
            delete temp;
            return x;
        }
    }

    void display() {
        if (isEmpty()){
            std::cout << "Queue is Empty!\n";
        } else {
            Node* temp = front;
            while (temp != nullptr){
                std::cout << temp->data << " ";
                temp = temp->next;
            }
            std::cout << "\n";
        }
    }

    ~LinkedQueue(){
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

struct DNode{
    int data;
    DNode* next;
    DNode* prev;

    DNode(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};

class LinkedDeque{
public:
    DNode* front = nullptr;
    DNode* rear = nullptr;

    bool isEmpty(){
        return front == nullptr;
    }

    void insertAtBeg(int x){
        DNode* newNode = new DNode(x);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    void insertAtEnd(int x){
        DNode* newNode = new DNode(x);
        if (isEmpty()) {
            front = rear = newNode;
        }else{
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
    }

    void deleteFromFront(){
        if (isEmpty()) {
            std::cout << "Deque is Empty!\n";
        }else{
            DNode* temp = front;
            std::cout << "Deleted: " << temp->data << "\n";
            front = front->next;
            if (front == nullptr) {
                rear = nullptr;
            }else{
                front->prev = nullptr;
            }
            delete temp;
        }
    }

    void deleteFromRear(){
        if (isEmpty()) {
            std::cout << "Deque is Empty!\n";
        }else{
            DNode* temp = rear;
            std::cout << "Deleted: " << temp->data << "\n";
            rear = rear->prev;
            if (rear == nullptr) {
                front = nullptr;
            }else{
                rear->next = nullptr;
            }
            delete temp;
        }
    }

    void display() {
        if (isEmpty()){
            std::cout << "Deque is Empty!\n";
        }else{
            DNode* temp = front;
            while (temp != nullptr) {
                std::cout << temp->data << " ";
                temp = temp->next;
            }
            std::cout << "\n";
        }
    }

    ~LinkedDeque(){
        while (front != nullptr) {
            DNode* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
    // Activity 1: Array-Based FIFO Queue
    std::cout << "Activity 1: Array FIFO Queue\n";
    Que q1(5);
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.display();
    std::cout << "Dequeued: " << q1.dequeue() << "\n";
    q1.display();

    // Activity 2: Shift-Left Queue
    std::cout << "\nActivity 2: Shift-Left Queue\n";
    ShiftQueue q2(5);
    q2.enqueue(10);
    q2.enqueue(20);
    q2.enqueue(30);
    q2.display();
    std::cout << "Dequeued: " << q2.dequeue() << "\n";
    q2.enqueue(40);
    q2.display();

    // Activity 3: Circular Queue
    std::cout << "\nActivity 3: Circular Queue\n";
    CircularQueue q3;
    q3.enqueue(10);
    q3.enqueue(20);
    q3.enqueue(30);
    q3.display();
    std::cout << "Dequeued: " << q3.dequeue() << "\n";
    q3.display();
    // Activity 4: Array-Based Deque
    std::cout << "\nActivity 4: Array Deque\n";
    ArrayDeque d1;
    d1.insertAtEnd(10);
    d1.insertAtEnd(20);
    d1.deleteFromFront();
    d1.insertAtBeg(5);
    d1.display();
    d1.deleteFromFront();
    d1.deleteFromRear();
    d1.display();

    // Lab Task 1: Linked-List Queue
    std::cout << "\nLab Task 1: Linked Queue\n";
    LinkedQueue q6;
    q6.enqueue(10);
    q6.enqueue(20);
    q6.enqueue(30);
    q6.display();
    std::cout << "Dequeued: " << q6.dequeue() << "\n";
    q6.display();

    // Lab Task 2: Linked-List Deque
    std::cout << "\nLab Task 2: Linked Deque\n";
    LinkedDeque d2;
    d2.insertAtEnd(10);
    d2.insertAtEnd(20);
    d2.insertAtBeg(5);
    d2.display();
    d2.deleteFromFront();
    d2.deleteFromRear();
    d2.display();

    return 0;
}
