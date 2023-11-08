//Next Greater Element (GFG)

#include <iostream>
#include <vector>
#include <stack>
using namespace std;


// 1. Brute force approach (TLE)

class Solution {
public:
    vector<long long> nextLargerElement(vector<long long> arr, int n) {
        vector<long long> result(n, -1);  // Initialize the result vector with -1.

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[j] > arr[i]) {
                    result[i] = arr[j];  // Set the result for the current element.
                    break;  // Break the inner loop once a greater element is found.
                }
            }
        }

        return result;
    }
};

//Time complexity : O(n^2)
//Space complexity : O(n)

/*---------------------------------------------------------------------------------------*/

// 2. stack approach
class Solution
{
public:
    // Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        
        stack<long long> s;          // Stack to hold elements from the array.
        vector<long long> result(n, -1);  // Initialize the result vector with -1.

        // Loop through the array in reverse order.
        for (int i = n - 1; i >= 0; i--) {
            // While the stack is not empty and the top element of the stack is less than or equal to the current element.
            while (!s.empty() && s.top() <= arr[i]) {
                s.pop();  // Pop elements from the stack until the condition is met.
            }
            
            if (!s.empty()) {
                result[i] = s.top();  // Set the result for the current element from the top of the stack.
            }

            s.push(arr[i]);  // Push the current element onto the stack for future comparisons.
        }

        return result;  // Return the result vector with next greater elements.
    }
};

//time complexity is O(n)
//space complexity is O(n)
