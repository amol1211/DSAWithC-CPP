//Check if given number N is factorial no. or not.
#include <iostream>
using namespace std;

class Solution {
public:
    int isFactorial(int N) {
        int i = 1;  // initialize i to 1
        while (i*i <= N) {  // loop while i^2 is less than or equal to N
            if (N % i == 0) {  // if i is a factor of N
                N /= i;  // divide N by i
            } else {
                return 0;  // if i is not a factor of N, N is not a factorial number, so return 0
            }
            i++;  // increment i
        }
        return (N == 1);  // if N is equal to 1, it is a factorial number, so return true (1); otherwise, return false (0)
    }
};
