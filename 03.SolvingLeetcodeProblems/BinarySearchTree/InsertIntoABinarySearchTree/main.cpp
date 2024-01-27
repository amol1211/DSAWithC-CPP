//701. Insert into a Binary Search Tree

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

class Solution {
public:
    // Function to insert a value into a Binary Search Tree (BST).
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // If the current node is null, create a new node with the given value.
        if (root == nullptr) {
            root = new TreeNode(val);
            return root;
        }

        // If the value to be inserted is greater than the current node's value,
        // insert into the right subtree.
        if (val > root->val) {
            root->right = insertIntoBST(root->right, val);
        } 
        // If the value to be inserted is less than or equal to the current node's value,
        // insert into the left subtree.
        else {
            root->left = insertIntoBST(root->left, val);
        }

        // Return the updated root node.
        return root;
    }
};

/*Time Complexity:

The time complexity of this algorithm is O(h), where 'h' is the height of the binary tree.
In the worst case (skewed tree), the time complexity approaches O(n), but in a balanced tree, it is O(log n).
Space Complexity:

The space complexity is O(h), where 'h' is the height of the binary tree.
In the worst case (skewed tree), the space complexity approaches O(n), but in a balanced tree, it is O(log n).
The space complexity is primarily due to the recursive call stack.*/