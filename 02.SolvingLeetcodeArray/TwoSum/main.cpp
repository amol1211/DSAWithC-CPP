/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.*/
//1.Brute force approach
#include <bits/stdc++.h>
using namespace std;
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
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> indices(n);
        for(int i = 0; i < n; i++) {
            indices[i] = i; // storing indices of all elements
        }
        sort(indices.begin(), indices.end(), [&](int i, int j) {
            return nums[i] < nums[j]; // sort indices based on element values
        });
        int left = 0, right = n - 1;
        while(left < right) {
            int sum = nums[indices[left]] + nums[indices[right]];
            if(sum == target) {
                return {indices[left], indices[right]}; // found the pair
            } else if(sum < target) {
                left++; // move left pointer to increase sum
            } else {
                right--; // move right pointer to decrease sum
            }
        }
        return {}; // no pair found
    }
};
/*--------------------------------------------------------------------------------------------------------------*/
//3. Using Hashmap
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
/*---------------------------------*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int m,n;
        vector<int> v;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i;j<nums.size();j++)
            {
               
                 if(nums[i]+nums[j]==target and i!=j)
                {
                    v.push_back(i);
                    v.push_back(j);
                }
            }
        }
        return v;
        
    }
};