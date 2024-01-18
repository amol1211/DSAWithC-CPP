//3005. Count Elements With Maximum Frequency

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Define a class named Solution
class Solution {
public:
    // Function to find the total frequency of elements with the maximum frequency
    int maxFrequencyElements(vector<int>& nums) {
        // Create an unordered map to store the frequency of each element
        unordered_map<int, int> mp;
        // Initialize a variable to track the maximum frequency encountered
        int maxFrequency = 0;

        // Loop through each element in the input vector
        for (auto i : nums) {
            // Increment the frequency of the current element in the map
            mp[i]++;
            // Update the maximum frequency if the current element's frequency is higher
            maxFrequency = max(maxFrequency, mp[i]);
        }

        // Initialize a variable to store the total frequency of elements with maximum frequency
        int totalMaxFrequency = 0;

        // Iterate through the elements in the map
        for (const auto z : mp) {
            // Check if the frequency of the current element is equal to the maximum frequency
            if (z.second == maxFrequency) {
                // Increment the total frequency of elements with maximum frequency
                totalMaxFrequency += z.second;
            }
        }

        // Return the total frequency of elements with maximum frequency
        return totalMaxFrequency;
    }
};

//Time complexity is O(n)
//Space complexity is O(n)
 