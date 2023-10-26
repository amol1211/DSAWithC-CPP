// Codestudio problem

#include <iostream>
#include <stack>
using namespace std;


bool findRedundantBrackets(string &s) {
    stack<char> st; // Create a stack to store characters

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i]; // Get the current character

        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            // If the character is an opening parenthesis or an operator, push it onto the stack.
            st.push(ch);
        } else {
            // The character is either ')' or a lowercase letter

            if (ch == ')') { // If the character is a closing parenthesis
                bool isRedundant = true;

                // Check for redundant brackets by examining the characters between '(' and ')'
                while (st.top() != '(') {
                    char top = st.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/') {
                        isRedundant = false; // If an operator is found, it's not a redundant bracket
                    }
                    st.pop();
                }

                if (isRedundant == true) {
                    return true; // If it's a redundant bracket, return true
                }

                st.pop(); // Pop the opening parenthesis from the stack
            }
        }
    }

    return false; // If no redundant brackets are found, return false
}

//Time Complexity: O(N)
//Space Complexity: O(N)
