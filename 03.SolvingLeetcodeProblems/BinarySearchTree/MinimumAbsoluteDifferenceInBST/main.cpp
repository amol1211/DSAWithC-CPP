//530. Minimum Absolute Difference in BST

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
private:
    // Helper function for in-order traversal to find minimum difference
    void inOrder(TreeNode* root, TreeNode* &prev) {
        // Base case: if the current node is null, return
        if (!root) return;

        // Traverse the left subtree
        inOrder(root->left, prev);

        // Check the difference between the current node and the previous node
        if (prev != nullptr) {
            minDiff = min(minDiff, root->val - prev->val);
        }

        // Update the previous node to the current node
        prev = root;

        // Traverse the right subtree
        inOrder(root->right, prev);
    }

public:
    // Initialize the minimum difference to the maximum possible value
    int minDiff = INT_MAX;

    // Main function to get the minimum absolute difference
    int getMinimumDifference(TreeNode* root) {
        // Initialize the previous node to null
        TreeNode* prev = nullptr;

        // Call the inOrder helper function to perform in-order traversal
        inOrder(root, prev);

        // Return the minimum absolute difference found during traversal
        return minDiff;
    }
};


/*Time Complexity: The time complexity is O(n), where n is the number of nodes in the binary search tree. 
This is because the algorithm performs an in-order traversal of the entire tree, visiting each node once.

Space Complexity: The space complexity is O(h), where h is the height of the binary search tree. 
In the worst case, if the tree is skewed, the recursive call stack can reach a depth equal to the height 
of the tree. In a balanced BST, the height is O(log n), making the space complexity O(log n).*/