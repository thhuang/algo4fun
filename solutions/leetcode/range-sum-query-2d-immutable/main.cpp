class NumMatrix {
    vector<vector<int>> prefix_sum_;

   public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix.front().size();
        prefix_sum_ = vector<vector<int>>(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            int row_sum = 0;
            for (int j = 0; j < m; ++j) {
                row_sum += matrix[i][j];
                prefix_sum_[i][j] += row_sum;
                if (i > 0) prefix_sum_[i][j] += prefix_sum_[i - 1][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = prefix_sum_[row2][col2];
        if (row1 > 0) sum -= prefix_sum_[row1 - 1][col2];
        if (col1 > 0) sum -= prefix_sum_[row2][col1 - 1];
        if (row1 > 0 && col1 > 0) sum += prefix_sum_[row1 - 1][col1 - 1];
        return sum;
    }
};

class NumMatrix {
    int m, n;
    vector<vector<int>> prefix;

   public:
    NumMatrix(vector<vector<int>>& matrix)
        : m(matrix.size()),
          n(matrix.front().size()),
          prefix(m + 1, vector<int>(n + 1, 0)) {
        for (int i = 0; i < m; ++i) {
            int s = 0;
            for (int j = 0; j < n; ++j) {
                s += matrix[i][j];
                prefix[i + 1][j + 1] = prefix[i][j + 1] + s;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefix[row2 + 1][col2 + 1] - prefix[row2 + 1][col1] -
               prefix[row1][col2 + 1] + prefix[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
