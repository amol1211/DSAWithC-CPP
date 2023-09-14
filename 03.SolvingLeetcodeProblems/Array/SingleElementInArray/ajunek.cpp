class Solution {
    public: 
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];

        for(int i = 1; i < n; i++) {
            ans ^= nums[i];
        }
        return ans;
    }
};

/*------------------------------------------------------------------------*/
class Solution {
    public:
    int singleNonDuplicate(vector<int>& nums) {
        int result = 0;
        for(int num: nums) {
            result ^= num;
        }
        return result;
        
    }
};

/*----------------------------------------------*/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        // Binary search loop
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            // If mid is even and its next element is the same, then the single element is to the right of mid
            if (mid % 2 == 0 && nums[mid] == nums[mid+1]) {
                left = mid + 1;
            }
            // If mid is odd and its previous element is the same, then the single element is to the right of mid
            else if (mid % 2 == 1 && nums[mid] == nums[mid-1]) {
                left = mid + 1;
            }
            // Otherwise, the single element is to the left of mid
            else {
                right = mid;
            }
        }
        
        // Return the single element
        return nums[left];
    }
};
