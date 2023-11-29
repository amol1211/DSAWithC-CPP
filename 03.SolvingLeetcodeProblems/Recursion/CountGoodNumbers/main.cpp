//1922. Count Good Numbers

#include <iostream>
using namespace std;

/*

    Time Complexity : O(logN).

    Space Complexity : O(logN), Recursion stack space.

*/

/*
    Time Complexity: O(logN).
    Space Complexity: O(logN), Recursion stack space.
*/

#define mod 1000000007

class Solution {
private:
    // Recursive function for efficient binary exponentiation
    long long power(long long x, long long n){
        // Base case: x^0 is always 1
        if(n == 0){
            return 1;
        }

        // Recursive calculation of x^(n/2)
        long long ans = power(x, n/2);

        // Square the result
        ans *= ans;
        ans %= mod;

        // If n is odd, multiply by x one more time
        if(n % 2 == 1){
            ans *= x;
            ans %= mod;
        }

        return ans;
    }

public:
    // Function to count good numbers
    int countGoodNumbers(long long n) {
        // Calculate the number of odd and even places in the digit string
        long long numberOfOddPlaces = n/2;
        long long numberOfEvenPlaces = n - numberOfOddPlaces; // or long long numberOfEvenPlaces = (n + 1)/2;

        // Calculate the total count using binary exponentiation
        return (power(5, numberOfEvenPlaces) * power(4, numberOfOddPlaces)) % mod;
    }
};

//Time Complexity: O(log n)
//Space Complexity: O(log n)