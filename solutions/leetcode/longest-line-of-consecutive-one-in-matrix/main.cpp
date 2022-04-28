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
