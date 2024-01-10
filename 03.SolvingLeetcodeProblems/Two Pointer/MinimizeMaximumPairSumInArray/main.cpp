//1877. Minimize Maximum Pair Sum in Array

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Approach : Two pointer

class Solution {
public:
    // Function to find the minimum pair sum in a given vector of integers
    int minPairSum(vector<int>& nums) {
        // Get the size of the vector
        int n = nums.size();

        // Sort the vector in ascending order
        sort(begin(nums), end(nums));

        // Initialize two pointers, i at the beginning and j at the end of the sorted vector
        int i = 0;
        int j = n - 1;

        // Initialize the result to store the maximum sum of pairs
        int result = 0;

        // Iterate through the vector until the two pointers meet
        while (i < j) {
            // Calculate the sum of the current pair
            int sum = nums[i] + nums[j];

            // Update the result with the maximum of the current sum and the existing result
            result = max(result, sum);

            // Move the pointers towards each other
            i++;
            j--;
        }

        // Return the maximum pair sum
        return result;
    }
};

/*Time Complexity: The time complexity is dominated by the sorting operation, which is O(n log n), 
where n is the size of the vector.

Space Complexity: The space complexity is O(1) as the algorithm uses a constant amount of extra space 
regardless of the input size. The sorting is typically done in-place, 
and other variables consume constant space.*/
