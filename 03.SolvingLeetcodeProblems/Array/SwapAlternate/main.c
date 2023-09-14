#include <stdio.h>

void printArray(int arr[], int n) {

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void swapAlternate(int arr[], int size) {
    
    for (int i = 0; i < size; i+=2) {
        if (i+1 < size) {
            swap(&arr[i], &arr[i+1]);
        }
    }
}


int main() {
    int even[6] = {1,2,3,4,5,6};
    int odd[5] = {12,24,36,48,60};

    swapAlternate(even, 6);
    printArray(even, 6);

    printf("\n");

    swapAlternate(odd, 5);
    printArray(odd, 5);


    return 0; 
}