class Solution {
    struct State {
        int i, j, step;
    };

    const vector<array<int, 2>> directions = {
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

   public:
    int minKnightMoves(int x, int y) {
        unordered_map<int, unordered_map<int, bool>> vis;
        queue<State> q;
        q.push({x, y, 0});
        while (!q.empty()) {
            auto [i, j, step] = q.front();
            q.pop();

            if (vis[i][j]) continue;
            vis[i][j] = true;

            if (i == 0 && j == 0) return step;

            for (auto [di, dj] : directions) {
                q.push({i + di, j + dj, step + 1});
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
