#include <iostream>
using namespace std;

class Solution {
    public:
    bool checkPerfectNumber(int num) {
    int sum =  0;
    for (int i = 0; i < num/2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }
    return sum == num;
    }
};