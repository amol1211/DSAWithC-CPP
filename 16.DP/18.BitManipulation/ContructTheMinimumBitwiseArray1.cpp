
// Leetcode POTD for the date 20/01/2026
 
#include <iostream>
#include <vector>
using namespace std;


class Solution {
    public:

    vector<int> minBitwiseArray(vector<int> &nums) {

        vector<int> ans;

        for (auto &num : nums) {

            int bestAnsEle = -1;

            for (int i = 0; i <= num; i++) {

                if ((i | (i + 1)) == 0) {

                    bestAnsEle = i;
                    break;
                }
            }
            ans.push_back(bestAnsEle);
        }

        return ans;
    }
};