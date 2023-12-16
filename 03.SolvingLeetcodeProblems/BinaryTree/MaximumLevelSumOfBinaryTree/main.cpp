//1161. Maximum Level Sum of a Binary Tree

#include <iostream>
#include <queue>
#include <map>
#include <climits>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//Approach 1 : BFS (level order traversal)
class Solution {
public:
    // Function to find the level with the maximum sum in a binary tree
    int maxLevelSum(TreeNode* root) {
        // Initialize variables to track the maximum sum and the corresponding level
        int maxSum = INT_MIN;
        int resultLevel = 0;

        // Queue for BFS traversal
        queue<TreeNode*> q;
        q.push(root); // Start with the root node

        int currentLevel = 1; // Variable to track the current level during traversal

        // BFS traversal
        while (!q.empty()) {
            int n = q.size(); // Number of nodes at the current level

            int sum = 0; // Variable to store the sum of values at the current level

            // Traverse all elements at the current level
            while (n--) {
                TreeNode* temp = q.front();
                q.pop();

                sum += temp->val; // Add the value of the current node to the sum

                // Enqueue the left and right child nodes if they exist
                if (temp->left) {
                    q.push(temp->left);
                }

                if (temp->right) {
                    q.push(temp->right);
                }
            }

            // Check if the sum at the current level is greater than the maximum sum
            if (sum > maxSum) {
                maxSum = sum; // Update the maximum sum
                resultLevel = currentLevel; // Update the result level
            }

            currentLevel++; // Move to the next level
        }

        // Return the level with the maximum sum
        return resultLevel;
    }
};

// Time Complexity: O(N) where N is the number of nodes in the binary tree
// Each node is processed once during the BFS traversal.
// Space Complexity: O(W) where W is the maximum width of the tree (number of nodes at the maximum level).
// In the worst case, the queue can contain all nodes at the last level of the tree.

/*-----------------------------------------------------------------------------------------------------------*/
// Approach 2 : DFS approach

class Solution {
private:
    // Map to store the sum of node values for each level during DFS traversal
    map<int, int> mp;

    // DFS function to traverse the binary tree and accumulate node values
    void DFS(TreeNode* root, int level) {
        // Base case: If the current node is NULL, return
        if (!root) return;

        // Increment the sum for the current level in the map
        mp[level] += root->val;

        // Recursive calls for the left and right subtrees with increased level
        DFS(root->left, level + 1);
        DFS(root->right, level + 1);
    }

public:
    // Function to find the level with the maximum sum in a binary tree
    int maxLevelSum(TreeNode* root) {
        // Clear the map before starting a new DFS traversal
        mp.clear();
        // Perform DFS traversal to accumulate sums for each level
        DFS(root, 1);
        
        // Initialize variables to track the maximum sum and the corresponding level
        int maxSum = INT_MIN;
        int resultLevel = 0;

        // Iterate over the entries in the map to find the level with the maximum sum
        for (auto it : mp) {
            int level = it.first;
            int sum = it.second;

            // Update maxSum and resultLevel if the current sum is greater
            if (sum > maxSum) {
                maxSum = sum;
                resultLevel = level;
            }
        }

        // Return the level with the maximum sum
        return resultLevel;
    }
};

// Time Complexity: O(N) where N is the number of nodes in the binary tree
// Each node is processed once during the DFS traversal.
// Space Complexity: O(H) where H is the height of the binary tree.
// The space complexity is determined by the maximum height of the recursion stack,
// which is equal to the height of the binary tree in the worst case.