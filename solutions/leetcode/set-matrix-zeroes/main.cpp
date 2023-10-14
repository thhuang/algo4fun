class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix.front().size();

        vector<bool> row(m, false), col(n, false);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                row[i] = row[i] || matrix[i][j] == 0;
                col[j] = col[j] || matrix[i][j] == 0;
            }
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (row[i] || col[j]) matrix[i][j] = 0;
            }
        }
    }
};

class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix.front().size();

        bool row0 = false, col0 = false;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] != 0) continue;
                matrix[i][0] = matrix[0][j] = 0;
                if (i == 0) row0 = true;
                if (j == 0) col0 = true;
            }
        }

        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    if (i == 0 && !row0) continue;
                    if (j == 0 && !col0) continue;
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix.front().size();

        bool row0 = false, col0 = false;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] != 0) continue;
                matrix[0][j] = matrix[i][0] = 0;
                if (i == 0) row0 = true;
                if (j == 0) col0 = true;
            }
        }

        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (matrix[i][0] != 0 && matrix[0][j] != 0) continue;
                if (i == 0 && !row0) continue;
                if (j == 0 && !col0) continue;
                matrix[i][j] = 0;
            }
        }
    }
};

class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix.front().size();

        bool row0 = false;
        bool col0 = false;

        for (int i = 0; i < m; ++i) {
            if (matrix[i][0] == 0) col0 = true;
        }
        for (int j = 0; j < n; ++j) {
            if (matrix[0][j] == 0) row0 = true;
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < m; ++i) {
            if (matrix[i][0] != 0) continue;
            for (int j = 1; j < n; ++j) {
                matrix[i][j] = 0;
            }
        }

        for (int j = 1; j < n; ++j) {
            if (matrix[0][j] != 0) continue;
            for (int i = 1; i < m; ++i) {
                matrix[i][j] = 0;
            }
        }

        if (row0) {
            for (int j = 0; j < n; ++j) {
                matrix[0][j] = 0;
            }
        }

        if (col0) {
            for (int i = 0; i < m; ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};
