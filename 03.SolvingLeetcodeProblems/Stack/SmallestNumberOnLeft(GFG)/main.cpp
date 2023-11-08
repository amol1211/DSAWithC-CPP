//Smallest number on left (GFG)

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// 1.Brute-force approach

#include <vector>

using namespace std;

vector<int> leftSmaller(int n, int a[]) {
    vector<int> result(n, -1);  // Initialize the result vector with -1.

    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (a[j] < a[i]) {
                result[i] = a[j];  // Set the result for the current element.
                break;  // Break the inner loop once a smaller element is found.
            }
        }
    }

    return result;
}

//Time complexity : O(n^2)
//Space complexity : O(n)

/*----------------------------------------------------------------------*/

// 2. Stack approach

class Solution {
public:
    vector<int> leftSmaller(int n, int a[]) {
        vector<int> result(n, -1);  // Initialize the result vector with -1.

        stack<int> s;  // Create an empty stack to store indices of elements.

        for (int i = 0; i < n; i++) {
            // While the stack is not empty and the element at the top of the stack is greater than or equal to the current element.
            while (!s.empty() && a[s.top()] >= a[i]) {
                s.pop();  // Pop elements from the stack until the condition is met.
            }

            if (!s.empty()) {
                result[i] = a[s.top()];  // Set the result for the current element.
            }

            s.push(i);  // Push the current element's index onto the stack.
        }

        return result;
    }
};


//Time complexity : O(n)
//Space complexity : O(n)