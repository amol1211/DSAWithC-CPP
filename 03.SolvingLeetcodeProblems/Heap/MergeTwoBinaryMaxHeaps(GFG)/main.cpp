//Merge two binary Max heaps (GFG)

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; // Definition of the Node structure

class Solution {
private:
    // Function to heapify a subtree rooted at index i in vector arr of size n
    void heapify(vector<int> &arr, int n, int i) {
        int largest = i;  // Initialize largest as root
        int left = 2 * i + 1;  // left child index
        int right = 2 * i + 2;  // right child index

        // If left child is larger than root
        if (left < n && arr[largest] < arr[left]) {
            largest = left;
        }

        // If right child is larger than largest so far
        if (right < n && arr[largest] < arr[right]) {
            largest = right;
        }

        // If largest is not root
        if (largest != i) {
            swap(arr[largest], arr[i]);  // swap the largest child with root
            heapify(arr, n, largest);  // recursively heapify the affected subtree
        }
    }

public:
    // Function to merge two heaps represented by vectors a and b of sizes n and m respectively
    // Time Complexity: O((n + m) * log(n + m)) due to heapify calls
    // Space Complexity: O(n + m) for the merged heap
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {

        vector<int> ans;  // Initialize a vector to store the merged heap

        // Copy elements of vector a to ans
        for (auto i : a) {
            ans.push_back(i);
        }

        // Copy elements of vector b to ans
        for (auto i : b) {
            ans.push_back(i);
        }

        int mergedSize = n + m;  // Calculate the total size of merged heap

        // Heapify the merged heap starting from the last non-leaf node up to the root
        for (int i = mergedSize / 2 - 1; i >= 0; i--) {
            heapify(ans, mergedSize, i);  // Call heapify for each non-leaf node
        }

        return ans;  // Return the merged heap
    }
};

// Time Complexity: O((n + m) * log(n + m)) due to heapify calls
// Space Complexity: O(n + m) for the merged heap