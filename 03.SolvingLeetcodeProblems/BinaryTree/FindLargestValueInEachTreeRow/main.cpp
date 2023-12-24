//515. Find Largest Value in Each Tree Row

#include <iostream>
#include <queue>
using namespace std;

// Approach 1: Using Breadth-First Search (BFS) with Queue


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
    // Function to find the largest values in each level of a binary tree
    vector<int> largestValues(TreeNode* root) {
        // Check if the tree is empty
        if (root == nullptr) return {};

        // Result vector to store the largest values
        vector<int> result;

        // Queue for BFS traversal
        queue<TreeNode*> q;
        q.push(root);

        // Perform BFS
        while (!q.empty()) {
            // Number of nodes at the current level
            int n = q.size();
            // Initialize maxElement to the smallest possible integer
            int maxElement = INT_MIN;

            // Iterate through nodes at the current level
            while (n--) {
                // Get the front node
                TreeNode* node = q.front();
                q.pop();

                // Update maxElement with the maximum value at the current level
                maxElement = max(maxElement, node->val);

                // Enqueue left and right children if they exist
                if (node->left) 
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            // Add the maximum value of the current level to the result vector
            result.push_back(maxElement);
        }

        // Return the result vector containing the largest values at each level
        return result;
    }
};

//Time Complexity: O(N) where N is the number of nodes in the tree.
//Space Complexity: O(M) where M is the maximum number of nodes at 
//any level in the tree (the maximum width of the tree).

/*-----------------------------------------------------------------------------------------*/

//Approach 2: Using Depth-First Search (DFS) with Recursion

class Solution {
private:
    // Recursive function to perform DFS and update result vector
    void DFS(TreeNode* root, int depth) {
        // Base case: if the node is null, return
        if (root == nullptr) return;

        // If the current depth is equal to the size of the result vector,
        // add a new element to the result vector with the value of the current node.
        // Otherwise, update the element at the current depth with the maximum of
        // its current value and the value of the current node.
        if (depth == result.size()) {
            result.push_back(root->val);
        } else {
            result[depth] = max(result[depth], root->val);
        }

        // Recursively call DFS on the left and right children with an increased depth.
        DFS(root->left, depth + 1);
        DFS(root->right, depth + 1);
    }

public:
    // Result vector to store the largest values
    vector<int> result;

    // Function to find the largest values in each level of a binary tree
    vector<int> largestValues(TreeNode* root) {
        // Call the DFS function starting from the root with depth 0
        DFS(root, 0);

        // Return the result vector containing the largest values at each level
        return result;
    }
};

//Time Complexity: O(N) where N is the number of nodes in the tree.
//Space Complexity: O(H) where H is the height of the tree (the maximum depth of the recursion stack).