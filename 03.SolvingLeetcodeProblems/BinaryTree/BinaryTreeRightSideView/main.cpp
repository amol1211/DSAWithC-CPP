//199. Binary Tree Right Side View

#include <iostream>
#include <vector>
using namespace std;

//1. Preorder traversal approach (DFS)
class Solution {
private:
    void preOrder(TreeNode* root, int level, vector<int>& result) {
        if (root == nullptr)
            return;

        if (result.size() < level) {
            result.push_back(root->val);
        }

        preOrder(root->right, level + 1, result);  // Traverse right subtree
        preOrder(root->left, level + 1, result);   // Traverse left subtree
    }

public:
    // Returns a vector representing the right side view of the binary tree
    vector<int> rightSideView(TreeNode* root) {
        // Preorder traversal approach (DFS)
        vector<int> result;
        preOrder(root, 1, result);
        return result;
    }
};

// Time Complexity: O(N), where N is the number of nodes in the tree
// Space Complexity: O(H), where H is the height of the tree (recursive stack space)

/*----------------------------------------------------------------------------------------------------*/

//2. Level order approach (BFS)

class Solution {
public:

    vector<int> rightSideView(TreeNode* root) {
        // Level order approach (BFS)
        if (root == nullptr)
            return {};

        vector<int> result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();
            TreeNode* node = nullptr;

            while (n--) {
                node = q.front();
                q.pop();

                if (node->left != nullptr) {
                    q.push(node->left);
                }

                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            result.push_back(node->val);  // Add the last node value from the level (rightmost) to the result
        }

        return result;
    }
};

// Time Complexity: O(N), where N is the number of nodes in the tree
// Space Complexity: O(W), where W is the maximum width of the tree (maximum number of nodes at any level)