/*#include <iostream>
using namespace std;

// Function to perform bubble sort on an array
void bubble_sort(int arr[], int n) {
    // Outer loop for the passes
    for (int i = n - 1; i >= 0; i--) {
        // Inner loop for the comparisons and swapping
        for (int j = 0; j <= i - 1; j++) {
            // If the current element is greater than the next element, swap them
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Main function where the program execution starts
int main() {
    // Declaring and taking input for the number of elements in the array
    int n;
    cin >> n;

    // Declaring an array of size n
    int arr[n];

    // Taking input for the elements of the array
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Calling the bubble_sort function to sort the array
    bubble_sort(arr, n);

    // Printing the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    // Indicating successful program execution
    return 0;
} 

*/

//Time complexity = Average and Worst case: O(n^2)
//Best Case: O(n)

/*--------------------------------------------------*/

// If array is partially sorted we can optimize the code like

#include <iostream>
using namespace std;

void bubble_sort(int arr[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        int didSwap = 0;
        for (int j = 0; j <= i - 1; j++) {
            if (arr[j] > arr[ j + 1]) {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                didSwap = 1;
            }
        }
        if (didSwap == 0) {
            break;
        }
        cout << "runs\n";
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    bubble_sort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}