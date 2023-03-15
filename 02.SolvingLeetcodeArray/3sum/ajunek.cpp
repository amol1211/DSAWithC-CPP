#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public: 
    vector<vector<int>> threeSum(vector<int> &nums) {

        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++) {

            int target = -nums[i];

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {

                int sum = nums[left] + nums[right];

                if (sum < target)
                left++;

                else if (sum > target)
                right--;

                else {
                    vector<int> triplet = {nums[i], nums[left], nums[right]};
                    ans.push_back(triplet);

                    while (left < right && nums[right] == triplet[2])
                    right--;

                    while (left < right && nums[left] == triplet[1])
                    left++;
                }
            }

            while (i+1 < nums.size() && nums[i + 1] == nums[i])
            i++;
        }

        return ans;
    }
};
/*-----------------------------------------------------------------------------------*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:

    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            int target = -nums[i];
            int left = i + 1;
            int right = nums.size() - 1;

            while(left < right) {

                int sum = nums[left] + nums[right];

                if (sum < target)
                left++;

                else if (sum > target)
                right--;

                else {
                    vector<int> triplet = {nums[i], nums[left], nums[right]};
                    ans.push_back(triplet);

                    while (left < right && nums[right] == triplet[2])
                    right--;

                    while (left < right && nums[left] == triplet[1])
                    left++;
                }
            }

            while (i+1 < nums.size() && nums[i + 1] == nums[i])
            i++;
        }
        return ans;
    }

};

/*----------------------------------------------------------------------------------*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            int target = -nums[i];

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[left] + nums[right];

                if (sum < target)
                left++;

                else if (sum > target)
                right--;

                else {
                    vector<int> triplet = {nums[i], nums[left], nums[right]};
                    ans.push_back(triplet);

                    while (left < right && nums[right] == triplet[2])
                    right--;

                    while (left < right && nums[left] == triplet[1])
                    left++;
                }
            }
            while (i+1 < nums.size() && nums[i + 1] == nums[i])
            i++;
        }
        return ans;
    }
};
/*-------------------------------------------------------------------------*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public: 

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {

        int target = -nums[i];
        int left = i + 1;
        int right = nums.size() - 1;

        if (target < 0) {
            break;
        }

        while (left < right) {
            int sum = nums[left] + nums[right];

            if (sum < target) 
            left++;

            else if (sum > target)
            right--;

            else {
                vector<int> triplet(3, 0);
                triplet[0] = nums[i];
                triplet[1] = nums[left];
                triplet[2] = nums[right];
                ans.push_back(triplet);

                while (left < right && nums[left] == triplet[1])
                left++;

                while (left < right && nums[right] == triplet[2])
                right--;
            }
        }
        while (i + 1 < nums.size() && nums[i + 1] == nums[i])
        i++;
    }
    return ans;
}
};

/*----------------------------------------------------------------------------*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public: 
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        sort(nums.begin(), nums.begin());

        for (int i = 0; i < nums.size(); i++) {
            int target = -nums[i];
            int left = i + 1;
            int right = nums.size() - 1;

            if (target < 0) {
                break;
            }

            while (left < right) {
                int sum = nums[left] + nums[right];

                if (sum < target)
                left++;

                else if (sum > target)
                right--;

                else {
                    vector<int> triplet(3, 0);
                    triplet[0] = nums[i];
                    triplet[1] = nums[left];
                    triplet[2] = nums[right];
                    ans.push_back(triplet);

                    while (left < right && nums[left] == triplet[1]) left++;
                    while (left < left && nums[right] == triplet[2]) right--;

                }
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i])
            i++;
        }
        return ans;
    }
};
