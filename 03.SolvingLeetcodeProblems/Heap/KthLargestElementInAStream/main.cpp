//703. Kth Largest Element in a Stream

#include <bits/stdc++.h>
using namespace std;

//Approach 1 : Brute force approach(TLE)

class KthLargest {
public:
    int K;
    vector<int> nums; // Vector to store all elements
    
    // Constructor to initialize K and the vector with elements
    KthLargest(int k, vector<int>& nums) {
        K = k; // Assign k to K
        this->nums = nums; // Store the input elements in the vector
    }
    
    // Function to add a new element and return the kth largest element
    int add(int val) {
        nums.push_back(val); // Add the new element to the vector
        sort(nums.begin(), nums.end(), greater<int>()); // Sort the vector in descending order
        
        return nums[K - 1]; // Return the kth largest element from the sorted vector
    }
};

/*Time Complexity:

Construction of the KthLargest object:

No significant operation is performed during construction, so it takes O(1) time.
Adding a new element:

Adding the new element to the vector takes O(1) time.
Sorting the vector takes O(n log n) time, where n is the size of the vector.
Accessing the kth largest element takes O(1) time.
So, the time complexity for adding a new element is O(n log n).
Space Complexity:

The space complexity is O(n) to store all elements in the vector.*/

/*------------------------------------------------------------------------------------------------------*/

// Approach 2 : MinHeap appraoch
class KthLargest {
public:
    int K; // Variable to store the value of k
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min heap to store the k largest elements
    
    // Constructor to initialize K and populate the min heap with initial elements
    KthLargest(int k, vector<int>& nums) {
        K = k; // Assign k to K
        // Iterate through the input vector nums
        for (auto &num : nums) {
            minHeap.push(num); // Push each element to the min heap
            if (minHeap.size() > k) // If the size of the min heap exceeds k
                minHeap.pop(); // Pop the smallest element from the heap
        }
    }
    
    // Function to add a new element and return the kth largest element
    int add(int val) {
        minHeap.push(val); // Add the new element to the min heap
        if (minHeap.size() > K) // If the size of the min heap exceeds k
            minHeap.pop(); // Pop the smallest element from the heap

        return minHeap.top(); // Return the top element of the min heap which is the kth largest element
    }
};

/*Time Complexity:

Construction of the KthLargest object:

Adding each element to the min heap takes O(log n) time, where n is the size of the heap.
We are adding elements one by one for a total of n elements, so the total time complexity is O(n log n).
Adding a new element:

Pushing a new element to the min heap takes O(log k) time, where k is the size of the heap.
If the heap size exceeds k, popping the smallest element takes O(log k) time.
So, the time complexity for adding a new element is O(log k).

Space Complexity:

The space complexity is O(k) to store the k largest elements in the min heap.*/