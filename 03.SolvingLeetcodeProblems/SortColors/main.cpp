//75. Sort Colors

//1. Brute Force Approach:

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Declare variables to store counts of each color
        int n = nums.size();            // Get the size of the input array
        int count0 = 0, count1 = 0, count2 = 0; // Initialize counters for colors 0, 1, and 2
               
        // Count the occurrences of each color in the input array
        for (int num : nums) {
            if (num == 0) count0++;     // Increment count0 if color is 0
            else if (num == 1) count1++; // Increment count1 if color is 1
            else if (num == 2) count2++; // Increment count2 if color is 2
        }
              
        // Overwrite the input array with the sorted colors based on the counts
        for (int i = 0; i < n; i++) {
            if (count0 > 0) {
                nums[i] = 0;             // Fill with color 0 if count0 > 0
                count0--;                // Decrement count0
            } else if (count1 > 0) {
                nums[i] = 1;             // Fill with color 1 if count1 > 0
                count1--;                // Decrement count1
            } else if (count2 > 0) {
                nums[i] = 2;             // Fill with color 2 if count2 > 0
                count2--;                // Decrement count2
            }
        }
    }
};

/*--------------------------------------------------------------------------------*/

// 2. Brute Force Approach:

void sortColorsBruteForce(vector<int>& nums) {
    int n = nums.size();
    
    // Perform bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                // Swap elements if they are out of order
                swap(nums[j], nums[j + 1]);
            }
        }
    }
}

/*--------------------------------------------------------------------------------*/

// 3. Slightly Optimized Approach (Dutch National Flag Algorithm):

void sortColorsDutchFlag(vector<int>& nums) {
    int low = 0, high = nums.size() - 1, mid = 0;
    
    // Move elements smaller than 1 to the beginning and larger than 1 to the end
    while (mid <= high) {
        if (nums[mid] == 0) {
            // Swap current element with the element at 'low' index
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        } else if (nums[mid] == 1) {
            // Move to the next element
            mid++;
        } else {
            // Swap current element with the element at 'high' index
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

/*----------------------------------------------------------------------------*/
