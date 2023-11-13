#include <iostream>
#include <stack>
using namespace std;

//1. Stack approach

class Solution {
public:
    int Operate(int a, int b, string token) {
        if (token == "+")
            return a + b;
        if (token == "-")
            return a - b;
        if (token == "*")
            return (long)a * (long)b; // Using 'long' to handle potential integer overflow.
        if (token == "/")
            return a / b; // Note: Integer division, which truncates any decimal part.
        return -1; // Unknown operator; you may want to handle this case differently.
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for (string &token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = s.top(); // Get the second operand.
                s.pop(); // Remove it from the stack.
                int a = s.top(); // Get the first operand.
                s.pop(); // Remove it from the stack.

                int result = Operate(a, b, token); // Perform the operation.
                s.push(result); // Push the result back onto the stack.
            } else {
                s.push(stoi(token)); // Push the integer value onto the stack.
            }
        }

        return s.top(); // The final result is at the top of the stack.
    }
};

//Time complexity : O(n)
//Space complexity : O(n)

/*---------------------------------------------------------------------------------------*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s; // Create a stack to store operands and intermediate results.

        // Define a map that associates operators with lambda functions.
        unordered_map<string, function<int(int, int)>> mp = {
            {"+", [](int a, int b) { return a + b; }},
            {"-", [](int a, int b) { return a - b; }},
            {"*", [](int a, int b) { return (long)a * (long)b; }},
            {"/", [](int a, int b) { return a / b; }},
        };

        // Iterate through the tokens in the input array.
        for (string &token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = s.top(); // Get the second operand.
                s.pop(); // Remove it from the stack.
                int a = s.top(); // Get the first operand.
                s.pop(); // Remove it from the stack.

                // Perform the operation using the lambda function from the map.
                int result = mp[token](a, b);

                s.push(result); // Push the result back onto the stack.
            } else {
                s.push(stoi(token)); // Push the integer value onto the stack.
            }
        }

        return s.top(); // The final result is at the top of the stack.
    }
};

//Time complexity : O(n)
//Space complexity : O(n)
