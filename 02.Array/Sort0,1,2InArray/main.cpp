// Dutch National Flag Algorithm to sort the array in linear time.
#include <bits/stdc++.h> // non-standard header, includes all standard headers
void sort012(int *arr, int n) { // function to sort array of 0's, 1's, and 2's in ascending order
    int low = 0; // pointer to the beginning of the array
    int mid = 0; // pointer to the current element being processed
    int high = 0; // pointer to the end of the array

    // count the occurrences of 0's, 1's, and 2's in the array
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            low++;
        } else if (arr[i] == 1) {
            mid++;
        } else {
            high++;
        }
    }

    // set the elements of the array in sorted order
    for (int j = 0; j < n; j++) {
        if (j < low) {
            arr[j] = 0;
        } else if (j < low + mid) {
            arr[j] = 1;
        } else {
            arr[j] = 2;
        }
    }
}

// Time complexity: O(n) (two loops that iterate over the array once)
// Space complexity: O(1) (only three pointers are used to keep track of indices)

/*-------------------------------------------------------------------------------------*/
// Same algorithm with three pointers - low, mid, and high but with SINGLE SCAN

#include <bits/stdc++.h>
void sort012(int *arr, int n) {
    int low = 0; // pointer to the beginning of the array
    int mid = 0; // pointer to the current element being processed
    int high = n - 1; // pointer to the end of the array

    while (mid <= high) { // traverse the array using the mid pointer
        if (arr[mid] == 0) { // if the current element is 0, swap it with the element at the low pointer
            std::swap(arr[low], arr[mid]);
            low++;
            mid++;
        } else if (arr[mid] == 1) { // if the current element is 1, simply increment the mid pointer
            mid++;
        } else { // if the current element is 2, swap it with the element at the high pointer
            std::swap(arr[mid], arr[high]);
            high--;// after swapping the current element with the element at the high pointer,
            // we decrement the high pointer to move it one position to the left
            // since the current element at mid might still need to be swapped again.
        }
        }
    }

// Time complexity: O(n) (single loop that iterates over the array once)
// Space complexity: O(1) (only three pointers are used to keep track of indices)
