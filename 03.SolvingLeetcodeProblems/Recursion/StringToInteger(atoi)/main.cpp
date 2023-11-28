// 8. String to Integer (atoi)

#include <iostream>
#include <climits>
#include <string>
#include <cctype>
using namespace std;

// 1. Brute force approach

class Solution {
public:
    int myAtoi(string s) {
        // Get the length of the input string
        int n = s.length();
        // Initialize the index i, sign, and result variables
        int i = 0;
        int sign = 1;
        long result = 0;

        // Skip leading whitespaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Handle sign only once
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            // Update sign based on the encountered sign character
            sign = (s[i] == '-') ? -1 : 1;
            i++; // Move to the next character
        }

        // Process digits
        while (i < n && isdigit(s[i])) {
            // Update the result by appending the current digit
            result = result * 10 + s[i] - '0';

            // Check for overflow
            if (result * sign > INT_MAX) {
                return INT_MAX; // Return maximum integer value in case of overflow
            } else if (result * sign < INT_MIN) {
                return INT_MIN; // Return minimum integer value in case of overflow
            }

            i++; // Move to the next character
        }

        // Return the final result after applying the sign
        return static_cast<int>(result * sign);
    }
};

//Time complexity : O(n) 
//Space complexity : O(1)

/*------------------------------------------------------------------------------------*/

//2. Recursive approach

class Solution {
public:
    int myAtoiHelper(const string& s, int& i, int sign) {
        long result = 0;

        // Step 3: Read in digits
        while (i < s.length() && isdigit(s[i])) {
            result = result * 10 + (s[i++] - '0');

            // Step 4: Check for overflow
            if (result * sign > INT_MAX) {
                return INT_MAX;
            } else if (result * sign < INT_MIN) {
                return INT_MIN;
            }
        }

        return static_cast<int>(result * sign);
    }

    int myAtoi(const string& s, int i = 0, int sign = 1) {
        // Step 1: Ignore leading whitespace
        while (i < s.length() && s[i] == ' ') {
            i++;
        }

        // Step 2: Check for sign
        if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i++] == '-') ? -1 : 1;
        }

        return myAtoiHelper(s, i, sign);
    }
};

//Time complexity : O(n) 
//Space complexity : O(1)
