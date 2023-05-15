#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }
    bool isNegative = (dividend < 0) ^ (divisor < 0);
    long long absDividend = abs((long long)dividend);
    long long absDivisor = abs((long long)divisor);
    long long quotient = 0;
    for (int i = 31; i >= 0; i--) {
        if ((absDividend >> i) >= absDivisor) {
            quotient += ((long long)1 << i);
            absDividend -= (absDivisor << i);
        }
    }
    return isNegative ? -quotient : quotient;
    }
        
    
};


