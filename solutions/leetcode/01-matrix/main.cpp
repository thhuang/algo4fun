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
