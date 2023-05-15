class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) { // if the vector is empty, return 0
            return 0;
        }
        int i = 0; // use a pointer i to keep track of the unique elements in nums
        for (int j = 1; j < nums.size(); j++) { // use a pointer j to iterate through nums
            if (nums[j] != nums[i]) { // if nums[j] is not a duplicate of nums[i], increment i and update nums[i]
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1; // return the length of the new array
    }
};
