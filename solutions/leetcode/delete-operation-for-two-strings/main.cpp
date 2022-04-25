class Solution {
   public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1,
                               vector<int>(word2.size() + 1, 0));
        for (int i = 1; i <= word1.size(); ++i) dp[i][0] = i;
        for (int j = 1; j <= word2.size(); ++j) dp[0][j] = j;
        for (int i = 1; i <= word1.size(); ++i) {
            for (int j = 1; j <= word2.size(); ++j) {
                char c1 = word1[i - 1], c2 = word2[j - 1];
                if (c1 == c2) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp.back().back();
    }
};
