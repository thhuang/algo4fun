class Solution {
   public:
    int deleteString(string s) {
        int n = s.size();
        if (n == 0) return 0;

        vector<int> dp(n, 1);

        for (int i = n - 1; i >= 0; --i) {
            vector<int> prefix(n - i, 0);
            for (int j = 1; j < n - i; ++j) {
                int d = prefix[j - 1];
                while (d > 0 && s[i + j] != s[i + d]) d = prefix[d - 1];
                if (s[i + j] == s[i + d]) ++d;
                prefix[j] = d;
            }

            for (int j = 0; j < prefix.size(); ++j) {
                if (prefix[j] * 2 != j + 1) continue;
                dp[i] = max(dp[i], dp[i + prefix[j]] + 1);
            }
        }

        return dp.front();
    }
};
