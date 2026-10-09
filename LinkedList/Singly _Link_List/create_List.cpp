#include<iostream>
#include<stdlib.h>
using namespace std;


struct Node
{
    int data;
    Node* next;

};

int main(){

    Node* head =new Node;
    Node* second =new Node;
    Node* third =new Node;
  

    head->data=10;
    second->data=20;
    third->data=30;

    head->next=second;
    second->next=third;
    third->next=nullptr;

    Node* current=head;
    while (current!=nullptr)
    {
        cout<<current->data<<" ";
        current=current->next;
    }
    
    
    
   system("pause");
    return 0;
    
}
