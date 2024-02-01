//501. Find Mode in Binary Search Tree

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

//Approach 1: In-order Traversal with Additional Variables
class Solution {
public:
    // Name: InOrderWithVariables
    // Description: Perform in-order traversal with additional variables to track values and counts.
    // Time Complexity: O(n) where n is the number of nodes in the tree (each node is visited once).
    // Space Complexity: O(h) where h is the height of the tree (depth of recursion stack).
    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        int currentVal = 0;
        int currentCount = 0;
        int maxCount = 0;

        // In-order traversal with additional variables
        inorder(root, result, currentVal, currentCount, maxCount);

        return result;
    }

    void inorder(TreeNode* root, vector<int>& result, int& currentVal, int& currentCount, int& maxCount) {
        if (root == nullptr) return;

        // Traverse left subtree
        inorder(root->left, result, currentVal, currentCount, maxCount);

        // Check and update counts
        if (root->val == currentVal) {
            currentCount++;
        } else {
            currentVal = root->val;
            currentCount = 1;
        }

        // Update result based on counts
        if (currentCount == maxCount) {
            result.push_back(currentVal);
        } else if (currentCount > maxCount) {
            result.clear();
            result.push_back(currentVal);
            maxCount = currentCount;
        }

        // Traverse right subtree
        inorder(root->right, result, currentVal, currentCount, maxCount);
    }
};
/*----------------------------------------------------------------------------------------*/

//Approach 2: Using Hash Map for Frequency Count

class Solution {
private:
    // Name: FrequencyHashMap
    // Description: Use a hash map to count the frequency of each value in the tree.
    // Time Complexity: O(n) where n is the number of nodes in the tree.
    // Space Complexity: O(n) for the hash map to store frequencies.
    void dfs(TreeNode* root) {
        if (!root) return;

        // Traverse left subtree
        dfs(root->left);

        // Update frequency map
        mp[root->val]++;

        // Traverse right subtree
        dfs(root->right);
    }

public:
    unordered_map<int, int> mp;
    vector<int> findMode(TreeNode* root) {
        // Populate the frequency map
        dfs(root);

        vector<int> result;
        int maxFrequency = 0;

        // Iterate through the frequency map to find modes
        for (auto &it : mp) {
            if (it.second > maxFrequency) {
                maxFrequency = it.second;
                result = {};
                result.push_back(it.first);
            } else if (it.second == maxFrequency) {
                result.push_back(it.first);
            }
        }
        return result;
    }
};

/*------------------------------------------------------------------------*/

//Approach 3: Recursive In-order Traversal with Member Variables

class Solution {
private:
    // Name: RecursiveInOrderWithMembers
    // Description: Recursive in-order traversal with member variables to track values and counts.
    // Time Complexity: O(n) where n is the number of nodes in the tree.
    // Space Complexity: O(h) where h is the height of the tree (depth of recursion stack).
    void dfs(TreeNode* root) {
        if (!root) return;

        // Traverse left subtree
        dfs(root->left);

        // Update counts and result
        if (root->val == currNum) {
            currFreq++;
        } else {
            currNum = root->val;
            currFreq = 1;
        }

        // Update result based on counts
        if (currFreq > maxFreq) {
            result = {};
            maxFreq = currFreq;
        }

        if (currFreq == maxFreq) {
            result.push_back(root->val);
        }

        // Traverse right subtree
        dfs(root->right);
    }
        
public:
    int currNum = 0;
    int currFreq = 0;
    int maxFreq = 0;
    vector<int> result;
    vector<int> findMode(TreeNode* root) {
        // Perform in-order traversal
        dfs(root);

        return result;
    }
};
