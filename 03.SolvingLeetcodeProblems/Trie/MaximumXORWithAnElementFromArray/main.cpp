//1707. Maximum XOR With an Element From Array
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

//Approach 1 : Using Trie (TLE)

class Solution {
public:
    // Function to maximize XOR for each query
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans; // Initialize the answer vector

        // Iterate through each query
        for (int i = 0; i < queries.size(); i++) {
            int maxXor = -1; // Initialize maxXor to -1
            // Iterate through each element in nums
            for (int j = 0; j < nums.size(); j++) {
                // Check if the current element in nums is less than or equal to the limit in the query
                if (nums[j] <= queries[i][1]) {
                    // Update maxXor by taking the bitwise XOR of the current query value and the element in nums
                    maxXor = max(maxXor, queries[i][0] ^ nums[j]);
                }
            }
            // Push the final maxXor value for the current query into the answer vector
            ans.push_back(maxXor);
        }
        // Return the answer vector
        return ans;
    }
};

/*Time Complexity: O(N * M), where N is the number of elements in nums and M is the number of queries. 
In the worst case, for each query, we iterate through all elements in nums.

Space Complexity: O(M), where M is the number of queries. The space complexity is influenced by the 
size of the answer vector.*/

/*----------------------------------------------------------------------------------------------------------------*/

//Approach 2 : Using Trie

// Definition of TrieNode with left and right pointers
class TrieNode {
public:
    TrieNode* left;  // 0
    TrieNode* right; // 1
};

// Comparator function for sorting queries based on the second element
bool comp(vector<int> &a, vector<int> &b) {
    return a[1] < b[1];
}

class Solution {
public:
    // Function to insert a number into the trie
    void insert(int num, TrieNode* root) {
        for (int i = 31; i >= 0; i--) {
            int ith_bit = (num >> i) & 1;

            // If the current bit is 0 and left pointer is null, create a new TrieNode
            if (ith_bit == 0) {
                if (root->left == nullptr) {
                    root->left = new TrieNode();
                }
                root = root->left;
            } else { // If the current bit is 1 and right pointer is null, create a new TrieNode
                if (root->right == nullptr) {
                    root->right = new TrieNode();
                }
                root = root->right;
            }
        }
    }

    // Function to find the maximum XOR value for a given number in the trie
    int query(int num, TrieNode* root) {
        TrieNode* crawl = root;
        int maxXor = 0;

        for (int i = 31; i >= 0; i--) {
            int ith_bit = (num >> i) & 1;

            // If the current bit is 1 and left pointer is not null, update maxXor and move left
            if (ith_bit == 1) {
                if (crawl->left != nullptr) {
                    maxXor += pow(2, i); // Calculating XOR value on the fly
                    crawl = crawl->left;
                } else {
                    crawl = crawl->right;
                }
            } else { // If the current bit is 0 and right pointer is not null, update maxXor and move right
                if (crawl->right != nullptr) {
                    maxXor += pow(2, i); // Calculating XOR value on the fly
                    crawl = crawl->right;
                } else {
                    crawl = crawl->left;
                }
            }
        }

        return maxXor;
    }

    // Function to maximize XOR for each query
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();

        vector<int> ans(m, -1); // Initialize the answer vector with -1
        for (int i = 0; i < m; i++) {
            queries[i].push_back(i); // Append the index to each query for later sorting
        }

        sort(nums.begin(), nums.end()); // Sort the nums array in ascending order
        sort(queries.begin(), queries.end(), comp); // Sort the queries based on the second element

        TrieNode* root = new TrieNode(); // Create the root of the trie
        int i = 0;

        for (int k = 0; k < m; k++) {
            // Insert numbers into the trie while they are less than or equal to the current query limit
            while (i < n && nums[i] <= queries[k][1]) {
                insert(nums[i], root);
                i++;
            }

            if (i != 0) {
                // If there are numbers less than or equal to the query limit, update the answer using the trie
                ans[queries[k][2]] = query(queries[k][0], root);
            }
        }

        return ans;
    }
};

// Time Complexity: O((N + M) * log(MAX)), where N is the number of elements in nums, M is the number of 
//queries, and MAX is the maximum value of nums.
// Space Complexity: O(N * log(MAX)), where N is the number of elements in nums and MAX is the maximum 
//value of nums.
