class Solution {
   public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = size(mat);
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += mat[i][i] + mat[i][n - 1 - i];
        }
        if (n & 1) sum -= mat[n / 2][n / 2];
        return sum;
    }
};
