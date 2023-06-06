class Solution {
   public:
    double findMaxAverage(vector<int>& nums, int k) {
        double result = -1e9;
        double sum = 0;
        for (int i = 0; i < k - 1; ++i) sum += nums[i];
        for (int i = k - 1; i < nums.size(); ++i) {
            sum += nums[i];
            result = max(result, sum);
            sum -= nums[i - k + 1];
        }
        return result / k;
    }
};
