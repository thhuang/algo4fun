class Solution {
    const vector<pair<int, int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

   public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat.front().size();

        vector<vector<int>> result(m, vector<int>(n, -1));

        queue<tuple<int, int, int>> q;  // {i, j, distance}
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) q.push({i, j, 0});
            }
        }

        while (!q.empty()) {
            auto [i, j, d] = q.front();
            q.pop();

            if (i < 0 || i >= m || j < 0 || j >= n || result[i][j] != -1) continue;
            result[i][j] = d;

            for (auto [di, dj] : directions) q.push({i + di, j + dj, d + 1});
        }

        return result;
    }
};

class Solution {
   public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat.front().size();

        vector<vector<int>> result(m, vector<int>(n, m + n));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    result[i][j] = 0;
                    continue;
                }
                if (i > 0) result[i][j] = min(result[i][j], result[i - 1][j] + 1);
                if (j > 0) result[i][j] = min(result[i][j], result[i][j - 1] + 1);
            }
        }

        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (i < m - 1) result[i][j] = min(result[i][j], result[i + 1][j] + 1);
                if (j < n - 1) result[i][j] = min(result[i][j], result[i][j + 1] + 1);
            }
        }

        return result;
    }
};
