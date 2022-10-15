class Solution {
    const int inf = 1e3;

    int count2length(int v) {
        if (v > 99) return 4;
        if (v > 9) return 3;
        if (v > 1) return 2;
        return 1;
    }

   public:
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));

        function<int(int, int)> dfs = [&](int l, int t) -> int {
            if (t < 0) return inf;
            if (n - l <= t) return 0;
            if (dp[l][t] != -1) return dp[l][t];

            array<int, 26> cnt;
            cnt.fill(0);

            int result = inf;
            for (int r = l, mx = 0; r < n; ++r) {
                mx = max(mx, ++cnt[s[r] - 'a']);
                int use = r - l + 1 - mx;
                result = min(result, count2length(mx) + dfs(r + 1, t - use));
            }

            return dp[l][t] = result;
        };

        return dfs(0, k);
    }
};
