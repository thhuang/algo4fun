class Solution {
   public:
    int getMaxLen(vector<int>& nums) {
        struct DP {
            int pos, neg;
        };

        int max_pos = 0;
        DP dp = {0, 0};
        for (int v : nums) {
            if (v > 0) {
                dp = {dp.pos + 1, dp.neg ? dp.neg + 1 : 0};
            } else if (v < 0) {
                dp = {dp.neg ? dp.neg + 1 : 0, dp.pos + 1};
            } else {
                dp = {0, 0};
            }
            max_pos = max(max_pos, dp.pos);
        }
        return max_pos;
    }
};
