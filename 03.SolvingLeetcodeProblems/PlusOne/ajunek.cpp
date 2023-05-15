#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() - 1;

        for (int i = n; i >= 0; --i) {

            if (digits[i] == 9) {
                digits[i] = 0;
            } else {
                digits[i] += 1;
                return digits;
            }
        }
        digits.push_back(0);
        digits[0] = 1;
        return digits;
    }
};
/*------------------------------------------------------------------------------------*/

class Solution {
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        digits[n-1]++;

        for (int i = n-1; i > 0 && digits[i] == 10; i--) {
            digits[i] = 0;
            digits[i-1]++;
        }

        if (digits[0] == 10) {
            digits[0] = 0;
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};