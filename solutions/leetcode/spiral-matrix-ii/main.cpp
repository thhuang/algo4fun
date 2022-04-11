class Solution {
    const vector<array<int, 2>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

   public:
    vector<vector<int>> generateMatrix(int n) {
        int d = 0;
        int i = 0, j = 0;
        vector<vector<int>> mat(n, vector<int>(n, 0));
        for (int v = 1; v <= n * n; ++v) {
            mat[i][j] = v;
            int ii = i + directions[d][0];
            int jj = j + directions[d][1];
            if (ii < 0 || ii >= n || jj < 0 || jj >= n || mat[ii][jj] != 0) {
                d = (d + 1) % 4;
                ii = i + directions[d][0];
                jj = j + directions[d][1];
            }
            i = ii, j = jj;
        }
        return mat;
    }
};
