class Solution {
   public:
    int tallestBillboard(vector<int>& rods) {
        int mx = accumulate(rods.begin(), rods.end(), 0);
        vector<int> dp(mx + 1, 0);

        for (int v : rods) {
            auto dpNew = dp;

            for (int d = 0; d < mx; ++d) {
                if (d > 0 && dp[d] == 0) continue;

                int taller = dp[d];
                int shorter = taller - d;

                {
                    int t = taller + v;
                    int s = shorter;
                    dpNew[t - s] = max(dpNew[t - s], t);
                }
                {
                    int t = taller;
                    int s = shorter + v;
                    if (s > t) swap(t, s);
                    dpNew[t - s] = max(dpNew[t - s], t);
                }
            }

            dp = move(dpNew);
        }

        return max(0, dp[0]);
    }
};
