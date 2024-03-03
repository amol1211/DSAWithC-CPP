//K-th Largest Sum Contiguous Subarray (GFG)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the Kth largest element in the sums of consecutive elements in the given array

    int kthLargest(vector<int> &Arr, int N, int K) {
        // Vector to store all possible sums
        vector<int> sumStore;

        // Calculate all possible sums of consecutive elements
        for (int i = 0; i < N; i++) {
            int sum = 0;
            // Iterate over elements starting from index 'i'
            for (int j = i; j < N; j++) { 
                sum += Arr[j]; // Accumulate the sum
                sumStore.push_back(sum); // Store the sum
            }
        }

        // Sort the sums vector in ascending order
        sort(sumStore.begin(), sumStore.end());

        // Return the Kth largest element
        return sumStore[sumStore.size() - K]; // Get the Kth largest element from the sorted sums
    }
};

    // Time Complexity: O(N^2 log(N)) - Where N is the size of the input array
    //                                    - O(N^2) for calculating all possible sums
    //                                    - O(N^2 log(N^2)) = O(N^2 log(N)) for sorting
    // Space Complexity: O(N^2) - Required to store all possible sums
