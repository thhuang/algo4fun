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
        int n = size(mat);
        int m = size(mat[0]);
        vector<vector<int>> ans(n, vector<int>(m, n + m);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 0) {
                    ans[i][j] = 0;
                    continue;
                }
                if (i > 0) ans[i][j] = min(ans[i][j], ans[i - 1][j] + 1);
                if (j > 0) ans[i][j] = min(ans[i][j], ans[i][j - 1] + 1);
            }
        }

        for (int i = n - 1; ~i; --i) {
            for (int j = m - 1; ~j; --j) {
                if (i < n - 1) ans[i][j] = min(ans[i][j], ans[i + 1][j] + 1);
                if (j < m - 1) ans[i][j] = min(ans[i][j], ans[i][j + 1] + 1);
            }
        }

        return ans;
    }
};
