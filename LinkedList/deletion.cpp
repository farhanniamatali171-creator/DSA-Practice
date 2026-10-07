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

    // 2. Assign data values 
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
    // SCENARIO 1: Deletion at Beginning
    // ==========================================
    std::cout << "Deletion at beginning: ";
    Node* tempBegin = head;
    head = head->next; // Move head forward
    delete tempBegin;  // Free old head

    // Print list after beginning deletion
    Node* curr1 = head;
    while (curr1 != nullptr)
    {
        std::cout << curr1->data << " ";
        curr1 = curr1->next;
    }
    std::cout << "\n\n";

    // ==========================================
    // SCENARIO 2: Deletion at End
    // ==========================================
    std::cout << "Deletion at end: ";
    Node* tail = fourth; // 'fourth' is our current tail
    
    // Walk until we reach the second-to-last node
    Node* tempEnd = head;
    while (tempEnd->next != tail)
    {
        tempEnd = tempEnd->next;
    }
    
    Node* targetEnd = tail;
    tempEnd->next = nullptr; // Cut off the last node
    tail = tempEnd;          // Update tail pointer
    delete targetEnd;        // Free the memory

    // Print list after end deletion
    Node* curr2 = head;
    while (curr2 != nullptr)
    {
        std::cout << curr2->data << " ";
        curr2 = curr2->next;
    }
    std::cout << "\n\n";

    // ==========================================
    // SCENARIO 3: Deletion at Middle
    // ==========================================
    std::cout << "Deletion at middle: ";
    int targetIndex = 1; // Position to delete (e.g., index 1)
    
    Node* n = head;
    for (int i = 0; i < targetIndex - 1; i++)
    {
        n = n->next;
    }
    
    Node* targetMiddle = n->next;
    n->next = targetMiddle->next; // Bypass the middle node
    delete targetMiddle;          // Free its memory

    // Print final list after middle deletion
    Node* curr3 = head;
    while (curr3 != nullptr)
    {
        std::cout << curr3->data << " ";
        curr3 = curr3->next;
    }
    std::cout << "\n";

    system("pause");
    return 0;
}
