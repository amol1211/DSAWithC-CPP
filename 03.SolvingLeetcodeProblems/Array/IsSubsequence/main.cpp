//392. Is Subsequence
#include <iostream>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0; // pointer for s
        int j = 0; // pointer for t
        
        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j]) {
                i++; // move pointer in s
            }
            j++; // always move pointer in t
        }
        
        return i == s.length(); // check if all characters in s were found in t
    }
};
