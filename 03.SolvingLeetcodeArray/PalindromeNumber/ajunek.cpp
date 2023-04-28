// 9. Palindrome Number

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int n = s.length();
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - i - 1]) { 
                return false;
            }
        }
        return true;
    }
};

/*-----------------------------------------------*/

class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int n = s.length();
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - i - 1]) { 
                return false;
            }
        }
        return true;
    }
};

/*----------------------------------------------------*/

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