#include <iostream>
using namespace std;

class Solution {
public:
    long long sumOfSeries(long long N) {
        // Formula for sum of cubes of first N natural numbers: (N * (N+1) / 2) ^ 2
        long long int s = N * (N + 1) / 2;
        return s * s;
    }
};

/*---------------------------------------OR---------------------------------------------------------*/

class Solution {
  public:
    long long sumOfSeries(long long N) {
        
        long long int sum = 0;
        for (int i = 1; i <= N; i++) {
            sum += i;
        }
        return sum * sum;
    }
};
