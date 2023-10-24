//GFG Problem

class Solution {
public:
    // Function to move elements to insert 'x' at the bottom of the stack.
    void solve(stack<int> &s, int x) {
        // Base case - if the stack is empty.
        if (s.empty()) {
            s.push(x);  // Insert 'x' at the bottom (since the stack is empty).
            return;
        }

        int num = s.top(); // Store the top element of the stack.
        s.pop();           // Remove the top element from the stack.

        // Recursive call - move to the bottom.
        solve(s, x);

        s.push(num); // Push the stored element back on top of 'x'.
    }

    // Function to insert an element 'x' at the bottom of the stack.
    stack<int> insertAtBottom(stack<int> myStack, int x) {
        solve(myStack, x); // Call the solve function to insert 'x' at the bottom.
        return myStack;    // Return the modified stack with 'x' at the bottom.
    }
};

