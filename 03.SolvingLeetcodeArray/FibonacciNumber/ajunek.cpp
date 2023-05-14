#include <iostream>
using namespace std;

class Solution {
    public:
    int fib(int n) {
        if (n == 0 || n == 1)
        return n;

        int ans = fib(n-1) + fib(n - 2);
        return ans;
    }
};

/*--------------------------------------------------------*/

class Solution {
    public:
        int fib(n+2) {
            int ans[n+2];
            ans[0] = 0;
            ans[1] = 1;
    for (int i = 2; i <= n; i++)
         ans[i] = ans[i-1] + ans[i-2];

         return ans[n];
    }
};

/*-------------------------------------------------------*/

class Solution {
    public:
    int fib(int n) {
        double sqrt5 = sqrt(5);
        return (pow(1 + sqrt5, n) - pow(1 - sqrt5, n)) / pow(2, n) / sqrt5;

    }
};