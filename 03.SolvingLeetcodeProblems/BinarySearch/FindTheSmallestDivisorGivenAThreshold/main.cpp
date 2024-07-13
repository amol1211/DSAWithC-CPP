//1283. Find the Smallest Divisor Given a Threshold

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Function to compute the sum of elements after dividing each element by the divisor and taking the ceiling of each division.
    int sumAfterDivision(vector<int>& nums, int divisor) {
        int sum = 0; // Initialize sum to 0

        // Iterate through each number in the nums vector
        for (int& x : nums) {
            // Divide each number by the divisor, take the ceiling of the result, and add it to sum
            sum += ceil((double)x / divisor);
        }

        return sum; // Return the total sum
    }

public:
    // Function to find the smallest divisor such that the sum after division is less than or equal to the threshold
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size(); // Get the number of elements in nums

        // Initialize low to 1 and high to the maximum element in nums
        int low = 1, high = *max_element(nums.begin(), nums.end());

        // Binary search loop to find the smallest divisor
        while (low < high) {
            int mid = low + (high - low) / 2; // Compute the mid point

            // If the sum after division by mid is less than or equal to the threshold
            if (sumAfterDivision(nums, mid) <= threshold) {
                high = mid; // Update high to mid, as we look for a smaller divisor
            } else {
                low = mid + 1; // Update low to mid + 1, as we look for a larger divisor
            }
        }

        return low; // Return the smallest divisor
    }
};

/*
Time Complexity:
- The binary search runs in O(log(max_element)), where max_element is the maximum 
value in the nums vector.
- The sumAfterDivision function runs in O(n), where n is the number of elements 
in the nums vector.
- Therefore, the overall time complexity is O(n * log(max_element)).

Space Complexity:
- The space complexity is O(1) because no additional space proportional to the input 
size is used, only a few extra variables.
*/
