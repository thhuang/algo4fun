class Solution {
    const vector<pair<int, int>> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

   public:
    int getFood(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid.front().size();

        queue<array<int, 3>> q;  // {i, j, d}
        for (int i = 0; i < m && q.empty(); ++i) {
            for (int j = 0; j < n && q.empty(); ++j) {
                if (grid[i][j] == '*') {
                    q.push({i, j, 0});
                }
            }
        }

        while (!q.empty()) {
            auto [i, j, d] = q.front();
            q.pop();

            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 'X') continue;
            if (grid[i][j] == '#') return d;
            grid[i][j] = 'X';

            for (auto [di, dj] : directions) q.push({i + di, j + dj, d + 1});
        }

        return -1;
    }
};
