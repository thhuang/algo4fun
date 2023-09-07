class Solution {
   public:
    int minBuildTime(vector<int>& blocks, int split) {
        sort(blocks.begin(), blocks.end());

        int n = blocks.size();
        vector<vector<int>> memo(n, vector<int>(n + 1, -1));

        function<int(int, int)> build = [&](int i, int w) -> int {
            if (w == 0) return numeric_limits<int>::max();
            if (i < 0) return 0;
            if (i < w) return blocks[i];
            if (memo[i][w] != -1) return memo[i][w];

            int workNow = max(blocks[i], build(i - 1, w - 1));
            int splitNow = split + build(i, w * 2);

            return memo[i][w] = min(workNow, splitNow);
        };

        return build(n - 1, 1);
    }
};

class Solution {
   public:
    int minBuildTime(vector<int>& blocks, int split) {
        sort(blocks.begin(), blocks.end(), greater<>());

        int n = blocks.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, numeric_limits<int>::max()));
        for (int w = 0; w <= n; ++w) dp[n][w] = 0;

        for (int b = n - 1; b >= 0; --b) {
            for (int w = n; w > 0; --w) {
                if (b + w >= n) {
                    dp[b][w] = blocks[b];
                    continue;
                }
                int workNow = max(blocks[b], dp[b + 1][w - 1]);
                int splitNow = split + dp[b][min(n, w * 2)];
                dp[b][w] = min(workNow, splitNow);
            }
        }

        return dp[0][1];
    }
};
