class Solution {
   public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix.front().size();

        for (int k = -n + 1; k < m; ++k) {
            int i = k < 0 ? 0 : k;
            int j = k < 0 ? -k : 0;
            for (int v = matrix[i][j]; i < m && j < n; ++i, ++j) {
                if (matrix[i][j] != v) return false;
            }
        }

        return true;
    }
};
