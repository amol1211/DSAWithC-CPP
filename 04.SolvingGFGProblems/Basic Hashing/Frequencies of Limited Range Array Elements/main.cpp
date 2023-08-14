#include <iostream>
using namespace std;

// Using unordered_map

class Solution{
    public:
    //Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& arr,int N, int P)
    { 
        unordered_map<int, int> freq;
    
    // iterate over the input array and update frequency count
    for(int i=0;i<N;i++){
        freq[arr[i]]++;
    }
    
    // iterate through the frequency table and update the input array
    for(int i=1;i<=N;i++){
        arr[i-1] = freq[i];
    }
    }
};

//Time complexity : O(N)
//Space complexity : O(N)

/*-------------------------------------------------------------------------------------*/

//2. Using the counting sort algorithm to count the frequency of elements
class Solution {
public:
    // Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& arr, int N, int P) {
        // Create a frequency array of size N with all elements initialized to 0.
        vector<int> freq(N, 0);

        // Iterate over the input array and update frequency count for valid elements.
        for(int i = 0; i < arr.size(); i++) {
            // If the element is greater than N or less than 1, skip it.
            if(arr[i] > N || arr[i] < 1) continue;
            // Increment the count for this element in the frequency array.
            freq[arr[i] - 1]++;
        }

        // Update the input array with the frequency counts.
        for (int i = 0; i < N; i++) {
            arr[i] = freq[i];
        }
    }
};

//Time complexity : O(n + N
//Space complexity : O(N)
