//1046. Last Stone Weight

#include <bits/stdc++.h>
using namespace std;

//Approach 1: Using Sorting

class Solution {
public:
    // Function to find the weight of the last stone after all collisions
    // Time Complexity: O(n^2 log n) where n is the number of stones
    // Space Complexity: O(1) since the sorting is done in-place
    int lastStoneWeight(vector<int>& stones) {
        // Sort the stones in ascending order
        sort(stones.begin(), stones.end());
        
        // Repeat until there is only one stone left
        while (stones.size() > 1) {
            // Get the two heaviest stones
            int x = stones.back(); // Get the last stone
            stones.pop_back(); // Remove the last stone
            int y = stones.back(); // Get the second last stone
            stones.pop_back(); // Remove the second last stone

            // If the two stones are not equal, calculate the new stone weight and insert it
            if (x != y) {
                stones.push_back(x - y); // Calculate the new stone weight and insert it
                sort(stones.begin(), stones.end()); // Re-sort the stones after inserting the new stone
            }
        }

        // If stones array is empty, return 0, otherwise return the weight of the last stone
        if (stones.empty())
            return 0;
        else
            return stones.back(); // Return the weight of the last stone
    }
};

/*----------------------------------------------------------------------------------------------------------------*/

//Approch 2 : Using max heap

class Solution {
public:
    // Function to find the weight of the last stone after all collisions
    // Time Complexity: O(n log n) where n is the number of stones
    // Space Complexity: O(n) since priority queue is used
    int lastStoneWeight(vector<int>& stones) {
        // Create a max heap to store the stones
        priority_queue<int> maxHeap;

        // Insert all stones into the max heap
        for (auto it : stones) {
            maxHeap.push(it);
        }

        // Repeat until there is only one stone left in the heap
        while (maxHeap.size() > 1) {
            // Get the two heaviest stones from the max heap
            int x = maxHeap.top(); // Get the heaviest stone
            maxHeap.pop(); // Remove the heaviest stone
            int y = maxHeap.top(); // Get the second heaviest stone
            maxHeap.pop(); // Remove the second heaviest stone

            // If the two stones are not equal, calculate the new stone weight and insert it into the max heap
            if (x != y) {
                maxHeap.push(x - y); // Calculate the new stone weight and insert it into the max heap
            }
        }

        // If max heap is empty, return 0, otherwise return the weight of the last stone
        if (maxHeap.empty())
            return 0;
        else
            return maxHeap.top(); // Return the weight of the last stone
    }
};


