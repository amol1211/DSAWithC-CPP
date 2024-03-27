//713. Subarray Product Less Than K

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to count the number of subarrays whose product is less than k
    // Time Complexity: O(n), where n is the size of the input array nums.
    // Space Complexity: O(1)
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // Get the size of the input array
        int n = nums.size();

        // If k is less than or equal to 1, there can be no subarrays whose product is less than k
        if (k <= 1) return 0;

        // Initialize two pointers i and j to traverse the array
        int i = 0, j = 0;

        // Initialize a variable to store the count of valid subarrays
        int count = 0;

        // Initialize a variable to keep track of the product of elements in the current subarray
        int product = 1;

        // Iterate through the array using the j pointer
        while (j < n) {
            // Update the product by multiplying it with the current element
            product *= nums[j];

            // If the product is greater than or equal to k,
            // move the i pointer forward and divide the product by nums[i]
            while (product >= k) {
                product /= nums[i];
                i++;
            }

            // Count the number of valid subarrays ending at index j and add it to the total count
            // The number of valid subarrays ending at index j is (j - i + 1)
            count += (j - i + 1);

            // Move the j pointer forward
            j++;
        }

        // Return the total count of valid subarrays
        return count;
    }
};

/*Time Complexity:

The time complexity of the algorithm is O(n), where n is the size of the input array nums. This is because we iterate through the array once using two pointers i and j.
Space Complexity:

The space complexity is O(1) because we only use a constant amount of extra space for variables n, count, product, i, and j, regardless of the size of the input array.*/