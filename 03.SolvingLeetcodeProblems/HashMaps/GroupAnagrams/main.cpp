//49. Group Anagrams

#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_map>
using namespace std;
// This class provides a solution for grouping anagrams in a given vector of strings.

class Solution {
public:
    // Function to group anagrams in the input vector of strings.
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Using an unordered_map to store groups of anagrams based on sorted representations.
        unordered_map<string, vector<string>> mp;
        
        // Iterating through each string in the input vector.
        for(auto x: strs){
            // Creating a sorted representation of the current string.
            string word = x;
            sort(word.begin(), word.end());
            
            // Adding the original string to its corresponding anagram group.
            mp[word].push_back(x);
        }
        
        // Creating the final result vector to hold groups of anagrams.
        vector<vector<string>> ans;
        
        // Iterating through the map and adding anagram groups to the result vector.
        for(auto x: mp){
            ans.push_back(x.second);
        }
        
        // Returning the final result containing grouped anagrams.
        return ans;
    }
};

// Time Complexity: O(N * K * log(K)), where N is the number of strings in the input vector,
// and K is the maximum length of any string. Sorting each string takes O(K * log(K)) time.
// Space Complexity: O(N * K), where N is the number of strings in the input vector,
// and K is the maximum length of any string. The unordered_map stores the sorted representations
// of strings, and each vector contains the original strings.
