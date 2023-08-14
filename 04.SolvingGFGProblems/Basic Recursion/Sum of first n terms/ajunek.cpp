#include <iostream>
using namespace std;

class Solution {
    public:
    long long sumOfSeries(long long N) {
        long long int sum = 0;
        for (int i = 0; i <= N; i++) {
            sum += i;
        }
        return sum * sum;
    }
};

/*---------------------------------------------------------*/

class Solution {
    public:
    long long sumOfSeries(long long N) {
        long long int sum = N * (N + 1)/ 2;
        return sum * sum;
    }
};