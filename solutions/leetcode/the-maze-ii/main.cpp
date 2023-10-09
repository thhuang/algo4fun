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

class Solution {
    const vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    struct Status {
        int i, j;
        int d;
        int dist;
    };

   public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start,
                         vector<int>& destination) {
        int m = maze.size();
        int n = maze.front().size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vis[start[0]][start[1]] = true;

        queue<Status> q;
        for (int d = 0; d < 4; ++d) {
            q.push({start[0], start[1], d, 0});
        }

        while (!q.empty()) {
            auto e = q.front();
            q.pop();

            int i = e.i, j = e.j, d = e.d, dist = e.dist;
            auto [di, dj] = directions[d];

            int ii = i + di, jj = j + dj;
            if (0 <= ii && ii < m && 0 <= jj && jj < n && maze[ii][jj] != 1) {
                q.push({ii, jj, d, dist + 1});
                continue;
            }

            if (i == destination[0] && j == destination[1]) {
                return dist;
            }

            if (vis[i][j]) continue;
            vis[i][j] = true;

            for (int k = 0; k < 4; ++k) {
                auto [di, dj] = directions[k];
                int ii = i + di, jj = j + dj;
                if (ii < 0 || m <= ii || jj < 0 || n <= jj || maze[ii][jj] == 1)
                    continue;
                q.push({ii, jj, k, dist + 1});
            }
        }

        return -1;
    }
};
