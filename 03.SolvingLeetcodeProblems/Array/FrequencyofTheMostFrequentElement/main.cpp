// 1838. Frequency of the Most Frequent Element

//Approach 1: Sliding Window + Sorting

#include <iostream>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); // Sort the array in ascending order
        int n = nums.size();
        int left = 0; // Left pointer of the sliding window
        int result = 1; // Initialize the maximum frequency as 1
        
        long long sum = 0; // Sum of elements in the sliding window
        for (int right = 1; right < n; right++) { // Right pointer of the sliding window
            sum += (long long)(nums[right] - nums[right - 1]) * (right - left); 
            // Calculate the sum of differences between consecutive elements
            while (sum > k) { // If the sum exceeds k, move the left pointer and update the sum
                sum -= nums[right] - nums[left];
                left++;
            }
            result = max(result, right - left + 1); // Update the maximum frequency
        }
        
        return result;
    }
};

/*----------------------------------------------------------------------------------------------------*/

//Approach 2: Sliding Window + Prefix Sum

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); // Sort the array in ascending order
        int n = nums.size();
        int left = 0; // Left pointer of the sliding window
        int result = 1; // Initialize the maximum frequency as 1
        
        long long sum = 0; // Sum of elements in the sliding window
        vector<long long> prefixSum(n + 1, 0); // Prefix sum array
        
        for (int i = 1; i <= n; i++) { // Calculate the prefix sum array
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }
        
        for (int right = 1; right < n; right++) { // Right pointer of the sliding window
            sum = prefixSum[right] - prefixSum[left]; // Calculate the sum of elements in the sliding window
            while (sum + k < (long long)nums[right] * (right - left)) { 
                // If the sum plus k is less than the target sum, move the left pointer
                sum = prefixSum[right] - prefixSum[++left];
            }
            result = max(result, right - left + 1); // Update the maximum frequency
        }
        
        return result;
    }
};

/*---------------------------------------------------------------------------------------------------------------*/

//Approach 3: Binary Search

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end()); // Sort the array in ascending order
        int n = nums.size();
        int left = 0; // Left pointer of the sliding window
        int result = 1; // Initialize the maximum frequency as 1
        
        for (int right = 1; right < n; right++) { // Right pointer of the sliding window
            int targetSum = (long long)nums[right] * (right - left); // Calculate the target sum for the sliding window
            
            while (targetSum > k) { // If the target sum exceeds k, adjust the sliding window by moving the left pointer
                targetSum -= nums[right] - nums[left];
                left++;
            }
            
            result = max(result, right - left + 1); // Update the maximum frequency
        }
        
        return result;
    }
};

/*In all the approaches, we sort the array first, which has a time 
complexity of O(n log n). The subsequent sliding window operations 
have a time complexity of O(n). Therefore, the overall time complexity 
of the solution is O(n log n).*/

//space complexity is O(1)

