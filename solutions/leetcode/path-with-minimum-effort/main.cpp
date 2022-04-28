class Solution {
    vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

   public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights.front().size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>>
            q;  // [effort, row, col]

        q.push({0, 0, 0});

        while (!q.empty()) {
            auto [curr_effort, i, j] = q.top();
            q.pop();

            if (vis[i][j]) continue;
            vis[i][j] = true;

            if (i == n - 1 && j == m - 1) return curr_effort;

            for (auto [di, dj] : directions) {
                int ii = i + di, jj = j + dj;
                if (ii < 0 || ii >= n || jj < 0 || jj >= m) continue;
                int next_effort =
                    max(curr_effort, abs(heights[i][j] - heights[ii][jj]));
                q.push({next_effort, ii, jj});
            }
        }

        return -1;
    }
};
