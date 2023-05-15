// 9. Palindrome Number

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x); // Convert the integer to a string
        int n = s.length();
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - i - 1]) { // Compare the characters from the beginning and the end of the string
                return false;
            }
        }
        return true;
    }
};

/*--------------------------------------------------------------------------------------------------------------------*/

class Solution {
public:
    bool isPalindrome(int x) { // A function to check if an integer x is a palindrome
        if (x < 0 || (x != 0 && x % 10 == 0)) { // If the number is negative or ends with a zero, it cannot be a palindrome
            return false;
        }
        int sum = 0;
        while (x > sum) { // Reverse the digits of the input number x and store the result in a variable sum
            sum = sum * 10 + x % 10; // Extract the last digit of x using x%10 and add it to sum (after multiplying sum by 10 
            //to shift digits to the left)
            x = x / 10; // Remove the last digit of x (by dividing it by 10)
        }
        // If x is a palindrome, it should be equal to sum or sum/10 (when the number of digits in x is odd)
        return (x == sum) || (x == sum / 10);
    }
};

/*---------------------------------------------------------------------------------------------------------------------------*/

class Solution {
public:
    bool isPalindrome(int x) {
        long int revNum = 0;
        int dup = x;

        while (x > 0) {
            int ld = x % 10;
            revNum = (revNum * 10) + ld;
            x /= 10;
        }
        if (dup == revNum)
        return true;
        else 
        return false;
    }
};
