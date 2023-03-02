/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.*/
//1.Brute force approach
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        
        return {};
    }
};
/*--------------------------------------------------------------------------------------------------------------*/
//2. Using Hashmap
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Create a hashmap to store the element-value pairs
        unordered_map<int, int> hashmap;
        
        // Iterate through the input array
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int complement = target - num;
            
            // Check if the complement exists in the hashmap
            if (hashmap.count(complement)) {
                // If it does, then return the current index and the complement's index
                return {hashmap[complement], i};
            }
            
            // Otherwise, add the current element and its index to the hashmap
            hashmap[num] = i;
        }
        
        // If no two elements add up to the target, then return an empty vector
        return {};
    }
};
