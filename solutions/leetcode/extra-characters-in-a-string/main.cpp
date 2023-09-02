class Solution {
   public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();

        vector<int> dp(n + 1, n);
        dp[n] = 0;

        for (int i = n - 1; i >= 0; --i) {
            dp[i] = dp[i + 1] + 1;
            for (string w : dictionary) {
                int m = w.size();
                if (i + m > n || s.substr(i, m) != w) continue;
                dp[i] = min(dp[i], dp[i + m]);
            }
        }

        return dp[0];
    }
};
