#include <iostream>
using namespace std;

// Hold

void printArray(int arr[], int size) {
    
    cout << "printing the array " << '\n';
    //print the array 
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << " printing done! " << '\n';

}

int main() {

    //declare 
    int number[15];

    //accessing an array
    cout << "Value at 14th index " << number[14] << '\n';

    cout << "Value at 20th index " << number[20] << '\n';

    //Initializing an array
    int second[3] = {5, 7, 11};

    //Accessing an element
    cout << "Value at 2nd index " << second[2] << '\n';

    int third[15] = {2,7};

    int n = 15;
    //printArray(third, 15);
    int thirdSize = sizeof(third)/sizeof(int);
    cout << "Size of Third is " << thirdSize << '\n';

    //Initializing all locations with 0
    int fourth[10] = {0};

    n = 10;
    //printArray(fourth, 10);

    //Initializing all locations(indexes) with 1 is not possible with below line
    int fifth[10] = {1};

    n = 10;
    //printArray(fifth, 10);

    int fifthSize = sizeof(fifth)/sizeof(int);
    cout << "Size of Fifth is " << fifthSize << '\n';

    char ch[5] = {'H', 'e', 'l', 'l', 'o'};
    cout << ch[3] << '\n';

    cout << "printing the array " << '\n';
    //print the array
    for(int i = 0; i < 5; i++) {
        cout << ch[i] << " ";
    }
    cout << "Printing done! " << '\n';
    
    double firstDouble[5];
    float firstFloat[6];
    bool firstBool[9];


    cout << '\n'<< "Everything is fine " << '\n' << '\n';

    return 0;
}