class Solution {
   public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.front().size();

        int l = 0, r = n - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;

            int max_val = numeric_limits<int>::min();
            int max_row = -1;
            for (int i = 0; i < mat.size(); ++i) {
                if (mat[i][m] > max_val) {
                    max_val = mat[i][m];
                    max_row = i;
                }
            }

            int left = m - 1 >= 0 ? mat[max_row][m - 1] : -1;
            int right = m + 1 < n ? mat[max_row][m + 1] : -1;
            if (left < max_val && max_val > right) return {max_row, m};
            if (left > max_val) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return {-1, -1};
    }
};
