//Search a node in BST (GFG)

#include <iostream>
using namespace std;

struct Node {
      int data;
      Node *left;
      Node *right;
      Node() : data(0), left(nullptr), right(nullptr) {}
      Node(int x) : data(x), left(nullptr), right(nullptr) {}
      Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};

/**
 * Iterative approach to search for a node with value 'x' in a Binary Search Tree (BST).
 * 
 * Time Complexity: O(h) - where 'h' is the height of the BST.
 * Space Complexity: O(1) - constant space is used as no additional data structures are used.
 */
bool search(Node* root, int x) {
    // Initialize a temporary pointer to the root of the tree.
    Node* temp = root;
    
    // Iterate until the temporary pointer is not null.
    while (temp != nullptr) {
        // Check if the current node's value is equal to the target value 'x'.
        if (temp->data == x) {
            return true; // Return true if found.
        }
        
        // If the target value 'x' is smaller, move to the left subtree.
        if (temp->data > x) {
            temp = temp->left;
        }
        // If the target value 'x' is larger, move to the right subtree.
        else {
            temp = temp->right;
        }
    }
    
    // If the target value 'x' is not found, return false.
    return false;
}

/*----------------------------------------------------------------------------------------*/

/**
 * Recursive approach to search for a node with value 'x' in a Binary Search Tree (BST).
 * 
 * Time Complexity: O(h) - where 'h' is the height of the BST.
 * Space Complexity: O(h) - where 'h' is the height of the BST (due to recursive call stack).
 */
bool search(Node* root, int x) {
    // Base case: if the current node is null, the value 'x' is not found.
    if (root == nullptr) {
        return false;
    }
    
    // Check if the current node's value is equal to the target value 'x'.
    if (root->data == x) {
        return true; // Return true if found.
    }
    
    // If the target value 'x' is smaller, recursively search in the left subtree.
    if (root->data > x) {
        return search(root->left, x);
    }
    // If the target value 'x' is larger, recursively search in the right subtree.
    else {
        return search(root->right, x);
    }
}
