class Solution {
   public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix.front().size();

        vector<int> prev(m, 0);
        int result = 0;
        for (int i = 0; i < n; ++i) {
            vector<int> curr(m, 0);
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == '0') continue;
                curr[j] = 1;
                if (j > 0) curr[j] += min({prev[j], prev[j - 1], curr[j - 1]});
                result = max(result, curr[j] * curr[j]);
            }
            prev = move(curr);
        }

        return result;
    }
};
