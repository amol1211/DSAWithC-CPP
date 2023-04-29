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

/*--------------------------------------------------------*/

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) {
            return false;
        }
        int sum = 1;
        int sqrt_num = sqrt(num);
        for (int i = 2; i <= sqrt_num; i++) {
            if (num % i == 0) {
                sum += i;
                if ( i != num/i) {
                    sum += num/i;
                }
            }
        }
        return sum == num;
    }
};
