class Solution {
    vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

   public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights.front().size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>>
            q;  // [effort, row, col]

        // auto cmp = [](const array<int, 3>& a, const array<int, 3>& b) {
        // return a[0] > b[0]; }; priority_queue<array<int, 3>,
        // vector<array<int, 3>>, decltype(cmp)> q(cmp);

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

class Solution {
    const vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

   public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights.front().size();

        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>>
            pq;  // {max effort, i, j}
        pq.push({0, 0, 0});

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        while (!pq.empty()) {
            auto [d, i, j] = pq.top();
            pq.pop();

            if (i == m - 1 && j == n - 1) return d;
            if (vis[i][j]) continue;
            vis[i][j] = true;

            for (auto [di, dj] : directions) {
                int ii = i + di;
                int jj = j + dj;
                if (ii < 0 || m <= ii || jj < 0 || n <= jj) continue;

                int v = max(d, abs(heights[i][j] - heights[ii][jj]));
                pq.push({v, ii, jj});
            }
        }

        return numeric_limits<int>::max();
    }
};
