#include <iostream>
#include <vector>
using namespace std;

// Function to merge two sorted subarrays: [low..mid] and [mid+1..high]
void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // Temporary vector to store the merged result

    int left = low; // Pointer for the left subarray
    int right = mid + 1; // Pointer for the right subarray

    // Merge elements from both subarrays in ascending order
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]); // Append the smaller element to temp
            left++;
        } else {
            temp.push_back(arr[right]); // Append the smaller element to temp
            right++;
        }
    }

    // Append remaining elements from the left subarray (if any)
    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    // Append remaining elements from the right subarray (if any)
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy elements from the temporary vector back to the original array
    //i - low is used as an offset to access the elements in the temporary vector temp. 
    //Since temp contains the merged elements, the indices in temp start from 0.
    //By subtracting low from i, we get the relative position of the current index i in 
    //the original subarray [low..mid] with respect to the starting index of the subarray. 
    //This allows us to access the correct element from the temp vector.
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

// Recursive function to perform Merge Sort on the array
void mS(vector<int> &arr, int low, int high) {
    // Base case: If the subarray has only one element, it is already sorted
    if (low == high) return;

    int mid = (low + high) / 2; // Calculate the middle index

    // Recursively sort the left and right halves of the array
    mS(arr, low, mid);
    mS(arr, mid + 1, high);

    // Merge the sorted subarrays to get the final sorted array
    merge(arr, low, mid, high);
}

// Function to perform Merge Sort on the entire array
void mergeSort(vector<int> &arr, int n) {
    mS(arr, 0, n - 1); // Call the recursive Merge Sort function with low=0 and high=n-1
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();

    cout << "Original Array: ";
    for (int num : arr) {
        cout << num << " "; // Print the elements of the original array
    }
    cout << endl;

    mergeSort(arr, n); // Sort the array using Merge Sort

    cout << "Sorted Array: ";
    for (int num : arr) {
        cout << num << " "; // Print the sorted elements
    }
    cout << endl;

    return 0;
}

//Time complexity of the Merge Sort algorithm is O(n log n)
//Space complexity of Merge Sort is O(n)