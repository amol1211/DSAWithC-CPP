//Selection Sort

#include <iostream>
using namespace std;

class Solution {
private:
    int n;

public:
    int select(int arr[], int i) {
        int mini = i;
        for (int j = i; j <= n - 1; j++) {
            if (arr[j] < arr[mini]) {
                mini = j;
            }
        }
        return mini;
    }

    void selectionSort(int arr[], int size) {
        n = size; // Assign the size to the member variable
        for (int i = 0; i <= n - 2; i++) {
            int minIndex = select(arr, i);
            swap(arr[i], arr[minIndex]);
        }
    }
};