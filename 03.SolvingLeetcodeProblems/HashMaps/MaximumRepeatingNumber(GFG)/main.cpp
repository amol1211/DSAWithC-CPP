//Maximum repeating number (GFG)
#include <iostream> 
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Returns maximum repeating element in arr[0..n-1].
    // The array elements are in range from 0 to k-1
    int maxRepeating(int *arr, int n, int k) {
        // Create a hash map to store the frequency of each element
        unordered_map<int, int> mp;

        // Iterate through the array and count the frequency of each element
        for (int i = 0; i < n; i++) {
            mp[arr[i]]++;
        }

        int maxCount = 0, maxElement = 0;

        // Find the element with the maximum frequency
        for (int i = 0; i < k; i++) {
            // Check if the element is present in the hash map and has a higher frequency
            if (mp.find(i) != mp.end() && mp[i] > maxCount) {
                // Update maxCount and maxElement with the new frequency and element
                maxCount = mp[i];
                maxElement = i;
            }
        }
        // Return the element with the maximum frequency
        return maxElement;
    }
};

// Time Complexity: O(N + K)
//   - The first loop iterates through the array of size N.
//   - The second loop iterates through the possible values from 0 to K-1.
// Space Complexity: O(K)
//   - The hash map stores the frequency of each element, and in the worst case, it can have K distinct elements.
