#include <iostream>
using namespace std;

class Solution {
    public:
    string armstrongNumber(int n) {

        int dup = n;
        int sum = 0;

        while (n > 0) {

            int ld = n % 10;
            sum += (ld * ld *ld);
            n /= 10;
        }
        if (dup == sum)
        return "Yes";
        else
        return "No";
    }
};

int main() {
    Solution s;
    cout << "Enter any three digit number: ";
    int n;
    cin >> n;
    cout << s.armstrongNumber(n) << endl;
    return 0;
}