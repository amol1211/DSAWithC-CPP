//700. Search in a Binary Search Tree

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

/**
 * Iterative approach to search for a value in a Binary Search Tree (BST).
 * 
 * Time Complexity: O(h) - where 'h' is the height of the BST.
 * Space Complexity: O(1) - constant space is used as no additional data structures are used.
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // Initialize a temporary pointer to the root of the tree.
        TreeNode* temp = root;

        // Iterate until the pointer is not null.
        while (temp != nullptr) {
            // Check if the current node's value is equal to the target value.
            if (temp->val == val) {
                return temp; // Return the current node if found.
            }

            // If the target value is smaller, move to the left subtree.
            if (temp->val > val) {
                temp = temp->left;
            }
            // If the target value is larger, move to the right subtree.
            else {
                temp = temp->right;
            }
        }

        // If the target value is not found, return null.
        return temp;
    }
};


/*-----------------------------------------------------------------------*/


/**
 * Recursive approach to search for a value in a Binary Search Tree (BST).
 * 
 * Time Complexity: O(h) - where 'h' is the height of the BST.
 * Space Complexity: O(h) - where 'h' is the height of the BST (due to recursive call stack).
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // Base case: if the root is null or the root's value is equal to the target value.
        if (root == nullptr || root->val == val) {
            return root;
        }

        // If the target value is smaller, recursively search in the left subtree.
        if (root->val > val) {
            return searchBST(root->left, val);
        }
        // If the target value is larger, recursively search in the right subtree.
        else {
            return searchBST(root->right, val);
        }
    }
};
