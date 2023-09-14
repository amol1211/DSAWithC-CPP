//242. Valid Anagram

#include <iostream>  
using namespace std;  

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;  // If the lengths of strings s and t are different, they can't be anagrams
        }
        
        vector<int> freq(26, 0);  // Create a vector to store the frequency of each character in the alphabet
        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;  // Increment the count for character s[i] in the frequency vector
            freq[t[i] - 'a']--;  // Decrement the count for character t[i] in the frequency vector
        }
        
        for (int i = 0; i < freq.size(); i++) {
            if (freq[i] != 0) {
                return false;  // If any count in the frequency vector is non-zero, the strings are not anagrams
            }
        }
        
        return true;  // If all counts in the frequency vector are zero, the strings are anagrams
    }
};
