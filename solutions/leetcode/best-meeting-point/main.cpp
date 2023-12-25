class Solution {
   public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.front().size();

        vector<int> rows, cols;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }

        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());

        int mr = rows[rows.size() / 2];
        int mc = cols[cols.size() / 2];

        int result = 0;
        for (int r : rows) result += abs(r - mr);
        for (int c : cols) result += abs(c - mc);

        return result;
    }
};

class Solution {
   public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.front().size();

        vector<int> rowAccu(m, 0);
        for (int i = 0; i < m; ++i) {
            if (i != 0) {
                rowAccu[i] = rowAccu[i - 1];
            }
            for (int j = 0; j < n; ++j) {
                rowAccu[i] += grid[i][j];
            }
        }

        vector<int> colAccu(n, 0);
        for (int j = 0; j < n; ++j) {
            if (j != 0) {
                colAccu[j] = colAccu[j - 1];
            }
            for (int i = 0; i < m; ++i) {
                colAccu[j] += grid[i][j];
            }
        }

        int cnt = 0;
        vector<vector<int>> dist(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ++cnt;
                    dist[0][0] += i + j;
                }
            }
        }

        for (int j = 1; j < n; ++j) {
            dist[0][j] = dist[0][j - 1] + colAccu[j - 1] * 2 - cnt;
        }

        for (int i = 1; i < m; ++i) {
            dist[i][0] = dist[i - 1][0] + rowAccu[i - 1] * 2 - cnt;
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dist[i][j] = dist[i][j - 1] + colAccu[j - 1] * 2 - cnt;
            }
        }

        int result = dist[0][0];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                result = min(result, dist[i][j]);
            }
        }

        return result;
    }
};
