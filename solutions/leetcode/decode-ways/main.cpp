class Solution {
   public:
    int numDecodings(string s) {
        unordered_set<string> valid;
        for (int i = 1; i <= 26; ++i) valid.insert(to_string(i));

        array<int, 2> dp = {1, s[0] == '0' ? 0 : 1};
        for (int i = 1; i < size(s); ++i) {
            int count = 0;
            if (valid.count(s.substr(i, 1))) count += dp[1];
            if (valid.count(s.substr(i - 1, 2))) count += dp[0];
            dp = {dp[1], count};
        }

        return dp.back();
    }
};
