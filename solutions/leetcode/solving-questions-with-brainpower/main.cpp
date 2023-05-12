class Solution {
   public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();

        long long result = 0;

        vector<long long> dp(n, 0);
        for (int i = 0; i < n; ++i) {
            int point = questions[i][0];
            int brainpower = questions[i][1];

            long long v = dp[i] + point;
            result = max(result, v);

            if (i + 1 < n) dp[i + 1] = max(dp[i + 1], dp[i]);
            if (int j = i + brainpower + 1; j < n) dp[j] = max(dp[j], v);
        }

        return result;
    }
};
