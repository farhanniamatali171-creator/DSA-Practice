#include <iostream>
#include <cstdlib>

struct Node
{
    int data;
    Node* next;
};

int main()
{
    // 1. Create nodes
    Node* head = new Node;
    Node* second = new Node;
    Node* third = new Node;
    Node* fourth = new Node;

    // 2. Assign initial data values 
    head->data = 10;
    second->data = 20;
    third->data = 30;
    fourth->data = 40;
    
    // 3. Link the nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = nullptr;

    // Print Original List
    Node* curr = head;
    std::cout << "Original List: ";
    while (curr != nullptr)
    {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << "\n\n";

    // ==========================================
    // SCENARIO 1: Updation at Start
    // ==========================================
    std::cout << "Updation at start: ";
    head->data = 90; // No loop or pointers needed for the head!

    // Print list
    Node* asd1 = head;
    while (asd1 != nullptr)
    {
        std::cout << asd1->data << " ";
        asd1 = asd1->next;
    }
    std::cout << "\n\n";

    // ==========================================
    // SCENARIO 2: Updation at End
    // ==========================================
    std::cout << "Updation at end: ";
    fourth->data = 99; // Directly update the last node's data

    // Print list
    Node* asd2 = head;
    while (asd2 != nullptr)
    {
        std::cout << asd2->data << " ";
        asd2 = asd2->next;
    }
    std::cout << "\n\n";

    // ==========================================
    // SCENARIO 3: Updation at Middle
    // ==========================================
    std::cout << "Updation at middle: ";
    int targetIndex = 2; // Index of the node you want to update (e.g., third node)
    
    Node* n = head;
    for (int i = 0; i < targetIndex; i++)
    {
        n = n->next; // Walk to the target node
    }
    n->data = 555; // Update its value

    // Print final list
    Node* asd3 = head;
    while (asd3 != nullptr)
    {
        std::cout << asd3->data << " ";
        asd3 = asd3->next;
    }
    std::cout << "\n";

    system("pause");
    return 0;
}
