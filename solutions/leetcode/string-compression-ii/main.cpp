class Solution {
    const int INF = 1e3;

    int compressedLength(int n) {
        if (n >= 100) return 4;
        if (n >= 10) return 3;
        if (n >= 2) return 2;
        return 1;
    }

   public:
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.size();
        vector<vector<int>> memo(n, vector<int>(k + 1, -1));

        function<int(int, int)> dp = [&](int l, int remain) -> int {
            if (remain < 0) return INF;
            if (n - l <= remain) return 0;
            if (memo[l][remain] != -1) return memo[l][remain];

            array<int, 26> cnt = {};
            int result = INF;

            for (int r = l, mx = 0; r < n; ++r) {
                mx = max(mx, ++cnt[s[r] - 'a']);
                int use = r - l + 1 - mx;
                result =
                    min(result, compressedLength(mx) + dp(r + 1, remain - use));
            }

            return memo[l][remain] = result;
        };

        return dp(0, k);
    }
};
