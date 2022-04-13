class Solution {
   public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid.front().size();

        int count = 0;
        int j = m - 1;
        for (int i = 0; i < n; ++i) {
            while (j >= 0 && grid[i][j] < 0) --j;
            count += m - 1 - j;
        }

        return count;
    }
};
