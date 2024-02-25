//BST to max heap (GFG)

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

class Solution {
private:
    // Function to perform an in-order traversal of the binary tree and store the node values in a vector.
    void inOrder(Node* root, vector<int> &arr) {
        
        // Base case: If the root is null, return.
        if (!root) return;
        
        // Recursively traverse the left subtree.
        inOrder(root->left, arr);
        
        // Store the value of the current node in the vector.
        arr.push_back(root->data);
        
        // Recursively traverse the right subtree.
        inOrder(root->right, arr);
    }
    
    // Function to perform a post-order traversal of the binary tree and fill the nodes with values from a vector.
    void postOrderFill(Node* root, vector<int> &arr, int &i) {
        
        // Base case: If the root is null, return.
        if (!root) return;
        
        // Recursively fill the left subtree.
        postOrderFill(root->left, arr, i);
        
        // Recursively fill the right subtree.
        postOrderFill(root->right, arr, i);
        
        // Fill the current node with the value from the vector if there are remaining values, and increment the index.
        if (i < arr.size()) {
            root->data = arr[i++];
        }
    }
public:
    // Function to convert a binary tree to a max heap.
    void convertToMaxHeapUtil(Node* root)
    {
        // Vector to store the in-order traversal of the binary tree.
        vector<int> ans;
        
        // Perform an in-order traversal of the binary tree and store the node values in the vector.
        inOrder(root, ans);
        
        // Variable to keep track of the index in the vector.
        int index = 0;
        
        // Perform a post-order traversal of the binary tree and fill the nodes with values from the vector.
        postOrderFill(root, ans, index);
    }    
};

/*Time Complexity:

In-order traversal of the binary tree: O(n), where n is the number of nodes in the tree.
Post-order traversal of the binary tree: O(n), where n is the number of nodes in the tree.
Space Complexity:

Vector to store in-order traversal: O(n), where n is the number of nodes in the tree.
Recursive stack space: O(h), where h is the height of the tree. In the worst case, the height of the tree could be O(n), resulting in O(n) space complexity.*/