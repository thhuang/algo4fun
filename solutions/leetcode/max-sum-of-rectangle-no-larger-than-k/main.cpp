class Solution {
   public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix.front().size();

        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                prefix[i + 1][j + 1] = matrix[i][j] + prefix[i + 1][j] +
                                       prefix[i][j + 1] - prefix[i][j];
            }
        }

        int result = numeric_limits<int>::min();
        for (int u = 0; u < m; ++u) {
            for (int d = u; d < m; ++d) {
                set<int> s;
                s.insert(0);

                for (int j = 0; j < n; ++j) {
                    int v = prefix[d + 1][j + 1] - prefix[u][j + 1];
                    auto it = s.lower_bound(v - k);
                    if (it != s.end()) result = max(result, v - *it);
                    s.insert(v);
                }
            }
        }

        return result;
    }
};
