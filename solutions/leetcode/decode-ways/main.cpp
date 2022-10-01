class Solution {
   public:
    int numDecodings(string s) {
        if (s.front() == '0') return 0;

        unordered_set<string> nums;
        for (int i = 1; i <= 26; ++i) nums.insert(to_string(i));

        array<int, 2> dp = {1, 1};
        for (int i = 1; i < s.size(); ++i) {
            int count = 0;
            if (nums.count(s.substr(i, 1))) count += dp[1];
            if (nums.count(s.substr(i - 1, 2))) count += dp[0];
            dp = {dp[1], count};
        }

        return dp.back();
    }
};

class Solution {
   public:
    int numDecodings(string s) {
        if (s.front() == '0') return 0;

        int n = s.size();
        array<int, 2> dp = {1, 1};
        for (int i = 2; i <= n; ++i) {
            int v = 0;
            if (s[i - 1] - '0' > 0) v += dp[1];
            if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] - '0' <= 6)) v += dp[0];
            dp = {dp[1], v};
        }

        return dp.back();
    }
};
