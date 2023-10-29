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
        unordered_map<int, unordered_map<int, int>> memo;
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (memo[i].count(j)) return memo[i][j];
            if (i + j == 0) return memo[i][j] = 0;
            if (i + j == 2) return memo[i][j] = 2;
            return memo[i][j] = 1 + min(dfs(abs(i - 1), abs(j - 2)),
                                        dfs(abs(i - 2), abs(j - 1)));
        };
        return dfs(abs(x), abs(y));
    }
};
