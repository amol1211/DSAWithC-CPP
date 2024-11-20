//2516. Take K of Each Character From Left and Right

//Approach 1 : Brute force with recursion (TLE)
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
    int result = INT_MAX; // Initialize the result with a very large value.

    // Recursive function to explore all possibilities.
    void solve(string& s, int k, int i, int j, int minutes, vector<int> charFreq) {
        // If all characters ('a', 'b', 'c') have frequency >= k, update the result.
        if (charFreq[0] >= k && charFreq[1] >= k && charFreq[2] >= k) {
            result = min(result, minutes); // Update the minimum minutes.
            return;
        }

        // Base case: If pointers cross, return as all characters have been considered.
        if (i > j)
            return;

        // **Option 1: Delete from the left**
        vector<int> tempCharFreqLeft = charFreq; // Copy current frequency state.
        tempCharFreqLeft[s[i] - 'a'] += 1;      // Increment the frequency of the character being deleted.
        solve(s, k, i + 1, j, minutes + 1, tempCharFreqLeft); // Recurse with the updated state.

        // **Option 2: Delete from the right**
        vector<int> tempCharFreqRight = charFreq; // Copy current frequency state.
        tempCharFreqRight[s[j] - 'a'] += 1;       // Increment the frequency of the character being deleted.
        solve(s, k, i, j - 1, minutes + 1, tempCharFreqRight); // Recurse with the updated state.
    }

    int takeCharacters(string s, int k) {
        // **Brute force approach**

        vector<int> charFreq(3, 0); // Frequency array for 'a', 'b', and 'c'.

        int i = 0;                 // Left pointer.
        int j = s.length() - 1;    // Right pointer.
        int minutes = 0;           // Initial count of deletions.

        // Call the recursive solve function to explore all possible deletions.
        solve(s, k, i, j, minutes, charFreq);

        // If the result remains INT_MAX, it means no valid solution was found.
        return result == INT_MAX ? -1 : result;
    }
};

/*Time complexity : O(2^n)
  Space complexity : O(n)*/

/*----------------------------------------------------------------------------------------------------------*/

//Approach 2 : Sliding window

class Solution {
public:
    int takeCharacters(string s, int k) {

        int n = s.length(); // Get the length of the input string.

        int count_a = 0, count_b = 0, count_c = 0; // Initialize counters for 'a', 'b', and 'c'.

        // Count the frequency of each character in the string.
        for (char& ch : s) { 
            if (ch == 'a') count_a++;
            else if (ch == 'b') count_b++;
            else count_c++;
        }

        // If any character has a frequency less than k, it's impossible to satisfy the condition.
        if (count_a < k || count_b < k || count_c < k) {
            return -1; // Return -1 to indicate the task is not possible.
        }

        int i = 0, j = 0; // Initialize two pointers for the sliding window.
        int notDeletedWindowSize = 0; // Track the size of the largest valid subarray.

        // Expand the window to the right until the end of the string.
        while (j < n) {

            // Decrease the count for the current character in the window.
            if (s[j] == 'a') count_a--;
            else if (s[j] == 'b') count_b--;
            else count_c--;

            // Shrink the window from the left if any character count becomes invalid (< k).
            while (i <= j && (count_a < k || count_b < k || count_c < k)) {
                if (s[i] == 'a') count_a++; // Restore the count for 'a'.
                else if (s[i] == 'b') count_b++; // Restore the count for 'b'.
                else count_c++; // Restore the count for 'c'.
                i++; // Move the left pointer forward.
            }

            // Update the maximum size of the valid window that doesn't need deletion.
            notDeletedWindowSize = max(notDeletedWindowSize, j - i + 1);
            j++; // Move the right pointer forward.
        }

        // Calculate and return the number of characters to be deleted.
        return n - notDeletedWindowSize; 
    }
};

/*Time complexity : O(n)
  Space complexity : O(1)*/



