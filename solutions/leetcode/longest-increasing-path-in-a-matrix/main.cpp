class Solution {
    vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

   public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix.front().size();

        vector<vector<int>> vis(m, vector<int>(n, 0));
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (vis[i][j]) return vis[i][j];
            vis[i][j] = 1;
            for (auto [di, dj] : directions) {
                int ii = i + di;
                int jj = j + dj;
                if (ii < 0 || ii >= m || jj < 0 || jj >= n) continue;
                if (matrix[i][j] >= matrix[ii][jj]) continue;
                vis[i][j] = max(vis[i][j], dfs(ii, jj) + 1);
            }
            return vis[i][j];
        };

        int result = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (vis[i][j]) continue;
                result = max(result, dfs(i, j));
            }
        }

        return result;
    }
};

class Solution {
    const vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

   public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix.front().size();

        vector<vector<int>> dist(m, vector<int>(n, -1));
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            int d = 0;
            for (auto [di, dj] : directions) {
                int ii = i + di;
                int jj = j + dj;
                if (ii < 0 || ii >= m || jj < 0 || jj >= n) continue;
                if (matrix[ii][jj] <= matrix[i][j]) continue;
                if (dist[ii][jj] != -1) {
                    d = max(d, dist[ii][jj]);
                    continue;
                }
                d = max(d, dfs(ii, jj));
            }
            return dist[i][j] = d + 1;
        };

        int result = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][j] != -1) continue;
                result = max(result, dfs(i, j));
            }
        }

        return result;
    }
};
