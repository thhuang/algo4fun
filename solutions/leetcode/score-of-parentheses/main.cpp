class Solution {
   public:
    int scoreOfParentheses(string s) {
        s = '(' + s + ')';

        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));
        for (int i = 0; i + 1 < n; ++i) {
            if (s[i] == '(' && s[i + 1] == ')') {
                dp[i][i + 1] = 1;
            }
        }

        for (int len = 4; len <= n; len += 2) {
            for (int l = 0, r = l + len - 1; r < n; ++l, ++r) {
                if (s[l] != '(' || s[r] != ')') {
                    continue;
                }
                if (dp[l + 1][r - 1] != -1) {
                    dp[l][r] = dp[l + 1][r - 1] * 2;
                    continue;
                }
                for (int i = l + 1; i < r - 1; ++i) {
                    if (dp[l][i] != -1 && dp[i + 1][r] != -1) {
                        dp[l][r] = dp[l][i] + dp[i + 1][r];
                        break;
                    }
                }
            }
        }

        return dp.front().back() / 2;
    }
};
