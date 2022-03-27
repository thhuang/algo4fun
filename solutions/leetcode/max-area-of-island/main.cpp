class Solution {
    vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = size(grid), m = size(grid[0]);

        int max_area = 0;
        function<int(int, int)> search = [&](int i, int j) -> int {
            if (i < 0 || i >= n || j < 0 || j >= m) return 0;
            if (grid[i][j] != 1) return 0;

            grid[i][j] = 2;

            int sum = 1;
            for (auto [di, dj] : directions) {
                sum += search(i + di, j + dj);
            }

            return sum;
        };

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                max_area = max(max_area, search(i, j));
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2) {
                    grid[i][j] = 1;
                }
            }
        }

        return max_area;
    }
};
