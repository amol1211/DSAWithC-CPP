//503. Next Greater Element II

#include <iostream>
#include <stack>
using namespace std;

// 1.Brute force appraoch

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);  // Initialize the result vector with -1 values

        for (int i = 0; i < n; i++) {  // Loop through the elements in nums
            for (int j = 1; j < n; j++) {  // Search for the next greater element in a circular manner
                int nextIdx = (i + j) % n;  // Calculate the circular index

                if (nums[nextIdx] > nums[i]) {
                    ans[i] = nums[nextIdx];
                    break;  // We found the next greater element, so break the loop
                }
            }
        }

        return ans;
    }
};

//Time complexity : O(n^2)
//Space complexity : O(n)

/*------------------------------------------------------------------------------------*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size(); // Get the size of the input vector.
        vector<int> ans(n, -1); // Initialize the result vector with -1s.
        stack<int> s; // Create a stack to store indices of elements from nums.

        for (int i = 2 * n - 1; i >= 0; i--) {
            // Loop through 2 * n - 1 to 0, effectively traversing the circular array.

            while (!s.empty() && nums[s.top()] <= nums[i % n]) {
                // While the stack is not empty and the current element is greater
                // than or equal to the element at the index stored in the stack,
                // pop elements from the stack until this condition is met.
                s.pop();
            }

            if (!s.empty() && (i < n)) {
                // If the stack is not empty and the current index is within the
                // range of the original array (0 to n-1), update ans for the
                // corresponding index with the next greater element from nums.
                ans[i % n] = nums[s.top()];
            }

            s.push(i % n); // Push the current index into the stack.
        }

        return ans; // Return the result vector containing the next greater elements.
    }
};

/*Time Complexity: The time complexity of this code is O(n), 
where n is the number of elements in the input vector nums. The code iterates through 
the elements twice (2 * n) and maintains a stack, which operates in constant time for each element.

Space Complexity: The space complexity is O(n) because of the result vector ans and the stack s, 
both of which can have a maximum of n elements.*/