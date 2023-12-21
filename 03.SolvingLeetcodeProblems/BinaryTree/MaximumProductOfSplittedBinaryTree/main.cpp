//1339. Maximum Product of Splitted Binary Tree

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
private:
    // Total Sum
    int totalSum(TreeNode* root) {
        // Base case: if the node is null, return 0
        if (root == nullptr) return 0;

        // Recursively calculate the sum of the left subtree
        int leftSubtreeSum = totalSum(root->left);

        // Recursively calculate the sum of the right subtree
        int rightSubtreeSum = totalSum(root->right);

        // Calculate the total sum of the current subtree
        int sum = root->val + leftSubtreeSum + rightSubtreeSum;

        // Return the total sum
        return sum;
    }

    // Recursive function to find and calculate the maximum product
    int find(TreeNode* root) {
        // Base case: if the node is null, return 0
        if (root == nullptr) return 0;

        // Recursively calculate the sum of the left subtree
        int leftSum = find(root->left);

        // Recursively calculate the sum of the right subtree
        int rightSum = find(root->right);

        // Calculate the total sum of the current subtree
        long subTreeSum = root->val + leftSum + rightSum; // s1

        // Calculate the remaining sum in the tree (excluding the current subtree)
        long remainingSubTreeSum = SUM - subTreeSum; // s2

        // Update the maximum product if the current product is greater
        maxP = max(maxP, subTreeSum * remainingSubTreeSum);

        // Return the total sum of the current subtree
        return subTreeSum;
    }

public:
    long SUM = 0; // Total sum of the entire tree
    long maxP = 0; // Maximum product

    // Main function to calculate the maximum product of a binary tree
    int maxProduct(TreeNode* root) {
        // Base case: if the root is null, return 0
        if (root == nullptr) return 0;

        // Initialize the maximum product to 0
        maxP = 0;

        // Calculate the total sum of the entire tree
        SUM = totalSum(root);

        // Find and calculate the maximum product
        find(root);

        // Return the maximum product modulo 1000000007
        return maxP % (1000000007);
    }
};

//Time Complexity:O(n), where n is the number of nodes in the tree. 
//Space Complexity: O(H), where H is the height of the binary tree. This is the 
//maximum depth of the recursive call stack during the traversal. In the worst case, 
//the height of the tree is equal to the number of nodes in the tree (for a skewed tree), 
//making the space complexity O(N).





