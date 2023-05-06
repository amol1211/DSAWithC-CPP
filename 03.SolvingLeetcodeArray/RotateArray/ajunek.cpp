#include <iostream>
using namespace std;

class Solution {
    public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        while (k-- > 0) {
            int temp = nums[n -1];
            for (int i = n - 1; i > 0; i--) {
                nums[i] = nums[i - 1];
            }
            nums[0] = temp;
        }
    }
};

/*------------------------------------------------------*/

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
