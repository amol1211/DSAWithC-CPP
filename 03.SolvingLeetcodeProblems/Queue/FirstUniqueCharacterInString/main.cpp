//387. First Unique Character in a String
#include <iostream>
using namespace std;

// 1. Brute Force Approach:

class Solution {
public:
    int firstUniqChar(string s) {
        for (int i = 0; i < s.length(); i++) {
            bool isUnique = true;  // Flag to track if the character is unique.
            for (int j = 0; j < s.length(); j++) {
                if (i != j && s[i] == s[j]) { // Check if the character appears again in the string.
                    isUnique = false;
                    break;
                }
            }
            if (isUnique) {
                return i;  // Return the index if the character is unique.
            }
        }
        return -1;  // Return -1 if no unique character is found.
    }
};

//Time Complexity: O(n^2)
//Space Complexity: O(1).

/*-----------------------------------------------------------------------------------*/

//2. HashMap approach :

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> charCount; // Create a hash map to count character occurrences.
        for (char c : s) {
            charCount[c]++;
        }
        for (int i = 0; i < s.length(); i++) {
            if (charCount[s[i]] == 1) { // Check if the count of the character is 1.
                return i;
            }
        }
        return -1;  // Return -1 if no unique character is found.
    }
};

//Time Complexity: O(n), where n is the length of the string.
//Space Complexity: O(k), where k is the number of distinct characters.

/*------------------------------------------------------------------------------------------------------*/

//3. Array-Based counting Approach

class Solution {
public:
    int firstUniqChar(string s) {
        int charCount[26] = {0}; // Create an array to count character occurrences for lowercase English letters.
        for (char c : s) {
            charCount[c - 'a']++; // Increment the count for the corresponding character.
        }
        for (int i = 0; i < s.length(); i++) {
            if (charCount[s[i] - 'a'] == 1) { // Check if the count of the character is 1.
                return i;
            }
        }
        return -1;  // Return -1 if no unique character is found.
    }
};

//Time Complexity: O(n), where n is the length of the string.
//Space Complexity: O(1) since the size of the character count array is constant (26 lowercase letters).

/*----------------------------------------------------------------------------------------------------------------*/

// 4. Queue-Based Approach :

class Solution {
public:
    int firstUniqChar(string s) {
        queue<pair<char, int>> charQueue; // Create a queue to store characters and their positions.
        unordered_map<char, int> charCount; // Create a hash map to count character occurrences.

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            charCount[c]++; // Increment the count for the character.

            if (charCount[c] == 1) {
                charQueue.push({c, i}); 
                // Push the character and its position into the queue if it's the first occurrence.
            }

            // Remove characters from the queue as long as they are no longer unique.
            while (!charQueue.empty() && charCount[charQueue.front().first] > 1) {
                charQueue.pop();
            }
        }

        if (charQueue.empty()) {
            return -1; // If the queue is empty, no unique character exists.
        }

        return charQueue.front().second; // Return the index of the first unique character.
    }
};

//Time Complexity: O(n), where n is the length of the string.
//Space Complexity: O(k), where k is the number of distinct characters (for both the queue and the hash map).