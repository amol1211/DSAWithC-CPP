//2963. Count the Number of Good Partitions

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Define a class named Solution
class Solution {
public:
    // Define a constant MOD with a value of 10^9 + 7
    int MOD = 1e9 + 7;

    // Function to calculate the number of good partitions in an array
    int numberOfGoodPartitions(vector<int>& nums) {
        // Get the size of the input array
        int n = nums.size();

        // Create an unordered_map to store the last index of each number
        unordered_map<int, int> lastIndex; // number -> last index;

        // Populate the map with the last index of each number in the array
        for (int i = 0; i < n; i++) {
            lastIndex[nums[i]] = i;
        }

        // Initialize variables i and j to 0, representing the current and last indices
        int i = 0;
        int j = 0;

        // Update j to be the maximum of its current value and the last index of the first element
        j = max(j, lastIndex[nums[0]]);

        // Initialize the result variable to 1, representing the number of good partitions
        int result = 1;

        // Iterate through the array
        while (i < n) {
            // Check if i is greater than j, indicating a new partition
            if (i > j) {
                // Update the result by multiplying it by 2 and taking the modulo of MOD
                result = (result * 2) % MOD;
            }

            // Update j to be the maximum of its current value and the last index of the current element
            j = max(j, lastIndex[nums[i]]);
            
            // Move to the next element in the array
            i++;
        }

        // Return the final result, representing the number of good partitions
        return result;       
    }
};


/*Time Complexity: O(n)
Space Complexity: O(n)*/