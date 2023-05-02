#include <iostream>
using namespace std;

class Solution {
    public:
    vector<long long> factorialNumbers(long long N) {

        vector<long long> ans;
        
        long long fact = 1;
        
        for (int i = 1; fact * i <= N; i++) {
            fact *= i;
            ans.push_bacl(fact);
        }

        return ans;
    }
};

/*-------------------------------------------------------------*/

class Solution {
    public:

    vector<long long> factorialNumbers(long long N) {

        vector<long long> ans = {1};
        for (int i = 1; i <= N; i++) {

            long long t = i * ans[i - 1];
            if (t > N)
            break;

            ans.push_back(t);
        }

        auto it = ans.begin();
        ans.erase(it);

        return ans;
    }
}; 