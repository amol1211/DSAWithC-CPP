// 189. Rotate Array

// Approach 1: Brute Force

#include <iostream>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // calculate the actual number of rotations needed
        while (k-- > 0) { // rotate the array k times
            int temp = nums[n - 1]; // store the last element in a temporary variable
            for (int i = n - 1; i > 0; i--) { // shift all elements to the right by one position
                nums[i] = nums[i - 1];
            }
            nums[0] = temp; // place the temporary variable at the beginning of the array
        }
    }
};

/*----------------------------------------------------------------------------------------------------*/

// Approach 2: Using Extra Array

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // calculate the actual number of rotations needed
        vector<int> temp(k); // create an extra array to store the rotated elements
        for (int i = n - k; i < n; i++) { // copy the last k elements to the beginning of the extra array
            temp[i - (n - k)] = nums[i];
        }
        for (int i = n - k - 1; i >= 0; i--) { // shift the remaining elements to the right
            nums[i + k] = nums[i];
        }
        for (int i = 0; i < k; i++) { // copy the rotated elements from the extra array to the beginning of the original array
            nums[i] = temp[i];
        }
    }
};

/*-----------------------------------------------------------------------------------------------------------------------------*/

// Approach 3: Reversing the Array

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n; // calculate the actual number of rotations needed
        reverse(nums.begin(), nums.end()); // reverse the entire array
        reverse(nums.begin(), nums.begin() + k); // reverse the first k elements separately
        reverse(nums.begin() + k, nums.end()); // reverse the remaining elements separately
    }
};
