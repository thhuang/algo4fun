class Solution {
   public:
    int wiggleMaxLength(vector<int>& nums) {
        struct DP {
            int neg, pos;
        };
        DP dp = {1, 1};
        for (int i = 1; i < nums.size(); ++i) {
            int diff = nums[i] - nums[i - 1];
            if (diff < 0) {
                dp.neg = dp.pos + 1;
            } else if (diff > 0) {
                dp.pos = dp.neg + 1;
            }
        }
        return max(dp.neg, dp.pos);
    }
};
