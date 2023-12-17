//958. Check Completeness of a Binary Tree

#include <iostream>
#include <queue>
using namespace std;

//Approach 1 : BFS

class Solution {
public:
    // Function to check if a binary tree is complete using BFS
    bool isCompleteTree(TreeNode* root) {
        // Breadth-First Search
        queue<TreeNode*> q;
        q.push(root); // Start with the root

        bool past = false; // Have you encountered nullptr in the past

        // Iterate through the tree nodes using BFS
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();

            if (temp == nullptr) {
                past = true; // Mark that nullptr has been encountered
            } else {
                if (past == true) {
                    return false; // If nullptr encountered earlier, any non-nullptr node indicates incompleteness
                }
                q.push(temp->left); // Enqueue left child
                q.push(temp->right); // Enqueue right child
            }
        }

        return true; // If the loop completes, the tree is complete
    }
};

//Time Complexity: O(n) - where n is the number of nodes in the tree
//Space Complexity: O(m) - where m is the maximum number of nodes at any 
//level in the tree (worst-case scenario)

/*-----------------------------------------------------------------------------------------------------------------------*/

// Approach 2: DFS

class Solution {
private:
    // Function to count the total number of nodes in the tree
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    // Function to perform DFS and check if the tree is complete
    bool dfs(TreeNode* root, int index, int totalNodes) {
        if (root == nullptr) return true;

        if (index > totalNodes) return false;

        // Recursive DFS on left and right children
        return dfs(root->left, 2 * index, totalNodes) && 
               dfs(root->right, 2 * index + 1, totalNodes);
    }

public:
    // Function to check if a binary tree is complete using DFS
    bool isCompleteTree(TreeNode* root) {
        // Count total nodes in the tree
        int totalNodes = countNodes(root);

        int index = 1; // Starting index for the root
        // Check completeness using DFS
        return dfs(root, 1, totalNodes);
    }
};

//Time Complexity: O(n) - where n is the number of nodes in the tree
//Space Complexity: O(h) - where h is the height of the tree (recursive call stack depth)