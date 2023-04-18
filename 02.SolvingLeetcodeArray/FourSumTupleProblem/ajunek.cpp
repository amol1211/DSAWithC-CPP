#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        int count = 0;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int target = -nums3[i] - nums4[j];
                int left = 0, right = n - 1;

                while (left < n && right >= 0) {
                    int sum = nums1[left] + nums2[right];
                    if(sum < target) {
                        left++;
                    } else if (sum > target) {
                        right--;
                    } else {
                        int leftCount = 1, rightCount = 1;
                        while (left + 1 < n && nums1[left] == nums1[left + 1]) {
                            leftCount++;
                            left++;
                        }
                        while (right - 1 >= 0 && nums2[right] == nums2[right - 1]) {
                            rightCount++;
                            right--;
                        }
                        count += leftCount * rightCount;
                        left++;
                        right--;
                    }
                }
            }
        }
        return count;
    }
};