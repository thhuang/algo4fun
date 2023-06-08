class Solution {
   public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.front().size();

        int result = 0;
        for (int i = 0, j = n - 1; i < m; ++i) {
            while (j >= 0 && grid[i][j] < 0) --j;
            result += n - j - 1;
        }

        return result;
    }
};
