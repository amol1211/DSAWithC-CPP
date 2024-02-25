//Convert BST into Min Heap(Coding Ninja)

#include <bits/stdc++.h> 
using namespace std;

    class BinaryTreeNode {
        
    public :
        int data;
        BinaryTreeNode* left;
        BinaryTreeNode* right;

        BinaryTreeNode(int data) {
            this -> left = NULL;
            this -> right = NULL;
            this -> data = data;
        }
    };


// Function to perform an in-order traversal of the binary tree and store the node values in a vector.
void inOrder(BinaryTreeNode* root, vector<int> &arr) {

    // Base case: If the root is null, return.
    if (!root) return;

    // Recursively traverse the left subtree.
    inOrder(root->left, arr);

    // Store the value of the current node in the vector.
    arr.push_back(root->data);

    // Recursively traverse the right subtree.
    inOrder(root->right, arr);
}

// Function to perform a pre-order traversal of the binary tree and fill the nodes with values from a vector.
void preOrderFill(BinaryTreeNode* root, vector<int> &arr, int &i) {

    // Base case: If the root is null, return.
    if (!root) return;

    // Fill the current node with the value from the vector and increment the index.
    root->data = arr[i++];

    // Recursively fill the left subtree.
    preOrderFill(root->left, arr, i);

    // Recursively fill the right subtree.
    preOrderFill(root->right, arr, i);
}

// Function to convert a Binary Search Tree (BST) to a Greater Sum Tree (GST).
BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
    // Vector to store the in-order traversal of the binary tree.
    vector<int> ans;
    
    // Perform an in-order traversal of the binary tree and store the node values in the vector.
    inOrder(root, ans);

    // Variable to keep track of the index in the vector.
    int index = 0;

    // Perform a pre-order traversal of the binary tree and fill the nodes with values from the vector.
    preOrderFill(root, ans, index);

    // Return the root of the modified binary tree.
    return root;
}

/*Time Complexity:

In-order traversal of the binary tree: O(n), where n is the number of nodes in the tree.
Pre-order traversal of the binary tree: O(n), where n is the number of nodes in the tree.
Space Complexity:

Vector to store in-order traversal: O(n), where n is the number of nodes in the tree.
Recursive stack space: O(h), where h is the height of the tree. In the worst case, the height of the tree could be O(n), resulting in O(n) space complexity.*/