class Solution {
   public:
    int minCut(string s) {
        int n = s.size();

        vector<vector<int>> palindrome(n, vector<int>(n, false));
        function<void(int, int)> search = [&](int l, int r) -> void {
            while (0 <= l && r < n && s[l] == s[r]) palindrome[l--][r++] = true;
        };
        for (int i = 0; i < n; ++i) search(i, i);
        for (int i = 1; i < n; ++i) search(i - 1, i);

        vector<int> dp(n, numeric_limits<int>::max());
        for (int r = 0; r < n; ++r) {
            if (palindrome[0][r]) {
                dp[r] = 0;
                continue;
            }

            for (int i = 0; i < r; ++i) {
                if (palindrome[i + 1][r]) dp[r] = min(dp[r], dp[i] + 1);
            }
        }

        return dp.back();
    }
};
