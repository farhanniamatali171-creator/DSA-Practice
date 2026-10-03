#include <iostream>

struct Node{
    int data;
    Node* next;
    Node* prev;
};

struct SNode{
    int data;
    SNode* next;
};

int main(){
    Node* first = NULL;
    Node* last = NULL;

    // Activity 1: Creation of Doubly Linked List
    int n;

    std::cout << "Enter number of nodes: ";
    std::cin >> n;

    for (int i = 0; i < n; i++){
        Node* p = new Node;

        std::cout << "Enter data: ";
        std::cin >> p->data;

        p->next = NULL;
        p->prev = last;

        if (first == NULL){
            first = last = p;
        }
        else{
            last->next = p;
            last = p;
        }
    }

    // Activity 2: Accessing nodes
    std::cout << "\nForward: ";

    Node* p = first;

    while (p != NULL){
        std::cout << p->data << " ";
        p = p->next;
    }

    std::cout << "\nBackward: ";
    p = last;

    while (p != NULL){
        std::cout << p->data << " ";
        p = p->prev;
    }

    // Activity 3: Insertion
    // Insert before first
    p = new Node;

    std::cout << "\n\nEnter value to insert before first: ";
    std::cin >> p->data;

    p->prev = NULL;
    p->next = first;

    if (first == NULL){
        first = last = p;
    }
    else{
        first->prev = p;
        first = p;
    }

    // Insert after last
    p = new Node;

    std::cout << "Enter value to insert after last: ";
    std::cin >> p->data;

    p->next = NULL;
    p->prev = last;

    if (last == NULL){
        first = last = p;
    }
    else{
        last->next = p;
        last = p;
    }

    // Insert after a given key
    int key;

    std::cout << "Enter value after which to insert: ";
    std::cin >> key;

    Node* q = first;

    while (q != NULL && q->data != key){
        q = q->next;
    }

    if (q != NULL){
        p = new Node;

        std::cout << "Enter new value: ";
        std::cin >> p->data;

        p->prev = q;
        p->next = q->next;

        if (q->next != NULL)
            q->next->prev = p;
        else
            last = p;

        q->next = p;
    }
    else{
        std::cout << "Value not found.\n";
    }

    // Activity 4: Deletion
    // Delete first node
    if (first != NULL){
        p = first;
        first = first->next;

        if (first != NULL)
            first->prev = NULL;
        else
            last = NULL;

        delete p;

        std::cout << "First node deleted.\n";
    }

    // Delete last node
    if (last != NULL){
        p = last;
        last = last->prev;

        if (last != NULL)
            last->next = NULL;
        else
            first = NULL;

        delete p;

        std::cout << "Last node deleted.\n";
    }

    // Delete node by key
    std::cout << "Enter value to delete: ";
    std::cin >> key;

    p = first;

    while (p != NULL && p->data != key){
        p = p->next;
    }

    if (p != NULL){
        if (p->prev != NULL)
            p->prev->next = p->next;
        else
            first = p->next;

        if (p->next != NULL)
            p->next->prev = p->prev;
        else
            last = p->prev;

        delete p;

        std::cout << "Node deleted.\n";
    }
    else{
        std::cout << "Value not found.\n";
    }

    // Activity 5: Complete deletion
    // The list will be completely deleted later
    // after the graded tasks are completed.

    // Graded Lab Task 1: Reverse Doubly Linked 

    p = first;

    while (p != NULL){
        Node* temp = p->next;

        p->next = p->prev;
        p->prev = temp;

        p = temp;
    }

    p = first;
    first = last;
    last = p;

    std::cout << "\nReversed list: ";

    p = first;

    while (p != NULL){
        std::cout << p->data << " ";
        p = p->next;
    }

    // Graded Lab Task 2: Swap two actual nodes

    int value1, value2;

    std::cout << "\n\nEnter first value to swap: ";
    std::cin >> value1;

    std::cout << "Enter second value to swap: ";
    std::cin >> value2;

    Node* a = first;
    Node* b = first;

    while (a != NULL && a->data != value1)
        a = a->next;

    while (b != NULL && b->data != value2)
        b = b->next;

    if (a == NULL || b == NULL){
        std::cout << "One or both values not found.\n";
    }
    else if (a == b){
        std::cout << "Both values are in the same node.\n";
    }
    else{
        Node* aPrev = a->prev;
        Node* aNext = a->next;
        Node* bPrev = b->prev;
        Node* bNext = b->next;

        if (aNext == b){
            a->prev = b;
            a->next = bNext;

            b->prev = aPrev;
            b->next = a;

            if (aPrev != NULL)
                aPrev->next = b;
            else
                first = b;

            if (bNext != NULL)
                bNext->prev = a;
            else
                last = a;
        }
        else if (bNext == a){
            b->prev = a;
            b->next = aNext;

            a->prev = bPrev;
            a->next = b;

            if (bPrev != NULL)
                bPrev->next = a;
            else
                first = a;

            if (aNext != NULL)
                aNext->prev = b;
            else
                last = b;
        }
        else{
            a->prev = bPrev;
            a->next = bNext;

            b->prev = aPrev;
            b->next = aNext;

            if (aPrev != NULL)
                aPrev->next = b;
            else
                first = b;

            if (aNext != NULL)
                aNext->prev = b;
            else
                last = b;

            if (bPrev != NULL)
                bPrev->next = a;
            else
                first = a;

            if (bNext != NULL)
                bNext->prev = a;
            else
                last = a;
        }

        std::cout << "Nodes swapped successfully.\n";
    }

    std::cout << "List after swapping: ";

    p = first;

    while (p != NULL){
        std::cout << p->data << " ";
        p = p->next;
    }

    // Graded Lab Task 3:
    // Convert Singly Linked List to Doubly Linked List

    SNode* sFirst = NULL;
    SNode* sLast = NULL;

    std::cout << "\n\nEnter number of nodes for singly linked list: ";
    std::cin >> n;

    for (int i = 0; i < n; i++){
        SNode* s = new SNode;

        std::cout << "Enter data: ";
        std::cin >> s->data;

        s->next = NULL;

        if (sFirst == NULL){
            sFirst = sLast = s;
        }
        else{
            sLast->next = s;
            sLast = s;
        }
    }

    // Delete old doubly linked list
    while (first != NULL){
        p = first;
        first = first->next;
        delete p;
    }

    last = NULL;

    // Convert singly list to doubly list
    SNode* s = sFirst;

    while (s != NULL){
        Node* d = new Node;

        d->data = s->data;
        d->next = NULL;
        d->prev = last;

        if (first == NULL){
            first = last = d;
        }
        else{
            last->next = d;
            last = d;
        }

        s = s->next;
    }

    std::cout << "Doubly linked list after conversion: ";

    p = first;

    while (p != NULL){
        std::cout << p->data << " ";
        p = p->next;
    }

    // Activity 5: Complete deletion
    //keep it in last as it delete everything

    while (first != NULL){
        p = first;
        first = first->next;
        delete p;
    }

    last = NULL;

    while (sFirst != NULL){
        s = sFirst;
        sFirst = sFirst->next;
        delete s;
    }

    std::cout << "\nAll nodes of Doubly Linked List have been deleted.";

    return 0;
}
