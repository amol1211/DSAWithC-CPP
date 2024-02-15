//1008. Construct Binary Search Tree from Preorder Traversal

#include <iostream>
#include <vector>
#include <limits.h>
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
private:
    // Recursive function to construct the BST from preorder traversal
    TreeNode* solve(vector<int> &preorder, int mini, int maxi, int &i) {
        // Base case: If all elements in the preorder traversal are processed, return nullptr
        if (i >= preorder.size()) return nullptr;

        // If the current element is not within the valid range for the current subtree, return nullptr
        if (preorder[i] < mini || preorder[i] > maxi)
            return nullptr;

        // Create a new node with the current element and move to the next element in preorder
        TreeNode* root = new TreeNode(preorder[i++]);
        
        // Recursively construct the left subtree within the valid range [mini, root->val)
        root->left = solve(preorder, mini, root->val, i);
        
        // Recursively construct the right subtree within the valid range (root->val, maxi]
        root->right = solve(preorder, root->val, maxi, i);

        // Return the root of the constructed subtree
        return root;    
    }

public:
    // Function to construct the BST from preorder traversal
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // Define the initial range for the root node
        int mini = INT_MIN;
        int maxi = INT_MAX;

        // Initialize the index pointer for preorder traversal
        int i = 0;

        // Call the recursive function to construct the BST
        return solve(preorder, mini, maxi, i);
    }
};

  /*
 * Time Complexity: O(n) where n is the number of nodes in the BST.
 * Space Complexity: O(n) for the recursive stack space used by the solve function.
 */





