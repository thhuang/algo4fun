class Solution {
   public:
    int maxTrailingZeros(vector<vector<int>>& grid) {
        struct Entry {
            int n2, n5;

            Entry operator+(const Entry& other) {
                return {n2 + other.n2, n5 + other.n5};
            }

            Entry operator-(const Entry& other) {
                return {n2 - other.n2, n5 - other.n5};
            }

            int zeros() { return min(n2, n5); }
        };

        int n = grid.size();
        int m = grid.front().size();

        vector<vector<Entry>> mat(n, vector<Entry>(m, {0, 0}));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int v = grid[i][j];
                int n2 = 0;
                while (v && v % 2 == 0) ++n2, v /= 2;

                v = grid[i][j];
                int n5 = 0;
                while (v && v % 5 == 0) ++n5, v /= 5;

                mat[i][j] = {n2, n5};
            }
        }

        vector<vector<Entry>> acc_h(n, vector<Entry>(m, {0, 0}));
        for (int i = 0; i < n; ++i) {
            Entry acc = {0, 0};
            for (int j = 0; j < m; ++j) {
                acc.n2 += mat[i][j].n2;
                acc.n5 += mat[i][j].n5;
                acc_h[i][j] = acc;
            }
        }

        vector<vector<Entry>> acc_v(n, vector<Entry>(m, {0, 0}));
        for (int j = 0; j < m; ++j) {
            Entry acc = {0, 0};
            for (int i = 0; i < n; ++i) {
                acc.n2 += mat[i][j].n2;
                acc.n5 += mat[i][j].n5;
                acc_v[i][j] = acc;
            }
        }

        int result = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                Entry left = acc_h[i][j];
                Entry right =
                    acc_h[i][m - 1] - (j == 0 ? Entry{0, 0} : acc_h[i][j - 1]);
                Entry up = acc_v[i][j];
                Entry down =
                    acc_v[n - 1][j] - (i == 0 ? Entry{0, 0} : acc_v[i - 1][j]);
                result = max({result, (left + up - mat[i][j]).zeros(),
                              (left + down - mat[i][j]).zeros(),
                              (right + up - mat[i][j]).zeros(),
                              (right + down - mat[i][j]).zeros()});
            }
        }

        return result;
    }
};
