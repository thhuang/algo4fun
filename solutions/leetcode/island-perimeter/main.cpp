class Solution {
    vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

   public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.front().size();

        int result = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 1) continue;
                for (auto [di, dj] : directions) {
                    int ii = i + di;
                    int jj = j + dj;
                    if (0 <= ii && ii < m && 0 <= jj && jj < n &&
                        grid[ii][jj] == 1) {
                        continue;
                    }
                    ++result;
                }
            }
        }

        return result;
    }
};
