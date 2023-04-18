class Solution {
public:
    int digitSum(int num){
        int sum = 0;
        while(num > 0){
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    int differenceOfSum(vector<int>& nums) {
        int ele = 0, dig = 0;
        for(int num : nums){
            ele += num;
            dig += digitSum(num);
        }
        return abs(ele - dig);
    }
};
/*---------------------------------------------------------------------*/

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int elementSum = 0, digitSum = 0;
        for(auto n: nums) {
            elementSum += n;
            while(n > 0) {
                digitSum += n%10;
                n = n/10;
            }
        }
        return abs(elementSum - digitSum);
        
    }
};