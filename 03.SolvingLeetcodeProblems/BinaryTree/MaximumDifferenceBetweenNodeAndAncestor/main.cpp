//1026. Maximum Difference Between Node and Ancestor

#include <iostream>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//Approach 1 : Brute force DFS

class Solution {
private:
    // Helper function to find the maximum difference recursively
    void findMaxDiffUtil(TreeNode* root, TreeNode* child) {
        // Base case: if either root or child is null, return
        if (root == nullptr || child == nullptr) return;

        // Update maxDiff with the absolute difference between root and child
        maxDiff = max(maxDiff, abs(root->val - child->val));

        // Recursively call on left and right children of root
        findMaxDiffUtil(root, child->left);
        findMaxDiffUtil(root, child->right);
    }  

    // Main function to find the maximum difference for each node
    void findMaxDiff(TreeNode* root) {
        // Base case: if root is null, return
        if (root == nullptr) return;

        // Recursively call on left and right children of root
        findMaxDiffUtil(root, root->left);
        findMaxDiffUtil(root, root->right);

        // Recursively call on left and right subtrees of root
        findMaxDiff(root->left);
        findMaxDiff(root->right);
    }

public:
    int maxDiff;
    
    // Main function to find the maximum ancestor difference
    int maxAncestorDiff(TreeNode* root) {
        // Initialize maxDiff to -1
        maxDiff = -1;

        // Call the helper function to find the maximum difference
        findMaxDiff(root);

        // Return the result
        return maxDiff;
    }
};

//Time Complexity:O(n^2), where n is the number of nodes in the tree. 
//Space Complexity:O(h), O(h), where h is the height of the tree. 
//In the worst case (skewed tree), it would be O(n), and in the best 
//case (balanced tree), it would be O(log n).

/*------------------------------------------------------------------------------------*/

//Approach 2 : Optimized DFS

class Solution {
private:
    // Helper function to find the maximum difference efficiently
    int findMaxDiff(TreeNode* root, int minV, int maxV) {
        // Base case: if root is null, return the absolute difference between maxV and minV
        if (root == nullptr) {
            return abs(maxV - minV);
        }

        // Update minV and maxV based on the current node's value
        minV = min(minV, root->val);
        maxV = max(maxV, root->val);

        // Recursively call on left and right subtrees and return the maximum of the two
        int l = findMaxDiff(root->left, minV, maxV);
        int r = findMaxDiff(root->right, minV, maxV);

        return max(l, r);
    }    

public:
    // Main function for optimized approach
    int maxAncestorDiff(TreeNode* root) {
        // Call the helper function with initial minV and maxV set to root's value
        return findMaxDiff(root, root->val, root->val);
    }
};

//Time Complexity:O(n), where n is the number of nodes in the tree. 
//Space Complexity:O(h), O(h), where h is the height of the tree. 
//In the worst case (skewed tree), it would be O(n), and in the best 
//case (balanced tree), it would be O(log n).