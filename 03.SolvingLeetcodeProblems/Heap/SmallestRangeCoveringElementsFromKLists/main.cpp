//632. Smallest Range Covering Elements from K Lists

#include <queue>
#include <vector>
#include <climits> // for INT_MAX and INT_MIN
#include <algorithm> // for min and max

using namespace std;

class Node {
public:
    int data; // Value of the element
    int row; // Row index of the element in 'nums'
    int col; // Column index of the element in 'nums'

    Node(int data, int row, int col) {
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare {
public:
    bool operator()(Node* &a, Node* &b) {
        return a->data > b->data; // Comparison function for priority queue
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size(); // Number of arrays
        priority_queue<Node*, vector<Node*>, compare > minHeap; // Min-Heap to track the smallest element

        int end = INT_MIN; // Current end of the range
        vector<int> pointers(n, 0); // Track the current column index for each row

        // Initialization: Push the first element of each array into the heap
        for (int i = 0; i < n; i++) {
            int element = nums[i][0];
            minHeap.push(new Node(element, i, 0)); // Push the element into the heap
            end = max(end, element); // Update the end of the range
        }

        int start = minHeap.top()->data; // Current start of the range
        vector<int> ans = {start, end}; // Initial smallest range

        // Main loop to find the smallest range
        while (true) {
            Node* temp = minHeap.top(); // Get the smallest element from the heap
            minHeap.pop(); // Remove the smallest element from the heap

            int row = temp->row; // Row index of the smallest element
            int col = temp->col; // Column index of the smallest element

            // If the column index reaches the end of the array, exit the loop
            if (col + 1 == nums[row].size()) {
                break;
            }

            // Get the next element from the same row
            int nextElement = nums[row][col + 1];
            minHeap.push(new Node(nextElement, row, col + 1)); // Push the next element into the heap

            end = max(end, nextElement); // Update the end of the range
            start = minHeap.top()->data; // Update the start of the range

            // Update the smallest range if the current range is smaller
            if (end - start < ans[1] - ans[0] || (end - start == ans[1] - ans[0] && start < ans[0])) {
                ans = {start, end};
            }
        }

        return ans; // Return the smallest range
    }
};

/*
The time complexity of the provided code can be analyzed as follows:

Initialization: We push the first element of each array into the heap, which takes O(n log n) time, where 'n' is the number of arrays. This is because for each of the 'n' arrays, we perform a push operation onto the priority queue, which takes O(log n) time.

Main Loop: In each iteration of the main loop, we perform the following operations:

a. Pop the smallest element from the heap: This operation takes O(log n) time.
b. Push the next element from the same row into the heap: This operation also takes O(log n) time.
c. Update the start and end of the range: These operations take constant time.

Since we iterate through all the elements in the arrays once, the total time complexity of the main loop is O(N log n), where 'N' is the total number of elements across all arrays.

Therefore, the overall time complexity of the provided code is O(n log n + N log n), which simplifies to O(N log n) since 'N' can be larger than 'n' in most cases.

As for space complexity: The space complexity is dominated by the priority queue, which can contain at most one element from each of the 'n' arrays at any given time. Therefore, the space complexity is O(n), where 'n' is the number of arrays.
So, the correct time complexity is O(N log n) and the space complexity is O(n).