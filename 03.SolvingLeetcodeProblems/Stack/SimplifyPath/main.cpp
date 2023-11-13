//71. Simplify Path

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// 1. Stack approach

class Solution {
public:
    string simplifyPath(string path) {
        string token = ""; // Declare a string variable to store individual path components.

        stringstream ss(path); // Create a stringstream object to split the input 'path' string into tokens.
        stack<string> s; // Create a stack to store valid path components.

        // Start processing the input 'path' string.
        while (getline(ss, token, '/')) {
            // Tokenize the input string by '/' and process each component.

            if (token == "" || token == ".") continue; // Skip empty components and "." components.

            if (token != "..") {
                s.push(token); // Push valid path components onto the stack.
            } else if (!s.empty()) {
                s.pop(); // Pop the top component from the stack when encountering "..".
            }
        }

        if (s.empty())
            return "/"; // If the stack is empty, return the root directory.

        string result = "";

        // Reconstruct the simplified path by popping components from the stack.
        while (!s.empty()) {
            result = "/" + s.top() + result;
            s.pop();
        }  

        return result; // Return the simplified path.
    }
};

//Time complexity : O(n)
//Space complexity : O(n)

/*--------------------------------------------------------------------------*/

// 2. Vector approach

class Solution {
public:
    string simplifyPath(string path) {
        string token = ""; // Declare a string variable to store individual path components.

        stringstream ss(path); // Create a stringstream object to split the input 'path' string into tokens.
        vector<string> s; // Create a vector to store valid path components.

        // Start processing the input 'path' string.
        while (getline(ss, token, '/')) {
            // Tokenize the input string by '/' and process each component.

            if (token == "" || token == ".") continue; // Skip empty components and "." components.

            if (token != "..") {
                s.push_back(token); // Push valid path components into the vector.
            } else if (!s.empty()) {
                s.pop_back(); // Pop the last component from the vector when encountering "..".
            }
        }

        if (s.empty())
            return "/"; // If the vector is empty, return the root directory.

        string result = "";

        for (auto &token : s) {
            result = result + "/" + token; // Concatenate components to reconstruct the simplified path.
        } 

        return result; // Return the simplified path.
    }
};

//Time complexity : O(n)
//Space complexity : O(n)

