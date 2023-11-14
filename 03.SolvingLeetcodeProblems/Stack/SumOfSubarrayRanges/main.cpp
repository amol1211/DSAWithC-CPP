//2104. Sum of Subarray Ranges

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// 1. Brute force approach

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        // Get the size of the input array
        int n = nums.size();
        // Initialize the sum variable to store the result
        long long sum = 0;

        // Outer loop to iterate over each element in the array
        for (int i = 0; i < n; i++) {
            // Initialize the minimum and maximum values for the current subarray
            int minValue = nums[i];
            int maxValue = nums[i];

            // Inner loop to iterate over all possible subarrays starting from the current element
            for (int j = i; j < n; j++) {
                // Update the minimum and maximum values for the current subarray
                minValue = min(minValue, nums[j]);
                maxValue = max(maxValue, nums[j]);

                // Update the sum by adding the range of the current subarray
                sum += (maxValue - minValue);
            }
        }

        // Return the final sum of all subarray ranges
        return sum;
    }
};
