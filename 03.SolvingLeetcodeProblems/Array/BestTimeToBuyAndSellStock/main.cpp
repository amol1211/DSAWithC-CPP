#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        if (n == 0) {
            return 0;
        }
        
        int result = 0;
        int mini = prices[0]; // Initialize the minimum element as the first element
        int maxi = 0; // Initialize the maximum element as 0
        
        for (int i = 1; i < n; i++) {
            mini = min(mini, prices[i]); // Update the minimum element
            result = max(result, prices[i] - mini); // Update the maximum profit
        }
        
        return result;
    }
};