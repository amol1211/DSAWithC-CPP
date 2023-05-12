#include <iostream>
using namespace std;

class Solution
{
    public:
    //Function to return list containing first n fibonacci numbers.
    vector<long long> printFibb(int n) 
    {   
        vector<long long> v;
        for (int i = 0; i < n; i++) {
            v.push_back(fibonacci(i));
        }
        return v;
    }
    
    //Function to calculate the nth Fibonacci number.
    long long fibonacci(int n) {
        if (n == 0) {
            return 0;
        }
        else if (n == 1) {
            return 1;
        }
        else {
            return fibonacci(n-1) + fibonacci(n-2);
        }
    }
};
