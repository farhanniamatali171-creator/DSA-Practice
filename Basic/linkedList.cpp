#include <iostream>


struct Node{
    int data;
    Node* next;

    Node(int value){
       data = value;
       next = nullptr;
    }
};

class LinkedList{
private:
    Node* head;
public:
    LinkedList(){
        head = nullptr;
    }

    void insert(int value){
        Node* newNode = new Node(value);

        if (head == nullptr){
            head = newNode;
            return;
        }
        Node* temp = head;

        while (temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void display(){
        Node* temp = head;

        while (temp != nullptr){
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    // TASK 1: Reverse using loop
 
    void displayReverseLoop(){   
        int count = 0;
        Node* temp = head;

        while (temp != nullptr){
            count++;
            temp = temp->next;
        }

        for (int i = count - 1; i >= 0; i--){
            temp = head;
            for (int j = 0; j < i; j++){
                temp = temp->next;
            }

            std::cout << temp->data << " ";
        }
        std::cout << std::endl;
    }

    // TASK 1: Reverse using recursion
    void displayReverseRecursive(Node* temp){
        
        if (temp == nullptr)
            return;

        displayReverseRecursive(temp->next);

        std::cout << temp->data << " ";
    }

    void displayReverseRecursive(){
        displayReverseRecursive(head);
        std::cout << std::endl;
    }

    // TASK 2: Merge two lists into a third new list
    static LinkedList mergeLists(LinkedList& list1, LinkedList& list2){
  
        LinkedList newList;

        Node* temp = list1.head;

        while (temp != nullptr){
            newList.insert(temp->data);
            temp = temp->next;
        }

        temp = list2.head;

        while (temp != nullptr){
            newList.insert(temp->data);
            temp = temp->next;
        }

        return newList;
    }

    // TASK 3: Find multiple occurrences
    void findOccurrences(int value){
    
        Node* temp = head;
        int position = 1;
        int count = 0;

        std::cout << "Occurrences of " << value << " at position(s): ";

        while (temp != nullptr){
            if (temp->data == value){
                std::cout << position << " ";
                count++;
            }

            temp = temp->next;
            position++;
        }
        if (count == 0){
            std::cout << "Not found";
        }
        std::cout << std::endl;
        std::cout << "Total occurrences = " << count << std::endl;
    }
};

int main()
{
     system("chcp 65001 > nul");
    // TASK 1
    std::cout << std::endl;
    std::cout << "╔═════════════════╗" << std::endl;
    std::cout << "║   LAB TASK-1    ║" << std::endl;
    std::cout << "╚═════════════════╝" << std::endl;

    LinkedList list;

    list.insert(10);
    list.insert(15);
    list.insert(20);
    list.insert(25);
    list.insert(30);

    std::cout << "Original List: ";
    list.display();

    std::cout << "Reverse using Loop: ";
    list.displayReverseLoop();

    std::cout << "Reverse using Recursion: ";
    list.displayReverseRecursive();


    // TASK 2
    std::cout << std::endl;  
    std::cout << "╔═════════════════╗" << std::endl;
    std::cout << "║   LAB TASK-2    ║" << std::endl;
    std::cout << "╚═════════════════╝" << std::endl;

    LinkedList list1;
    LinkedList list2;

    list1.insert(2);
    list1.insert(4);
    list1.insert(6);

    list2.insert(7);
    list2.insert(8);
    list2.insert(9);

    std::cout << "\nList 1: ";
    list1.display();

    std::cout << "List 2: ";
    list2.display();

    LinkedList list3 = LinkedList::mergeLists(list1, list2);

    std::cout << "Third List: ";
    list3.display();

    // TASK 3
    std::cout << std::endl; 
    std::cout << "╔═════════════════╗" << std::endl;
    std::cout << "║   LAB TASK-3    ║" << std::endl;
    std::cout << "╚═════════════════╝" << std::endl;

    LinkedList list4;

    list4.insert(10);
    list4.insert(20);
    list4.insert(10);
    list4.insert(30);
    list4.insert(10);
    list4.insert(40);

    std::cout << "\nList: ";
    list4.display();

    list4.findOccurrences(10);

    
    return 0;
}
