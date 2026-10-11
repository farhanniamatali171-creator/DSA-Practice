
#include <iostream>

struct Node
{
    int data;
    Node* next;
};

void insertEnd(Node*& head, int value){
    Node* p = new Node{value, nullptr};

    if (head == nullptr){
        head = p;
        p->next = head;
        return;
    }
    Node* last = head;

    while (last->next != head){
        last = last->next;
    }
    last->next = p;
    p->next = head;
}

void display(Node* head){
    if (head == nullptr){
        std::cout << "List is empty.\n";
        return;
    }
    Node* p = head;

    do{
        std::cout << p->data << " ";
        p = p->next;
    }while (p != head);

    std::cout << "\n";
}

int searchNode(Node* head, int key){
    if (head == nullptr){
        return -1;
    }
    Node* p = head;
    int index = 1;

    do{
        if (p->data == key){
            return index;
        }
     p = p->next;
        index++;
    } while (p != head);

    return -1;
}

void insertBefore(Node*& head, int key, int value){
    if (head == nullptr){
        std::cout << "List is empty.\n";
        return;
    }
    Node* p = new Node{value, nullptr};

    if (head->data == key){
        Node* last = head;

        while (last->next != head){
            last = last->next;
        }
        p->next = head;
        last->next = p;
        head = p;
        return;
    }
    Node* prev = head;
    Node* curr = head->next;

    while (curr != head && curr->data != key){
        prev = curr;
        curr = curr->next;
    }

    if (curr == head){
        delete p;
        std::cout << "Key not found.\n";
        return;
    }
    prev->next = p;
    p->next = curr;
}

void insertAfter(Node* head, int key, int value){
    if (head == nullptr){
        std::cout << "List is empty.\n";
        return;
    }
    Node* curr = head;

    do{
        if (curr->data == key){
            Node* p = new Node{value, curr->next};
            curr->next = p;
            return;
        }

        curr = curr->next;
    } while (curr != head);

    std::cout << "Key not found.\n";
}

