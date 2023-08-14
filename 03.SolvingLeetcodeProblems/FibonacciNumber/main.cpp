//509. Fibonacci Number

// 1. Recursive approach
#include <iostream>
using namespace std;

class Solution {
public:
    int fib(int n) {
        // Base cases: fib(0) = 0 and fib(1) = 1
        if(n==0 || n==1)
            return n;
        // Recursive case: fib(n) = fib(n-1) + fib(n-2)
        int ans = fib(n-1)+fib(n-2);
        return ans;
    }
};

/*-------------------------------------------------------------*/

//2.Iterative approach using an array (dp)

class Solution {
public:
    int fib(int n) {
        // Initialize array to store Fibonacci sequence up to n
        int ans[n+2];
        ans[0]=0; // First number is 0
        ans[1]=1; // Second number is 1
        
        // Generate Fibonacci sequence up to n
        for(int i=2; i<=n; i++)
            ans[i]=ans[i-1]+ans[i-2];
        
        return ans[n]; // Return nth number in sequence
    }
};

/*---------------------------------------------------------------*/

//3.Closed-form formula approach

class Solution {
public:
    int fib(int n) {
        // Calculate square root of 5
        double sqrt5 = sqrt(5);
        // Use closed-form formula to calculate nth Fibonacci number
        return (pow(1 + sqrt5, n) - pow(1 - sqrt5, n)) / pow(2, n) / sqrt5;
    }
};


