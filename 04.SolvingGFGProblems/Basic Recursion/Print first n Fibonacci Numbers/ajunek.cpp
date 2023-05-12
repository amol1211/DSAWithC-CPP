#include <iostream>
using namespace std;

class Solution {
    public:
    vector<long long> printFibb(int N) {
        vector<long long> fib(N);
        fib[0] = 1;
        fib[1] = 1;
        for (int i = 2; i < N; i++) {
            fib[i] = fib[i-1] + fib[i-2];
        }
        return fib;
    }
};