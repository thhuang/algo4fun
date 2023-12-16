class Solution {
   public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.front().size();

        vector<int> onesRow(m, 0), onesCol(n, 0), zerosRow(m, 0),
            zerosCol(n, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    ++onesRow[i];
                    ++onesCol[j];
                } else {
                    ++zerosRow[i];
                    ++zerosCol[j];
                }
            }
        }

        vector<vector<int>> result(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                result[i][j] =
                    onesRow[i] + onesCol[j] - zerosRow[i] - zerosCol[j];
            }
        }

        return result;
    }
};
