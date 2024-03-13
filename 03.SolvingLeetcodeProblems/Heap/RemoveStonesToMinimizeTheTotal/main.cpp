//1962. Remove Stones to Minimize the Total

#include <bits/stdc++.h>
using namespace std;
//TLE
// Approach 1: Using sorting and manipulation of the vector directly

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        sort(piles.begin(), piles.end()); // Sort the vector
        int n = piles.size();
        
        // Perform k operations
        while (k > 0) {
            int element = piles.back(); // Get the last element
            piles.pop_back(); // Remove the last element

            int newElement = element - element/2; // Calculate the new element after halving
            piles.push_back(newElement); // Push the new element to the vector

            k--; // Decrement k

            sort(piles.begin(), piles.end()); // Re-sort the vector after manipulation
        }

        // Calculate the sum of elements in the vector
        int result = 0;
        for (auto it : piles) {
            result += it;
        }

        return result; // Return the sum
    }
};

/*// Time Complexity: O(k * log n), where n is the size of the piles vector
// Space Complexity: O(1)*/

/*------------------------------------------------------------------*/

// Approach 2: Using a priority queue (max heap)

#include <queue>

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;

        // Fill the priority queue with elements from the vector
        for (auto it : piles) {
            pq.push(it);
        }

        // Perform k operations
        while (k > 0) {
            int element = pq.top(); // Get the largest element from the top
            pq.pop(); // Remove the largest element

            int newElement = element - element/ 2; // Calculate the new element after halving
            pq.push(newElement); // Push the new element to the priority queue

            k--; // Decrement k
        } 

        // Calculate the sum of elements in the priority queue
        int result = 0;
        while (!pq.empty()) {
            result += pq.top();
            pq.pop();
        }

        return result; // Return the sum
    }
};

/*// Time Complexity: O(n + k * log n), where n is the size of the piles vector
//                   and k is the number of operations
// Space Complexity: O(n)*/

/*Filling the priority queue initially with n elements takes O(n) time.
Performing k operations on the priority queue involves k insertions and k deletions, 
each taking O(log n) time, resulting in O(k * log n) time.
Finally, summing up the elements of the priority queue takes O(n) time as well.
Therefore, the total time complexity is O(n + k * log n). */