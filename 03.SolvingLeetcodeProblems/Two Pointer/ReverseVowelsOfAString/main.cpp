//345. Reverse Vowels of a String
#include <iostream>
#include <string>
using namespace std;

class Solution {
private:
    // Function to check if a character is a vowel
    bool isVowel(char &ch) {
        // Check if the character is one of the vowels (both lowercase and uppercase)
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || 
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            // If it is a vowel, return true
            return true;
        }
        // If it is not a vowel, return false
        return false;
    }

public:
    // Function to reverse the vowels in a given string
    string reverseVowels(string s) {
        // Get the length of the string
        int n = s.length();

        // Initialize two pointers, i and j, representing the start and end of the string
        int i = 0;
        int j = n - 1;

        // Continue until i is less than j
        while (i < j) {
            // If s[i] is not a vowel, move the pointer i to the right
            if (!isVowel(s[i])) {
                i++;
            } 
            // If s[j] is not a vowel, move the pointer j to the left
            else if (!isVowel(s[j])) {
                j--;
            } 
            // If both s[i] and s[j] are vowels, swap them and move both pointers
            else {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }

        // Return the modified string with reversed vowels
        return s;
    }
};


/*Time Complexity:

The time complexity of this algorithm is O(n), where n is the length of the input string. 
The while loop processes each character at most once.

Space Complexity:
The space complexity is O(1) since the algorithm uses a constant amount of extra space 
regardless of the input size.*/