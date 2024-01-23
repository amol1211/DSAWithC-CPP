//823. Binary Trees With Factors

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

// This class represents a solution for the given problem.
class Solution {
public:
    // Constant representing the modulo value for calculations.
    int MOD = 1e9+7;

    // Function to count the number of different binary trees that can be formed using elements in the input array.
    int numFactoredBinaryTrees(vector<int>& arr) {
        // Get the size of the input array.
        int n = arr.size();

        // Sort the input array in ascending order.
        sort(arr.begin(), arr.end());

        // Create a map to store the number of ways a binary tree can be formed for each element (root) in the array.
        unordered_map<int, long long> mp; // key = element i.e. root, value = no. ways binary tree can be formed

        // Iterate through each element in the array.
        for (int i = 0; i < n; i++) {
            // Current element is considered as the root of a binary tree.
            int root = arr[i];
            // Initialize the count of ways to form a binary tree with the current root.
            mp[root] = 1;

            // Iterate through the elements before the current root.
            for (int j = 0; j < i; j++) {
                // Consider the j-th element as a potential left child of the current root.
                int leftChild = arr[j];

                // Check if the current root is divisible by the left child and if the complement (right child) is already in the map.
                if (root % leftChild == 0 && mp.find(root / leftChild) != mp.end()) {
                    // Update the count of ways to form a binary tree with the current root.
                    mp[root] += ( mp[leftChild] * mp[root / leftChild] );
                }
            }
        }

        // Initialize the result to 0.
        long result = 0;

        // Sum up the counts of ways to form binary trees for each element in the map.
        for (auto &it : mp) {
            result  = (result + it.second) % MOD;
        }

        // Return the final result.
        return result;
    }
};

/*Time Complexity: O(n^2) - Two nested loops iterating through the array.
Space Complexity: O(n) - Additional space is used to store counts for each element in the map.*/