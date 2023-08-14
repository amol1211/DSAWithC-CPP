#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                return true;
            }
        }
        return false;
    }
};
/*------------------------------------------------------------*/
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> count_map;
        for (int i = 0; i < nums.size(); i++) {
            count_map[nums[i]]++;
            if(count_map[nums[i]] > 1) {
                return true;
            }
        }
        return false;
    }
};
        
    