//31. Next Permutation

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {  // begin class and function definition
        int n = nums.size(), k, l;  // declare variables n, k, and l
        for (k = n - 2; k >= 0; k--) {  // find the first decreasing element from right to left
            if (nums[k] < nums[k + 1]) {  // if such an element is found
                break;  // exit loop
            }
        }
        if (k < 0) {  // if no such element is found, the array is already in its last permutation
            reverse(nums.begin(), nums.end());  // reverse the entire array to get the first permutation
        } else {  // otherwise, swap nums[k] with the next larger element in the suffix
            for (l = n - 1; l > k; l--) {  // find the next larger element in the suffix
                if (nums[l] > nums[k]) {
                    break;
                }
            }
            swap(nums[k], nums[l]);  // swap nums[k] and nums[l]
            reverse(nums.begin() + k + 1, nums.end());  // reverse the suffix to get the next permutation
        }
    }  // end function definition
};
