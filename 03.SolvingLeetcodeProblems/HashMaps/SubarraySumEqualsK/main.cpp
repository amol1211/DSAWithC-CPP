//560. Subarray Sum Equals K

#include <bits/stdc++.h>
using namespace std;

//Approach 1 : Brute force (TLE)

// This approach iterates over all possible subarrays and counts the ones whose sum equals k.

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Stores the sum of each subarray.
        vector<int> subarraysWhichEqualsK;

        // Iterate over all elements of the array to form subarrays.
        for (int i = 0; i < nums.size(); i++) {
            // Compute the sum of the current subarray.
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                // Store the sum of the current subarray.
                subarraysWhichEqualsK.push_back(sum);
            }
        }

        // Count the subarrays whose sum equals k.
        int count = 0;
        for (int i = 0; i < subarraysWhichEqualsK.size(); i++) {
            if (subarraysWhichEqualsK[i] == k) {
                count++;
            }
        }

        return count;
    }
};

// Time complexity: O(n^2) - The nested loops iterate over all subarrays.
// Space complexity: O(n^2) - The vector 'subarraysWhichEqualsK' can potentially store O(n^2) subarrays.

/*-----------------------------------------------------------------------------------------------------------*/

//Approach 2 :  Using Hash Map

// This approach uses a hash map to keep track of cumulative sums and their frequencies.

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Map to store cumulative sums and their frequencies.
        unordered_map<int, int> mp;

        // Stores the result.
        int result = 0;

        // Cumulative sum of elements.
        int cumulativeSum = 0;

        // Initialize the map with 0 to handle cases where the cumulative sum equals k.
        mp.insert({0, 1});

        // Iterate over the array to compute cumulative sums.
        for (int i = 0; i < nums.size(); i++) {
            cumulativeSum += nums[i];

            // If there exists a cumulative sum at (cumulativeSum - k),
            // it means a subarray summing to k is found from previous positions.
            if (mp.find(cumulativeSum - k) != mp.end()) {
                result += mp[cumulativeSum - k];
            }

            // Update the frequency of the current cumulative sum.
            mp[cumulativeSum]++;
        }

        return result;
    }
};

// Time complexity: O(n) - The loop iterates through the array once.
// Space complexity: O(n) - The unordered_map 'mp' can store at most O(n) cumulative sums.