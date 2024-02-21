//Build Min Heap (Coding Ninja)

#include <bits/stdc++.h> 
using namespace std;

// Function to heapify a subtree rooted at index i in a min-heap
void heapify(vector<int> &arr, int n, int i) {
    // Initialize the index of the smallest element as the root
    int smallest = i;
    // Calculate the indices of the left and right children of the current node
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // If the left child is smaller than the root, update the index of the smallest element
    if (left < n && arr[smallest] > arr[left]) {
        smallest = left;
    }
    // If the right child is smaller than the root or left child, update the index of the smallest element
    if (right < n && arr[smallest] > arr[right]) {
        smallest = right;
    }

    // If the smallest element is not the root, swap it with the root and recursively heapify the affected subtree
    if(smallest != i) {
        swap(arr[smallest], arr[i]);
        heapify(arr, n, smallest);
    }
}

// Function to build a min-heap from an array
vector<int> buildMinHeap(vector<int> &arr) {
    // Get the size of the array
    int n = arr.size();
    // Start from the last non-leaf node and heapify all subtrees
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Return the min-heap array
    return arr;
}

// Time Complexity:
// - heapify: O(log n) - where n is the number of nodes in the heap
// - buildMinHeap: O(n) - building a heap from an array of size n requires heapifying each non-leaf node, which takes O(log n) time, and there are n/2 such nodes
// Overall, the time complexity is O(n log n)

// Space Complexity:
// - heapify: O(log n) - for the recursion stack, where n is the height of the heap
// - buildMinHeap: O(1) - the function operates in-place on the given array without using any additional space
// Overall, the space complexity is O(log n) due to the recursion stack space
