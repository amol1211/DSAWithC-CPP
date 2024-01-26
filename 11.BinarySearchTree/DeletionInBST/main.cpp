//Deletion of Node in BST

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

Node* minVal(Node* root) {
    Node* temp = root;
    
    while(temp->left != nullptr) {
        temp = temp->left;
    }
    return temp;
}

Node* maxVal(Node* root) {
    Node* temp = root;
    
    while(temp->right != nullptr) {
        temp = temp->right;
    }
    return temp;
}

Node* deleteFromBST(Node* root, int val) {
    //Base case
    if (root == nullptr) {
        return root;
    }

    if (root->data == val) {
        //O child (leaf node)
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }

        //1 child

        //left child
        if (root->left != nullptr && root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        //right child
        if (root->left == nullptr && root->right != nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        //2 child
        if (root->left != nullptr && root->right != nullptr) {
            //we have to first either find maximum value from left 
            //OR
            //Find minimun value from right
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }
    else if (root->data > val) {
        //Go to left part of BST
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else {
        //Go to right part of BST
        root->right = deleteFromBST(root->right, val);
        return root;
    }
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
    
    cout << endl << "Minimum value is " << minVal(root)->data << endl;
    cout << "Maximum value is " << maxVal(root)->data << endl;
    
    // Deletion
    int deleteValue;
    cout << "Enter the value to delete from BST: ";
    cin >> deleteValue;
    
    root = deleteFromBST(root, 27);
    
    cout << "Printing the BST after deletion of node" << endl;
    inOrderTraversal(root);
    return 0;
}

