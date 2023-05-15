//Heap and Hashing approach" to find the top k elements with the 
//highest frequency in a vector of integers.

#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> topK(vector<int>& nums, int k) {
        // Create an unordered map to store the frequency of each element in nums.
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        
        // Create a max heap to store the pairs (frequency, element).
        // The max heap will order the pairs by their frequency in descending order.
        priority_queue<pair<int, int>> max_heap;
        for (auto it : freq) {
            max_heap.push(make_pair(it.second, it.first));
        }
        
        // Extract the k most frequent elements from the max heap and add them to the result vector.
        vector<int> result;
        while (k > 0 && !max_heap.empty()) {
            // Extract the top element from the max heap.
            int element = max_heap.top().second;
            // Add the element to the result vector.
            result.push_back(element);
            // Decrease k to count the number of elements extracted so far.
            k--;
            // Remove the top element from the max heap.
            max_heap.pop();
        }
        
        // Return the result vector.
        return result;
    }
};


//Here's a brief summary of the steps performed by this implementation:

//1. Create a frequency map using an unordered map to count the frequency 
//of each element in the input vector.
//2. Create a max heap of pairs, where the first element of each pair is 
//the frequency of the element and the second element is the element 
//itself, and initialize it with the pairs in the frequency map.
//3. Extract the top k elements from the max heap and add them to the result vector.
//4. Return the result vector.





//The time complexity of this implementation is O(N log N), 
//where N is the size of the input vector, due to the use of 
//a max heap. The space complexity is O(N) for the frequency 
//map and the max heap.
