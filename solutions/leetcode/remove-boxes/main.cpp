class Solution {
   public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(n, vector<int>(n, -1)));

        function<int(int, int, int)> dfs = [&](int l, int r, int k) -> int {
            if (l > r) return 0;
            if (dp[l][r][k] != -1) return dp[l][r][k];
            if (l == r) return dp[l][r][k] = (k + 1) * (k + 1);

            int result = dfs(l, r - 1, 0) + (k + 1) * (k + 1);
            for (int m = l; m < r; ++m) {
                if (boxes[m] == boxes[r]) {
                    result =
                        max(result, dfs(l, m, k + 1) + dfs(m + 1, r - 1, 0));
                }
            }

            return dp[l][r][k] = result;
        };

        return dfs(0, n - 1, 0);
    }
};
