//2265. Count Nodes Equal to Average of Subtree

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

// Approach 1 : Brute force approach

class Solution {
private:
    // Helper function to calculate the sum of values in the subtree rooted at 'root'
    int sum(TreeNode* root, int &count) {
        // Base case: if the node is null, return 0
        if (!root) return 0;

        // Increment the count for each node encountered
        count++;

        // Recursively calculate the sum of values in the left and right subtrees
        int leftSum = sum(root->left, count);
        int rightSum = sum(root->right, count);

        // Return the sum of values in the current subtree
        return leftSum + rightSum + root->val;
    }

    // Helper function to recursively solve the problem
    void solve(TreeNode* root) {
        // Base case: if the node is null, return
        if (!root) return;

        // Initialize count for the current subtree
        int count = 0;

        // Calculate the total sum of values in the current subtree
        int totalSum = sum(root, count);

        // Check if the average of the subtree is equal to the value of the root
        if (totalSum / count == root->val) {
            result++;  // Increment the result count
        }

        // Recursively process the left and right subtrees
        solve(root->left);
        solve(root->right);
    }

public:
    int result;  // Result variable to store the count of subtrees satisfying the condition

    // Main function to find the count of subtrees where the average is equal to the root value
    int averageOfSubtree(TreeNode* root) {
        result = 0;  // Initialize result to 0

        solve(root);  // Start the recursive process

        return result;  // Return the final result count
    }
};

//Time Complexity: O(N^2), where N is the number of nodes in the tree.
//Space Complexity: O(H), where H is the height of the tree, representing 
//the maximum depth of the recursion stack.

/*-------------------------------------------------------------------------------------------------*/

// Appraoch 2 : Recursive pair pattern (where we traverse from bottom to up)

class Solution {
private:
    // Helper function to recursively calculate the total sum and node count in the subtree rooted at 'root'
    pair<int, int> solve(TreeNode* root) {
        // Base case: if the node is null, return {0, 0}
        if (!root) {
            return {0, 0};
        }

        // Recursively calculate the sum and count in the left subtree
        auto left = solve(root->left);
        // Recursively calculate the sum and count in the right subtree
        auto right = solve(root->right);

        // Calculate the total sum and node count in the current subtree
        int totalSum = left.first + right.first + root->val;
        int totalCount = left.second + right.second + 1;

        // Calculate the average of the subtree
        int avg = totalSum / totalCount;

        // Check if the average is equal to the value of the root
        if (avg == root->val) {
            result += 1;  // Increment the result count
        }

        // Return the total sum and node count in the current subtree
        return {totalSum, totalCount};
    }

public:
    int result;  // Result variable to store the count of subtrees satisfying the condition

    // Main function to find the count of subtrees where the average is equal to the root value
    int averageOfSubtree(TreeNode* root) {
        result = 0;  // Initialize result to 0

        solve(root);  // Start the recursive process

        return result;  // Return the final result count
    }
};

//Time Complexity: O(N), where N is the number of nodes in the tree.
//Space Complexity: O(H), where H is the height of the tree, representing 
//the maximum depth of the recursion stack.