#include <iostream>
#include <climits>
using namespace std;

int getMin(int num[], int n) {

    int mini = INT_MAX;

    for(int i = 0; i < n; i++) {

        mini = min(mini, num[i]);

        //if(num[i] < min){
        //    min = num[i];
        //}
    }

    //returning min value
    return mini;
}

int getMax(int num[], int n) {

    int maxi = INT_MIN;

    // if(num[i] > max){
        //   max = num[i];
        // }

    for(int i = 0; i < n; i++) {

        maxi = max (maxi, num[i]);
    }

    //return max value
    return maxi;
}

int main() {

    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int num[100];

    //Taking input in array
    cout << "Enter " << size << " integers: ";
    for(int i = 0; i < size; i++) {
        cin >> num[i];
    }

    cout << " Maximum value is " << getMax(num, size) << '\n';
    cout << " Minimum value is " << getMin(num, size) << '\n';


    return 0;
}
