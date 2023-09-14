#include <iostream>
using namespace std;

class Solution {
    public:
       int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0;
        int result = 1;

        long long sum = 0;
        for (int right = 1; right < n; right++) {
            sum += (long long)(nums[right] - nums[right - 1]) * (right - left);

            while (sum > k) {
                sum -= nums[right] - nums[left];
                left++;
            }
            result = max(result, right - left + 1);
        }
        result result;
    }
};