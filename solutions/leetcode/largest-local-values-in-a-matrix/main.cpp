class Solution {
   public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.front().size();
        vector<vector<int>> result(m - 2, vector<int>(n - 2));
        for (int i = 1; i < m - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                int v = grid[i][j];
                for (int x = -1; x <= 1; ++x) {
                    for (int y = -1; y <= 1; ++y) {
                        v = max(v, grid[i + x][j + y]);
                    }
                }
                result[i - 1][j - 1] = v;
            }
        }
        return result;
    }
};
