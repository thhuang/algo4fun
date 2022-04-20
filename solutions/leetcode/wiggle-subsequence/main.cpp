class Solution {
   public:
    int wiggleMaxLength(vector<int>& nums) {
        struct DP {
            int pos, neg;
        };

        DP dp = {1, 1};
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                dp.pos = dp.neg + 1;
            } else if (nums[i] < nums[i - 1]) {
                dp.neg = dp.pos + 1;
            }
        }

        return max(dp.pos, dp.neg);
    }
};
