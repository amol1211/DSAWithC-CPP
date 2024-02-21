//Heap Sort (GFG)

#include <iostream>
using namespace std;

//This is the the 0-based indexing based solution 
class Solution {
public:
    // Heapify function to maintain the heap property.
    // This function compares the root element with its left and right children
    // and swaps the root with the largest child if necessary to maintain the heap property.
    // Time Complexity: O(log n), where n is the number of elements in the heap.
    //                This is because in the worst-case scenario, the element being
    //                moved down the heap may need to traverse the height of the heap.
    // Space Complexity: O(1). This function does not use any extra space.
    void heapify(int arr[], int n, int i) {
        int largest = i;
        int left = 2 * i + 1;  // Calculate the index of the left child.
        int right = 2 * i + 2; // Calculate the index of the right child.

        // Compare the root with its left child.
        if (left < n && arr[largest] < arr[left]) {
            largest = left;
        }

        // Compare the root (or largest) with its right child.
        if (right < n && arr[largest] < arr[right]) {
            largest = right;
        }

        // If the largest element is not the root, swap them and
        // recursively call heapify on the affected subtree.
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

public:
    // Function to build a max heap from an array.
    // This function starts from the last non-leaf node and
    // calls heapify on each node to build the heap.
    // Time Complexity: O(n), where n is the number of elements in the array.
    // Space Complexity: O(1). This function does not use any extra space.
    void buildHeap(int arr[], int n) {
        // Start from the last non-leaf node and move up to the root.
        // Call heapify on each node to maintain the heap property.
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }
    }

public:
    // Function to perform heap sort on an array.
    // This function first builds a max heap from the array,
    // then repeatedly extracts the maximum element from the heap
    // and places it at the end of the array, adjusting the heap each time.
    // Time Complexity: O(n log n), where n is the number of elements in the array.
    //                  Building the heap takes O(n) time, and heapifying each element
    //                  during extraction takes O(log n) time. Since each element is
    //                  extracted and placed in its correct position, the total time
    //                  complexity is O(n log n).
    // Space Complexity: O(1). This function does not use any extra space.
    void heapSort(int arr[], int n) {
        // Build a max heap from the array.
        buildHeap(arr, n);

        // Extract the maximum element from the heap and place it at the end of the array.
        // Adjust the heap after each extraction to maintain the heap property.
        for (int i = n - 1; i >= 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
};

/*-------------------------------------------------------------------------------*/

//We can solve this as 1-based indexing based as well

// The functions should be written in a way that array become sorted 
// in increasing order when heapSort() is called.

class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
      int largest = i;
      int left = 2 * i ;
      int right = 2 * i + 1;
      
      if (left < n && arr[largest] < arr[left]) {
          largest = left;
      }
      
      if (right < n && arr[largest] < arr[right]) {
          largest = right;
      }
      
      if (largest != i) {
          swap(arr[i], arr[largest]);
          heapify(arr, n, largest);
      }
      
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
       for (int i = n/2; i >= 0; i--) {
           heapify(arr, n, i);
       }
    }

    
    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        buildHeap(arr, n);
        for (int i = n - 1; i >= 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
};



