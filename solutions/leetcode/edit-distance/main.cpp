class Solution {
   public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; ++i) dp[i][0] = i;
        for (int j = 1; j <= m; ++j) dp[0][j] = j;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = min(
                    {dp[i - 1][j - 1] + (word1[i - 1] == word2[j - 1] ? 0 : 1),
                     dp[i][j - 1] + 1, dp[i - 1][j] + 1});
            }
        }

        return dp.back().back();
    }
};
