class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            int n = nums.size();
            for (int i = 0; i < n; i++) {
                if (nums[i] == 0) {
                    for (int j = i+1; j < n; j++) {
                        if (nums[j] != 0) {
                            swap(nums[i], nums[j]);
                            break;
                        }
                    }
                }
            }
        }
}

/*-------------------------------------------------------*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int nextNonZero = 0; // Position to place the next non-zero element
        
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                swap(nums[nextNonZero], nums[i]);
                nextNonZero++;
            }
        }
    }
};