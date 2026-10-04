#include<iostream>

struct Node
{
   int data;
   Node* next;
};

int main(){

    Node* head=new Node;
    Node* second=new Node;
    Node* third=new Node;
//assign data values 
    head->data=50;
    second->data=60;
    third->data=70;
//link the nodes
    head->next=second;
    second->next=third;
    third->next=nullptr;

    Node* curr=head;
   std::cout<<"Orignal List: ";

    while (curr!=nullptr)
    {
        std::cout<<curr->data<<" ";
        curr=curr->next;
    }
    std::cout<<"\n";

//insertion at beginning
std::cout<<"Insertion at beginning: ";
    Node* newNode=new Node;
    newNode->data=5;
    newNode->next=head;
    head=newNode;

    Node* current=head;
    while (current!=nullptr)
    {
        std::cout<<current->data<<" ";
        current=current->next;
    }
    std::cout<<"\n";
    //insrtion at end
     Node* newNode1=new Node;
    newNode1->data=50;
    third->next=newNode1;
    newNode1->next=nullptr;

    std::cout<<"Insertion at end: ";
    Node* current1=head;
    while (current1!=nullptr)
    {
        std::cout<<current1->data<<" ";
        current1=current1->next;
    }
    std::cout<<"\n";

   
    return 0;


}
