#include <stdio.h>

void update(int arr[], int n) {

    printf("Inside the function\n");

    // Updating array's first element
    arr[0] = 120;

    // Printing the array
    for(int i = 0; i < 3; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Going back to main function\n");
}

int main() {
    int arr[3] = {1, 2, 3};

    update(arr, 3);

    // Printing the array
    printf("\nPrinting in main function\n");
    for(int i = 0; i < 3; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
