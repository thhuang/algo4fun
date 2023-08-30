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

class Solution {
   public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        for (int i = n1 - 1; i >= 0; --i) {
            for (int j = n2 - 1; j >= 0; --j) {
                if (text1[i] == text2[j]) {
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        return dp[0][0];
    }
};

class Solution {
   public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();

        vector<int> dp(n2 + 1, 0);

        for (int i = n1 - 1; i >= 0; --i) {
            vector<int> dpNew(n2 + 1);
            for (int j = n2 - 1; j >= 0; --j) {
                if (text1[i] == text2[j]) {
                    dpNew[j] = dp[j + 1] + 1;
                } else {
                    dpNew[j] = max(dp[j], dpNew[j + 1]);
                }
            }
            dp = move(dpNew);
        }

        return dp[0];
    }
};
