class Solution {
   public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0) return 1;

        vector<double> dp(n + 1);
        dp[0] = 1;

        double prob = 1;
        for (int i = 1; i <= n; ++i) {
            dp[i] += prob / maxPts;
            if (i < k) prob += dp[i];
            if (int j = i - maxPts; 0 <= j && j < k) prob -= dp[j];
        }

        double result = 0;
        for (int i = k; i <= n; ++i) result += dp[i];

        return result;
    }
};
