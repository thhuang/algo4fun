class Solution {
   public:
    bool isValidPalindrome(string s, int k) {
        int n = s.size();
        string r(s.rbegin(), s.rend());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (s[i] == r[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                } else {
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }
        return dp.back().back() + k >= n;
    }
};
