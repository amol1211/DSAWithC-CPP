#include <iostream>
using namespace std;

void reverse(int arr[], int n) {

    int start = 0;
    int end = n-1;

    while (start<=end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void printArray(int arr[], int n) {

    for(int i=0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << '\n';

}

int main() {
    
    int arr[6] = {1,2,3,4,5,6};
    int amol[5] = {3,6,9,12,15};

    reverse(arr, 6);
    reverse(amol, 5);

    printArray(arr, 6);
    printArray(amol, 5);


    return 0;
}