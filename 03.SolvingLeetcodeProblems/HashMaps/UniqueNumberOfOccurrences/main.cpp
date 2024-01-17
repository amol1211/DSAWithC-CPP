//1207. Unique Number of Occurrences

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Approach 1: Frequency Count with HashSet

class Solution {
public:
    // Function to check if the occurrences of elements in the array are unique
    bool uniqueOccurrences(vector<int>& arr) {
        // Map to store the frequency of each number in the array
        unordered_map<int, int> mp;

        // Storing frequency of each number
        for (int &x : arr) {
            mp[x]++;
        }

        // Set to store unique frequencies
        unordered_set<int> st;
        for (auto &it: mp) {
            int freq = it.second; // Frequency of the current number

            // If the frequency is already in the set, return false
            if (st.find(freq) != st.end()) {
                return false;
            }
            // Insert the frequency into the set
            st.insert(freq);
        }

        // All frequencies are unique, return true
        return true;
    }
};

/*Time Complexity: O(N), where N is the size of the input array.
Space Complexity: O(N), where N is the number of unique elements in the input array.*/

/*-----------------------------------------------------------------------------------------*/

//Approach 2: Counting and Sorting

class Solution {
public:
    // Function to check if the occurrences of elements in the array are unique
    bool uniqueOccurrences(vector<int>& arr) {
        // Vector to store the count of occurrences for each number (assuming numbers range from -1000 to 1000)
        vector<int> vec(2001, 0);

        // Counting occurrences of each number and adjusting index for negative values
        for (int &x : arr) {
            vec[x + 1000]++;
        }

        // Sorting the vector for easy comparison of adjacent occurrences
        sort(vec.begin(), vec.end());

        // Checking if adjacent occurrences are equal, if yes, return false
        for (int i = 1; i < 2001; i++) {
            if (vec[i] != 0 && vec[i] == vec[i - 1]) {
                return false;
            }
        }

        // All occurrences are unique, return true
        return true;
    }
};

/*Time Complexity: O(N log N), where N is the size of the input array due to the sorting step.
Space Complexity: O(1), since the vector size is constant (2001) and doesn't depend on the input size.*/