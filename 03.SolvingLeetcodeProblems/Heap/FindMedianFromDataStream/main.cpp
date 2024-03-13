//295. Find Median from Data Stream

#include <bits/stdc++.h>
using namespace std;

// Class definition for finding the median of a stream of numbers
class MedianFinder {
public:
    // Max heap to store the smaller half of the numbers
    priority_queue<int> left_max_heap;
    // Min heap to store the larger half of the numbers
    priority_queue<int, vector<int>, greater<int>> right_min_heap;

    // Constructor
    MedianFinder() {
    }
    
    // Function to add a number to the stream
    void addNum(int num) {
        // If the number is smaller than the current median, add it to the left max heap
        if (left_max_heap.empty() || num < left_max_heap.top()) {
            left_max_heap.push(num);
        } 
        // Otherwise, add it to the right min heap
        else {
            right_min_heap.push(num);
        }

        // We need to ensure that the size difference between the two heaps is at most one
        if (abs((int)left_max_heap.size() - (int)right_min_heap.size()) > 1) {
            // If the left heap is larger, move its top element to the right heap
            if (left_max_heap.size() > right_min_heap.size()) {
                right_min_heap.push(left_max_heap.top());
                left_max_heap.pop();
            }
            // If the right heap is larger, move its top element to the left heap
            else {
                left_max_heap.push(right_min_heap.top());
                right_min_heap.pop();
            }
        }
    }
    
    // Function to find the median of the current stream
    double findMedian() {
        // If the number of elements is even, return the mean of the two middle elements
        if (left_max_heap.size() == right_min_heap.size()) {
            return (double) (left_max_heap.top() + right_min_heap.top()) / 2;
        }
        // Otherwise, return the middle element
        else 
            return left_max_heap.top();        
    }
};

/*Time Complexity:

Adding a number takes O(log n) time in the worst case, where 'n' is the number of elements in the stream.
Finding the median takes O(1) time.
Space Complexity:

The space complexity is O(n), where 'n' is the number of elements in the stream, as we store all the elements in 
two priority queues.*/