//N Stacks In An Array - Coding Ninja's problem

#include <bits/stdc++.h> 

class NStack
{
    int *arr;      // Array to store elements for all stacks
    int *top;      // Array to keep track of the top element in each stack
    int *next;     // Array to keep track of the next free slot in the array

    int n, s;       // n: number of stacks, s: total size of the array
    int freespot;   // Index of the next free spot in the array

public:
    // Constructor to initialize the NStack data structure.
    NStack(int N, int S)
    {
        n = N;
        s = S;

        arr = new int[s];
        top = new int[n];
        next = new int[s];

        // Initialize top: Set the top of each stack to -1 (empty).
        for (int i = 0; i < n; i++) {
            top[i] = -1;
        }

        // Initialize next: Set the next available slot to the next slot (consecutive).
        for (int i = 0; i < s - 1; i++) {
            next[i] = i + 1;
        }
        next[s - 1] = -1; // The last slot is the end of the array.

        // Initialize freespot: Set the first available slot as 0.
        freespot = 0;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // Check for overflow (if there's no space left in the array).
        if (freespot == -1) {
            return false;
        }

        // Find the index of the next free spot.
        int index = freespot;

        // Insert the element 'x' into the array at the found index.
        arr[index] = x;

        // Update freespot to the next available spot.
        freespot = next[index];

        // Update 'next' to point to the previous top of the stack 'm'.
        next[index] = top[m - 1];

        // Update 'top' to the new top, which is the inserted element.
        top[m - 1] = index;

        return true; // Element successfully pushed.
    }

    // Pops the top element from the Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // Check for underflow (if the stack is empty).
        if (top[m - 1] == -1) {
            return -1;
        }

        // Find the index of the current top element in stack 'm'.
        int index = top[m - 1];

        // Update 'top' to the next element in the stack.
        top[m - 1] = next[index];

        // Update 'next' to point to the current freespot.
        next[index] = freespot;

        // Update freespot to the index of the popped element.
        freespot = index;

        // Return the popped element from the stack.
        return arr[index];
    }
};

//Time complexity : O(1)
//Space complexity : O(S + N)
