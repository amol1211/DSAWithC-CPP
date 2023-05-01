#include <iostream>
using namespace std;

class Solution {
public:
    long long sumOfDivisors(int N)
    {   
        // Initialize sum as 0
        long long sum = 0;

        // Iterate from 1 to N
        for (int i = 1; i <= N; i++) {
            // Calculate the sum of divisors of i using the formula:
            // sum of divisors of i = (N/i) * i
            sum += (N / i) * i;
        }

        // Return the final sum
        return sum;
    }
};
