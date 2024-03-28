//2958. Length of Longest Subarray With at Most K Frequency

#include <bits/stdc++.h>
using namespace std;

// This solution uses a sliding window approach to find the maximum length of a subarray 
// whose elements occur at most k times. It employs a hashmap to store the frequency of 
// elements in the current window.

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(); // Size of the input array

        unordered_map<int, int> mp; // Hashmap to store the frequency of elements

        int i = 0, j = 0; // Pointers for the sliding window
        int maxLength = 0; // Variable to store the maximum length of subarray

        // Loop until the end of the array
        while (j < n) {

            mp[nums[j]]++; // Increment the frequency of the current element

            // Check if frequency exceeds k, if yes, move the left pointer
            while(i < j && mp[nums[j]] > k) {
                mp[nums[i]]--; // Decrement the frequency of the leftmost element
                i++; // Move the left pointer to the right
            }

            maxLength = max(maxLength, j - i + 1); // Update the maximum length
            j++; // Move the right pointer to the right
        }

        return maxLength; // Return the maximum length of the subarray
    }
};

/*Time Complexity: O(n) where n is the number of elements in the input array. The algorithm scans the array once using two pointers, i and j, and performs constant-time operations within the loop.

Space Complexity: O(n) due to the usage of the unordered_map to store the frequency of elements in the array. In the worst case, the hashmap can store all elements of the array.*/

/*-------------------------------------------------------------------------*/

// This solution is similar to the previous one but includes a counter for elements 
// whose frequency exceeds k. It avoids unnecessary sliding of the window when there's
// no element violating the constraint.

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size(); // Size of the input array

        unordered_map<int, int> mp; // Hashmap to store the frequency of elements

        int i = 0, j = 0; // Pointers for the sliding window
        int maxLength = 0; // Variable to store the maximum length of subarray
        int culprit = 0; // Counter for elements whose frequency exceeds k

        // Loop until the end of the array
        while (j < n) {

            mp[nums[j]]++; // Increment the frequency of the current element

            // If the frequency exceeds k, increment the culprit count
            if (mp[nums[j]] == k + 1) {
                culprit++;
            }

            // If there's a culprit, move the left pointer and adjust the culprit count
            if (culprit > 0) {
                mp[nums[i]]--; // Decrement the frequency of the leftmost element
                if (mp[nums[i]] == k) {
                    culprit--; // Decrement the culprit count if the frequency becomes k
                }
                i++; // Move the left pointer to the right
            }

            // Update the maximum length if there's no culprit
            if (culprit == 0) {
                maxLength = max(maxLength, j - i + 1); // Update the maximum length
            }
            j++; // Move the right pointer to the right
        }

        return maxLength; // Return the maximum length of the subarray
    }
};

/*Time Complexity: O(n) where n is the number of elements in the input array. Similar to the previous approach, the algorithm scans the array once using two pointers, i and j, and performs constant-time operations within the loop.

Space Complexity: O(n) due to the usage of the unordered_map to store the frequency of elements in the array. In the worst case, the hashmap can store all elements of the array. Additionally, there's a constant space overhead for the 'culprit' variable.*/