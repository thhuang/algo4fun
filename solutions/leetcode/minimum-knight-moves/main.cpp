class Solution {
    vector<array<int, 2>> directions = {{2, 1}, {-2, 1}, {2, -1}, {-2, -1},
                                        {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};

   public:
    int minKnightMoves(int x, int y) {
        if (x == 0 && y == 0) return 0;

        x = abs(x), y = abs(y);
        unordered_map<int, unordered_map<int, bool>> vis;

        deque<array<int, 3>> q = {{0, 0, 0}};
        vis[0][0] = true;

        while (!q.empty()) {
            auto [i, j, d] = q.front();
            q.pop_front();

            int dd = d + 1;
            for (auto [di, dj] : directions) {
                int ii = i + di, jj = j + dj;
                if (ii == x && jj == y) return dd;
                if (ii < -1 || jj < -1) continue;

                if (vis[ii][jj]) continue;
                vis[ii][jj] = true;

                q.push_back({ii, jj, dd});
            }
        }

        return -1;
    }
};

class Solution {
   public:
    int minKnightMoves(int x, int y) {
        unordered_map<int, unordered_map<int, int>> cache;

        function<int(int, int)> dfs = [&cache, &dfs](int x, int y) -> int {
            if (cache[x].count(y)) return cache[x][y];

            if (x + y == 0) return cache[x][y] = 0;
            if (x + y == 2) return cache[x][y] = 2;

            return cache[x][y] = 1 + min(dfs(abs(x - 2), abs(y - 1)),
                                         dfs(abs(x - 1), abs(y - 2)));
        };

        return dfs(abs(x), abs(y));
    }
};
