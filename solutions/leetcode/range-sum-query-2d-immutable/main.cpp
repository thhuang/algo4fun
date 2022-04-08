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

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
