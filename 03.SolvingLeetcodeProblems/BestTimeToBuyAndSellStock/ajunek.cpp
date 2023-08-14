#include <iostream>
using namespace std;

class Solution {
    public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        if (n == 0) {
            return 0;
        }

        int maxProfit = 0;
        int mini = prices[0];
        int maxi = 0;

        for (int i = 1; i < n; i++) {
            mini = min(mini, prices[i]);
            maxProfit = max(result, prices[i] - mini);
        }
        
        return maxProfit;
    }
};