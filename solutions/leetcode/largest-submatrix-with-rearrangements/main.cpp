class Solution {
   public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix.front().size();

        for (int j = 0; j < n; ++j) {
            for (int i = 1; i < m; ++i) {
                if (matrix[i][j] == 0) continue;
                matrix[i][j] = matrix[i - 1][j] + 1;
            }
        }

        int result = 0;
        for (vector<int>& row : matrix) {
            sort(row.begin(), row.end(), greater<>());
            for (int i = 0; i < n; ++i) {
                result = max(result, (i + 1) * row[i]);
            }
        }

        return result;
    }
};
