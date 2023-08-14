#include <iostream>
using namespace std;

class Solution {
    public:
    void frequencyCount(vector<int>& arr, int N, int P) {

        unordered_map<int, int> freq;

        for(int i=0; i < N; i++) {
            freq[arr[i]]++;
        }

        for(int i = 1; i <= N; i++) {
            arr[i - 1] = freq[i];
        }
    }
};

/*--------------------OR----------------------------------*/

class Solution {
    public:
    void frequencyCount(vector<int>& arr, int N, int P) {
        vector<int> freq(N, 0);

        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] > N || arr[i] < 1) continue;
            freq[arr[i] - 1]++;
        }

        for(int i = 0; i < N; i++) {
            arr[i] = freq[i];
        }
    }
};