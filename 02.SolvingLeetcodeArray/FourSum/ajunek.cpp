#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;

        if(nums.empty())
        return ans;

        int n = nums.size();

        sort(nums.begin(), nums.end());

        for(int i= 0; i < n; i++) {
            long long int target3 = target - nums[i];

            for(int j = i + 1; j < n; j++) {
                long long int target2 = target3 - nums[j];

                int start = j + 1;
                int end = n - 1;

                while(start < end) {

                    int two_sum = nums[start] + nums[end];

                    if(two_sum < target2)
                    start++;
                    else if(two_sum > target2)
                    end--;
                    else {
                        vector<int> quad(4,0);
                        quad[0] = nums[i];
                        quad[1] = nums[j];
                        quad[2] = nums[start];
                        quad[3] = nums[end];

                        ans.push_back(quad);

                        while(start < end && nums[start] == quad[2])
                        start++;

                        while(start < end && nums[end] == quad[3])
                        end--;
                    }
                }
                while(j + 1 < n && nums[j + 1] == nums[j])
                j++;
            }
            while (i + 1 < n && nums[i + 1] == nums[i])
            i++;
        }
        return ans;
    }
};

/*--------------------------------------------------------------------------------------*/
class Solution {
    public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;

        if(nums.empty())
        return ans;

        int n = nums.size();

        sort(nums.begin(), nums.end());

        for(int i= 0; i < n; i++){
            
            long long int target3 = target - nums[i];

            for(int j = i + 1; j < n; j++) {
                long long int target2 = target3 - nums[j];
                int start = j + 1;
                int end = n - 1;

                while(start < end) {
                    
                    int two_sum = nums[start] + nums[end];

                    if(two_sum < target2)
                    start++;
                    else if(two_sum > target2)
                    end--;

                    else{
                        vector<int> quad(4,0);
                        quad[0] = nums[i];
                        quad[1] = nums[j];
                        quad[2] = nums[start];
                        quad[3] = nums[end];

                        ans.push_back(quad);

                        while(start < end && nums[start] == quad[2])
                        start++;

                        while(start < end && nums[end] == quad[3])
                        end--;
                    }
                }
                while (j + 1 < n && nums[j + 1] == nums[j])
                j++;
            }
            while(i + 1 < n && nums[i + 1] == nums[i])
            i++;
        }
        return ans;

    }
};