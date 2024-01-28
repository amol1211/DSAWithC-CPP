//450. Delete Node in a BST

#include <iostream>
using namespace std;

   struct TreeNode {
       int val;
       TreeNode* left;
       TreeNode* right;

       TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
private:
    // Helper function to find the minimum value in a subtree
    TreeNode* minVal(TreeNode* root) {
        TreeNode* temp = root;
        while (temp->left != nullptr) {
            temp = temp->left;
        }
        return temp;
    }

public:
    // Function to delete a node with a specific key from the BST
    TreeNode* deleteNode(TreeNode* root, int key) {
        // Base case: if the root is null, return null
        if (root == nullptr) {
            return root;
        }

        // If the key is less than the root's value, delete from the left subtree
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        // If the key is greater than the root's value, delete from the right subtree
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // Node with only one child or no child
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Node with two children
            // Find the inorder successor (smallest in the right subtree)
            //we have to first either find maximum value from left 
            //OR
            //Find minimun value from right
            int minValue = minVal(root->right)->val;
            root->val = minValue;
            // Delete the inorder successor
            root->right = deleteNode(root->right, minValue);
        }

        return root;
    }
};


/*Time Complexity:

The time complexity of the deleteNode function is O(h), where h is the height 
of the binary search tree.

Space Complexity:

The space complexity is O(h), where h is the height of the binary search tree. 
This is due to the recursive nature of the deleteNode function, which uses the call stack. 
In the worst case (skewed tree), the space complexity can be O(n), where n is the number of 
nodes in the tree.
*/