//Flatten BST to sorted list (GFG)

#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};


class Solution
{
private:
    // Function to perform in-order traversal of the binary search tree
    // and store the values in the given vector
    void inOrder(Node* root, vector<int> &in) {
        if (!root) return;
        
        inOrder(root->left, in); // Traverse left subtree
        in.push_back(root->data); // Store current node's value
        inOrder(root->right, in); // Traverse right subtree
    }    

public:
    // Function to flatten a binary search tree into a linked list
    Node *flattenBST(Node *root)
    {
        if (!root) return nullptr; // Base case: empty tree

        vector<int> inOrderVal; // Vector to store in-order traversal values
        inOrder(root, inOrderVal); // Perform in-order traversal and store values

        Node* newRoot = new Node(inOrderVal[0]); // Create the root node using the provided newNode function
        Node* current = newRoot; // Pointer to keep track of the current node in the linked list

        // Loop through the in-order traversal values starting from index 1
        for (int i = 1; i < inOrderVal.size(); i++) {
            Node* temp = new Node(inOrderVal[i]); // Create new node with the value from inOrderVal

            current->left = nullptr; // Set left child to nullptr
            current->right = temp; // Link current node to the new node
            current = temp; // Move the current pointer to the new node
        }

        // Set the last node's right child to nullptr
        current->left = nullptr;
        current->right = nullptr;
        
        return newRoot; // Return the head of the flattened linked list
    }
}; 


/*Time Complexity:

The time complexity of in-order traversal of a binary search tree is O(n), where n is the number 
of nodes in the tree. Constructing the linked list from the in-order traversal values also takes O(n) 
time since we iterate through each value once.

Space Complexity:

The space complexity is O(n) due to the storage of in-order traversal values in the vector.*/