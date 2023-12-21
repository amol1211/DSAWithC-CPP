//652. Find Duplicate Subtrees

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    // Function to get a string representation of the subtree rooted at 'root'
    // and update the frequency map 'mp'. Also, find and collect duplicate subtrees in 'result'.
    string getSubTreeString(TreeNode* root, unordered_map<string, int> &mp, vector<TreeNode*> &result) {
        // If the current node is null, return a placeholder string "N".
        if (root == nullptr) return "N";

        // Create a string representation of the subtree rooted at 'root'.
        // It includes the current node's value, left subtree string, and right subtree string.
        string s = to_string(root->val) + "," + getSubTreeString(root->left, mp, result) + "," + getSubTreeString(root->right, mp, result);

        // If this string has been seen before, and it's the first duplicate,
        // add the current node to the 'result' vector.
        if (mp[s] == 1) {
            result.push_back(root);
        }

        // Increment the frequency of the current subtree string in the map.
        mp[s]++;

        // Return the current subtree string.
        return s;
    }

public:
    // Main function to find duplicate subtrees in the given binary tree 'root'.
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        // Map to store the frequency of subtree strings.
        unordered_map<string, int> mp;

        // Vector to store the resulting duplicate subtrees.
        vector<TreeNode*> result;

        // Invoke the recursive function to populate the frequency map and find duplicates.
        getSubTreeString(root, mp, result);

        // Return the vector containing duplicate subtrees.
        return result;
    }
};

//Time Complexity: O(N^2), where N is the total number of nodes in the binary tree. 
//This is because, for each node, the algorithm may construct a string of length O(N), 
//and there are potentially O(N) such strings formed across all nodes.

//Space Complexity:  O(N^2) as well. This is due to the space used by the recursion stack 
//(which can go as deep as the height of the tree) and the space required to store 
//the frequency map ('mp'), which can have O(N) distinct entries in the worst case.