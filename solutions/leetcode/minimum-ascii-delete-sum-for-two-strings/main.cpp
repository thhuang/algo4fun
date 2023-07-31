class Solution {
   public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
        for (int i = 0, sum = 0; i < s1.size(); ++i)
            dp[i + 1][0] = sum += s1[i];
        for (int j = 0, sum = 0; j < s2.size(); ++j)
            dp[0][j + 1] = sum += s2[j];

        for (int i = 1; i <= s1.size(); ++i) {
            for (int j = 1; j <= s2.size(); ++j) {
                char c1 = s1[i - 1], c2 = s2[j - 1];
                dp[i][j] = dp[i - 1][j - 1];
                if (c1 != c2) dp[i][j] += c1 + c2;
                dp[i][j] =
                    min({dp[i][j], dp[i - 1][j] + c1, dp[i][j - 1] + c2});
            }
        }

        return dp.back().back();
    }
};

class Solution {
   public:
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));

        dp[n1][n2] = 0;
        for (int i = n1 - 1, v = 0; i >= 0; --i) dp[i][n2] = v += s1[i];
        for (int j = n2 - 1, v = 0; j >= 0; --j) dp[n1][j] = v += s2[j];

        for (int i = n1 - 1; i >= 0; --i) {
            for (int j = n2 - 1; j >= 0; --j) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = dp[i + 1][j + 1];
                } else {
                    dp[i][j] = min(dp[i + 1][j] + s1[i], dp[i][j + 1] + s2[j]);
                }
            }
        }

        return dp[0][0];
    }
};
