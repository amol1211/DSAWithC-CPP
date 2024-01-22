#include <iostream>
#include <vector>
#include <iostream>
using namespace std;

//Approach 1 : Word Pattern Matching with Containers approach

// This class provides a solution for determining if a given pattern matches a string.
class Solution {
public:
    // Function to check if the given word pattern matches the string.
    bool wordPattern(string pattern, string s) {
        // Vector to store individual words extracted from the string.
        vector<string> words;

        // Create a stringstream to process the input string.
        stringstream ss(s);

        // Temporary variable to store each word during extraction.
        string token;

        // Variable to count the number of words in the string.
        int countWords = 0;

        // Extract words from the string and store them in the vector.
        while (getline(ss, token, ' ')) {
            words.push_back(token);
            countWords++;
        }

        // Get the length of the input pattern.
        int n = pattern.length();

        // If the number of words extracted doesn't match the pattern length, return false.
        if (n != countWords) return false;

        // Map to associate each unique word with a character from the pattern.
        unordered_map<string, char> mp;

        // Set to keep track of characters from the pattern that have been used.
        set<char> used;

        // Check if the current word-pattern pairing is consistent.
        for (int i = 0; i < n; i++) {
            string word = words[i];
            char ch = pattern[i];

            // If the word is not in the map and the pattern character is not used, add them.
            if (mp.find(word) == mp.end() && used.find(ch) == used.end()) {
                used.insert(ch);
                mp[word] = ch;
            }
            // If the word is already in the map but does not match the pattern character, return false.
            else if (mp[word] != pattern[i]) {
                return false;
            }
        }

        // If all checks pass, the pattern matches the string.
        return true;
    }
};


/*Time Complexity: O(N), where N is the length of the input pattern or the number of words in the string.

Space Complexity: O(M), where M is the number of unique words in the string. In the worst case, it could 
be O(N) if all words are unique.*/

/*-------------------------------------------------------------------------------------------------------*/

//Approach 2 : Word Pattern Matching with Indexing approach.

// This class provides a solution for determining if a given pattern matches a string,
// ensuring that each character in the pattern corresponds to the same index as the word in the string.
class Solution {
public:
    // Function to check if the given word pattern matches the string.
    bool wordPattern(string pattern, string s) {
        // Map to store the index of each character in the pattern.
        unordered_map<char, int> charToIndex;

        // Map to store the index of each word in the string.
        unordered_map<string, int> wordToIndex;

        // Create a stringstream to process the input string.
        stringstream ss(s);

        // Temporary variable to store each word during extraction.
        string token;

        // Variable to count the number of tokens (words) in the string.
        int countTokens = 0;

        // Variable to iterate over the characters in the pattern.
        int i = 0;

        // Get the length of the input pattern.
        int n = pattern.size();

        // Extract words from the string and perform pattern matching.
        while (ss >> token) {
            countTokens++;

            // Check if the current character in the pattern has a corresponding index for the current word.
            if (i == n || charToIndex[pattern[i]] != wordToIndex[token]) 
                return false;

            // Update the index for the current character and word.
            charToIndex[pattern[i]] = i + 1;
            wordToIndex[token] = i + 1;

            // Move to the next character in the pattern.
            i++;
        }

        // Check if the number of tokens and characters in the pattern match.
        if (countTokens != n || i != n) 
            return false;

        // If all checks pass, the pattern matches the string.
        return true;
    } 
};


/*Time Complexity: O(N), where N is the length of the input pattern or the number of words in the string.

Space Complexity: O(M), where M is the number of unique characters in the pattern or the number of unique 
words in the string. In the worst case, it could be O(N) if all characters or words are unique.*/
