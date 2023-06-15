//202. Happy Number

#include <iostream>
#include <unordered_set>
using namespace std;


class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visited; // Set to keep track of visited numbers

        while (n != 1 && visited.find(n) == visited.end()) {
            visited.insert(n); // Add n to visited set
            int sum = 0;
            while (n > 0) {
                int digit = n % 10; // Extract the last digit
                sum += digit * digit; // Add the square of the digit to the sum
                n /= 10; // Remove the last digit from n
            }
            n = sum; // Assign the sum to n for the next iteration
        }

        return n == 1; // Return true if n is 1 (happy number), false otherwise
    }
};
