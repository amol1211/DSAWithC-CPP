//GFG problem
//Delete middle element of a stack

class Solution
{
public:

    // This method is a recursive helper function to delete the middle element of the stack.
    void solve(stack<int>& s, int count, int size) {
        // Base case: If the count reaches half of the size, we remove the middle element and return.
        if (count == size / 2) {
            s.pop();
            return;
        }

        // Get the top element from the stack and remove it.
        int num = s.top();
        s.pop();

        // Recursive call: Continue with the next element and increment the count.
        solve(s, count + 1, size);

        // After the recursive call, push the previously removed element back onto the stack.
        s.push(num);
    }

    // Function to delete the middle element of a stack.
    void deleteMid(stack<int>& s, int sizeOfStack)
    {
        int count = 0;
        // Start the process by calling the solve method with the initial count and the size of the stack.
        solve(s, count, sizeOfStack);
    }
};

//Time Complexity: O(N)
//Space Complexity: O(N)
