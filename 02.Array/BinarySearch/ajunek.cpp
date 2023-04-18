/*#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key) {
    int start = 0;
    int end = size - 1;
    int mid = start + (end-start)/2;

    while(start <= end) {
        if (arr[mid] == key) {
            
            return mid;
        }
        if (key > arr[mid]) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
        mid = start + (end-start)/2;
    }
    return -1;
}

int main() {
    
    int even [6] = {3, 6, 9, 12, 15, 18};
    int odd [5] = {9, 18, 27, 36, 45};

    int evenIndex = binarySearch(even, 6, 12);
    cout << "Index of 12 is: " << evenIndex << '\n';

    int oddIndex = binarySearch(odd, 5, 45);
    cout << "Index of 45 is: " << oddIndex << '\n';
    return 0;
}*/
/*
#include <iostream>
using namespace std;
int binarySearch(int arr[], int n, int key) {
    int start = 0;
    int end = n-1;
    int mid = start + (end-start)/2;
    while (start <= end) {
        if (arr[mid] == key) {
            return mid;
        }
        if (key > arr[mid]) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
        mid = start + (end-start)/2;
    }
    return -1;

}

int main() {
    int even [6] = {2,4,6,8,12,18};
    int odd [5] = {3, 8, 11, 14, 16}; 

    int evenIndex = binarySearch(even, 6, 8);
    cout << "Index of 8 is: " << evenIndex << '\n';

    int oddIndex = binarySearch(odd, 5, 14);
    cout << "Index of 14 is: " << oddIndex << '\n';
    return 0;
}*/

#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {

    int start = 0;
    int end = n-1;
    int mid = start + (end-start)/2;

    while(start <= end) {
        if (arr[mid] == key) {
            return mid;
        }
        if(key > arr[mid]) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
        mid = start + (end-start)/2;
    }
    return -1;
}

int main() {
    int even [6] = {3, 6, 9, 12, 15, 18};
    int odd [5] = {9, 18, 27, 36, 45};

    int evenIndex = binarySearch(even, 6, 15);
    cout << "Index of 15 is: " << evenIndex << '\n';

    int oddIndex = binarySearch(odd, 5, 36);
    cout << "Index of 36 is: " << oddIndex << '\n';
    return 0;
}

//Find Peak
int findPeak(int arr[], int n) {

    int start = 0; 
    int end = n-1;
    int mid = start + (end - start)/2;

    while(start < end) {
        //cout<<" start " << start <<" end " << end << '\n';
        if(arr[mid] < arr[mid+1]){
            start = mid+1; 
        }
        else{
            end = mid;
        }
        mid = start + (end-start)/2;
    }
    return start;
}
