// https://leetcode.com/problems/number-of-distinct-substrings-in-a-string/solutions/985468/c-max-match-suffix-clean-code/
class Solution {
   public:
    int countDistinct(string s) {
        int n = s.size();

        vector<int> dp(n);

        for (int d = 1; d < n; d++) {
            int len = 0;

            for (int l = 0; l < n; l++) {
                int r = l + d;

                if (r >= n) break;

                s[l] == s[r] ? ++len : len = 0;

                dp[r] = max(dp[r], len);
            }
        }

        int result = 0;
        for (int i = 0; i < n; i++) {
            result += i + 1 - dp[i];
        }

        return result;
    }
};
