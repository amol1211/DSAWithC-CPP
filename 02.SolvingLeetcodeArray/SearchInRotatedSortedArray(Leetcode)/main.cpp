/* There is an integer array nums sorted in ascending order (with distinct values).
Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) 
such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 
For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].
Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, 
or -1 if it is not in nums.
You must write an algorithm with O(log n) runtime complexity.
Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Example 3:
Input: nums = [1], target = 0
Output: -1
 Constraints:
1 <= nums.length <= 5000
-104 <= nums[i] <= 104
All values of nums are unique.
nums is an ascending array that is possibly rotated.
-104 <= target <= 104  */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) {
            return -1;
        }
        if (n == 1) {
            return nums[0] == target ? 0 : -1;
        }

        // find pivot index k
        int left = 0, right = n-1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        // binary search on the appropriate subarray
        int pivot = left;
        left = 0, right = n-1;
        if (target >= nums[pivot] && target <= nums[right]) {
            left = pivot;
        } else {
            right = pivot - 1;
        }
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }
};

/*----------------------------------------------------------------------------------------*/
//bit more concise and easier to follow code.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1; // initialize left and right pointers
        while (left <= right) { // continue loop while left is less than or equal to right
            int mid = left + (right - left) / 2; // find the middle index
            if (nums[mid] == target) { // if target is found at the middle index, return it
                return mid;
            }
            if (nums[mid] >= nums[left]) { // if left subarray is sorted in ascending order
                if (target >= nums[left] && target < nums[mid]) { // if target is within the left subarray
                    right = mid - 1; // update right pointer to search in the left subarray
                } else {
                    left = mid + 1; // update left pointer to search in the right subarray
                }
            } else { // if right subarray is sorted in ascending order
                if (target <= nums[right] && target > nums[mid]) { // if target is within the right subarray
                    left = mid + 1; // update left pointer to search in the right subarray
                } else {
                    right = mid - 1; // update right pointer to search in the left subarray
                }
            }
        }
        return -1; // target not found
    }
};
