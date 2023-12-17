// 1110. Delete Nodes And Return Forest

#include <iostream>
#include <unordered_set>
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
    // Helper function for deleting nodes and collecting disconnected subtrees
    TreeNode* deleteHelper(TreeNode* root, unordered_set<int> &st, vector<TreeNode*> &result) {
        // Base case: If the current node is null, return null
        if (root == nullptr) return nullptr;

        // Recursively traverse the left and right subtrees
        root->left = deleteHelper(root->left, st, result);
        root->right = deleteHelper(root->right, st, result);

        // Check if the current node's value is in the set of values to be deleted
        if (st.find(root->val) != st.end()) {
            // If the value is to be deleted, add the left and right subtrees to the result vector
            if (root->left != nullptr)
                 result.push_back(root->left);

            if (root->right != nullptr)
                 result.push_back(root->right); 

            // Return null to effectively remove the current node from the tree
            return nullptr;         
        } else {
            // If the value is not to be deleted, return the current node
            return root;
        }
    }

public:
    // Main function to delete nodes with specified values and return disconnected subtrees
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        // Result vector to store disconnected subtrees
        vector<TreeNode*> result;
        
        // Set to store values to be deleted for efficient lookup
        unordered_set<int> st;

        // Populate the set with values to be deleted
        for (int &num : to_delete) {
            st.insert(num);
        }

        // Call the deleteHelper function to perform the deletion and collect result
        deleteHelper(root, st, result);

        // Check if the root itself should be included in the result
        if(st.find(root->val) == st.end()) {
            result.push_back(root);
        }

        // Return the final result vector
        return result;
    }
};

//Time Complexity: O(N), where N is the number of nodes in the binary tree. This is 
//because each node is visited once in the post-order traversal.

//Space Complexity: O(H), where H is the height of the binary tree. This is due to the 
//recursive call stack during the post-order traversal. In the worst case, the height 
//of the call stack is equal to the height of the tree.




