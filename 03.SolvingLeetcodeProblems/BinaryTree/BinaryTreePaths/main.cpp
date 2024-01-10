//257. Binary Tree Paths

#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//Approach 1 : BFS

// This class represents a solution for finding all binary tree paths using Breadth-First Search (BFS).
class Solution {
public:
    // Public function to get all binary tree paths.
    // Parameter:
    //   - root: The root of the binary tree.
    // Returns:
    //   - A vector of strings representing all paths in the binary tree.
    vector<string> binaryTreePaths(TreeNode* root) {
        // Initialize the result vector.
        vector<string> result;

        // Check if the tree is empty.
        if (!root) return result;

        // Initialize a queue for BFS, each element contains a node and its corresponding path.
        queue<pair<TreeNode*, string>> q;
        q.push({root, to_string(root->val)});

        // Perform BFS.
        while (!q.empty()) {
            auto [root, path] = q.front();
            q.pop();

            // Check if the current node is a leaf node, and if so, add its path to the result.
            if (!root->left && !root->right) {
                result.push_back(path);
            }

            // Enqueue left child if exists.
            if (root->left != nullptr) {
                q.push({root->left, path + "->" + to_string(root->left->val)});
            }

            // Enqueue right child if exists.
            if (root->right != nullptr) {
                q.push({root->right, path + "->" + to_string(root->right->val)});
            }
        }

        // Return the final result.
        return result;
    }
};

/*-----------------------------------------------------------*/
//Approach 2 : DFS

// This class represents a solution for finding all binary tree paths using Depth-First Search (DFS).
class Solution {
private: 
    // Helper function for DFS traversal.
    // Parameters:
    //   - root: The current node in the traversal.
    //   - path: The path from the root to the current node.
    //   - result: The vector to store the result paths.
    void dfs(TreeNode* root, string path, vector<string> &result) {
        // Check if the current node is a leaf node, and if so, add its path to the result.
        if (root->left == nullptr && root->right == nullptr) {
            result.push_back(path);
        }

        // Recursively call the function for the left child if it exists.
        if (root->left != nullptr) {
            dfs(root->left, path + "->" + to_string(root->left->val), result);
        }

        // Recursively call the function for the right child if it exists.
        if (root->right != nullptr) {
            dfs(root->right, path + "->" + to_string(root->right->val), result);
        }
    }    

public:
    // Public function to get all binary tree paths using DFS.
    // Parameter:
    //   - root: The root of the binary tree.
    // Returns:
    //   - A vector of strings representing all paths in the binary tree.
    vector<string> binaryTreePaths(TreeNode* root) {
        // Initialize the result vector.
        vector<string> result;

        // Check if the tree is empty.
        if (root == nullptr) return result;

        // Call the DFS function with the root and its value as the initial path.
        dfs(root, to_string(root->val), result);

        // Return the final result.
        return result;
    }
};

// Time Complexity for both solutions: O(N), where N is the number of nodes in the binary tree.
//   - In both BFS and DFS, each node is visited once.
// Space Complexity for BFS: O(W), where W is the maximum width of the tree (number of nodes in the level with the most nodes).
//   - The space complexity is dominated by the queue used in BFS.
// Space Complexity for DFS: O(H), where H is the height of the binary tree.
//   - The space complexity is dominated by the recursive call stack during DFS.
//   - In the worst case, when the tree is skewed, H is equal to N, resulting in O(N) space complexity.
