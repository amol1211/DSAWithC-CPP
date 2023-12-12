//105. Construct Binary Tree from Preorder and Inorder Traversal

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    // Recursive helper function to build a binary tree from preorder and inorder traversals
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int start, int end, int &index) {
        // If the start index is greater than the end index, the subtree is empty
        if (start > end) return nullptr;

        // The root value is the current element in the preorder traversal
        int rootVal = preorder[index];
        int i = start;

        // Find the index of the root value in the inorder traversal
        for (; i <= end; i++) {
            if (inorder[i] == rootVal)
                break;
        }
        index++;  // Move to the next element in the preorder traversal

        // Create the root node
        TreeNode* root = new TreeNode(rootVal);

        // Recursively build the left and right subtrees
        root->left = solve(preorder, inorder, start, i - 1, index);
        root->right = solve(preorder, inorder, i + 1, end, index);

        return root;  // Return the root of the subtree
    }

public:
    // Main function to build a binary tree from preorder and inorder traversals
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();

        int index = 0;  // Initialize index to 0 for the preorder traversal

        // Call the recursive helper function to build the tree
        return solve(preorder, inorder, 0, n - 1, index);
    }
};

//Time complexity : O(n)
//Space complexity : O(n)

