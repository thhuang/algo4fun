class Solution {
   public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid.front().size();

        if ((m + n - 1) & 1) return false;
        if (grid[0][0] == ')') return false;

        int total_open = (m + n - 1) / 2;
        vector<vector<bitset<101>>> open_count(m, vector<bitset<101>>(n, 0));
        open_count[0][0][1] = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;

                auto up = i == 0 ? 0 : open_count[i - 1][j];
                auto left = j == 0 ? 0 : open_count[i][j - 1];
                open_count[i][j] = up | left;

                if (grid[i][j] == '(') {
                    open_count[i][j] <<= 1;
                } else {  // ')'
                    open_count[i][j] >>= 1;
                }
            }
        }

        return open_count.back().back()[0];
    }
};
