#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<long long> lcmAndGcd(long long A, long long B) {
        long long a = A, b = B;
        while (a > 0 && b > 0) {
            if (a > b) {
                a %= b;
            } else {
                b %= a;
            }
        }
        vector<long long> ans;
        long long GCD, LCM;

        if (a == 0) {
            GCD = b;
        } else {
            GCD = a;
        }
        LCM = (A * B) / GCD;
        ans.push_back(LCM);
        ans.push_back(GCD);
        return ans;
    }
};

int main() {
    long long A, B;
    cout << "Enter two numbers: ";
    cin >> A >> B;

    Solution s;
    vector<long long> ans = s.lcmAndGcd(A, B);

    cout << "LCM: " << ans[0] << endl;
    cout << "GCD: " << ans[1] << endl;

    return 0;
}

/*------------------------------------------------------------------------------*/
/*
class Solution {
    public: 

    vector<long long> lcmAndGcd(long long A, long long B) {
        vector<long long> lcmAndGcd;
        long long x = __gcd(A, B);
        long long lcm = (A * B) / x;
        lcmAndGcd.push_back(lcm);
        lcmAndGcd.push_back(x);
        return lcmAndGcd;
    }
};

int main() {
    long long A, B;
    cout << "Enter two numbers: ";
    cin >> A >> B;

    Solution s;
    vector<long long> ans = s.lcmAndGcd(A, B);

    cout << "LCM: " << ans[0] << endl;
    cout << "GCD: " << ans[1] << '\n';

    return 0;
}
*/