//1st approach: By iterating over nums array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        int start = -1;
        int end = -1;

        if (nums.empty())
            return {-1, -1};

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                if (start == -1)
                    start = i;
                end = i;
            }
        }

        result.push_back(start);
        result.push_back(end);
        return result;
    }
};

/*--------------------------------------------------------------*/
//Using Binary Search

class Solution {
    public:
       vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int start = -1, end = -1;
        while (i <= j) {
            int mid = (i + j) / 2;
            if (nums[mid] == target) {
                int temp = mid;
                while (mid > 0 && nums[mid - 1] == target) 
                mid--;
                start = mid;
                while(temp < nums.size() - 1 && nums[temp + 1] == target)
                temp++;
                end = temp;

                ans.push_back(start);
                ans.push_back(end);
                return ans;
            }
            else if(nums[mid] > target)
                j = mid - 1;
            else 
                i = mid + 1;
        }

            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
    }
};

/*----------------------------------------------------------------------------------------------------*/

//Using Unordered map

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans(2, -1);
        unordered_map<int,int>mp;
        for(int i = 0; i < nums.size(); i++)
            mp[nums[i]]++;
        
        int index = -1;
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] == target){
                index = i;
                break;
            }
        if(index != -1){
            ans[0] = index;
            ans[1] = index + mp[target] - 1;
        }
        return ans;
    }
};
