// 507. Perfect Number

#include <iostream>
using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;
        for (int i = 1; i < num/2 + 1; i++) {
            if (num % i == 0) {
                sum += i;
            }
        }
        return sum == num;
    }
};

int main() {
    Solution s;
    int num;
    cin >> num;
    cout << s.checkPerfectNumber(num) << '\n';
    return 0;
}
