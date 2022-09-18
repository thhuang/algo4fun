class Solution {
   public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1,
                               vector<int>(text2.size() + 1, 0));
        for (int i = 1; i <= text1.size(); ++i) {
            for (int j = 1; j <= text2.size(); ++j) {
                char c1 = text1[i - 1], c2 = text2[j - 1];
                if (c1 == c2) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp.back().back();
    }
};

class Solution {
   public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= m; ++i) {
            vector<int> new_dp(n + 1, 0);
            for (int j = 1; j <= n; ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    new_dp[j] = dp[j - 1] + 1;
                } else {
                    new_dp[j] = max(new_dp[j - 1], dp[j]);
                }
            }
            dp = move(new_dp);
        }

        return dp.back();
    }
};
