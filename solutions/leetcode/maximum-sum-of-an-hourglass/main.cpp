class Solution {
   public:
    int maxSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.front().size();
        vector<vector<long long>> prefix(m + 1, vector<long long>(n + 1, 0));
        for (int i = 1; i <= m; ++i) {
            int s = 0;
            for (int j = 1; j <= n; ++j) {
                s += grid[i - 1][j - 1];
                prefix[i][j] = prefix[i - 1][j] + s;
            }
        }

        long long result = 0;
        for (int i = 3; i <= m; ++i) {
            for (int j = 3; j <= n; ++j) {
                long long v = prefix[i][j] - prefix[i][j - 3] -
                              prefix[i - 3][j] + prefix[i - 3][j - 3] -
                              grid[i - 2][j - 1] - grid[i - 2][j - 3];
                result = max(result, v);
            }
        }

        return result;
    }
};
