//623. Add One Row to Tree

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//Approach 1 : DFS

class Solution {
private:
    // Helper function for DFS
    TreeNode* add(TreeNode* root, int val, int depth, int curr) {
        // If the current node is null, return null
        if (root == nullptr) return nullptr;

        // If we reached the target depth - 1
        if (curr == depth - 1) {
            // Save the original left and right children
            TreeNode* leftTemp = root->left;
            TreeNode* rightTemp = root->right;

            // Add new nodes with the given value at the target depth
            root->left = new TreeNode(val);
            root->right = new TreeNode(val);

            // Connect the new nodes to the saved children
            root->left->left = leftTemp;
            root->right->right = rightTemp;

            // Return the modified root
            return root;
        }

        // Recursively traverse the left and right subtrees
        root->left = add(root->left, val, depth, curr + 1);
        root->right = add(root->right, val, depth, curr + 1);

        // Return the modified root
        return root;
    }

public:
    // Main function using DFS
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        // If depth is 1, create a new root with the given value
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;

            // Return the new root
            return newRoot;
        }

        // Initialize the current depth to 1 and call the helper function
        int curr = 1;
        return add(root, val, depth, curr);
    }
};

//Time Complexity:O(n), where n is the number of nodes in the tree. 
//Space Complexity:O(h), where h is the height of the tree. 
//In the worst case (skewed tree), it would be O(n), 
//and in the best case (balanced tree), it would be O(log n).

/*-----------------------------------------------------------------------------*/

//Approach 2 : BFS

class Solution {
public:
    // Main function using BFS
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        // If depth is 1, create a new root with the given value
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;

            // Return the new root
            return newRoot;
        }

        // Initialize a queue for BFS and push the root
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        bool rowAdded = false;

        // Perform BFS
        while (!q.empty()) {
            int n = q.size();
            level++;

            while (n--) {
                // Process each node in the current level
                TreeNode* curr = q.front();
                q.pop();
                TreeNode* leftTemp = curr->left;
                TreeNode* rightTemp = curr->right;

                // If the current level is the target depth - 1
                if (level == depth - 1) {
                    // Add new nodes with the given value
                    curr->left = new TreeNode(val);
                    curr->right = new TreeNode(val);

                    // Connect the new nodes to the saved children
                    curr->left->left = leftTemp;
                    curr->right->right = rightTemp;
                    rowAdded = true;
                }

                // Enqueue the left and right children for the next level
                if (leftTemp) q.push(leftTemp);
                if (rightTemp) q.push(rightTemp);
            }

            // If the new row is added, exit the loop
            if (rowAdded) break;
        }

        // Return the modified root
        return root;
    }
};

//Time Complexity:O(n), where n is the number of nodes in the tree. 
//Space Complexity:O(w), where w is the maximum width of the tree (number of nodes at the maximum level). In the worst case, it would be O(n), and in the best case (complete binary tree), it would be O(2^(h-1)).

