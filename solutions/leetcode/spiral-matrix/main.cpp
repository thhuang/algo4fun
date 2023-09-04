
class Solution {
    vector<array<int, 2>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix.front().size();

        vector<int> result(m * n);

        for (int k = 0, d = 0, i = 0, j = 0; k < m * n; ++k) {
            result[k] = matrix[i][j];
            matrix[i][j] += 1000;

            auto [di, dj] = directions[d];
            int ii = i + di;
            int jj = j + dj;
            if (ii < 0 || m <= ii || jj < 0 || n <= jj ||
                matrix[ii][jj] > 100) {
                (d += 1) %= 4;
                auto [di, dj] = directions[d];
                ii = i + di;
                jj = j + dj;
            }

            i = ii;
            j = jj;
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                matrix[i][j] -= 1000;
            }
        }

        return result;
    }
};
