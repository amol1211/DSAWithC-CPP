//946. Validate Stack Sequences

//Each distinct element
//Initially empty stack
//Popped is permutations of pushed
//lengths of arrays are same

// 1. Stack approach

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st; // Initialize a stack to simulate the stack operations
        int n = pushed.size(); // Get the size of the pushed vector
        int i = 0, j = 0; // Initialize pointers for the pushed and popped arrays
        
        while (i < n && j < n) {
            st.push(pushed[i]); // Push the current element from pushed to the stack

            while (!st.empty() && j < n && st.top() == popped[j]) {
                st.pop(); // Pop elements from the stack as long as they match with popped
                j++;
            }
            i++; // Move to the next element in the pushed array
        }

        return st.empty(); // Check if the stack is empty at the end
    }
};

/*Time Complexity: O(n)
Space Complexity: O(n)*/

/*--------------------------------------------------------------------------------------------*/

// 2.Pointers approach

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0, j = 0; // Initialize pointers for the pushed and popped arrays

        for (int x : pushed) {
            pushed[i++] = x; // Replace pushed[i] with x and increment i
            
            while (i > 0 && pushed[i - 1] == popped[j]) {
                --i; // Decrement i to simulate a pop operation from the stack
                ++j; // Move to the next element in the popped array
            }
        }

        return i == 0; // Check if all elements have been processed (stack is empty)
    }
};

/*Time Complexity: O(n)
Space Complexity: O(n)*/


