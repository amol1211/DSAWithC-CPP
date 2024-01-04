//226. Invert Binary Tree

#include <iostream>
#include <stack>
using namespace std;

// Approach 1: Iterative using Stack (BFS)

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
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            TreeNode* temp = st.top();
            st.pop();

            if (temp) {
                st.push(temp->left);
                st.push(temp->right);
                swap(temp->left, temp->right);
            }
        }

        return root;
    }
};

// Time Complexity: O(n) - where n is the number of nodes in the tree
// Space Complexity: O(h) - where h is the height of the tree (maximum nodes in the stack at any point)

/*----------------------------------------------------------------*/

// Approach 2: Recursive(DFS)

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;

        invertTree(root->left);
        invertTree(root->right);

        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        return root;
    }
};

// Time Complexity: O(n) - where n is the number of nodes in the tree
// Space Complexity: O(h) - where h is the height of the tree (recursion call stack)