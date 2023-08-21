class Solution {
    public:
    double findMaxAverage(vector<int>& nums, int k) {
            double avgSum = 0;
            for (int i = 0; i < k; i++) {
                avgSum += nums[i];
            }

            avgSum = avgSum / k;

            double result = avgSum;

            for (int i = k; i < nums.size(); i++) {

                int prev = nums[i - k];

                int next = nums[i];

                avgSum = avgSum + double(next - prev) / k;

                result = max(result, avgSum);
            }

            return result;
        }
    };
