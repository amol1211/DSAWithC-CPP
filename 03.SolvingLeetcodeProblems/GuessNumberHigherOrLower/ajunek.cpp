#include <iostream>
using namespace std;

class Solution {
    public:
      int guessNumber(int n) {
        int left = 1;
        int right = n;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int result = guess(mid);

            if (result == 0) {
                return mid;
            } else if (result == 1) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};