//1457. Pseudo-Palindromic Paths in a Binary Tree

#include <iostream>
#include <vector>
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
    
    void solve(TreeNode* root, vector<int> &count) {
        
        // Base case: If the current node is null, return.
        if (root == nullptr) return;

        // Increment the count for the current digit.
        count[root->val]++;

        // Check if the current node is a leaf node.
        if (root->left == nullptr && root->right == nullptr) {
            
            // Count the odd frequencies of digits in the count vector.
            int oddFrequency = 0;
            for (int i = 1; i <= 9; i++) {
                if (count[i] % 2 != 0) { // If odd frequency
                    oddFrequency++;
                }
            }

            // If there is at most one digit with odd frequency, increment the result.
            if (oddFrequency <= 1) {
                result += 1;
            }
        }

        // Recursively traverse the left and right subtrees.
        solve(root->left, count);
        solve(root->right, count);

        // Decrement the count for the current digit (backtrack).
        count[root->val]--;
    }

public:
    // Public variable to store the final result.
    int result = 0;

    /**
     * Main function to calculate the number of pseudo-palindromic paths in a binary tree.
     * @param root: The root of the binary tree.
     * @return The number of pseudo-palindromic paths.
     */
    int pseudoPalindromicPaths(TreeNode* root) {
        
        // Initialize a vector to store the count of each digit (0 to 9).
        vector<int> count(10, 0);

        // Call the recursive helper function to solve the problem.
        solve(root, count);

        // Return the final result.
        return result;
    }
};


/*Time Complexity: O(N)

N is the number of nodes in the binary tree, and we visit each node once.
Space Complexity: O(H)

H is the height of the binary tree, and the space required for the count vector is proportional 
to the height of the tree due to recursion. In the worst case, when the tree is skewed, the space 
complexity is O(N), but in a balanced tree, it is O(log N).*/