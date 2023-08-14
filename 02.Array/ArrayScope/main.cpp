#include <iostream>
using namespace std;

void update(int arr[], int n) {

    cout << "Inside the function" << '\n';

    //Updating array's first element
    arr[0] = 120;

    //printing the array
    for(int i = 0; i < 3; i++) {
        cout << arr[i] << " ";
    } cout << '\n';

    cout << "Going back to main function" << '\n';
}


int main() {
    int arr[3] = {1,2,3};

    update(arr, 3);

    //Printing the array
    cout << '\n' << "Printing in main function" << '\n';
    for(int i = 0; i < 3; i++) {
        cout << arr[i] << " ";
    }
    cout << '\n';

    return 0;
}