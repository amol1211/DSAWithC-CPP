//2390. Removing Stars From a String

#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

// 1. Stack approach

// Stack approach
class Solution {
public:
    string removeStars(string s) {
        int n = s.length();

        stack<char> st;

        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                st.pop(); // Remove the previous character
            } else {
                st.push(s[i]);
            }
        }

        string ans = "";
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

/*Time Complexity: O(n), where n is the length of the input string 's'. 
The loop iterates through the string once.
Space Complexity: O(n), as the stack can potentially contain all characters in the input string.*/

/*-----------------------------------------------------------------------------------------------------*/

// 2. String Approach:

// String approach
class Solution {
public:
    string removeStars(string s) {
        int n = s.length();

        string ans = "";

        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                ans.pop_back(); // Remove the previous character
            } else {
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};

/*Time Complexity: O(n)
Space Complexity: O(n)*/

/*------------------------------------------------------------------------------*/

// 3. Two Pointer Approach:

// Two-pointer approach
class Solution {
public:
    string removeStars(string s) {
        int n = s.length();
        vector<char> temp(n);

        int j = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '*') {
                j--; // Move the pointer back to effectively remove the previous character
            } else {
                temp[j] = s[i];
                j++;
            }
        }

        string ans = "";
        for (int k = 0; k <= j - 1; k++) {
            ans.push_back(temp[k]);
        }

        return ans;
    }
};

/*Time Complexity: O(n)
Space Complexity: O(n)*/