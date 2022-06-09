class Solution {
   public:
    int numDistinct(string s, string t) {
        vector<long> dp(t.size(), 0);
        for (int i = 0; i < s.size(); ++i) {
            for (int j = t.size() - 1; ~j; --j) {
                if (s[i] != t[j]) continue;
                int v = j == 0 ? 1 : dp[j - 1];
                dp[j] += v;
            }
        }
        return dp.back();
    }
};
