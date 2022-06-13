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

class Solution {
   public:
    bool isValidPalindrome(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int d = 2; d <= n; ++d) {
            for (int l = 0; l + d - 1 < n; ++l) {
                int r = l + d - 1;
                if (s[l] == s[r]) {
                    dp[l][r] = dp[l + 1][r - 1];
                } else {
                    dp[l][r] = 1 + min(dp[l][r - 1], dp[l + 1][r]);
                }
            }
        }
        return dp[0][n - 1] <= k;
    }
};
