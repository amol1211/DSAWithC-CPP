#include <iostream>
using namespace std;

class Solution {
public:
    vector<long long> printFibb(int N) {
        vector<long long> fib(N); // create a vector to store the Fibonacci numbers
        fib[0] = 1; // set the first two numbers to 1
        fib[1] = 1;
        for (int i = 2; i < N; i++) {
            fib[i] = fib[i-1] + fib[i-2]; // compute the i-th Fibonacci number
        }
        return fib; // return the vector of Fibonacci numbers
    }
};
