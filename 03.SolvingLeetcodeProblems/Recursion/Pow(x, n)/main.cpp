//50. Pow(x, n)

#include <iostream>
#include <cmath>
using namespace std;

// 1. Brute force approach

class Solution {
public:
    // Brute force approach using the pow function
    double myPow(double x, int n) {

        return pow(x, n);
    }
};

// Time Complexity: O(n) - Linear time, where n is the exponent
// Space Complexity: O(1) - Constant space, no additional space used

/*-------------------------------------------------------------------------------*/

// 2. Iterative Binary Exponentiation Approach :

class Solution {
public:
   
    double myPow(double x, int n) {
        // Base case: exponent is 0, return 1.0
        if (n == 0) {
            return 1.0;
        }

        // Initialize result to 1.0
        double ans = 1.0;

        // Use a long long to handle the edge case of INT_MIN
        long long absN = abs((long long)n);

        // Binary exponentiation loop
        while (absN > 0) {
            // If current power is odd, multiply result by x
            if (absN % 2 == 1) {
                ans *= x;
            }
            // Square x for the next iteration
            x *= x;
            // Halve the power
            absN /= 2;
        }

        // Adjust result for negative exponent
        return (n < 0) ? 1 / ans : ans;
    }
};

// Time Complexity: O(log(n)) - Logarithmic time, as we divide n by 2 in each iteration
// Space Complexity: O(1) - Constant space, no additional space used

/*----------------------------------------------------------------------------------------*/

// 3. Recursive Binary Exponentiation Approach :

class Solution {
public:
   
    double myPow(double x, int n) {
        // Base case: exponent is 0, return 1.0
        if (n == 0) {
            return 1.0;
        }

        // Calculate the result for half of the power
        double ans = myPow(x, n / 2);

        // If power is even, return the square of the result
        if (n % 2 == 0) {
            return ans * ans;
        } else {
            // If power is odd, adjust result for negative exponent and return x times the square of the result
            return (n < 0) ? (1 / x) * ans * ans : x * ans * ans;
        }
    }
};

// Time Complexity: O(log(n)) - Logarithmic time, as each recursion reduces the problem size by half
// Space Complexity: O(log(n)) - Logarithmic space, due to the recursive call stack