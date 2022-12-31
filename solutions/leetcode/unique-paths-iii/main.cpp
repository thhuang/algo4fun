class Solution {
    const vector<pair<int, int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

   public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.front().size();

        function<int(int, int)> index = [&](int i, int j) -> int {
            return j + i * n;
        };

        int curr = 0;
        int target = (1 << (m * n)) - 1;
        int result = 0;

        pair<int, int> from;
        int to;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == -1) {
                    curr |= (1 << index(i, j));
                } else if (grid[i][j] == 1) {
                    from = {i, j};
                } else if (grid[i][j] == 2) {
                    to = 1 << index(i, j);
                    curr |= (1 << index(i, j));
                }
            }
        }

        function<void(int, int, int)> dfs = [&](int i, int j,
                                                int curr) -> void {
            if (i < 0 || i >= m || j < 0 || j >= n) return;

            int k = 1 << index(i, j);
            if (curr == target) {
                if (k == to) ++result;
                return;
            }

            if (curr & k) return;
            curr |= k;

            for (auto [di, dj] : directions) dfs(i + di, j + dj, curr);
        };

        dfs(from.first, from.second, curr);

        return result;
    }
};