void deleteNode(Node*& head, int key)
{
    if (head == nullptr){
        std::cout << "List is empty.\n";
        return;
    }
    Node* curr = head;
    Node* prev = nullptr;

    do{
        if (curr->data == key){
            if (curr->next == curr){
                delete curr;
                head = nullptr;
                return;
            }
            if (curr == head){
                Node* last = head;

                while (last->next != head){
                    last = last->next;
                }
                head = head->next;
                last->next = head;
            }
            else{
                prev->next = curr->next;
            }
            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != head);

    std::cout << "Key not found.\n";
}

void deleteAll(Node*& head){
    if (head == nullptr){
        std::cout << "List is already empty.\n";
        return;
    }
    Node* curr = head->next;

    while (curr != head){
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
    delete head;
    head = nullptr;

    std::cout << "All nodes deleted.\n";
}

void deleteEvenOddValues(Node*& head, bool even){
    if (head == nullptr){
        std::cout << "List is empty.\n";
        return;
    }

    while (head != nullptr &&((head->data % 2 == 0) == even)){
        if (head->next == head){
            delete head;
            head = nullptr;
            return;
        }
        Node* last = head;

        while (last->next != head){
            last = last->next;
        }
        Node* temp = head;
        head = head->next;
        last->next = head;
        delete temp;
    }
    if (head == nullptr){
        return;
    }
    Node* prev = head;
    Node* curr = head->next;

    while (curr != head){
        if ((curr->data % 2 == 0) == even){
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        else{
            prev = curr;
            curr = curr->next;
        }
    }
}

void josephus(int n, int k){
    if (n <= 0 || k <= 0)
    {
        std::cout << "Enter positive values.\n";
        return;
    }
    Node* head = nullptr;

    for (int i = 1; i <= n; i++){
        insertEnd(head, i);
    }
    Node* prev = head;

    while (prev->next != head){
        prev = prev->next;
    }
    Node* curr = head;

    while (curr->next != curr){
        for (int count = 1; count < k; count++){
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;

        if (curr == head){
            head = curr->next;
        }
        delete curr;
        curr = prev->next;
    }
    std::cout << "Survivor: " << curr->data << "\n";

    delete curr;
    head = nullptr;
}

void deleteEvenPositions(Node*& head){
    if (head == nullptr || head->next == head){
        std::cout << "No even-positioned nodes to delete.\n";
        return;
    }
    Node* prev = head;
    Node* curr = head->next;
    int position = 2;

    while (curr != head){
        if (position % 2 == 0){
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        else{
            prev = curr;
            curr = curr->next;
        }
        position++;
    }
}

int main(){

    Node* head = nullptr;
    int choice, value, key, n, k, position;

    do{
        std::cout << "\n===== CIRCULAR LINKED LIST =====\n";
        std::cout << "1. Activity 1: Creation\n";
        std::cout << "2. Activity 2: Access and Search\n";
        std::cout << "3. Activity 3: Insertion Before a Node\n";
        std::cout << "4. Activity 3: Insertion After a Node\n";
        std::cout << "5. Activity 4: Delete a Node\n";
        std::cout << "6. Activity 5: Delete Complete List\n";
        std::cout << "7. Lab Task 1: Delete Even/Odd Values\n";
        std::cout << "8. Lab Task 2: Josephus Problem\n";
        std::cout << "9. Lab Task 3: Delete Even Positions\n";
        std::cout << "10. Display List\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice){
        case 1:
            std::cout << "\nActivity 1: Creation of Circular Linked List\n";
            std::cout << "How many nodes? ";
            std::cin >> n;

            for (int i = 1; i <= n; i++){
                std::cout << "Enter value for node " << i << ": ";
                std::cin >> value;
                insertEnd(head, value);
            }

            std::cout << "Circular linked list: ";
            display(head);
            break;

        case 2:
            std::cout << "\nActivity 2: Accessing and Searching Nodes\n";
            std::cout << "List: ";
            display(head);

            std::cout << "Enter value to search: ";
            std::cin >> key;

            position = searchNode(head, key);

            if (position != -1){
                std::cout << "Node found at index: " << position << "\n";
            }
            else{
                std::cout << "Value not found.\n";
            }
            break;

        case 3:
            std::cout << "\nActivity 3: Insertion Before a Node\n";
            std::cout << "Enter key: ";
            std::cin >> key;
            std::cout << "Enter new value: ";
            std::cin >> value;

            insertBefore(head, key, value);

            std::cout << "Updated list: ";
            display(head);
            break;

       case 4:
            std::cout << "\nActivity 3: Insertion After a Node\n";
            std::cout << "Enter key: ";
            std::cin >> key;
            std::cout << "Enter new value: ";
            std::cin >> value;

            insertAfter(head, key, value);

            std::cout << "Updated list: ";
            display(head);
            break;

          case 5:
            std::cout << "\nActivity 4: Deleting a Node\n";
            std::cout << "Enter value to delete: ";
            std::cin >> key;

            deleteNode(head, key);

            std::cout << "Updated list: ";
            display(head);
            break;

        case 6:
            std::cout << "\nActivity 5: Complete Deletion\n";
            deleteAll(head);
            display(head);
            break;

      case 7:
            std::cout << "\nLab Task 1: Delete Even/Odd Values\n";
            std::cout << "1. Delete even values\n";
            std::cout << "2. Delete odd values\n";
            std::cout << "Enter choice: ";
            std::cin >> key;

            if (key == 1){
                deleteEvenOddValues(head, true);
            }
            else if (key == 2){
                deleteEvenOddValues(head, false);
            }
            else{
                std::cout << "Invalid choice.\n";
                break;
            }

            std::cout << "Updated list: ";
            display(head);
            break;

     case 8:
            std::cout << "\nLab Task 2: Josephus Problem\n";
            std::cout << "Enter number of people: ";
            std::cin >> n;
            std::cout << "Enter counting number k: ";
            std::cin >> k;

            josephus(n, k);
            break;

        case 9:
            std::cout << "\nLab Task 3: Delete Even-Positioned Nodes\n";
            deleteEvenPositions(head);

            std::cout << "Updated list: ";
            display(head);
            break;

      case 10:
            std::cout << "\nCircular Linked List:\n";
            display(head);
            break;

        case 0:
            std::cout << "\nExiting program.\n";
            deleteAll(head);
            break;

        default:
            std::cout << "Invalid choice.\n";
        }
    }while (choice != 0);

    return 0;
}
