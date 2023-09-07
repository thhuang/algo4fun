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
