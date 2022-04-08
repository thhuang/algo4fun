class Solution {
   public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat.front().size();

        vector<vector<int>> prefix_sum(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            int row_sum = 0;
            for (int j = 0; j < m; ++j) {
                row_sum += mat[i][j];
                prefix_sum[i][j] += row_sum;
                if (i > 0) prefix_sum[i][j] += prefix_sum[i - 1][j];
            }
        }

        vector<vector<int>> result(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int r0 = max(i - k, 0);
                int c0 = max(j - k, 0);
                int r1 = min(i + k, n - 1);
                int c1 = min(j + k, m - 1);

                result[i][j] += prefix_sum[r1][c1];
                if (r0 > 0) result[i][j] -= prefix_sum[r0 - 1][c1];
                if (c0 > 0) result[i][j] -= prefix_sum[r1][c0 - 1];
                if (r0 > 0 && c0 > 0)
                    result[i][j] += prefix_sum[r0 - 1][c0 - 1];
            }
        }

        return result;
    }
};
