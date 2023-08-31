class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        int n = size(grid);
        int m = size(grid[0]);

        vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        function<void(int, int)> dfs = [&](int i, int j) -> void {
            if (i < 0 || i >= n || j < 0 || j >= m) return;
            if (grid[i][j] != '1') return;

            grid[i][j] = 'v';

            for (auto [di, dj] : directions) dfs(i + di, j + dj);
        };

        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] != '1') continue;
                ++count;
                dfs(i, j);
            }
        }

        for (auto& r : grid) {
            for (auto& v : r) {
                v = v == '-' ? '1' : v;
            }
        }

        return count;
    }
};

class Solution {
    const vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

   public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid.front().size();

        int result = 0;

        function<void(int, int)> dfs = [&](int i, int j) -> void {
            if (i < 0 || m <= i || j < 0 || n <= j || grid[i][j] != '1') return;
            grid[i][j] = '2';
            for (auto [di, dj] : directions) dfs(i + di, j + dj);
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != '1') continue;
                dfs(i, j);
                ++result;
            }
        }

        return result;
    }
};

class Solution {
    const vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

   public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid.front().size();

        function<bool(int, int)> search = [&](int x, int y) -> bool {
            if (grid[x][y] != '1') return false;

            vector<array<int, 2>> stk = {{x, y}};
            while (!stk.empty()) {
                auto [i, j] = stk.back();
                stk.pop_back();

                if (i < 0 || m <= i || j < 0 || n <= j || grid[i][j] != '1')
                    continue;
                grid[i][j] = '2';

                for (auto [di, dj] : directions)
                    stk.push_back({i + di, j + dj});
            }

            return true;
        };

        int result = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (search(i, j)) ++result;
            }
        }

        return result;
    }
};
