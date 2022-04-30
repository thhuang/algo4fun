class Solution {
    vector<array<int, 2>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

   public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix.front().size();

        vector<vector<int>> cache(n, vector<int>(m, 0));
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (cache[i][j]) return cache[i][j];

            int d = 0;
            for (auto [di, dj] : directions) {
                int ii = i + di;
                int jj = j + dj;
                if (ii < 0 || ii >= n || jj < 0 || jj >= m) continue;
                if (matrix[ii][jj] <= matrix[i][j]) continue;

                d = max(d, dfs(ii, jj));
            }

            return cache[i][j] = d + 1;
        };

        int result = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                result = max(result, dfs(i, j));
            }
        }

        return result;
    }
};
