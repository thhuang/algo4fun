class NumMatrix {
    int m, n;
    vector<vector<int>> tree;

    void updateBST(int r, int c, int d) {
        for (int i = r; i < m; i += i & -i) {
            for (int j = c; j < n; j += j & -j) {
                tree[i][j] += d;
            }
        }
    }

    int queryBST(int r, int c) {
        int result = 0;
        for (int i = r; i > 0; i -= i & -i) {
            for (int j = c; j > 0; j -= j & -j) {
                result += tree[i][j];
            }
        }
        return result;
    }

   public:
    NumMatrix(vector<vector<int>>& matrix)
        : m(matrix.size() + 1),
          n(matrix.front().size() + 1),
          tree{vector<vector<int>>(m, vector<int>(n, 0))} {
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                updateBST(i, j, matrix[i - 1][j - 1]);
            }
        }
    }

    void update(int row, int col, int val) {
        int valOld = sumRegion(row, col, row, col);
        updateBST(row + 1, col + 1, val - valOld);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return queryBST(row2 + 1, col2 + 1) + queryBST(row1, col1) -
               queryBST(row2 + 1, col1) - queryBST(row1, col2 + 1);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */
