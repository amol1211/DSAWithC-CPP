#include <iostream>
using namespace std;

class Node {

    public:
    int data;
    Node* left;
    Node* right;
    
    //Constructor
    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

Node* buildTree(Node* root) {
    cout << "Enter the data: " << '\n';
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1) {
        return nullptr;
    }

    cout << "Enter data for inserting in left of " << data << '\n';
    root->left = buildTree(root->left);
    cout << "Enter data for inserting at right of " << data << '\n';
    root->right = buildTree(root->right);
    return root;
}

int main() {
    Node* root = nullptr;

    //Creating a tree 
    root = buildTree(root);



    return 0;
}