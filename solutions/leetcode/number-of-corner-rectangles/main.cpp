
class Solution {
   public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.front().size();

        int count = 0;
        vector<vector<int>> pair_count(n, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) continue;
                for (int k = j + 1; k < n; ++k) {
                    if (grid[i][k] == 0) continue;
                    count += pair_count[j][k]++;
                }
            }
        }

        return count;
    }
};
