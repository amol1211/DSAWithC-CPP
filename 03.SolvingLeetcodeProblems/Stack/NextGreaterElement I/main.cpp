//496. Next Greater Element I

#include <iostream>
#include <stack>
#include <map>
using namespace std;

// 1. Brute force approach

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int n = nums2.size();

        for (int num1 : nums1) {
            int index = -1;

            // Find the index of num1 in nums2
            for (int i = 0; i < n; i++) {
                if (nums2[i] == num1) {
                    index = i;
                    break;
                }
            }

            int nextGreater = -1;

            // Search for the next greater element in nums2
            for (int i = index + 1; i < n; i++) {
                if (nums2[i] > num1) {
                    nextGreater = nums2[i];
                    break;
                }
            }

            ans.push_back(nextGreater);
        }

        return ans;
    }
};

//Time Complexity: O(n^2)
//Space Complexity: O(1)

/*--------------------------------------------------------------*/

// 2. Stack + hashmap approach
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans; // Initialize the result vector
        stack<int> s; // Create a stack to store indices
        unordered_map<int, int> nextGreater; // Create a map to store next greater elements

        for (int i = 0; i < nums2.size(); i++) {
            while (!s.empty() && nums2[i] > nums2[s.top()]) {
                // While the stack is not empty and the current element is greater than the element at the top of the stack
                nextGreater[nums2[s.top()]] = nums2[i]; // Store the next greater element in the map
                s.pop(); // Remove the element at the top of the stack
            }
            s.push(i); // Push the current element's index onto the stack
        }

        for (int i = 0; i < nums1.size(); i++) {
            ans.push_back(nextGreater.count(nums1[i]) ? nextGreater[nums1[i]] : -1);
            // For each element in nums1, add its next greater element from the map to the result vector, or -1 if not found
        }

        return ans; // Return the result vector

    }
};

/*Time Complexity:

The first loop processes nums2, which has a time complexity of O(n), where n is the size of nums2.
The second loop processes nums1, which has a time complexity of O(m), where m is the size of nums1.
In total, the time complexity is O(n + m).
Space Complexity:

The space complexity is O(n) due to the stack and the nextGreater map, where n is the size of nums2*/
