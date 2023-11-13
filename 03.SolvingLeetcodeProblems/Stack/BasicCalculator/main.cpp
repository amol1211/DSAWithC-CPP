//224. Basic Calculator

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public: 
    int calculate(string s) {
        int n = s.length(); // Obtain the length of the input string.
        stack<int> st; // Initialize a stack to help with calculations.

        int number = 0; // Initialize a variable to store the current number being evaluated.
        int result = 0; // Initialize the final result.
        int sign = 1; // Initialize the sign (+ or -) for the current number.

        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) { // If the character is a digit, update the current number.
                number = number * 10 + (s[i] - '0');
            } else if (s[i] == '+') { // If the character is '+', update result with the current number 
            //based on the sign.
                result += (number * sign);
                number = 0; // Reset the number for the next calculation.
                sign = 1; // Update the sign for the next number.
            } else if (s[i] == '-') { // If the character is '-', update result with the current number based 
            //on the sign.
                result += (number * sign);
                number = 0; // Reset the number for the next calculation.
                sign = -1; // Update the sign for the next number.
            } else if (s[i] == '(') { // If the character is '(', store the current result, sign, and reset for 
            //the new segment.
                st.push(result);
                st.push(sign);
                result = 0;
                number = 0;
                sign = 1;
            } else if (s[i] == ')') { // If the character is ')', perform operations to handle the segment within 
            //the parentheses.
                result += (number * sign);
                number = 0;

                int stack_sign = st.top(); st.pop(); // Retrieve the sign from the stack.
                int last_result = st.top(); st.pop(); // Retrieve the last result from the stack.

                result *= stack_sign; // Multiply the result within the parentheses 
                //by the sign outside the parentheses.
                result += last_result; // Add the result within the parentheses to the previous result.
            }
        }
        result += (number * sign); // Add any remaining number at the end of the string to the final result.
        return result; // Return the computed result.
    }
};

//Time complexity : O(n)
//Space complexity : O(n)