class Solution {
   public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat.front().size();

        vector<vector<int>> diag(m + n - 1);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int k = -i + j + m - 1;
                diag[k].push_back(mat[i][j]);
            }
        }

        for (auto& d : diag) sort(d.begin(), d.end());

        vector<vector<int>> result(m, vector<int>(n));
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int k = -i + j + m - 1;
                result[i][j] = diag[k].back();
                diag[k].pop_back();
            }
        }

        return result;
    }
};
