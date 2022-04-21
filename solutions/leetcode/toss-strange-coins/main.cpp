class Solution {
   public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        int n = prob.size();
        vector<vector<double>> dp(n + 1, vector<double>(target + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int t = 0; t <= target && t <= i; ++t) {
                dp[i][t] += dp[i - 1][t] * (1 - prob[i - 1]);
                if (t - 1 >= 0) dp[i][t] += dp[i - 1][t - 1] * prob[i - 1];
            }
        }
        return dp.back().back();
    }
};

class Solution {
   public:
    double probabilityOfHeads(vector<double>& prob, int target) {
        int n = prob.size();
        vector<double> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            vector<double> new_dp(target + 1, 0);
            for (int t = 0; t <= target && t <= i; ++t) {
                new_dp[t] += dp[t] * (1 - prob[i - 1]);
                if (t - 1 >= 0) new_dp[t] += dp[t - 1] * prob[i - 1];
            }
            dp = move(new_dp);
        }
        return dp.back();
    }
};
