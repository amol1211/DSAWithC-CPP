//26. Remove Duplicates from Sorted Array
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to remove duplicates from a sorted array in-place
    int removeDuplicates(vector<int>& nums) {
        // Get the size of the input vector
        int n = nums.size();

        // If the vector is empty, no duplicates to remove
        if (n == 0) {
            return 0;
        }

        // Initialize a pointer i to track the position of non-duplicate elements
        int i = 0;

        // Iterate through the array starting from the second element (j = 1)
        for (int j = 1; j < n; j++) {
            // If the current element is different from the previous non-duplicate element
            if (nums[j] != nums[i]) {
                // Move the pointer i to the next position
                i++;

                // Update nums[i] with the value of the current non-duplicate element
                nums[i] = nums[j];
            }
        }

        // Return the length of the array containing unique elements (non-duplicates)
        return i + 1;
    }
};

/*
Time Complexity:

The time complexity of this algorithm is O(n), where n is the length of the input vector nums. 
The algorithm iterates through the array once.

Space Complexity:

The space complexity is O(1) because the algorithm modifies the input vector in-place and uses a 
constant amount of extra space regardless of the input size.
*/

/*------------------------------------------------------------------------------*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        int i = 0, j = 1;

        while ( j < n) {
            if (nums[i] != nums[j]) {
                //We encountered the unique element
                i++;
                nums[i] = nums[j];
            }
            j++; // To find the unique element
        }

        return i + 1;
    }
};