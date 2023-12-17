//814. Binary Tree Pruning

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

// Approach 1 : Brute force

class Solution {
private:
    // Helper function to check if '1' is present in the subtree rooted at 'root'
    bool isOnePresent(TreeNode* root) {
        // Base case: If the node is null, '1' is not present
        if (!root) return false;

        // If the current node's value is '1', return true
        if (root->val == 1) return true;

        // Recursively check for '1' in the left or right subtrees
        return isOnePresent(root->left) || isOnePresent(root->right);
    }

public:
    // Main function to prune the binary tree
    TreeNode* pruneTree(TreeNode* root) {
        // Base case: If the node is null, return null
        if (root == nullptr) return nullptr;

        // Prune the left subtree if '1' is not present
        if (!isOnePresent(root->left))
            root->left = nullptr;

        // Prune the right subtree if '1' is not present
        if (!isOnePresent(root->right))
            root->right = nullptr; 

        // Recursively prune the left and right subtrees
        pruneTree(root->left);
        pruneTree(root->right);

        // Prune the current node if it has value '0' and has no children
        if(root->left == nullptr && root->right == nullptr && root->val == 0)
            return nullptr;

        // Return the pruned root
        return root;           
    }
};

//Time Complexity: O(N^2)
//Space Complexity: O(H), where H is the height of the binary tree. 
//This is due to the recursive call stack during the post-order traversal. 
//In the worst case, the height of the call stack is equal to the height of the tree.

/*--------------------------------------------------------------------------------------*/

//Appraoch 2 : Optimized 

class Solution {
public:
    // Main function to prune the binary tree
    TreeNode* pruneTree(TreeNode* root) {
        // Base case: If the node is null, return null
        if (!root) return nullptr;

        // Recursively prune the left and right subtrees
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);

        // Prune the current node if it has value '0' and has no children
        if (root->left == nullptr && root->right == nullptr && root->val == 0) 
            return nullptr;

        // Return the pruned root
        return root;
    }
};

//Time Complexity: O(N), where N is the number of nodes in the binary tree. 
//This is because each node is visited once in the post-order traversal.
//Space Complexity: O(H)