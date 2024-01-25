//Implementation of BST using Inorder traversal

#include <iostream>
#include <queue>
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

void inOrderTraversal(Node* root) { //LNR
    //Base case
    if (root == nullptr) {
        return;
    }

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

Node* insertIntoBST(Node* root, int data) {

    //Base case
    if (root == nullptr) {
        root = new Node(data);
        return root;
    }

    if (data > root->data) {
        //insert into right part of root node
        root->right = insertIntoBST(root->right, data);
    }
    else {
        //insert into left part of the root node
        root->left = insertIntoBST(root->left, data);
    }

    return root;
}

void takeInput(Node* &root) {

    int data;
    cin >> data;

    while (data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

int main() {
    Node* root = nullptr;

    cout << "Enter data to create BST" << endl;
    takeInput(root);

    cout << "Printing the BST using Inorder traversal" << endl;
    inOrderTraversal(root);

    return 0;
}

//10 8 21 7 27 5 4 3 -1
/*Printing the BST using Inorder traversal
3 4 5 7 8 10 21 27 */