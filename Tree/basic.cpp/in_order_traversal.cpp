#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val, Node* l = nullptr, Node* r = nullptr)
        : data(val), left(l), right(r) {}
};

// In-Order Traversal 
void inOrder(Node* root) {
    if (root==nullptr)
    {
      return;
    }
    inOrder(root->left);
    std::cout<<root->data<<" ";
    inOrder(root->right);
    
}

int main() {
    // Constructing BST
    Node* root = new Node(100);
    root->left = new Node(50, new Node(25), new Node(75));
    root->right = new Node(150);

    std::cout << "In-Order Traversal of BST: ";
    inOrder(root);
    std::cout << std::endl;

    
    return 0;
}
