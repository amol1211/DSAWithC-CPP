#include <iostream>
using namespace std;

class Solution {
    public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int majority = nums[0];

        for (int i = 0; i < n; i++) {
            if (count == 0) {
                majority = nums[i];
            }

            if (nums[i] == majority) {
                count++;
            } else {
                count--;
            }
        }

        return majority;
    }
};

/*-------------------------------------------------------------*/

class Solution {
    public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};

/*-------------------------------------------------------------*/