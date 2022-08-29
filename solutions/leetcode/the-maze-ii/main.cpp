class Solution {
    const vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

   public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start,
                         vector<int>& destination) {
        int m = maze.size();
        int n = maze.front().size();

        vector<vector<vector<bool>>> vis(
            m, vector<vector<bool>>(n, vector<bool>(4, false)));

        queue<array<int, 4>> q;  // {i, j, direction, distance}
        for (int i = 0; i < 4; ++i) q.push({start[0], start[1], i, 0});

        while (!q.empty()) {
            auto [i, j, dir, dist] = q.front();
            q.pop();

            if (vis[i][j][dir]) continue;
            vis[i][j][dir] = true;

            int ii = i + directions[dir][0];
            int jj = j + directions[dir][1];
            if (ii >= 0 && ii < m && jj >= 0 && jj < n && maze[ii][jj] == 0) {
                q.push({ii, jj, dir, dist + 1});
                continue;
            }

            if (i == destination[0] && j == destination[1]) return dist;

            for (dir = 0; dir < 4; ++dir) {
                ii = i + directions[dir][0];
                jj = j + directions[dir][1];
                if (ii < 0 || ii >= m || jj < 0 || jj >= n || maze[ii][jj] == 1)
                    continue;
                q.push({ii, jj, dir, dist + 1});
            }
        }

        return -1;
    }
};
