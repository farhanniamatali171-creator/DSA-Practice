#include<iostream>
  
struct Node
{
    int data;
    Node* next;
    Node* prev;
};

int main(){
    Node* head=new Node;
    Node* second=new Node;
    Node* third=new Node;
    Node* fourth=new Node;

    head->data=10;
    second->data=20;
    third->data=30;
    fourth->data=40;

    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=head;

    head->prev=fourth;
    second->prev=head;
    third->prev=second;
    fourth->prev=third;

    std::cout << head->data <<" ";
    std::cout << second->data << " ";
    std::cout << third->data << " ";
    std::cout << fourth->data << "\n";

  
    return 0;
}
