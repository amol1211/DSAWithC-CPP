//1373. Maximum Sum BST in Binary Tree

#include <iostream>
#include <climits> 
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Define a class for storing information about the tree nodes
    class info {
    public:
        int maxi; // Maximum value in the subtree rooted at this node
        int mini; // Minimum value in the subtree rooted at this node
        bool isBST; // Whether the subtree rooted at this node is a BST
        int sum; // Sum of values in the subtree rooted at this node
    };

    // Function to recursively solve the problem
    info solve(TreeNode* root, int &ans) {
        // Base case: if root is null, return an empty info object
        if(root == NULL) {
            return {INT_MIN, INT_MAX, true, 0};
        }

        // Recursively solve for left and right subtrees
        info left = solve(root->left, ans);
        info right = solve(root->right, ans);

        // Initialize info object for the current node
        info currNode;

        // Calculate sum, maximum, and minimum values for the current node
        currNode.sum = left.sum + right.sum + root->val;
        currNode.maxi = max(root->val, right.maxi);
        currNode.mini = min(root->val, left.mini);

        // Check if the subtree rooted at this node is a BST
        if(left.isBST && right.isBST && (root->val > left.maxi && root->val < right.mini)) {
            currNode.isBST = true;
        } else {
            currNode.isBST = false;
        }

        // Update the answer if the subtree rooted at this node is a BST
        if(currNode.isBST) {
            ans = max(ans, currNode.sum);
        }

        return currNode; // Return info object for the current node
    }

    // Function to find the maximum sum BST
    int maxSumBST(TreeNode* root) {
        int maxSum = 0; // Initialize maximum sum to 0
        info temp = solve(root, maxSum); // Call solve function to find the maximum sum BST
        return maxSum; // Return the maximum sum
    }
};

/*Time Complexity:

The time complexity of the solve function is O(N), where N is the number of nodes in the tree, as it visits each node once.
Space Complexity:

The space complexity is O(N), where N is the number of nodes in the tree. This is because of 
the recursion stack used in the solve function, which can go as deep as the height of the tree.*/