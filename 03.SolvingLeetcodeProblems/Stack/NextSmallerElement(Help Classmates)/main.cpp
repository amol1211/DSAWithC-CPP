//GFG Problem
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//Approach 1 : Brute force

class Solution {
public:
    vector<int> help_classmate(vector<int> arr, int n) {
        vector<int> result(n, -1);  // Initialize the result vector with -1.

        for (int i = 0; i < n; i++) {
            int curr = arr[i];

            // Iterate through elements to the right of the current element to find the next smaller element.
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < curr) {
                    result[i] = arr[j];  // Set the result for the current element.
                    break;  // Exit the inner loop once a smaller element is found.
                }
            }
        }

        return result;
    }
};

/*---------------------------------------------------------------------------------*/

class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        stack<int> s;
        s.push(-1);
        
        
        for (int i = n - 1; i >= 0; i--) {
            int curr = arr[i];
            
            while (s.top() >= curr) {
                s.pop();
            }
            arr[i] = s.top();
            s.push(curr);
        }
        
        return arr;
    } 
};

