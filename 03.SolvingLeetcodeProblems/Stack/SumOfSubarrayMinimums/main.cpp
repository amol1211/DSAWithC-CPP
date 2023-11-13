//907. Sum of Subarray Minimums

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getNSL(vector<int> &arr, int n) {
        vector<int> result(n); // Create a vector to store the next smaller element to the 
        //left (NSL) for each element in 'arr'.
        stack<int> s; // Create a stack to help find the NSL values.

        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i])
                s.pop(); // Pop elements from the stack until the top element is smaller than the current element.

            result[i] = s.empty() ? -1 : s.top(); // Store the NSL for the current element in 'result'.
            s.push(i); // Push the current element onto the stack for future comparisons.
        }

        return result; // Return the vector of NSL values.
    }
    
    vector<int> getNSR(vector<int> &arr, int n) {
        vector<int> result(n); // Create a vector to store the next smaller element to the right (NSR) 
        //for each element in 'arr'.
        stack<int> s; // Create a stack to help find the NSR values.

        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] > arr[i])
                s.pop(); // Pop elements from the stack until the top element is smaller than or equal 
                //to the current element.

            result[i] = s.empty() ? n : s.top(); // Store the NSR for the current element in 'result'.
            s.push(i); // Push the current element onto the stack for future comparisons.
        }

        return result; // Return the vector of NSR values.
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> NSL = getNSL(arr, n); // Calculate the NSL values for the input array.
        vector<int> NSR = getNSR(arr, n); // Calculate the NSR values for the input array.

        long long sum = 0;
        int M = 1e9+7; // Modulus value for the final answer.

        for (int i = 0; i < n; i++) {
            long long ls = i - NSL[i]; // Calculate the number of subarrays with the current element as the 
            //minimum on the left.
            long long rs = NSR[i] - i; // Calculate the number of subarrays with the current element as the 
            //minimum on the right.

            long long totalWays = ls * rs; // Calculate the total number of subarrays with the current element 
            //as the minimum.

            long long totalSum = arr[i] * totalWays; // Calculate the sum of subarrays with the current element 
            //as the minimum.

            sum = (sum + totalSum) % M; // Update the running sum with the current element's contribution.
        }

        return sum; // Return the final result.
    }
};

//Time complexity : O(n)
//Space complexity : O(n)