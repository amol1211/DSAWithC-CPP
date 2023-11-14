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

//Time complexity : O(n^2)
//Space complexity : O(1)

/*---------------------------------------------------------------------------------*/

class Solution {
public:
    // Function to calculate the sum of products of subarray ranges based on the input vector 'nums'.
    long subArrayRanges(vector<int>& nums) {
        // Variable to store the final result.
        long result = 0;
        
        // Stack to track increasing elements' indices.
        stack<int> inc;
        
        // Stack to track decreasing elements' indices.
        stack<int> dec;

        // Iterate through the vector 'nums' and one additional iteration for handling the remaining elements.
        for (int i = 0; i <= nums.size(); ++i) {
            // Process increasing elements.
            while (!inc.empty() && (i == nums.size() || nums[inc.top()] < nums[i])) {
                int currIndex = inc.top();
                inc.pop();
                int leftBound = inc.empty() ? -1 : inc.top();
                int rightBound = i;
                
                // Update the result by adding the product of the current subarray range.
                result += (currIndex - leftBound) * (rightBound - currIndex) * static_cast<long>(nums[currIndex]);
            }
            
            // Process decreasing elements.
            while (!dec.empty() && (i == nums.size() || nums[dec.top()] > nums[i])) {
                int currIndex = dec.top();
                dec.pop();
                int leftBound = dec.empty() ? -1 : dec.top();
                int rightBound = i;
                
                // Update the result by subtracting the product of the current subarray range.
                result -= (currIndex - leftBound) * (rightBound - currIndex) * static_cast<long>(nums[currIndex]);
            }
            
            // Push the current index onto both increasing and decreasing stacks.
            inc.push(i);
            dec.push(i);
        }

        // Return the final result.
        return result;
    }
};

//Time complexity : O(n)
//Space complexity : O(n)
