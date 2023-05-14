#include <iostream>
using namespace std;

class Solution {
    public:
    void frequencyCount(vector<int>& arr, int N, int P) {
    // iterate through the array and update its values
    for (int i = 0; i < N; i++) {
        // Calculate the index of the current element
        int index = arr[i] - 1;

        // We add P to the value at index (arr[i] - 1) % P to keep track of 
        // how many times the number has occurred in the array.
        // The modulo operator is used to ensure that the index is within the range [0, P-1].
        arr[index % N] += N;
    }

    // iterate through the array again and compute the frequency count
    for (int i = 0; i < N; i++) {
        // Divide each value by N to obtain the frequency count of each element.
        arr[i] /= N;
    }
}

};

/*------------------------------------------------------------------------------------*/

class Solution{
    public:
    void frequencyCount(vector<int>& arr,int N, int P)
    { 
        // Step 1: Initialize the frequency array
        vector<int> freq(N, 0);
        
        // Step 2: Update the frequency array
        for(int i = 0; i < arr.size(); i++){
            freq[arr[i] - 1]++;
        }
        
        // Step 3: Copy the values from the frequency array to the input array
        for(int i = 0; i < N; i++){
            arr[i] = freq[i];
        }
    }
};
