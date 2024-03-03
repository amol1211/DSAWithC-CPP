#include <bits/stdc++.h>
using namespace std;

// 1. Sorting approach:
// - Sorts the array from index l to r using the std::sort algorithm.
// - After sorting, the kth smallest element is accessed directly from the sorted array.
// - Returns the kth smallest element.

class Solution{
public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        // Sorting the array
        sort(arr + l, arr + r + 1);
        // Returning the kth smallest element
        return arr[l + k - 1];
    }
};

// Time complexity: O(n log n), where n is the number of elements in the range (r - l + 1).
//                  Sorting the array takes O(n log n) time.
// Space complexity: O(1), as it sorts the array in-place without any additional memory usage.

/*-----------------------------------------------------------------------------------*/

//Approach 2: Priority Queue (Max-Heap)

// - Uses a priority queue to find the kth smallest element.
// - Inserts the first k elements into the priority queue.
// - Iterates from index k to r, pushing elements into the priority queue if they are smaller than the maximum element in the queue.
// - Returns the top element of the priority queue, which is the kth smallest element.


#include <queue>

class Solution{
public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        // Priority queue to store the k smallest elements
        priority_queue<int> pq;
        // Inserting the first k elements into the priority queue
        for (int i = l; i < l + k; i++) {
            pq.push(arr[i]);
        }
        // Iterating over the remaining elements and maintaining the priority queue
        for (int j = l + k; j <= r; j++) {
            if (arr[j] < pq.top()) {
                pq.pop();
                pq.push(arr[j]);
            }
        }
        // Returning the top element of the priority queue
        return pq.top();
    }
};

// Time complexity: O((r - l + 1) * log k), where n is the number of elements in the range (r - l + 1).
// Building the priority queue takes O(k log k) time for the first k elements,
// and for the subsequent (r - l + 1 - k) elements, each insertion into the priority queue takes O(log k) time.
// Space complexity: O(k), as the priority queue holds at most k elements.

/* ----------------------------------------------------------------------------------------------------------------- */