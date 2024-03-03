//K-th Largest Sum Contiguous Subarray (GFG)

#include <bits/stdc++.h>
using namespace std;

//Brute force approach

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
// - O(N^2) for calculating all possible sums
// - O(N^2 log(N^2)) = O(N^2 log(N)) for sorting
// Space Complexity: O(N^2) - Required to store all possible sums

/*---------------------------------------------------------------------------------------------------*/

//Approach 2 : Using min-heap (priority queue)

class Solution{
public:
    // Function to find the Kth largest element in the sums of consecutive elements in the given array

    int kthLargest(vector<int> &Arr, int N, int K){
        // Priority queue to store the K smallest sums of consecutive elements encountered so far
        priority_queue<int, vector<int>, greater<int>> mini;
        
        // Iterate over the elements of the array
        for (int i = 0; i < N; i++) {
            int sum = 0;
            // Calculate the sums of consecutive elements starting from index 'i'
            for (int j = i; j < N; j++) {
                sum += Arr[j]; // Accumulate the sum
                // If the size of the priority queue is less than K, push the sum
                if (mini.size() < K) {
                    mini.push(sum);
                } else { // Otherwise, compare the current sum with the smallest sum in the queue
                    if (sum > mini.top()) { // If the current sum is larger, replace the smallest sum
                        mini.pop();
                        mini.push(sum);
                    }
                }
            }
        }
        
        // Return the top element of the priority queue, which is the Kth largest sum
        return mini.top();
    }
};

// Time Complexity: O(N^2 log(K)) - Where N is the size of the input array
// - O(N^2) for calculating all possible sums
// - O(N^2 log(K)) for maintaining the priority queue of size K
// Space Complexity: O(K) - Required to maintain the priority queue of size K
