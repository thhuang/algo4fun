class Solution {
   public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.front().size();

        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> colPrefix(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0, sum = 0; j < n; ++j) {
                sum += grid[i][j];
                prefix[i + 1][j + 1] = sum + prefix[i][j + 1];
            }
        }

        int result = 1;

        for (int k = 2; k <= min(m, n); ++k) {
            if (k == result) continue;

            for (int i = 0; i + k <= m; ++i) {
                for (int j = 0; j + k <= n; ++j) {
                    bool isMagic = true;
                    int sum = prefix[i + 1][j + k] + prefix[i][j] -
                              prefix[i + 1][j] - prefix[i][j + k];

                    for (int r = i + 1; isMagic && r < i + k; ++r) {
                        if (sum != prefix[r + 1][j + k] + prefix[r][j] -
                                       prefix[r + 1][j] - prefix[r][j + k]) {
                            isMagic = false;
                        }
                    }

                    for (int c = j; isMagic && c < j + k; ++c) {
                        if (sum != prefix[i + k][c + 1] + prefix[i][c] -
                                       prefix[i + k][c] - prefix[i][c + 1]) {
                            isMagic = false;
                        }
                    }

                    if (!isMagic) continue;

                    int diag0 = 0, diag1 = 0;
                    for (int d = 0; d < k; ++d) {
                        diag0 += grid[i + d][j + d];
                        diag1 += grid[i + d][j + k - 1 - d];
                    }

                    if (sum == diag0 && sum == diag1) {
                        result = k;
                    }
                }
            }
        }

        return result;
    }
};
