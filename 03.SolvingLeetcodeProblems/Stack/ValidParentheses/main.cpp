//20. Valid Parentheses

class Solution {
public:
    bool isValid(string s) {
        // Create a stack to store opening brackets as they are encountered.
        stack<char> ans;

        // Loop through each character in the input string 's'.
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i]; // Get the current character.

            // Check if 'ch' is an opening bracket ('{', '(', or '[').
            if (ch == '{' || ch == '(' || ch == '[') {
                ans.push(ch); // Push it onto the stack.
            } else {
                // If 'ch' is not an opening bracket...
                if (!ans.empty()) {
                    char top = ans.top(); // Get the top character from the stack.

                    // Check if 'ch' matches with the corresponding opening bracket.
                    if (ch == ')' && top == '(' ||
                        ch == '}' && top == '{' ||
                        ch == ']' && top == '[') {
                        ans.pop(); // Pop the matching opening bracket from the stack.
                    } else {
                        return false; // Mismatched brackets, return 'false'.
                    }
                } else {
                    return false; // No matching opening bracket, return 'false'.
                }
            }
        }
        
        // After processing all characters, if the stack is empty, return 'true'.
        if (ans.empty())
            return true;
        else 
            return false;
    }
};
