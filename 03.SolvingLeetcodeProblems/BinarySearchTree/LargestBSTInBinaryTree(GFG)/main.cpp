//Largest BST in a binary tree (GFG)

#include <iostream>
#include <climits> 
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) { // Constructor for creating a new node
        data = val;
        left = right = nullptr;
    }
};

class info {
public:
    int maxi; // Maximum value in the subtree rooted at this node
    int mini; // Minimum value in the subtree rooted at this node
    bool isBST; // Whether the subtree rooted at this node is a BST
    int size; // Size of the largest BST in the subtree rooted at this node

    // Constructor for creating an info object with given values
    info(int mx, int mn, bool bst, int sz) {
        maxi = mx;
        mini = mn;
        isBST = bst;
        size = sz;
    }
};

// Function to recursively solve the problem
info solve(Node* root, int &ans) {
    // Base case: if root is null, return an empty info object
    if (root == nullptr) {
        return info(INT_MIN, INT_MAX, true, 0);
    }

    // Recursively solve for left and right subtrees
    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    // Initialize info object for the current node
    info currNode(INT_MIN, INT_MAX, true, 0);

    // Calculate size, maximum, and minimum values for the current node
    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root->data, right.maxi);
    currNode.mini = min(root->data, left.mini);

    // Check if the subtree rooted at this node is a BST
    if (left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)) {
        currNode.isBST = true;
    }
    else {
        currNode.isBST = false;
    }

    // Update the answer if the subtree rooted at this node is a BST
    if (currNode.isBST) {
        ans = max(ans, currNode.size);
    }

    return currNode; // Return info object for the current node
}

class Solution{
public:
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root) {
        int maxSize = 0; // Initialize maximum size to 0
        info temp = solve(root, maxSize); // Call solve function to find the largest BST
        return maxSize; // Return the maximum size
    }
};


/*Time Complexity:

The time complexity of the solve function is O(N), where N is the number of nodes in the tree, as it visits each node once.
Space Complexity:

The space complexity is O(N), where N is the number of nodes in the tree. This is because of the recursion 
stack used in the solve function, which can go as deep as the height of the tree.*/