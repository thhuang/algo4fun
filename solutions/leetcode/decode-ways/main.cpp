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
