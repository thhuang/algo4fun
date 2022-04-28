class Solution {
   public:
    int longestLine(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat.front().size();

        int result = 0;

        for (int i = 0, length; i < n; ++i) {
            length = 0;
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 0) {
                    length = 0;
                } else {
                    result = max(result, ++length);
                }
            }
        }

        for (int j = 0, length; j < m; ++j) {
            length = 0;
            for (int i = 0; i < n; ++i) {
                if (mat[i][j] == 0) {
                    length = 0;
                } else {
                    result = max(result, ++length);
                }
            }
        }

        vector<vector<int>> diag(n, vector<int>(m, 0));
        vector<vector<int>> adiag(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 0) continue;
                diag[i][j] = 1;
                if (i - 1 >= 0 && j - 1 >= 0) diag[i][j] += diag[i - 1][j - 1];
                result = max(result, diag[i][j]);
            }
            for (int j = m - 1; ~j; --j) {
                if (mat[i][j] == 0) continue;
                adiag[i][j] = 1;
                if (i - 1 >= 0 && j + 1 < m) adiag[i][j] += adiag[i - 1][j + 1];
                result = max(result, adiag[i][j]);
            }
        }

        return result;
    }
};

class Solution {
   public:
    int longestLine(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat.front().size();

        int result = 0;

        for (int i = 0, length; i < n; ++i) {
            length = 0;
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 0) {
                    length = 0;
                } else {
                    result = max(result, ++length);
                }
            }
        }

        for (int j = 0, length; j < m; ++j) {
            length = 0;
            for (int i = 0; i < n; ++i) {
                if (mat[i][j] == 0) {
                    length = 0;
                } else {
                    result = max(result, ++length);
                }
            }
        }

        vector<int> diag(m, 0), adiag(m, 0);
        for (int i = 0; i < n; ++i) {
            vector<int> new_diag(m, 0), new_adiag(m, 0);
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 0) continue;
                new_diag[j] = 1;
                if (j - 1 >= 0) new_diag[j] += diag[j - 1];
                result = max(result, new_diag[j]);
            }
            for (int j = m - 1; ~j; --j) {
                if (mat[i][j] == 0) continue;
                new_adiag[j] = 1;
                if (j + 1 < m) new_adiag[j] += adiag[j + 1];
                result = max(result, new_adiag[j]);
            }
            diag = move(new_diag), adiag = move(new_adiag);
        }

        return result;
    }
};
