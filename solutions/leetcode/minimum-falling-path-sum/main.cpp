class Solution {
   public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(n), curr;
        for (int i = 0; i < n; ++i) prev[i] = matrix[0][i];

        for (int i = 1; i < n; ++i) {
            curr = prev;
            for (int j = 0; j < n; ++j) {
                if (j - 1 >= 0) curr[j] = min(curr[j], prev[j - 1]);
                if (j + 1 < n) curr[j] = min(curr[j], prev[j + 1]);
                curr[j] += matrix[i][j];
            }
            prev = move(curr);
        }

        return *min_element(prev.begin(), prev.end());
    }
};
