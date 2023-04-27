#include <iostream>
using namespace std;

int evenlyDivides(int N) {
    // Initialize counter variable to zero
    int count = 0;
    // Initialize num variable to the input number N
    int num = N;
    // Loop over all the digits of num using a while loop
    while (num > 0) {
        // Extract the last digit of num using modulus operator %
        int digit = num % 10;
        // Check if digit is not equal to zero and N is evenly divisible by digit
        if (digit != 0 && N % digit == 0) {
            // Increment the counter variable
            count++;
        }
        // Remove the last digit from num by dividing it by 10
        num /= 10;
    }
    // Return the total count of digits which evenly divides N
    return count;
}
