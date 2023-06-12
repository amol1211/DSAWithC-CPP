#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
    public:
    bool isHappy(int n) {
        unordered_set<int> visited;

        while (n != 1 && visited.find() == visited.end()) {
            visited.insert(n);
            int sum = 0;
            while (n > 0) {
                int digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }
            n = sum;
        }

        return n == 1;
    }
}