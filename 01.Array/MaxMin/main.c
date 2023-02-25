#include <stdio.h>
#include <limits.h>

int getMin(int num[], int n) {
    
    int mini = INT_MAX;

    for(int i = 0; i < n; i++) {

        mini = mini < num[i] ? mini : num[i];
    }
    return mini;
}

int getMax(int num[], int n) {

    int maxi = INT_MIN;

    for (int i = 0; i < n; i++) {

        maxi = maxi > num[i] ? maxi : num[i];
    }
    return maxi;
}

int main() {

    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int num[100];

    //Taking input in array
    printf("Enter %d integers: ", size);
    for(int i = 0; i < size; i++) {
        scanf("%d", &num[i]);
    }

    printf("Maximum value is %d\n", getMax(num, size));
    printf("Minimum value is %d\n", getMin(num, size));


    return 0;
}