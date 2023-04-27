//190. Reverse Bits

#include <iostream>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // Initialize the result variable to zero
        uint32_t res = 0;
        // Iterate over all the bits in n, from right to left
        for (int i = 0; i < 31; i++) {
            // Extract the rightmost bit of n using the modulus operator %
            // and add it to the left of res using bitwise OR operator |
            res = (n % 2) + res << 1;
            // Shift n one bit to the right using the right shift operator >>
            n >>= 1;
        }
        // Add the leftmost bit of n (i.e., the sign bit) to the right of res using bitwise OR operator |
        return res + n % 2;
    }
};
