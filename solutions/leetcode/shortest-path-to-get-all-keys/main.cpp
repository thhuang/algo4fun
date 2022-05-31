class Solution {
    vector<array<int, 2>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

   public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid.front().size();

        unordered_map<char, int> keys;
        deque<array<int, 4>> q;  // {i, j, keys, distance}
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                char c = grid[i][j];
                if (c == '@') {
                    q.push_back({i, j, 0, 0});
                } else if (islower(c)) {
                    keys.insert({c, keys.size()});
                }
            }
        }

        vector<vector<vector<bool>>> vis(m, vector<vector<bool>>(n, vector<bool>(1 << keys.size(), false)));
        vis[q.front()[0]][q.front()[1]][q.front()[2]] = true;

        int target = (1 << keys.size()) - 1;
        while (!q.empty()) {
            auto [i, j, k, d] = q.front();
            q.pop_front();

            int dd = d + 1;
            for (auto [di, dj] : directions) {
                int ii = i + di;
                int jj = j + dj;
                int kk = k;

                if (ii < 0 || ii >= m || jj < 0 || jj >= n) continue;
                if (grid[ii][jj] == '#') continue;

                if (char c = grid[ii][jj]; isupper(c)) {
                    if (!(kk & (1 << keys[tolower(c)]))) continue;
                } else if (islower(grid[ii][jj])) {
                    kk |= (1 << keys[c]);
                }

                if (vis[ii][jj][kk]) continue;
                vis[ii][jj][kk] = true;

                if (kk == target) return dd;

                q.push_back({ii, jj, kk, dd});
            }
        }

        return -1;
    }
};
