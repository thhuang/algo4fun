class Solution {
   public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        int final_state = (1 << n) - 1;

        vector<int> dp(final_state + 1, 0);
        for (int state = 0; state < final_state; ++state) {
            int cnt = __builtin_popcount(state);
            if (cnt & 1) continue;

            int v = 1 + cnt / 2;

            for (int i = 0; i < n; ++i) {
                int pi = 1 << i;
                if (state & pi) continue;

                for (int j = i + 1; j < n; ++j) {
                    int pj = 1 << j;
                    if (state & pj) continue;

                    int new_state = state | pi | pj;
                    dp[new_state] = max(dp[new_state],
                                        dp[state] + v * gcd(nums[i], nums[j]));
                }
            }
        }

        return dp[final_state];
    }
};
