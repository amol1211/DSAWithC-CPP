//84. Largest Rectangular Area in Histogram

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//Approach 1: Brute force approach

//The intuition behind the approach is taking different 
//bars and finding the maximum width possible using the bar.

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();  // Get the number of elements in the input vector.
        int maxArea = 0;  // Initialize the maximum area to 0.
        
        for (int i = 0; i < n; i++) {  // Iterate through the elements of the input vector.
            int minHeight = INT_MAX;  // Initialize the minimum height to positive infinity.
            
            for (int j = i; j < n; j++) {  // Iterate from the current element to the end of the vector.
                minHeight = min(minHeight, heights[j]);  // Update the minimum height.
                maxArea = max(maxArea, minHeight * (j - i + 1));  // Update the maximum area.
            }
        }
        
        return maxArea;  // Return the maximum area.
    }
};

//Time Complexity: O(N*N)
//Space Complexity: O(1)

/*-------------------------------------------------------------------------------------------------------*/

//Approach 2 : optimized approach using stack

class Solution {

private:
    // Function to find the next smaller element for each element of the array.
    vector<int> nextSmallerElement(vector<int> arr, int n) {
        stack<int> s;                // Create an empty stack to hold indices.
        s.push(-1);                  // Initialize the stack with -1.
        vector<int> ans(n);          // Create a vector to store results.

        for (int i = n - 1; i >= 0; i--) {
            int curr = arr[i];        // Current element in the array.

            // Pop elements from the stack while they are not smaller or -1.
            while(s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }
            ans[i] = s.top();         // Store the index of the next smaller element.
            s.push(i);                // Push the current element's index onto the stack.
        }

        return ans;                   // Return a vector of indices.
    }

    // Function to find the previous smaller element for each element of the array.
    vector<int> prevSmallerElement(vector<int> arr, int n) {
        stack<int> s;                // Create an empty stack to hold indices.
        s.push(-1);                  // Initialize the stack with -1.
        vector<int> ans(n);          // Create a vector to store results.

        for (int i = 0; i < n; i++ ) {
            int curr = arr[i];        // Current element in the array.

            // Pop elements from the stack while they are not smaller or -1.
            while(s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }
            ans[i] = s.top();         // Store the index of the previous smaller element.
            s.push(i);                // Push the current element's index onto the stack.
        }

        return ans;                   // Return a vector of indices.
    }        

public:
    // Function to find the largest rectangle area in a histogram.
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();        // Get the number of elements in the input array.

        vector<int> next;              // Vector to store results from nextSmallerElement.
        next = nextSmallerElement(heights, n);

        vector<int> prev;              // Vector to store results from prevSmallerElement.
        prev = prevSmallerElement(heights, n);

        int area = INT_MIN;            // Initialize the maximum area to a very small value.

        for (int i = 0; i < n; i++) {
            int l = heights[i];        // Current height of the histogram.

            if(next[i] == -1) {
                next[i] = n;             // If there is no next smaller element, set it to the end of the array.
            }

            int b = next[i] - prev[i] - 1;  // Calculate the width of the rectangle.
            int newArea = l * b;            // Calculate the area of the rectangle.
            area = max(area, newArea);      // Update the maximum area if needed.
        }

        return area;                      // Return the maximum rectangle area.
    }
};

//Time Complexity: O(N*N)
//Space Complexity: O(1)