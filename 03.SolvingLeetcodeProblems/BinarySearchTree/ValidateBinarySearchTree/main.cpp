//98. Validate Binary Search Tree

#include <iostream>
#include <stack>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
 //Approach 1 : Iterative approach

class Solution {
public:
    // Function to check if the given binary tree is a valid BST (Iterative Approach)
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;

        // Stack to perform iterative inorder traversal
        stack<TreeNode*> st;

        // Pointer to keep track of the previously visited node
        TreeNode* prev = nullptr;

        // Iterate through the tree nodes
        while (root != nullptr || !st.empty()) {
            // Push nodes to the stack while moving to the leftmost node
            while (root != nullptr) {
                st.push(root);
                root = root->left;
            }

            // Pop the top node from the stack
            root = st.top();
            st.pop();

            // Check if the current node's value is greater than or equal to the previous node's value
            if (prev != nullptr && prev->val >= root->val) {
                return false;
            }

            // Update the previously visited node to the current node
            prev = root;

            // Move to the right child
            root = root->right;     
        } 

        // All nodes have been processed, and the tree is a valid BST
        return true;
    }
};

/*Time Complexity: O(N) - where N is the number of nodes in the tree
Space Complexity: O(H) - where H is the height of the tree (worst-case H=N for a skewed tree)*/

/*----------------------------------------------------------------------------------------------------*/

//Approach 2 : Recursive approach

class Solution {
private:
    // Recursive helper function to check if the given binary tree is a valid BST
    bool isValidBSTHelper(TreeNode* root, long long minValue, long long maxValue) {
        if (root == nullptr) return true;

        // Check if the current node's value is within the valid range
        if (root->val <= minValue || root->val >= maxValue) return false;

        // Recursively check the left and right subtrees
        return isValidBSTHelper(root->left, minValue, root->val) && isValidBSTHelper(root->right, root->val, maxValue);
    }

public:
    // Main function to check if the given binary tree is a valid BST (Recursive Approach)
    bool isValidBST(TreeNode* root) {
        // Start with the initial valid range for the root node
        return isValidBSTHelper(root, LONG_LONG_MIN, LONG_LONG_MAX);
    }
};


/* Time Complexity: O(N) - where N is the number of nodes in the tree
Space Complexity: O(H) - where H is the height of the tree (worst-case H=N for a skewed tree) */