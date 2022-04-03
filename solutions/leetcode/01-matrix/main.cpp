class Solution {
    const vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

   public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = size(mat), m = size(mat[0]);
        vector<vector<int>> ans(n, vector<int>(m, -1));

        struct Entry {
            int i, j;
            int d;
        };
        queue<Entry> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 0) q.push({i, j, 0});
            }
        }

        while (!empty(q)) {
            auto e = q.front();
            q.pop();

            if (e.i < 0 || e.i >= n || e.j < 0 || e.j >= m) continue;
            if (ans[e.i][e.j] != -1) continue;

            ans[e.i][e.j] = e.d;

            for (auto [di, dj] : directions)
                q.push({e.i + di, e.j + dj, e.d + 1});
        }

        return ans;
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
