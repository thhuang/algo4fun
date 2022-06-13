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

class Solution {
   public:
    bool isValidPalindrome(string s, int k) {
        int n = s.size();
        string r(s.rbegin(), s.rend());
        vector<int> dp(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            vector<int> new_dp(n + 1, 0);
            for (int j = 0; j < n; ++j) {
                if (s[i] == r[j]) {
                    new_dp[j + 1] = dp[j] + 1;
                } else {
                    new_dp[j + 1] = max(dp[j + 1], new_dp[j]);
                }
            }
            dp = move(new_dp);
        }
        return dp.back() + k >= n;
    }
};
