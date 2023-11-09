//739. Daily Temperatures

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// 1. Stack approach

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s; // Stack to store indices of temperatures
        int n = temperatures.size(); // Number of elements in temperatures array
        vector<int> result(n, 0); // Result vector to store the days until a warmer temperature

        for (int i = 0; i < n; i++) {
            while (!s.empty() && temperatures[s.top()] < temperatures[i]) {
                // If the current temperature is higher than the temperature at the top of the stack
                result[s.top()] = i - s.top(); // Update the result for the top of the stack
                s.pop(); // Pop the element from the stack
            }

            s.push(i); // Push the current index onto the stack
        }

        return result; // Return the result vector
    }
};

//Time complexity : O(n)
//Space complexity : O(n)

/*----------------------------------------*/

// 2. Another variant of stack appraoch with reverse loop

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        int n = temperatures.size();
        vector<int> result(n, 0);

        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && temperatures[s.top()] <= temperatures[i]) {
                s.pop();            
            }
            
            if (!s.empty()) {
                result[i] = s.top() - i;
            }
            
            s.push(i);
        }

        return result;
    }
};

//Time complexity : O(n)
//Space complexity : O(n)

/*-----------------------------------------------*/

// 3. Brute force (TLE)

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (temperatures[j] > temperatures[i]) {
                    result[i] = j - i;
                    break;
                }
            }
        }

        return result;
    }
};

//Time complexity : O(n^2)
//Space complexity : O(n)