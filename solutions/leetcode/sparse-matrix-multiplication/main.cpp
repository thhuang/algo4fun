class Solution {
   public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1,
                                 vector<vector<int>>& mat2) {
        int m = mat1.size();
        int k = mat1.front().size();
        int n = mat2.front().size();

        vector<array<int, 3>> m1, m2;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < k; ++j) {
                int v = mat1[i][j];
                if (v != 0) m1.push_back({i, j, v});
            }
        }
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < n; ++j) {
                int v = mat2[i][j];
                if (v != 0) m2.push_back({i, j, v});
            }
        }

        vector<vector<int>> result(m, vector<int>(n, 0));
        for (auto [i, k1, v1] : m1) {
            for (auto [k2, j, v2] : m2) {
                if (k1 == k2) result[i][j] += v1 * v2;
            }
        }

        return result;
    }
};
