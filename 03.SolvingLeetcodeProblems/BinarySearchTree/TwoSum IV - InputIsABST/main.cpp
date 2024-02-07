#include <iostream>
#include <vector>
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

 //Approach 1: Using Inorder Traversal and Two Pointers

  // Approach 1: Using Inorder Traversal and Two Pointers
// This approach uses inorder traversal to get the sorted array of values.
// Then, it uses two pointers to find if there exist two elements whose sum equals k.
// Time complexity: O(n) where n is the number of nodes in the tree.
// Space complexity: O(n) for the inorder traversal array.
class Solution {
private:
    // Helper function for inorder traversal
    void inOrder(TreeNode* root, vector<int> &in) {
        if (!root) return;

        inOrder(root->left, in);
        in.push_back(root->val);
        inOrder(root->right, in);
    }    

public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> inOrderVal;

        // Perform inorder traversal to populate the vector with sorted values
        inOrder(root, inOrderVal);

        int i = 0, j = inOrderVal.size() - 1;

        // Two pointers approach to find if two elements sum up to k
        while (i < j) {
            int sum = inOrderVal[i] + inOrderVal[j];

            if (sum == k) 
                return true;
            else if (sum > k)
                j--;
            else
                i++;    
        }

        return false;
    }
};

/*----------------------------------------------------------------*/

//Approach 2: Using Depth-First Search (DFS) and HashSet

// Approach 2: Using Depth-First Search (DFS) and HashSet
// This approach uses DFS to traverse the tree while maintaining a set of visited node values.
// It checks if the complement of the current node's value (k - node->val) exists in the set.
// Time complexity: O(n) where n is the number of nodes in the tree.
// Space complexity: O(n) for the hash set to store unique values.
class Solution {
private:
    // Helper function for DFS traversal
    bool dfs(TreeNode* node, int k, unordered_set<int> &nums) {
        if (!node) return false;

        // Check if the complement exists in the set
        if (nums.find(k - node->val) != nums.end()) return true;

        // Insert current node value into the set
        nums.insert(node->val);

        // Recursively traverse left and right subtrees
        return dfs(node->left, k, nums) || dfs(node->right, k, nums);
    }

public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> nums;
        return dfs(root, k, nums);
    }
};

/*------------------------------------------------------------------*/

//Approach 3: Using DFS and Recursive Search

// Approach 3: Using DFS and Recursive Search
// This approach uses DFS to traverse the tree.
// For each node, it searches for the complement of its value (k - current->val) in the tree.
// Time complexity: O(n^2) in the worst case, where n is the number of nodes in the tree.
// Space complexity: O(h) for the recursive call stack, where h is the height of the tree.
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        return dfs(root, root, k);
    }

    bool dfs(TreeNode* node, TreeNode* current, int k) {
        if (!current) return false;

        // Search for the complement of current node's value
        return search(node, current, k - current->val) || dfs(node, current->left, k) || dfs(node, current->right, k);
    }

    bool search(TreeNode* root, TreeNode* current, int target) {
        if (!root) return false;

        // Perform binary search for the target value
        return (root->val == target) && (root != current)
            || (root->val < target) && search(root->right, current, target)
            || (root->val > target) && search(root->left, current, target);
    }
};


