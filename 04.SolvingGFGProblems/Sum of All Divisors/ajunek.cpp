#include <iostream>
using namespace std;

class Solution {
    long long sumOfDivisors(int N) {

        long long sum = 0;

        for (int i = 1; i <= N; i++) {

            sum += ( N/i) * i;
        }

        return sum;
    }
};