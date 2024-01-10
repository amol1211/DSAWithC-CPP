// 1448. Count Good Nodes in Binary Tree

#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// This class represents a solution for counting "good" nodes in a binary tree.
class Solution {
private: 
    // Helper function for depth-first search (DFS) traversal.
    // Parameters:
    //   - root: The current node in the traversal.
    //   - currentMax: The maximum value encountered so far in the path from the root to the current node.
    void dfs(TreeNode* root, int currentMax) {
        
        // Base case: If the current node is null, return.
        if (!root) return;

        // Check if the value of the current node is greater than or equal to the current maximum.
        if (root->val >= currentMax) {
            // If true, increment the count of "good" nodes.
            count++;
            // Update the current maximum for the subsequent recursive calls.
            currentMax = root->val;
        }
        
        // Recursive call for the left subtree.
        dfs(root->left, currentMax);
        // Recursive call for the right subtree.
        dfs(root->right, currentMax);
    } 
    
public:
    // Public function to calculate the count of "good" nodes in the binary tree.
    // Parameter:
    //   - root: The root of the binary tree.
    // Returns:
    //   - The count of "good" nodes in the binary tree.
    int count = 0;   
    int goodNodes(TreeNode* root) {
        // Initial call to the DFS function with the root of the tree and its value as the current maximum.
        dfs(root, root->val);
        // Return the final count of "good" nodes.
        return count;
    }
};

// Time Complexity: O(N), where N is the number of nodes in the binary tree.
//   - The DFS traversal visits each node once.
// Space Complexity: O(H), where H is the height of the binary tree.
//   - The space complexity is dominated by the recursive call stack during DFS.
//   - In the worst case, when the tree is skewed, the height H is equal to the 
//number of nodes N, resulting in O(N) space complexity.
