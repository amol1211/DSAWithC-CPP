//169. Majority Element

#include <iostream>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int majority = nums[0]; // Assume the first element as the majority element

        for (int i = 0; i < n; i++) {
            if (count == 0) {
                // If the count becomes zero, update the majority element
                majority = nums[i];
            }
            
            if (nums[i] == majority) {
                // If the current element is the same as the majority element, increment the count
                count++;
            } else {
                // If the current element is different from the majority element, decrement the count
                count--;
            }
        }
        
        return majority;
    }
};


//Time Complexity: O(n)
//Space Complexity:O(1)
/*----------------------------------------------------------------------------------------------------------*/
//2.Sorting

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

//Time Complexity: O(n log n) 
//Space Complexity: O(1) 

/*-----------------------------------------------------------------------------------------------------*/
//3.HashMap

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        int n = nums.size();
        
        for (int num : nums) {
            freq[num]++;
            if (freq[num] > n/2) {
                return num;
            }
        }
        
        return -1; // No majority element found
    }
};

//Time Complexity: O(n)
//Space Complexity: O(n)

/*------------------------------------------------------------------------------------------------------*/
//4.Moore's Voting Algorithm (recursive)

class Solution {
public:
    int countInRange(vector<int>& nums, int num, int left, int right) {
        int count = 0;
        for (int i = left; i <= right; i++) {
            if (nums[i] == num) {
                count++;
            }
        }
        return count;
    }
    
    int majorityElementHelper(vector<int>& nums, int left, int right) {
        // Base case: if the subarray has only one element, return it as the majority element
        if (left == right) {
            return nums[left];
        }
        
        // Recursive step
        int mid = (left + right) / 2;
        int leftMajority = majorityElementHelper(nums, left, mid);
        int rightMajority = majorityElementHelper(nums, mid + 1, right);
        
        // If the two halves have the same majority element, return it
        if (leftMajority == rightMajority) {
            return leftMajority;
        }
        
        // Count the occurrences of the majority elements in the entire range
        int leftCount = countInRange(nums, leftMajority, left, right);
        int rightCount = countInRange(nums, rightMajority, left, right);
        
        // Return the majority element with the higher count
        return (leftCount > rightCount) ? leftMajority : rightMajority;
    }
    
    int majorityElement(vector<int>& nums) {
        return majorityElementHelper(nums, 0, nums.size() - 1);
    }
};

////Time Complexity: O(n log n)
//Space Complexity: O(log n) 

