#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

//Approach 1  (Traversing Paths)

class Solution {
private:
    // Recursive function to traverse the binary tree and find paths with a given sum.
    void solve(Node* root, int k, long &count, vector<int> &path) {
        // Base case: if the current node is nullptr, return.
        if (root == nullptr) return;

        // Add the current node's value to the path.
        path.push_back(root->data);

        // Recur for the left subtree.
        solve(root->left, k, count, path);

        // Recur for the right subtree.
        solve(root->right, k, count, path);

        // Calculate the sum of subarrays ending at the current node.
        int size = path.size();
        long sum = 0;

        // Traverse the path in reverse order and check for the given sum.
        for (int i = size - 1; i >= 0; i--) {
            sum += path[i];
            if (sum == k) 
                count++;
        }

        // Backtrack: remove the last element from the path.
        path.pop_back();
    }

public:
    // Function to find the number of paths with a given sum in a binary tree.
    int sumK(Node *root, int k) {
        // Vector to store the current path during traversal.
        vector<int> path;

        // Variable to store the final count of paths with the given sum.
        long count = 0;

        // Start the recursion with the root node.
        solve(root, k, count, path);

        // Return the final count.
        return count;
    }
};

//Time complexity: O(N^2) time
//Space complexity:  O(N) space.

/*-----------------------------------------------------------------------*/

//Approach 2 Optimized Prefix Sum Approach

class Solution {
private:
    void solve(Node* root, int k, long &count, unordered_map<long, int> &prefixSums, long currentSum) {
        if (root == nullptr) return;

        // Update the current prefix sum.
        currentSum += root->data;

        // Check if the current prefix sum is equal to the target sum.
        count += (currentSum == k);

        // Check if there is a prefix sum equal to (currentSum - targetSum) in the hash map.
        count += prefixSums[currentSum - k];

        // Increment the count for the current prefix sum in the hash map.
        prefixSums[currentSum]++;

        // Recur for the left and right subtrees.
        solve(root->left, k, count, prefixSums, currentSum);
        solve(root->right, k, count, prefixSums, currentSum);

        // Backtrack: decrement the count for the current prefix sum in the hash map.
        prefixSums[currentSum]--;
    }

public:
    int sumK(Node *root, int k) {
        unordered_map<long, int> prefixSums;

        // Variable to store the final count.
        long count = 0;

        // Start the recursion with the root node.
        solve(root, k, count, prefixSums, 0);

        // Return the final count.
        return count;
    }
};


////Time complexity: O(N) time
//Space complexity:  O(N) space.
