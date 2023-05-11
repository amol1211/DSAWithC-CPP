#include <iostream>
using namespace std;

class Solution {
    public:
    int isPalindrome(string S) {
        string revS = S;
        reverse(revS.begin(), revS.end());

        if (S == revS) {
            return 1;
        } else {
            return 0;
        }

    }
};