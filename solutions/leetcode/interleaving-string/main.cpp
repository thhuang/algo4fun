class Solution {
   public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;

        int m = s1.size();
        int n = s2.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        dp[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                int b1 = i > 0 && dp[i - 1][j] && s1[i - 1] == s3[i + j - 1];
                int b2 = j > 0 && dp[i][j - 1] && s2[j - 1] == s3[i + j - 1];
                if (b1 || b2) dp[i][j] = true;
            }
        }

        return dp.back().back();
    }
};

class Solution {
   public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;

        int n1 = s1.size();
        int n2 = s2.size();

        vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));
        dp[n1][n2] = true;

        for (int i = n1; i >= 0; --i) {
            for (int j = n2; j >= 0; --j) {
                if (i < n1)
                    dp[i][j] = dp[i][j] || dp[i + 1][j] && s1[i] == s3[i + j];
                if (j < n2)
                    dp[i][j] = dp[i][j] || dp[i][j + 1] && s2[j] == s3[i + j];
            }
        }

        return dp.front().front();
    }
};

class Solution {
   public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;

        int m = s1.size(), n = s2.size();
        vector<bool> dp(n + 1, false);

        for (int i = 0; i <= m; ++i) {
            vector<bool> new_dp(n + 1, false);
            for (int j = 0; j <= n; ++j) {
                int b1 = i > 0 && dp[j] && s1[i - 1] == s3[i + j - 1];
                int b2 = j > 0 && new_dp[j - 1] && s2[j - 1] == s3[i + j - 1];
                if ((i + j == 0) || b1 || b2) new_dp[j] = true;
            }
            dp = move(new_dp);
        }

        return dp.back();
    }
};
