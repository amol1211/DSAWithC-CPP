#include <iostream>
using namespace std;

class Solution {
    public:
    int isFactorial(int N) {
        int i;
        while (i*i <= N) {
            if (N % i == 0) {
                N /= i;
            } else {
                return 0;
            }
            i++;
        }
        return (N == 1);
    }
};