//344. Reverse String

#include <iostream>
#include <vector>
using namespace std;

// 1. Iterative approach

class Solution {
public:
    // Function to reverse a string in-place
    void reverseString(vector<char>& s) {
        // Initialize two pointers, i at the beginning, and j at the end
        int i = 0, j = s.size() - 1;

        // Iterate through the string until i is no longer less than j
        while (i < j) {
            // Swap characters at indices i and j
            swap(s[i], s[j]);
            
            // Move the pointers towards each other
            i++;
            j--;
        }
        // The string is now reversed in-place
    }
};

//Time complexity : O(n)
//Space complexity : O(1)

/*---------------------------------*/

// 2. Recursive approach

class Solution {
private:
    // Recursive helper function to reverse a portion of the string
    void reverseHelper(vector<char>& s, int i, int j) {
        // Base case: if the indices cross or are equal, the string is reversed for this segment
        if (i >= j) {
            return;
        }

        // Swap characters at indices i and j
        swap(s[i], s[j]);
        // Move the indices towards each other
        i++;
        j--;

        // Recursive call to reverse the remaining portion of the string
        reverseHelper(s, i, j);
    }

public:
    // Public function to reverse the entire string
    void reverseString(vector<char>& s) {
        // Call the recursive helper function with the entire range of the string
        reverseHelper(s, 0, s.size() - 1);
    }
};

//Time complexity : O(n)
//Space complexity : O(1)