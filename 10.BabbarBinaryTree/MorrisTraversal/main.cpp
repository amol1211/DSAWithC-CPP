#include <iostream>
using namespace std;

// Define a class for a binary tree node
class Node {

public:
    int data;        // Data stored in the node
    Node* left;      // Pointer to the left child
    Node* right;     // Pointer to the right child
    
    // Constructor to initialize the node with data
    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Function to perform Morris Traversal on a binary tree
void MorrisTraversal(Node* root) {
    Node* current, *prev;

    // Check if the tree is empty
    if (root == nullptr) return;

    // Start from the root of the tree
    current = root;
    while (current != nullptr) {
        // If the left child is null, print the current node and move to the right child
        if (current->left == nullptr) {
            cout << current->data << " ";
            current = current->right;
        }
        else {
            // Find the in-order predecessor (rightmost node in the left subtree)
            prev = current->left;
            while (prev->right != nullptr && prev->right != current)
                prev = prev->right;

            // If the predecessor's right child is null, set it to the current node and move to the left child
            if (prev->right == nullptr) {
                prev->right = current;
                current = current->left;
            }
            else {
                // If the predecessor's right child is the current node, reset it to null, print the current node,
                // and move to the right child
                prev->right = nullptr;
                cout << current->data << " ";
                current = current->right;
            }      
        }
    }
}
 
// Function to create a new binary tree node with the given data
Node* newNode(int data) {
    Node* node = new Node(data);
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;

    return (node);
}

// The main function
int main() {
    // Create a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Perform Morris Traversal on the binary tree
    MorrisTraversal(root);

    return 0;
}

/* Constructed binary tree is
            1
          /   \
         2     3
       /   \
      4     5
  */

 /*output : 4 2 5 1 3 */