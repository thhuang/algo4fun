class Solution {
   public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid.front().size();

        vector<int> prev(m, 0);
        int sum = 0;
        for (int i = 0; i < m; ++i) prev[i] = sum += grid[0][i];

        for (int i = 1; i < n; ++i) {
            vector<int> curr = grid[i];
            curr[0] += prev[0];
            for (int j = 1; j < m; ++j) {
                curr[j] += min(curr[j - 1], prev[j]);
            }
            prev = move(curr);
        }

        return prev.back();
    }
};
