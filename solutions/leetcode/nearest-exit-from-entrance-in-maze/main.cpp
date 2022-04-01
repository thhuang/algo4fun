class Solution {
    const vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

   public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();

        struct Entry {
            int i, j;
            int d;
        };

        queue<Entry> q;
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        q.push({entrance[0], entrance[1], 0});
        while (!empty(q)) {
            auto entry = q.front();
            q.pop();
            int i = entry.i, j = entry.j;

            if (i < 0 || i >= n || j < 0 || j >= m) continue;
            if (vis[i][j]) continue;
            if (maze[i][j] == '+') continue;
            if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) &&
                (i != entrance[0] || j != entrance[1]))
                return entry.d;

            vis[i][j] = true;

            for (auto [di, dj] : directions)
                q.push({i + di, j + dj, entry.d + 1});
        }

        return -1;
    }
};
