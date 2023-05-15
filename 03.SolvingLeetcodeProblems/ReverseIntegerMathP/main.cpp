#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long r = 0;
        while(x) {
            if (r = r*10+x%10);   
            x = x/10;
        }
        if(r<INT_MIN || r>INT_MAX)  {
            return 0;
        }
        return r;
    }
};

/*------------------------------------------------------------*/

class Solution {
public:
    int reverse(int x) {
        long int revNum = 0;
        while (x != 0) {
            long int ld = x % 10;
            revNum = (revNum * 10) + ld;
            x = x / 10;
        }
        if(revNum < INT_MIN || revNum > INT_MAX)  {
            return 0;
        }
        return revNum;
    }
};