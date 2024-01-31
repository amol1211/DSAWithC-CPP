//938. Range Sum of BST

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
    // Function to calculate the sum of values in the BST within the given range [low, high]
    int rangeSumBST(TreeNode* root, int low, int high) {
        
        // Base case: If the current node is null, return 0
        if (root == nullptr) return 0;
        
        // If the value of the current node is within the range [low, high],
        // include it in the sum and recursively check its left and right subtrees
        if (root->val >= low && root->val <= high) {
            return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
        }
        
        // If the value of the current node is less than low, it's not beneficial to go left, so go right
        if (root->val < low) {
            return rangeSumBST(root->right, low, high);
        }
        
        // If the value of the current node is greater than high, it's not beneficial to go right, so go left
        if (root->val > high) {
            return rangeSumBST(root->left, low, high);
        }

        // Default case, not strictly necessary, but added for completeness
        // This line is reached when root->val is equal to low or high
        return 0;
    }
};

/*Time Complexity: The time complexity of this algorithm is O(N), where N is the number of nodes in the 
binary search tree. In the worst case, we may have to visit all nodes.

Space Complexity: The space complexity is O(H), where H is the height of the binary search tree. 
In the worst case, the recursion stack can go as deep as the height of the tree.*/