#include <stdio.h>

// Hold

void printArray(int arr[], int size) {
    
    printf("printing the array\n");
    //print the array 
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("printing done!\n");

}

int main() {

    //declare 
    int number[15];

    //accessing an array
    printf("Value at 14th index: %d\n", number[14]);
    printf("Value at 20th index: %d\n", number[20]);

    //Initializing an array
    int second[3] = {5, 7, 11};

    //Accessing an element
    printf("Value at 2nd index: %d\n", second[2]);

    int third[15] = {2, 7};

    int n = 15;
    //printArray(third, 15);
    int thirdSize = sizeof(third)/sizeof(int);
    printf("Size of Third is %d\n", thirdSize);

    //Initializing all locations with 0
    int fourth[10] = {0};

    n = 10;
    //printArray(fourth, 10);

    //Initializing all locations(indexes) with 1 is not possible with below line
    int fifth[10] = {1};

    n = 10;
    //printArray(fifth, 10);

    int fifthSize = sizeof(fifth)/sizeof(int);
    printf("Size of Fifth is %d\n", fifthSize);

    char ch[5] = {'H', 'e', 'l', 'l', 'o'};
    printf("%c\n", ch[3]);

    printf("printing the array\n");
    //print the array
    for(int i = 0; i < 5; i++) {
        printf("%c ", ch[i]);
    }
    printf("Printing done!\n");
    
    double firstDouble[5];
    float firstFloat[6];
    int firstBool[9];

    printf("\nEverything is fine\n\n");

    return 0;
}
