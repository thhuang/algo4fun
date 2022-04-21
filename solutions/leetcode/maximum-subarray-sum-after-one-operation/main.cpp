class Solution {
   public:
    int maxSumAfterOperation(vector<int>& nums) {
        int n = nums.size();
        vector<int> left_sum = nums, right_sum = nums;
        for (int i = 1; i < n; ++i) {
            left_sum[i] += max(0, left_sum[i - 1]);
            right_sum[n - 1 - i] += max(0, right_sum[n - i]);
        }

        int result = 0;
        for (int i = 0; i < n; ++i) {
            int v = nums[i] * nums[i];
            if (i - 1 >= 0) v += max(0, left_sum[i - 1]);
            if (i + 1 <= n - 1) v += max(0, right_sum[i + 1]);

            result = max(result, v);
        }

        return result;
    }
};

class Solution {
   public:
    int maxSumAfterOperation(vector<int>& nums) {
        int operated = 0;
        int unoperated = 0;
        int result = 0;
        for (int v : nums) {
            operated = max({operated + v, unoperated + v * v, v * v});
            unoperated = max(0, unoperated) + v;
            result = max(result, operated);
        }
        return result;
    }
};
